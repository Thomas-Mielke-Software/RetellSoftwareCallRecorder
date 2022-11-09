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

// EnterResponseKey.cpp : implementation file
//

#include "stdafx.h"
#include <mapi.h>
#include "resource.h"
#include "EnterResponseKey.h"
#include "EnterContactDetails.h"
#include "telar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CEnterResponseKey dialog


CEnterResponseKey::CEnterResponseKey(int nTemplate, CWnd* pParent /*=NULL*/)
	: CDialog(nTemplate, pParent)
{
	//{{AFX_DATA_INIT(CEnterResponseKey)
	m_request_code = _T("");
	m_response_code = _T("");
	//}}AFX_DATA_INIT
}


void CEnterResponseKey::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterResponseKey)
	DDX_Text(pDX, IDC_REQUESTCODE, m_request_code);
	DDX_Text(pDX, IDC_RESPONSECODE, m_response_code);
	DDV_MaxChars(pDX, m_response_code, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterResponseKey, CDialog)
	//{{AFX_MSG_MAP(CEnterResponseKey)
	ON_EN_CHANGE(IDC_RESPONSECODE, OnChangeResponseCode)
	ON_BN_CLICKED(IDC_MAPIMAIL, OnMapimail)
	ON_BN_CLICKED(IDC_INTERNETMAIL, OnInternetmail)
	ON_BN_CLICKED(IDC_COPYTOCLIPBOARD, OnCopytoclipboard)
	ON_BN_CLICKED(IDC_WWW, OnWww)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterResponseKey message handlers

BOOL CEnterResponseKey::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (!m_product.IsEmpty()) SetWindowText(m_product);
	
	SetDlgItemText(IDC_PHONE, m_phone);
	return TRUE;
}

void CEnterResponseKey::OnChangeResponseCode() 
{
	CString cs;
	GetDlgItemText(IDC_RESPONSECODE, cs);
	if (cs.GetLength() == 30)
		GetDlgItem(IDOK)->EnableWindow(TRUE);
	else
		GetDlgItem(IDOK)->EnableWindow(FALSE);
}


