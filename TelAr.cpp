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
*	TelAr.cpp : Defines the class behaviors for the application.
*	
*	$Log:   D:/pvcsarch/telar/telar.cpv  $
* 
*    Rev 1.123   Dec 19 2007 17:27:40   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.122   Oct 11 2007 10:15:14   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.121   Sep 21 2007 15:47:28   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.120   Aug 14 2007 14:09:18   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.119   May 09 2007 10:23:56   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.118   Dec 13 2006 13:38:28   tmielke
* No refund possible text added
* 
*    Rev 1.117   Nov 16 2006 14:59:56   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.116   Nov 13 2006 13:26:34   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.115   Nov 12 2006 17:16:50   tmielke
* v1.79 build 2095 -- messed up version: auto-recording broken
* 
*    Rev 1.114   Jun 12 2006 15:13:30   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.113   May 31 2006 09:19:10   tmielke
* zur Sicherheit vor Lautstärkeregler für Audio-Ausgabe
* 
*    Rev 1.112   Mar 17 2006 13:16:28   tmielke
* v1.77 build 1818
* 
*    Rev 1.111   Nov 25 2005 01:32:32   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.110   Nov 23 2005 16:11:34   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.109   Nov 11 2005 09:51:06   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.108   Jul 11 2005 08:52:50   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.107   Jul 05 2005 01:50:30   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.106   Jun 28 2005 01:46:36   tmielke
* v1.72 build 1250
* 
*    Rev 1.105   Jun 02 2005 01:30:38   tmielke
* v1.72 build 1207
* 
*    Rev 1.104   May 18 2005 13:47:18   tmielke
* v1.72 build 1200
* 
*    Rev 1.103   Apr 10 2005 17:59:58   tmielke
* New folder select dialog.
* 
*    Rev 1.102   Mar 18 2005 16:12:08   tmielke
*  
* 
*    Rev 1.101   Mar 12 2005 07:08:44   tmielke
* v1.69
* 
*    Rev 1.100   Feb 22 2005 16:53:28   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.99   Nov 21 2004 01:29:22   tmielke
* v1.66 build 883
* 
*    Rev 1.98   Jun 01 2004 05:07:22   tmielke
* v1.66 build 846
* improved stability
* 
*    Rev 1.97   Mar 28 2004 03:58:30   tmielke
* v1.66 bugfix Sekunden vergessen
* 
*    Rev 1.96   Feb 11 2004 00:50:40   tmielke
* v1.66 pre-final
* 
*    Rev 1.95   Dec 04 2003 03:36:52   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.94   Nov 06 2003 05:18:30   tmielke
* MDB-index Zwischenversion
* 
*    Rev 1.93   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.92   Sep 23 2003 01:48:10   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.91   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.90   Sep 11 2003 04:04:08   tmielke
*  
* 
*    Rev 1.89   Sep 04 2003 00:55:32   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.88   Aug 20 2003 01:03:06   tmielke
* nomixer failsafe setting
* 
*    Rev 1.87   Aug 04 2003 00:35:06   tmielke
* v1.64
* 
*    Rev 1.86   Aug 04 2003 00:34:26   tmielke
* optional ALC, corrected spelling, and setup script modification
* 
*    Rev 1.85   Jul 21 2003 00:02:30   tmielke
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
*    Rev 1.84   Jun 09 2003 15:25:22   tmielke
* v1.63 final
* 
*    Rev 1.83   May 13 2003 06:47:14   tmielke
* - trying to estimate proper input line after changing the device
* - added much brain to the automatic detection of the input line for the IRI
* 
* 
*    Rev 1.82   Apr 30 2003 01:02:30   tmielke
* DSAMessageBox eingebaut
* 
*    Rev 1.81   Apr 29 2003 05:37:22   tmielke
* pre30 - data link 'change filename' function
* 
*    Rev 1.80   Mar 27 2003 05:26:56   tmielke
* Data Link DLL speeded up
* recording delay fix
* 
*    Rev 1.79   Mar 25 2003 23:06:06   tmielke
* log file system revised
* 
*    Rev 1.78   Mar 17 2003 02:12:16   tmielke
* Actimax without background texture
* 
*    Rev 1.77   Jan 27 2003 01:14:06   tmielke
* Polish language support
* 
*    Rev 1.76   Jan 22 2003 16:50:34   tmielke
* MiniFrame ausgebaut
* 
*    Rev 1.75   Jan 05 2003 11:00:30   tmielke
* Icon-Tip bug beseitigt
* 
*    Rev 1.74   Dec 18 2002 15:45:46   tmielke
* recording level has no more any time delay
* 
*    Rev 1.73   Dec 18 2002 01:17:44   tmielke
* SelectAudioDevice eingebaut.
* ProbeSMC funktionierte noch nicht richtig.
* 
*    Rev 1.72   Nov 20 2002 03:56:02   tmielke
* Dutch language support 
* 
*    Rev 1.71   Nov 02 2002 20:59:38   tmielke
* - Timer ID1 verändert
* - Debug Informationen in Datei
* 
*    Rev 1.70   Oct 16 2002 17:04:16   tmielke
* 1.63 pre 3
* 
*    Rev 1.69   Oct 12 2002 00:43:34   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer 
*   windows versions
* - fixed IRI recording
* 
*    Rev 1.68   Oct 08 2002 05:01:18   tmielke
* PropSheetFrame eingebaut
* 
*    Rev 1.67   Sep 24 2002 15:16:26   tmielke
* Total vermurxt alles... :(
* 
*    Rev 1.66   Sep 11 2002 20:13:34   tmielke
* Mixer Architektur in hardware screen eingebaut
* 
*    Rev 1.65   Aug 16 2002 20:03:46   tmielke
* control tone
* 
*    Rev 1.64   Jul 22 2002 12:43:44   tmielke
* fixed multi-select list box
* 
*    Rev 1.63   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.62   May 05 2002 11:56:56   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.61   Apr 25 2002 06:43:06   tmielke
* zusätzliche Suchfilterfunktionen
* 
*    Rev 1.60   Apr 19 2002 07:27:56   tmielke
* Czech translation added
* 
*    Rev 1.59   Mar 28 2002 13:07:44   tmielke
* Search by date, search window now docks on the left side.
* 
*    Rev 1.58   Mar 15 2002 20:22:36   tmielke
* v1.60
* 
*    Rev 1.57   Jan 28 2002 16:19:00   tmielke
* License Confirmation
* 
*    Rev 1.56   May 26 2002 19:50:48   tmielke
* License confirmation in SCR eingebaut.
* 
*    Rev 1.55   Dec 18 2001 11:11:58   tmielke
* v1.59.0.3 Splash screen
* 
*    Rev 1.54   Nov 07 2001 02:40:36   tmielke
* v1.59 bugfix release
* 
*    Rev 1.53   Nov 06 2001 05:27:54   tmielke
* v1.58a
* 
*    Rev 1.52   Oct 12 2001 16:23:50   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.51   Sep 14 2001 04:13:06   
* v1.57
* 
*    Rev 1.50   06 Jun 2001 02:01:38   tmielke
* offizielle release 1.55
* 
*    Rev 1.49   02 Jun 2001 17:01:28   tmielke
* lite version Prototyp
* 
*    Rev 1.48   02 Jun 2001 02:57:18   tmielke
* CODECs screen in lite Version ausgebaut
* 
*    Rev 1.47   17 May 2001 02:02:06   tmielke
* v1.54
* 
*    Rev 1.46   17 May 2001 00:35:20   tmielke
* Spanische Sprach-DLL hinzugefügt
* 
*    Rev 1.45   12 Feb 2001 19:37:42   tmielke
* v1.53
* 
*    Rev 1.44   12 Feb 2001 19:35:46   tmielke
* disregard recordings less than X seconds
* neues exit-symbol für deakt.-button
* 
*    Rev 1.43   21 Dec 2000 01:33:58   tmielke
* Änderungen nach umstellung auf DS60
* 
*    Rev 1.42   20 Dec 2000 18:19:54   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.41   04 Dec 2000 02:24:12   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.40   19 Oct 2000 02:29:58   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.39   18 Oct 2000 17:14:40   tmielke
* Sicherheits-Checkin vor Auto-Level-Control
* 
*    Rev 1.38   30 Jul 2000 04:34:38   tmielke
* Info-Screen & GB-Version gecheckt
* 
*    Rev 1.37   21 Jun 2000 05:36:16   tmielke
* Drag-and-drop basics eingebaut
* 
*    Rev 1.36   19 Jun 2000 23:18:00   tmielke
* Ordner eingebaut, drag-and-drop fehlt noch.
* 
*    Rev 1.35   19 Jun 2000 15:54:52   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.34   24 Mar 2000 22:36:46   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.33   18 Mar 2000 11:40:46   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.32   17 Mar 2000 05:32:18   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.31   05 Mar 2000 05:21:24   tmielke
* v1.43
* 
*    Rev 1.30   04 Mar 2000 21:37:54   tmielke
* vendor dll eingebaut
* 
*    Rev 1.29   28 Feb 2000 00:30:58   tmielke
* v1.42
* 
*    Rev 1.28   24 Feb 2000 15:28:16   tmielke
* v1.41
* 
*    Rev 1.27   24 Feb 2000 01:23:28   tmielke
* v1.39
* 
*    Rev 1.26   18 Feb 2000 08:21:20   tmielke
* Tageswerk 17.02.00
* 
*    Rev 1.25   18 Feb 2000 00:39:12   tmielke
* v1.38
* 
*    Rev 1.24   15 Dec 1999 03:34:08   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.23   01 Dec 1999 18:45:38   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.22   27 Aug 1999 16:43:34   tmielke
* Lizenz-Management eingebaut
* 
*    Rev 1.21   25 Aug 1999 05:57:42   tmielke
* EC, DC und Zufallsgenerator in crypt.h ausgelagert
* 
*    Rev 1.20   16 Aug 1999 10:31:46   tmielke
* v1.34
* 
*    Rev 1.19   14 Aug 1999 08:51:00   tmielke
* Suchfunktion eingebaut
* 
*    Rev 1.18   09 Aug 1999 07:51:04   tmielke
* Encryption eingebaut
* 
*    Rev 1.17   07 Jun 1999 19:34:48   tmielke
* TelArDlg.h endgültig 'rausgeschmissen
* 
*    Rev 1.16   07 Jun 1999 18:37:00   tmielke
* Multi Language Version
* 
*    Rev 1.15   05 Apr 1999 09:39:34   tmielke
* Nachtrag v1.32
* 
*    Rev 1.14   05 Apr 1999 08:14:28   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
* 
*    Rev 1.13   22 Mar 1999 16:26:30   tmielke
* v1.31 Letzte-Aufnahme-Button und Logo
* 
*    Rev 1.12   20 Mar 1999 18:52:34   tmielke
* v1.3
* 
*    Rev 1.11   18 Mar 1999 13:27:34   tmielke
* v0.8 - Demoversion fertig gemacht
* 
*    Rev 1.10   03 Mar 1999 18:15:30   tmielke
* v0.6
* 
*    Rev 1.9   03 Mar 1999 16:38:34   tmielke
* Exception handling läuft in der Debug-Version
* 
*    Rev 1.8   03 Mar 1999 13:40:24   tmielke
* Version Label v0.6
* 
*    Rev 1.7   03 Mar 1999 13:39:30   tmielke
* mysteriösen CODEC-Deselect bug beseitigt.
* SaveReg() bei WM_CLOSE über KillActive sichergestellt.
* Kleinigkeiten.
* 
*    Rev 1.6   03 Mar 1999 10:51:58   tmielke
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
*    Rev 1.6   02 Mar 1999 09:18:46   tmielke
* Lustig: mit Resource-Ausleser!
* 
*    Rev 1.5   01 Mar 1999 12:47:04   tmielke
* Indexdatei eingebaut, Gesprächspartner & Notizen, Gesprächslänge...
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

#include "stdafx.h"

#include "TelAr.h"

// new MFC stuff from expansion pack
// (new visual studio style):
//#include "MainFrm.h"
//#include "TelarDoc.h"
//#include "TelarView.h"

// classic property sheet style:
#include "TelArPropertySheet.h"

#include "GetProgramVersion.h"
#include "crypt.h"
//#include "shlobj.h" -- better use shfolder.dll !!!
#include <shlobj.h>
#include "mmsystem.h"
#include "wavein\wavein.h"
#include "DetectSMC.h"
#include "SelectDeviceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// einige eXterne Variablen:
char  X_path[1000] = "C:\\\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_local_path[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_local_path_subfolder[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_connect_string[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_main_archive_path[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
int   X_aufnahmegeraet = 0;
int   X_samplingrate = 8000;
int   X_kanaele = 1;
int   X_aufloesung = 16;
char  X_codec[1000] = "Microsoft CCITT G.711\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
DWORD_PTR X_codec_id;
DWORD_PTR X_format;
DWORD_PTR X_format_wfx;
int   X_anschluss;
DWORD X_volume;
int   X_modus;
int   X_intelligent;
int   X_ControlToneChannel;
char  X_initialen[3] = "\0\0";
char  X_passwort[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_master_passwort[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
int   X_passes;
int   X_vergroessern_bei_pegel;
BOOL  X_minimize_after;
int   X_schwellwert = 15;
int   X_toggle_noise = 1;
int   X_toggle_silence = 8;
time_t X_installationsdatum;
char  X_SuchfilterGespraechspartner[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_SuchfilterIdentifikation[3]; 
char  X_SuchfilterNotizen[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_SuchfilterDatumVon[20] = "\0\0\0\0\0\0\0\0\0\0";
char  X_SuchfilterDatumBis[20] = "\0\0\0\0\0\0\0\0\0\0";
char  X_SuchfilterZeitVon[20] = "\0\0\0\0\0\0\0\0\0\0";
char  X_SuchfilterZeitBis[20] = "\0\0\0\0\0\0\0\0\0\0";
char  X_SuchfilterMinDauer[20] = "\0\0\0\0\0\0\0\0\0\0";
char  X_SuchfilterMaxDauer[20] = "\0\0\0\0\0\0\0\0\0\0";
char  X_LicenseKey[200] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_NPLK[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
BOOL  X_Locked;
BOOL  X_NPLKTrial;
BOOL  X_NPLKTrialExpired = FALSE;
int   X_Nichtbeachtung;
int   X_AutomatischLoeschen;
int   X_alc;
int   X_nomixer;
char  X_ConfigData[200] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_rqk[200] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
int   X_nosave2profile;
char  X_windowpos[100] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_sense_caller[200] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_sense_called[200] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_sense_extension[200] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

//___ pseudo X_ setings
BOOL  X_MessageShownOnce = FALSE;
BOOL  X_InitialSelection = FALSE;
char  X_aufnahmegeraetname[1000] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char  X_ClientLicenseKey[200] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
BOOL  X_RecordingDisabled = FALSE;

//___ global variables ___
char  G_CurrentPath[1000];


/////////////////////////////////////////////////////////////////////////////
// Sense Stuff
void SenseErrorCb(const char* callid, long party, long reason)
{
#ifdef SENSE 
	CString msg;
	msg.Format("callback function (%lx, %ld, %s)", reason, party, callid);
	if (!SenseError(msg.GetBuffer(0), reason))
	{
		AfxMessageBox(msg);
		DF1("Unrecognized sense error -- %s", msg.GetBuffer(0));
	}
#endif
}

void SetSenseCallbacks()
{
#ifdef SENSE 
	set_error(SenseErrorCb);
#endif
}

long Reconnect2SenseServer(char *buffer)	// buffer contaions the 'url' to the sense server
{
#ifdef SENSE 
	destroy();	// if path changed, disconnect before reconnect with new location

	char host[1000];
	char port[100];
	char *cp;

	strcpy(host, buffer+8);
	if (cp = strchr(host, ':'))
	{
		*cp = '\0';
		strcpy(port, cp+1);
	}
	else
		strcpy(port, "9803");

	long result = connectToServer(host, port, "", "");
	return result;
#else
	return 0L;
#endif
}

BOOL SenseError(char *function, DWORD dw)
{
	BOOL bReturn = TRUE;
	char *errmsg;

	switch (dw)
	{
	case IVRERR_UNKNOWN_ERROR: errmsg = "An error occured but its reason is unknown"; break;
	case IVRERR_INVALID_CALLID: errmsg = "The callid does not exist."; break;
	case IVRERR_INVALID_NUMBER: errmsg = "The phone number is illeagal."; break;
	case IVRERR_BUSY: errmsg = "Server is busy."; break;
	case IVRERR_TIMEOUT: errmsg = "The request has timed out."; break;
	case IVRERR_BUFFER_OVERFLOW: errmsg = "Overflow."; break;
	case IVRERR_FILE_NAME: errmsg = "Invalid file name"; break;
	case IVRERR_FILE_ACCESS: errmsg = "File open/create/close failed."; break;
	case IVRERR_FILE_IO: errmsg = "File read/write error."; break;
	case IVRERR_CS_LOST: errmsg = "The CS stopped communicating with the PC."; break;
	case IVRERR_EXCEPTION: errmsg = "An exception of unknown type occured."; break;
	case IVRERR_LAYER1: errmsg = "ISDN Layer 1 is down."; break;
	case IVRERR_LAYER2: errmsg = "ISDN Layer 2 is down."; break;
	case IVRERR_CONNECT_FAILED: errmsg = "Connection to IVRLLA server failed."; break;
	case IVRERR_LOW_DISK_SPACE: errmsg = "Disk space is too low."; break;
	case IVRERR_BAD_FORMAT: errmsg = "Bad format."; break;
	case IVRERR_NO_BANDWIDTH: errmsg = "Not enough bandwidth."; break;
	case IVRERR_CS_FATAL: errmsg = "The CS encountered a non recoverable error."; break;
	case IVRERR_FILE_PERMANENTLY_DELETED: errmsg = "File intentionally deleted by the system. "; break;
	case IVRERR_INVALID_NAME: errmsg = "The requested object name was not found."; break;
	case IVRERR_BACKUP_DISK_FULL: errmsg = "Back up Disk is full."; break;
	case IVRERR_NOT_SUPPORTED_OPERATION: errmsg = "IVR don't support the required operation."; break;
	case IVRERR_INVALID_PARAMETER: errmsg = "Invalid parameter sent to API."; break;
	case IVRERR_INVALID_OPERATION: errmsg = "Invalid operation, out of sync operation."; break;
	case IVRERR_ACTIVE: errmsg = "Audio already playing for this connection or segment already recording for this connection."; break;
	case IVRERR_INACTIVE: errmsg = "Stop: Audio already inactive for this connection."; break;
	case IVRERR_PROGRESSING: errmsg = "Cconnection is in Alerting or Progressing state"; break;
	case IVRERR_CONNECTED: errmsg = "Connection is in Connected state"; break;
	case IVRERR_DISCONNECTED: errmsg = "Connection is in Disconnected state"; break;
	case IVRERR_NON_INTERCEPTABLE: errmsg = "This call may not be intercepted or played audio."; break;
	case IVRERR_NO_ACCEPT_OUTGOING: errmsg = "Outgoing calls can not be accepted by IVRLLA because they are accepted by Vps according to local interception rules."; break;
	case 0xd100019: errmsg = "The Sense server storage disk is full. Calls will be deleted!"; break;
	case 0xd100021: errmsg = "The Sense server has been restarted."; break;
default:
	bReturn = FALSE;
	}

	if (bReturn)
	{
		CString csMsg = "Sense error in call to '" + (CString)function + ": " + (CString)errmsg;
		DF1("Sense Error: '%s'", csMsg.GetBuffer(0));
		AfxMessageBox(csMsg);
	}
	else
		DF2("Sense call to '%s' returned %lx", function, dw);

	return bReturn;
}



/////////////////////////////////////////////////////////////////////////////
// CTelArApp

BEGIN_MESSAGE_MAP(CTelArApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CTelArApp::OnAppAbout)
	// Standard file based document commands
	// Standard print setup command
	//{{AFX_MSG_MAP(CTelArApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTelArApp construction

CTelArApp::CTelArApp()
{
	EnableHtmlHelp();

	m_bHiColorIcons = TRUE;

	m_pPropFrame = NULL;
	hLanguageDLL = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTelArApp object

CTelArApp theApp;

/////////////////////////////////////////////////////////////////////////////
// The one and only TMTabelle object

TMTabelle theTabelle(INDEX_FILEMAGIC, INDEX_FILECOLUMNS, INDEX_FILEVERSION);

/////////////////////////////////////////////////////////////////////////////
// CTelArApp initialization

char version_string[50];
char build_string[50];

#ifdef DEBUGFILE
void CTelArApp::DebugFile(char *s)
{
	if (pDebugFile)
	{
		char buffer[1000];
		char buffer2[1000];
		CTime now = now.GetCurrentTime();                           
		sprintf(buffer, "%02d:%02d:%02d - ", now.GetHour(), now.GetMinute(), now.GetSecond());
		strcpy(buffer2, "\r\n");
		strcat(buffer2, buffer);
		if (strlen(s) < 980)
			strcat(buffer2, s);
		else
		{
			strncat(buffer2, s, 980);
			s[980] = '\0';
		}
		pDebugFile->Write(buffer2, (UINT)strlen(buffer2));
	}
}
#endif

// store operating system specific info here
OSVERSIONINFOEX osvi;
BOOL bOsVersionInfoEx = FALSE;	// true if info has been retreived
HINSTANCE hSCRVistaHelper = NULL;
char C_CommonAppDataPath[1000];

BOOL CTelArApp::InitInstance()
{
	ppropSheet = NULL;
	pLockingFile = NULL;
#ifdef DEBUGFILE
	pDebugFile = NULL;
#endif

    if (!SUCCEEDED(CoInitialize(NULL)))
    {
		AfxMessageBox("CoInitializeEx failed");
        return 0;
    }
//return TRUE;
	// Check if running in compatibility mode
	{
		HKEY hkcu;
		char path[1000];
		char compatibility[1000];
		char compatibility_long[1000] = "";
		RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers", &hkcu);
		if (hkcu)
		{
			DWORD dw = GetModuleFileName(m_hInstance, path, sizeof(path));
			if (QueryKey(hkcu, NULL, path, compatibility, sizeof(compatibility)) == ERROR_SUCCESS)
			{
				if (!strcmp(compatibility, "WIN95")) strcpy(compatibility_long, "Windows 95");
				else if (!strcmp(compatibility, "WIN98")) strcpy(compatibility_long, "Windows 98 / Windows Me");
				else if (!strcmp(compatibility, "NT4SP5")) strcpy(compatibility_long, "Windows NT 4.0 (Service Pack 5)");
				else if (!strcmp(compatibility, "WIN2000")) strcpy(compatibility_long, "Windows 2000");
				else if (!strcmp(compatibility, "WINXPSP2")) strcpy(compatibility_long, "Windows XP (Service Pack 2)");
				else if (!strcmp(compatibility, "WINXPSP3")) strcpy(compatibility_long, "Windows XP (Service Pack 3)");
				else if (!strcmp(compatibility, "WINSRV03SP1")) strcpy(compatibility_long, "Windows Server 2003 (Service Pack 1)");

				if (*compatibility_long)
				{
					char message[1000] = "The Software Call Recorder is currently running in ";
					strcat(message, compatibility_long);
					strcat(message, " compatibility mode. This will most certainly keep the software from working properly. To switch off the compatibility mode find '");
					strcat(message, path);
					strcat(message, "' using Explorer, right click on the executable file, select Properties, change to the Compatibility tab, and uncheck the compatibility mode checkbox.");
					::MessageBox(NULL, message, "Software Call Recorder", IDOK);
					RegCloseKey(hkcu);
					return FALSE;
				}
			}
		}

		if (hkcu) RegCloseKey(hkcu);
	}

#ifdef TAPI
    if (S_OK != m_Tapi.Initialize())
    {
        //return 0; -- it's ok, we can live without TAPI...
		;
    }
#endif

	//SetDialogBkColor(RGB(198, 195, 198),RGB(0, 0, 0));

	// read info about operating system
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(osvi);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO *)&osvi);

	// directory to store application data in, such as logs
	if (VISTA_RUNNING)	// Windows Vista and beyond? Get common app directory
	{
		*C_CommonAppDataPath = '\0';
		if (!(hSCRVistaHelper = LoadLibrary("SCRVistaHelper")))
			AfxMessageBox("Wasn't able to call GetCommonAppDataPath of the SCRVistaHelper DLL.", MB_ICONSTOP);
		else
		{
			BOOL (__cdecl *pGetCommonAppDataPath)(char *);
			pGetCommonAppDataPath = (BOOL (__cdecl *)(char *))GetProcAddress(hSCRVistaHelper, "GetCommonAppDataPath");
			if (pGetCommonAppDataPath) 
			{
				if (!(*pGetCommonAppDataPath)(C_CommonAppDataPath))
				{
					AfxMessageBox("Error retrieving application data directory.", MB_ICONSTOP);
					AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0L);
				}
			}
			else
				AfxMessageBox("Wasn't able to call GetCommonAppDataPath of the SCRVistaHelper DLL.", MB_ICONSTOP);
		}
	}
	else	// os before Vista: USE program directory
	{
		HINSTANCE hmod = GetModuleHandle("TELAR.EXE");
		DWORD dw = GetModuleFileName(hmod, C_CommonAppDataPath, sizeof(C_CommonAppDataPath));
		char *cp;
		if (!dw || !(cp =strrchr(C_CommonAppDataPath, '\\')))
		{
			AfxMessageBox("Error retrieving application directory.", MB_ICONSTOP);
			AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0L);
		}
		else
			*cp = '\0';
	}

#ifdef DEBUGFILE
	BOOL bNewLogStarted = FALSE;
	pLockingFile = NULL;

	pDebugFile = new CFile;
	if (pDebugFile)
	{
		char filebuffer[1000];
		char *cp = NULL;

		strcpy(filebuffer, C_CommonAppDataPath);			// directory for app data
		cp = filebuffer + strlen(filebuffer);				// find end
		if (cp)
		{
			CTime now = now.GetCurrentTime();  
			sprintf(cp, "\\log%02d.txt", now.GetDay());		// append log filename

			if (!pDebugFile->Open(filebuffer, CFile::modeNoTruncate|CFile::modeWrite|CFile::modeCreate))
			{
				delete pDebugFile;
				pDebugFile = NULL;
			}
			else
			{
				FILETIME CreationTime;
				FILETIME LastAccessTime;
				FILETIME LastWriteTime;

				// Inhalt der log datei löschen wenn ein Monat um ist
				if (GetFileTime((HANDLE)pDebugFile->m_hFile, &CreationTime, &LastAccessTime, &LastWriteTime))
				{
					CTime ft = CTime(LastWriteTime);
					if (now - ft > CTimeSpan(20, 0, 0, 0))	// min. 20 Tage alt?
					{
						pDebugFile->SetLength(0L);
						bNewLogStarted = TRUE;
					}
				}

				pDebugFile->SeekToEnd();
					
				ULONGLONG dw = pDebugFile->GetLength();
				if (!dw)	// neue Datei begonnen? dann Systeminformation rausschmeißen
				{				
					DF("==== SYSTEM INFORMATION ====");
					DF("");

					if (bOsVersionInfoEx)
					{
						switch (osvi.dwPlatformId) 
						{

						   case VER_PLATFORM_WIN32_NT:

							  DF("Microsoft Windows NT");
							  break;

						   case VER_PLATFORM_WIN32_WINDOWS:

							  if	  (osvi.dwMajorVersion == 8) { DF("Microsoft Windows 8") }  // if (osvi.dwMinorVersion == 0)
							  else if (osvi.dwMajorVersion == 7) { DF("Microsoft Windows 7") }  // if (osvi.dwMinorVersion == 0)
							  else if (osvi.dwMajorVersion == 6) { DF("Microsoft Windows Vista") }  // if (osvi.dwMinorVersion == 0)
							  else if (osvi.dwMajorVersion == 5) { if (osvi.dwMinorVersion == 0) DF("Microsoft Windows 2000") else { if (osvi.dwMinorVersion == 1) DF("Microsoft Windows XP") else DF("Microsoft Windows 2003 Server") } }
							  else if (osvi.dwMajorVersion == 4) { if (osvi.dwMinorVersion == 0) DF("Microsoft Windows 95") else DF("Microsoft Windows 98") }
							  break;

						   case VER_PLATFORM_WIN32s:

							  DF("Microsoft Win32s")
							  break;
						}

						DF3("version %d.%d (Build %d)",
							osvi.dwMajorVersion, 
							osvi.dwMinorVersion, 
							osvi.dwBuildNumber & 0xFFFF)

						if (bOsVersionInfoEx)
							DF2("Service Pack %d.%d", 
								osvi.wServicePackMajor, 
								osvi.wServicePackMinor)
 


						DF("")
					}
				}
			}
		}
	}
#endif

	// move Telar.dat to common app folder, if not already there
	{
		char oldFoldersFileLocation[1000];
		char newFoldersFileLocation[1000];
		if (GetFoldersFileNameOld(oldFoldersFileLocation, sizeof(oldFoldersFileLocation)))
		{
			if (GetFoldersFileName(newFoldersFileLocation, sizeof(oldFoldersFileLocation)))
			{
				CFile cf;
				if (!cf.Open(newFoldersFileLocation, CFile::modeRead))
				{
					DF("Trying to move the folders file Telar.dat to the common apps folder..."); 
					if (CopyFile(oldFoldersFileLocation, newFoldersFileLocation, TRUE))
					{
						if (DeleteFile(oldFoldersFileLocation))
							DF("... succeeded!")
						else
							DF1("DeleteFile(%s) failed.", oldFoldersFileLocation); 
					}
					else
						DF2("CopyFile(%s -> %s) failed.", oldFoldersFileLocation, newFoldersFileLocation); 
				}
			}
			else
				DF("GetFoldersFileName() failed."); 
		}
		else
			DF("GetFoldersFileNameOld() failed."); 
	}
	if (!(hLanguageDLL = LoadLibrary("TELARLNG.DLL")))
	{
		AfxMessageBox("Could not load TELARLNG.DLL");
		return FALSE;
	}

	if (!(hVendorDLL = LoadLibrary("TELARVND.DLL")))
	{
		AfxMessageBox("Could not load TELARVND.DLL");
		return FALSE;
	}

    if (!AfxOleInit())
    {
        AfxMessageBox("Ole Initialization Failed");
        return FALSE;
    }

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	//InitCtrls.dwICC = ICC_WIN95_CLASSES;
	//InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	LoadStringConstants();

	// schon eine andere Instanz von TelAr am Laufen?
	{
		int i, j, k;
		char *lkp;

		static char *laenderkuerzel[] = { "", "D", "GB", "CZ", "NL", "PL", "E" }; 
		int lk_count = sizeof(laenderkuerzel) / sizeof(laenderkuerzel[0]);

		for (i = 0; i < 3; i++)
		{
			for (j = 100; j < 300; j++)
			{

				for (k = 0; k < lk_count; k++)
				{
					char buffer[100];
					char buffer2[100];
					VEND2BUFFER(IDS_STRING6, buffer2);
					strcat(buffer2, " ");
					switch (i)
					{
					case 0:
						LoadString(GetModuleHandle("TELAR.EXE"), IDS_TITEL, buffer2+strlen(buffer2), sizeof(buffer2)); break;
					case 1:
						LoadString(GetModuleHandle("TELAR.EXE"), IDS_TITEL2, buffer2+strlen(buffer2), sizeof(buffer2)); break;
					case 2:
						LoadString(GetModuleHandle("TELAR.EXE"), IDS_TITEL3, buffer2+strlen(buffer2), sizeof(buffer2)); break;
					}
					strcat(buffer2, " v%d.%02d (%s)");
					if (!k) lkp = C_language; else lkp = laenderkuerzel[k];
					sprintf(buffer, buffer2, j / 100, j % 100, lkp);
					HWND hWndFind = FindWindow(NULL, buffer);
					if (hWndFind)
					{
						PostMessage(hWndFind, WM_COMMAND, IDC_RETELLSCR_NORMALIZE_WINDOW, 0L);
						DF("Found an instance of the software already running: restoring that window and exiting now.");
						return TRUE;
					}
				}
			}
		}
	}

	// If both autostart keys are set, delete one and stop one instance
	{
		HKEY hklm;
		HKEY hkcu;
		char hklm_autostart_path[1000];
		char hkcu_autostart_path[1000];
		RegOpenKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hklm);
		RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkcu);
		if (hklm && hkcu)
		{
			if (QueryKey(hklm, NULL, "TelAr", hklm_autostart_path, sizeof(hklm_autostart_path)) == ERROR_SUCCESS
				&& QueryKey(hkcu, NULL, "TelAr", hkcu_autostart_path, sizeof(hkcu_autostart_path)) == ERROR_SUCCESS)
			{
				strcat(hklm_autostart_path, ".lock");
				TRY
				{
					pLockingFile = new CFile(hklm_autostart_path, CFile::modeCreate|CFile::modeWrite|CFile::shareExclusive);
				}
				CATCH( CFileException, e )
				{	// I lost :(
					pLockingFile = NULL;
					if (hkcu) RegCloseKey(hkcu);
					if (hklm) RegCloseKey(hklm);
					DF("Another instance of the software is currently starting up: exiting now.");
					return TRUE;	// close instance
				}
				END_CATCH
			}
		}
		if (hkcu) RegCloseKey(hkcu);
		if (hklm) RegCloseKey(hklm);
	}

	//char buffer[1000];
	//HMODULE nMod = LoadLibrary("TELAR.EXE");
	//HRSRC hRes = FindResourceEx(hExe, (char *)16, (char *)2, 0x0407);
	//HGLOBAL hGlobal = LoadResource(nMod, hRes);
	//char *cp = (char *)LockResource(hGlobal);
	//DWORD dw = GetLastError();
	//int n = LoadString(m_hInstance, VS_VERSION_INFO, buffer, sizeof(buffer));

	// Version abholen
	{
		HMODULE hExe = GetModuleHandle("TELAR.EXE");
		VS_FIXEDFILEINFO vs_ffi;
		if (hExe) 
		{
			GetProgramVerion(hExe, &vs_ffi);	// version_string := "v2.0" oder so ähnlich
			sprintf(version_string, "v%0lu.%0lu", vs_ffi.dwProductVersionMS >> 16, vs_ffi.dwProductVersionMS & 0xffff);
			sprintf(build_string, "build %lu", vs_ffi.dwProductVersionLS  & 0xffff);
			DF("");
			DF2("SCR version number: %s %s", version_string, build_string);
		}
		else 
			*version_string = '\0';
	}
	
	DF("");
	DF("--- NEW SESSION ---");
	DF("");

	DSASetModule(hLanguageDLL);
	DSASetRegKey("SOFTWARE\\TRS\\TelAr");

	SetSenseCallbacks();

	ReadReg();

	AfxEnableControlContainer();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	// SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	// LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)

// new MFC stuff from expansion pack
//	InitContextMenuManager();
//	InitShellManager();
//	InitKeyboardManager();
//	InitTooltipManager();
//	CMFCToolTipInfo ttParams;
//	ttParams.m_bVislManagerTheme = TRUE;
//	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
//		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
/*	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTelarDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CTelarView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_HIDE);
	m_pMainWnd->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand
	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();
*/
	OnProperties();
	
	DF("CTelArApp::InitInstance exited normally.");
	return TRUE;
}


// App command to run the dialog
void CTelArApp::OnAppAbout()
{
	CAboutDlg aboutDlg("Retell Software Call Recorder");
	aboutDlg.DoModal();
}


void CTelArApp::OnProperties()
{
	try
	{
		ppropSheet = new CTelArPropertySheet(IDS_TITEL, NULL, 3);
		m_pMainWnd = ppropSheet;
		if (0 == ppropSheet->Create(NULL, WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_POPUP | WS_CAPTION | DS_MODALFRAME, WS_EX_DLGMODALFRAME))
			throw "propSheet.DoModal() failed!";
	}
	catch(char * str)
	{
		//AfxMessageBox(str);
#ifdef _DEBUG
		TRACE ("str Exception thrown: %s\n", str);
#else
		str;
#endif
	}
	catch( CException* e )
	{
		char buffer[1000];
		e->GetErrorMessage(buffer, sizeof(buffer));
		TRACE ("CException thrown: %s\n", buffer);
		e->Delete();
	}
}


/*
void CTelArApp::OnProperties()
{
	// If mini frame does not already exist, create a new one.
	// Otherwise, unhide it
	if (m_pPropFrame == NULL)
	{
		m_pPropFrame = new CTelArPropSheetFrame;
		CRect rect(0, 0, 0, 0);
		CString strTitle;
		VERIFY(strTitle.LoadString(IDS_TITEL));

		// TODO: Warning: Your base class isn't a CWnd type
		// so the menu will be created with a parent HWND of NULL.
		if (!m_pPropFrame->Create(NULL, strTitle,
			WS_POPUP | WS_CAPTION | WS_SYSMENU, rect))
		{
			delete m_pPropFrame;
			m_pPropFrame = NULL;
			return;
		}
		m_pPropFrame->CenterWindow();
	}

	// Before unhiding the modeless property sheet, update its
	// settings appropriately.  For example, if you are reflecting
	// the state of the currently selected item, pick up that
	// information from the active view and change the property
	// sheet settings now.

	if (m_pPropFrame != NULL && !m_pPropFrame->IsWindowVisible())
	{
		m_pMainWnd = m_pPropFrame;
	}
}
*/

int CTelArApp::ExitInstance() 
{
	if (pLockingFile)
	{
		HKEY hkcu;

		RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkcu);
		if (hkcu)
		{
			RegDeleteValue(hkcu, "TelAr");
			RegCloseKey(hkcu);
		}

		CString csFName = pLockingFile->GetFileName();
		pLockingFile->Close();
		pLockingFile = NULL;
		DeleteFile(csFName);
	}

	if (ppropSheet) delete ppropSheet;

	if (hLanguageDLL) FreeLibrary(hLanguageDLL);
	if (hVendorDLL) FreeLibrary(hVendorDLL);

#ifdef DEBUGFILE
	if (pDebugFile)
	{
		pDebugFile->Close();
		delete pDebugFile;
		pDebugFile = NULL;
	}
#endif

	if (VISTA_RUNNING)	
	{
		FreeLibrary(hSCRVistaHelper);
	}

#ifdef TAPI
	m_Tapi.Shutdown();
#endif

	CoUninitialize();

	_CrtDumpMemoryLeaks();

	return CWinApp::ExitInstance();
}

