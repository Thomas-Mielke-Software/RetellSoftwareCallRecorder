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
*	$Log:   D:/pvcsarch/telar/telarlangenglish/telarllangenglish.cpv  $
* 
*    Rev 1.55   Dec 19 2007 17:27:40   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.54   Oct 11 2007 10:15:16   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.53   Sep 21 2007 15:47:28   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.52   Aug 14 2007 14:09:18   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.51   May 09 2007 10:23:58   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.50   Nov 16 2006 14:59:56   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.49   Nov 13 2006 13:26:36   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.48   Jun 12 2006 15:13:32   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.47   Nov 25 2005 01:32:34   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.46   Nov 23 2005 16:11:34   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.45   Nov 11 2005 09:51:08   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.44   Jul 11 2005 08:52:52   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.43   Jul 05 2005 01:50:32   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.42   Jun 28 2005 01:46:36   tmielke
* v1.72 build 1250
* 
*    Rev 1.41   Jun 02 2005 01:30:38   tmielke
* v1.72 build 1207
* 
*    Rev 1.40   May 18 2005 13:47:20   tmielke
* v1.72 build 1200
* 
*    Rev 1.39   Mar 18 2005 16:12:10   tmielke
*  
* 
*    Rev 1.38   Mar 12 2005 07:08:46   tmielke
* v1.69
* 
*    Rev 1.37   Feb 22 2005 16:53:30   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.36   Nov 21 2004 01:29:24   tmielke
* v1.66 build 883
* 
*    Rev 1.35   Dec 04 2003 03:36:52   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.34   Nov 18 2003 09:39:48   tmielke
* komisch, Workfile �lter als Archive...
* Checkin anyway...
* 
*    Rev 1.33   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.32   Sep 23 2003 01:48:12   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.31   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.30   Sep 11 2003 04:04:10   tmielke
*  
* 
*    Rev 1.29   Sep 04 2003 00:55:34   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.28   Aug 04 2003 00:35:08   tmielke
* v1.64
* 
*    Rev 1.27   Jun 09 2003 15:25:24   tmielke
* v1.63 final
* 
*    Rev 1.26   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.25   May 05 2002 11:57:02   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.24   Mar 15 2002 20:22:48   tmielke
* v1.60
* 
*    Rev 1.23   Nov 07 2001 02:40:44   tmielke
* v1.59 bugfix release
* 
*    Rev 1.22   Nov 06 2001 05:28:06   tmielke
* v1.58a
* 
*    Rev 1.21   Oct 12 2001 16:24:02   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.20   Sep 14 2001 04:13:12   
* v1.57
* 
*    Rev 1.19   06 Jun 2001 02:01:52   tmielke
* offizielle release 1.55
* 
*    Rev 1.18   17 May 2001 02:02:16   tmielke
* v1.54
* 
*    Rev 1.17   12 Feb 2001 19:37:50   tmielke
* v1.53
* 
*    Rev 1.16   20 Dec 2000 18:20:06   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.15   04 Dec 2000 02:24:22   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.14   19 Oct 2000 02:30:08   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien l�schen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.13   19 Jun 2000 15:55:00   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.12   24 Mar 2000 22:36:52   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.11   18 Mar 2000 11:40:52   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.10   17 Mar 2000 05:32:24   tmielke
* v1.6 jetzt tauglich f�r �sterreich/Schweitz
* 
*    Rev 1.9   05 Mar 2000 05:21:32   tmielke
* v1.43
* 
*    Rev 1.8   28 Feb 2000 00:31:04   tmielke
* v1.42
* 
*    Rev 1.7   24 Feb 2000 15:28:24   tmielke
* v1.41
* 
*    Rev 1.6   24 Feb 2000 01:23:34   tmielke
* v1.39
* 
*    Rev 1.5   18 Feb 2000 00:39:18   tmielke
* v1.38
* 
*    Rev 1.4   15 Dec 1999 03:34:18   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad pr�fen
* 
*    Rev 1.3   01 Dec 1999 18:45:44   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.2   16 Aug 1999 10:31:48   tmielke
* v1.34
* 
*    Rev 1.1   09 Aug 1999 07:51:06   tmielke
* Encryption eingebaut
* 
*    Rev 1.0   07 Jun 1999 18:59:38   tmielke
* Multi Language
* 
*/

#include <windows.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                        DWORD ul_reason_for_call, 
                        LPVOID lpReserved )
{
    switch( ul_reason_for_call ) 
	{
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
		;
    }
    return TRUE;
}
  
