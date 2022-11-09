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
*	SuchfilterDlg.cpp : implementation file
*	
*	$Log:   D:/pvcsarch/telar/suchfilterdlg.cpv  $
* 
*    Rev 1.58   Dec 19 2007 17:27:40   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.57   Oct 11 2007 10:15:14   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.56   Sep 21 2007 15:47:28   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.55   Aug 14 2007 14:09:18   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.54   May 09 2007 10:23:56   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.53   Nov 16 2006 14:59:56   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.52   Nov 13 2006 13:26:34   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.51   Jun 12 2006 15:13:30   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.50   Nov 25 2005 01:32:32   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.49   Nov 23 2005 16:11:34   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.48   Nov 11 2005 09:51:06   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.47   Jul 11 2005 08:52:50   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.46   Jul 05 2005 01:50:30   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.45   Jun 28 2005 01:46:36   tmielke
* v1.72 build 1250
* 
*    Rev 1.44   Jun 02 2005 01:30:36   tmielke
* v1.72 build 1207
* 
*    Rev 1.43   May 18 2005 13:47:18   tmielke
* v1.72 build 1200
* 
*    Rev 1.42   Mar 18 2005 16:12:08   tmielke
*  
* 
*    Rev 1.41   Mar 12 2005 07:08:44   tmielke
* v1.69
* 
*    Rev 1.40   Feb 22 2005 16:53:28   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.39   Nov 21 2004 01:29:22   tmielke
* v1.66 build 883
* 
*    Rev 1.38   Dec 04 2003 03:36:52   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.37   Nov 18 2003 09:39:48   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.36   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.35   Sep 23 2003 01:48:10   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.34   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.33   Sep 11 2003 04:04:08   tmielke
*  
* 
*    Rev 1.32   Sep 04 2003 00:55:32   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.31   Aug 04 2003 00:35:06   tmielke
* v1.64
* 
*    Rev 1.30   Jul 21 2003 00:02:30   tmielke
* 1.) Changed Title to "PhoneCoach CompuCorder" (therby crossing all the clean code for composing vendor, lite/demo/pro, and for version number)
* 2.) Rearranged the ad text on page 1 (deleted ", with its manual recording")
* 3.) Never was aware of "It was agreed that the default identification would be PC", but ok, added more individual code, making program code more ugly... 
* 4.) I changed the tab of the system tray icon to "Double-click middle mouse button for manual recording, double-click left button to just open the SCR"
* 5.) I now have hidden the "confirm license" key for all lite versions, including the PhoneCoach 'CompuCorder'.
* 
* Further changes:
* - I changed default control background color and logos so there is no loner a slight difference which created a frame
* - I noticed that on PC withot hardware accelerated graphic cards the building of info and filter window was too slow, I increased the speed drastically, so the impression now is rather subconcious
* 
* 
*    Rev 1.29   Jun 09 2003 15:25:22   tmielke
* v1.63 final
* 
*    Rev 1.28   Apr 29 2003 21:48:50   tmielke
* WindowAnima eingebaut
* 
*    Rev 1.27   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.26   May 05 2002 11:56:54   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.25   Apr 25 2002 06:43:06   tmielke
* zusätzliche Suchfilterfunktionen
* 
*    Rev 1.24   Mar 28 2002 13:07:44   tmielke
* Search by date, search window now docks on the left side.
* 
*    Rev 1.23   Mar 15 2002 20:22:34   tmielke
* v1.60
* 
*    Rev 1.22   Nov 07 2001 02:40:34   tmielke
* v1.59 bugfix release
* 
*    Rev 1.21   Nov 06 2001 05:27:54   tmielke
* v1.58a
* 
*    Rev 1.20   Oct 12 2001 16:23:48   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.19   Sep 14 2001 04:13:06   
* v1.57
* 
*    Rev 1.18   06 Jun 2001 02:01:36   tmielke
* offizielle release 1.55
* 
*    Rev 1.17   17 May 2001 02:02:06   tmielke
* v1.54
* 
*    Rev 1.16   12 Feb 2001 19:37:40   tmielke
* v1.53
* 
*    Rev 1.15   20 Dec 2000 18:19:52   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.14   04 Dec 2000 02:24:10   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.13   19 Oct 2000 02:29:58   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.12   19 Jun 2000 15:54:50   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.11   24 Mar 2000 22:36:44   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.10   18 Mar 2000 11:40:44   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.9   17 Mar 2000 05:32:16   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.8   05 Mar 2000 05:21:22   tmielke
* v1.43
* 
*    Rev 1.7   28 Feb 2000 00:30:56   tmielke
* v1.42
* 
*    Rev 1.6   24 Feb 2000 15:28:14   tmielke
* v1.41
* 
*    Rev 1.5   24 Feb 2000 01:23:26   tmielke
* v1.39
* 
*    Rev 1.4   18 Feb 2000 00:39:10   tmielke
* v1.38
* 
*    Rev 1.3   15 Dec 1999 03:34:04   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.2   01 Dec 1999 18:45:36   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.1   16 Aug 1999 10:31:44   tmielke
* v1.34
* 
*    Rev 1.0   14 Aug 1999 08:51:00   tmielke
* Suchfunktion eingebaut
* 
*    Rev 1.2   14 Aug 1999 01:55:50   tmielke
* Log-Keyword eingebaut
* 
*/

