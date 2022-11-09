// WindowAnima.cpp: implementation of the CWindowAnima class.
//
//////////////////////////////////////////////////////////////////////
/*
 *
 *
 *  Copyright (c) 2002 DigitalConvict <ax@digitalconvict.com>
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * Contact info:
 * Site: http://www.digitalconvict.com
 * Email: ax@digitalconvict.com
 */
#include "stdafx.h"
#include "WindowAnima.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/************************************************************************************
	Default Constructor
************************************************************************************/
CWindowAnima::CWindowAnima()
{
	InitialSetup();
}

/************************************************************************************
	Overloaded constructor, takes CWnd* and captures an image of the winddow.  The
	window pointed to by pWnd mUST be visible unless the WA_WND_SKIPCAPTURE flag is
	also included in the nFlags parameter.
************************************************************************************/
CWindowAnima::CWindowAnima(CWnd *pWnd, UINT nFlags)
{
	InitialSetup();
	FlagSet(nFlags);
	SetWindow(pWnd);
}

/************************************************************************************
	Deletes any of the dynamically created CDC pointers
************************************************************************************/
CWindowAnima::~CWindowAnima()
{
	// select out bitmap we've been using replace with original
	m_pdcMemScr->SelectObject(m_pOldBitmapScr);
	m_pdcMemWnd->SelectObject(m_pOldBitmapWnd);

	// delete all DC's held in memory
	delete m_pdcScreen;
	delete m_pdcMemWnd;
	delete m_pdcMemScr;

}

/************************************************************************************
	Two partitions slide horizontally away from eachother underneath the window.
	The window then disappears into the black void, Finally the partitions close
	back together leaving the screen intact minus the window
************************************************************************************/
void CWindowAnima::SlideVanish(int nSlideFactor, int nScaleFactor,
							   int nSlideDelay, int nVanishDelay)
{
	// make sure we can stretch blit on this device
	if(!(m_pdcScreen->GetDeviceCaps(RASTERCAPS) & RC_STRETCHBLT))
		return;

	// Do any pre-animation initialisations
	Initialise();

	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	CPoint cptWindowCenter=m_rectWnd.CenterPoint();
	CSize czDiv(m_czWnd.cx/2, m_czWnd.cy/2);
	int nHeight=m_rectWnd.Height(), nWidth=m_rectWnd.Width(),nLeftx, nRightx;
	int nOpen=0;

	// print an image of the original window to the screen
	PrintWindow();

	// slide partitions apart
	while(nOpen<=czDiv.cx){
		nLeftx=wx-nOpen;
		nRightx=m_rectWnd.right-nOpen;
		
		//move left partition
		m_pdcScreen->BitBlt(nLeftx,wy,nOpen,nHeight,m_pdcMemScr,
			wx,wy,SRCCOPY);
		//move right partition
		m_pdcScreen->BitBlt(m_rectWnd.right,wy,nOpen,nHeight,m_pdcMemScr,
			nRightx,wy,SRCCOPY);
		nOpen+=nSlideFactor;
		Sleep(nSlideDelay);		
	}

	int nScale=0;
	int x=wx,y=wy,w=nWidth,h=nHeight;

	// scale down the window so it disappears into a black background
	while(w>0 && h>0){
			// scale window
			m_pdcScreen->StretchBlt(x,y,w,h,m_pdcMemWnd,0,0,nWidth,nHeight,SRCCOPY);
			// fill in solid black rectangles over only the areas that show
			// part of the last scale operation.  This is better than just drawing
			// one solid rectangle over the whole area where we're manipulating
			// because we'll avoid flicker.
			m_pdcScreen->FillSolidRect(x,y,w,nScaleFactor,0x00000000);
			m_pdcScreen->FillSolidRect(x,y+h-nScaleFactor,w,nScaleFactor,0x00000000);
			m_pdcScreen->FillSolidRect(x,y,nScaleFactor,h,0x00000000);
			m_pdcScreen->FillSolidRect(x+w,y,nScaleFactor,h,0x00000000);
			x=m_rectWnd.left+nScale/2;
			y=m_rectWnd.top+nScale/2;
			w=nWidth-nScale;
			h=nHeight-nScale;
			nScale+=nScaleFactor;
			Sleep(nVanishDelay);
	}

	// slide partitions together again
	nOpen=0;
	while(nOpen<=czDiv.cx){
		//move left partition
		m_pdcScreen->BitBlt(m_rectWnd.left-czDiv.cx+nOpen,wy,czDiv.cx,nHeight,m_pdcMemScr,
			wx,wy,SRCCOPY);
		//move right partition
		m_pdcScreen->BitBlt(m_rectWnd.right-nOpen,wy,czDiv.cx,nHeight,m_pdcMemScr,
			wx+czDiv.cx,wy,SRCCOPY);

		//cover site of last left partition
		m_pdcScreen->BitBlt(nLeftx,wy,nOpen,nHeight,m_pdcMemScr,
			nLeftx,wy,SRCCOPY);
		//cover site of last right partition
		m_pdcScreen->BitBlt(m_rectWnd.right+czDiv.cx-nOpen,wy,nOpen,nHeight,m_pdcMemScr,
			m_rectWnd.right+czDiv.cx-nOpen,wy,SRCCOPY);
		Sleep(nSlideDelay);
		nOpen+=nSlideFactor;		
	}

	// execute loop code one more time if window size is odd
	if(m_rectWnd.Width()%2==1){
		m_pdcScreen->BitBlt(m_rectWnd.left-czDiv.cx+nOpen,wy,czDiv.cx,nHeight,m_pdcMemScr,
			wx,wy,SRCCOPY);
		m_pdcScreen->BitBlt(m_rectWnd.right-nOpen,wy,czDiv.cx,nHeight,m_pdcMemScr,
			wx+czDiv.cx,wy,SRCCOPY);

		// repaint original screen to avoid animation trail
		m_pdcScreen->BitBlt(nLeftx,wy,nOpen,nHeight,m_pdcMemScr,
			nLeftx,wy,SRCCOPY);
		m_pdcScreen->BitBlt(m_rectWnd.right+czDiv.cx-nOpen,wy,nOpen,nHeight,m_pdcMemScr,
			nRightx-nOpen,wy,SRCCOPY);
	}

}

