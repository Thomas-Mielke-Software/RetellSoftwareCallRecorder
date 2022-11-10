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
*	TelArPropertySheet.cpp : implementation file
*	
*	$Log:   D:/pvcsarch/telar/telarpropertysheet.cpv  $
* 
*    Rev 1.125   Dec 19 2007 17:27:42   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.124   Oct 11 2007 10:15:16   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.123   Sep 21 2007 15:47:30   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.122   Aug 14 2007 14:09:20   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.121   May 09 2007 10:23:58   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.120   Nov 16 2006 14:59:58   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.119   Nov 13 2006 13:26:36   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.118   Nov 12 2006 17:16:50   tmielke
* v1.79 build 2095 -- messed up version: auto-recording broken
* 
*    Rev 1.117   Jun 12 2006 15:13:32   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.116   Jun 12 2006 13:56:28   tmielke
* zur Sicherheit Check-In vor Word-Wrap Notes box
* 
*    Rev 1.115   Mar 17 2006 13:16:30   tmielke
* v1.77 build 1818
* 
*    Rev 1.114   Nov 25 2005 01:32:34   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.113   Nov 23 2005 16:11:36   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.112   Nov 11 2005 09:51:08   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.111   Oct 19 2005 12:22:28   tmielke
* solved problems when accessing file-based index files.
* 
*    Rev 1.110   Jul 11 2005 08:52:54   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.109   Jul 05 2005 01:50:32   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.108   Jun 28 2005 01:46:38   tmielke
* v1.72 build 1250
* 
*    Rev 1.107   Jun 02 2005 01:30:38   tmielke
* v1.72 build 1207
* 
*    Rev 1.106   May 18 2005 13:47:20   tmielke
* v1.72 build 1200
* 
*    Rev 1.105   Mar 18 2005 16:12:12   tmielke
*  
* 
*    Rev 1.104   Mar 12 2005 07:08:48   tmielke
* v1.69
* 
*    Rev 1.103   Feb 22 2005 16:53:30   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.102   Nov 21 2004 01:29:24   tmielke
* v1.66 build 883
* 
*    Rev 1.101   Sep 22 2004 05:20:40   tmielke
* v1.66 build 869 
* improved db-index file creation & cleaned up moving files
* 
*    Rev 1.100   Mar 28 2004 03:58:30   tmielke
* v1.66 bugfix Sekunden vergessen
* 
*    Rev 1.99   Dec 04 2003 03:36:54   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.98   Nov 18 2003 09:39:48   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.97   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.96   Sep 23 2003 01:48:12   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.95   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.94   Sep 11 2003 04:04:10   tmielke
*  
* 
*    Rev 1.93   Sep 11 2003 04:03:42   tmielke
* This version should fix the NT40 problems (waveinAddBuffer deadlock).
* I also removed the animated window code for opening info and search screens.
* 
*    Rev 1.92   Sep 04 2003 00:55:34   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.91   Aug 22 2003 11:49:54   tmielke
* fixed invalid path problem
* 
*    Rev 1.90   Aug 13 2003 01:02:14   tmielke
* IRI warning bugfix, IMPORTANT NOTE on setup screen
* 
*    Rev 1.89   Aug 04 2003 00:35:08   tmielke
* v1.64
* 
*    Rev 1.88   Jul 21 2003 00:02:30   tmielke
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
*    Rev 1.87   Jul 20 2003 21:35:16   tmielke
* m_Page1.m_SCRCTRL_filename = "";
* 
*    Rev 1.86   Jun 09 2003 15:25:24   tmielke
* v1.63 final
* 
*    Rev 1.85   May 19 2003 14:30:28   tmielke
* 1.63pre32 - reverse MIXER order problem fixed
* 
*    Rev 1.84   May 13 2003 06:47:16   tmielke
* - trying to estimate proper input line after changing the device
* - added much brain to the automatic detection of the input line for the IRI
* 
* 
*    Rev 1.83   Apr 29 2003 21:48:50   tmielke
* WindowAnima eingebaut
* 
*    Rev 1.82   Apr 29 2003 05:37:22   tmielke
* pre30 - data link 'change filename' function
* 
*    Rev 1.81   Mar 27 2003 05:26:56   tmielke
* Data Link DLL speeded up
* recording delay fix
* 
*    Rev 1.80   Mar 04 2003 01:13:44   tmielke
* pre release 20 - Actimax manufacturer
* 
*    Rev 1.79   Jan 27 2003 01:14:06   tmielke
* Polish language support
* 
*    Rev 1.78   Jan 22 2003 16:50:34   tmielke
* MiniFrame ausgebaut
* 
*    Rev 1.77   Dec 31 2002 04:39:56   tmielke
* auf dem Win98 Rechner gemachte Änderungen
* 
*    Rev 1.76   Nov 24 2002 01:36:50   tmielke
* Vendor DLL für Ron Telekom, NL Übers. Änderungen
* 
*    Rev 1.75   Nov 20 2002 03:56:04   tmielke
* Dutch language support 
* 
*    Rev 1.74   Oct 25 2002 15:52:20   tmielke
*     - improved userfriendlyness when switching IRI on and off
*     - IRI detection with countdown now
* 
*    Rev 1.73   Oct 16 2002 17:04:16   tmielke
* 1.63 pre 3
* 
*    Rev 1.72   Oct 12 2002 00:43:36   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer 
*   windows versions
* - fixed IRI recording
* 
*    Rev 1.71   Oct 11 2002 22:20:22   tmielke
*  
* 
*    Rev 1.70   Oct 11 2002 20:38:50   tmielke
*  
* 
*    Rev 1.69   Oct 11 2002 19:29:06   tmielke
* zwischendurch-checkin
* 
*    Rev 1.68   Oct 08 2002 05:01:20   tmielke
* PropSheetFrame eingebaut
* 
*    Rev 1.67   Jul 07 2002 02:03:42   tmielke
* Sicherheits-Checkin vor Änderung der Listbox auf Multi-Select
* 
*    Rev 1.66   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.65   May 29 2002 20:30:06   tmielke
* Tracys Änderungswünsche vom 22 Mai 2002 und 
* Übers. vom 20. Mai 2002 eingearbeitet
* 
*    Rev 1.64   May 05 2002 11:57:06   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.63   Apr 19 2002 07:28:08   tmielke
* Czech translation added
* 
*    Rev 1.62   Apr 02 2002 15:01:36   tmielke
* kleinere Änderungen: Suchfenster schließt jetzt mit dem Hauptfenster zusammen, Schließen-Knopf-Text verändert
* 
*    Rev 1.61   Mar 15 2002 20:15:38   tmielke
* 1.60 final
* 
*    Rev 1.60   Feb 11 2002 18:07:36   tmielke
* neue Felder im LG, Übers. d. EnterResponseKey Dialogs
* 
*    Rev 1.59   Jan 28 2002 16:23:40   tmielke
* License Confirmation
* 
*    Rev 1.58   May 26 2002 19:50:56   tmielke
* License confirmation in SCR eingebaut.
* 
*    Rev 1.57   Dec 18 2001 11:12:04   tmielke
* v1.59.0.3 Splash screen
* 
*    Rev 1.56   Nov 07 2001 02:40:50   tmielke
* v1.59 bugfix release
* 
*    Rev 1.55   Nov 06 2001 05:28:14   tmielke
* v1.58a
* 
*    Rev 1.54   Oct 12 2001 16:24:14   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.53   Sep 14 2001 04:13:16   
* v1.57
* 
*    Rev 1.52   20 Jul 2001 02:30:54   tmielke
* v1.56
* 
*    Rev 1.51   13 Jun 2001 16:58:00   tmielke
* Richards Änderungswünsche zur lite Version berücksichtigt
* 
*    Rev 1.50   06 Jun 2001 02:02:02   tmielke
* offizielle release 1.55
* 
*    Rev 1.49   02 Jun 2001 17:02:34   tmielke
* lite version Prototyp
* 
*    Rev 1.48   02 Jun 2001 02:57:28   tmielke
* CODECs screen in lite Version ausgebaut
* 
*    Rev 1.47   17 May 2001 02:02:22   tmielke
* v1.54
* 
*    Rev 1.46   12 Feb 2001 19:37:54   tmielke
* v1.53
* 
*    Rev 1.45   12 Feb 2001 19:35:56   tmielke
* disregard recordings less than X seconds
* neues exit-symbol für deakt.-button
* 
*    Rev 1.44   12 Feb 2001 13:40:54   tmielke
* GetProgramVersion gefixt
* DSP-Dateien gefixt
* Bug: Liste wurde bei Aufnahme nicht richtig aktualisiert
* 
*    Rev 1.43   20 Dec 2000 18:20:14   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.42   04 Dec 2000 02:24:26   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.41   16 Nov 2000 04:26:36   tmielke
* v1.51a:
* - the problem that occured on Iain Gows system has been fixed.
* - the PDF manual will be installed together with the application.
* - the expiry date of the demo version has been changed to 01/04/01
* 
*    Rev 1.40   19 Oct 2000 02:30:12   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.39   18 Oct 2000 20:35:46   tmielke
* Alpha version ALC
* 
*    Rev 1.38   18 Oct 2000 17:14:50   tmielke
* Sicherheits-Checkin vor Auto-Level-Control
* 
*    Rev 1.37   30 Jul 2000 04:34:50   tmielke
* Info-Screen & GB-Version gecheckt
* 
*    Rev 1.36   19 Jun 2000 23:18:14   tmielke
* Ordner eingebaut, drag-and-drop fehlt noch.
* 
*    Rev 1.35   19 Jun 2000 15:55:06   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.34   24 Mar 2000 22:36:56   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.33   18 Mar 2000 11:40:56   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.32   17 Mar 2000 05:32:28   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.31   05 Mar 2000 05:21:36   tmielke
* v1.43
* 
*    Rev 1.30   04 Mar 2000 21:38:04   tmielke
* vendor dll eingebaut
* 
*    Rev 1.29   28 Feb 2000 00:31:08   tmielke
* v1.42
* 
*    Rev 1.28   24 Feb 2000 15:28:28   tmielke
* v1.41
* 
*    Rev 1.27   24 Feb 2000 03:23:00   tmielke
* schnelle Ändeerungen für Retell
* 
*    Rev 1.26   24 Feb 2000 01:23:38   tmielke
* v1.39
* 
*    Rev 1.25   18 Feb 2000 08:21:30   tmielke
* Tageswerk 17.02.00
* 
*    Rev 1.24   18 Feb 2000 00:39:22   tmielke
* v1.38
* 
*    Rev 1.23   15 Dec 1999 03:34:26   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.22   01 Dec 1999 18:45:46   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.21   27 Aug 1999 16:43:38   tmielke
* Lizenz-Management eingebaut
* 
*    Rev 1.20   16 Aug 1999 10:31:50   tmielke
* v1.34
* 
*    Rev 1.19   09 Aug 1999 07:51:08   tmielke
* Encryption eingebaut
* 
*    Rev 1.18   07 Jun 1999 18:37:02   tmielke
* Multi Language Version
* 
*    Rev 1.17   05 Apr 1999 09:39:36   tmielke
* Nachtrag v1.32
* 
*    Rev 1.16   05 Apr 1999 08:14:30   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
* 
*    Rev 1.15   22 Mar 1999 16:26:32   tmielke
* v1.31 Letzte-Aufnahme-Button und Logo
* 
*    Rev 1.14   21 Mar 1999 19:14:48   tmielke
* Info-Button + verbesserter Info-Screen in v1.30
* 
*    Rev 1.13   20 Mar 1999 18:52:36   tmielke
* v1.3
* 
*    Rev 1.12   18 Mar 1999 13:27:40   tmielke
* v0.8 - Demoversion fertig gemacht
* 
*    Rev 1.11   03 Mar 1999 18:13:52   tmielke
* v0.6
* 
*    Rev 1.10   03 Mar 1999 16:39:00   tmielke
* Exception handling läuft in der Debug-Version
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
*    Rev 1.6   01 Mar 1999 13:29:04   tmielke
* Kleinigkeiten
* 
*    Rev 1.5   01 Mar 1999 12:47:06   tmielke
* Indexdatei eingebaut, Gesprächspartner & Notizen, Gesprächslänge...
* 
*    Rev 1.4   28 Feb 1999 11:33:20   tmielke
* Kleinigkeiten
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


