/*	$Header:   D:/pvcsarch/telar/TelArPropSheetFrame.cpv   1.36   Dec 19 2007 17:27:28   tmielke  $
*
*	Beschreibung:
*     This file contains the mini-frame that controls modeless 
*     property sheet
*	
*	TelArPropertyPage.cpp : implementation file
*	
*	$Log:   D:/pvcsarch/telar/TelArPropSheetFrame.cpv  $
* 
*    Rev 1.36   Dec 19 2007 17:27:28   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.35   Oct 11 2007 10:15:02   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.34   Sep 21 2007 15:47:18   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.33   Aug 14 2007 14:09:06   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.32   May 09 2007 10:23:42   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.31   Nov 16 2006 14:59:44   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.30   Nov 13 2006 13:26:20   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.29   Jun 12 2006 15:13:20   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.28   Nov 25 2005 01:32:16   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.27   Nov 23 2005 16:11:18   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.26   Nov 11 2005 09:50:56   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.25   Jul 11 2005 08:52:32   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.24   Jul 05 2005 01:50:18   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.23   Jun 28 2005 01:46:24   tmielke
* v1.72 build 1250
* 
*    Rev 1.22   Jun 02 2005 01:30:26   tmielke
* v1.72 build 1207
* 
*    Rev 1.21   May 18 2005 13:47:10   tmielke
* v1.72 build 1200
* 
*    Rev 1.20   Mar 18 2005 16:11:58   tmielke
*  
* 
*    Rev 1.19   Mar 12 2005 07:08:30   tmielke
* v1.69
* 
*    Rev 1.18   Feb 22 2005 16:53:20   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.17   Nov 21 2004 01:29:14   tmielke
* v1.66 build 883
* 
*    Rev 1.16   Dec 04 2003 03:36:42   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.15   Nov 18 2003 09:39:42   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.14   Oct 03 2003 01:22:08   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.13   Sep 23 2003 01:48:02   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.12   Sep 12 2003 01:12:10   tmielke
*  
* 
*    Rev 1.11   Sep 11 2003 04:04:04   tmielke
*  
* 
*    Rev 1.10   Sep 04 2003 00:55:26   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.9   Aug 04 2003 00:34:58   tmielke
* v1.64
* 
*    Rev 1.8   Jun 09 2003 15:25:16   tmielke
* v1.63 final
* 
*    Rev 1.7   Mar 04 2003 01:13:42   tmielke
* pre release 20 - Actimax manufacturer
* 
*    Rev 1.6   Jan 27 2003 01:14:04   tmielke
* Polish language support
* 
*    Rev 1.5   Jan 15 2003 16:12:38   tmielke
* v1.63 pre 13
* 
*    Rev 1.4   Nov 20 2002 03:56:00   tmielke
* Dutch language support 
* 
*    Rev 1.3   Oct 12 2002 00:43:32   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer 
*   windows versions
* - fixed IRI recording
* 
*    Rev 1.2   Oct 11 2002 20:20:12   tmielke
* vor korrekturen aus backup verwirrung
* 
*    Rev 1.1   Oct 08 2002 05:01:16   tmielke
* PropSheetFrame eingebaut
* 
*    Rev 1.0   Oct 08 2002 02:26:10   tmielke
* initial check-in
* 
*/

#include "stdafx.h"
#include "resource.h"
#include "TelArPropSheetFrame.h"
#include <mmsystem.h>
#include "wavein\wavein.h"
#include "TelAr.h"
#include "email.h"
#include "crypt.h"
#include "EnterKeyDlg.h"
#include "PasswortDlg.h"
#include "SuchfilterDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTelArPropSheetFrame

IMPLEMENT_DYNCREATE(CTelArPropSheetFrame, CMiniFrameWnd)

CTelArPropSheetFrame::CTelArPropSheetFrame()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pModelessPropSheet = NULL;
}

CTelArPropSheetFrame::~CTelArPropSheetFrame()
{
	if (m_pModelessPropSheet) delete m_pModelessPropSheet;
}


BEGIN_MESSAGE_MAP(CTelArPropSheetFrame, CMiniFrameWnd)
	//{{AFX_MSG_MAP(CTelArPropSheetFrame)
	ON_WM_SYSCOMMAND()
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_ACTIVATE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTelArPropSheetFrame message handlers

int CTelArPropSheetFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	TRACE0("CTelArPropSheetFrame::OnCreate()\n");

	if (CMiniFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pModelessPropSheet = new CTelArPropertySheet(IDS_TITEL, this, 0);
	if (!m_pModelessPropSheet->Create(this, 
		WS_CHILD | WS_VISIBLE, 0))
	{
		delete m_pModelessPropSheet;
		m_pModelessPropSheet = NULL;
		return -1;
	}

	// Resize the mini frame so that it fits around the child property
	// sheet.
	CRect rectClient, rectWindow;
	m_pModelessPropSheet->GetWindowRect(rectClient);
	rectWindow = rectClient;

	// CMiniFrameWnd::CalcWindowRect adds the extra width and height
	// needed from the mini frame.
	CalcWindowRect(rectWindow);
	SetWindowPos(NULL, rectWindow.left, rectWindow.top,
		rectWindow.Width(), rectWindow.Height(),
		SWP_NOZORDER | SWP_NOACTIVATE);
	m_pModelessPropSheet->SetWindowPos(NULL, 0, 0,
		rectClient.Width(), rectClient.Height(),
		SWP_NOZORDER | SWP_NOACTIVATE);

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// Set the icon in the status area of the taskbar
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = STATUS_ICON_ID;
	nid.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP;
	nid.uCallbackMessage = MYWM_NOTIFYICON;
	nid.hIcon = m_hIcon;
	LANG2BUFFER(IDS_STRING26, nid.szTip); // "Telefonat Archiver öffnen mit Doppelklick"
	if (!Shell_NotifyIcon(NIM_ADD, &nid)) ShowLastError();

	return 0;
}

void CTelArPropSheetFrame::OnSetFocus(CWnd* pOldWnd) 
{
	CMiniFrameWnd::OnSetFocus(pOldWnd);
}

void CTelArPropSheetFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CMiniFrameWnd::OnActivate(nState, pWndOther, bMinimized);

	// Forward any WM_ACTIVATEs to the property sheet...
	// Like the dialog manager itself, it needs them to save/restore the focus.
	ASSERT_VALID(m_pModelessPropSheet);

	// Use GetCurrentMessage to get unmodified message data.
	const MSG* pMsg = GetCurrentMessage();
	ASSERT(pMsg->message == WM_ACTIVATE);
	m_pModelessPropSheet->SendMessage(pMsg->message, pMsg->wParam,
		pMsg->lParam);
}

BOOL CTelArPropSheetFrame::OnCommand(WPARAM wParam, LPARAM lParam) 
{
#if !defined(SCRLITE)

	switch (wParam)
	{
	case IDC_RETELLSCR_START_STOP_RECORDING:
		{
			if (X_modus == 0)
			{
				X_modus = 1; // manuell
				AfxMessageBox("SCR has been switched to manual recording mode for remote control. Please restart recording.", MB_ICONINFORMATION);
				m_pModelessPropSheet->m_Page1.Normalisieren();
				return TRUE;
			}
			m_pModelessPropSheet->m_Page1.OnAufnahme();

			// get global memory
			HGLOBAL hmem = GlobalAlloc(GMEM_SHARE, 30);
			char *cp = (char *)GlobalLock(hmem);
			sprintf(cp, "%d", m_pModelessPropSheet->m_Page1.nRecordingPeak);
			GlobalUnlock(cp);

			// put signal max to clipboard
			OpenClipboard();
			SetClipboardData(CF_TEXT, hmem);	
			CloseClipboard();
		}
		return TRUE;
	case IDC_RETELLSCR_SET_URN:
		{
			OpenClipboard();
			HGLOBAL hmem = GetClipboardData(CF_TEXT);
			if (hmem)
			{
				char *cp = (char *)GlobalLock(hmem);
				m_pModelessPropSheet->m_Page1.SetDlgItemText(IDC_GESPRAECHSPARTNER, cp);
				GlobalUnlock(hmem);
			}
			CloseClipboard();
		}
		return TRUE;
	case IDC_RETELLSCR_SET_NOTE:
		{
			OpenClipboard();
			HGLOBAL hmem = GetClipboardData(CF_TEXT);
			if (hmem)
			{
				char *cp = (char *)GlobalLock(hmem);
				m_pModelessPropSheet->m_Page1.SetDlgItemText(IDC_NOTIZEN, cp);
				GlobalUnlock(hmem);
			}
			CloseClipboard();
		}
		return TRUE;
	case IDC_RETELLSCR_CANCEL_RECORDING:
		m_pModelessPropSheet->m_Page1.OnAbbrechen();
		return TRUE;
	case IDC_RETELLSCR_SET_WINDOW_TITLE:
		{
			OpenClipboard();
			HGLOBAL hmem = GetClipboardData(CF_TEXT);
			if (hmem)
			{
				char *cp = (char *)GlobalLock(hmem);
				m_pModelessPropSheet->m_Page1.NotifyWindowTitle = cp;
				GlobalUnlock(hmem);
			}
			EmptyClipboard();
			CloseClipboard();
		}
		return TRUE;
	}
#endif

	return CTelArPropSheetFrame::OnCommand(wParam, lParam);
}