#include "stdafx.h"
#include "TelAr.h"
#include "SuchfilterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSuchfilterDlg dialog


CSuchfilterDlg::CSuchfilterDlg(int Template, CTelArPropertyPage2* pParent)
	: CDialog(Template, pParent)
{
	//{{AFX_DATA_INIT(CSuchfilterDlg)
	m_Gespraechspartner = _T("");
	m_Identifikation = _T("");
	m_Notizen = _T("");
	m_DatumVon = _T("");
	m_DatumBis = _T("");
	m_MaxDauer = _T("");
	m_MinDauer = _T("");
	m_ZeitVon = _T("");
	m_ZeitBis = _T("");
	//}}AFX_DATA_INIT

	m_pParent = pParent;
}


void CSuchfilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSuchfilterDlg)
	DDX_Text(pDX, IDC_GESPRAECHSPARTNER, m_Gespraechspartner);
	DDX_Text(pDX, IDC_IDENTIFIKATION, m_Identifikation);
	DDV_MaxChars(pDX, m_Identifikation, 2);
	DDX_Text(pDX, IDC_NOTIZEN, m_Notizen);
	DDX_Text(pDX, IDC_DATUM_NACH, m_DatumVon);
	DDV_MaxChars(pDX, m_DatumVon, 10);
	DDX_Text(pDX, IDC_DATUM_VOR, m_DatumBis);
	DDV_MaxChars(pDX, m_DatumBis, 10);
	DDX_Text(pDX, IDC_MAX_DAUER, m_MaxDauer);
	DDV_MaxChars(pDX, m_MaxDauer, 5);
	DDX_Text(pDX, IDC_MIN_DAUER, m_MinDauer);
	DDV_MaxChars(pDX, m_MinDauer, 5);
	DDX_Text(pDX, IDC_ZEIT_NACH, m_ZeitVon);
	DDV_MaxChars(pDX, m_ZeitVon, 5);
	DDX_Text(pDX, IDC_ZEIT_VOR, m_ZeitBis);
	DDV_MaxChars(pDX, m_ZeitBis, 5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSuchfilterDlg, CDialog)
	//{{AFX_MSG_MAP(CSuchfilterDlg)
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_IDENTIFIKATION, OnChangeIdentifikation)
	ON_EN_CHANGE(IDC_GESPRAECHSPARTNER, OnChangeGespraechspartner)
	ON_EN_CHANGE(IDC_NOTIZEN, OnChangeNotizen)
	ON_EN_CHANGE(IDC_DATUM_NACH, OnChangeDatumNach)
	ON_EN_CHANGE(IDC_DATUM_VOR, OnChangeDatumVor)
	ON_EN_CHANGE(IDC_ZEIT_NACH, OnChangeZeitNach)
	ON_EN_CHANGE(IDC_ZEIT_VOR, OnChangeZeitVor)
	ON_EN_CHANGE(IDC_MAX_DAUER, OnChangeMaxDauer)
	ON_EN_CHANGE(IDC_MIN_DAUER, OnChangeMinDauer)
	//}}AFX_MSG_MAP
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuchfilterDlg message handlers