#include "stdafx.h"
#include "resource.h"
#include <mmsystem.h>
#include "wavein\wavein.h"
#include "TelAr.h"
#include "TelArPropertySheet.h"
#include "email.h"
#include "crypt.h"
#include "EnterKeyDlg.h"
#include "PasswortDlg.h"
#include "EnterResponseKey.h"
#include "SuchfilterDlg.h"
#include "WindowAnima.h"
#include "AutoUpdate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTelArPropertySheet

IMPLEMENT_DYNAMIC(CTelArPropertySheet, CResizableSheet)


CTelArPropertySheet::CTelArPropertySheet(UINT nIDCaption, CWnd *pParentWnd, UINT iSelectPage) : CResizableSheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_Page1);
	AddPage(&m_Page2);
	AddPage(&m_Page3);
	AddPage(&m_Page4);
	AddPage(&m_Page5);
	m_Page1.m_pTelArPropertyPage2 = &m_Page2;
	m_Page1.m_pTelArPropertyPage3 = &m_Page3;
	m_Page3.m_pTelArPropertyPage1 = &m_Page1;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CTelArPropertySheet::~CTelArPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CTelArPropertySheet, CResizableSheet)
	//{{AFX_MSG_MAP(CTelArPropertySheet)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// ------

void DrawBitmapFromResources(HWND hDlg, int ResourceBitmapID)
{
	RECT r;
	HDC  hdc;
	HDC  hdcmem;
//	CDC  *dc;
//	CDC dcMem;
	BITMAP bm;
	HBITMAP hbm;
	CBitmap cbm;

	VERIFY(hdc = GetDC(hDlg));
//	VERIFY(dc = dc->FromHandle(hdc));
	VERIFY(GetClientRect(hDlg,&r));

	// Create a memory DC for the bitmap.
//	dcMem.CreateCompatibleDC(dc);
	hdcmem = CreateCompatibleDC(hdc);

	//----- bitmap anzeigen

	// Get the size of the bitmap.
	//--cbm.LoadBitmap(ResourceBitmapID);
	HINSTANCE hi = GetModuleHandle("TELARVND.DLL");
	hbm = ::LoadBitmap(hi, MAKEINTRESOURCE(ResourceBitmapID));
	
	//cbm.GetObject(sizeof(bm), &bm);
	GetObject(hbm, sizeof(bm), &bm);
//	cbm.FromHandle(hbm);


	if (!hbm)
	{
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
			MessageBox( NULL, (char *)lpMsgBuf, "GetLastError", MB_OK|MB_ICONINFORMATION );

			// Free the buffer.
			LocalFree( lpMsgBuf );
		}
	}	
	
	
	
	
	
	
	// Select the bitmap into the memory DC.
	HBITMAP hbmOld;
	VERIFY(hbmOld = (HBITMAP)SelectObject(hdcmem, hbm));

	// thumbnails: Blt the bitmaps to the screen DC.
	if (hbmOld)
		StretchBlt(hdc, 0, 0,  // Destination
				r.right-r.left, r.bottom-r.top,
				hdcmem,     // Source DC
				0, 0,       // Source
				bm.bmWidth, // Width
				bm.bmHeight,// Height
				SRCCOPY);   // Operation

	// Default Thumbnail löschen
	/////dcMem.SelectObject(DefaultThumbnail);
	//		DefaultThumbnail.DeleteObject();	

	// Done with memory DC now, so clean up.
	VERIFY(SelectObject(hdcmem, hbmOld));
	VERIFY(DeleteDC(hdcmem));
	VERIFY(ReleaseDC(hDlg,hdc));
}

