// WindowAnima.h: interface for the CWindowAnima class.
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

#if !defined(AFX_WINDOWANIMA_H__6007F99C_1E5E_459B_8BCC_E00CE41F8A74__INCLUDED_)
#define AFX_WINDOWANIMA_H__6007F99C_1E5E_459B_8BCC_E00CE41F8A74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WA_LEFT		0
#define WA_RIGHT	1
#define WA_UP		2
#define WA_DOWN		3
#define WA_VERT		4
#define WA_HORZ		5
#define WA_RAND		6
#define WA_AUTO		7

#define WA_TASKBAR_OFF	0
#define WA_TASKBAR_ON	1

#define WA_SCR_SKIPCAPTURE		1	// don't capture the screen on each animation
#define WA_WND_SKIPCAPTURE		2	// don't capture the window image
#define WA_WND_SKIPRESTORE		4	// don't restore the window or window background
									//  after an animation
#define WA_KEEP_WINDOW_HIDDEN	8	// don't restore the window after an animation
#define WA_KEEP_BKGRND_HIDDEN	16	// don't restore the window background after an animation
#define WA_KEEP_TASKBAR_ONTOP	32	// don't draw the animation over the taskbar
#define WA_SKIPHIDEONCAPTURE	64	// don't hide the window after capturing the screen


class CWindowAnima  
{
public:
	CWindowAnima();
	CWindowAnima(CWnd *pWnd, UINT nFlags=0x0);
	virtual ~CWindowAnima();
	CWnd* GetWindow();
	UINT FlagUnset(UINT nFlags);
	UINT FlagSet(UINT nFlags);
	BOOL FlagIsSet(UINT nFlags);
	BOOL CopyWindowCapture(CWindowAnima *pWA);
	BOOL CopyScreenCapture(CWindowAnima *pWA);
	BOOL ReplaceWindowImage(UINT nResID);
	BOOL ReplaceWindowImage(CDC *pdc);
	BOOL SetClippingRegion(int l, int t, int r, int b);
	BOOL SetClippingRegion(CRect &ClipRect);
	void GetClippingRegion(CRect *pEmptyRect);
	void SetWindow(CWnd *pWnd);
	void GetWindowRect(CRect *pRect);
	void MoveWindowPosition(int x, int y);
	void ShowWindow();
	void RestoreWindow(BOOL bIgnoreFlags=TRUE);
	void UnBlind(int nDirection=WA_VERT, int nSegments=8, int nGapFactor=4, int nSleeptime=100);
	void Blind(int nDirection=WA_VERT, int nSegments=8, int nGapFactor=4, int nSleeptime=100);
	void Wipe(int nDirection=WA_RAND, int nWipeFactor=4, int nSleeptime=20);
	void UnWipe(int nDirection=WA_RAND, int nWipeFactor=4, int nSleeptime=20);
	void Melt(int nDirection=WA_AUTO, int nSegments=6, int nStagger=40, int nSleeptime=1);
	void UnMelt(int nDirection=WA_AUTO, int nSegments=6, int nStagger=40, int nSleeptime=1);
	void Scatter4(int nDistance=90, int nMoveFactor=4, int nSleeptime=1);
	void Scatter6(int nDistance=90, int nMoveFactor=4, int nSleeptime=1);
	void ReAssemble4(int nDistance=90, int nMoveFactor=4, int nSleeptime=1);
	void ReAssemble6(int nDistance=90, int nMoveFactor=4, int nSleeptime=1);
	void SlideAppear(int nSlideFactor=1, int nScaleFactor=15, int nSlideDelay=10, int nAppearDelay=0);
	void SlideVanish(int nSlideFactor=1, int nScaleFactor=15, int nSlideDelay=10, int nVanishDelay=0);

protected:
	void BlindHorz(int nSegments, int nGapFactor, int nSleeptime);
	void BlindVert(int nSegments, int nGapFactor, int nSleeptime);
	void UnBlindHorz(int nSegments, int nGapFactor, int nSleeptime);
	void UnBlindVert(int nSegments, int nGapFactor, int nSleeptime);
	void UnWipeDown(int nWipeFactor, int nSleeptime);
	void UnWipeUp(int nWipeFactor, int nSleeptime);
	void UnWipeRight(int nWipeFactor, int nSleeptime);
	void UnWipeLeft(int nWipeFactor, int nSleeptime);
	void UnWipeVert(int nWipeFactor, int nSleeptime);
	void UnWipeHorz(int nWipeFactor, int nSleeptime);
	void WipeUp(int nWipeFactor, int nSleeptime);
	void WipeDown(int nWipeFactor, int nSleeptime);
	void WipeRight(int nWipeFactor, int nSleeptime);
	void WipeLeft(int nWipeFactor, int nSleeptime);
	void WipeVert(int nWipeFactor, int nSleeptime);
	void WipeHorz(int nWipeFactor, int nSleeptime);
	void UnMeltDown(int nSegments, int nDrop, int nSleeptime);
	void UnMeltUp(int nSegments, int nDrop, int nSleeptime);
	void UnMeltRight(int nSegments, int nDrop, int nSleeptime);
	void UnMeltLeft(int nSegments, int nDrop, int nSleeptime);
	void MeltUp(int nSegments, int nDrop, int nSleeptime);
	void MeltDown(int nSegments, int nDrop, int nSleeptime);
	void MeltRight(int nSegments, int nDrop, int nSleeptime);
	void MeltLeft(int nSegments, int nDrop, int nSleeptime);
	void InitialSetup();
	void Initialise();
	void CaptureWindowImage(CWnd *pWnd);
	void CaptureScreenImage(CWnd *pWnd);
	void PrintImageBehindWindow();
	void HideWindow();
	void PrintWindow();
	void SetWindowSize(int nWidth, int nHeight);
	void ToggleTaskBarOnTop(UINT);
	void SetScreenDimensions(CRect &ScrRect);
	int GetClosestSide();
	int GetRandomDirection(int nDirections);
	BOOL InjectScreenImage(CDC *pdcMemScr);
	BOOL InjectWindowImage(CDC *pdcMemWnd, CRect *prectWnd);
	BOOL m_TaskBarClippingOn;		// used to tell if task bar clipping is on/off
	CWnd *m_pWnd;					// pointer to the window being animated
	CDC *m_pdcMemWnd;				// pointer to the off screen "Window" memory dc
	CDC *m_pdcMemScr;				// pointer to the off screen "Screen" memory dc
	CClientDC *m_pdcScreen;			// pointer to the on screen dc
	CBitmap* m_pOldBitmapScr;		// holds old selected screen bitmap
	CBitmap* m_pOldBitmapWnd;		// holds old selected window bitmap
	CRect m_rectWnd;				// holds window position
	CRect m_rectScr;				// holds screen position
	CSize m_czWnd;					// holds window dimensions
	CSize m_czScr;					// holds screen dimensions
	UINT m_nFlags;					// used to find which flags (if any) are set
};

#endif // !defined(AFX_WINDOWANIMA_H__6007F99C_1E5E_459B_8BCC_E00CE41F8A74__INCLUDED_)
