/*
* This file is part of Retell Software Call Recorder.
*
* Retell Software Call Recorder is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the License,
* or (at your option) any later version.
*
* Retell Software Call Recorder is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* Retell Software Call Recorder. If not, see <https://www.gnu.org/licenses/>.
*
*	Beschreibung:
*	
*	COwnerDrawButton implementation file
*	
*	$Log:   D:/pvcsarch/telar/ownerdrawbutton.cpv  $
* 
*    Rev 1.46   Dec 19 2007 17:27:34   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.45   Oct 11 2007 10:15:08   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.44   Sep 21 2007 15:47:22   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.43   Aug 14 2007 14:09:12   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.42   May 09 2007 10:23:48   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.41   Nov 16 2006 14:59:50   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.40   Nov 13 2006 13:26:28   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.39   Jun 12 2006 15:13:26   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.38   Nov 25 2005 01:32:26   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.37   Nov 23 2005 16:11:26   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.36   Nov 11 2005 09:51:02   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.35   Jul 11 2005 08:52:40   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.34   Jul 05 2005 01:50:24   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.33   Jun 28 2005 01:46:30   tmielke
* v1.72 build 1250
* 
*    Rev 1.32   Jun 02 2005 01:30:32   tmielke
* v1.72 build 1207
* 
*    Rev 1.31   May 18 2005 13:47:14   tmielke
* v1.72 build 1200
* 
*    Rev 1.30   Mar 18 2005 16:12:02   tmielke
*  
* 
*    Rev 1.29   Mar 12 2005 07:08:36   tmielke
* v1.69
* 
*    Rev 1.28   Feb 22 2005 16:53:24   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.27   Nov 21 2004 01:29:18   tmielke
* v1.66 build 883
* 
*    Rev 1.26   Dec 04 2003 03:36:46   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.25   Nov 18 2003 09:39:44   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.24   Oct 03 2003 01:22:12   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.23   Sep 23 2003 01:48:06   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.22   Sep 12 2003 01:12:12   tmielke
*  
* 
*    Rev 1.21   Sep 11 2003 04:04:06   tmielke
*  
* 
*    Rev 1.20   Sep 04 2003 00:55:28   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.19   Aug 04 2003 00:35:02   tmielke
* v1.64
* 
*    Rev 1.18   Jun 09 2003 15:25:18   tmielke
* v1.63 final
* 
*    Rev 1.17   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.16   May 05 2002 11:56:24   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.15   Mar 15 2002 20:21:58   tmielke
* v1.60
* 
*    Rev 1.14   Jan 28 2002 16:11:22   tmielke
* License confirmation
* 
*    Rev 1.13   Nov 07 2001 02:08:24   tmielke
* v1.59 bugfix release
* 
*    Rev 1.12   Nov 06 2001 05:27:02   tmielke
* v1.58a
* 
*    Rev 1.11   Oct 12 2001 16:22:52   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.10   Sep 14 2001 04:12:36   
* v1.57
* 
*    Rev 1.9   06 Jun 2001 02:00:24   tmielke
* offizielle release 1.55
* 
*    Rev 1.8   17 May 2001 02:01:16   tmielke
* v1.54
* 
*    Rev 1.7   12 Feb 2001 19:36:56   tmielke
* v1.53
* 
*    Rev 1.6   20 Dec 2000 18:18:34   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.5   04 Dec 2000 02:23:04   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.4   19 Oct 2000 02:28:50   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.3   29 Jul 2000 03:55:28   tmielke
* Aufnahme-Screen redesign fertig
* 
*    Rev 1.2   23 Jul 2000 21:32:24   tmielke
* Owner-draw bitmap+text button fertig
* 
*    Rev 1.1   23 Jul 2000 19:17:32   tmielke
* zwischendurch
* 
*    Rev 1.0   23 Jul 2000 17:32:30   tmielke
* initial checkin
*/

#include "stdafx.h"
#include "OwnerDrawButton.h"

//--- public member functions ---

void COwnerDrawButton::InitButton(CWnd *pPar, int ctrl_id, char **text_array, int *bitmap_array, int nNumberOfStates)
{
	// store init values
	pParent = pPar;
	m_ctrl_id = ctrl_id;
	for (int i = 0; i < nNumberOfStates; i++)
	{
		cbmButtonBitmap[i].LoadBitmap(bitmap_array[i]);			// 1st state
		cbmButtonBitmap[i].GetObject(sizeof(bm[i]), &bm[i]);
		m_text[i] = text_array[i];
	}

	SetState(0);
}

