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
*	TelArPropertyPage.h : header file
*	
*	$Log:   D:/pvcsarch/telar/telarpropertypage.h_v  $
* 
*    Rev 1.109   Dec 19 2007 17:27:42   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.108   Oct 11 2007 10:15:16   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.107   Sep 21 2007 15:47:30   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.106   Aug 14 2007 14:09:20   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.105   May 09 2007 10:23:58   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.104   Nov 16 2006 14:59:58   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.103   Nov 13 2006 13:26:36   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.102   Jun 12 2006 15:13:32   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.101   May 31 2006 10:23:48   tmielke
* Speaker volume slider
* 
*    Rev 1.100   Mar 17 2006 13:16:30   tmielke
* v1.77 build 1818
* 
*    Rev 1.99   Nov 25 2005 01:32:34   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.98   Nov 23 2005 16:11:36   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.97   Nov 11 2005 09:51:08   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.96   Oct 19 2005 12:22:28   tmielke
* solved problems when accessing file-based index files.
* 
*    Rev 1.95   Jul 11 2005 08:52:54   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.94   Jul 05 2005 01:50:32   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.93   Jun 28 2005 01:46:38   tmielke
* v1.72 build 1250
* 
*    Rev 1.92   Jun 02 2005 01:30:38   tmielke
* v1.72 build 1207
* 
*    Rev 1.91   May 18 2005 13:47:20   tmielke
* v1.72 build 1200
* 
*    Rev 1.90   Mar 18 2005 16:12:12   tmielke
*  
* 
*    Rev 1.89   Mar 12 2005 07:08:48   tmielke
* v1.69
* 
*    Rev 1.88   Feb 22 2005 16:53:30   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.87   Nov 21 2004 01:29:24   tmielke
* v1.66 build 883
* 
*    Rev 1.86   Sep 22 2004 05:20:40   tmielke
* v1.66 build 869 
* improved db-index file creation & cleaned up moving files
* 
*    Rev 1.85   Dec 04 2003 03:36:52   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.84   Nov 06 2003 05:18:32   tmielke
* MDB-index Zwischenversion
* 
*    Rev 1.83   Oct 21 2003 03:42:22   tmielke
* started database index file
* 
*    Rev 1.82   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.81   Sep 23 2003 01:48:12   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.80   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.79   Sep 11 2003 04:04:10   tmielke
*  
* 
*    Rev 1.78   Sep 04 2003 00:55:34   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.77   Aug 04 2003 00:35:08   tmielke
* v1.64
* 
*    Rev 1.76   Aug 04 2003 00:34:26   tmielke
* optional ALC, corrected spelling, and setup script modification
* 
*    Rev 1.75   Jun 09 2003 15:25:24   tmielke
* v1.63 final
* 
*    Rev 1.74   May 19 2003 14:30:28   tmielke
* 1.63pre32 - reverse MIXER order problem fixed
* 
*    Rev 1.73   Apr 29 2003 05:37:22   tmielke
* pre30 - data link 'change filename' function
* 
*    Rev 1.72   Apr 07 2003 09:53:22   tmielke
* pre release 28 - speeded up delete and move recordings
* 
*    Rev 1.71   Mar 25 2003 23:06:06   tmielke
* log file system revised
* 
*    Rev 1.70   Dec 31 2002 04:39:56   tmielke
* auf dem Win98 Rechner gemachte Änderungen
* 
*    Rev 1.69   Dec 18 2002 23:41:38   tmielke
* added Record Indicator and current recording time elapsed on Record tab
* 
*    Rev 1.68   Nov 28 2002 03:38:44   tmielke
* parameters on Options tab greyed out if IRI active
* 
*    Rev 1.67   Nov 02 2002 20:59:40   tmielke
* - Timer ID1 verändert
* - Debug Informationen in Datei
* 
*    Rev 1.66   Oct 28 2002 18:37:30   tmielke
* 1.63 pre 5:
*     - fixed level control slider by changing to the mixer architecture
*     - fitted mixer interface to cope with different soundcard designs
* 
* 
*    Rev 1.65   Oct 25 2002 15:52:20   tmielke
*     - improved userfriendlyness when switching IRI on and off
*     - IRI detection with countdown now
* 
*    Rev 1.64   Oct 08 2002 05:01:20   tmielke
* PropSheetFrame eingebaut
* 
*    Rev 1.63   Sep 24 2002 15:16:26   tmielke
* Total vermurxt alles... :(
* 
*    Rev 1.62   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.61   May 05 2002 11:57:06   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.60   Apr 02 2002 15:01:36   tmielke
* kleinere Änderungen: Suchfenster schließt jetzt mit dem Hauptfenster zusammen, Schließen-Knopf-Text verändert
* 
*    Rev 1.59   Mar 15 2002 20:22:58   tmielke
* v1.60
* 
*    Rev 1.58   Nov 07 2001 02:40:50   tmielke
* v1.59 bugfix release
* 
*    Rev 1.57   Nov 06 2001 05:28:12   tmielke
* v1.58a
* 
*    Rev 1.56   Oct 12 2001 16:24:12   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.55   Sep 14 2001 04:13:16   
* v1.57
* 
*    Rev 1.54   06 Jun 2001 02:02:02   tmielke
* offizielle release 1.55
* 
*    Rev 1.53   02 Jun 2001 02:57:26   tmielke
* CODECs screen in lite Version ausgebaut
* 
*    Rev 1.52   17 May 2001 02:02:22   tmielke
* v1.54
* 
*    Rev 1.51   12 Feb 2001 19:37:54   tmielke
* v1.53
* 
*    Rev 1.50   20 Dec 2000 18:20:12   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.49   04 Dec 2000 02:24:26   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.48   19 Oct 2000 02:30:12   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.47   30 Jul 2000 03:22:44   tmielke
* allg. Einstellungen auch redesigned
* 
*    Rev 1.46   30 Jul 2000 02:22:46   tmielke
* Hardware- und CODEC pages redesigned
* 
*    Rev 1.45   29 Jul 2000 03:56:10   tmielke
* Aufnahme-Screen redesign fertig
* 
*    Rev 1.44   23 Jul 2000 19:18:08   tmielke
* zwischendurch
* 
*    Rev 1.43   23 Jul 2000 17:02:34   tmielke
* Zwischendurch: OwnerDraw Prototyp
* 
*    Rev 1.42   21 Jul 2000 09:17:56   tmielke
* Wiedergabe-Screen fertig redesigned
* 
*    Rev 1.41   22 Jun 2000 04:18:38   tmielke
* In Ordner kopieren/bewegen eingebaut.
* Add, Del, Edit Ordner implementiert.
* 
*    Rev 1.40   21 Jun 2000 05:36:26   tmielke
* Drag-and-drop basics eingebaut
* 
*    Rev 1.39   19 Jun 2000 23:18:12   tmielke
* Ordner eingebaut, drag-and-drop fehlt noch.
* 
*    Rev 1.38   19 Jun 2000 15:55:04   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.37   05 Jun 2000 05:26:00   tmielke
* DEBUGFILE logging für Prop2
* 
*    Rev 1.36   24 Mar 2000 22:36:56   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.35   18 Mar 2000 11:40:56   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.34   17 Mar 2000 05:32:28   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.33   05 Mar 2000 05:21:36   tmielke
* v1.43
* 
*    Rev 1.32   05 Mar 2000 01:23:00   tmielke
* safety check-in
* 
*    Rev 1.31   04 Mar 2000 21:38:02   tmielke
* vendor dll eingebaut
* 
*    Rev 1.30   28 Feb 2000 00:31:08   tmielke
* v1.42
* 
*    Rev 1.29   24 Feb 2000 15:28:28   tmielke
* v1.41
* 
*    Rev 1.28   24 Feb 2000 01:23:38   tmielke
* v1.39
* 
*    Rev 1.27   18 Feb 2000 08:21:30   tmielke
* Tageswerk 17.02.00
* 
*    Rev 1.26   18 Feb 2000 00:39:22   tmielke
* v1.38
* 
*    Rev 1.25   15 Dec 1999 03:34:24   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.24   01 Dec 1999 18:45:46   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.23   25 Aug 1999 05:57:44   tmielke
* EC, DC und Zufallsgenerator in crypt.h ausgelagert
* 
*    Rev 1.22   16 Aug 1999 10:31:50   tmielke
* v1.34
* 
*    Rev 1.21   16 Aug 1999 10:20:40   tmielke
* Exportfunktion eingebaut
* 
*    Rev 1.20   14 Aug 1999 08:51:04   tmielke
* Suchfunktion eingebaut
* 
*    Rev 1.19   14 Aug 1999 06:49:44   tmielke
* Passwortschutz verfeinert
* 
*    Rev 1.18   14 Aug 1999 04:26:38   tmielke
* Bitmap Buttons für Wiedergabe-Screen
* 
*    Rev 1.17   09 Aug 1999 07:51:08   tmielke
* Encryption eingebaut
* 
*    Rev 1.16   07 Jun 1999 18:37:02   tmielke
* Multi Language Version
* 
*    Rev 1.15   05 Apr 1999 09:39:36   tmielke
* Nachtrag v1.32
* 
*    Rev 1.14   05 Apr 1999 08:14:30   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
* 
*    Rev 1.13   22 Mar 1999 16:26:30   tmielke
* v1.31 Letzte-Aufnahme-Button und Logo
* 
*    Rev 1.12   21 Mar 1999 19:14:48   tmielke
* Info-Button + verbesserter Info-Screen in v1.30
* 
*    Rev 1.11   20 Mar 1999 18:52:36   tmielke
* v1.3
* 
*    Rev 1.10   18 Mar 1999 13:27:40   tmielke
* v0.8 - Demoversion fertig gemacht
* 
*    Rev 1.9   03 Mar 1999 13:40:26   tmielke
* Version Label v0.6
* 
*    Rev 1.8   03 Mar 1999 13:39:32   tmielke
* mysteriösen CODEC-Deselect bug beseitigt.
* SaveReg() bei WM_CLOSE über KillActive sichergestellt.
* Kleinigkeiten.
* 
*    Rev 1.7   03 Mar 1999 10:52:00   tmielke
* CPropertySheet bug workaround versucht.
* Einstellungen erweitert:
* Auto-Aufnahmetrigger Einstellungen in 'Einstellungen'
* Bugfixing.
* 
*    Rev 1.7   02 Mar 1999 09:59:42   tmielke
* Wav-Player eingebaut.
* GetProgramVersion eingebaut.
* 
*    Rev 1.6   01 Mar 1999 12:47:06   tmielke
* Indexdatei eingebaut, Gesprächspartner & Notizen, Gesprächslänge...
* 
*    Rev 1.5   28 Feb 1999 11:33:20   tmielke
* Kleinigkeiten
* 
*    Rev 1.4   28 Feb 1999 09:20:04   tmielke
* Leitungspegel-Automatik eingebaut.
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

#ifndef __TELARPROPERTYPAGE_H__
#define __TELARPROPERTYPAGE_H__

#include "ResizablePage.h"
#include "TMTabelle.h"
#include "IndexDB.h"
#include "afxole.h"
#include "DDList.h"
#include "OwnerDrawButton.h"
#include "ArchiveWizzard.h"
#include "QuickList.h"
#ifdef TAPI
#include <Tapi3.h>
#endif

class CTelArPropertySheet;
class CTelArPropSheetFrame;

/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage1 dialog

class CTelArPropertyPage2;
class CTelArPropertyPage3;

class CTelArPropertyPage1 : public CResizablePage
{
	DECLARE_DYNCREATE(CTelArPropertyPage1)

friend CTelArPropertySheet;
friend CTelArPropSheetFrame;

// Construction
public:
	CTelArPropertyPage1();
	~CTelArPropertyPage1();

// Dialog Data
	//{{AFX_DATA(CTelArPropertyPage1)
	enum { IDD = IDD_PROPPAGE1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTelArPropertyPage1)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
// Implementation
	// Generated message map functions
	//{{AFX_MSG(CTelArPropertyPage1)
	afx_msg void OnAufnahme();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnAbbrechen();
	afx_msg void OnBeenden();
	afx_msg void OnChangeGespraechspartner();
	afx_msg void OnChangeNotizen();
	afx_msg void OnInfo();
	afx_msg void OnLetzteAufnahme();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnPaint();
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	DECLARE_MESSAGE_MAP()

public:
	// Owner Draw Buttons
	COwnerDrawButton odbAufnahme;
	COwnerDrawButton odbInfo;
	COwnerDrawButton odbLetzteAufnahme;
	COwnerDrawButton odbAbbrechen;
	COwnerDrawButton odbBeenden;
	COwnerDrawButton odbMute;

	CIndexDB default_index;
	
	void Normalisieren();

#ifdef TAPI
	void TAPIUpdateCallID(ITBasicCallControl * gpCall);
	void TAPIConnected(ITBasicCallControl * gpCall);
	void TAPIDisconnected(ITBasicCallControl * gpCall);
#endif

protected:
	void AufnahmedatensatzSchreiben();
	BOOL Record(BOOL);
	void SetVolume(int volume);

	int n_silence;
	int n_noise;
	TMZeile *aufnahme_datensatz;
	CString m_SCRCTRL_filename;
	CString m_SCRCTRL_get_last_filename;
	CTime m_aufnahmestartzeit;
	CString m_ArchivPfadMerker;
	CTelArPropertyPage2 *m_pTelArPropertyPage2;
	CTelArPropertyPage3 *m_pTelArPropertyPage3;
	int nRecordingPeak;
	CString NotifyWindowTitle;
	BOOL m_bControlToneWarningDisplayed;
	int m_nControlToneWarningCounter;
	BOOL m_bRecordingLedBlinkState;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedMute();
};


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage2 dialog

#define FOLDERS_FILENAME "TelAr_Folders.dat"
#define FOLDERS_FILEMAGIC "TelArFolders"
#define FOLDERS_FILECOLUMNS 2
#define FOLDERS_FILEVERSION 1

#define IDXTYPE_FILE	0
#define IDXTYPE_ACCESS	1
#define IDXTYPE_SENSE	2

class CSuchfilterDlg;

class CTelArPropertyPage2 : public CResizablePage
{
	DECLARE_DYNCREATE(CTelArPropertyPage2)

friend CTelArPropertyPage1;
friend CSuchfilterDlg;
friend CListeDDListbox;
friend COrdnerDDListbox;
friend CDDListBox;
friend COleListBoxDropTarget;

// Construction
public:
	void OnWizard();
	CTelArPropertyPage2();
	~CTelArPropertyPage2();

// Dialog Data
	//{{AFX_DATA(CTelArPropertyPage2)
	enum { IDD = IDD_PROPPAGE2 };
	CQuickList		m_ListeLB;
	CListCtrl		m_OrdnerLB;
	//}}AFX_DATA

    CRect           m_DragSourceRect;   // drag/drop source rectangle
                                        // maintained so that we don't
                                        // allow a drag/drop source to 
                                        // drop on itself 
	CSuchfilterDlg *suchfilter;
	CArchiveWizzard *archivewizzard;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTelArPropertyPage2)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTelArPropertyPage2)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListe();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnRew();
	afx_msg void OnFf();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFf2();
	afx_msg void OnRew2();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDestroy();
	afx_msg void OnSuchen();
	afx_msg void OnExport();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	afx_msg void OnAddOrdner();
	afx_msg void OnDelOrdner();
	afx_msg void OnEditOrdner();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct);
	afx_msg void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct);
	afx_msg void OnArchive();
	afx_msg LRESULT OnGetListItem(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDeleteitemListe(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBegindragListe(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnItemchangedOrdner(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeleditListe(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBeginlabeleditListe(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	DECLARE_MESSAGE_MAP()

public:
	void RefreshOrdner();
	void RefreshListe();
	void OnSelchange(CWnd *child);
	void SetDragCursor(POINT dragpos);
	int  KopiereListeneintrag(CListCtrl *Source, int nSourceLBItem, CListCtrl *Dest, int nDestLBItem);
	void LoescheListeneintraege(CListCtrl *lb, int *pLBItem, int n);
	void DoDeleteEintrag(TMZeile *zeile);
	int  EinsortierenNachDatum(CTime *date, int begin, int end);
	BOOL MyMciSendString(LPCSTR cmd, char *ret, int retsize, HWND hWnd);
	TMZeile *SafeGetItemData(int n);
	void ResetItemData(int size);
	void SetItemData(int item, TMZeile *p);
	TMZeile *GetItemData(int item);
	void DeleteItemData(int item);

	int nLastSelection;
	BOOL bPlaying;
	BOOL bSeeking;
	long position;
	CString csKillTheFile;		// temporäres file - löschen z.B. wenn das programm verlassen wird
	CString csOrdner;			// Name der gerade geöffneten Ordners

	TMTabelle *pFolders;
	CIndexDB liste_index;
	int m_CurrentIndexType;		// IDXTYPE_FILE v IDXTYPE_ACCESS
	long m_CurrentIndexPosition;
	CIndexDB dest_index;		// for copy operations, see KopiereListeneintrag
	TMZeile **myItemData;		// for caching list elements
	int myItemDataSize;			// size of the cache 

	// CQuickList Listbox
	CImageList m_imgList;
	//CImageList m_imgLargeList;
	CImageList* m_DragImage;	

	// for drag&drop
	CListCtrl*  m_pDragList;		//Which ListCtrl we are dragging FROM
	CListCtrl*  m_pDropList;		//Which List we are dropping ON
	CImageList* m_pDragImage;	//For creating and managing the drag-image
	BOOL		m_bDragging;	//T during a drag operation
	int			m_nDragIndex;	//Index of selected item in the List we are dragging FROM
	int			m_nDropIndex;	//Index at which to drop item in the List we are dropping ON
	CWnd*		m_pDropWnd;		//Pointer to window we are dropping on (will be cast to CListCtrl* type)
	BOOL		m_bCopyDropeffect;	// TRUE=copy, FALSE=move

protected:
	// Button-Bitmaps
	CBitmap AddOrdnerBmp;
	CBitmap DelOrdnerBmp;
	CBitmap EditOrdnerBmp;
	CBitmap ArchiveOrdnerBmp;
	CBitmap Rew2Bmp;
	CBitmap RewBmp;
	CBitmap PlayBmp;
	CBitmap PauseBmp;
	CBitmap StopBmp;
	CBitmap FfBmp;
	CBitmap Ff2Bmp;
	CBitmap SuchenBmp;
	CBitmap ExportBmp;
	CBitmap EditBmp;
	CBitmap DeleteBmp;

	char m_szMyTitle[100];
public:
	afx_msg void OnNMDblclkListe(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage3 dialog

class CTelArPropertyPage3 : public CResizablePage
{
	DECLARE_DYNCREATE(CTelArPropertyPage3)

friend CTelArPropertySheet;
friend CTelArPropertyPage1;

// Construction
public:
	CTelArPropertyPage3();
	~CTelArPropertyPage3();

// Dialog Data
	//{{AFX_DATA(CTelArPropertyPage3)
	enum { IDD = IDD_PROPPAGE3 };
	int		m_radio;
	int		m_intelligent_radio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTelArPropertyPage3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTelArPropertyPage3)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeDevice();
	afx_msg void OnSelchangeSamplingrate();
	afx_msg void OnSelchangeAnschluss();
	afx_msg void OnRadio();
	afx_msg void OnAnschlussVistaMute();
	afx_msg void OnPaint();
	afx_msg void OnIntelligentActive();
	afx_msg void OnIntelligentInactive();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	DECLARE_MESSAGE_MAP()

	void ShowDevices();
	void ShowAux();
	void GetData();

	CTelArPropertyPage1 *m_pTelArPropertyPage1;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage4 dialog

class CTelArPropertyPage4 : public CResizablePage
{
	DECLARE_DYNCREATE(CTelArPropertyPage4)

// Construction
public:
	CTelArPropertyPage4();
	~CTelArPropertyPage4();

// Dialog Data
	//{{AFX_DATA(CTelArPropertyPage4)
	enum { IDD = IDD_PROPPAGE4 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

	BOOL m_InitDlg;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTelArPropertyPage4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTelArPropertyPage4)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeListe();
	afx_msg void OnSelchangeListeFormat();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	DECLARE_MESSAGE_MAP()

	void ShowCodecs();
	void ClearFormatLB();
	void GetData();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage5 dialog

class CTelArPropertyPage5 : public CResizablePage
{
	DECLARE_DYNCREATE(CTelArPropertyPage5)

// Construction
public:
	CTelArPropertyPage5();
	~CTelArPropertyPage5();

// Dialog Data
	//{{AFX_DATA(CTelArPropertyPage5)
	enum { IDD = IDD_PROPPAGE5 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTelArPropertyPage5)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_pw_merken;
	CString m_master_pw_merken;

	void EnableVoxOptions(BOOL bEnable);

	// Generated message map functions
	//{{AFX_MSG(CTelArPropertyPage5)
	virtual BOOL OnInitDialog();
	afx_msg void OnSetRootPath();
	afx_msg void OnPaint();
	afx_msg void OnSetMainarchive();
	afx_msg void OnAutostart();
	afx_msg void OnConnectToSqlServer();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangePasswort();
	//}}AFX_MSG
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnConnectToSense();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
};
 
#endif // __TELARPROPERTYPAGE_H__
