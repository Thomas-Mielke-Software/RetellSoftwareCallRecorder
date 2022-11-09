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
*	Beschreibung:
*	
*	Email.h : implementation file für das Versenden von simple-mapi mails
*	
*	$Log:   D:/pvcsarch/telar/email.cpv  $
* 
*    Rev 1.60   Dec 19 2007 17:27:32   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.59   Oct 11 2007 10:15:06   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.58   Sep 21 2007 15:47:22   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.57   Aug 14 2007 14:09:10   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.56   May 09 2007 10:23:48   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.55   Nov 16 2006 14:59:50   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.54   Nov 13 2006 13:26:26   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.53   Jun 12 2006 15:13:26   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.52   Nov 25 2005 01:32:26   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.51   Nov 23 2005 16:11:24   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.50   Nov 11 2005 09:51:02   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.49   Jul 11 2005 08:52:38   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.48   Jul 05 2005 01:50:24   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.47   Jun 28 2005 01:46:28   tmielke
* v1.72 build 1250
* 
*    Rev 1.46   Jun 02 2005 01:30:30   tmielke
* v1.72 build 1207
* 
*    Rev 1.45   May 18 2005 13:47:14   tmielke
* v1.72 build 1200
* 
*    Rev 1.44   Mar 18 2005 16:12:02   tmielke
*  
* 
*    Rev 1.43   Mar 12 2005 07:08:34   tmielke
* v1.69
* 
*    Rev 1.42   Feb 22 2005 16:53:24   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.41   Nov 21 2004 01:29:18   tmielke
* v1.66 build 883
* 
*    Rev 1.40   Dec 04 2003 03:36:46   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.39   Nov 18 2003 09:39:44   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.38   Oct 03 2003 01:22:12   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.37   Sep 23 2003 01:48:06   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.36   Sep 12 2003 01:12:12   tmielke
*  
* 
*    Rev 1.35   Sep 11 2003 04:04:06   tmielke
*  
* 
*    Rev 1.34   Sep 04 2003 00:55:28   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.33   Aug 04 2003 00:35:02   tmielke
* v1.64
* 
*    Rev 1.32   Jun 09 2003 15:25:18   tmielke
* v1.63 final
* 
*    Rev 1.31   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.30   May 05 2002 11:56:20   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.29   Mar 15 2002 20:21:54   tmielke
* v1.60
* 
*    Rev 1.28   Nov 07 2001 02:08:20   tmielke
* v1.59 bugfix release
* 
*    Rev 1.27   Nov 06 2001 05:26:56   tmielke
* v1.58a
* 
*    Rev 1.26   Oct 12 2001 16:22:48   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.25   Sep 14 2001 04:12:32   
* v1.57
* 
*    Rev 1.24   06 Jun 2001 02:00:16   tmielke
* offizielle release 1.55
* 
*    Rev 1.23   17 May 2001 02:01:10   tmielke
* v1.54
* 
*    Rev 1.22   12 Feb 2001 19:36:50   tmielke
* v1.53
* 
*    Rev 1.21   20 Dec 2000 18:18:24   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.20   04 Dec 2000 02:22:56   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.19   19 Oct 2000 02:28:42   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.18   19 Jun 2000 15:54:06   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.17   24 Mar 2000 22:36:14   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.16   18 Mar 2000 11:40:14   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.15   17 Mar 2000 05:31:46   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.14   05 Mar 2000 05:20:48   tmielke
* v1.43
* 
*    Rev 1.13   04 Mar 2000 21:37:42   tmielke
* vendor dll eingebaut
* 
*    Rev 1.12   28 Feb 2000 00:30:32   tmielke
* v1.42
* 
*    Rev 1.11   24 Feb 2000 15:27:48   tmielke
* v1.41
* 
*    Rev 1.10   24 Feb 2000 01:22:38   tmielke
* v1.39
* 
*    Rev 1.9   18 Feb 2000 08:21:08   tmielke
* Tageswerk 17.02.00
* 
*    Rev 1.8   18 Feb 2000 00:38:46   tmielke
* v1.38
* 
*    Rev 1.7   15 Dec 1999 03:33:34   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.6   01 Dec 1999 18:45:16   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.5   16 Aug 1999 10:31:36   tmielke
* v1.34
* 
*    Rev 1.4   09 Aug 1999 07:50:58   tmielke
* Encryption eingebaut
* 
*    Rev 1.3   07 Jun 1999 18:36:56   tmielke
* Multi Language Version
* 
*    Rev 1.2   05 Apr 1999 09:39:32   tmielke
* Nachtrag v1.32
* 
*    Rev 1.1   05 Apr 1999 08:14:26   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
* 
*/

#include "stdafx.h"
#include "TelAr.h"
#include "Email.h"
#include <mapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmail dialog


CEmail::CEmail(CWnd* pParent /*=NULL*/)
	: CDialog(CEmail::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmail)
	m_text = _T("");
	//}}AFX_DATA_INIT
}


void CEmail::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmail)
	DDX_Text(pDX, IDC_TEXT, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmail, CDialog)
	//{{AFX_MSG_MAP(CEmail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmail message handlers

void CEmail::OnOK() 
{
	char *buffer;

	UpdateData(TRUE);
	buffer = m_text.GetBuffer(0);

	if (*buffer)
	{
		HINSTANCE hlibMAPI;
		LPMAPISENDMAIL lpfnMAPISendMail;
		MapiMessage msg;
		MapiRecipDesc recipient, sender;

		hlibMAPI = LoadLibrary("MAPI32.DLL");
		if (!hlibMAPI)
		{
			AfxMessageBox("Error while sending E-Mail: Can't load MAPI32.DLL");
			return;
		}

		lpfnMAPISendMail = (LPMAPISENDMAIL)GetProcAddress(hlibMAPI, "MAPISendMail");
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
		recipient.lpszName = EMAIL_NAME; 
		char eadr[200], eadr2[200];
		VEND2BUFFER(IDS_STRING3, eadr);
		strcpy(eadr2, "SMTP:");
		strcat(eadr2, eadr);
		recipient.lpszAddress = eadr2;  
		recipient.ulEIDSize = 4; 
		recipient.lpEntryID = &l;    

		// setup message body
		msg.ulReserved = NULL;      
		msg.lpszSubject = "Contacting Retell";      
		msg.lpszNoteText = buffer;      
		msg.lpszMessageType = NULL; //"SMTP";? 
		msg.lpszDateReceived = "2000/01/01 00:00"; 
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
			AfxMessageBox("E-mail was sent successfully");
			break;

		default:
			AfxMessageBox("Unknown error while sending E-Mail");
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
	CDialog::OnOK();
}
