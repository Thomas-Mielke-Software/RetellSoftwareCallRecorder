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

// MuteInput.cpp : implementation file
//

#include "stdafx.h"
#include "telar.h"
#include "MuteInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMuteInput dialog


CMuteInput::CMuteInput(CWnd* pParent /*=NULL*/)
	: CDialog(CMuteInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMuteInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	*m_strControlPanelPath = '\0';
}


void CMuteInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMuteInput)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMuteInput, CDialog)
	//{{AFX_MSG_MAP(CMuteInput)
	ON_BN_CLICKED(IDC_OPEN_CONTROL_PANEL, OnOpenControlPanel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMuteInput message handlers

BOOL CMuteInput::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	BOOL (__cdecl *pGetControlPanelPath)(char *);
	pGetControlPanelPath = (BOOL (__cdecl *)(char *))GetProcAddress(hSCRVistaHelper, "GetControlPanelPath");

/* stack overflow somehow... -- was because of wrong (FAR PASCAL) function declaration 
	if (pGetControlPanelPath) 
	{
		if ((*pGetControlPanelPath)(m_strControlPanelPath))
		{
			m_strControlPanelPath[sizeof(m_strControlPanelPath-1)] = '\0';
*/			GetDlgItem(IDC_OPEN_CONTROL_PANEL)->ShowWindow(SW_SHOW);	// show button to run control.exe
/*		}
		else 
		{
			*m_strControlPanelPath = '\0';
		}
	}
*/
	char buffer[1000];
	LANG2BUFFER(IDS_STRING200, buffer);
	SetDlgItemText(IDC_STATIC0, buffer);
	LANG2BUFFER(IDS_STRING201, buffer);
	SetDlgItemText(IDC_STATIC1, buffer);
	LANG2BUFFER(IDS_STRING202, buffer);
	SetDlgItemText(IDC_STATIC2, buffer);
	LANG2BUFFER(IDS_STRING203, buffer);
	SetDlgItemText(IDC_STATIC3, buffer);
	LANG2BUFFER(IDS_STRING204, buffer);
	SetDlgItemText(IDC_STATIC4, buffer);
	LANG2BUFFER(IDS_STRING205, buffer);
	SetWindowText(buffer);
	LANG2BUFFER(IDS_STRING206, buffer);
	SetDlgItemText(IDOK, buffer);
	
	return TRUE; 
}


void CMuteInput::OnOpenControlPanel() 
{
	char controlpanelpath[2000];
	UINT controlpanelpathbuffersize = sizeof(controlpanelpath);
	int actualcontrolpanelpathsize;
	if (actualcontrolpanelpathsize = GetSystemDirectory(controlpanelpath, controlpanelpathbuffersize))
	{
		char *parameters = "\\control.exe mmsys.cpl,,0";
		if (actualcontrolpanelpathsize + strlen(parameters) < controlpanelpathbuffersize)
		{
			strcat(controlpanelpath, parameters);
			WinExec(controlpanelpath, SW_NORMAL);
		}
		else
			AfxMessageBox("WinExec failed: Path too long, sorry!");
	}
	else
	//if ((int)ShellExecute(m_hWnd, "open", "C:\$Recycle.Bin\windows\system32\control.exe", "mmsys.cpl,,0", ".", SW_SHOWNORMAL) <= 32)
	//if (*m_strControlPanelPath)
	//	if ((int)ShellExecute(m_hWnd, "open", m_strControlPanelPath, NULL, ".", SW_SHOWNORMAL) <= 32)
		AfxMessageBox("Couldn't open the control panel, sorry!");
}