BOOL CTelArApp::GetIniFileName(char *buffer3, int size)
{
	if (!strlen(C_CommonAppDataPath)) return FALSE;
	strncpy(buffer3, C_CommonAppDataPath, size-11);
	buffer3[size-11] = '\0';
	if (buffer3[strlen(buffer3)-1] != '\\') strcat(buffer3, "\\");
	strcat(buffer3, "Telar.ini");
	return TRUE;
}

BOOL CTelArApp::GetIniFileNameOld(char *buffer3, int size)
{
	char *cp;

	DWORD dw = GetModuleFileName(m_hInstance, buffer3, size);
	for (cp = buffer3+strlen(buffer3)-3; *cp; cp++)
		*cp = tolower(*cp);
	if (!strcmp(buffer3+strlen(buffer3)-3, "exe"))
	{
		strcpy(buffer3+strlen(buffer3)-3, "ini");
		return TRUE;
	}
	else
		return FALSE;
}

BOOL CTelArApp::GetFoldersFileName(char *filename, int size)
{
	GetIniFileName(filename, size);
	if (!strcmp(filename+strlen(filename)-3, "ini"))
	{
		strcpy(filename+strlen(filename)-3, "dat");
		return TRUE;
	}
	else
		return FALSE;
}

BOOL CTelArApp::GetFoldersFileNameOld(char *filename, int size)
{
	GetIniFileNameOld(filename, size);
	if (!strcmp(filename+strlen(filename)-3, "ini"))
	{
		strcpy(filename+strlen(filename)-3, "dat");
		return TRUE;
	}
	else
		return FALSE;
}