BOOL CSuchfilterDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Fenster sinnvoll anordnen
	CRect r_main, r;
	AfxGetMainWnd()->GetWindowRect(&r_main);
	GetWindowRect(&r);
	int nLeft = r_main.left-r.Width();
	if (nLeft < 0) nLeft = 0;
	SetWindowPos(NULL, nLeft, r.top, 0, 0, SWP_NOZORDER|SWP_NOSIZE);	

	// Feldinhalte setzen
	m_Gespraechspartner = X_SuchfilterGespraechspartner;
	m_Identifikation = X_SuchfilterIdentifikation;
	m_Notizen = X_SuchfilterNotizen;
	m_DatumVon = X_SuchfilterDatumVon;
	m_DatumBis = X_SuchfilterDatumBis;
	m_ZeitVon = X_SuchfilterZeitVon;
	m_ZeitBis = X_SuchfilterZeitBis;
	m_MinDauer = X_SuchfilterMinDauer;
	m_MaxDauer = X_SuchfilterMaxDauer;
	UpdateData(FALSE);

	// Feldbezeichnungen setzen
	LANG_SETWINDOWTEXT(IDS_STRING122)
	LANG_SETCTRLTEXT(IDS_STRING123, IDC_STATIC_SUCHE_NACH_FRAME)
	LANG_SETCTRLTEXT(IDS_STRING124, IDC_STATIC_IDENTIFIKATION)
	LANG_SETCTRLTEXT(IDS_STRING125, IDC_STATIC_GESPRAECHSPARTNER)
	LANG_SETCTRLTEXT(IDS_STRING126, IDC_STATIC_NOTIZEN)
	LANG_SETCTRLTEXT(IDS_STRING127, IDC_STATIC_DATUM)
	LANG_SETCTRLTEXT(IDS_STRING128, IDC_STATIC_ZEIT1)
	LANG_SETCTRLTEXT(IDS_STRING128, IDC_STATIC_ZEIT2)
	LANG_SETCTRLTEXT(IDS_STRING129, IDC_STATIC_DATUM_NACH)
	LANG_SETCTRLTEXT(IDS_STRING130, IDC_STATIC_DATUM_VOR)
	LANG_SETCTRLTEXT(IDS_STRING131, IDC_STATIC_MIN_DAUER)
	LANG_SETCTRLTEXT(IDS_STRING132, IDC_STATIC_MAX_DAUER)
	LANG_SETCTRLTEXT(IDS_STRING172, IDOK)
	LANG_SETCTRLTEXT(IDS_STRING133, IDCANCEL)

	return TRUE;
}

void CSuchfilterDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	GetData();
}

void CSuchfilterDlg::GetData()
{
	UpdateData(TRUE);
	strcpy(X_SuchfilterGespraechspartner, (LPCSTR)m_Gespraechspartner);
	strcpy(X_SuchfilterIdentifikation, (LPCSTR)m_Identifikation);
	strcpy(X_SuchfilterNotizen, (LPCSTR)m_Notizen);
	strcpy(X_SuchfilterDatumVon, (LPCSTR)m_DatumVon);
	strcpy(X_SuchfilterDatumBis, (LPCSTR)m_DatumBis);
	strcpy(X_SuchfilterZeitVon, (LPCSTR)m_ZeitVon);
	strcpy(X_SuchfilterZeitBis, (LPCSTR)m_ZeitBis);
	strcpy(X_SuchfilterMinDauer, (LPCSTR)m_MinDauer);
	strcpy(X_SuchfilterMaxDauer, (LPCSTR)m_MaxDauer);
}

void CSuchfilterDlg::OnOK() 
{
	GetData();
	m_pParent->RefreshListe();
}

void CSuchfilterDlg::OnCancel() 
{
	ShowWindow(SW_HIDE);
	m_pParent->RefreshListe();
}

