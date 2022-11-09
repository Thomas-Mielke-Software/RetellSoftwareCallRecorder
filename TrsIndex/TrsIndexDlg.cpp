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

// TrsIndexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TrsIndex.h"
#include "TrsIndexDlg.h"
#include "..\telar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrsIndexDlg dialog

CTrsIndexDlg::CTrsIndexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrsIndexDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrsIndexDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrsIndexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrsIndexDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrsIndexDlg, CDialog)
	//{{AFX_MSG_MAP(CTrsIndexDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrsIndexDlg message handlers

BOOL CTrsIndexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	char buffer2[1000];
    HKEY hKey;
	*buffer2 = '\0';
	if (RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\TRS\\TelAr", &hKey) == ERROR_SUCCESS)
	{
		long lRetCode, lDummy;
		long lType = REG_SZ;
		long lCb = sizeof(buffer2);
		lDummy = 0L;
	
		lRetCode = RegQueryValueEx(hKey, TEXT("Path"), 
								   NULL, (ULONG *)&lType, 
								   (LPBYTE)buffer2, (ULONG *)&lCb);
		if (lRetCode == ERROR_SUCCESS)
		{
			SetDlgItemText(IDC_PAF, buffer2);
		}
	}
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrsIndexDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrsIndexDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTrsIndexDlg::OnOK() 
{
	char archive_path[1000];
	char first_file[1000];
	char index_filename[1000];
	GetDlgItemText(IDC_PAF, archive_path, sizeof(archive_path));
	if (!*archive_path) return;
	if (archive_path[strlen(archive_path)-1] != '\\') strcat(archive_path, "\\");
	strcpy(index_filename, archive_path);
	strcat(index_filename, INDEX_FILENAME);

	TMTabelle theTabelle(INDEX_FILEMAGIC, INDEX_FILECOLUMNS, INDEX_FILEVERSION);

	DWORD dw = GetFileAttributes(index_filename);
	if (dw != 0xFFFFFFFF)
	{
		if (AfxMessageBox("You are about to overwrite your original TRS index file. All note and reference entrys will be lost, if you decide to rebuild the index file. Really do it?", MB_YESNO) != IDYES) 
			return;

		if (!DeleteFile(index_filename))
		{
			AfxMessageBox("Old index file couldn't be deleted!", MB_ICONSTOP);
			return;
		}

	}

	theTabelle.Write(index_filename);
	
	strcpy(first_file, archive_path);
	strcat(first_file, "*.trs");


	int nCheck = ((CButton*) GetDlgItem(IDC_PASSWORDPROTECTED))->GetCheck();

	HANDLE hSearch;
	WIN32_FIND_DATA fd;

	hSearch = FindFirstFile(first_file, &fd);
	if (hSearch == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("Found no recordings ('*.trs' files) in this folder!");
		return;
	}

	do
	{
		TMZeile zeile;
		SYSTEMTIME systime;
		char buffer[1000];
		zeile.Spalte(SPID_DATEINAME) = fd.cFileName;
		zeile.Spalte(SPID_INITIALEN) = "XX";
		zeile.Spalte(SPID_GESPRAECHSPARTNER) = "";
		zeile.Spalte(SPID_NOTIZEN) = "";
		if (isalpha(fd.cFileName[0]) &&
			isalpha(fd.cFileName[1]) &&
			isdigit(fd.cFileName[2]) &&
			isdigit(fd.cFileName[3]) &&
			isdigit(fd.cFileName[4]) &&
			isdigit(fd.cFileName[5]) &&
			isdigit(fd.cFileName[6]) &&
			isdigit(fd.cFileName[7]) &&
			isdigit(fd.cFileName[8]) &&
			isdigit(fd.cFileName[9]) &&
			fd.cFileName[10] == '-' &&
			isdigit(fd.cFileName[11]) &&
			isdigit(fd.cFileName[12]) &&
			isdigit(fd.cFileName[13]) &&
			isdigit(fd.cFileName[14]) &&
			isdigit(fd.cFileName[15]) &&
			isdigit(fd.cFileName[16]) &&
			fd.cFileName[17] == '.')
		{
			zeile.Spalte(SPID_INITIALEN) = (CString) fd.cFileName[0] + fd.cFileName[1];
			sprintf(buffer, "%4.4s/%2.2s/%2.2s", fd.cFileName+2, fd.cFileName+6, fd.cFileName+8);
			zeile.Spalte(SPID_DATUM) = buffer;
			sprintf(buffer, "%2.2s:%2.2s:%2.2s", fd.cFileName+11, fd.cFileName+13, fd.cFileName+15);
			zeile.Spalte(SPID_ZEIT) = buffer;
		}
		else
		{
			FileTimeToSystemTime(&fd.ftCreationTime, &systime);
			sprintf(buffer, "%04d/%02d/%02d", (int)systime.wYear, (int)systime.wMonth, (int)systime.wDay);
			zeile.Spalte(SPID_DATUM) = buffer;
			sprintf(buffer, "%02d:%02d:%02d", (int)systime.wHour, (int)systime.wMinute, (int)systime.wSecond);
			zeile.Spalte(SPID_ZEIT) = buffer;
		}
		zeile.Spalte(SPID_CODEC) = "unknown CODEC format";
		zeile.Spalte(SPID_FORMAT) = "unknown CODEC subformat";
		zeile.Spalte(SPID_MODUS) = "";
		zeile.Spalte(SPID_DAUER) = "00:01:00";
		zeile.Spalte(SPID_GESCHUETZT) = nCheck ? "1" : "0";

		theTabelle.Append(index_filename, &zeile);
	} 
	while (FindNextFile(hSearch, &fd));

	AfxMessageBox("TRS archive index has been rebuilt.", MB_ICONINFORMATION);

	CDialog::OnOK();
}