//--- Registry Werte speichern/lesen -----

long QueryKey(HKEY hklm, HKEY hkcu, char *valuename, char *data, long datasize)
{
	long lMaxBuffersize = datasize;
	long lRetCode = ERROR_SUCCESS;
	long lDummy;
	long lType = REG_SZ;
	long lCb;
	lDummy = 0L;

	// first try to read settings for current user
	if (hkcu)
	{
		*data = '\0';
		lCb = datasize;
		lRetCode = RegQueryValueEx(hkcu, valuename, 
								   NULL, (ULONG *)&lType, 
								   (LPBYTE)data, (ULONG *)&lCb);

		// only accept string data type
		if (lRetCode == ERROR_SUCCESS && lType != REG_SZ) lRetCode = ERROR_INVALID_DATATYPE;
	}

	// if there are none, try to read machine wide default settings
	if (!hkcu || lRetCode != ERROR_SUCCESS)
		if (hklm)
		{
			*data = '\0';
			lCb = datasize;
			lRetCode = RegQueryValueEx(hklm, valuename, 
									   NULL, (ULONG *)&lType, 
									   (LPBYTE)data, (ULONG *)&lCb);

			// only accept string data type
			if (lRetCode == ERROR_SUCCESS && lType != REG_SZ) lRetCode = ERROR_INVALID_DATATYPE;
		}

	if (lRetCode == ERROR_SUCCESS && lType != REG_SZ) 
	{
		if (lCb < lMaxBuffersize)
			data[lCb] = '\0';
		else
			data[lMaxBuffersize-1] = '\0';
	}

	DF3("%s = '%s' -- return code: %ld", valuename, !strcmp(valuename, "Passwort")||!strcmp(valuename, "MasterPasswort") ? "*****" : data, lRetCode)

	return lRetCode;
}

