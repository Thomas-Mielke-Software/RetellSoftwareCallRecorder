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

#if !defined(AFX_AUTOUPDATE_H__CFA596F8_337C_4691_90C1_AEB004B4C929__INCLUDED_)
#define AFX_AUTOUPDATE_H__CFA596F8_337C_4691_90C1_AEB004B4C929__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AutoUpdate.h : header file
//

//#define FTP_DOWNLOAD_SERVER "168.100.0.2"

#define FTP_DOWNLOAD_SERVER		"957ftp.no-ip.org"
#if !defined(_WIN64)
#define FTP_DOWNLOAD_PATH		"/regular/"
#define FTP_DOWNLOAD_FILENAME	"SCR_Setup.exe"
#else
#define FTP_DOWNLOAD_PATH		"/regular64/"
#define FTP_DOWNLOAD_FILENAME	"SCR_UD_SetupX64.exe"
#endif
#define FTP_DOWNLOAD_VERSION_FILENAME   "version.txt"
#define FTP_DOWNLOAD_USER		"scr957ud"
#define FTP_DOWNLOAD_PASSWORD   "???"

class CThreadParam : public CObject
{
public:
	DECLARE_DYNAMIC( CThreadParam )
	char Server[1000];
	char FTP_Path[1000];
	char local_Path[1000];
	char User[100];
	char Password[100];
	char Filename[1000];
	int  trans_bytes;
	int  total_bytes;
	char *status_text;
	char *version_information;
	BOOL cancel;			// Kommando an Thread
	BOOL canceled;			// Bestätigung von Thread
	BOOL update_available;	// true if ...
	BOOL download_succeeded;
};

/////////////////////////////////////////////////////////////////////////////
// CAutoUpdate dialog

class CAutoUpdate : public CDialog
{
// Construction
public:
	CAutoUpdate(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoUpdate)
	enum { IDD = IDD_AUTO_UPDATE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	void UpdatePercent(int nNewPos);
	int SetPos();
	void PumpMessages();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoUpdate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// zur Kalkulation der Restzeit:
#define  ETA_INTERVALL 500	// Timer-Intervall in Millisekunden
#define  ETA_ARRAY_SIZE 30
	int  eta_array[ETA_ARRAY_SIZE];
	int  eta_n; // Anzahl gespeicherter Elemente im Array

	CString m_URL;
	CWinThread *m_thread;
	CThreadParam* m_pThreadParam;
    int m_nLower;
    int m_nUpper;
	BOOL m_bNotYetDownloaded;

	// Generated message map functions
	//{{AFX_MSG(CAutoUpdate)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOUPDATE_H__CFA596F8_337C_4691_90C1_AEB004B4C929__INCLUDED_)