#define REGISTRY_PATH  "SOFTWARE\\TRS\\TelAr"


static BOOL CheckIt(WORD license_number)
{
#define PRODUCT_ID     '1'

	char product_id = PRODUCT_ID;
	char VolumeNameBuffer[1000];
	DWORD dwVolumeSerialNumber;
	DWORD dwMaximumComponentLength;
	DWORD dwFileSystemFlags;
	char FileSystemNameBuffer[1000];
	char output[100];

	BOOL ok = GetVolumeInformation("C:\\", VolumeNameBuffer, sizeof(VolumeNameBuffer), &dwVolumeSerialNumber,
				&dwMaximumComponentLength, &dwFileSystemFlags, FileSystemNameBuffer, sizeof(FileSystemNameBuffer));
	if (!ok) // 2nd try
	{
		char filebuffer[1000];
		DWORD dw = GetModuleFileName(theApp.m_hInstance, filebuffer, sizeof(filebuffer));
		filebuffer[3] = '\0';
		ok = GetVolumeInformation(filebuffer, VolumeNameBuffer, sizeof(VolumeNameBuffer), &dwVolumeSerialNumber,
			&dwMaximumComponentLength, &dwFileSystemFlags, FileSystemNameBuffer, sizeof(FileSystemNameBuffer));
	}
	
	if (!ok) goto error_message;

	dwVolumeSerialNumber ^= 0xc539b4a6;
	
	char cryptbuf[sizeof(dwVolumeSerialNumber)+sizeof(license_number)];
	memcpy(cryptbuf, &dwVolumeSerialNumber, sizeof(dwVolumeSerialNumber));
	memcpy(cryptbuf+sizeof(dwVolumeSerialNumber), &license_number, sizeof(license_number));

	// in Registry nach license conf code überprüfen und in buffer schreiben
	{
		char buffer[1000];
		char value[200];
		HKEY hKey;
		long lRetCode;
		long lType = REG_SZ;
		long lCb;

		*buffer = '\0';
		if (RegCreateKey(HKEY_LOCAL_MACHINE, REGISTRY_PATH, &hKey) == ERROR_SUCCESS)
		{
			sprintf(value, "ConfigData%d", (int)product_id);

			lCb = sizeof(buffer);
			lRetCode = RegQueryValueEx(hKey, value, 
									   NULL, (ULONG *)&lType, 
									   (LPBYTE)buffer, (ULONG *)&lCb);
			if (lRetCode != ERROR_SUCCESS)
			{
				strcpy(buffer, "");
			}			
		}
		strcpy(X_ConfigData, buffer);

		ECL(product_id, license_number, cryptbuf, output, sizeof(cryptbuf));
		if (!strcmp(buffer, output)) 
		{
			RegCloseKey(hKey);
			sprintf(X_rqk, "%c%05d%010lu", product_id, (int)license_number, dwVolumeSerialNumber);
			return TRUE;
		}
		else
			if (strlen(buffer)==30)
			{
				LANG_MESSAGEBOX1(IDS_STRING116);	// "System has changed. You have to reconfirm the software license."
			}

		{
			int idd;
			
			if (!strcmp(C_language, "D")) 
				idd = IDD_ENTERRESPONSEKEY_DIALOG;
			else if (!strcmp(C_language, "GB")) 
				idd = IDD_GB_ENTERRESPONSEKEY_DIALOG;
			else if (!strcmp(C_language, "CZ")) 
				idd = IDD_CZ_ENTERRESPONSEKEY_DIALOG;
			else if (!strcmp(C_language, "NL")) 
				idd = IDD_NL_ENTERRESPONSEKEY_DIALOG;
			else if (!strcmp(C_language, "PL")) 
				idd = IDD_PL_ENTERRESPONSEKEY_DIALOG;
			else 
				idd = IDD_E_ENTERRESPONSEKEY_DIALOG;

			CEnterResponseKey dlg(idd, AfxGetMainWnd());
			char prodbuf[1000];
			LANG2BUFFER(IDS_STRING114, prodbuf);
			char phonebuf[1000];
			LANG2BUFFER(IDS_STRING115, phonebuf);

			char number[100];
			VEND2BUFFER(IDS_STRING5, number);
			strcat(phonebuf, number);

			dlg.m_product = prodbuf;
			dlg.m_phone   = phonebuf;
			dlg.m_request_code.Format("%c%05d%010lu", product_id, (int)license_number, dwVolumeSerialNumber);
			if (dlg.DoModal()!=IDOK)
			{
				RegCloseKey(hKey);
				goto error;
			}
			
			if (dlg.m_response_code != output)
			{
				LANG_MESSAGEBOX1(IDS_STRING117); // "Response code does not match the request code."
				RegCloseKey(hKey);
				goto error;
			}
			else
				LANG_MESSAGEBOX1(IDS_STRING209); // "The license registration was succesful and the software is now activated."

		}

		lRetCode = RegSetValueEx(hKey,	value, 
								(ULONG)0, (ULONG)REG_SZ, 
								(LPBYTE)output, (ULONG)strlen(output));
		if (lRetCode != ERROR_SUCCESS)
		{
			LANG_MESSAGEBOX1(IDS_STRING118); // "Unable to store some system information. Maybe insufficient privileges? Try to login as Administrator."
			RegCloseKey(hKey);
			goto error;
		}

		RegCloseKey(hKey);
	}
	return TRUE;

error_message:
	LANG_MESSAGEBOX1(IDS_STRING119); // "Impossible to retrieve some needed system information."

error:
	return FALSE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_HOMEPAGE, OnHomepage)
	ON_BN_CLICKED(IDC_EMAIL, OnEmail)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CAboutDlg::CAboutDlg(char *titel) : CDialog(CAboutDlg::IDD)
{
	m_titel = titel;	// "" == about box in splash mode
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT

	n_lauftext = 0;
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (*m_titel)
	{
		// SetDlgItemText(IDC_VERSION, m_titel);

		char wwwadr[200];
		VEND2BUFFER(IDS_STRING4, wwwadr);
		SetDlgItemText(IDC_HOMEPAGE, wwwadr);

		char eadr[200];
		VEND2BUFFER(IDS_STRING3, eadr);
		SetDlgItemText(IDC_EMAIL, eadr);
	}
	else
	{
		GetDlgItem(IDC_HOMEPAGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
		SetTimer(10, 5000, NULL);

		ShowWindow(SW_SHOW);
	}

	//CRect inforect(10,20,200,55);
	//m_info.Create(this);
	//m_info.ShowWindow(WS_VISIBLE);

	SetTimer(12, 1, NULL);
	return TRUE;
}

void CAboutDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// Textausrichtung für DrawText
	dc.SetTextAlign(TA_LEFT | TA_TOP);
	// Textfarbe
	dc.SetTextColor(RGB(0xFF,0xFF,0xFF));
	// Texthintergrund
	dc.SetBkColor(RGB(0x0,0x0,0x0));
	
	// Hintergrund malen
	//CRect rcClient;
	//GetClientRect(rcClient);
	//CBrush brushClient(RGB(0x0,0x0,0x0));
	//dc.FillRect(rcClient, &brushClient);

	CRect rc;

	// Titel / Version Info ausgeben
	GetDlgItem(IDC_VERSIONINFO)->GetClientRect(&rc);
	rc.left+=15;
	rc.right+=15;
	rc.top+=15;
	rc.bottom+=15;
	dc.DrawText(m_titel, rc, DT_TABSTOP);

	// License info
	GetDlgItem(IDC_LICENSE_INFO)->GetClientRect(&rc);
	rc.left += 15;
	rc.right += 15;
	rc.top += 30-(!*m_titel?15:0);
	rc.bottom += 30-(!*m_titel?15:0);
	dc.DrawText("Licensed under the GNU GPL v3.0\r\© 2022 Vidicode UK && Thomas Mielke" , rc, DT_WORDBREAK | DT_TABSTOP);

	CDialog::OnPaint();
} 

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

