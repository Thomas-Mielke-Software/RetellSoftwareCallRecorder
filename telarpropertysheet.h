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
*	TelArPropertySheet.h : header file
*	
*	This class defines custom modal property sheet 
*	CTelArPropertySheet.
*	
*	$Log:   D:/pvcsarch/telar/telarpropertysheet.h_v  $
* 
*    Rev 1.76   Dec 19 2007 17:27:42   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.75   Oct 11 2007 10:15:16   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.74   Sep 21 2007 15:47:30   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.73   Aug 14 2007 14:09:20   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.72   May 09 2007 10:23:58   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.71   Nov 16 2006 14:59:58   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.70   Nov 13 2006 13:26:36   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.69   Jun 12 2006 15:13:32   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.68   Mar 17 2006 13:16:30   tmielke
* v1.77 build 1818
* 
*    Rev 1.67   Nov 25 2005 01:32:36   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.66   Nov 23 2005 16:11:36   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.65   Nov 11 2005 09:51:08   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.64   Jul 11 2005 08:52:54   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.63   Jul 05 2005 01:50:32   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.62   Jun 28 2005 01:46:38   tmielke
* v1.72 build 1250
* 
*    Rev 1.61   Jun 02 2005 01:30:38   tmielke
* v1.72 build 1207
* 
*    Rev 1.60   May 18 2005 13:47:20   tmielke
* v1.72 build 1200
* 
*    Rev 1.59   Mar 18 2005 16:12:12   tmielke
*  
* 
*    Rev 1.58   Mar 12 2005 07:08:48   tmielke
* v1.69
* 
*    Rev 1.57   Feb 22 2005 16:53:30   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.56   Nov 21 2004 01:29:24   tmielke
* v1.66 build 883
* 
*    Rev 1.55   Mar 28 2004 03:58:30   tmielke
* v1.66 bugfix Sekunden vergessen
* 
*    Rev 1.54   Dec 04 2003 03:36:54   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.53   Nov 18 2003 09:39:48   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.52   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.51   Sep 23 2003 01:48:12   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.50   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.49   Sep 11 2003 04:04:10   tmielke
*  
* 
*    Rev 1.48   Sep 04 2003 00:55:34   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.47   Aug 04 2003 00:35:08   tmielke
* v1.64
* 
*    Rev 1.46   Jun 09 2003 15:25:24   tmielke
* v1.63 final
* 
*    Rev 1.45   Apr 29 2003 21:48:52   tmielke
* WindowAnima eingebaut
* 
*    Rev 1.44   Jan 22 2003 16:50:34   tmielke
* MiniFrame ausgebaut
* 
*    Rev 1.43   Oct 12 2002 00:43:36   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer 
*   windows versions
* - fixed IRI recording
* 
*    Rev 1.42   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.41   May 29 2002 20:30:06   tmielke
* Tracys Änderungswünsche vom 22 Mai 2002 und 
* Übers. vom 20. Mai 2002 eingearbeitet
* 
*    Rev 1.40   May 05 2002 11:57:08   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.39   Mar 15 2002 20:23:00   tmielke
* v1.60
* 
*    Rev 1.38   Nov 07 2001 02:40:52   tmielke
* v1.59 bugfix release
* 
*    Rev 1.37   Nov 06 2001 05:28:14   tmielke
* v1.58a
* 
*    Rev 1.36   Oct 12 2001 16:24:14   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.35   Sep 14 2001 04:13:18   
* v1.57
* 
*    Rev 1.34   06 Jun 2001 02:02:04   tmielke
* offizielle release 1.55
* 
*    Rev 1.33   02 Jun 2001 17:02:40   tmielke
* lite version Prototyp
* 
*    Rev 1.32   02 Jun 2001 02:57:28   tmielke
* CODECs screen in lite Version ausgebaut
* 
*    Rev 1.31   17 May 2001 02:02:24   tmielke
* v1.54
* 
*    Rev 1.30   12 Feb 2001 19:37:56   tmielke
* v1.53
* 
*    Rev 1.29   20 Dec 2000 18:20:16   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.28   04 Dec 2000 02:24:28   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.27   19 Oct 2000 02:30:14   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.26   19 Jun 2000 15:55:08   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.25   24 Mar 2000 22:36:56   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.24   18 Mar 2000 11:40:56   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.23   17 Mar 2000 05:32:28   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.22   05 Mar 2000 05:21:38   tmielke
* v1.43
* 
*    Rev 1.21   28 Feb 2000 00:31:08   tmielke
* v1.42
* 
*    Rev 1.20   24 Feb 2000 15:28:28   tmielke
* v1.41
* 
*    Rev 1.19   24 Feb 2000 01:23:40   tmielke
* v1.39
* 
*    Rev 1.18   18 Feb 2000 00:39:24   tmielke
* v1.38
* 
*    Rev 1.17   15 Dec 1999 03:34:28   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.16   01 Dec 1999 18:45:46   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.15   27 Aug 1999 16:43:38   tmielke
* Lizenz-Management eingebaut
* 
*    Rev 1.14   16 Aug 1999 10:31:50   tmielke
* v1.34
* 
*    Rev 1.13   09 Aug 1999 07:51:08   tmielke
* Encryption eingebaut
* 
*    Rev 1.12   07 Jun 1999 18:37:02   tmielke
* Multi Language Version
* 
*    Rev 1.11   05 Apr 1999 09:39:36   tmielke
* Nachtrag v1.32
* 
*    Rev 1.10   05 Apr 1999 08:14:30   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
* 
*    Rev 1.9   22 Mar 1999 16:26:32   tmielke
* v1.31 Letzte-Aufnahme-Button und Logo
* 
*    Rev 1.8   21 Mar 1999 19:14:48   tmielke
* Info-Button + verbesserter Info-Screen in v1.30
* 
*    Rev 1.7   20 Mar 1999 18:52:36   tmielke
* v1.3
* 
*    Rev 1.6   18 Mar 1999 13:27:40   tmielke
* v0.8 - Demoversion fertig gemacht
* 
*    Rev 1.5   03 Mar 1999 13:40:26   tmielke
* Version Label v0.6
* 
*    Rev 1.4   03 Mar 1999 10:52:00   tmielke
* CPropertySheet bug workaround versucht.
* Einstellungen erweitert:
* Auto-Aufnahmetrigger Einstellungen in 'Einstellungen'
* Bugfixing.
* 
*    Rev 1.3   28 Feb 1999 07:08:02   tmielke
* Aufnahmepegel eingebaut.
* Monitor Modus eingebaut.
* 
*    Rev 1.2   28 Feb 1999 01:10:18   tmielke
* Dateiheader/keywords verschönert
* 
*    Rev 1.1   28 Feb 1999 01:07:32   tmielke
* keywords hinzugefügt
*
*/