void COwnerDrawButton::PerformDrawItem(LPDRAWITEMSTRUCT lpdis)
{
	CString text = m_text[active_state];
	POINT pt;
	pt.x = lpdis->rcItem.right - lpdis->rcItem.left;
	pt.y = (lpdis->rcItem.bottom - lpdis->rcItem.top) / 2;

    // define size of dashed rectangles around text in both bitmaps
	pDC           = pParent->GetDC();
	//csizeRectDim  = pDC->GetTextExtent(text);
	CRect textrect = lpdis->rcItem;
	int textheight = pDC->DrawText((LPCSTR)text, text.GetLength(), &textrect, DT_LEFT|DT_WORDBREAK|DT_CENTER|DT_CALCRECT);    
	csizeRectDim.cx = textrect.right - textrect.left;
	csizeRectDim.cy = textrect.bottom - textrect.top;
	pParent->ReleaseDC(pDC);

	nSpaceWidth   = GetSystemMetrics(SM_CXBORDER);
	nSpaceHeight  = GetSystemMetrics(SM_CYBORDER);
	rectDraw.top    = ((pt.y - csizeRectDim.cy) >> 1) + pt.y;
    rectDraw.bottom = rectDraw.top + csizeRectDim.cy;
    rectDraw.left   = ((pt.x - csizeRectDim.cx) >> 1);
    rectDraw.right  = rectDraw.left + csizeRectDim.cx;
    rectDrawDown.top    = 2 + rectDraw.top;
    rectDrawDown.bottom = 2 + rectDraw.bottom;
    rectDrawDown.left   = 2 + rectDraw.left;
    rectDrawDown.right  = 2 + rectDraw.right;
    rectHi.top    = -nSpaceHeight + ((pt.y - csizeRectDim.cy) >> 1) + pt.y;
    rectHi.bottom = (nSpaceHeight << 1) + rectHi.top + csizeRectDim.cy - 3/*!*/;
    rectHi.left   = -nSpaceWidth + ((pt.x - csizeRectDim.cx) >> 1);
    rectHi.right  = (nSpaceWidth << 1) + rectHi.left + csizeRectDim.cx;
    rectHiDown.top    = 2 + rectHi.top;
    rectHiDown.bottom = 2 + rectHi.bottom;
    rectHiDown.left   = 2 + rectHi.left;
    rectHiDown.right  = 2 + rectHi.right;
    switch (lpdis->itemAction)
    {
    // handle normal drawing of button, but check if its
    // selected or focus
    case ODA_DRAWENTIRE:
        // this handles both button down and button up
        ButtonSelectedState(lpdis);

        // this handles focus rectangle around "Hi!"
        ButtonFocusState(lpdis);
        break;

    // handle drawing selection if needed
    //   selected is button down, not selected is button up
    //   focus will occur when button is pressed.
    case ODA_SELECT:
        ButtonSelectedState(lpdis);
        ButtonFocusState(lpdis);
        break;

    // handle focus drawing if needed
    case ODA_FOCUS:
        ButtonFocusState(lpdis);
        break;
    }  //itemAction
}

void COwnerDrawButton::SetState(int n)
{
	if (n < 0 && n >= ODB_MAX_STATES) n = 0;
	active_state = n;
	pParent->GetDlgItem(m_ctrl_id)->InvalidateRect(NULL, FALSE);
}

int  COwnerDrawButton::GetState()
{
	return active_state;
}

//--- private member functions ---

void COwnerDrawButton::ButtonFocusState(LPDRAWITEMSTRUCT lpdis)
{
    // if focus state, draw a dashed rect around text
    if (lpdis->itemState & ODS_FOCUS)
    {
        // if selected, shift focus rect right and down 2 pixels around text
        if (lpdis->itemState & ODS_SELECTED)
            DrawFocusRect(lpdis->hDC, (LPRECT)&rectHiDown);
        // else text centered, so focus rect will be too
        else
            DrawFocusRect(lpdis->hDC, (LPRECT)&rectHi);
    }
    return;
}

void COwnerDrawButton::ButtonSelectedState(LPDRAWITEMSTRUCT lpdis)
{
	CString text = m_text[active_state];
	//POINT pt;
	//pt.x = (active_state == 1 ? bm1.bmWidth : bm2.bmWidth);
	//pt.y = (active_state == 1 ? bm1.bmHeight : bm2.bmHeight);
	POINT pt;
	pt.x = lpdis->rcItem.right - lpdis->rcItem.left;
	pt.y = lpdis->rcItem.bottom - lpdis->rcItem.top;

    // handle button pressed down select state -- button down bitmap
    //   text is right & down 2 pixels
    if (lpdis->itemState & ODS_SELECTED)
    {
        DrawButton(lpdis->hDC,&lpdis->rcItem, TRUE);

        // put text 2 pixels right and down of center of bitmap
        nOldBkMode = SetBkMode(lpdis->hDC,TRANSPARENT);
        //TextOut(lpdis->hDC, 2 + ((pt.x - csizeRectDim.cx) >> 1),
        //    2 + ((pt.y - csizeRectDim.cy) >> 1), (LPCSTR)text, text.GetLength());
		::DrawText(lpdis->hDC, (LPCSTR)text, text.GetLength(), &rectDrawDown, DT_LEFT|DT_WORDBREAK|DT_CENTER);    

        SetBkMode(lpdis->hDC,nOldBkMode);
    }
    // not selected -- button up; text is in normal position
    else
    {
        DrawButton(lpdis->hDC,&lpdis->rcItem, FALSE);

        // center text in bitmap
        nOldBkMode = SetBkMode(lpdis->hDC,TRANSPARENT);
        //TextOut(lpdis->hDC, (pt.x - csizeRectDim.cx) >> 1,
        //    (pt.y - csizeRectDim.cy) >> 1, (LPCSTR)text, text.GetLength());
		::DrawText(lpdis->hDC, (LPCSTR)text, text.GetLength(), &rectDraw, DT_LEFT|DT_WORDBREAK|DT_CENTER);    

        SetBkMode(lpdis->hDC,nOldBkMode);
    }
    return;
}

