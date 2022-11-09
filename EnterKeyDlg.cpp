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
*   EnterKeyDlg.cpp : implementation file
*/

#include "stdafx.h"
#include "telar.h"
#include "EnterKeyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnterKeyDlg dialog


CEnterKeyDlg::CEnterKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterKeyDlg)
	m_license_key = _T("");
	//}}AFX_DATA_INIT
}


void CEnterKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterKeyDlg)
	DDX_Text(pDX, IDC_LICENSE_KEY, m_license_key);
	DDV_MaxChars(pDX, m_license_key, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CEnterKeyDlg)
	ON_BN_CLICKED(IDTRIAL, OnTrial)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterKeyDlg message handlers

BOOL CEnterKeyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	char buffer[200];

	LANG2BUFFER(IDS_STRING99, buffer);
	SetWindowText(buffer);
	LANG2BUFFER(IDS_STRING100, buffer);
	SetDlgItemText(IDC_LICENSE_KEY_STATIC, buffer);
	LANG2BUFFER(IDS_STRING101, buffer);
	SetDlgItemText(IDC_TEXT, buffer);
	LANG2BUFFER(IDS_STRING102, buffer);
	SetDlgItemText(IDCANCEL, buffer);
	LANG2BUFFER(IDS_STRING103, buffer);
	SetDlgItemText(IDC_TEXT2, buffer);
	LANG2BUFFER(IDS_STRING141, buffer);
	SetDlgItemText(IDC_TEXT3, buffer);
	
	if (m_no_more_trial) GetDlgItem(IDTRIAL)->EnableWindow(FALSE);

	return TRUE;
}

void CEnterKeyDlg::OnTrial() 
{
	EndDialog(IDIGNORE);
}
