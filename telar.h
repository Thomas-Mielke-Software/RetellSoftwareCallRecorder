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
*	TelAr.h : main header file for the TELAR application
*
*	put SCRLITE in Project settings -> C/C++ Preprocessor symbols to build LITE version
*
*	$Log:   D:/pvcsarch/telar/telar.h_v  $
* 
*    Rev 1.98   Dec 19 2007 17:27:40   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.97   Oct 11 2007 10:15:14   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.96   Sep 21 2007 15:47:28   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.95   Aug 14 2007 14:09:18   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.94   May 09 2007 10:23:56   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.93   Nov 16 2006 14:59:56   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.92   Nov 13 2006 13:26:34   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.91   Nov 12 2006 17:16:50   tmielke
* v1.79 build 2095 -- messed up version: auto-recording broken
* 
*    Rev 1.90   Jun 12 2006 15:13:30   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.89   Mar 17 2006 13:16:28   tmielke
* v1.77 build 1818
* 
*    Rev 1.88   Nov 25 2005 01:32:34   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.87   Nov 23 2005 16:11:34   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.86   Nov 11 2005 09:51:06   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.85   Jul 11 2005 08:52:52   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.84   Jul 05 2005 01:50:30   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.83   Jun 28 2005 01:46:36   tmielke
* v1.72 build 1250
* 
*    Rev 1.82   Jun 02 2005 01:30:38   tmielke
* v1.72 build 1207
* 
*    Rev 1.81   May 18 2005 13:47:18   tmielke
* v1.72 build 1200
* 
*    Rev 1.80   Apr 10 2005 17:59:58   tmielke
* New folder select dialog.
* 
*    Rev 1.79   Mar 18 2005 16:12:10   tmielke
*  
* 
*    Rev 1.78   Mar 12 2005 07:08:44   tmielke
* v1.69
* 
*    Rev 1.77   Feb 22 2005 16:53:28   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.76   Nov 21 2004 01:29:22   tmielke
* v1.66 build 883
* 
*    Rev 1.75   Jun 01 2004 05:07:22   tmielke
* v1.66 build 846
* improved stability
* 
*    Rev 1.74   Dec 04 2003 03:36:52   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.73   Nov 18 2003 09:39:48   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.72   Oct 21 2003 03:42:20   tmielke
* started database index file
* 
*    Rev 1.71   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.70   Sep 23 2003 01:48:10   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.69   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.68   Sep 11 2003 04:04:08   tmielke
*  
* 
*    Rev 1.67   Sep 11 2003 04:03:42   tmielke
* This version should fix the NT40 problems (waveinAddBuffer deadlock).
* I also removed the animated window code for opening info and search screens.
*
*    Rev 1.66   Sep 04 2003 00:55:32   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
*
*    Rev 1.65   Aug 20 2003 01:03:06   tmielke
* nomixer failsafe setting
*
*    Rev 1.64   Aug 04 2003 00:35:08   tmielke
* v1.64
*
*    Rev 1.63   Aug 04 2003 00:34:26   tmielke
* optional ALC, corrected spelling, and setup script modification
*
*    Rev 1.62   Jun 09 2003 15:25:22   tmielke
* v1.63 final
*
*    Rev 1.61   May 13 2003 06:47:14   tmielke
* - trying to estimate proper input line after changing the device
* - added much brain to the automatic detection of the input line for the IRI
*
*
*    Rev 1.60   Apr 30 2003 01:02:30   tmielke
* DSAMessageBox eingebaut
*
*    Rev 1.59   Apr 29 2003 05:37:22   tmielke
* pre30 - data link 'change filename' function
*
*    Rev 1.58   Mar 27 2003 05:26:56   tmielke
* Data Link DLL speeded up
* recording delay fix
*
*    Rev 1.57   Mar 25 2003 23:06:06   tmielke
* log file system revised
*
*    Rev 1.56   Nov 02 2002 20:59:38   tmielke
* - Timer ID1 verändert
* - Debug Informationen in Datei
*
*    Rev 1.55   Oct 12 2002 00:43:34   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer
*   windows versions
* - fixed IRI recording
*
*    Rev 1.54   Oct 08 2002 05:01:18   tmielke
* PropSheetFrame eingebaut
*
*    Rev 1.53   Sep 24 2002 15:16:26   tmielke
* Total vermurxt alles... :(
*
*    Rev 1.52   Jun 05 2002 19:31:58   tmielke
* v1.62
*
*    Rev 1.51   May 05 2002 11:56:56   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
*
*    Rev 1.50   Apr 25 2002 06:43:08   tmielke
* zusätzliche Suchfilterfunktionen
*
*    Rev 1.49   Mar 28 2002 13:07:46   tmielke
* Search by date, search window now docks on the left side.
*
*    Rev 1.48   Mar 15 2002 20:22:38   tmielke
* v1.60
*
*    Rev 1.47   Jan 28 2002 16:20:26   tmielke
* License Confirmation
*
*    Rev 1.46   May 26 2002 19:50:50   tmielke
* License confirmation in SCR eingebaut.
*
*    Rev 1.45   Nov 07 2001 02:40:38   tmielke
* v1.59 bugfix release
*
*    Rev 1.44   Nov 06 2001 05:27:58   tmielke
* v1.58a
*
*    Rev 1.43   Oct 12 2001 16:23:52   tmielke
* v1.58 bugfix wav export
*
*    Rev 1.42   Sep 14 2001 04:13:08
* v1.57
*
*    Rev 1.41   06 Jun 2001 02:01:40   tmielke
* offizielle release 1.55
*
*    Rev 1.40   17 May 2001 02:02:08   tmielke
* v1.54
*
*    Rev 1.39   12 Feb 2001 19:37:42   tmielke
* v1.53
*
*    Rev 1.38   12 Feb 2001 19:35:48   tmielke
* disregard recordings less than X seconds
* neues exit-symbol für deakt.-button
*
*    Rev 1.37   20 Dec 2000 18:19:56   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
*
*    Rev 1.36   04 Dec 2000 02:24:12   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
*
*    Rev 1.35   19 Oct 2000 02:30:00   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
*
*
*    Rev 1.34   18 Oct 2000 17:14:40   tmielke
* Sicherheits-Checkin vor Auto-Level-Control
*
*    Rev 1.33   29 Jul 2000 03:56:00   tmielke
* Aufnahme-Screen redesign fertig
*
*    Rev 1.32   19 Jun 2000 23:18:02   tmielke
* Ordner eingebaut, drag-and-drop fehlt noch.
*
*    Rev 1.31   19 Jun 2000 15:54:52   tmielke
* v1.44 letzte TRS-Version
*
*    Rev 1.30   24 Mar 2000 22:36:46   tmielke
* v1.44 encrypting im hintergrund
*
*    Rev 1.29   18 Mar 2000 11:40:46   tmielke
* zur sicherheit eingecheckt
*
*    Rev 1.28   17 Mar 2000 05:32:18   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
*
*    Rev 1.27   05 Mar 2000 05:21:26   tmielke
* v1.43
*
*    Rev 1.26   04 Mar 2000 21:37:54   tmielke
* vendor dll eingebaut
*
*    Rev 1.25   28 Feb 2000 00:30:58   tmielke
* v1.42
*
*    Rev 1.24   24 Feb 2000 15:28:18   tmielke
* v1.41
*
*    Rev 1.23   24 Feb 2000 01:23:28   tmielke
* v1.39
*
*    Rev 1.22   18 Feb 2000 00:39:12   tmielke
* v1.38
*
*    Rev 1.21   15 Dec 1999 03:34:10   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
*
*    Rev 1.20   01 Dec 1999 18:45:38   tmielke
* v1.36 BPS -> Frohberg GmbH
*
*    Rev 1.19   27 Aug 1999 16:43:34   tmielke
* Lizenz-Management eingebaut
*
*    Rev 1.18   16 Aug 1999 10:31:46   tmielke
* v1.34
*
*    Rev 1.17   14 Aug 1999 08:51:00   tmielke
* Suchfunktion eingebaut
*
*    Rev 1.16   14 Aug 1999 06:49:40   tmielke
* Passwortschutz verfeinert
*
*    Rev 1.15   09 Aug 1999 07:51:04   tmielke
* Encryption eingebaut
*
*    Rev 1.14   07 Jun 1999 18:37:00   tmielke
* Multi Language Version
*
*    Rev 1.13   05 Apr 1999 09:39:34   tmielke
* Nachtrag v1.32
*
*    Rev 1.12   05 Apr 1999 08:14:28   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
*
*    Rev 1.11   22 Mar 1999 16:26:30   tmielke
* v1.31 Letzte-Aufnahme-Button und Logo
*
*    Rev 1.10   20 Mar 1999 18:52:34   tmielke
* v1.3
*
*    Rev 1.9   18 Mar 1999 13:27:36   tmielke
* v0.8 - Demoversion fertig gemacht
*
*    Rev 1.8   03 Mar 1999 13:40:24   tmielke
* Version Label v0.6
*
*    Rev 1.7   03 Mar 1999 10:52:00   tmielke
* CPropertySheet bug workaround versucht.
* Einstellungen erweitert:
* Auto-Aufnahmetrigger Einstellungen in 'Einstellungen'
* Bugfixing.
*
*    Rev 1.8   02 Mar 1999 11:34:22   tmielke
* GetProgramVersion steht.
*
*    Rev 1.7   02 Mar 1999 09:59:40   tmielke
* Wav-Player eingebaut.
* GetProgramVersion eingebaut.
*
*    Rev 1.6   01 Mar 1999 12:47:04   tmielke
* Indexdatei eingebaut, Gesprächspartner & Notizen, Gesprächslänge...
*
*    Rev 1.5   28 Feb 1999 11:33:20   tmielke
* Kleinigkeiten
*
*    Rev 1.4   28 Feb 1999 09:20:02   tmielke
* Leitungspegel-Automatik eingebaut.
*
*    Rev 1.3   28 Feb 1999 07:08:02   tmielke
* Aufnahmepegel eingebaut.
* Monitor Modus eingebaut.
*
*    Rev 1.2   28 Feb 1999 01:10:16   tmielke
* Dateiheader/keywords verschönert
*
*    Rev 1.1   28 Feb 1999 01:07:30   tmielke
* keywords hinzugefügt
*
*/

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

// Sense support only for WIN32
#if !defined(_WIN64)
	#define SENSE 
#endif

#include "resource.h"					// main symbols
#include "TelArLangDeutsch\resource.h"	// sprachspezifische symbole für string table
#include "TelArPropertySheet.h"
#include "TMTabelle.h"
#include "IndexDB.h"
#include "DSAMessageBox.h"
#include "XFolderDialog.h"
#include "MyTapi.h"

extern "C"
{
#include "ivrlla.h"
}

/////////////////////////////////////////////////////////////////////////////
// CTelArApp:
// See TelAr.cpp for the implementation of this class
//

class CTelArApp : public CWinApp
{
public:
	void OnProperties();
	CTelArApp();
	CTelArPropertySheet *ppropSheet;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTelArApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	BOOL  m_bHiColorIcons;

	HINSTANCE hLanguageDLL;
	HINSTANCE hVendorDLL;

	CFile *pLockingFile;	// used to determine the instance that 'wins' when mutiple Autostart 'RUN' Keys are set

#ifdef DEBUGFILE
	//Debugging
	CFile *pDebugFile;
	void DebugFile(char *s);
#endif

	void LoadStringConstants();
	BOOL GetIniFileName(char *buffer3, int size);
	BOOL GetIniFileNameOld(char *buffer3, int size);
	BOOL GetFoldersFileName(char *filename, int size);
	BOOL GetFoldersFileNameOld(char *filename, int size);

#ifdef TAPI
	CMyTapi m_Tapi;
#endif

	afx_msg void OnAppAbout();

	//{{AFX_MSG(CTelArApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	CTelArPropSheetFrame* m_pPropFrame;
};

extern CTelArApp theApp;

/////////////////////////////////////////////////////////////////////////////

// einige eXterne Variablen:
extern char  X_path[1000];
extern char  X_local_path[1000];
extern char  X_local_path_subfolder[1000];
extern char  X_connect_string[1000];
extern char  X_main_archive_path[1000];
extern int   X_aufnahmegeraet;
extern int   X_samplingrate;
extern int   X_kanaele;	// nicht benutzt
extern int   X_aufloesung;
extern char  X_codec[1000];
extern DWORD_PTR X_codec_id;
extern DWORD_PTR X_format;
extern DWORD_PTR X_format_wfx;
extern int   X_anschluss;
extern DWORD X_volume;
extern int   X_modus;
extern int   X_intelligent;
extern int   X_ControlToneChannel;
extern char  X_initialen[3];
extern char  X_passwort[1000];
extern char  X_master_passwort[1000];
extern int   X_passes;
extern int   X_vergroessern_bei_pegel;
extern BOOL  X_minimize_after;
extern int   X_schwellwert;
extern int   X_toggle_noise;
extern int   X_toggle_silence;
extern time_t X_installationsdatum;
extern char  X_SuchfilterGespraechspartner[1000];
extern char  X_SuchfilterIdentifikation[3];
extern char  X_SuchfilterNotizen[1000];
extern char  X_SuchfilterDatumVon[20];
extern char  X_SuchfilterDatumBis[20];
extern char  X_SuchfilterZeitVon[20];
extern char  X_SuchfilterZeitBis[20];
extern char  X_SuchfilterMinDauer[20];
extern char  X_SuchfilterMaxDauer[20];
extern char  X_LicenseKey[200];
extern char  X_NPLK[50];
extern BOOL  X_Locked;
extern BOOL  X_NPLKTrial;
extern BOOL  X_NPLKTrialExpired;
extern int   X_Nichtbeachtung;
extern int   X_AutomatischLoeschen;
extern int   X_alc;
extern int   X_nomixer;
extern int   X_nomixer;
extern char  X_ConfigData[200];
extern char  X_rqk[200];
extern int   X_nosave2profile;
extern char  X_windowpos[100];
extern char  X_sense_caller[200];
extern char  X_sense_called[200];
extern char  X_sense_extension[200];

//___ pseudo X_ setings
extern BOOL  X_MessageShownOnce;
extern BOOL  X_InitialSelection;
extern char  X_aufnahmegeraetname[1000];
extern char  X_ClientLicenseKey[200];
extern BOOL  X_RecordingDisabled;

//___ global variable (sorry!) ___
extern char  G_CurrentPath[1000];

extern OSVERSIONINFOEX osvi;
extern BOOL bOsVersionInfoEx;	// true if info has been retreived
#define VISTA_RUNNING (bOsVersionInfoEx && osvi.dwMajorVersion >= 6)
extern HINSTANCE hSCRVistaHelper;
extern char C_CommonAppDataPath[1000];

extern char C_language[50];
extern char C_vendor[50];
extern char C_letzte_aufnahme[50];
extern char C_standard_ordner[50];

extern char C_manuelle_aufnahme[50];
extern char C_automatik_start[50];
extern char C_aufnahme_beenden[50];
extern char C_automatik_stop[50];

extern char C_abbrechen[50];
extern char C_mute_microphone[50];
extern char C_open_microphone[50];

#define MANUELLE_AUFNAHME	0
#define AUTOMATIK_START		1
#define AUFNAHME_BEENDEN	2
#define AUTOMATIK_STOP		3

#define MUTE_MICROPHONE    0
#define OPEN_MICROPHONE    1

extern char version_string[];
extern char build_string[];

extern TMTabelle theTabelle;
// Spalten-IDs für die Tabelle
#define SPID_DATEINAME 0
#define SPID_INITIALEN 1
#define SPID_GESPRAECHSPARTNER 2
#define SPID_NOTIZEN 3
#define SPID_DATUM 4
#define SPID_ZEIT 5
#define SPID_CODEC 6
#define SPID_FORMAT 7
#define SPID_MODUS 8
#define SPID_DAUER 9
#define SPID_GESCHUETZT 10


// und Funktionen:
extern void ReadReg();
extern void SaveReg();

#define MYWM_NOTIFYICON		(WM_APP+100)
#define STATUS_ICON_ID		1

// see wavein.h: #define MYWM_REALLOCATE_WAVEIN_BUFFER		(WM_APP+123)

#define INDEX_FILENAME "TelAr_Index.dat"
#define INDEX_FILEMAGIC "TelArIdx"
#define INDEX_FILECOLUMNS 11
#define INDEX_FILEVERSION 3

// language support:
#define LANG2BUFFER(IDS,BUFFER) LoadString(GetModuleHandle("TELARLNG.DLL"), IDS, BUFFER, sizeof(BUFFER))
#define LANG_MESSAGEBOX1(IDS) {char langmbbuf[3000]; LoadString(GetModuleHandle("TELARLNG.DLL"), IDS, langmbbuf, sizeof(langmbbuf)); AfxMessageBox(langmbbuf);}
#define LANG_MESSAGEBOX2(IDS, MBTYPE) {char langmbbuf[3000]; LoadString(GetModuleHandle("TELARLNG.DLL"), IDS, langmbbuf, sizeof(langmbbuf)); AfxMessageBox(langmbbuf, MBTYPE);}
#define LANG_SETWINDOWTEXT(IDS) {char langctrlbuf[3000]; LoadString(GetModuleHandle("TELARLNG.DLL"), IDS, langctrlbuf, sizeof(langctrlbuf)); SetWindowText(langctrlbuf);}
#define LANG_SETCTRLTEXT(IDS, IDC) {char langctrlbuf[3000]; LoadString(GetModuleHandle("TELARLNG.DLL"), IDS, langctrlbuf, sizeof(langctrlbuf)); SetDlgItemText(IDC, langctrlbuf);}

// vendor support:
#define VEND2BUFFER(IDS,BUFFER) LoadString(GetModuleHandle("TELARVND.DLL"), IDS, BUFFER, sizeof(BUFFER))
#define VEND_MESSAGEBOX1(IDS) {char langmbbuf[3000]; LoadString(GetModuleHandle("TELARVND.DLL"), IDS, langmbbuf, sizeof(langmbbuf)); AfxMessageBox(langmbbuf);}
#define VEND_MESSAGEBOX2(IDS, MBTYPE) {char langmbbuf[3000]; LoadString(GetModuleHandle("TELARVND.DLL"), IDS, langmbbuf, sizeof(langmbbuf)); AfxMessageBox(langmbbuf, MBTYPE);}
#define VEND_SETWINDOWTEXT(IDS) {char langctrlbuf[3000]; LoadString(GetModuleHandle("TELARVND.DLL"), IDS, langctrlbuf, sizeof(langctrlbuf)); SetWindowText(langctrlbuf);}
#define VEND_SETCTRLTEXT(IDS, IDC) {char langctrlbuf[3000]; LoadString(GetModuleHandle("TELARVND.DLL"), IDS, langctrlbuf, sizeof(langctrlbuf)); SetDlgItemText(IDC, langctrlbuf);}

#define IDC_RETELLSCR_START_STOP_RECORDING	10000
#define IDC_RETELLSCR_SET_URN				10001
#define IDC_RETELLSCR_SET_NOTE				10002
#define IDC_RETELLSCR_CANCEL_RECORDING		10003
#define IDC_RETELLSCR_SET_WINDOW_TITLE		10004
#define IDC_RETELLSCR_SET_FILENAME			10005
#define IDC_RETELLSCR_GET_STATUS			10006
#define IDC_RETELLSCR_GET_LAST_FILENAME		10007
#define IDC_RETELLSCR_NORMALIZE_WINDOW		10008
#define IDC_RETELLSCR_MUTE_RECORDING		10009
#define IDC_RETELLSCR_UNMUTE_RECORDING		10010

#if defined(DEBUGFILE)
#define DFTICK(str) { if (theApp.pDebugFile) theApp.pDebugFile->Write(str, (UINT)strlen(str)); }
#define DF(str) { theApp.DebugFile(str); }
#define DF1(str, p1) { CString cs; cs.Format(str, p1); theApp.DebugFile(cs.GetBuffer(0)); }
#define DF2(str, p1, p2) { CString cs; cs.Format(str, p1, p2); theApp.DebugFile(cs.GetBuffer(0)); }
#define DF3(str, p1, p2, p3) { CString cs; cs.Format(str, p1, p2, p3); theApp.DebugFile(cs.GetBuffer(0)); }
#define DF4(str, p1, p2, p3, p4) { CString cs; cs.Format(str, p1, p2, p3, p4); theApp.DebugFile(cs.GetBuffer(0)); }
#else
#define DFTICK(str) ;
#define DF(str) ;
#define DF1(str, p1) ;
#define DF2(str, p1, p2) ;
#define DF3(str, p1, p2, p3) ;
#define DF4(str, p1, p2, p3, p4) ;
#endif

//--- global helper ---

// returns TRUE if conversion was successful
extern BOOL String2CTime(CString &date, CString &time, CTime &ct);
extern void ShowLastError(char *operation);
extern long SetKey(HKEY hklm, HKEY hkcu, char *valuename, char *data);
extern long QueryKey(HKEY hklm, HKEY hkcu, char *valuename, char *data, long datasize);
extern void DrawBackgroundBitmap(CDC* pDC, int ResourceBitmapID, RECT *r, BOOL bStretch);
extern void DrawAndCenterBitmap(CDC* pDC, int ResourceBitmapID, RECT *r);
extern long Reconnect2SenseServer(char *buffer);	// buffer contaions the 'url' to the sense server
extern BOOL SenseError(char *function, DWORD dw);	// in Telar.cpp
extern BOOL IsOldStyleIndexFile(char *pathfile);		// in TelarPropPage2

//--- Sense Errors
#define IVRERR_SUCCESS				0x00000000 // OK
#define IVRERR_UNKNOWN_ERROR		0x0D100001 // An error occured but its reason is unknown
#define IVRERR_INVALID_CALLID		0x0D100002 // The callid does not exist.
#define IVRERR_INVALID_NUMBER		0x0D100003 // The phone number is illeagal.
#define IVRERR_BUSY					0x0D100004 // 
#define IVRERR_TIMEOUT				0x0D100005 // The request has timed out.
#define IVRERR_BUFFER_OVERFLOW		0x0D100006 
#define IVRERR_FILE_NAME			0x0D100007 // Invalid file name
#define IVRERR_FILE_ACCESS			0x0D100008 // File open/create/close failed.
#define IVRERR_FILE_IO				0x0D100009 // File read/write error.
#define IVRERR_CS_LOST				0x0D10000A // The CS stopped communicating with the PC.
#define IVRERR_EXCEPTION			0x0D10000B // An exception of unknown type occured.
#define IVRERR_LAYER1				0x0D10000C // ISDN Layer 1 is down.
#define IVRERR_LAYER2				0x0D10000D // ISDN Layer 2 is down.
#define IVRERR_CONNECT_FAILED		0x0D10000E  // Connection to IVRLLA server failed.
#define IVRERR_LOW_DISK_SPACE		0x0D10000F  // Disk space is too low.
#define IVRERR_BAD_FORMAT			0x0D100010  // Bad format.
#define IVRERR_NO_BANDWIDTH			0x0D100011  // Not enough bandwidth.
#define IVRERR_CS_FATAL				0x0D100012  // The CS encountered a non recoverable error.
#define IVRERR_FILE_PERMANENTLY_DELETED 0x0D100013 // File intentionally deleted by the system. 
#define IVRERR_INVALID_NAME			0x0D100014 // The requested object name was not found.
#define IVRERR_BACKUP_DISK_FULL		0x0D100015 // Back up Disk is full.
#define IVRERR_NOT_SUPPORTED_OPERATION 0x0D100016 // IVR don't support the required operation.
#define IVRERR_INVALID_PARAMETER	0x0D100017 // Invalid parameter sent to API.
#define IVRERR_INVALID_OPERATION	0x0D100018 // Invalid operation, out of sync operation.
#define IVRERR_ACTIVE				0x0C100001 // Code's meaning depends on requests's context:
		 //  Play: Audio already playing for this connection.
		 //  StartRecordSegment: Segment already recording for this connection.
#define IVRERR_INACTIVE				0x0C100002 // Stop: Audio already inactive for this connection.
#define IVRERR_PROGRESSING			0x0C100003 // Cconnection is in Alerting or Progressing state
#define IVRERR_CONNECTED			0x0C100004 // Connection is in Connected state
#define IVRERR_DISCONNECTED			0x0C100005 // Connection is in Disconnected state
#define IVRERR_NON_INTERCEPTABLE	0x0C100006 // This call may not be intercepted or played audio.
#define IVRERR_NO_ACCEPT_OUTGOING	0x0C100007 // Outgoing calls can not be accepted by IVRLLA ecause they are accepted by Vps according to local interception rules.