static int S_masterpassword_seed1 = -1;
static int S_masterpassword_seed2 = -1;

void ReadReg()
{
	char buffer2[1000];
    HKEY hklm;
    HKEY hkcu;
	*buffer2 = '\0';

	// try HKEY_LOCAL_MACHINE
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\TRS\\TelAr", 0L, KEY_READ, &hklm) != ERROR_SUCCESS)
	{
		hklm = NULL;
	}

	// HKEY_CURRENT_USER
	if (RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\TRS\\TelAr", &hkcu) != ERROR_SUCCESS)
	{
		// give up
		DF("ReadReg::RegCreateKey(HKEY_CURRENT_USER) failed.")
		if (hklm) RegCloseKey(hklm);
		return;
	}

	DF("")
	DF("___ Reading SCR settings ___")

	{
		long lRetCode, lDummy;
		long lType = REG_SZ;
		long lCb = sizeof(buffer2);
		lDummy = 0L;
	
		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "Path", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "C:\\");
			HRESULT hRes = SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, NULL, buffer2);	// früher: CSIDL_DESKTOP (root) jetzt: CSIDL_PERSONAL

			char TitleBuffer[200];
			LANG2BUFFER(IDS_STRING51, TitleBuffer);
			CXFolderDialog dlg(buffer2);
			dlg.SetOsVersion(CXFolderDialog::XFILEDIALOG_AUTO_DETECT_OS_VERSION);
			dlg.SetTitle(TitleBuffer);
			if (dlg.DoModal() == IDOK)
			{
    			CString csTemp = dlg.GetPath();
				strcpy(buffer2, csTemp.GetBuffer(0));				
			}
		}
		strcpy(X_path, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "local_path", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_local_path, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "local_path_subfolder", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_local_path_subfolder, buffer2);

		// X_path override if hklm local_path is set
		if (*X_local_path)
		{
			if (X_local_path[strlen(X_local_path)-1] == '\\') X_local_path[strlen(X_local_path)-1] = '\0';
			strcpy(X_path, X_local_path);
			strcat(X_path, "\\");
			strcat(X_path, X_local_path_subfolder);
		}

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "connect_string", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_connect_string, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "MainArchivePath", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_main_archive_path, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "Aufnahmegeraet", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
			X_aufnahmegeraet = 0;
			
			int n;
			if (!(n = waveInGetNumDevs()))
			{
				LANG_MESSAGEBOX1(IDS_STRING153);
			}
			else
			{
				if (n > 1)
				{
					CSelectDeviceDlg dlg;
					if (dlg.DoModal() == IDOK) 
					{
						X_aufnahmegeraet = dlg.m_liste;
						X_InitialSelection = TRUE;
					}
				}
			}

		}
		else
			X_aufnahmegeraet = atoi(buffer2);
		
		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "Aufnahmegeraetname", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_aufnahmegeraetname, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "Samplingrate", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "8000");
		}
		X_samplingrate = atoi(buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "CODEC", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "Microsoft CCITT G.711");
		}
		strcpy(X_codec, buffer2);

		lRetCode = QueryKey(hklm, NULL, "SubFormat", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_format = atoi(buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "Anschluss", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "-1");
		}
		X_anschluss = atoi(buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "Volume", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "32767");
		}
		X_volume = atoi(buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "Modus", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_modus = atoi(buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "alc", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "1");
		}
		X_alc = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "Intelligent", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "-1");
		}
		X_intelligent = atoi(buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "ControlToneChannel", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_ControlToneChannel = atoi(buffer2);

		// nur einmal am Anfang der Installation auf IRI checken
		if (X_intelligent == -1)
		{
			WaveIn_SetALC(FALSE); // konfigurierbar machen!!!!
			CDetectSMC dlg;
			if (dlg.DoModal() != IDOK)
			{
				X_intelligent = 0;
				WaveIn_SetALC(X_alc);
				LANG_MESSAGEBOX1(IDS_STRING163);
			}
			else
			{
				X_intelligent = 1;
				WaveIn_SetALC(FALSE);
			}
		}
		else if (X_intelligent == 1)
		{
			WaveIn_SetControlToneChannel(X_ControlToneChannel);
			WaveIn_SetControlTone(TRUE);
			WaveIn_SetALC(FALSE);
		}
		else
		{
			WaveIn_SetALC(X_alc);
			WaveIn_SetControlTone(FALSE);
		}

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "Initialen", buffer2, sizeof(buffer2));
		if (!strcmp(C_vendor, "PhoneCoach CompuCorder"))
		{
			strcpy(buffer2, "PC");
		}
		else if (lRetCode != ERROR_SUCCESS)
		{
			// 1. Versuch: der reguläre Username
			DWORD dwSize = sizeof(buffer2);
			char *cp;
			if (!GetUserName(buffer2, &dwSize)) *buffer2 = '\0';

			// 2. Versuch: der Username von der Windows-Installation
			if (!*buffer2)
			{
				HKEY hKey2;
				*buffer2 = '\0';
				strcpy(buffer2, "");
				if (RegOpenKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion", &hKey2) == ERROR_SUCCESS)
				{
					*buffer2 = '\0';
					lCb = sizeof(buffer2);
					lRetCode = RegQueryValueEx(hKey2, TEXT("RegisteredOwner"), 
											   NULL, (ULONG *)&lType, 
											   (LPBYTE)buffer2, (ULONG *)&lCb);
					if (lRetCode != ERROR_SUCCESS) *buffer2 = '\0';
					RegCloseKey(hKey2);
				}
				else
					*buffer2 = '\0';
			}

			// mit dem, was wir jetzt haben, die Initialen erstellen
			if (*buffer2)
			{
				BOOL bIsOK = FALSE;
				if (strlen(buffer2) == 2)	// 1. Versuch
				{
					if (isalpha(*buffer2) && isalpha(buffer2[1])) bIsOK = TRUE;
				}
				if (!bIsOK)					// 2. Versuch
				{
					if (isalpha(*buffer2) && (cp = strchr(buffer2, ' ')))
					{
						if (isalpha(cp[1]))
						{
							buffer2[1] = cp[1];
							buffer2[2] = '\0';
							bIsOK = TRUE;
						}
					}
				}
				if (!bIsOK)					// 3. Versuch
				{
					cp = buffer2;
					while(!isalpha(*cp) && *cp)
						cp++;
					if (isalpha(*cp))
					{
						*buffer2 = *cp;
						char *cp2 = cp+1;
						while(!isalpha(*cp2) && *cp2)
							cp2++;
						if (isalpha(*cp2))
							buffer2[1] = *cp2;
						else
							buffer2[1] = 'X';
						bIsOK = TRUE;
					}
					else
					{
						strcpy(buffer2, "XX");	// Aufgeben...
						bIsOK = TRUE;
					}
					buffer2[2] = '\0';
				}
				else
					strcpy(buffer2, "XX");
			}
			else // aufgeben
				strcpy(buffer2, "XX");
		}
		*buffer2 = toupper(*buffer2);
		buffer2[1] = toupper(buffer2[1]);
		strcpy(X_initialen, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "Passwort", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		else
		{
			if (strlen(buffer2) < 10)
				strcpy(buffer2, "");
			else
			{
				char buf1[6], buf2[6], buffer3[1000];
				strncpy(buf1, buffer2, 5); buf1[5] = '\0';
				strncpy(buf2, buffer2+5, 5); buf2[5] = '\0';
				if (DC(atoi(buf1), atoi(buf2), buffer2+10, buffer3))
					strcpy(buffer2, buffer3);
				else
					strcpy(buffer2, "");
			}
		}
		strcpy(X_passwort, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "MasterPasswort", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		else
		{
			if (strlen(buffer2) < 10)
				strcpy(buffer2, "");
			else
			{
				char buf1[6], buf2[6], buffer3[1000];
				strncpy(buf1, buffer2, 5); buf1[5] = '\0';
				strncpy(buf2, buffer2+5, 5); buf2[5] = '\0';
				if (DC(S_masterpassword_seed1 = atoi(buf1), S_masterpassword_seed2 = atoi(buf2), buffer2+10, buffer3))
					strcpy(buffer2, buffer3);
				else
					strcpy(buffer2, "");
			}
		}
		strcpy(X_master_passwort, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "Passes", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "1");
		}
		X_passes = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "Vergroessern_bei_pegel", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "1");
		}
		X_vergroessern_bei_pegel = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, NULL, "minimize_after", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_minimize_after = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "schwellwert", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "5");
		}
		X_schwellwert = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "Toggle_noise", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "1");
		}
		X_toggle_noise = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "Toggle_silence", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "8");
		}
		X_toggle_silence = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterGespraechspartner", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterGespraechspartner, buffer2);
		
		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterIdentifikation", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		buffer2[2] = '\0';
		strcpy(X_SuchfilterIdentifikation, buffer2);
		
		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterNotizen", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterNotizen, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterDatumVon", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterDatumVon, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterDatumBis", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterDatumBis, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterMinDauer", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterMinDauer, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterMaxDauer", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterMaxDauer, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterZeitVon", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterZeitVon, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(NULL, hkcu, "SuchfilterZeitBis", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		strcpy(X_SuchfilterZeitBis, buffer2);

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "Nichtbeachtung", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_Nichtbeachtung = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "AutomatischLoeschen", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_AutomatischLoeschen = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "nomixer", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_nomixer = atoi(buffer2);		

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "nosave2profile", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "0");
		}
		X_nosave2profile = atoi(buffer2);	

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "windowpos", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "");
		}
		buffer2[99] = '\0';
		strcpy(X_windowpos, buffer2);	

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "sense_caller", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "957");
		}
		buffer2[199] = '\0';
		strcpy(X_sense_caller, buffer2);	

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "sense_called", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "957");
		}
		buffer2[199] = '\0';
		strcpy(X_sense_called, buffer2);	

		memset(buffer2, 0x00, sizeof(buffer2));
		lRetCode = QueryKey(hklm, hkcu, "sense_extension", buffer2, sizeof(buffer2));
		if (lRetCode != ERROR_SUCCESS)
		{
			strcpy(buffer2, "957");
		}
		buffer2[199] = '\0';
		strcpy(X_sense_extension, buffer2);	

		RegCloseKey(hkcu);
		if (hklm) RegCloseKey(hklm);
	}

	DF("")
}

