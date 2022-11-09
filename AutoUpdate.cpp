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
*    AutoUpdate.cpp : implementation file
*/

#include "stdafx.h"
#include "telar.h"
#include "AutoUpdate.h"
#include <afxinet.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CThreadParam, CObject)

/////////////////////////////////////////////////////////////////////////////
// CAutoUpdate dialog


CAutoUpdate::CAutoUpdate(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoUpdate::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoUpdate)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_thread = NULL;

    m_nLower=0;
    m_nUpper=-1;

	eta_n = 0;  // Anzahl Elemente im Array auf Null
}


void CAutoUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoUpdate)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAutoUpdate, CDialog)
	//{{AFX_MSG_MAP(CAutoUpdate)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// --- Thread Funktion ---

static int CheckForUpdate(CThreadParam *pThreadParam); // 1. Hilfsfunktion
static int DownloadUpdate(CThreadParam *pThreadParam, char *filename); // 2. Hilfsfunktion

UINT DownloadControllingFunction( LPVOID pParam )
{
	char local_Path_plus_Filename[2000];
    CThreadParam *pThreadParam = (CThreadParam*)pParam;

    if (pThreadParam == NULL ||
        !pThreadParam->IsKindOf(RUNTIME_CLASS(CThreadParam)))
		    return 1;	// illegal parameter

	pThreadParam->trans_bytes = 0;

	strcpy(local_Path_plus_Filename, pThreadParam->local_Path);
	if (local_Path_plus_Filename[strlen(local_Path_plus_Filename)-1] != '\\')
		strcat(local_Path_plus_Filename, "\\");
	strcat(local_Path_plus_Filename, pThreadParam->Filename);

	if (pThreadParam->cancel)
	{
		pThreadParam->status_text = "User canceled!";
		pThreadParam->canceled = TRUE;
		return 0;
	}

	pThreadParam->status_text = "Starting internet session";
	CInternetSession S("Auto Update FTP",1);//INTERNET_OPEN_TYPE_PRECONFIG | INTERNET_OPEN_TYPE_DIRECT
	CFtpConnection *f; 

	if (pThreadParam->cancel)
	{
		pThreadParam->status_text = "User canceled!";
		pThreadParam->canceled = TRUE;
		return 0;
	}

	try
	{ 
		pThreadParam->status_text = "Connecting to server";
		f = S.GetFtpConnection(pThreadParam->Server,pThreadParam->User,pThreadParam->Password,21,FALSE); 

		if (pThreadParam->cancel)
		{
			pThreadParam->status_text = "User canceled!";
			pThreadParam->canceled = TRUE;
			return 0;
		}

		pThreadParam->status_text = "Opening source direcory";
		f->SetCurrentDirectory(pThreadParam->FTP_Path); 
		//f->GetFile(pThreadParam->Filename,local_Path_plus_Filename,FALSE,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1);

		if (pThreadParam->cancel)
		{
			pThreadParam->status_text = "User canceled!";
			pThreadParam->canceled = TRUE;
			return 0;
		}

		// Dateinamen nach lowercase konvertieren
		// char filename_buffer[1000], *cp1, *cp2;
		// for (cp1 = pThreadParam->Filename, cp2 = filename_buffer; *cp1; cp1++, cp2++)
		// 	*cp2 = tolower(*cp1);

		pThreadParam->status_text = "Looking for update file";
		CFtpFileFind find(f);
		if (find.FindFile(pThreadParam->Filename))
		{
			find.FindNextFile(); // sucht nach nächstem file - ergebnis ist egal - und stellt die daten des ersten files zur verfügung

			pThreadParam->status_text = "Retrieving file size";
			pThreadParam->total_bytes = (int)find.GetLength();

			CInternetFile *pFtpFile;

			pThreadParam->status_text = "Opening file for download";
			try
			{
				pFtpFile = f->OpenFile(pThreadParam->Filename, GENERIC_READ, FTP_TRANSFER_TYPE_BINARY, 1);
			}
			catch (CInternetException* pEx)
			{
				char buffer[5000];
				pEx->GetErrorMessage(buffer, sizeof(buffer));
				AfxMessageBox(buffer, MB_ICONSTOP);
				pThreadParam->status_text = "FAILED: Couldn't open file on server!"; 
				pThreadParam->canceled = TRUE;
				pEx->Delete();
				return 0;
			}

			pThreadParam->status_text = "Downloading software update";
			CFile file;
			if (file.Open(local_Path_plus_Filename, CFile::modeCreate|CFile::modeWrite))
			{
				while (TRUE)
				{
					char buf[1024];
					int n = pFtpFile->Read(buf, sizeof(buf));
					if (n) file.Write(buf, n);
					pThreadParam->trans_bytes += n;
					if (pThreadParam->cancel)break;
					if (n < sizeof(buf)) break;
					if (pThreadParam->trans_bytes == pThreadParam->total_bytes) break;
				}
				file.Close();
				pFtpFile->Close();
				delete pFtpFile;

				delete f; 
				S.Close(); 
				
				if (pThreadParam->trans_bytes == pThreadParam->total_bytes)
				{
					pThreadParam->status_text = "Download of software update was successful!";
					pThreadParam->download_succeeded = TRUE;

					// hier Setup des Updates ausführen
					ShellExecute(NULL, "open", local_Path_plus_Filename, NULL, NULL, SW_SHOW);	
				}
				else
				{
					pThreadParam->status_text = "User canceled!";
					DeleteFile(local_Path_plus_Filename);
				}
			}
			else
			{
				pThreadParam->status_text = "FAILED: File open error on local system!"; 

				pFtpFile->Close();
				delete pFtpFile;

				delete f; 
				S.Close(); 
			}	
		}
		else
		{
			pThreadParam->status_text = "FAILED: Couldn't retrieve information about download file from server!"; 
			DWORD dw = GetLastError();
			LPVOID lpMsgBuf;
 
			FormatMessage( 
				FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
				NULL,
				GetLastError(),
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
				(LPTSTR) &lpMsgBuf,
				0,
				NULL 
			);

			if (lpMsgBuf)
			{
				// Display the string.
				AfxMessageBox((char *)lpMsgBuf, MB_OK|MB_ICONINFORMATION);

				// Free the buffer.
				LocalFree( lpMsgBuf );
			}

			delete f; 
			S.Close(); 
		}
	} 
	catch (CInternetException* pEx) 
	{ 
		char buffer[5000];
		pEx->GetErrorMessage(buffer, sizeof(buffer));
		AfxMessageBox(buffer, MB_ICONSTOP);
		pThreadParam->status_text = "FAILED: Couldn't get a connection to the internet!"; 
		pThreadParam->canceled = TRUE;
		pEx->Delete();
		return 0;
	} 

	pThreadParam->cancel = TRUE;
	pThreadParam->canceled = TRUE;
    return 0;	// thread completed successfully
}


