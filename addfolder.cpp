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
*	AddFolder.cpp : implementation file
*	
*	$Log:   D:/pvcsarch/telar/addfolder.cpv  $
* 
*    Rev 1.47   Dec 19 2007 17:27:30   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.46   Oct 11 2007 10:15:02   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.45   Sep 21 2007 15:47:18   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.44   Aug 14 2007 14:09:08   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.43   May 09 2007 10:23:44   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.42   Dec 13 2006 13:38:24   tmielke
* No refund possible text added
* 
*    Rev 1.41   Nov 16 2006 14:59:46   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.40   Nov 13 2006 13:26:22   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.39   Jun 12 2006 15:13:22   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.38   Nov 25 2005 01:32:18   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.37   Nov 23 2005 16:11:20   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.36   Nov 11 2005 09:50:58   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.35   Nov 03 2005 00:25:16   tmielke
* added suggestions according to #491
* 
*    Rev 1.34   Jul 11 2005 08:52:34   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.33   Jul 05 2005 01:50:18   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.32   Jun 28 2005 01:46:26   tmielke
* v1.72 build 1250
* 
*    Rev 1.31   Jun 02 2005 01:30:26   tmielke
* v1.72 build 1207
* 
*    Rev 1.30   May 18 2005 13:47:10   tmielke
* v1.72 build 1200
* 
*    Rev 1.29   Apr 10 2005 17:59:56   tmielke
* New folder select dialog.
* 
*    Rev 1.28   Mar 18 2005 16:12:00   tmielke
*  
* 
*    Rev 1.27   Mar 12 2005 07:08:32   tmielke
* v1.69
* 
*    Rev 1.26   Feb 22 2005 16:53:20   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.25   Nov 21 2004 01:29:14   tmielke
* v1.66 build 883
* 
*    Rev 1.24   Dec 04 2003 03:36:42   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.23   Nov 18 2003 09:39:42   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.22   Oct 03 2003 01:22:08   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.21   Sep 23 2003 01:48:04   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.20   Sep 12 2003 01:12:10   tmielke
*  
* 
*    Rev 1.19   Sep 11 2003 04:04:04   tmielke
*  
* 
*    Rev 1.18   Sep 04 2003 00:55:26   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.17   Aug 04 2003 00:34:58   tmielke
* v1.64
* 
*    Rev 1.16   Jun 09 2003 15:25:16   tmielke
* v1.63 final
* 
*    Rev 1.15   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.14   May 05 2002 11:56:14   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.13   Mar 15 2002 20:21:50   tmielke
* v1.60
* 
*    Rev 1.12   Nov 07 2001 02:08:12   tmielke
* v1.59 bugfix release
* 
*    Rev 1.11   Nov 06 2001 05:26:48   tmielke
* v1.58a
* 
*    Rev 1.10   Oct 12 2001 16:22:40   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.9   Sep 14 2001 04:12:28   
* v1.57
* 
*    Rev 1.8   06 Jun 2001 02:00:04   tmielke
* offizielle release 1.55
* 
*    Rev 1.7   17 May 2001 02:01:04   tmielke
* v1.54
* 
*    Rev 1.6   12 Feb 2001 19:36:44   tmielke
* v1.53
* 
*    Rev 1.5   20 Dec 2000 18:18:14   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.4   04 Dec 2000 02:22:48   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.3   19 Oct 2000 02:28:36   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.2   22 Jun 2000 04:18:08   tmielke
* In Ordner kopieren/bewegen eingebaut.
* Add, Del, Edit Ordner implementiert.
* 
*    Rev 1.1   21 Jun 2000 05:35:52   tmielke
* Drag-and-drop basics eingebaut
*
*
*/

#include "stdafx.h"
#include "telar.h"
#include "AddFolder.h"

//#include "shlobj.h" -- better use shfolder.dll !!!
#include <shlobj.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddFolder dialog


CAddFolder::CAddFolder(int idd, CWnd* pParent /*=NULL*/)
	: CDialog(idd, pParent)
{
	//{{AFX_DATA_INIT(CAddFolder)
	m_name = _T("");
	m_pfad = _T("");
	//}}AFX_DATA_INIT

	m_bModifyFolderTitle = FALSE;
}


void CAddFolder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddFolder)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_PFAD, m_pfad);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddFolder, CDialog)
	//{{AFX_MSG_MAP(CAddFolder)
	ON_BN_CLICKED(IDC_SET_PATH, OnSetPath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddFolder message handlers

void CAddFolder::OnSetPath() 
{
	DF("CAddFolder::OnSetPath()");

	CString csPathBuffer;	 
	char TitleBuffer[200];

	GetDlgItemText(IDC_PFAD, csPathBuffer);
	LANG2BUFFER(IDS_STRING51, TitleBuffer);
	CXFolderDialog dlg(csPathBuffer);
	dlg.SetOsVersion(CXFolderDialog::XFILEDIALOG_AUTO_DETECT_OS_VERSION);
	dlg.SetTitle(TitleBuffer);
	if (dlg.DoModal() == IDOK)
	{
    	csPathBuffer = dlg.GetPath();
		DF1("CAddFolder->CXFolderDialog.DoModal() returned == IDOK; dlg.GetPath() is '%s'", csPathBuffer.GetBuffer(0));

		if (csPathBuffer.GetLength() && csPathBuffer[csPathBuffer.GetLength()-1] == '\\')
			csPathBuffer = csPathBuffer.Left(csPathBuffer.GetLength()-1);
		SetDlgItemText(IDC_PFAD, csPathBuffer);
	}
	DF("CAddFolder->CXFolderDialog.DoModal() returned != IDOK");
}

BOOL CAddFolder::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (!m_name.IsEmpty()) GetDlgItem(IDC_NAME)->EnableWindow(FALSE);


	if (m_bModifyFolderTitle) LANG_SETWINDOWTEXT(IDS_STRING192)
	
	return TRUE;
}