void CSuchfilterDlg::OnChangeIdentifikation() 
{
}

void CSuchfilterDlg::OnChangeGespraechspartner() 
{
}

void CSuchfilterDlg::OnChangeNotizen() 
{
}

void CSuchfilterDlg::OnChangeDatumNach() 
{
	AddSeparator(IDC_STATIC_DATUM, IDC_DATUM_NACH);
/*
	CString cs;
	GetDlgItemText(IDC_DATUM_NACH, cs);
	if (cs.GetLength() == 10 || !cs.GetLength())
	{
		GetData();
		m_pParent->RefreshListe();
	}
*/
}

void CSuchfilterDlg::OnChangeDatumVor() 
{
	AddSeparator(IDC_STATIC_DATUM, IDC_DATUM_VOR);
/*
	CString cs;
	GetDlgItemText(IDC_DATUM_VOR, cs);
	if (cs.GetLength() == 10 || !cs.GetLength())
	{
		GetData();
		m_pParent->RefreshListe();
	}
*/
}

void CSuchfilterDlg::OnChangeZeitNach() 
{
	AddSeparator(IDC_STATIC_ZEIT1, IDC_ZEIT_NACH);
/*
	CString cs;
	GetDlgItemText(IDC_ZEIT_NACH, cs);
	if (cs.GetLength() == 5 || !cs.GetLength())
	{
		GetData();
		m_pParent->RefreshListe();
	}
*/
}

void CSuchfilterDlg::OnChangeZeitVor() 
{
	AddSeparator(IDC_STATIC_ZEIT1, IDC_ZEIT_VOR);
/*
	CString cs;
	GetDlgItemText(IDC_ZEIT_VOR, cs);
	if (cs.GetLength() == 5 || !cs.GetLength())
	{
		GetData();
		m_pParent->RefreshListe();
	}
*/
}

void CSuchfilterDlg::OnChangeMaxDauer() 
{
	AddSeparator(IDC_STATIC_ZEIT2, IDC_MAX_DAUER);
/*
	CString cs;
	GetDlgItemText(IDC_MAX_DAUER, cs);
	if (cs.GetLength() == 5 || !cs.GetLength())
	{
		GetData();
		m_pParent->RefreshListe();
	}
*/
}

void CSuchfilterDlg::OnChangeMinDauer() 
{
	AddSeparator(IDC_STATIC_ZEIT2, IDC_MIN_DAUER);
/*
	CString cs;
	GetDlgItemText(IDC_MIN_DAUER, cs);
	if (cs.GetLength() == 5 || !cs.GetLength())
	{
		GetData();
		m_pParent->RefreshListe();
	}
*/
}

void CSuchfilterDlg::AddSeparator(int nIDStatic, int nIDText)
{
	CString csText, csStatic, csOut;
	int nStartChar, nEndChar;

	GetDlgItemText(nIDStatic, csStatic);	
	GetDlgItemText(nIDText, csText);	
	((CEdit *)GetDlgItem(nIDText))->GetSel(nStartChar, nEndChar);

	// Bedingungen:
	if (nStartChar == nEndChar)	// keine Selektion
	{
		if (csText.GetLength() < (int)((CEdit *)GetDlgItem(nIDText))->GetLimitText())	// noch Platz im Feld
		{
			if ((nStartChar < csStatic.GetLength())	// entspricht noch der Schablone?
				&& (csStatic[nStartChar] == '.' || csStatic[nStartChar] == '/' || csStatic[nStartChar] == ':'))	// Pos. entspricht Trenner in der Schablone
			{
				if (nStartChar == csText.GetLength() || isdigit(csText[nStartChar])) // am Ende oder Zeichen davor eine Ziffer
				{
					csOut = csStatic[nStartChar];
					((CEdit *)GetDlgItem(nIDText))->ReplaceSel(csOut);
				}
			}
		}
	}

}

void CSuchfilterDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	if (bShow)	// in case dialog entries were changed but search button wasn't hit: restore previous data
	{
		UpdateData(FALSE);
	}
}