/************************************************************************************
	Two partitions slide horizontally away from eachother opening into a black void.
	Zoooming out of the woid the window appears.  The partitions then close slide
	back together again behind the now fully visible window.
************************************************************************************/
void CWindowAnima::SlideAppear(int nSlideFactor, int nScaleFactor,
							   int nSlideDelay, int nAppearDelay)
{
	// make sure we can stretch blit on this device
	if(!(m_pdcScreen->GetDeviceCaps(RASTERCAPS) & RC_STRETCHBLT))
		return;

	// Do any pre-animation initialisations
	Initialise();

	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	CPoint cptWindowCenter=m_rectWnd.CenterPoint();
	CSize czDiv(m_czWnd.cx/2, m_czWnd.cy/2);
	int nHeight=m_rectWnd.Height(), nWidth=m_rectWnd.Width(),nLeftx, nRightx;
	int nOpen=0;

	// slide out two parts of the screen to make way for the window
	while(nOpen<=czDiv.cx){
		nLeftx=wx-nOpen;
		nRightx=cptWindowCenter.x+nOpen;

		m_pdcScreen->BitBlt(nLeftx,wy,czDiv.cx,nHeight,m_pdcMemScr,
			wx,wy,SRCCOPY);
		m_pdcScreen->BitBlt(nRightx,wy,czDiv.cx,nHeight,m_pdcMemScr,
			cptWindowCenter.x,wy,SRCCOPY);
		m_pdcScreen->FillSolidRect(wx+czDiv.cx-nOpen,wy,nOpen*2,nHeight,0x00000000);
		nOpen+=nSlideFactor;
		Sleep(nSlideDelay);
	}

	int nScale=(nWidth<nHeight ? nWidth : nHeight);
	int x=wx,y=wy,w=nWidth,h=nHeight;

	// scale up the window into the foreground
	while(nScale>=0){
			x=wx+nScale/2;
			y=wy+nScale/2;
			w=nWidth-nScale;
			h=nHeight-nScale;
			nScale-=nScaleFactor;
			m_pdcScreen->StretchBlt(x,y,w,h,m_pdcMemWnd,0,0,nWidth,nHeight,SRCCOPY);
			Sleep(nAppearDelay);
	}

	// print the fully sized window to the screen
	PrintWindow();

	nOpen=0;

	// close the partitions behind the window
	while(nOpen<=czDiv.cx){
		m_pdcScreen->BitBlt(m_rectWnd.left-czDiv.cx+nOpen,wy,czDiv.cx-nOpen,nHeight,m_pdcMemScr,
			wx,wy,SRCCOPY);
		m_pdcScreen->BitBlt(m_rectWnd.right,wy,czDiv.cx-nOpen,nHeight,m_pdcMemScr,
			wx+czDiv.cx+nOpen,wy,SRCCOPY);

		m_pdcScreen->BitBlt(nLeftx,wy,nOpen,nHeight,m_pdcMemScr,
			nLeftx,wy,SRCCOPY);
		m_pdcScreen->BitBlt(m_rectWnd.right+czDiv.cx-nOpen,wy,nOpen,nHeight,m_pdcMemScr,
			m_rectWnd.right+czDiv.cx-nOpen,wy,SRCCOPY);
		Sleep(nSlideDelay);
		nOpen+=nSlideFactor;		
	}

	// execute above part one last time if the window size is odd
	if(m_rectWnd.Width()%2==1){
		m_pdcScreen->BitBlt(m_rectWnd.left-czDiv.cx+nOpen,wy,czDiv.cx-nOpen,nHeight,m_pdcMemScr,
			wx,wy,SRCCOPY);
		m_pdcScreen->BitBlt(m_rectWnd.right,wy,czDiv.cx-nOpen,nHeight,m_pdcMemScr,
			wx+czDiv.cx+nOpen,wy,SRCCOPY);

		m_pdcScreen->BitBlt(nLeftx,wy,nOpen,nHeight,m_pdcMemScr,
			nLeftx,wy,SRCCOPY);
		m_pdcScreen->BitBlt(m_rectWnd.right+czDiv.cx-nOpen,wy,nOpen,nHeight,m_pdcMemScr,
			m_rectWnd.right+czDiv.cx-nOpen,wy,SRCCOPY);
	}

	// make the real window visible
	RestoreWindow(FALSE);
}

/************************************************************************************
	Split the window into four separate rectangles and send each part flying away
	from the window's center
************************************************************************************/
void CWindowAnima::Scatter4(int nDistance, int nMoveFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	int nSteps=nDistance;
	int nMove=nMoveFactor;
	int a=0,b=0;
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	CPoint cptWindowCenter=m_rectWnd.CenterPoint();
	CSize czDiv(m_czWnd.cx/2, m_czWnd.cy/2);

	int i; for(i=0;i<nSteps;i++){
		m_pdcScreen->BitBlt(wx-a,wy-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			0,0,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			czDiv.cx,0,SRCCOPY);
		m_pdcScreen->BitBlt(wx-a,wy+czDiv.cy+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			0,czDiv.cy,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy+czDiv.cy+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			czDiv.cx,czDiv.cy,SRCCOPY);

		Sleep(nSleeptime);

		// repaint original screen to avoid animation trail
		m_pdcScreen->BitBlt(wx-a,wy-b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx-a,wy-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy-b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx+czDiv.cx+a,wy-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx-a,wy+czDiv.cy+b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx-a,wy+czDiv.cy+b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy+czDiv.cy+b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx+czDiv.cx+a,wy+czDiv.cy+b,SRCCOPY);

		a+=nMove;
		b+=nMove;
	}
}

/************************************************************************************
	Four separate parts of a window fly from different directions to a central point
	where they join to make a full window.
************************************************************************************/
void CWindowAnima::ReAssemble4(int nDistance, int nMoveFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	int a=0,b=0;
	int nSteps=nDistance;
	int nMove=nMoveFactor;
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	CPoint cptWindowCenter=m_rectWnd.CenterPoint();
	CSize czDiv(m_czWnd.cx/2, m_czWnd.cy/2);
	a=nMove*nSteps;
	b=a;

	int i; for(i=0;i<nSteps;i++){
		m_pdcScreen->BitBlt(wx-a,wy-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			0,0,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			czDiv.cx,0,SRCCOPY);
		m_pdcScreen->BitBlt(wx-a,wy+czDiv.cy+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			0,czDiv.cy,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy+czDiv.cy+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			czDiv.cx,czDiv.cy,SRCCOPY);

		Sleep(nSleeptime);

		// repaint original screen to avoid animation trail
		m_pdcScreen->BitBlt(wx-a,wy-b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx-a,wy-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy-b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx+czDiv.cx+a,wy-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx-a,wy+czDiv.cy+b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx-a,wy+czDiv.cy+b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+czDiv.cx+a,wy+czDiv.cy+b,czDiv.cx,czDiv.cy,m_pdcMemScr,wx+czDiv.cx+a,wy+czDiv.cy+b,SRCCOPY);

		a-=nMove;
		b-=nMove;
	}

	RestoreWindow(FALSE);
}

/************************************************************************************
	Split the window into six separate rectangles and send each part flying away
	from the window's center
************************************************************************************/
void CWindowAnima::Scatter6(int nDistance, int nMoveFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	int nSteps=nDistance;
	int nMove=nMoveFactor;
	int a=0,b=0;
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	CPoint cptWindowCenter=m_rectWnd.CenterPoint();
	CSize czDiv(m_czWnd.cx/3, m_czWnd.cy/2);
	int xs1,ys1,xs2,ys2,xs3,ys3,xs4,ys4,xs5,ys5,xs6,ys6;
	xs1=0;
	ys1=0;
	xs2=czDiv.cx;
	ys2=0;
	xs3=czDiv.cx*2;
	ys3=0;
	xs4=0;
	ys4=czDiv.cy;
	xs5=czDiv.cx;
	ys5=czDiv.cy;
	xs6=czDiv.cx*2;
	ys6=czDiv.cy;

	int i; for(i=0;i<nSteps;i++){
		m_pdcScreen->BitBlt(wx+xs1-a,wy+ys1-b,czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs1,ys1,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs2,wy+ys2-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs2,ys2,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs3+a,wy+ys3-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs3,ys3,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs4-a,wy+ys4+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs4,ys4,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs5,wy+ys5+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs5,ys5,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs6+a,wy+ys6+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs6,ys6,SRCCOPY);

		Sleep(nSleeptime);

		// repaint original screen to avoid animation trail
		m_pdcScreen->BitBlt(wx+xs1-a,wy+ys1-b,czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs1-a,wy+ys1-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs2,wy+ys2-b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs2,wy+ys2-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs3+a,wy+ys3-b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs3+a,wy+ys3-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs4-a,wy+ys4+b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs4-a,wy+ys4+b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs5,wy+ys5+b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs5,wy+ys5+b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs6+a,wy+ys6+b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs6+a,wy+ys6+b,SRCCOPY);

		a+=nMove;
		b+=nMove;
	}
}

/************************************************************************************
	Six separate parts of a window fly from different directions to a central point
	where they join to make a full window.
************************************************************************************/
void CWindowAnima::ReAssemble6(int nDistance, int nMoveFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	int nSteps=nDistance;
	int nMove=nMoveFactor;
	int a=nMove*nSteps;
	int b=a;
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	CPoint cptWindowCenter=m_rectWnd.CenterPoint();
	CSize czDiv(m_czWnd.cx/3, m_czWnd.cy/2);
	int xs1,ys1,xs2,ys2,xs3,ys3,xs4,ys4,xs5,ys5,xs6,ys6;
	xs1=0;
	ys1=0;
	xs2=czDiv.cx;
	ys2=0;
	xs3=czDiv.cx*2;
	ys3=0;
	xs4=0;
	ys4=czDiv.cy;
	xs5=czDiv.cx;
	ys5=czDiv.cy;
	xs6=czDiv.cx*2;
	ys6=czDiv.cy;

	int i; for(i=0;i<nSteps;i++){
		m_pdcScreen->BitBlt(wx+xs1-a,wy+ys1-b,czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs1,ys1,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs2,wy+ys2-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs2,ys2,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs3+a,wy+ys3-b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs3,ys3,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs4-a,wy+ys4+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs4,ys4,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs5,wy+ys5+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs5,ys5,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs6+a,wy+ys6+b, czDiv.cx,czDiv.cy,m_pdcMemWnd,
			xs6,ys6,SRCCOPY);

		Sleep(nSleeptime);

		// repaint original screen to avoid animation trail
		m_pdcScreen->BitBlt(wx+xs1-a,wy+ys1-b,czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs1-a,wy+ys1-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs2,wy+ys2-b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs2,wy+ys2-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs3+a,wy+ys3-b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs3+a,wy+ys3-b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs4-a,wy+ys4+b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs4-a,wy+ys4+b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs5,wy+ys5+b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs5,wy+ys5+b,SRCCOPY);
		m_pdcScreen->BitBlt(wx+xs6+a,wy+ys6+b, czDiv.cx,czDiv.cy,m_pdcMemScr,
			wx+xs6+a,wy+ys6+b,SRCCOPY);

		a-=nMove;
		b-=nMove;
	}
	RestoreWindow(FALSE);
}