static BOOL bAlreadyAsked = FALSE;

long SetKey(HKEY hklm, HKEY hkcu, char *valuename, char *data)
{
	long lRetCode1 = 0L, lRetCode2 = 0L;

	// first try to write machine wide settings
	if (hklm)
	{
		lRetCode1 = RegSetValueEx(hklm,	valuename, 
								(ULONG)0, (ULONG)REG_SZ, 
								(LPBYTE)data, (ULONG)strlen(data)+1);

		// hklm-only value couldn't be stored? Notify to runas Admin!
		if (!hkcu)
		{
			char buffer2[10000];
			QueryKey(hklm, NULL, valuename, buffer2, sizeof(buffer2));
			if (strcmp(buffer2, data))
				if (!bAlreadyAsked)
				{
					char msgbuffer[200];
					LANG2BUFFER(IDS_STRING217, msgbuffer);
					AfxMessageBox(msgbuffer);
					bAlreadyAsked = TRUE;
				}
		}
	}
	// then try to write settings for current user
	if (hkcu)
		lRetCode2 = RegSetValueEx(hkcu,	valuename, 
									(ULONG)0, (ULONG)REG_SZ, 
									(LPBYTE)data, (ULONG)strlen(data)+1);

	DF4("%s = '%s' -- return code (machine wide/user profile): %ld/%ld", valuename, !strcmp(valuename, "Passwort") ? "*****" : data, lRetCode1, lRetCode2)

	return lRetCode2;
}

