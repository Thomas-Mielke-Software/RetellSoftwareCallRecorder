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

// SelectDeviceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "telar.h"
#include "SelectDeviceDlg.h"
#include "mmsystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectDeviceDlg dialog


CSelectDeviceDlg::CSelectDeviceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectDeviceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectDeviceDlg)
	m_liste = -1;
	//}}AFX_DATA_INIT
}


void CSelectDeviceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectDeviceDlg)
	DDX_LBIndex(pDX, IDC_LISTE, m_liste);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectDeviceDlg, CDialog)
	//{{AFX_MSG_MAP(CSelectDeviceDlg)
	ON_LBN_DBLCLK(IDC_LISTE, OnDblclkListe)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectDeviceDlg message handlers

BOOL CSelectDeviceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	LANG_SETWINDOWTEXT(IDS_STRING152)
	LANG_SETCTRLTEXT(IDS_STRING102, IDCANCEL)

	int i, n;
	if (n = waveInGetNumDevs())
	{
		WAVEINCAPS wic;

		((CListBox *)GetDlgItem(IDC_LISTE))->ResetContent();
		for (i = 0; i < n; i++)
		{
			waveInGetDevCaps(i, &wic, sizeof(wic));
			((CListBox *)GetDlgItem(IDC_LISTE))->AddString(wic.szPname);
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSelectDeviceDlg::OnDblclkListe() 
{
	CSelectDeviceDlg::OnOK();
}