/************************************************************************************
	Checks that the Window pointer is not null and then captures a copy of
	the entire users screen area.
************************************************************************************/
void CWindowAnima::Initialise()
{
	ASSERT(m_pWnd!=NULL);

	// if task bar clipping is on then set the clipping region to
	// exclude drawing over the task bar else if task bar clipping WAS on
	// and and the flag is no longer set then turn task bar clipping off
	if(FlagIsSet(WA_KEEP_TASKBAR_ONTOP)){
		ToggleTaskBarOnTop(WA_TASKBAR_ON);
		m_TaskBarClippingOn=TRUE;
	} else if(m_TaskBarClippingOn) {
		ToggleTaskBarOnTop(WA_TASKBAR_OFF);
		m_TaskBarClippingOn=FALSE;
	}

	// Capture a copy of the screen within the clipping region
	CaptureScreenImage(m_pWnd);
}

/************************************************************************************
	Captures a copy of the users entire screen area and saves the data into the
	member variable m_pdcMemScr.  Also sets the dimensions of the screen in
	m_czScr.  Finally it hides the window from view, and copies the portion of the
	screen that was behind the window into the memory buffer.
************************************************************************************/
void CWindowAnima::CaptureScreenImage(CWnd *pWnd)
{
	if(m_nFlags & WA_SCR_SKIPCAPTURE)
		return;

	CBitmap bmWindow;

	ASSERT(m_pWnd!=NULL);

	// capture a copy of the screen area within our clipping region
	m_pdcMemScr->BitBlt(m_rectScr.left,m_rectScr.top,m_czScr.cx,m_czScr.cy,
		m_pdcScreen,m_rectScr.left,m_rectScr.top,SRCCOPY);

	// hide the window and capture the part of the screen that was
	// hidden behind it.  This reduces flicker if the window needs to be
	// visible again immediately after screen capture
	HideWindow();
	m_pdcMemScr->BitBlt(m_rectWnd.left,m_rectWnd.top,m_rectWnd.Width(),
		m_rectWnd.Height(),m_pdcScreen,m_rectWnd.left,m_rectWnd.top,SRCCOPY);
}

/************************************************************************************
	Captures a copy of the window image pointed to by pWnd unless the
	WA_WND_SKIPCAPTURE flag is set.  The window must be visible when 
	CaptureWindowImage() is called or the program will ASSERT in debug mode.
	When a window image is capture the size and position of the window are also
	recorded.
************************************************************************************/
void CWindowAnima::CaptureWindowImage(CWnd *pWnd)
{
	if(m_nFlags & WA_WND_SKIPCAPTURE)
		return;

	// make sure the window is visible
	ASSERT(pWnd->IsWindowVisible());

	// create a WindowDC object
	CWindowDC dcWindow(pWnd);

	// get window position & size data;
	pWnd->GetWindowRect(&m_rectWnd);

	CBitmap bmWindow;

	// copy size data to member variables
	m_czWnd.cx=m_rectWnd.Width();
	m_czWnd.cy=m_rectWnd.Height();

	// if there is already a window stored in our CWindowAnima object
	// the delete it.
	if(m_pdcMemWnd!=NULL){
		m_pdcMemWnd->SelectObject(m_pOldBitmapWnd);
		delete m_pdcMemWnd;
	}

	// create a new CDC memory object to store the image of the window
	m_pdcMemWnd=new CDC;

	// create a compbatible bitmap area to draw to
	bmWindow.CreateCompatibleBitmap(&dcWindow,m_czWnd.cx,m_czWnd.cy);

	m_pdcMemWnd->CreateCompatibleDC(&dcWindow);
	m_pOldBitmapWnd=m_pdcMemWnd->SelectObject(&bmWindow);

	// copy the image of the window into our dc memory buffer
	m_pdcMemWnd->BitBlt(0,0,m_czWnd.cx,m_czWnd.cy,&dcWindow,0,0,SRCCOPY);
}

/************************************************************************************
	Choose the direction in which to Melt a window.
************************************************************************************/
void CWindowAnima::Melt(int nDirection, int nSegments, 
						int nStagger, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	switch(nDirection){
	case WA_AUTO:
		nDirection=GetClosestSide();
		break;
	case WA_RAND:
		nDirection=GetRandomDirection(4);
		break;
	}

	switch(nDirection){
	case WA_LEFT:
		MeltLeft(nSegments, nStagger, nSleeptime);
		break;
	case WA_RIGHT:
		MeltRight(nSegments, nStagger, nSleeptime);
		break;
	case WA_UP:
		MeltUp(nSegments, nStagger, nSleeptime);
		break;
	case WA_DOWN:
		MeltDown(nSegments, nStagger, nSleeptime);
		break;
	}
}

/************************************************************************************
	Paints an image of the window onto the screen at the window's existing postion.
	When a window is processing an intensive loop, the interface sometimes remains
	blank, by printing a copy of the window to the screen instead of showing the
	actual window we avoid this.
************************************************************************************/
void CWindowAnima::PrintWindow()
{
	m_pdcScreen->BitBlt(m_rectWnd.left, m_rectWnd.top, 
		m_czWnd.cx, m_czWnd.cy, m_pdcMemWnd,0,0,SRCCOPY);
}

/************************************************************************************
	Restores the window and the proper background of the window to its existing
	location.  Internally RestoreWindow() is called with its parameter set to
	FALSE so that m_nFlags will be checked for the WA_KEEP_WINDOW_HIDDEN flag.
	Calling RestoreWindow() externally with no parameters causes the function
	to use the default value TRUE as its parameter and therefore ignore the value
	of the flags.  It is assumed that the only reason a user would call this function
	explicitly is to actually restore a window irrespective of what the flags are
	set to.
************************************************************************************/
void CWindowAnima::RestoreWindow(BOOL bIgnoreFlags)
{
	if(bIgnoreFlags || !(m_nFlags & WA_WND_SKIPRESTORE)){
		if(bIgnoreFlags || !(m_nFlags & WA_KEEP_BKGRND_HIDDEN))
			PrintImageBehindWindow();
		if(bIgnoreFlags || !(m_nFlags & WA_KEEP_WINDOW_HIDDEN))
			ShowWindow();
	}
}

/************************************************************************************
	Choose in which direction to Melt a window.
************************************************************************************/
void CWindowAnima::UnMelt(int nDirection, int nSegments,
						  int nStagger, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	switch(nDirection){
	case WA_AUTO:
		nDirection=GetClosestSide();
		break;
	case WA_RAND:
		nDirection=GetRandomDirection(4);
		break;
	}

	switch(nDirection){
	case WA_LEFT:
		UnMeltLeft(nSegments, nStagger, nSleeptime);
		break;
	case WA_RIGHT:
		UnMeltRight(nSegments, nStagger, nSleeptime);
		break;
	case WA_UP:
		UnMeltUp(nSegments, nStagger, nSleeptime);
		break;
	case WA_DOWN:
		UnMeltDown(nSegments, nStagger, nSleeptime);
		break;
	}

	RestoreWindow(FALSE);
}

