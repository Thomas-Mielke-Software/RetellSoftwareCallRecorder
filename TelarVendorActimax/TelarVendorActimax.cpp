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
*	$Log:   D:/PVCSArch/TelAr/TelarVendorActimax/TelarVendorActimax.cpv  $
* 
*    Rev 1.28   Dec 19 2007 17:27:20   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.27   Oct 11 2007 10:14:52   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.26   Sep 21 2007 15:47:10   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.25   Aug 14 2007 14:08:58   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.24   May 09 2007 10:23:32   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.23   Nov 16 2006 14:59:36   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.22   Nov 13 2006 13:26:12   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.21   Jun 12 2006 15:13:16   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.20   Nov 25 2005 01:32:04   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.19   Nov 23 2005 16:11:10   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.18   Nov 11 2005 09:50:48   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.17   Jul 11 2005 08:52:20   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.16   Jul 05 2005 01:50:14   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.15   Jun 28 2005 01:46:20   tmielke
* v1.72 build 1250
* 
*    Rev 1.14   Jun 02 2005 01:30:22   tmielke
* v1.72 build 1207
* 
*    Rev 1.13   May 18 2005 13:47:06   tmielke
* v1.72 build 1200
* 
*    Rev 1.12   Mar 18 2005 16:11:56   tmielke
*  
* 
*    Rev 1.11   Mar 12 2005 07:08:24   tmielke
* v1.69
* 
*    Rev 1.10   Feb 22 2005 16:53:18   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.9   Nov 21 2004 01:29:12   tmielke
* v1.66 build 883
* 
*    Rev 1.8   Dec 04 2003 03:36:38   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.7   Nov 18 2003 09:39:40   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.6   Oct 03 2003 01:22:06   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.5   Sep 23 2003 01:48:00   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.4   Sep 12 2003 01:12:08   tmielke
*  
* 
*    Rev 1.3   Sep 11 2003 04:04:02   tmielke
*  
* 
*    Rev 1.2   Sep 04 2003 00:55:24   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.1   Aug 04 2003 00:34:56   tmielke
* v1.64
* 
*    Rev 1.0   Jun 09 2003 16:48:18   tmielke
* TelarVendorPhoneCoach dazu (und Actimax auch nachträglich)
* 
*    Rev 1.0   Nov 23 2002 22:36:56   tmielke
* Initial check-in
* 
*    Rev 1.18   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.17   May 05 2002 11:57:08   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.16   Mar 15 2002 20:23:02   tmielke
* v1.60
* 
*    Rev 1.15   Nov 07 2001 02:40:52   tmielke
* v1.59 bugfix release
* 
*    Rev 1.14   Nov 06 2001 05:28:16   tmielke
* v1.58a
* 
*    Rev 1.13   Oct 12 2001 16:24:16   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.12   Sep 14 2001 04:13:18   
* v1.57
* 
*    Rev 1.11   06 Jun 2001 02:02:06   tmielke
* offizielle release 1.55
* 
*    Rev 1.10   17 May 2001 02:02:24   tmielke
* v1.54
* 
*    Rev 1.9   12 Feb 2001 19:37:56   tmielke
* v1.53
* 
*    Rev 1.8   20 Dec 2000 18:20:18   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.7   04 Dec 2000 02:24:30   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.6   19 Oct 2000 02:30:16   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.5   19 Jun 2000 15:55:10   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.4   24 Mar 2000 22:36:58   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.3   18 Mar 2000 11:40:58   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.2   17 Mar 2000 05:32:30   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.1   05 Mar 2000 05:21:38   tmielke
* v1.43
* 
*    Rev 1.0   04 Mar 2000 21:38:04   tmielke
* vendor dll eingebaut
* 
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
  