void CAboutDlg::OnHomepage() 
{
	char buffer2[256];
    HKEY hKey;
	char wwwadr[200], wwwadr2[200];

	VEND2BUFFER(IDS_STRING4, wwwadr);
	strcpy(wwwadr2, "http://");
	strcat(wwwadr2, wwwadr);

	if ((DWORD)ShellExecute(m_hWnd, "open", wwwadr2, NULL, ".", SW_SHOWNORMAL) > 32)
	{
		CDialog::OnOK();
		GetParent()->ShowWindow(SW_HIDE);
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

	CDialog::OnOK();
	GetParent()->ShowWindow(SW_HIDE);
}


void CAboutDlg::OnEmail() 
{
	char eadr[200], eadr2[200];
	VEND2BUFFER(IDS_STRING3, eadr);
	strcpy(eadr2, "mailto:");
	strcat(eadr2, eadr);

	// TODO: Add your control notification handler code here
	HINSTANCE hInst = ShellExecute(this->m_hWnd, "open", eadr2, NULL, NULL, SW_SHOW);
	
	// bei einem Shell-Execute Fehler versuchen wir mit simple MAPI zu senden
	if ((int)hInst <= 32)
	{
		CEmail dlg;
		dlg.DoModal();
	}
	
	CDialog::OnOK();
	GetParent()->ShowWindow(SW_HIDE);
}


void CAboutDlg::OnConfirm() 
{

}


// Hintergrundbitmap malen
BOOL CAboutDlg::OnEraseBkgnd( CDC* pDC )
{
	DrawBitmapFromResources(this->m_hWnd, IDB_INFO_SCREEN);
	return TRUE;
}


void CAboutDlg::OnTimer(UINT_PTR nIDEvent) 
{
	if (nIDEvent == 10)
	{
		KillTimer(nIDEvent);
		ShowWindow(SW_HIDE);
		CDialog::OnOK();
	}
	else if (nIDEvent == 11)
	{
		if (!n_lauftext)
			n_lauftext = 1;
		else
			n_lauftext = 0;
		RedrawWindow();
	}
	else if (nIDEvent == 12)
	{
		KillTimer(nIDEvent);
		ShowWindow(SW_SHOW);
		RedrawWindow();
	}

	CDialog::OnTimer(nIDEvent);
}


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertySheet message handlers



BOOL CTelArPropertySheet::PreCreateWindow(CREATESTRUCT& cs)
{
	return CResizableSheet::PreCreateWindow(cs);
}


BOOL CTelArPropertySheet::OnInitDialog() 
{	
	TRACE0("CTelArPropertySheet::OnInitDialog()\n");

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

	// enable save/restore, with active page
	// EnableSaveRestore(_T("AppWindow"), TRUE, TRUE); -- doesn't work easily...

	// Set the icon in the status area of the taskbar
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = STATUS_ICON_ID;
	nid.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP;
	nid.uCallbackMessage = MYWM_NOTIFYICON;
	nid.hIcon = m_hIcon;
	LANG2BUFFER(IDS_STRING26, nid.szTip); // "Telefonat Archiver öffnen mit Doppelklick"
	if (!Shell_NotifyIcon(NIM_ADD, &nid)) DSAMessageBox(IDS_STRING210);

	SetTimer(1, 1, NULL);

	return CResizableSheet::OnInitDialog();
}

BOOL CTelArPropertySheet::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	switch (wParam)
	{
	case IDC_RETELLSCR_START_STOP_RECORDING:
		{
			if (X_modus == 0)
			{
				X_modus = 1; // manuell
				AfxMessageBox("SCR has been switched to manual recording mode for remote control. Please restart recording.", MB_ICONINFORMATION);
				m_Page1.Normalisieren();
				return TRUE;
			}
			m_Page1.OnAufnahme();

			// get global memory
			HGLOBAL hmem = GlobalAlloc(GMEM_SHARE, 30);
			char *cp = (char *)GlobalLock(hmem);
			sprintf(cp, "%d", m_Page1.nRecordingPeak);
			GlobalUnlock(cp);

			// put signal max to clipboard
			OpenClipboard();
			EmptyClipboard();
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
				m_Page1.SetDlgItemText(IDC_GESPRAECHSPARTNER, cp);
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
				m_Page1.SetDlgItemText(IDC_NOTIZEN, cp);
				GlobalUnlock(hmem);
			}
			CloseClipboard();
		}
		return TRUE;
	case IDC_RETELLSCR_SET_FILENAME:
		{
			OpenClipboard();
			HGLOBAL hmem = GetClipboardData(CF_TEXT);
			if (hmem)
			{
				char *cp = (char *)GlobalLock(hmem);
				m_Page1.m_SCRCTRL_filename = cp;

				GlobalUnlock(hmem);
			}
			CloseClipboard();
		}
		return TRUE;
	case IDC_RETELLSCR_CANCEL_RECORDING:
		m_Page1.m_SCRCTRL_filename = "";
		m_Page1.OnAbbrechen();
		return TRUE;
	case IDC_RETELLSCR_SET_WINDOW_TITLE:
		{
			OpenClipboard();
			HGLOBAL hmem = GetClipboardData(CF_TEXT);
			if (hmem)
			{
				char *cp = (char *)GlobalLock(hmem);
				m_Page1.NotifyWindowTitle = cp;
				GlobalUnlock(hmem);
			}
			EmptyClipboard();
			CloseClipboard();
		}
		return TRUE;
	case IDC_RETELLSCR_GET_STATUS:
		if (m_Page1.GetDlgItem(IDC_NOTIZEN)->IsWindowEnabled()) 
			return 1;
		else 
			return 0;
	case IDC_RETELLSCR_GET_LAST_FILENAME:
		{
			// get some global memory
			HGLOBAL hmem = GlobalAlloc(GMEM_SHARE, m_Page1.m_SCRCTRL_get_last_filename.GetLength()+1);
			if (!hmem) return FALSE;
			char *cp = (char *)GlobalLock(hmem);
			strcpy(cp, m_Page1.m_SCRCTRL_get_last_filename.GetBuffer(0));

			// put filename to clipboard
			OpenClipboard();
			EmptyClipboard();
			HANDLE ret = SetClipboardData(CF_TEXT, hmem);
			CloseClipboard();
			if (!ret) return FALSE;
		}
		return TRUE;
	case IDC_RETELLSCR_NORMALIZE_WINDOW:
		{
			NormalizeWindow();
		}
		return TRUE;
	case IDC_RETELLSCR_MUTE_RECORDING:
		{
			if (m_Page1.odbMute.GetState() != MUTE_MICROPHONE)
				m_Page1.OnBnClickedMute();
		}
		return TRUE;
	case IDC_RETELLSCR_UNMUTE_RECORDING:
		{
			if (m_Page1.odbMute.GetState() == MUTE_MICROPHONE)
				m_Page1.OnBnClickedMute();
		}
		return TRUE;
	}

	return CPropertySheet::OnCommand(wParam, lParam);
}