UINT CheckForUpdate( LPVOID pParam )
{
    CThreadParam *pThreadParam = (CThreadParam*)pParam;
	
	static char statbuf[200];
	strcpy(statbuf, pThreadParam->status_text);
	pThreadParam->status_text = statbuf;
	strcat(pThreadParam->status_text, "Looking for update information...");

	CInternetSession S("Auto Update FTP",1);//INTERNET_OPEN_TYPE_PRECONFIG | INTERNET_OPEN_TYPE_DIRECT
	CFtpConnection *f; 

	static char version_information[10000];

	if (pThreadParam->cancel)
	{
		pThreadParam->status_text = "User canceled!";
		S.Close(); 
		return 0;
	}

	try
	{
		f = S.GetFtpConnection(pThreadParam->Server,pThreadParam->User,pThreadParam->Password,21,FALSE); 

		if (pThreadParam->cancel)
		{
			pThreadParam->status_text = "User canceled!";
			delete f; 
			S.Close(); 
			return 0;
		}

		// Verzeichnis wechseln
		f->SetCurrentDirectory(FTP_DOWNLOAD_PATH); 
		strcat(pThreadParam->status_text, ".");

		if (pThreadParam->cancel)
		{
			pThreadParam->status_text = "User canceled!";
			delete f; 
			S.Close(); 
			return 0;
		}

		// Datei suchen
		strcat(pThreadParam->status_text, ".");
		CFtpFileFind find(f);
		if (find.FindFile(FTP_DOWNLOAD_VERSION_FILENAME, INTERNET_FLAG_RELOAD))
		{
			find.FindNextFile(); // sucht nach nächstem file - ergebnis ist egal - und stellt die daten des ersten files zur verfügung

			strcat(pThreadParam->status_text, ".");
			int version_information_bytes = (int)find.GetLength();
			if (version_information_bytes > sizeof(version_information)-1)
				version_information_bytes = sizeof(version_information)-1;

			CInternetFile *pFtpFile;

			strcat(pThreadParam->status_text, ".");
			try
			{
				char filename_buffer[2000];
				strcpy(filename_buffer, FTP_DOWNLOAD_PATH);
				strcat(filename_buffer, FTP_DOWNLOAD_VERSION_FILENAME);
				pFtpFile = f->OpenFile(filename_buffer, GENERIC_READ, FTP_TRANSFER_TYPE_BINARY, 1);
			}
			catch (CInternetException* pEx)
			{
				char buffer[5000];
				pEx->GetErrorMessage(buffer, sizeof(buffer));
				AfxMessageBox(buffer, MB_ICONSTOP);
				pThreadParam->status_text = "FAILED: Couldn't find update information on server!"; 
				pEx->Delete();
				delete f; 
				S.Close(); 
				return 0;
			}

			strcat(pThreadParam->status_text, ".");

			int n = pFtpFile->Read(version_information, version_information_bytes);
			if (pThreadParam->cancel)
			{
				pThreadParam->status_text = "User canceled!";
				pFtpFile->Close();
				delete pFtpFile;
				delete f; 
				S.Close(); 
				return 0;
			}
			version_information[version_information_bytes] = '\0';

			if (!version_information_bytes || tolower(*version_information) != 'v')
			{
				pThreadParam->status_text = "FAILED: Couldn't find valid update information on server!"; 
				pFtpFile->Close();
				delete pFtpFile;
				delete f; 
				S.Close(); 
				return 0;
			}

			char *cp = strchr(version_information+1, ':');
			if (!cp)
			{
				pThreadParam->status_text = "FAILED: Couldn't find valid update information on the server!"; 
				pFtpFile->Close();
				delete pFtpFile;
				delete f; 
				S.Close(); 
				return 0;
			}


			*cp++ = '\0';
			if (!strcmp(version_information, version_string))
			{
				pThreadParam->status_text = "No application update available.";
				pFtpFile->Close();
				delete pFtpFile;
				delete f; 
				S.Close(); 
				AfxMessageBox("No application update available.");
				return 0;			// --> hier 'raus wenn kein neues update verfügbar
			}

			float verServer, verInstalled;
			sscanf(version_information+1, "%f", &verServer);
			sscanf(version_string+1, "%f", &verInstalled);
			if (verInstalled > verServer)
			{
				pThreadParam->status_text = "Installed version more up-to-date than the one on the server.";
				pFtpFile->Close();
				delete pFtpFile;
				delete f; 
				S.Close(); 
				AfxMessageBox("Installed version more up-to-date than the one on the server.");
				return 0;			// --> hier 'raus wenn installierte version neuer als die auf dem server
			}
			
			pFtpFile->Close();
			delete pFtpFile;
			delete f; 
			S.Close(); 

			char search_and_cut_version_info[100];
			strcpy(search_and_cut_version_info, version_string);
			strcat(search_and_cut_version_info, ":");
			char *cp2 = strstr(cp, search_and_cut_version_info);
			if (cp2) *cp2 = '\0';

			pThreadParam->status_text = "New application update available.";
			pThreadParam->version_information = cp;
			pThreadParam->update_available = TRUE;

			return 1;				// --> hier 'raus wenn neues update verfügbar war

		}
		else
		{
			pThreadParam->status_text = "FAILED: Couldn't retrieve information about application update from server!"; 
			DWORD dw = GetLastError();
			LPVOID lpMsgBuf;

			FormatMessage( 
				FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
				NULL,
				dw,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
				(LPTSTR) &lpMsgBuf,
				0,
				NULL 
			);

			if (lpMsgBuf)
			{
				// Display the string.
				MessageBox( NULL, (char *)lpMsgBuf, "GetLastError", MB_OK|MB_ICONINFORMATION );

				// Free the buffer.
				LocalFree( lpMsgBuf );
			} 
			delete f; 
			S.Close(); 

			return 0;
		}
	} 
	catch (CInternetException* pEx) 
	{ 
		char buffer[5000];
		pEx->GetErrorMessage(buffer, sizeof(buffer));
		AfxMessageBox(buffer, MB_ICONSTOP);
		pThreadParam->status_text = "FAILED: Couldn't get a connection to the internet!"; 
		pEx->Delete();
		S.Close(); 
		return 0;
	} 

	pThreadParam->cancel = TRUE;
	pThreadParam->canceled = TRUE;
    return 0;	// thread completed successfully
}