/************************************************************************************
	Simply calls the CWnd function ShowWindow to hide the window from view.
************************************************************************************/
void CWindowAnima::HideWindow()
{
	// don't hide the window if the WA_SKIPHIDEONCAPTURE flag is set
	if(!(m_nFlags & WA_SKIPHIDEONCAPTURE)){
		m_pWnd->ShowWindow(SW_HIDE);

		// sleep for 10 milliseconds because we generally do a screen capture
		// after hiding the window.  Windows doesn't always hide the window as
		// quickly as we'd like so sometimes we get half the window remaining
		// splashed across the screen.  By sleeping we give Windows time to fully
		// hide the window and if you can't wait an extra 10 millisecs then window
		// animations are not for you anyway!!!!
		Sleep(10);
	}
}

/************************************************************************************
	Prints the correct background that a window should have when it has been
	restored subsequent to an animation.
************************************************************************************/
void CWindowAnima::PrintImageBehindWindow()
{
	m_pdcScreen->BitBlt(m_rectWnd.left, m_rectWnd.top, 
		m_czWnd.cx, m_czWnd.cy, m_pdcMemScr,m_rectWnd.left, m_rectWnd.top,
		SRCCOPY);
}

/************************************************************************************
	Creates a vertical blinds disappearing effect on the window
************************************************************************************/
void CWindowAnima::BlindVert(int nSegments, int nGapFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int segWidth=m_czWnd.cx/nSegments;
	int istop=m_czWnd.cx;
	int stepcum=0;
	int nGapWidth=nGapFactor;

	PrintWindow();

	for(int gap=nGapWidth;stepcum<segWidth;gap+=nGapWidth){
		int i; for(i=0;i<=istop;i+=segWidth){
			m_pdcScreen->BitBlt(wx+i+stepcum,wy, gap,m_czWnd.cy,
				m_pdcMemScr, wx+i+stepcum, wy, SRCCOPY);
		}
		stepcum+=gap;
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Creates a vertical blinds appearing effect on the window
************************************************************************************/
void CWindowAnima::UnBlindVert(int nSegments, int nGapFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int segWidth=m_czWnd.cx/nSegments;
	int istop=m_czWnd.cx;
	int stepcum=0;
	int nGapWidth=nGapFactor;

	for(int gap=nGapWidth;stepcum<segWidth;gap+=nGapWidth){
		int i; for(i=0;i<=istop;i+=segWidth){
			m_pdcScreen->BitBlt(wx+i+stepcum,wy, gap,m_czWnd.cy,
				m_pdcMemWnd, i+stepcum, 0, SRCCOPY);
		}
		stepcum+=gap;
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Melts the window segment by segment towards the left of the screen
************************************************************************************/
void CWindowAnima::MeltLeft(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int cumulator=0, cumulator2=0;
	int step=nDrop;

	// calculates how many iterations we'll need to get the whole window
	// off screen
	int nVisibleLimit=(m_rectWnd.right/step)+3;

	// calculate the width of each segment based on the number of segments given
	int segWidth=m_czWnd.cy/nSegments;

	if(m_czWnd.cy%nSegments!=0)
		nSegments++;

	// draw a copy of the window onto the screen
	PrintWindow();

	// while the window is still visible
	int a;	
	for(a=0;a<nVisibleLimit;a++){
		// foreach segment
		int seg;
		for(seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nSegOffset=0;
			int nStepHeight=0;
			// foreach segment that is now staggered
			int i;
			for(i=0;i<seg;i++){
				int hd=wx+nStepHeight-cumulator;
				if(hd+m_czWnd.cx>0) {
					m_pdcScreen->BitBlt(hd,wy+nSegOffset,m_czWnd.cx,segWidth,
						m_pdcMemWnd,0,nSegOffset,SRCCOPY);
					Sleep(nSleeptime);
				}
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}

			nSegOffset=0;
			nStepHeight=0;

			// repaint original screen to avoid animation trail.  Here
			// we only paint nDrop length of the segment which further
			// speeds up the process
			for(i=0;i<seg;i++){
				int hd=m_czWnd.cx+wx+nStepHeight-cumulator2;
				if(hd+m_czWnd.cx>0)
					m_pdcScreen->BitBlt(hd,wy+nSegOffset,step,segWidth,
						m_pdcMemScr,hd,wy+nSegOffset,SRCCOPY);
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}
			cumulator+=step;
			cumulator2=cumulator;
		}
	}
}

/************************************************************************************
	Melts the window segment by segment towards the right of the screen
************************************************************************************/
void CWindowAnima::MeltRight(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int cumulator=0, cumulator2=0;
	int step=nDrop;

	int nVisibleLimit=m_czScr.cx-wx/step;

	int segWidth=m_czWnd.cy/nSegments;

	if(m_czWnd.cy%nSegments!=0)
		nSegments++;

	PrintWindow();

	int a;
	for(a=0;a<nVisibleLimit;a++){
		int seg;
		for(seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nSegOffset=0;
			int nStepHeight=0;
			int i;
			for(i=0;i<seg;i++){
				int hd=wx+cumulator-nStepHeight;
				if(hd<=m_czScr.cx) {
					m_pdcScreen->BitBlt(hd,wy+nSegOffset,m_czWnd.cx,segWidth,
						m_pdcMemWnd,0,nSegOffset,SRCCOPY);
					Sleep(nSleeptime);
				}
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}

			nSegOffset=0;
			nStepHeight=0;

			for(i=0;i<seg;i++){
				int hd=wx+cumulator2-nStepHeight;
				if(hd<=m_czScr.cx)
					m_pdcScreen->BitBlt(hd,wy+nSegOffset,step,segWidth,
						m_pdcMemScr,hd,wy+nSegOffset,SRCCOPY);
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}
			cumulator2=cumulator;
			cumulator+=step;
		}
	}
}

/************************************************************************************
	Melts the window segment by segment towards the bottom of the screen
************************************************************************************/
void CWindowAnima::MeltDown(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int cumulator=0, cumulator2=0;
	int step=nDrop;

	int nVisibleLimit=((m_czScr.cy-wy)/step)+2;
	int segWidth=m_czWnd.cx/nSegments;

	if(m_czWnd.cx%nSegments!=0)
		nSegments++;

	PrintWindow();

	for(int a=0;a<nVisibleLimit;a++){
		for(int seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nSegOffset=0;
			int nStepHeight=0;
			int i; for(i=0;i<seg;i++){
				int hd=wy+cumulator-nStepHeight;
				if(hd<=m_czScr.cy) {
					m_pdcScreen->BitBlt(wx+nSegOffset,hd,segWidth,m_czWnd.cy,
						m_pdcMemWnd,nSegOffset,0,SRCCOPY);
					Sleep(nSleeptime);
				}
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}

			nSegOffset=0;
			nStepHeight=0;

			for(i=0;i<seg;i++){
				int hd=wy+cumulator2-nStepHeight;
				if(hd<=m_czScr.cy)
					m_pdcScreen->BitBlt(wx+nSegOffset,hd, segWidth,step,
						m_pdcMemScr,wx+nSegOffset,hd,SRCCOPY);
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}
			cumulator2=cumulator;
			cumulator+=step;
		}
	}
}

/************************************************************************************
	Melts the window segment by segment towards the top of the screen
************************************************************************************/
void CWindowAnima::MeltUp(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int cumulator=0, cumulator2=0;
	int step=nDrop;

	int nVisibleLimit=((m_rectWnd.bottom)/step)+3;
	int segWidth=m_czWnd.cx/nSegments;

	if(m_czWnd.cy%nSegments!=0)
		nSegments++;

	PrintWindow();

	for(int a=0;a<nVisibleLimit;a++){
		for(int seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nSegOffset=0;
			int nStepHeight=0;
			int i; for(i=0;i<seg;i++){
				int hd=wy+nStepHeight-cumulator;
				if(hd>=0-m_czWnd.cy) {
					m_pdcScreen->BitBlt(wx+nSegOffset,hd,segWidth,m_czWnd.cy,
						m_pdcMemWnd,nSegOffset,0,SRCCOPY);
					Sleep(nSleeptime);
				}
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}

			nSegOffset=0;
			nStepHeight=0;

			for(i=0;i<seg;i++){
				int hd=wy+m_czWnd.cy+nStepHeight-cumulator2;
				if(hd>-step)
					m_pdcScreen->BitBlt(wx+nSegOffset,hd, segWidth,step,
						m_pdcMemScr,wx+nSegOffset,hd,SRCCOPY);
				nSegOffset+=segWidth;
				nStepHeight+=step;
			}
			cumulator2=cumulator;
			cumulator+=step;
		}
	}
}

/************************************************************************************
	Returns the direction a window's top-left corner should take to reach the closest
	edge of the screen.
************************************************************************************/
int CWindowAnima::GetClosestSide()
{
	// check if position is closer to top edge than bottom edge
	int ClosestY=(m_rectWnd.top < (m_czScr.cy-m_rectWnd.top) ? 
		m_rectWnd.top : (m_czScr.cy-m_rectWnd.top));
	// check if position is closer to left edge than right edge
	int ClosestX=(m_rectWnd.left < (m_czScr.cx-m_rectWnd.left) ? 
		m_rectWnd.left : (m_czScr.cx-m_rectWnd.left));

	// check if postion is closer to a horizontal edge than a vertical edge
	if(ClosestX < ClosestY)
		return (ClosestX==m_rectWnd.left ? WA_LEFT : WA_RIGHT);
	else
		return (ClosestY==m_rectWnd.top ? WA_UP : WA_DOWN);
}

/************************************************************************************
	UnMelts the window segment by segment from the left of the screen to the right
************************************************************************************/
void CWindowAnima::UnMeltLeft(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nDrop;
	int cumulator=0-m_czWnd.cx;
	int cumulator2=cumulator-step;

	int segWidth=m_czWnd.cy/nSegments;

	if(m_czWnd.cy%nSegments!=0)
		nSegments++;

	int nVisibleLimit=((m_czWnd.cx+m_rectWnd.left)/step)+2;

	for(int a=0;a<nVisibleLimit;a++){
		for(int seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nStepHeight=0;
			int nStepOffset=0;
			int i; for(i=0;i<seg;i++){
				int hd=cumulator-nStepHeight;
				if(hd<wx) {
					m_pdcScreen->BitBlt(hd,wy+nStepOffset,m_czWnd.cx,segWidth,
						m_pdcMemWnd,0,nStepOffset,SRCCOPY);
					Sleep(nSleeptime);
				} else {
					m_pdcScreen->BitBlt(wx,wy+nStepOffset,m_czWnd.cx,segWidth,
						m_pdcMemWnd,0,nStepOffset,SRCCOPY);
					Sleep(nSleeptime);						
				}
				nStepHeight+=step;
				nStepOffset+=segWidth;
			}

			nStepHeight=0;
			nStepOffset=0;

			for(i=0;i<seg;i++){
				int hd=cumulator2-nStepHeight;
				if(hd<=m_rectWnd.left)
					m_pdcScreen->BitBlt(hd,wy+nStepOffset,step,segWidth,
						m_pdcMemScr,hd,wy+nStepOffset,SRCCOPY);

				nStepHeight+=step;
				nStepOffset+=segWidth;
			}
			cumulator2=cumulator;
			cumulator+=step;
		}
	}
}

/************************************************************************************
	UnMelts the window segment by segment from the right of the screen to the left
************************************************************************************/
void CWindowAnima::UnMeltRight(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nDrop;
	int cumulator=m_czScr.cx-m_rectWnd.left;
	int cumulator2=cumulator-step;

	int segWidth=m_czWnd.cy/nSegments;

	if(m_czWnd.cy%nSegments!=0)
		nSegments++;

	int nVisibleLimit=((m_czScr.cx-m_rectWnd.left)/step)+1;

	for(int a=0;a<nVisibleLimit;a++){
		for(int seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nStepHeight=0;
			int nStepOffset=0;
			int i; for(i=0;i<seg;i++){
				int hd=wx+cumulator+nStepHeight;
				if(hd>=wx) {
					m_pdcScreen->BitBlt(hd,wy+nStepOffset,m_czWnd.cx,segWidth,
						m_pdcMemWnd,0,nStepOffset,SRCCOPY);
					Sleep(nSleeptime);
				} else {
					m_pdcScreen->BitBlt(wx,wy+nStepOffset,m_czWnd.cx,segWidth,
						m_pdcMemWnd,0,nStepOffset,SRCCOPY);
					Sleep(nSleeptime);						
				}
				nStepHeight+=step;
				nStepOffset+=segWidth;
			}

			nStepHeight=0;
			nStepOffset=0;

			for(i=0;i<seg;i++){
				int hd=cumulator2+nStepHeight+wx+m_czWnd.cx;
				if(hd>=m_rectWnd.left-step)
					m_pdcScreen->BitBlt(hd,wy+nStepOffset,step,segWidth,
						m_pdcMemScr,hd,wy+nStepOffset,SRCCOPY);

				nStepHeight+=step;
				nStepOffset+=segWidth;
			}
			cumulator-=step;
			cumulator2=cumulator-step;
		}
	}
}

/************************************************************************************
	UnMelts the window segment by segment from the bottom of the screen upwards
************************************************************************************/
void CWindowAnima::UnMeltUp(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nDrop;
	int cumulator=m_czScr.cy+m_rectWnd.top;
	int cumulator2=cumulator-step;

	int segWidth=m_czWnd.cx/nSegments;

	if(m_czWnd.cx%nSegments!=0)
		nSegments++;

	int nVisibleLimit=((m_czScr.cy+wy)/step)+2;

	for(int a=0;a<nVisibleLimit;a++){
		for(int seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nStepHeight=0;
			int nStepOffset=0;
			int i; for(i=0;i<seg;i++){
				int hd=wy-nStepHeight-cumulator;
				if(hd<=wy) {
					m_pdcScreen->BitBlt(wx+nStepOffset,hd,segWidth,m_czWnd.cy,
						m_pdcMemWnd,nStepOffset,0,SRCCOPY);
					Sleep(nSleeptime);
				} else {
					m_pdcScreen->BitBlt(wx+nStepOffset,wy,segWidth,m_czWnd.cy,
						m_pdcMemWnd,nStepOffset,0,SRCCOPY);
					Sleep(nSleeptime);						
				}
				nStepHeight+=step;
				nStepOffset+=segWidth;
			}

			nStepHeight=0;
			nStepOffset=0;

			for(i=0;i<seg;i++){
				int hd=wy-cumulator2-nStepHeight;
				if(hd<=m_rectWnd.top)
					m_pdcScreen->BitBlt(wx+nStepOffset,hd,segWidth,step,
						m_pdcMemScr,wx+nStepOffset,hd,SRCCOPY);

				nStepHeight+=step;
				nStepOffset+=segWidth;
			}
			cumulator2=cumulator;
			cumulator-=step;
		}
	}
}

/************************************************************************************
	UnMelts the window segment by segment from the top of the screen downwards
************************************************************************************/
void CWindowAnima::UnMeltDown(int nSegments, int nDrop, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nDrop;
	int cumulator=m_czScr.cy-m_rectWnd.top;
	int cumulator2=cumulator-step;

	int segWidth=m_czWnd.cx/nSegments;

	if(m_czWnd.cx%nSegments!=0)
		nSegments++;

	int nVisibleLimit=((m_czScr.cy-wy)/step)+2;

	for(int a=0;a<nVisibleLimit;a++){
		for(int seg=0;seg<nSegments;seg++){
			if(a>0)
				seg=nSegments;
			int nStepHeight=0;
			int nStepOffset=0;
			int i; for(i=0;i<seg;i++){
				int hd=wy+cumulator+nStepHeight;
				if(hd>=wy) {
					m_pdcScreen->BitBlt(wx+nStepOffset,hd,segWidth,m_czWnd.cy,
						m_pdcMemWnd,nStepOffset,0,SRCCOPY);
					Sleep(nSleeptime);
				} else {
					m_pdcScreen->BitBlt(wx+nStepOffset,wy,segWidth,m_czWnd.cy,
						m_pdcMemWnd,nStepOffset,0,SRCCOPY);
					Sleep(nSleeptime);						
				}
				nStepHeight+=step;
				nStepOffset+=segWidth;
			}

			nStepHeight=0;
			nStepOffset=0;

			for(i=0;i<seg;i++){
				int hd=cumulator2+nStepHeight+wy+m_czWnd.cy;
				if(hd>=m_rectWnd.bottom-step)
					m_pdcScreen->BitBlt(wx+nStepOffset,hd,segWidth,step,
						m_pdcMemScr,wx+nStepOffset,hd,SRCCOPY);

				nStepHeight+=step;
				nStepOffset+=segWidth;
			}
			cumulator-=step;
			cumulator2=cumulator-step;
		}
	}
}

/************************************************************************************
	Wipes the window into oblivion from right to left
************************************************************************************/
void CWindowAnima::WipeLeft(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;
	int nEndofWnd=m_rectWnd.right;

	// paint a copy of the window onto the screen
	PrintWindow();

	// while our leftside indicator has not reached
	// the right side, paint the area behind the window
	// over the image of the window thereby making it
	// disappear
	int i; for(i=wx;i<=nEndofWnd;i+=step){
		m_pdcScreen->BitBlt(i,wy, step,m_czWnd.cy,
			m_pdcMemScr, i, wy, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Wipes the window into oblivion from left to right
************************************************************************************/
void CWindowAnima::WipeRight(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;
	int nStartofWnd=wx;

	PrintWindow();

	int i; for(i=m_rectWnd.right;i>=nStartofWnd;i-=step){
		m_pdcScreen->BitBlt(i,wy, step,m_czWnd.cy,
			m_pdcMemScr, i, wy, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Wipes the window into oblivion from the top down
************************************************************************************/
void CWindowAnima::WipeDown(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;
	int nBaseofWnd=m_rectWnd.bottom;

	PrintWindow();

	int i; for(i=wy;i<=nBaseofWnd;i+=step){
		m_pdcScreen->BitBlt(wx,i, m_czWnd.cx,step,
			m_pdcMemScr,wx, i, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Wipes the window into oblivion from the bottom up
************************************************************************************/
void CWindowAnima::WipeUp(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;
	int nTopofWnd=wy-step;

	PrintWindow();

	int i; for(i=m_rectWnd.bottom;i>=nTopofWnd;i-=step){
		m_pdcScreen->BitBlt(wx,i, m_czWnd.cx,step,
			m_pdcMemScr,wx, i, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Chooses which Wipe animation to perform
************************************************************************************/
void CWindowAnima::Wipe(int nDirection, int nWipeFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	if(nDirection==WA_RAND)
		nDirection=GetRandomDirection(6);

	switch(nDirection){
	case WA_LEFT:
		WipeLeft(nWipeFactor, nSleeptime);
		break;
	case WA_RIGHT:
		WipeRight(nWipeFactor, nSleeptime);
		break;
	case WA_UP:
		WipeUp(nWipeFactor, nSleeptime);
		break;
	case WA_DOWN:
		WipeDown(nWipeFactor, nSleeptime);
		break;
	case WA_HORZ:
		WipeHorz(nWipeFactor, nSleeptime);
		break;
	case WA_VERT:
		WipeVert(nWipeFactor, nSleeptime);
		break;
	}
}

/************************************************************************************
	UnWipes the window into view from left to right
************************************************************************************/
void CWindowAnima::UnWipeLeft(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	int i; for(i=0;i<=m_czWnd.cx;i+=step){
		m_pdcScreen->BitBlt(m_rectWnd.right-i,wy, step,m_czWnd.cy,
			m_pdcMemWnd, m_czWnd.cx-i, 0, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	UnWipes the window into view from right to left
************************************************************************************/
void CWindowAnima::UnWipeRight(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	int i; for(i=0;i<=m_czWnd.cx;i+=step){
		m_pdcScreen->BitBlt(wx+i,wy, step,m_czWnd.cy,
			m_pdcMemWnd, i, 0, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	UnWipes the window into view from the bottom up
************************************************************************************/
void CWindowAnima::UnWipeUp(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	int i; for(i=0;i<=m_czWnd.cx;i+=step){
		m_pdcScreen->BitBlt(wx,m_rectWnd.bottom-i, m_czWnd.cx,step,
			m_pdcMemWnd, 0, m_czWnd.cy-i, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	UnWipes the window into view from the top down
************************************************************************************/
void CWindowAnima::UnWipeDown(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	int i; for(i=0;i<=m_czWnd.cx;i+=step){
		m_pdcScreen->BitBlt(wx,wy+i, m_czWnd.cx,step,
			m_pdcMemWnd, 0, i, SRCCOPY);
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	UnWipes the window into view from the top and bottom ends
************************************************************************************/
void CWindowAnima::UnWipeHorz(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	int nSplit=m_czWnd.cy/2;

	int i=nSplit;
	int j=nSplit;
	for(int k=0; k<nSplit; k+=step){
		m_pdcScreen->BitBlt(wx, wy+i,m_czWnd.cx,step,
			m_pdcMemWnd,0,i,  SRCCOPY);
		m_pdcScreen->BitBlt(wx, wy+j,m_czWnd.cx,step,
			m_pdcMemWnd,0,j,  SRCCOPY);
		Sleep(nSleeptime);
		i-=step;
		j+=step;
	}
}

/************************************************************************************
	UnWipes the window into view from the left and right sides
************************************************************************************/
void CWindowAnima::UnWipeVert(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	int nSplit=m_czWnd.cx/2;

	int i=nSplit;
	int j=nSplit;
	for(int k=0; k<nSplit; k+=step){
		m_pdcScreen->BitBlt(wx+i, wy,step,m_czWnd.cy,
			m_pdcMemWnd,i,0,  SRCCOPY);
		m_pdcScreen->BitBlt(wx+j, wy,step,m_czWnd.cy,
			m_pdcMemWnd,j,0,  SRCCOPY);
		Sleep(nSleeptime);
		i-=step;
		j+=step;
	}
}

/************************************************************************************
	Chooses which UnWipe animation to perform.
************************************************************************************/
void CWindowAnima::UnWipe(int nDirection, int nWipeFactor, 
						  int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	if(nDirection==WA_RAND)
		nDirection=GetRandomDirection(6);

	switch(nDirection){
	case WA_LEFT:
		UnWipeLeft(nWipeFactor, nSleeptime);
		break;
	case WA_RIGHT:
		UnWipeRight(nWipeFactor, nSleeptime);
		break;
	case WA_UP:
		UnWipeUp(nWipeFactor, nSleeptime);
		break;
	case WA_DOWN:
		UnWipeDown(nWipeFactor, nSleeptime);
		break;
	case WA_HORZ:
		UnWipeHorz(nWipeFactor, nSleeptime);
		break;
	case WA_VERT:
		UnWipeVert(nWipeFactor, nSleeptime);
		break;
	}

	RestoreWindow(FALSE);
}

/************************************************************************************
	Wipes the window into oblivion from the top and bottom ends
************************************************************************************/
void CWindowAnima::WipeHorz(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	PrintWindow();

	// add on an extra iteration to make sure it all fully
	// disappears
	int nSplit=(m_czWnd.cy/2)+step;

	int i=m_rectWnd.bottom;
	int j=m_rectWnd.top;
	for(int k=0; k<=nSplit; k+=step){
		m_pdcScreen->BitBlt(wx,i, m_czWnd.cx,step,
			m_pdcMemScr,wx, i, SRCCOPY);
		m_pdcScreen->BitBlt(wx,j, m_czWnd.cx,step,
			m_pdcMemScr,wx, j, SRCCOPY);
		Sleep(nSleeptime);
		i-=step;
		j+=step;
	}
}

/************************************************************************************
	Wipes the window into oblivion from the left and right sides.
************************************************************************************/
void CWindowAnima::WipeVert(int nWipeFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int step=nWipeFactor;

	PrintWindow();

	// add on an extra iteration to make sure it all fully
	// disappears
	int nSplit=(m_czWnd.cx/2)+step;

	int i=m_rectWnd.right;
	int j=m_rectWnd.left;
	for(int k=0; k<=nSplit; k+=step){
		m_pdcScreen->BitBlt(i, wy,step,m_czWnd.cy,
			m_pdcMemScr,i,wy,  SRCCOPY);
		m_pdcScreen->BitBlt(j, wy,step,m_czWnd.cy,
			m_pdcMemScr,j,wy,  SRCCOPY);
		Sleep(nSleeptime);
		i-=step;
		j+=step;
	}
}

/************************************************************************************
	Grab a copy of the screen that another CWindowAnima object has gone to all the
	trouble of capturing.  Make sure (in debug mode) that some idiot hasn't passed
	us a pointer to an CWindowAnima object that hasn't got a screen image.
************************************************************************************/
BOOL CWindowAnima::CopyScreenCapture(CWindowAnima *pWA)
{
	ASSERT(pWA->m_pdcMemScr!=NULL);
	return InjectScreenImage(pWA->m_pdcMemScr);
}

/************************************************************************************
	Copy the image from the CDC object pointed to by pdcMemWnd into our member
	DC object m_dcMemWnd and update our member variables describing the windows
	position and size;
************************************************************************************/
BOOL CWindowAnima::InjectWindowImage(CDC *pdcMemWnd, CRect *prectWnd)
{
	CBitmap bmWindow;

	// get the width and height of the window in the other CWindowAnima object
	m_czWnd.cx=prectWnd->Width();
	m_czWnd.cy=prectWnd->Height();

	// copy it's position and size
	m_rectWnd.CopyRect(prectWnd);

	// remove our old window image if we had one
	if(m_pdcMemWnd!=NULL){
		m_pdcMemWnd->SelectObject(m_pOldBitmapWnd);
		delete m_pdcMemWnd;
	}

	m_pdcMemWnd=new CDC;

	bmWindow.CreateCompatibleBitmap(pdcMemWnd,m_czWnd.cx,m_czWnd.cy);

	m_pdcMemWnd->CreateCompatibleDC(pdcMemWnd);
	m_pOldBitmapWnd=m_pdcMemWnd->SelectObject(&bmWindow);

	// copy the window image from the other CWindowAnima object into our own
	// offscreen window image memory
	return m_pdcMemWnd->BitBlt(0,0,m_czWnd.cx,m_czWnd.cy,pdcMemWnd,0,0,SRCCOPY);
}

/************************************************************************************
	Replace a window's image and size with an image resource identified by
	nResID.  Useful if you wanted to animate the initial appearance of a window
	whose image has not been captured before.  An image of the window could be
	stored as a resource within the application.
************************************************************************************/
BOOL CWindowAnima::ReplaceWindowImage(UINT nResID)
{
	CBitmap bmWindow;

	// load the bitmap into the object
	BOOL bResult=bmWindow.LoadBitmap(nResID);

	if(bResult){
		BITMAP bitmapData;
		// get the bitmap dimensions
		bmWindow.GetBitmap(&bitmapData);
		SetWindowSize(bitmapData.bmWidth, bitmapData.bmHeight);

		// get rid of the old window image is one existed
		if(m_pdcMemWnd!=NULL){
			m_pdcMemWnd->SelectObject(m_pOldBitmapWnd);
			delete m_pdcMemWnd;
		}

		m_pdcMemWnd=new CDC;

		m_pdcMemWnd->CreateCompatibleDC(NULL);
		//place the bitmap image into our memory DC for the window
		m_pOldBitmapWnd=m_pdcMemWnd->SelectObject(&bmWindow);
	}

	return bResult;
}

/************************************************************************************
	Copy the image from the CDC object pointed to by pdcMemScr into our member
	DC object m_dcMemScr and update our member variables describing the screen's
	size;
************************************************************************************/
BOOL CWindowAnima::InjectScreenImage(CDC *pdcMemScr)
{
	CBitmap bmWindow;
	CRect rectWindow;

	if(m_pdcMemScr!=NULL){
		m_pdcMemScr->SelectObject(m_pOldBitmapScr);
		delete m_pdcMemScr;
	}

	m_pdcMemScr=new CDC;

	CRect ClipRect;
	// get the other CWindowAnima object's clipping region
	pdcMemScr->GetClipBox(&ClipRect);

	// set the screen dimensions to those of the other CWindowAnima object
	SetScreenDimensions(ClipRect);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(m_pdcScreen,m_czScr.cx, m_czScr.cy);

	// create compatible memory buffer of the screen dc
	m_pdcMemScr->CreateCompatibleDC(m_pdcScreen);

	// get a pointer to our original screen image
	m_pOldBitmapScr=m_pdcMemScr->SelectObject(&bitmap);

	// set the clipping region equal to that of the other CWindowAnima object
	SetClippingRegion(ClipRect);

	// capture a copy of the screen within the clipping region
	return m_pdcMemScr->BitBlt(m_rectScr.left,m_rectScr.top,m_czScr.cx,
		m_czScr.cy,pdcMemScr,m_rectScr.left,m_rectScr.top,SRCCOPY);
}

/************************************************************************************
	Grab a copy of the window that another CWindowAnima object has gone to all the
	trouble of capturing.  Make sure (in debug mode) that some idiot hasn't passed
	us a pointer to an CWindowAnima object that hasn't got a window image.
************************************************************************************/
BOOL CWindowAnima::CopyWindowCapture(CWindowAnima *pWA)
{
	ASSERT(pWA->m_pdcMemWnd!=NULL);
	return InjectWindowImage(pWA->m_pdcMemWnd, &pWA->m_rectWnd);
}


/************************************************************************************
	Simply call the CWnd function ShowWindow with the SW_SHOW parameter on our
	member variable m_pWnd which holds the pointer to the window we are
	animating
************************************************************************************/
void CWindowAnima::ShowWindow()
{
	m_pWnd->ShowWindow(SW_SHOW);
}

/************************************************************************************
	Called by the constructors to initialise the member variables before any
	animation can be done.
************************************************************************************/
void CWindowAnima::InitialSetup()
{
	// get a dc to the entire screen
	m_pdcScreen=new CClientDC(NULL);
	m_pdcMemWnd=NULL;
	m_pdcMemScr=NULL;
	m_pWnd=NULL;
	m_nFlags=0x0;
	m_TaskBarClippingOn=FALSE;
	m_pdcMemScr=new CDC;

	//set the clipping region (initally the whole screen);
	CRect rectScreen(0,0,GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN));

	// set the screen dimensions
	SetScreenDimensions(rectScreen);

	CBitmap bitmap;
	// create a bitmap whose dimensions are equal to that of the screen
	bitmap.CreateCompatibleBitmap(m_pdcScreen,m_czScr.cx, m_czScr.cy);

	// create compatible memory buffer of the screen dc
	m_pdcMemScr->CreateCompatibleDC(m_pdcScreen);

	// get a pointer to our original bitmap object
	m_pOldBitmapScr=m_pdcMemScr->SelectObject(&bitmap);
}

/************************************************************************************
	Sets the window to be animated and captures an image of the window.  ASSERTs if
	the window to be animated is invalid.
************************************************************************************/
void CWindowAnima::SetWindow(CWnd *pWnd)
{
	ASSERT(pWnd!=NULL);
	m_pWnd=pWnd;
	CaptureWindowImage(m_pWnd);
}

/************************************************************************************
	Returns a pointer to the window currently set for animation
************************************************************************************/
CWnd* CWindowAnima::GetWindow()
{
	return m_pWnd;
}

/************************************************************************************
	Repositions a window to the new co-ordinates specified by x and y and updates
	internal variables that keep track of window position.
************************************************************************************/
void CWindowAnima::MoveWindowPosition(int x, int y)
{
	m_pWnd->MoveWindow(x,y,m_czWnd.cx, m_czWnd.cy, TRUE);
	m_rectWnd.OffsetRect(x-m_rectWnd.left,y-m_rectWnd.top);
}

/************************************************************************************
	Sets the member flags variable with the nFlags parameter.  Returns the current
	state of the flags.
************************************************************************************/
UINT CWindowAnima::FlagSet(UINT nFlags)
{
	m_nFlags|=nFlags;

	return m_nFlags;
}

/************************************************************************************
	Unsets the member flags variable with the nFlags parameter.  Returns the current
	state of the flags
************************************************************************************/
UINT CWindowAnima::FlagUnset(UINT nFlags)
{
	m_nFlags&=~nFlags;

	return m_nFlags;
}

/************************************************************************************
	Returns TRUE / FALSE depending on whether a flag or set of flags is set.
************************************************************************************/
BOOL CWindowAnima::FlagIsSet(UINT nFlags)
{
	return m_nFlags & nFlags;
}

/************************************************************************************
	Returns one random direction from a possible number of nDirections.  Currently
	4 or 6.  They include (left,right,up,down) when nDirections=4 and include
	(vertical, horizontal) when nDirections=6.
************************************************************************************/
int CWindowAnima::GetRandomDirection(int nDirections)
{
   srand((unsigned)time(NULL));
   return rand()%nDirections;
}

/************************************************************************************
	Creates a horizontal blinds disappearing effect on the window
************************************************************************************/
void CWindowAnima::BlindHorz(int nSegments, int nGapFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int segWidth=m_czWnd.cy/nSegments;
	int istop=m_czWnd.cy;
	int stepcum=0;
	int nGapWidth=nGapFactor;

	PrintWindow();

	for(int gap=nGapWidth;stepcum<segWidth;gap+=nGapWidth){
		int i; for(i=0;i<=istop;i+=segWidth){
			m_pdcScreen->BitBlt(wx,wy+i+stepcum, m_czWnd.cx,gap,
				m_pdcMemScr, wx, wy+i+stepcum, SRCCOPY);
		}
		stepcum+=gap;
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Creates a horizontal blinds appearing effect on the window
************************************************************************************/
void CWindowAnima::UnBlindHorz(int nSegments, int nGapFactor, int nSleeptime)
{
	int wx=m_rectWnd.left, wy=m_rectWnd.top;
	int segWidth=m_czWnd.cy/nSegments;
	int istop=m_czWnd.cy;
	int stepcum=0;
	int nGapWidth=nGapFactor;

	for(int gap=nGapWidth;stepcum<segWidth;gap+=nGapWidth){
		int i; for(i=0;i<=istop;i+=segWidth){
			m_pdcScreen->BitBlt(wx,wy+i+stepcum, m_czWnd.cx,gap,
				m_pdcMemWnd, 0, i+stepcum, SRCCOPY);
		}
		stepcum+=gap;
		Sleep(nSleeptime);
	}
}

/************************************************************************************
	Chooses which type of Blind effect to perform.
************************************************************************************/
void CWindowAnima::Blind(int nDirection, int nSegments, int nGapFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	switch(nDirection){
	case WA_HORZ:
		BlindHorz(nSegments, nGapFactor, nSleeptime);
		break;
	case WA_VERT:
		BlindVert(nSegments, nGapFactor, nSleeptime);
		break;
	}
}

/************************************************************************************
	Chooses which type of UnBlind effect to perform.
************************************************************************************/
void CWindowAnima::UnBlind(int nDirection, int nSegments, int nGapFactor, int nSleeptime)
{
	// Do any pre-animation initialisations
	Initialise();

	switch(nDirection){
	case WA_HORZ:
		UnBlindHorz(nSegments, nGapFactor, nSleeptime);
		break;
	case WA_VERT:
		UnBlindVert(nSegments, nGapFactor, nSleeptime);
		break;
	}

	RestoreWindow(FALSE);
}

/************************************************************************************
	Replace a window's image and size with an image contained in a CDC object.
	Useful if you wanted to animate the initial appearance of a window
	whose image has not been captured before.  An image of the window could be
	stored as a resource within the application.	
************************************************************************************/
BOOL CWindowAnima::ReplaceWindowImage(CDC *pdc)
{
	CRect dcRect;
	// get the other pdc's clipping region and use that as the window size
	// and postion
	pdc->GetClipBox(&dcRect);

	// call InjectWindowImage to set the new window image.
	return InjectWindowImage(pdc, &dcRect);
}

/************************************************************************************
	Sets the windows size by updating internal member variables relating to size
	and position.
************************************************************************************/
void CWindowAnima::SetWindowSize(int nWidth, int nHeight)
{
		CDC dc;
		m_czWnd.cx=nWidth;
		m_czWnd.cy=nHeight;
		m_rectWnd.right=m_rectWnd.left+m_czWnd.cx;
		m_rectWnd.bottom=m_rectWnd.top+m_czWnd.cy;
}

/************************************************************************************
	Sets the clipping region rectangle for the animation and updates the
	screen dimensions
************************************************************************************/
BOOL CWindowAnima::SetClippingRegion(CRect &ClipRect)
{
	CRgn ClipRgn;
	
	ClipRgn.CreateRectRgnIndirect(ClipRect);

	ASSERT(m_pdcScreen!=NULL && m_pdcMemScr!=NULL);

	// Possible change here is to set the clipping region only on the
	// screen dc.  Dunno if putting a clipping region on the memorydc
	// causes a performance penalty
	if(m_pdcScreen->SelectObject(&ClipRgn)!=ERROR &&
		m_pdcMemScr->SelectObject(&ClipRgn)!=ERROR){

		SetScreenDimensions(ClipRect);

		return TRUE;
	}

	return FALSE;
}

/************************************************************************************
	Overloaded version of SetClippingRegion() function above
************************************************************************************/
BOOL CWindowAnima::SetClippingRegion(int l, int t, int r, int b)
{
 	CRect ClipRect(l,t,r,b);
	return SetClippingRegion(ClipRect);
}

/************************************************************************************
	Returns the current Clipping Region and Working Screen Area (same thing)
************************************************************************************/
void CWindowAnima::GetClippingRegion(CRect *pEmptyRect)
{
	pEmptyRect->CopyRect(&m_rectScr);
}

/************************************************************************************
	Sets the dimensions of the Working Screen Area and clipping region (same thing)
************************************************************************************/
void CWindowAnima::SetScreenDimensions(CRect &ScrRect)
{
		m_rectScr.CopyRect(ScrRect);
		m_czScr.cx=ScrRect.Width();
		m_czScr.cy=ScrRect.Height();
}

/************************************************************************************
	Toggles on/off whether or not the windows taskbar will be always on top of the
	animation or not.
************************************************************************************/
void CWindowAnima::ToggleTaskBarOnTop(UINT nSwitch)
{
	APPBARDATA AppBarData;
	AppBarData.cbSize=sizeof(AppBarData);

	// get the taskbar position and dimensions
	if(SHAppBarMessage(ABM_GETTASKBARPOS, &AppBarData)){
		CRect rectTemp;
		// Set rectNewScreen to our current Screen dimensions, then at
		// worst we'll just set the clipping region to what it already is
		CRect rectNewScreen(m_rectScr);
		switch(nSwitch){
		case WA_TASKBAR_ON:
			// if part of the window is obscured by the task bar
			if(rectTemp.IntersectRect(m_rectScr, &AppBarData.rc))
				rectNewScreen.SubtractRect(m_rectScr, &AppBarData.rc);
			break;
		case WA_TASKBAR_OFF:
			// find which edge the task bar is stuck to
			switch(AppBarData.uEdge){
			case ABE_BOTTOM:
				// if the bottom of our window and the top of the taskbar
				// are touching then extend the clipping region
				if(AppBarData.rc.top<=m_rectScr.bottom)
					rectNewScreen.bottom=AppBarData.rc.bottom;
				break;
			case ABE_TOP:
				// if the top of our window and the bottom of the taskbar
				// are touching then extend the clipping region
				if(AppBarData.rc.bottom>=m_rectScr.top)
					rectNewScreen.top=AppBarData.rc.top;
				break;
			case ABE_LEFT:
				// if the left of our window and the right of taskbar
				// are touching then extend the clipping region
				if(AppBarData.rc.right>=m_rectScr.left)
					rectNewScreen.left=AppBarData.rc.left;
				break;
			case ABE_RIGHT:
				// if the right of our window and the left of the taskbar
				// are touching then extend the clipping region
				if(AppBarData.rc.left<=m_rectScr.right)
					rectNewScreen.right=AppBarData.rc.right;
				break;
			}
			break;
		}
		// set the new clipping region
		SetClippingRegion(rectNewScreen);
	}
}

/************************************************************************************
	Copies the window's positional rectangle into the CRect structure pointed to
	by pRect.
************************************************************************************/
void CWindowAnima::GetWindowRect(CRect *pRect)
{
	pRect->CopyRect(&m_rectWnd);
}