void CTelArPropertySheet::OnDestroy() 
{
	CPropertySheet::OnDestroy();

	// save window position
	RECT r;
	GetWindowRect(&r);
	WINDOWPLACEMENT wpl;
	GetWindowPlacement(&wpl);
	int maximized = (wpl.showCmd == SW_SHOWMAXIMIZED) != 0;
	if (maximized) 
		r = wpl.rcNormalPosition;
	sprintf(X_windowpos, "%5.5d%5.5d%5.5d%5.5d", r.left, r.top, r.right-r.left, r.bottom-r.top/*, maximized*/);

	switch (GetActiveIndex())
	{
	case 0:
		m_Page1.OnKillActive();
		break;
	case 1:
		m_Page2.OnKillActive();
		break;
	case 2:
		m_Page3.OnKillActive();
		break;
	case 3:
		m_Page4.OnKillActive();
		break;
	case 4:
		m_Page5.OnKillActive();
		break;
	}

	SaveReg();	

	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = STATUS_ICON_ID;
	Shell_NotifyIcon(NIM_DELETE, &nid);		
}


void CTelArPropertySheet::OnSysCommand(UINT nID, LPARAM lParam) 
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
		m_Page1.OnBeenden();
	}
	else if (nID == SC_MINIMIZE)
	{
		switch (GetActiveIndex())
		{
		case 0:
			m_Page1.OnKillActive();
			break;
		case 1:
			m_Page2.OnKillActive();
			break;
		case 2:
			m_Page3.OnKillActive();
			break;
		case 3:
			m_Page4.OnKillActive();
			break;
		case 4:
			m_Page5.OnKillActive();
			break;
		}

		if (m_Page2.suchfilter) 
			m_Page2.suchfilter->ShowWindow(SW_HIDE);
		ShowWindow(SW_HIDE);
		SaveReg();
	}
	else
	{
		CPropertySheet::OnSysCommand(nID, lParam);
	}
}


