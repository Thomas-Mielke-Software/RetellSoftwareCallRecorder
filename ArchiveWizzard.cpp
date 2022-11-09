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
*	Beschreibung: class CArchiveWizzard
*	
*	ArchiveWizzard.cpp : implementation file
*	Klasse zur Verwaltung des Archive Wizard Property Sheet
*	
*	$Log:   D:/pvcsarch/telar/IndexDB.cpv  $
*/

#include "stdafx.h"
#include "resource.h"
#include "ArchiveWizzard.h"
#include "TelAr.h"
#include "afxpriv.h"
//#include "..\src\afximpl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzard

IMPLEMENT_DYNAMIC(CArchiveWizzard, CPropertySheet)

CArchiveWizzard::CArchiveWizzard(CWnd* pWndParent)
	 : CPropertySheet(IDS_PROPSHT_CAPTION1, pWndParent)
{
	m_psh.dwFlags &= ~PSH_HASHELP;

	AddPage(&m_Page1);
	AddPage(&m_Page2);
	AddPage(&m_Page3);
	AddPage(&m_Page4);
	AddPage(&m_Page5);
	AddPage(&m_Page6);
	AddPage(&m_Page7);

	SetWizardMode();

	m_pWndParent = pWndParent;

	// init sheed data with default values
	m_nVolumeSize = 700;
	m_nMethod = 0;
	m_csTempFolder = "";
	int n = ((CListCtrl *)((CTelArPropertyPage2 *)m_pWndParent)->GetDlgItem(IDC_LISTE))->GetItemCount();
	if (n>0) 
		m_pSelector = new int[n];
	else
		m_pSelector = NULL;
	m_nSelected = 0;

}

CArchiveWizzard::~CArchiveWizzard()
{
}


BEGIN_MESSAGE_MAP(CArchiveWizzard, CPropertySheet)
	//{{AFX_MSG_MAP(CArchiveWizzard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CArchiveWizzard message handlers

BOOL CArchiveWizzard::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();

	CenterWindow();
	return bResult;
}

/*
int CArchiveWizzard::DoModal()
{
ASSERT_VALID(this);
ASSERT(m_hWnd == NULL);

// register common controls
VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTLS_REG));
AfxDeferRegisterClass(AFX_WNDCOMMCTLSNEW_REG);

// finish building PROPSHEETHEADER structure
BuildPropPageArray();
// find parent HWND
HWND hWndTop;
HWND hWndParent = CWnd::GetSafeOwner_(m_pParentWnd->GetSafeHwnd(), &hWndTop);
AFX_OLDPROPSHEETHEADER* psh = GetPropSheetHeader();
psh->hwndParent = hWndParent;

HWND hWndCapture = ::GetCapture();
if (hWndCapture != NULL)
::SendMessage(hWndCapture, WM_CANCELMODE, 0, 0);

// setup for modal loop and creation
m_nModalResult = 0;
m_nFlags |= WF_CONTINUEMODAL;

// hook for creation of window
AfxHookWindowCreate(this);
psh->dwFlags |= PSH_MODELESS;
m_nFlags |= WF_CONTINUEMODAL;
HWND hWnd = (HWND)::PropertySheet((PROPSHEETHEADER*)psh);
#ifdef _DEBUG
DWORD dwError = ::GetLastError();
#endif
psh->dwFlags &= ~PSH_MODELESS;
AfxUnhookWindowCreate();

// handle error
if (hWnd == NULL || hWnd == (HWND)-1)
{
TRACE1("PropertySheet() failed: GetLastError returned %d\n", dwError);
m_nFlags &= ~WF_CONTINUEMODAL;
}

int nResult = m_nModalResult;
if (ContinueModal())
{
// enter modal loop
DWORD dwFlags = MLF_SHOWONIDLE;
if (GetStyle() & DS_NOIDLEMSG)
dwFlags |= MLF_NOIDLEMSG;
nResult = RunModalLoop(dwFlags);
}

// hide the window before enabling parent window, etc.
if (m_hWnd != NULL)
{
SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW|
SWP_NOSIZE|SWP_NOMOVE|SWP_NOACTIVATE|SWP_NOZORDER);
}
if (hWndParent != NULL && ::GetActiveWindow() == m_hWnd)
::SetActiveWindow(hWndParent);

// cleanup
DestroyWindow();

return nResult;
} 
*/