void SaveReg()
{
	char buffer2[1000];
    HKEY hklm;
    HKEY hkcu;
	
	// try HKEY_LOCAL_MACHINE
	if (RegCreateKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\TRS\\TelAr", &hklm) != ERROR_SUCCESS)
	{
		hklm = NULL;
	}

	// HKEY_CURRENT_USER
	if (!X_nosave2profile)
	{
		if (RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\TRS\\TelAr", &hkcu) != ERROR_SUCCESS)
		{
			// give up
			DF("SaveReg::RegOpenKey(HKEY_CURRENT_USER) failed.")
			if (hklm) RegCloseKey(hklm);
			return;
		}
	}
	else
		hkcu = NULL;		

	DF("")
	DF("___ Writing SCR settings ___")

	SetKey(hklm, hkcu, "Path", X_path);
	SetKey(hklm, NULL, "local_path", X_local_path);
	SetKey(NULL, hkcu, "local_path_subfolder", X_local_path_subfolder);
	SetKey(hklm, hkcu, "connect_string", X_connect_string);

	SetKey(hklm, hkcu, "MainArchivePath", X_main_archive_path);

	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_aufnahmegeraet);
	long lRet = SetKey(hklm, NULL, "Aufnahmegeraet", buffer2);

	SetKey(hklm, hkcu, "Aufnahmegeraetname", X_aufnahmegeraetname);

	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_samplingrate);
	SetKey(hklm, NULL, "Samplingrate", buffer2);

	SetKey(hklm, NULL, "CODEC", X_codec);

	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_format);
	SetKey(hklm, NULL, "SubFormat", buffer2);

	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_anschluss);
	SetKey(hklm, NULL, "Anschluss", buffer2);

	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_volume);
	SetKey(hklm, NULL, "Volume", buffer2);

	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_alc);
	SetKey(hklm, NULL, "alc", buffer2);


	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_modus);
	SetKey(hklm, NULL, "Modus", buffer2);
	
	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_intelligent);
	SetKey(hklm, NULL, "Intelligent", buffer2);
	
	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_ControlToneChannel);
	SetKey(hklm, hkcu, "ControlToneChannel", buffer2);

	SetKey(NULL, hkcu, "Initialen", X_initialen);

	{
		int m = rand() % 31328, n = time( NULL ) % 30081;
		char buffer[1000];
		memset(buffer, 0x00, sizeof(buffer));
		sprintf(buffer, "%05d%05d", m, n);
		EC(m, n, X_passwort, buffer+10);
		
		SetKey(NULL, hkcu, "Passwort", buffer);
	}
	
	{
		int m = S_masterpassword_seed1 >= 0 ? S_masterpassword_seed1 : rand() % 31328, 
			n = S_masterpassword_seed2 >= 0 ? S_masterpassword_seed2 : time( NULL ) % 30081;
		char buffer[1000];
		memset(buffer, 0x00, sizeof(buffer));
		sprintf(buffer, "%05d%05d", m, n);
		EC(m, n, X_master_passwort, buffer+10);
		
		SetKey(hklm, NULL, "MasterPasswort", buffer);
	}

	memset(buffer2, 0x00, sizeof(buffer2));	
	sprintf(buffer2, "%d", X_passes);
	SetKey(hklm, hkcu, "Passes", buffer2);


	memset(buffer2, 0x00, sizeof(buffer2));	
	sprintf(buffer2, "%d", (int)X_vergroessern_bei_pegel);
	SetKey(hklm, hkcu, "Vergroessern_bei_pegel", buffer2);


	memset(buffer2, 0x00, sizeof(buffer2));	
	sprintf(buffer2, "%d", X_minimize_after);
	SetKey(hklm, NULL, "minimize_after", buffer2);


	memset(buffer2, 0x00, sizeof(buffer2));	
	sprintf(buffer2, "%d", X_schwellwert);
	SetKey(hklm, hkcu, "Schwellwert", buffer2);


	memset(buffer2, 0x00, sizeof(buffer2));	
	sprintf(buffer2, "%d", X_toggle_noise);
	SetKey(hklm, hkcu, "Toggle_noise", buffer2);
	
	sprintf(buffer2, "%d", X_toggle_silence);
	SetKey(hklm, hkcu, "Toggle_silence", buffer2);

	SetKey(NULL, hkcu, "SuchfilterGespraechspartner", X_SuchfilterGespraechspartner);

	SetKey(NULL, hkcu, "SuchfilterIdentifikation", X_SuchfilterIdentifikation);

	SetKey(NULL, hkcu, "SuchfilterNotizen", X_SuchfilterNotizen);
	
	SetKey(NULL, hkcu, "SuchfilterDatumVon", X_SuchfilterDatumVon);
	
	SetKey(NULL, hkcu, "SuchfilterDatumBis", X_SuchfilterDatumBis);
	
	SetKey(NULL, hkcu, "SuchfilterZeitVon", X_SuchfilterZeitVon);
	
	SetKey(NULL, hkcu, "SuchfilterZeitBis", X_SuchfilterZeitBis);
	
	SetKey(NULL, hkcu, "SuchfilterMinDauer", X_SuchfilterMinDauer);
	
	SetKey(NULL, hkcu, "SuchfilterMaxDauer", X_SuchfilterMaxDauer);
	

	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_Nichtbeachtung);
	SetKey(hklm, hkcu, "Nichtbeachtung", buffer2);


	memset(buffer2, 0x00, sizeof(buffer2));
	sprintf(buffer2, "%d", X_AutomatischLoeschen);
	SetKey(hklm, hkcu, "AutomatischLoeschen", buffer2);

	SetKey(NULL, hkcu, "windowpos", X_windowpos);

	SetKey(NULL, hkcu, "sense_caller", X_sense_caller);
	SetKey(NULL, hkcu, "sense_called", X_sense_called);
	SetKey(NULL, hkcu, "sense_extension", X_sense_extension);

	if (hkcu) RegCloseKey(hkcu);
	if (hklm) RegCloseKey(hklm);
}