// On_MYWM_NOTIFYICON - processes callback messages for taskbar icons  
// wParam - first message parameter of the callback message 
// lParam - second message parameter of the callback message 
void CTelArPropertySheet::On_MYWM_NOTIFYICON(WPARAM wParam, LPARAM lParam) 
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
					m_Page1.OnAufnahme();

				// hier gleich weitermachen:
 
            case WM_LBUTTONDBLCLK:
				//if (!IsWindowVisible()) 
				{
					NormalizeWindow();
				}
                break; 

            default: 
                break; 
        } 
    } 
    return; 
} 

///////////////////////////////////////////////////////////////////
// OnTapiEvent
//
// This is the real TAPI event handler, called on our UI thread when
// the WM_PRIVATETAPIEVENT message is received
//
///////////////////////////////////////////////////////////////////

#ifdef TAPI

HRESULT CTelArPropertySheet::OnTapiEvent(ITBasicCallControl * gpCall, TAPI_EVENT TapiEvent, IDispatch * pEvent)
{
    HRESULT hr;

    switch ( TapiEvent )
    {
        case TE_CALLNOTIFICATION:
        {
            //
            // TE_CALLNOTIFICATION means that the application is being notified
            // of a new call.
            //
            // Note that we don't answer to call at this point.  The application
            // should wait for a CS_OFFERING CallState message before answering
            // the call.
            //

            ITCallNotificationEvent         * pNotify;
            
            hr = pEvent->QueryInterface( IID_ITCallNotificationEvent, (void **)&pNotify );

            if (S_OK != hr)
            {
                DF("Incoming call, but failed to get the interface");
            }
            else
            {
                CALL_PRIVILEGE          cp;
                ITCallInfo *            pCall;

                //
                // get the call
                //

                hr = pNotify->get_Call( &pCall );

                pNotify->Release();

                if ( SUCCEEDED(hr) )
                {
                    //
                    // check to see if we own the call
                    //

                    hr = pCall->get_Privilege( &cp );

                    if ( FAILED(hr) || (CP_OWNER != cp) )
                    {
                        //
                        // just ignore it if we don't own it
                        //

                        pCall->Release();

                        pEvent->Release(); // we addrefed it CTAPIEventNotification::Event()

                        return S_OK;
                    }

                    //
                    // Get the ITBasicCallControl interface 
                    //

                    //
                    // If we're already in a call, disconnect the new call.  Otherwise,
                    // save it in our global variable.
                    //

                    ITBasicCallControl * pCallControl;

                    hr = pCall->QueryInterface( IID_ITBasicCallControl,
                                                (void**)&pCallControl );

                    pCall->Release();
                  
                    if ( SUCCEEDED(hr) )
                    {
                        if (gpCall == NULL)
                        {
                            gpCall = pCallControl;
                 
							if (X_modus == 2)
								m_Page1.TAPIUpdateCallID(gpCall);

                            //SetStatusMessage(L"Incoming Owner Call");
                        }
                        else
                        {
                            //
                            // Reject this call since we're already in a call
                            //

                            hr = pCallControl->Disconnect(DC_REJECTED);

                            pCallControl->Release();

                            if (FAILED(hr))
                            {
                                break;
                            }
                        }
                    }

                }
            }
            
            break;
        }
        
        case TE_CALLSTATE:
        {
            // TE_CALLSTATE is a call state event.  pEvent is
            // an ITCallStateEvent

            CALL_STATE           cs;
            ITCallStateEvent   * pCallStateEvent;
            ITCallInfo *         pCall;
            ITBasicCallControl * pCallControl;

            // Get the interface
            hr = pEvent->QueryInterface( IID_ITCallStateEvent, (void **)&pCallStateEvent );

            if ( FAILED(hr) )
            {
                break;
            }

            // get the CallInfo interface
            hr = pCallStateEvent->get_Call( &pCall );

            if ( FAILED(hr) )
            {
                pCallStateEvent->Release();
                break;
            }

            //get the ITBasicCallControl interface and compare it to our existing call
            hr = pCall->QueryInterface( IID_ITBasicCallControl,(void**)&pCallControl );

            pCall->Release();

            if (FAILED(hr))
            {
                pCallStateEvent->Release();
                break;
            }

            //ignore call state events for other calls
            if (pCallControl != gpCall && gpCall)
            {
                pCallControl->Release();
                pCallStateEvent->Release();
                break;
            }
			if (!gpCall) gpCall = pCallControl;
            pCallControl->Release();

            //
            // This is a call state event for our call
            //

            // get the CallState that we are being notified of.
            hr = pCallStateEvent->get_State( &cs );

            // Release the interface
            pCallStateEvent->Release();

            if ( FAILED(hr) )
            {
                break;
            }

            // if it's offering, update our UI
            if (CS_OFFERING == cs)
            {
//               if (gfAutoAnswer)
//                {
//                    PostMessage(ghDlg, WM_COMMAND, IDC_ANSWER, 0); 
//                }
//                else
//                {
//                    SetStatusMessage(L"Click the Answer button");
//                }
            }
            else if (CS_DISCONNECTED == cs)
            {
				if (X_modus == 2)
					m_Page1.TAPIDisconnected(gpCall);
//                PostMessage(ghDlg, WM_COMMAND, IDC_DISCONNECTED, 0);
            }
            else if (CS_CONNECTED == cs)
            {
				if (X_modus == 2)
					m_Page1.TAPIConnected(gpCall);
            }
                
            break;
        }

        default:
            break;
    }

    pEvent->Release(); // we addrefed it CTAPIEventNotification::Event()
    
    return S_OK;
}