void COwnerDrawButton::DrawButton(HDC hDC, RECT *r, BOOL bPressed)
{
    // HDC           hMemDC;
    // hMemDC = CreateCompatibleDC(hDC);
    // SelectObject(hMemDC, (HBITMAP)*pBitmap);
    // BitBlt(hDC, xStart, yStart, pt.x, pt.y, hMemDC, 0, 0, rop);
    // DeleteDC(hMemDC);

	CBrush white, black, lightgrey, grey;
	white.CreateSolidBrush(RGB(255,255,255));
	black.CreateSolidBrush(RGB(0,0,0));
	lightgrey.CreateSolidBrush(RGB(191,191,191));
	grey.CreateSolidBrush(RGB(127,127,127));

	CRgn border_rgn, butborder_left_rgn, butborder_top_rgn, butborder_bottom_rgn, butborder_right_rgn, butface_rgn;
	border_rgn.CreateRectRgnIndirect(r);
	CRect facerect = r;
	int reduce_facerect;
	if (!bPressed) reduce_facerect = 4; else reduce_facerect = 2;
	facerect.left += reduce_facerect; facerect.top += reduce_facerect; facerect.bottom -= reduce_facerect; facerect.right -= reduce_facerect;
	butface_rgn.CreateRectRgnIndirect(&facerect);
	
	if (!bPressed)
	{
		POINT butborder_topleft[6];
		butborder_topleft[0].x = r->left + 2;  butborder_topleft[0].y = r->bottom - 3;
		butborder_topleft[1].x = r->left + 4;  butborder_topleft[1].y = r->bottom - 4;
		butborder_topleft[2].x = r->left + 4;  butborder_topleft[2].y = r->top + 4;
		butborder_topleft[3].x = r->left + 2;  butborder_topleft[3].y = r->top + 2;
		butborder_topleft[4].x = r->right - 2; butborder_topleft[4].y = r->top + 2;
		butborder_topleft[5].x = r->right - 4; butborder_topleft[5].y = r->top + 4;
		butborder_left_rgn.CreatePolygonRgn(butborder_topleft, 4, WINDING);
		butborder_top_rgn.CreatePolygonRgn(butborder_topleft+2, 4, WINDING);
		POINT butborder_bottomright[6];
		butborder_bottomright[0].x = r->left + 1;  butborder_bottomright[0].y = r->bottom - 2;
		butborder_bottomright[5].x = r->left + 2;  butborder_bottomright[5].y = r->bottom - 3;
		butborder_bottomright[4].x = r->right - 3; butborder_bottomright[4].y = r->bottom - 3;
		butborder_bottomright[1].x = r->right - 2; butborder_bottomright[1].y = r->bottom - 2;
		butborder_bottomright[2].x = r->right - 2; butborder_bottomright[2].y = r->top + 1;
		butborder_bottomright[3].x = r->right - 3; butborder_bottomright[3].y = r->top + 3;
		butborder_bottom_rgn.CreatePolygonRgn(butborder_bottomright, 4, WINDING);
		butborder_right_rgn.CreatePolygonRgn(butborder_bottomright, 4, WINDING);
	}

	CDC *pDC = CDC::FromHandle(hDC);
	pDC->FrameRgn(&border_rgn, &black, reduce_facerect, reduce_facerect);
	if (!bPressed)
	{
		pDC->FillRgn(&butborder_left_rgn, &white);
		pDC->FillRgn(&butborder_top_rgn, &white);
		pDC->FillRgn(&butborder_bottom_rgn, &grey);
		pDC->FillRgn(&butborder_right_rgn, &grey);
	}
	pDC->FillRgn(&butface_rgn, &lightgrey);

	// draw bitmap
	CBitmap *pcbm = &cbmButtonBitmap[active_state];
	int x = bm[active_state].bmWidth;
	int y = bm[active_state].bmHeight;

    HDC           hMemDC;
    hMemDC = CreateCompatibleDC(hDC);
    SelectObject(hMemDC, (HBITMAP)*pcbm);
    ::BitBlt(hDC, r->right / 2 - x / 2 + (bPressed ? 2 : 0), 
		(r->bottom / 2 - y) / 2 + 3 + (bPressed ? 2 : 0),
		r->right / 2 - x / 2 + x + (bPressed ? 2 : 0),
		(r->bottom / 2 - y) / 2 + y + 3 + (bPressed ? 2 : 0), 
		hMemDC, 0, 0, SRCCOPY);
    DeleteDC(hMemDC);

}