/////////////////////////////////////////////////////////////////////////////
// CAutoUpdate message handlers

// --- INIT Dialog ---

BOOL CAutoUpdate::OnInitDialog() 
{
	CDialog::OnInitDialog();

	GetDlgItem(IDOK)->EnableWindow(FALSE);	
	m_bNotYetDownloaded = TRUE;

	//CheckForUpdate
	SetDlgItemText(IDC_INFO, "Please wait...");

	((CProgressCtrl *)GetDlgItem(CG_IDC_PROGDLG_PROGRESS))->SetRange(0, 100);

	m_pThreadParam = new CThreadParam;
	
	strcpy(m_pThreadParam->Server, FTP_DOWNLOAD_SERVER);
	strcpy(m_pThreadParam->FTP_Path, FTP_DOWNLOAD_PATH);
	strcpy(m_pThreadParam->User, FTP_DOWNLOAD_USER);
	strcpy(m_pThreadParam->Password, FTP_DOWNLOAD_PASSWORD);
	
	m_pThreadParam->status_text = "";
	m_pThreadParam->cancel = FALSE;
	m_pThreadParam->canceled = FALSE;
	m_pThreadParam->trans_bytes = 0;
	m_pThreadParam->total_bytes = 0;
	m_pThreadParam->update_available = FALSE;
	m_pThreadParam->version_information = '\0';
	m_pThreadParam->download_succeeded = FALSE;

	SetTimer(1, ETA_INTERVALL, NULL);

	m_thread = AfxBeginThread(&(CheckForUpdate), (LPVOID)m_pThreadParam, THREAD_PRIORITY_LOWEST);

	return TRUE;  
}