#endif // #ifdef TAPI

void CTelArPropertySheet::NormalizeWindow()
{
	static BOOL bDialogActive = FALSE;
	BOOL bDoIt = TRUE;
	if (X_Locked || *X_master_passwort)
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
		
		if (bDialogActive)
			bDoIt = FALSE;
		else
		{
			bDialogActive = TRUE;
			if (!*X_master_passwort)	// if there is no master pw, use default pw
			{
				CPasswortDlg dlg(idd, (CString)"wonder", this);
				if (dlg.DoModal() != IDOK) bDoIt = FALSE;
			}
			else
			{
				CPasswortDlg dlg(idd, (CString)X_master_passwort, this);
				if (dlg.DoModal() != IDOK) bDoIt = FALSE;
			}
			bDialogActive =
				 FALSE;
		}		
	}

	if (bDoIt)
	{
		AfxGetMainWnd()->SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);					
		AfxGetMainWnd()->SetForegroundWindow();
		AfxGetMainWnd()->SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);					
	}
}

LRESULT CTelArPropertySheet::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message == MYWM_NOTIFYICON)
	{
		On_MYWM_NOTIFYICON(wParam, lParam);
	}
	else if (message == MYWM_REALLOCATE_WAVEIN_BUFFER)
	{
		WaveIn_ReallocBuffer();
	}
	else if (message == WM_QUERYENDSESSION)
	{
		; // release network license
	}
	else if (message == WM_PRIVATETAPIEVENT)
    {
#ifdef TAPI
		OnTapiEvent(theApp.m_Tapi.gpCall, (TAPI_EVENT) wParam, (IDispatch *) lParam);
#endif
    }

	return CPropertySheet::WindowProc(message, wParam, lParam);
}

