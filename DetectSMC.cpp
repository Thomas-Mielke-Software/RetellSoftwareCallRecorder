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
*    DetectSMC.cpp : implementation file
*/

#include "stdafx.h"
#include "telar.h"
#include "DetectSMC.h"
#include <mmsystem.h>
#include "./wavein/wavein.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDetectSMC dialog


CDetectSMC::CDetectSMC(CWnd* pParent /*=NULL*/)
	: CDialog(CDetectSMC::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetectSMC)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDetectSMC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetectSMC)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDetectSMC, CDialog)
	//{{AFX_MSG_MAP(CDetectSMC)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDetectSMC message handlers

BOOL CDetectSMC::OnInitDialog() 
{
	char buffer[1000];

	CDialog::OnInitDialog();
	
	WaveIn_SetControlTone(FALSE);
	WaveIn_ProbeControlToneChannel(TRUE);
	int n = WaveIn_Open(NULL, X_aufnahmegeraet, 2, 8000, 16, -1L, -1);
	if (!n)
	{
		LANG_SETCTRLTEXT(IDS_STRING144, IDC_STATUS);	// "Audio device could not be opened"
		WaveIn_ProbeControlToneChannel(FALSE);
	}
	else
	{
		WaveIn_Start();
		WaveIn_SetControlTone(FALSE);
		SetTimer(1, 100, NULL);
		m_couter = 50;
		CString cs;
		LANG2BUFFER(IDS_STRING145, buffer);	// "Cancel (%d seconds)"
		cs.Format(buffer, m_couter);
		SetDlgItemText(IDCANCEL, cs);
	}

	LANG_SETCTRLTEXT(IDS_STRING102, IDCANCEL)
	
	return TRUE; 
}

void CDetectSMC::OnTimer(UINT_PTR nIDEvent) 
{
	switch (nIDEvent)
	{
	case 1:

		{
			int n = WaveIn_GetProbeControlToneChannelResult();
			if (n == -1) 
				LANG_SETCTRLTEXT(IDS_STRING146, IDC_STATUS)	// "No result yet...."
			else
			{
				if (n == 0) 
					LANG_SETCTRLTEXT(IDS_STRING147, IDC_STATUS)  // "No Intelligent Recording Interface detected"
				else
				{
					char b1[100], b2[100], b3[100], b4[100];
					LANG2BUFFER(IDS_STRING148, b1);
					LANG2BUFFER(IDS_STRING149, b2);
					LANG2BUFFER(IDS_STRING150, b3);
					LANG2BUFFER(IDS_STRING151, b4);

					CString cs;
					
					if (n & 1) cs += (CString)b1 + "\n\r";
					if (n & 2) cs += (CString)b2 + "\n\r";
					if (n & 4) cs += (CString)b3 + "\n\r";
					if (n & 8) cs += (CString)b4 + "\n\r";

					SetDlgItemText(IDC_STATUS, cs);

					WaveIn_ReallocBuffer();

					m_result = n;
					KillTimer(1);
					SetTimer(2, 1000, NULL);
				}
			}

			if (--m_couter >= 0)
			{
				CString cs;
				char buffer[100];
				LANG2BUFFER(IDS_STRING145, buffer);	// "Cancel (%d seconds)"
				cs.Format(buffer, m_couter/10);
				SetDlgItemText(IDCANCEL, cs);
			}
			else
				OnCancel();
		}
		break;

	case 2:
		KillTimer(2);
		OnOK();
		break;
	}

	CDialog::OnTimer(nIDEvent);
}

void CDetectSMC::OnOK() 
{
	WaveIn_ProbeControlToneChannel(0);
	WaveIn_Stop();
	WaveIn_Close();

	X_ControlToneChannel = m_result & 0x3 ? 0 : 1;
	WaveIn_SetControlToneChannel(X_ControlToneChannel);
	WaveIn_SetControlTone(TRUE);

	CDialog::OnOK();
}

void CDetectSMC::OnCancel() 
{
	WaveIn_ProbeControlToneChannel(0);
	WaveIn_Stop();
	WaveIn_Close();
	
	WaveIn_SetControlTone(FALSE);

	CDialog::OnCancel();
}