// --- OK Knopf ---

void CAutoUpdate::OnOK() 
{
	UpdateData(TRUE);


	// local download path is temp directory
	CString download_dir;
	char *cp = download_dir.GetBuffer(1000);
	if (!GetTempPath(1000, cp)) { AfxMessageBox("Unable to retrieve Windows temp directory."); return; }
	if (download_dir.GetBuffer(0)[download_dir.GetLength()-1] == '\\')
		download_dir.GetBuffer(0)[download_dir.GetLength()-1] = '\0';
	
	m_pThreadParam = new CThreadParam;
	
	strcpy(m_pThreadParam->Server, FTP_DOWNLOAD_SERVER);
	strcpy(m_pThreadParam->FTP_Path, FTP_DOWNLOAD_PATH);
	strcpy(m_pThreadParam->local_Path, (LPCSTR)download_dir);
	strcpy(m_pThreadParam->Filename, FTP_DOWNLOAD_FILENAME);
	strcpy(m_pThreadParam->User, FTP_DOWNLOAD_USER);
	strcpy(m_pThreadParam->Password, FTP_DOWNLOAD_PASSWORD);
	
	m_pThreadParam->status_text = "";
	m_pThreadParam->cancel = FALSE;
	m_pThreadParam->canceled = FALSE;
	m_pThreadParam->trans_bytes = 0;
	m_pThreadParam->total_bytes = 0;
	m_pThreadParam->update_available = FALSE;
	m_pThreadParam->download_succeeded = FALSE;

	//SetTimer(1, ETA_INTERVALL, NULL);

	m_thread = AfxBeginThread(&(DownloadControllingFunction), (LPVOID)m_pThreadParam, THREAD_PRIORITY_LOWEST);
	m_bNotYetDownloaded = FALSE;
}

// --- Cancel Knopf ---

// defaultmäßig diese Funktion zum Verlassen des Dialogs benutzen!
void CAutoUpdate::OnCancel() 
{
	if (m_bNotYetDownloaded)
	{

		if (m_pThreadParam->download_succeeded)
			CDialog::OnOK();
		else
			CDialog::OnCancel();
		
		return;
	}

	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);

	if (m_pThreadParam) 
	{
		m_pThreadParam->cancel = TRUE;
		m_pThreadParam->status_text = "Please wait while the internet connection is being closed...";
	}

}

// --- WM_TIMER ---