void CTelArPropertySheet::OnTimer(UINT_PTR nIDEvent) 
{
	try
	{

		if (nIDEvent == 1)
		{
			extern CTelArApp theApp;
			SetActivePage(3);	// CODEC-Listen MÜSSEN (NICHT MEHR??) aufgebaut werden!!!
			if (theApp.m_pMainWnd) WaveIn_SetHWND((DWORD)theApp.m_pMainWnd->m_hWnd);
			KillTimer(1);
			SetTimer(2, 1, NULL);
		}
		else if (nIDEvent == 2)
		{	// dann auf die Hardware-Seite schalten, nachdem CODECs-Seite initialisiert ist
			SetActivePage(2);
			KillTimer(2);
			SetTimer(3, 1, NULL);
		}
		else if (nIDEvent == 3)
		{	// dann auf die Wiedergabe-Seite schalten um  Liste zu initialisieren
			// brauchen wir nicht mehr, crasht bei IndexDB-Konvertierungsfehlern    SetActivePage(1);
			KillTimer(3);
			SetTimer(4, 1, NULL);
		}
		else if (nIDEvent == 4)
		{	// und nachdem alles andere initialisiert ist: auf die Aufnahme-Seite schalten, 
			SetActivePage(X_InitialSelection ? 2 : 0);	// ...es sei denn, das erste mal wurde die soudkarte ausgewählt
			KillTimer(4);

			// Fenstertitel setzen
			char titel[100];
			VEND2BUFFER(IDS_STRING6, titel);
			strcat(titel, " ");

			LoadString(GetModuleHandle("TELAR.EXE"), IDS_TITEL2, titel+strlen(titel), sizeof(titel));
			strcat(titel, " ");
			strcat(titel, version_string);	
			strcat(titel, " (");
			strcat(titel, C_language);
			strcat(titel, ")");
			if (!strcmp(C_vendor, "PhoneCoach CompuCorder"))
				strcpy(titel, "PhoneCoach CompuCorder");
			
			AfxGetMainWnd()->SetWindowText(titel);
			
			// Fenstertitel für data link in HKEY_CURRENT_USER schreiben
			HKEY hkcu;
			if (RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\TRS\\TelAr", &hkcu) != ERROR_SUCCESS)
			{
				// give up
				DF("CPropertySheet::OnTimer::RegOpenKey(HKEY_CURRENT_USER) failed.")
			}
			else
			{
				SetKey(NULL, hkcu, "WindowTitle", titel);
				RegCloseKey(hkcu);
			}

			// beim ersten mal starten mit Hardware tab sichtbar machen!
			if (X_InitialSelection) 
			{
				ShowWindow(SW_SHOW);
				m_Page3.OnIntelligentActive();
			}

			// restore window position
			if (strlen(X_windowpos) == 20)
			{
				RECT rScreen;
				GetDesktopWindow()->GetWindowRect(&rScreen);
				RECT r;
				GetWindowRect(&r);
				int x, y, cy, cx/*, maximized*/;
				sscanf(X_windowpos, "%5d%5d%5d%5d", &x, &y, &cx, &cy/*, &maximized*/);
				if (x < rScreen.left) x = rScreen.left;
				if (x > rScreen.right-100) x = rScreen.right-100;
				if (y < rScreen.top) y = rScreen.top;
				if (y > rScreen.bottom-100) y = rScreen.bottom-100;
				if (cx < 0 || cx > rScreen.right-rScreen.left) cx = rScreen.right-rScreen.left;
				if (cy < 0 || cy > rScreen.bottom-rScreen.top) cy = rScreen.bottom-rScreen.top;
				MoveWindow(x, y, cx, cy);
				/*WINDOWPLACEMENT wpl;
				if (maximized)
				GetWindowPlacement(&wpl); 
				wpl.showCmd = SW_SHOWMAXIMIZED;
				SetWindowPlacement(&wpl);*/
			}

			// at last: show or hide main window
#ifdef _DEBUG
			AfxGetMainWnd()->ShowWindow(SW_SHOW);
#else
			AfxGetMainWnd()->ShowWindow(SW_HIDE);
#endif // _DEBUG
		}
		else if (nIDEvent == 5)
		{
			KillTimer(5);
			SetTimer(5, 60000, NULL);
		}
	}
	catch( CException* e )
	{
		char buffer[1000];
		e->GetErrorMessage(buffer, sizeof(buffer));
		TRACE ("CException thrown by propSheet.OnTimer(): %s\n", buffer);
		e->Delete();
	}

endtimer:	
	CPropertySheet::OnTimer(nIDEvent);
}

void CAboutDlg::OnOK() 
{
	CWindowAnima wa(this);
	wa.Scatter4(90, 32, 1);	
	CDialog::OnOK();
}

void CAboutDlg::OnUpdate() 
{
	CAutoUpdate dlg;
	if (dlg.DoModal() == IDOK)
	{
		CDialog::OnCancel();
	
		AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0L);
	}
}