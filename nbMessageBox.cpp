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
*/

// nbMessageBox.cpp : implementation file
//

#include "stdafx.h"
#include "nbMessageBox.h"
#include <afxpriv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDC_SEPARATOR 111
#define IDC_CHECKBOX 666

/////////////////////////////////////////////////////////////////////////////
// CnbMessageBox

CString CnbMessageBox::m_strDoNotShowAgain = "Do not show again";
CString CnbMessageBox::m_strDoNotAskAgain = "Do not ask again";

CnbMessageBox::CnbMessageBox(CWnd *pParent)
{
    m_pParent = pParent;
    m_bChecked = FALSE;
}

CnbMessageBox::~CnbMessageBox()
{
}

void CnbMessageBox::SetChecked(BOOL bChecked)
{
    m_bChecked = bChecked;
}

BOOL CnbMessageBox::GetChecked()
{
    return m_bChecked;
}

void CnbMessageBox::SetDoNotAgainStrings(CString &strDoNotShowAgain, CString &strDoNotAskAgain)
{
    m_strDoNotShowAgain = strDoNotShowAgain;
    m_strDoNotAskAgain = strDoNotAskAgain;
}

void CnbMessageBox::SetDoNotAgainStrings(int nDoNotShowAgainId, int nDoNotAskAgainId)
{
    m_strDoNotShowAgain.LoadString(nDoNotShowAgainId);
    m_strDoNotAskAgain.LoadString(nDoNotAskAgainId);
}

BEGIN_MESSAGE_MAP(CnbMessageBox, CWnd)
	//{{AFX_MSG_MAP(CnbMessageBox)
	ON_WM_CREATE()
    ON_MESSAGE(WM_INITDIALOG, OnSubclassedInit)
    ON_COMMAND(IDC_CHECKBOX, OnDoNotAgain)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CnbMessageBox message handlers

//
// Move horizontally all the buttons of a dialog
//

BOOL CALLBACK MoveButtons(HWND hwnd, LPARAM lParam)
{
    int offset = * (int*) lParam;

    TCHAR szBuf[256];
    GetClassName( hwnd, szBuf, 256 );
    if (lstrcmp(szBuf, _T("Button")) == 0)
    {
        // get the window placement (position and size)
        WINDOWPLACEMENT placement;
        ::GetWindowPlacement(hwnd, &placement);
        CRect rc = placement.rcNormalPosition;

        ::SetWindowPos(hwnd, NULL, rc.left+offset/2, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER);
    }

    return TRUE;
}

int CnbMessageBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
    AfxUnhookWindowCreate();
	return CWnd::OnCreate(lpCreateStruct);
}

LRESULT CnbMessageBox::OnSubclassedInit(WPARAM wParam, LPARAM lParam)
{
    LRESULT lRet = Default();

    // some metrics
    static const int k_nCaptionHeight = GetSystemMetrics(SM_CYCAPTION);
    static const int k_nBorderHeight = GetSystemMetrics(SM_CYEDGE);
    static const int k_nBorderWidth = GetSystemMetrics(SM_CXEDGE);
    static const int k_nSepHeigth = 3;
    static const int k_nMargin = 7;

    // get standard font (from static)
    HWND hStatic = ::GetDlgItem(GetSafeHwnd(), 65535);
    HFONT hFont = (HFONT) ::SendMessage(hStatic, WM_GETFONT, 0, 0);

    // the checkbox label
    CString &strLabel = (m_nType&0xF) ? m_strDoNotAskAgain : m_strDoNotShowAgain;

    // calc the size of the checkbox
    CDC *pDC = GetDC();
    int dc = pDC->SaveDC();
    pDC->SelectObject(CFont::FromHandle(hFont));
    CSize size = pDC->GetTextExtent(strLabel);
    pDC->RestoreDC(dc);
    ReleaseDC(pDC);

    // more metrics
    int nCheckboxHeight = min(13, size.cy);
    int nOffset = 2*k_nSepHeigth + nCheckboxHeight + k_nMargin;

    // get the window placement (position and size)
    WINDOWPLACEMENT placement;
    GetWindowPlacement(&placement);
    CRect rc = placement.rcNormalPosition;
    rc.bottom -= k_nMargin;

    // make sure the box is wide enough for the checkbox
    size.cx += 2*k_nMargin + 2*k_nBorderWidth + 13 + 6;
    if (rc.Width() < size.cx)
    {
        // move each button so they appear centered
        int offset = size.cx - rc.Width();
        EnumChildWindows(GetSafeHwnd(), MoveButtons, (LPARAM) &offset);

        // adjust window width
        rc.right = rc.left + size.cx;
    }

    // set the window pos
    CRect rect = rc;
    rect.OffsetRect(-k_nBorderWidth, -k_nCaptionHeight-k_nBorderHeight);
    MoveWindow(rect.left, rect.top-nOffset/2, rect.Width(), rect.Height()+nOffset);
    CenterWindow(m_pParent);
    
    // ajust rect
    rc.bottom -= k_nCaptionHeight + k_nBorderHeight;

    // create the separator
    CRect rc_sep(-1, rc.Height(), rc.Width(), rc.Height()+k_nSepHeigth);
    m_ctrlSep.Create(NULL, "", SS_SIMPLE|WS_CHILD|WS_VISIBLE, rc_sep, this, IDC_SEPARATOR);

    // create the button
    CRect rc_but(k_nMargin, rc.Height()+2*k_nSepHeigth, rc.Width(), rc.Height()+2*k_nSepHeigth+nCheckboxHeight);
    m_cbDoNotAgain.Create(strLabel, WS_CHILD|WS_VISIBLE|BS_CHECKBOX, rc_but, this, IDC_CHECKBOX);
    m_cbDoNotAgain.SetFont(CFont::FromHandle(hFont));
    m_cbDoNotAgain.SetCheck(m_bChecked);

    return lRet;
}
    
void CnbMessageBox::OnDoNotAgain()
{
    m_bChecked = !m_bChecked;
    m_cbDoNotAgain.SetCheck(m_bChecked);
}

int CnbMessageBox::MessageBox(LPCTSTR lpszText, UINT nType, UINT nIDHelp)
{
    m_nType = nType;
    AfxHookWindowCreate(this);
    return AfxMessageBox(lpszText, nType, nIDHelp);
}

int CnbMessageBox::MessageBox( UINT nIDPrompt, UINT nType, UINT nIDHelp)
{
    CString strText;
    strText.LoadString(nIDPrompt);
    return MessageBox(strText, nType, nIDHelp);
}