void CAutoUpdate::OnTimer(UINT_PTR nIDEvent) 
{
	if (m_pThreadParam)
	{
		char buffer[1000];

		if (m_pThreadParam->update_available)
		{
			GetDlgItem(IDOK)->EnableWindow(TRUE);
			SetDlgItemText(IDC_INFO, m_pThreadParam->version_information);
			m_pThreadParam->update_available = FALSE;
		}

		if (m_pThreadParam->total_bytes >= 0)
			if (m_pThreadParam->trans_bytes <= m_pThreadParam->total_bytes)
			{
				((CProgressCtrl *)GetDlgItem(CG_IDC_PROGDLG_PROGRESS))->SetRange(0, m_pThreadParam->total_bytes/1024);
				SetPos();
			}

		if (!m_pThreadParam->trans_bytes)
			SetDlgItemText(IDC_STATUS, m_pThreadParam->status_text);
		else
		{
			if (eta_n >= ETA_ARRAY_SIZE) // array schon voll?
			{
				// nach unten schieben
				for (int i = 0; i < ETA_ARRAY_SIZE-1; i++)
				{
					eta_array[i] = eta_array[i+1];
				}
				eta_array[ETA_ARRAY_SIZE-1] = m_pThreadParam->trans_bytes;
			}
			else
				eta_array[eta_n++] = m_pThreadParam->trans_bytes; // einfach hinzufügen

			int data_rate = 0; // Bytes pro 1/10-Sekunde
			int remaining_time = 0; // Rest-Zeit in Sekunden
			if (eta_n >= 2) //min. 2 Meßwerte um Differenz zu bestimmen
			{
				data_rate = (eta_array[eta_n-1] - eta_array[0]) * 10 / (ETA_INTERVALL * (eta_n-1)); 
				if (data_rate == 0) 
					remaining_time = 23 * 3600 + 59 * 60 + 59;
				else
					remaining_time = (m_pThreadParam->total_bytes - m_pThreadParam->trans_bytes) / 100 / data_rate;
			
				if (m_pThreadParam->total_bytes == m_pThreadParam->trans_bytes)
					data_rate = 0;			
			}
			sprintf(buffer, "%s\r\nBytes transferred: %d\tkb/sec.: %3.1f \teta: %02d:%02d:%02d", 
				m_pThreadParam->status_text, 
				(int)m_pThreadParam->trans_bytes,
				(float)data_rate / 10.0,
				remaining_time / 3600/*h*/, (remaining_time / 60) % 60/*m*/, remaining_time % 60
			);
			SetDlgItemText(IDC_STATUS, buffer);
		}

		if (m_pThreadParam->download_succeeded)
		{
			SetDlgItemText(IDCANCEL, "OK");
		}

		// Auf Thread warten bei cancel:
		if (m_pThreadParam->cancel)
		{
			if (m_pThreadParam->canceled)
			{
				BOOL bDoOK = m_pThreadParam->download_succeeded;
				delete m_pThreadParam;
				m_pThreadParam = NULL;

				if (bDoOK)
					CDialog::OnOK();
				else
					CDialog::OnCancel();
			}
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CAutoUpdate::UpdatePercent(int nNewPos)
{
    CWnd *pWndPercent = GetDlgItem(CG_IDC_PROGDLG_PERCENT);
    int nPercent;
    
    int nDivisor = m_pThreadParam->total_bytes;

    int nDividend = nNewPos;

	if (!nDivisor) return;
	if (nDividend >= 0x01000000)
		nPercent = nDividend / (nDivisor / 100); // nur wenn die Gefahr eines Überlaufs besteht
	else
		nPercent = nDividend * 100 / nDivisor;

    // Since the Progress Control wraps, we will wrap the percentage
    // along with it. However, don't reset 100% back to 0%
    if(nPercent<100)
      nPercent %= 100;
    if(nPercent>100)
      nPercent = 100;

    // Display the percentage
    CString strBuf;
    strBuf.Format(_T("%d%c"),nPercent,_T('%'));

	CString strCur; // get current percentage
    pWndPercent->GetWindowText(strCur);

	if (strCur != strBuf)
		pWndPercent->SetWindowText(strBuf);
}

int CAutoUpdate::SetPos()
{
	if (!m_pThreadParam) return 0;

    PumpMessages();

	if (!m_pThreadParam) return 0;
    int iResult = ((CProgressCtrl *)GetDlgItem(CG_IDC_PROGDLG_PROGRESS))->SetPos(m_pThreadParam->trans_bytes/1024);
    UpdatePercent(m_pThreadParam->trans_bytes);
    return iResult;
}

void CAutoUpdate::PumpMessages()
{
    // Must call Create() before using the dialog
    ASSERT(m_hWnd!=NULL);

    MSG msg;
    // Handle dialog messages
    while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      if(!IsDialogMessage(&msg))
      {
        TranslateMessage(&msg);
        DispatchMessage(&msg);  
      }
    }
}