char C_language[50];
char C_vendor[50];
char C_manuelle_aufnahme[50];
char C_automatik_start[50];
char C_aufnahme_beenden[50];
char C_automatik_stop[50];
char C_letzte_aufnahme[50];
char C_standard_ordner[50];
char C_abbrechen[50];
char C_mute_microphone[50];
char C_open_microphone[50];

void CTelArApp::LoadStringConstants()
{
	LANG2BUFFER(IDS_STRING1, C_language);
	VEND2BUFFER(IDS_STRING1, C_vendor);
	LANG2BUFFER(IDS_STRING4, C_manuelle_aufnahme);
	LANG2BUFFER(IDS_STRING5, C_automatik_start);
	LANG2BUFFER(IDS_STRING6, C_aufnahme_beenden);
	LANG2BUFFER(IDS_STRING7, C_automatik_stop);
	LANG2BUFFER(IDS_STRING8, C_letzte_aufnahme);
	LANG2BUFFER(IDS_STRING63, C_standard_ordner);
	LANG2BUFFER(IDS_STRING73, C_abbrechen);
	LANG2BUFFER(IDS_STRING211, C_mute_microphone);
	LANG2BUFFER(IDS_STRING212, C_open_microphone);
	int lang = 0;
	if (!strcmp(C_language, "D")) lang = WAVEIN_LANG_D;
	else if (!strcmp(C_language, "GB")) lang = WAVEIN_LANG_GB;
	else if (!strcmp(C_language, "CZ")) lang = WAVEIN_LANG_CZ;
	else if (!strcmp(C_language, "NL")) lang = WAVEIN_LANG_NL;
	else if (!strcmp(C_language, "PL")) lang = WAVEIN_LANG_PL;
	else if (!strcmp(C_language, "E")) lang = WAVEIN_LANG_E;
	WaveIn_SetLanguage(lang);

	DF("")
}