void CEnterResponseKey::OnMapimail() 
{
	char msgbuffer[1000];
	char vend_name[1000];
	char vend_email[1000];
	VEND2BUFFER(IDS_STRING1, vend_name);
	VEND2BUFFER(IDS_STRING3, vend_email);

	LANG2BUFFER(IDS_STRING110, msgbuffer);	// "Do you have a properly installed MAPI mail system (like Microsoft Outlook)?"
	if (AfxMessageBox(msgbuffer, MB_YESNO) == IDNO)
	{
		LANG_MESSAGEBOX1(IDS_STRING111);   // "Sorry, then you have to submit the request code in some other manner."
		return;
	}

	CString text;
	CEnterContactDetails dlg;
	if (dlg.DoModal() != IDOK) { LANG_MESSAGEBOX1(IDS_STRING120); return; } // Mail canceled.
	text.Format("Name:%s\n\rPhone:%s\n\rBuyFrom:%s\n\r", dlg.m_name.GetBuffer(0), dlg.m_phone.GetBuffer(0), dlg.m_from.GetBuffer(0));
	
	char *buffer;

	buffer = text.GetBuffer(0);

	if (*buffer)
	{
		HINSTANCE hlibMAPI;
		typedef ULONG (FAR PASCAL *LPFNMAPISENDMAIL)(
			LHANDLE, 	
			ULONG, 	
			lpMapiMessage, 	
			FLAGS, 	
			ULONG	
		);
		LPFNMAPISENDMAIL lpfnMAPISendMail;
		MapiMessage msg;
		MapiRecipDesc recipient, sender;

		hlibMAPI = LoadLibrary("MAPI32.DLL");
		if (!hlibMAPI)
		{
			AfxMessageBox("Error while sending E-Mail: Can't load MAPI32.DLL");
			return;
		}

		lpfnMAPISendMail = (LPFNMAPISENDMAIL)GetProcAddress(hlibMAPI, "MAPISendMail");
		if (!lpfnMAPISendMail)
		{
			AfxMessageBox("Error while sending E-Mail: Can't locate function 'MAPISendMail' in 'MAPI32.DLL'");
			return;
		}

		long l = 123456;
		unsigned long ul;

		sender.ulReserved = NULL;   
		sender.ulRecipClass = MAPI_ORIG; 
		sender.lpszName = "generic"; 
		sender.lpszAddress = "SMTP:generic@generic.org";  
		sender.ulEIDSize = 4; 
		sender.lpEntryID = &l;    

		recipient.ulReserved = NULL;   
		recipient.ulRecipClass = MAPI_TO; 
		recipient.lpszName = vend_name; 
		CString emaiadr = (CString)"SMTP:" + (CString)vend_email;
		recipient.lpszAddress = emaiadr.GetBuffer(0);  
		recipient.ulEIDSize = 4; 
		recipient.lpEntryID = &l;    

		CString csSubject = m_request_code;
		char sComputerName[MAX_COMPUTERNAME_LENGTH + 1];
		DWORD dwSize = sizeof(sComputerName);
		GetComputerName(sComputerName, &dwSize);
		csSubject += "/" + (CString)sComputerName;

		// setup message body
		msg.ulReserved = NULL;      
		msg.lpszSubject = csSubject.GetBuffer(0);      
		msg.lpszNoteText = buffer;      
		msg.lpszMessageType = NULL; //"SMTP";? 
		msg.lpszDateReceived = "2002/01/01 00:00"; 
		msg.lpszConversationID = NULL;      
		msg.flFlags = MAPI_RECEIPT_REQUESTED;      
		msg.lpOriginator = &sender; 
		msg.nRecipCount = 1;      
		msg.lpRecips = &recipient;      
		msg.nFileCount = 0;      
		msg.lpFiles = NULL;           

		ul = (*lpfnMAPISendMail)(NULL, (ULONG)AfxGetMainWnd(), &msg, MAPI_LOGON_UI, NULL);
		FreeLibrary(hlibMAPI);

		switch (ul)
		{
		case MAPI_E_LOGIN_FAILURE:
			AfxMessageBox("Error while sending E-Mail: Coldn't login");
			return;

		case MAPI_E_INSUFFICIENT_MEMORY:
			AfxMessageBox("Error while sending E-Mail: There was insufficient memory to send the e-mail");
			return;

		case MAPI_E_USER_ABORT:
			AfxMessageBox("User canceled mail creation");
			return;

		case SUCCESS_SUCCESS:
			// AfxMessageBox("E-mail was sent successfully");
			break;

		default:
			AfxMessageBox("Error while sending E-Mail. Use 'Open with Notepad' or install a MAPI mailer.");
			return;
		}
		goto EndDialog;
	}
	else
	{
		AfxMessageBox("No message body. Enter some text or press cancel to exit.", MB_ICONINFORMATION);
		return;
	}

EndDialog:
	;
}

void CEnterResponseKey::OnInternetmail() 
{
	char buffer[1000];
	char vend_email[1000];
	char body[1000];
	VEND2BUFFER(IDS_STRING3, vend_email);

	CEnterContactDetails dlg;
	if (dlg.DoModal() != IDOK) { LANG_MESSAGEBOX1(IDS_STRING120); return; } // Mail canceled.
	sprintf(body, "Name:%s\n\rPhone:%s\n\rBuyFrom:%s\n\r", dlg.m_name.GetBuffer(0), dlg.m_phone.GetBuffer(0), dlg.m_from.GetBuffer(0));

	for (char *cp = body; *cp; cp++) if (!isalnum(*cp)&&!strchr("./*,&;:-!?()+", *cp)) *cp = '~';
	sprintf(buffer, "mailto:%s?subject=%s?body=%s", vend_email, m_request_code.GetBuffer(0));
	int n = (int)ShellExecute(m_hWnd, "open", buffer, NULL, ".", SW_SHOWNORMAL);
	if (n <= 32)
	{
		LANG_MESSAGEBOX1(IDS_STRING113); // "There was a little problem with the e-mail software on this workstation. Please try if MAPI mailing works better."
		return;
	}
}

void CEnterResponseKey::OnCopytoclipboard() 
{
	// get global memory
	HGLOBAL hmem = GlobalAlloc(GMEM_SHARE, m_request_code.GetLength()+1);
	char *cp = (char *)GlobalLock(hmem);
	strcpy(cp, m_request_code.GetBuffer(0));
	GlobalUnlock(cp);

	// put URN to clipboard
	OpenClipboard();
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hmem);	
	CloseClipboard();
}