#ifndef __TELARPROPERTYSHEET_H__
#define __TELARPROPERTYSHEET_H__

#include "ResizableSheet.h"
#include "TelArPropertyPage.h"
#include "callnot.h"

/////////////////////////////////////////////////////////////////////////////
// CTelArPropertySheet

class CTelArPropertySheet : public CResizableSheet
{
	DECLARE_DYNAMIC(CTelArPropertySheet)

// Construction
public:
	CTelArPropertySheet(UINT nIDCaption, CWnd *pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CTelArPropertyPage1 m_Page1;
	CTelArPropertyPage2 m_Page2;
	CTelArPropertyPage3 m_Page3;
	CTelArPropertyPage4 m_Page4;
	CTelArPropertyPage5 m_Page5;

// Operations
public:
	void On_MYWM_NOTIFYICON(WPARAM wParam, LPARAM lParam);
#ifdef TAPI
	HRESULT OnTapiEvent(ITBasicCallControl * gpCall, TAPI_EVENT TapiEvent, IDispatch * pEvent);
#endif

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTelArPropertySheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTelArPropertySheet();

	void NormalizeWindow();

	HICON m_hIcon;

// Generated message map functions
protected:
	//{{AFX_MSG(CTelArPropertySheet)
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg(char *titel);

	char *m_titel;
	int  n_lauftext;

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnHomepage();
	afx_msg void OnEmail();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnConfirm();
	virtual void OnOK();
	afx_msg void OnUpdate();
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#define MYWM_NOTIFYICON		(WM_APP+100)
#define STATUS_ICON_ID		1

#endif	// __TELARPROPERTYSHEET_H__