//--- global CTime helper ---

// returns TRUE if conversion was successful
BOOL String2CTime(CString &date, CString &time, CTime &ct)
{
	if (date.GetLength() != 10) return FALSE;
	
	char *cp = date.GetBuffer(0);
	char *y, *m, *d;

	if (cp[2] == '.' && cp[5] == '.') // german format
	{
		y = cp+6; m = cp+3; d = cp;
	}
	else if (cp[4] == '/' && cp[7] == '/') // english & spanish format
	{
		y = cp; m = cp+5; d = cp+8;
	}
	else return FALSE;

	// Datum richtig?
	if (!isdigit(*y) || !isdigit(y[1]) || !isdigit(y[2]) || !isdigit(y[3])
		|| !isdigit(*m) || !isdigit(m[1])
		|| !isdigit(*d) || !isdigit(d[1]))
			return FALSE;

	int hour, min, sec;

	if (!time.GetLength())
	{
		hour = min = 0;
	}
	else
	{
		if (!isdigit(*time) || !isdigit(time[1]) || time[2]!=':' || !isdigit(time[3]) || !isdigit(time[4])) 
			return FALSE;
		else
		{
			hour = atoi(time);
			min = atoi(time.GetBuffer(0)+3);
			sec = atoi(time.GetBuffer(0)+6);
		}
	}

	ct = CTime(atoi(y), atoi(m), atoi(d), hour, min, sec);
	return TRUE;
}

void ShowLastError(char *operation)
{
#ifdef DEBUGFILE
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
		char buffer[10000];

		if (!X_MessageShownOnce)
		{
			X_MessageShownOnce = TRUE;

			// Display message
			AfxMessageBox("There was some internal problem. Maybe the system became unstable. If this message should show up again after rebooting, please send the current 'logXX.txt' file from the program directory to our technical support and try to describe in detail the circumstances of the incident. (Note: this message only shows up once each time you start the SCR.)", MB_OK|MB_ICONINFORMATION);
		}
		DF("__________")
		strcpy(buffer, operation);
		strcat(buffer, ": ");
		strcat(buffer, (char *)lpMsgBuf);
		DF(buffer);
		DF("^^^^^^^^^^")

		// Free the buffer.
		LocalFree( lpMsgBuf );
	}
#endif
}	

//--- global Bitmap Helper -------

extern void DrawBackgroundBitmap(CDC* pDC, int ResourceBitmapID, RECT *r, BOOL bStretch)
{
	HDC  hdc;
	CDC  *dc;
	CDC dcMem;
	BITMAP bm;
	CBitmap cbm;

	VERIFY(hdc = pDC->m_hDC);
	VERIFY(dc = pDC);

	//----- bitmap anzeigen

	// Create a memory DC for the bitmap.
	dcMem.CreateCompatibleDC(dc);

	// Get the size of the bitmap.
		cbm.LoadBitmap(ResourceBitmapID);
	cbm.GetObject(sizeof(bm), &bm);

	// Select the bitmap into the memory DC.
	CBitmap* pbmOld;
	VERIFY(pbmOld = dcMem.SelectObject(&cbm));

	DWORD sysColor3D = GetSysColor(COLOR_3DFACE);
	for (int x = 0; x < bm.bmWidth; x++)
		for (int y = 0; y < bm.bmHeight; y++)
			if (dcMem.GetPixel(x, y) == RGB(198, 195, 198))
				dcMem.SetPixelV(x, y, sysColor3D);

	// thumbnails: Blt the bitmaps to the screen DC.
	if (bStretch)
		dc->StretchBlt(r->left, r->top,		// Destination
					r->right, r->bottom,	// Destination
					&dcMem,     // Source DC
					0, 0,       // Source
					bm.bmWidth, // Width
					bm.bmHeight,// Height
					SRCCOPY);   // Operation
	else
		dc->BitBlt(r->left, r->top,		// Destination
					//r->right, r->bottom,	// Destination
					bm.bmWidth, // Width
					bm.bmHeight,// Height
					&dcMem,     // Source DC
					0, 0,       // Source
					SRCCOPY);   // Operation

	// Done with memory DC now, so clean up.
	VERIFY(dcMem.SelectObject(pbmOld));
	VERIFY(dcMem.DeleteDC());
}

extern void DrawAndCenterBitmap(CDC* pDC, int ResourceBitmapID, RECT *r)
{
	HDC  hdc;
	CDC  *dc;
	CDC dcMem;
	BITMAP bm;
	CBitmap cbm;

	VERIFY(hdc = pDC->m_hDC);
	VERIFY(dc = pDC);

	//----- bitmap anzeigen

	// Create a memory DC for the bitmap.
	dcMem.CreateCompatibleDC(dc);

	// Get the size of the bitmap.
	cbm.LoadBitmap(ResourceBitmapID);
	cbm.GetObject(sizeof(bm), &bm);

	// Select the bitmap into the memory DC.
	CBitmap* pbmOld;
	VERIFY(pbmOld = dcMem.SelectObject(&cbm));

	// thumbnails: Blt & center the bitmaps to the screen DC.
	int x = r->left+(r->right-r->left-bm.bmWidth)/2;
	int y = r->top+(r->bottom-r->top-bm.bmHeight)/2;
	dc->BitBlt(x, y,		// Destination
				bm.bmWidth, // Width
				bm.bmHeight,// Height
				&dcMem,     // Source DC
				0, 0,       // Source
				SRCCOPY);   // Operation

	// Done with memory DC now, so clean up.
	VERIFY(dcMem.SelectObject(pbmOld));
	VERIFY(dcMem.DeleteDC());
}