void CEnterResponseKey::OnWww() 
{
	char buffer2[256];
    HKEY hKey;
	char wwwadr[200], wwwadr2[200];

	GetDlgItemText(IDC_REQUESTCODE, wwwadr, sizeof(wwwadr));
	strcpy(wwwadr2, "http://957.no-ip.org/licensing/enter_details.php?resquestcode=");
	strcat(wwwadr2, wwwadr);

	if ((DWORD)ShellExecute(m_hWnd, "open", wwwadr2, NULL, ".", SW_SHOWNORMAL) > 32)
	{
		return;
	}

	// was anderes versuchen... :-/

	static struct { 
		HKEY base;
		char *name;
	} keys[] = {
		HKEY_CURRENT_USER,"SOFTWARE\\TRS\\TelAr\\browser",
		HKEY_CLASSES_ROOT, "http\\shell\\open\\command",
		HKEY_CLASSES_ROOT, "HtmlDefBrowser\\shell\\open\\command",
		HKEY_CLASSES_ROOT, "html_auto_file\\shell\\open\\command",
		HKEY_CLASSES_ROOT, "htmlfile\\shell\\open\\command"
	};

	// einige Registry-Werte abfragen... empirisch vorgehen!
	for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
	{
		*buffer2 = '\0';
		if (RegCreateKey(keys[i].base, keys[i].name, &hKey) == ERROR_SUCCESS)
		{
			long lRetCode, lDummy;
			long lType = REG_SZ;
			long lCb = sizeof(buffer2);
			lDummy = 0L;
			
			lRetCode = RegQueryValueEx(hKey, TEXT(""), 
									   NULL, (ULONG *)&lType, 
									   (LPBYTE)buffer2, (ULONG *)&lCb);
			RegCloseKey(hKey);
			if (lRetCode != ERROR_SUCCESS || !*buffer2)
			{
				continue;
			}
			
			// störendes abschneiden...
			char *cp;
			if (cp = strstr(buffer2, " %1"))
				*cp = '\0';
			if (cp = strstr(buffer2, ".exe"))
				cp[4] = '\0';

			if (*buffer2)
			{
				DWORD dw = GetFileAttributes(buffer2);
				if (dw != 0xFFFFFFFF) break;
			}				
		}
	}

	if (!*buffer2)
	{
		AfxMessageBox("Sorry, couldn't find a browser.");
		return;
	}

	/*
	else
	{
		AfxMessageBox("Sorry, no default browser.");
		return;
	}
*/

	// Ausführen...
	SHELLEXECUTEINFO sef;
    sef.cbSize = sizeof(sef); 
    sef.fMask = 0;//SEE_MASK_FLAG_NO_UI; 
    sef.hwnd = m_hWnd; 
    sef.lpVerb = "Open"; 
    sef.lpFile = buffer2; 
    sef.lpParameters = wwwadr2; 
    sef.lpDirectory = NULL; 
    sef.nShow = SW_MAXIMIZE; 
    sef.hInstApp = 0; 

	ShellExecuteEx(&sef);

	CString errstr;
	switch ((int)sef.hInstApp)
	{
	case SE_ERR_FNF:			errstr = "File not found";
								break;
	case SE_ERR_PNF:			errstr = "Path not found";
								break;
	case SE_ERR_ACCESSDENIED:	errstr = "Access denied";
								break;
	case SE_ERR_OOM:			errstr = "Out of memory";
								break;
	case SE_ERR_DLLNOTFOUND:	errstr = "Dynamic-link library not found";
								break;
	case SE_ERR_SHARE:			errstr = "Cannot share open file";
								break;
	case SE_ERR_ASSOCINCOMPLETE:errstr = "errstr = 	File association information not complete";
								break;
	case SE_ERR_DDETIMEOUT:		errstr = "DDE operation timed out";
								break;
	case SE_ERR_DDEFAIL:		errstr = "DDE operation failed";
								break;
	case SE_ERR_DDEBUSY:		errstr = "DDE operation busy";
								break;
	case SE_ERR_NOASSOC:		errstr = "File association not available";
								break;
	default: errstr = "";
	}
	if (errstr != "")
	{
		AfxMessageBox( errstr );
	}

	// alter aufruf:
	// ShellExecute(this->m_hWnd, "open", "http://www.retell.co.uk", NULL, NULL, SW_SHOW);	

}