void CTelArPropSheetFrame::OnSysCommand(UINT nID, LPARAM lParam) 
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		char titel[100];
		VEND2BUFFER(IDS_STRING6, titel);
		strcat(titel, " ");
		LoadString(GetModuleHandle("TELAR.EXE"), IDS_TITEL, titel+strlen(titel), sizeof(titel));
		strcat(titel, " ");
		strcat(titel, version_string);	

		CAboutDlg dlgAbout(titel);
		dlgAbout.DoModal();
	}
	else if (nID == SC_CLOSE)
	{
		switch (m_pModelessPropSheet->GetActiveIndex())
		{
		case 0:
			m_pModelessPropSheet->m_Page1.OnKillActive();
			break;
		case 1:
			m_pModelessPropSheet->m_Page2.OnKillActive();
			break;
		case 2:
			m_pModelessPropSheet->m_Page3.OnKillActive();
			break;
		case 3:
#if !defined(SCRLITE)
			m_pModelessPropSheet->m_Page4.OnKillActive();
#endif
			break;
		case 4:
			m_pModelessPropSheet->m_Page5.OnKillActive();
			break;
		}

		if (m_pModelessPropSheet->m_Page2.suchfilter) 
			m_pModelessPropSheet->m_Page2.suchfilter->ShowWindow(SW_HIDE);
		ShowWindow(SW_HIDE);
		SaveReg();
	}
	else
	{
		CMiniFrameWnd::OnSysCommand(nID, lParam);
	}
}


// On_MYWM_NOTIFYICON - processes callback messages for taskbar icons  
// wParam - first message parameter of the callback message 
// lParam - second message parameter of the callback message 
void CTelArPropSheetFrame::On_MYWM_NOTIFYICON(WPARAM wParam, LPARAM lParam) 
{ 
    UINT uID; 
    UINT uMouseMsg; 
 
    uID = (UINT) wParam; 
    uMouseMsg = (UINT) lParam; 
 
    if (uID == STATUS_ICON_ID)
	{ 
        switch (uMouseMsg) 
		{ 
			case WM_MBUTTONDBLCLK:
				if (X_modus == 1)
					m_pModelessPropSheet->m_Page1.OnAufnahme();

				// hier gleich weitermachen:
 
            case WM_LBUTTONDBLCLK:
				//if (!IsWindowVisible()) 
				{
					BOOL bDoIt = TRUE;
					if (X_Locked)
					{
						int idd;

						if (!strcmp(C_language, "D"))
							idd = IDD_PASSWORT_APPLICATION_LOCKED;
						else if (!strcmp(C_language, "GB"))
							idd = IDD_GB_PASSWORT_APPLICATION_LOCKED;
						else if (!strcmp(C_language, "CZ"))
							idd = IDD_CZ_PASSWORT_APPLICATION_LOCKED;
						else if (!strcmp(C_language, "NL"))
							idd = IDD_NL_PASSWORT_APPLICATION_LOCKED;
						else if (!strcmp(C_language, "PL"))
							idd = IDD_PL_PASSWORT_APPLICATION_LOCKED;
						else
							idd = IDD_E_PASSWORT_APPLICATION_LOCKED;
						
						CPasswortDlg dlg(idd, (CString)"wonder", this);
						if (dlg.DoModal() != IDOK) bDoIt = FALSE;
						
					}

					if (bDoIt)
						SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);					
				}
                break; 

            default: 
                break; 
        } 
    } 
    return; 
} 
 

LRESULT CTelArPropSheetFrame::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == MYWM_NOTIFYICON)
	{
		On_MYWM_NOTIFYICON(wParam, lParam);
	}
	
	return CMiniFrameWnd::WindowProc(message, wParam, lParam);
}

void CTelArPropSheetFrame::OnTimer(UINT nIDEvent) 
{
	CMiniFrameWnd::OnTimer(nIDEvent);
}

void CTelArPropSheetFrame::OnDestroy() 
{
	CMiniFrameWnd::OnDestroy();
	
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = STATUS_ICON_ID;
	Shell_NotifyIcon(NIM_DELETE, &nid);		
}
