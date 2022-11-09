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
*	TelArPropertyPage.cpp : implementation file
*	
*	$Log:   D:/pvcsarch/telar/telarpropertypage.cpv  $
* 
*    Rev 1.170   Dec 19 2007 17:27:42   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.169   Oct 11 2007 10:15:16   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.168   Sep 21 2007 15:47:30   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.167   Aug 14 2007 14:09:20   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.166   May 09 2007 10:23:58   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.165   Dec 13 2006 13:38:28   tmielke
* No refund possible text added
* 
*    Rev 1.164   Nov 16 2006 14:59:58   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.163   Nov 13 2006 13:26:36   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.162   Nov 12 2006 17:16:50   tmielke
* v1.79 build 2095 -- messed up version: auto-recording broken
* 
*    Rev 1.161   Jun 12 2006 15:13:32   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.160   Jun 12 2006 13:56:28   tmielke
* zur Sicherheit Check-In vor Word-Wrap Notes box
* 
*    Rev 1.159   May 31 2006 10:23:48   tmielke
* Speaker volume slider
* 
*    Rev 1.158   May 31 2006 09:19:12   tmielke
* zur Sicherheit vor Lautstärkeregler für Audio-Ausgabe
* 
*    Rev 1.157   Mar 17 2006 13:16:30   tmielke
* v1.77 build 1818
* 
*    Rev 1.156   Nov 25 2005 01:32:34   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.155   Nov 23 2005 16:11:36   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.154   Nov 11 2005 09:51:08   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.153   Nov 03 2005 00:25:20   tmielke
* added suggestions according to #491
* 
*    Rev 1.152   Oct 19 2005 12:22:28   tmielke
* solved problems when accessing file-based index files.
* 
*    Rev 1.151   Jul 11 2005 08:52:54   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.150   Jul 05 2005 01:50:32   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.149   Jun 28 2005 01:46:36   tmielke
* v1.72 build 1250
* 
*    Rev 1.148   Jun 02 2005 01:30:38   tmielke
* v1.72 build 1207
* 
*    Rev 1.147   May 18 2005 13:47:20   tmielke
* v1.72 build 1200
* 
*    Rev 1.146   Apr 10 2005 18:00:00   tmielke
* New folder select dialog.
* 
*    Rev 1.145   Mar 18 2005 16:12:12   tmielke
*  
* 
*    Rev 1.144   Mar 12 2005 07:08:48   tmielke
* v1.69
* 
*    Rev 1.143   Feb 22 2005 16:53:30   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.142   Dec 17 2004 10:14:42   tmielke
* v1.66 build 950
* 
*    Rev 1.141   Dec 11 2004 10:06:16   tmielke
* RecordsCount
* 
*    Rev 1.140   Nov 21 2004 01:29:24   tmielke
* v1.66 build 883
* 
*    Rev 1.139   Nov 20 2004 01:03:40   tmielke
* v1.66 build 880
* 
*    Rev 1.138   Sep 22 2004 05:20:40   tmielke
* v1.66 build 869 
* improved db-index file creation & cleaned up moving files
* 
*    Rev 1.137   Jun 25 2004 23:25:46   tmielke
* added database index file versioning (Config key 'MinBuildNeeded')
* 
*    Rev 1.136   Jun 01 2004 05:07:22   tmielke
* v1.66 build 846
* improved stability
* 
*    Rev 1.135   Feb 11 2004 00:50:40   tmielke
* v1.66 pre-final
* 
*    Rev 1.134   Dec 04 2003 03:36:52   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.133   Nov 06 2003 05:18:32   tmielke
* MDB-index Zwischenversion
* 
*    Rev 1.132   Oct 21 2003 03:42:22   tmielke
* started database index file
* 
*    Rev 1.131   Oct 20 2003 19:18:08   tmielke
* v1.65 final
* 
*    Rev 1.130   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.129   Sep 23 2003 01:48:12   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.128   Sep 12 2003 01:12:16   tmielke
*  
* 
*    Rev 1.127   Sep 11 2003 04:04:10   tmielke
*  
* 
*    Rev 1.126   Sep 11 2003 04:03:42   tmielke
* This version should fix the NT40 problems (waveinAddBuffer deadlock).
* I also removed the animated window code for opening info and search screens.
* 
*    Rev 1.125   Sep 04 2003 00:55:34   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.124   Aug 22 2003 11:49:54   tmielke
* fixed invalid path problem
* 
*    Rev 1.123   Aug 20 2003 01:03:08   tmielke
* nomixer failsafe setting
* 
*    Rev 1.122   Aug 13 2003 01:02:14   tmielke
* IRI warning bugfix, IMPORTANT NOTE on setup screen
* 
*    Rev 1.121   Aug 04 2003 00:35:08   tmielke
* v1.64
* 
*    Rev 1.120   Aug 04 2003 00:34:26   tmielke
* optional ALC, corrected spelling, and setup script modification
* 
*    Rev 1.119   Jul 21 2003 00:02:30   tmielke
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
*    Rev 1.118   Jul 20 2003 21:35:16   tmielke
* m_Page1.m_SCRCTRL_filename = "";
* 
*    Rev 1.117   Jun 09 2003 16:48:22   tmielke
* TelarVendorPhoneCoach dazu (und Actimax auch nachträglich)
* 
*    Rev 1.116   Jun 09 2003 15:25:24   tmielke
* v1.63 final
* 
*    Rev 1.115   May 19 2003 20:46:20   tmielke
* 1.63pre32, jetzt aber wirklich gefixed
* 
*    Rev 1.114   May 19 2003 14:30:28   tmielke
* 1.63pre32 - reverse MIXER order problem fixed
* 
*    Rev 1.113   May 13 2003 06:47:16   tmielke
* - trying to estimate proper input line after changing the device
* - added much brain to the automatic detection of the input line for the IRI
* 
* 
*    Rev 1.112   May 11 2003 00:22:26   tmielke
* support for sound cards with mute button
* 
*    Rev 1.111   Apr 30 2003 01:02:30   tmielke
* DSAMessageBox eingebaut
* 
*    Rev 1.110   Apr 29 2003 21:48:50   tmielke
* WindowAnima eingebaut
* 
*    Rev 1.109   Apr 29 2003 05:37:22   tmielke
* pre30 - data link 'change filename' function
* 
*    Rev 1.108   Apr 07 2003 09:53:22   tmielke
* pre release 28 - speeded up delete and move recordings
* 
*    Rev 1.107   Mar 27 2003 05:26:56   tmielke
* Data Link DLL speeded up
* recording delay fix
* 
*    Rev 1.106   Mar 26 2003 03:57:52   tmielke
* changed to plain grey with Retell logo
* 
*    Rev 1.105   Mar 25 2003 23:06:06   tmielke
* log file system revised
* 
*    Rev 1.104   Mar 21 2003 12:33:24   tmielke
* Actimax logo on each screen
* 
*    Rev 1.103   Mar 17 2003 02:12:16   tmielke
* Actimax without background texture
* 
*    Rev 1.102   Mar 04 2003 01:13:44   tmielke
* pre release 20 - Actimax manufacturer
* 
*    Rev 1.101   Jan 27 2003 01:14:06   tmielke
* Polish language support
* 
*    Rev 1.100   Jan 22 2003 16:50:34   tmielke
* MiniFrame ausgebaut
* 
*    Rev 1.99   Jan 15 2003 16:12:42   tmielke
* v1.63 pre 13
* 
*    Rev 1.98   Jan 05 2003 11:00:30   tmielke
* Icon-Tip bug beseitigt
* 
*    Rev 1.97   Dec 31 2002 07:36:34   tmielke
*     - having the lines combo box work with the genius soundcard
*     - changed the way the software stores wav files to solve problems with the Windows multimedia command interface
*     - added comprehensive multimedia command interface error messages
*     - changed the buffering for recording to better work with 11025 Hz samplingrate and others
*  
* 
*    Rev 1.96   Dec 31 2002 04:41:06   tmielke
* auf dem Win98 Rechner gemachte Änderungen
* 
*    Rev 1.94   Dec 18 2002 23:41:38   tmielke
* added Record Indicator and current recording time elapsed on Record tab
* 
*    Rev 1.93   Dec 18 2002 15:45:46   tmielke
* recording level has no more any time delay
* 
*    Rev 1.92   Dec 15 2002 21:50:58   tmielke
* auto resore window, speeded up bulk deletion
* 
*    Rev 1.91   Dec 04 2002 15:48:04   tmielke
* Genius soundcard support
* 
*    Rev 1.90   Nov 28 2002 03:38:44   tmielke
* parameters on Options tab greyed out if IRI active
* 
*    Rev 1.89   Nov 24 2002 01:36:50   tmielke
* Vendor DLL für Ron Telekom, NL Übers. Änderungen
* 
*    Rev 1.88   Nov 20 2002 03:56:04   tmielke
* Dutch language support 
* 
*    Rev 1.87   Nov 02 2002 20:59:40   tmielke
* - Timer ID1 verändert
* - Debug Informationen in Datei
* 
*    Rev 1.86   Oct 28 2002 18:37:28   tmielke
* 1.63 pre 5:
*     - fixed level control slider by changing to the mixer architecture
*     - fitted mixer interface to cope with different soundcard designs
* 
* 
*    Rev 1.85   Oct 25 2002 15:52:20   tmielke
*     - improved userfriendlyness when switching IRI on and off
*     - IRI detection with countdown now
* 
*    Rev 1.84   Oct 25 2002 11:28:32   tmielke
* Sicherheits-CheckIn vor level control auf mixer umgestellt
* 
*    Rev 1.83   Oct 12 2002 00:43:34   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer 
*   windows versions
* - fixed IRI recording
* 
*    Rev 1.82   Oct 08 2002 05:01:20   tmielke
* PropSheetFrame eingebaut
* 
*    Rev 1.81   Sep 24 2002 18:00:22   tmielke
* v1.63 pre 1
* 
*    Rev 1.80   Sep 24 2002 15:16:26   tmielke
* Total vermurxt alles... :(
* 
*    Rev 1.79   Sep 11 2002 20:13:34   tmielke
* Mixer Architektur in hardware screen eingebaut
* 
*    Rev 1.78   Jul 22 2002 12:43:44   tmielke
* fixed multi-select list box
* 
*    Rev 1.77   Jul 07 2002 05:14:48   tmielke
* Multi-select listbox
* 
*    Rev 1.76   Jun 05 2002 19:31:58   tmielke
* v1.62
* 
*    Rev 1.75   May 05 2002 11:57:06   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.74   Apr 25 2002 06:43:14   tmielke
* zusätzliche Suchfilterfunktionen
* 
*    Rev 1.73   Apr 19 2002 07:28:06   tmielke
* Czech translation added
* 
*    Rev 1.72   Mar 28 2002 13:07:50   tmielke
* Search by date, search window now docks on the left side.
* 
*    Rev 1.71   Mar 15 2002 20:22:58   tmielke
* v1.60
* 
*    Rev 1.70   Nov 07 2001 02:40:48   tmielke
* v1.59 bugfix release
* 
*    Rev 1.69   Nov 06 2001 05:28:12   tmielke
* v1.58a
* 
*    Rev 1.68   Oct 12 2001 16:24:10   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.67   Oct 02 2001 19:08:56   
* spanische ad-texte für lite 1.57
* 
*    Rev 1.66   Sep 14 2001 04:13:16   
* v1.57
* 
*    Rev 1.65   Sep 14 2001 04:11:38   
* v1.57
* 
*    Rev 1.64   20 Jul 2001 02:30:52   tmielke
* v1.56
* 
*    Rev 1.63   13 Jun 2001 16:57:56   tmielke
* Richards Änderungswünsche zur lite Version berücksichtigt
* 
*    Rev 1.62   06 Jun 2001 02:02:00   tmielke
* offizielle release 1.55
* 
*    Rev 1.61   02 Jun 2001 17:02:26   tmielke
* lite version Prototyp
* 
*    Rev 1.60   02 Jun 2001 02:57:26   tmielke
* CODECs screen in lite Version ausgebaut
* 
*    Rev 1.59   17 May 2001 02:02:20   tmielke
* v1.54
* 
*    Rev 1.58   17 May 2001 00:35:28   tmielke
* Spanische Sprach-DLL hinzugefügt
* 
*    Rev 1.57   12 Feb 2001 19:37:54   tmielke
* v1.53
* 
*    Rev 1.56   12 Feb 2001 19:35:54   tmielke
* disregard recordings less than X seconds
* neues exit-symbol für deakt.-button
* 
*    Rev 1.55   12 Feb 2001 14:12:22   tmielke
* Focus-handling verbessert
* 
*    Rev 1.54   12 Feb 2001 13:40:54   tmielke
* GetProgramVersion gefixt
* DSP-Dateien gefixt
* Bug: Liste wurde bei Aufnahme nicht richtig aktualisiert
* 
*    Rev 1.53   20 Dec 2000 18:20:10   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.52   04 Dec 2000 02:24:24   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.51   16 Nov 2000 04:26:36   tmielke
* v1.51a:
* - the problem that occured on Iain Gows system has been fixed.
* - the PDF manual will be installed together with the application.
* - the expiry date of the demo version has been changed to 01/04/01
* 
*    Rev 1.50   19 Oct 2000 02:30:10   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.49   18 Oct 2000 17:14:48   tmielke
* Sicherheits-Checkin vor Auto-Level-Control
* 
*    Rev 1.48   30 Jul 2000 04:34:48   tmielke
* Info-Screen & GB-Version gecheckt
* 
*    Rev 1.47   30 Jul 2000 03:22:42   tmielke
* allg. Einstellungen auch redesigned
* 
*    Rev 1.46   30 Jul 2000 02:22:44   tmielke
* Hardware- und CODEC pages redesigned
* 
*    Rev 1.45   29 Jul 2000 03:56:08   tmielke
* Aufnahme-Screen redesign fertig
* 
*    Rev 1.44   23 Jul 2000 19:18:08   tmielke
* zwischendurch
* 
*    Rev 1.43   23 Jul 2000 17:02:32   tmielke
* Zwischendurch: OwnerDraw Prototyp
* 
*    Rev 1.42   21 Jul 2000 09:17:54   tmielke
* Wiedergabe-Screen fertig redesigned
* 
*    Rev 1.41   22 Jun 2000 04:18:38   tmielke
* In Ordner kopieren/bewegen eingebaut.
* Add, Del, Edit Ordner implementiert.
* 
*    Rev 1.40   21 Jun 2000 05:36:24   tmielke
* Drag-and-drop basics eingebaut
* 
*    Rev 1.39   19 Jun 2000 23:18:10   tmielke
* Ordner eingebaut, drag-and-drop fehlt noch.
* 
*    Rev 1.38   19 Jun 2000 15:55:04   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.37   05 Jun 2000 05:26:00   tmielke
* DEBUGFILE logging für Prop2
* 
*    Rev 1.36   24 Mar 2000 22:36:54   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.35   18 Mar 2000 11:40:54   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.34   17 Mar 2000 05:32:26   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.33   05 Mar 2000 05:21:34   tmielke
* v1.43
* 
*    Rev 1.32   05 Mar 2000 01:22:58   tmielke
* safety check-in
* 
*    Rev 1.31   04 Mar 2000 21:38:00   tmielke
* vendor dll eingebaut
* 
*    Rev 1.30   28 Feb 2000 00:31:06   tmielke
* v1.42
* 
*    Rev 1.29   24 Feb 2000 15:28:26   tmielke
* v1.41
* 
*    Rev 1.28   24 Feb 2000 01:23:38   tmielke
* v1.39
* 
*    Rev 1.27   18 Feb 2000 08:21:28   tmielke
* Tageswerk 17.02.00
* 
*    Rev 1.26   18 Feb 2000 00:39:20   tmielke
* v1.38
* 
*    Rev 1.25   15 Dec 1999 03:34:20   tmielke
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
*    Rev 1.12   21 Mar 1999 19:14:46   tmielke
* Info-Button + verbesserter Info-Screen in v1.30
* 
*    Rev 1.11   20 Mar 1999 18:52:34   tmielke
* v1.3
* 
*    Rev 1.10   18 Mar 1999 13:27:38   tmielke
* v0.8 - Demoversion fertig gemacht
* 
*    Rev 1.9   03 Mar 1999 13:40:24   tmielke
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
*    Rev 1.4   28 Feb 1999 09:20:02   tmielke
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


#include "stdafx.h"
#include "afxole.h"

#include "TelAr.h"
#include "resource.h"
#include "SuchfilterDlg.h"
#include "TelArPropertyPage.h"
#include "TelArPropertySheet.h"
#include "PasswortDlg.h"
#include "PasswortCheckDlg.h"
#include <sys/stat.h>
#include "crypt.h"
#include "ProgDlg.h"
#include "EditDlg.h"
#include "AddFolder.h"
#include "DetectSMC.h"
#include "WindowAnima.h"
#include "MuteInput.h"
#include "DataSourceDialog.h"

#include <mmsystem.h>
#include "wavein\wavein.h"
#include <mmreg.h>
#include <msacm.h>
//#include "shlobj.h" -- better use shfolder.dll !!!
#include <shlobj.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CTelArPropertyPage1, CResizablePage)
IMPLEMENT_DYNCREATE(CTelArPropertyPage2, CResizablePage)
IMPLEMENT_DYNCREATE(CTelArPropertyPage3, CResizablePage)
IMPLEMENT_DYNCREATE(CTelArPropertyPage4, CResizablePage)
IMPLEMENT_DYNCREATE(CTelArPropertyPage5, CResizablePage)

static CListBox *listbox;
static CListBox *listbox_format;

static BOOL EncryptFile(CString &source, CString &destination, CString &key, int passes, BOOL bProgressBar);
static BOOL DecryptFile(CString &source, CString &destination, CString &key);

struct tEncryptStruct {
	CString src;
	CString dest;
	CString password;
	int     encryption_level;
	BOOL	bProgressBar;
};

static int nThreadCounter = 0;

struct tSenseSaveAudioStruct {
	char	callId[64];
	char	path[2000];
	time_t	now;

};


void ModifyIconTip(HWND hWnd, char *s)
{
	// Set the icon tip in the status area of the taskbar
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(nid);
	nid.hWnd = AfxGetMainWnd()->m_hWnd;
	nid.uID = STATUS_ICON_ID;
	nid.uFlags = NIF_TIP;
	strncpy(nid.szTip, s, sizeof(nid.szTip));
	nid.szTip[sizeof(nid.szTip)-1] = '\0';
	Shell_NotifyIcon(NIM_MODIFY, &nid); 
}

BOOL IsOldStyleIndexFile(char *pathfile)
{
	// check for old-style index file
	CFile File;
	char magic_buffer[1000];
	if (File.Open(pathfile, CFile::modeRead|CFile::shareDenyNone))
	{
		File.Seek(0, CFile::begin);
		File.Read(magic_buffer, sizeof(magic_buffer));
		File.Close();
		return (!strcmp(magic_buffer, INDEX_FILEMAGIC));
	}
	else
		return FALSE;
}

BOOL DoConvert(char *path, char *connect)
{
	//___ CONVERSION CODE ___
	BOOL bDoConvert = FALSE;

	// prepare index filename
	char pathfile[1000];
	strcpy(pathfile, path);

	if (*pathfile && pathfile[strlen(pathfile)-1] != '\\')
		strcat(pathfile, "\\");
	strcat(pathfile, INDEX_FILENAME);

	char pathfile_of_old_index_file[1000];

	// check for old-style index file
	if (IsOldStyleIndexFile(pathfile))
	{
		int n, m;
		char buffer[1000];
		bDoConvert = TRUE;
		strcpy(pathfile_of_old_index_file, pathfile);
		strcat(pathfile_of_old_index_file, ".old");
		
		LANG2BUFFER(IDS_STRING167, buffer);
		AfxMessageBox(buffer, MB_OK);

		do
		{
			// rename file for conversion if old index file format
			m = MoveFile(pathfile, pathfile_of_old_index_file);
			if (!m) 
			{
				LANG2BUFFER(IDS_STRING168, buffer);
				n = AfxMessageBox(buffer, MB_ABORTRETRYIGNORE);
			}
		}
		while (!m && n == IDRETRY);
		if (!m)
		{
			if (n == IDABORT) 
			{
				AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0L);
				return FALSE;
			}
			else 
				return FALSE;
		}
	}
	
	// do conversion if needed
	if (bDoConvert)
	{
		// open index file with new database format
		CIndexDB temp_db;
		temp_db.OpenCreate(pathfile, connect);

		int file_version = INDEX_FILEVERSION;

		if (theTabelle.Read(pathfile_of_old_index_file, &file_version, FALSE))
		{
			TMZeile *pZeile = theTabelle.tabelle;
			CString td;
			CString tz;
			CTime ct;
			BOOL bProblem = FALSE;

			while (pZeile)
			{
				td = pZeile->Spalte(SPID_DATUM);
				tz = pZeile->Spalte(SPID_ZEIT);
				if(!String2CTime(td, tz, ct))
				{
					bProblem = TRUE;
					char buffer[1000];
					LANG2BUFFER(IDS_STRING171, buffer);
					strcat(buffer, " (Invalid date/time data in index file.)");
					if (AfxMessageBox(buffer, MB_OKCANCEL) == IDCANCEL) break;
				}
				pZeile->Spalte(SPID_DATUM).Format("%04d/%02d/%02d", ct.GetYear(), ct.GetMonth(), ct.GetDay());
				pZeile->Spalte(SPID_ZEIT).Format("%02d:%02d:%02d", ct.GetHour(), ct.GetMinute(), ct.GetSecond());
				if (pZeile->Spalte(SPID_CODEC).GetLength()>10) pZeile->Spalte(SPID_CODEC) = pZeile->Spalte(SPID_CODEC).Left(10);
				if (pZeile->Spalte(SPID_FORMAT).GetLength()>10) pZeile->Spalte(SPID_FORMAT) = pZeile->Spalte(SPID_FORMAT).Left(10);
				if(!temp_db.AppendRecording(pZeile)) 
				{
					bProblem = TRUE;
					char buffer[1000];
					LANG2BUFFER(IDS_STRING171, buffer);
					if (AfxMessageBox(buffer, MB_OKCANCEL) == IDCANCEL) break;
				}
				pZeile = pZeile->next;
			}
			if (pZeile || bProblem) LANG_MESSAGEBOX1(IDS_STRING169)	// Conversion was not (completely) successful.

			theTabelle.Erase();
		}

		temp_db.Close();
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage1 property page

CTelArPropertyPage1::CTelArPropertyPage1() : CResizablePage(CTelArPropertyPage1::IDD)
{
	TRACE0("CTelArPropertyPage1::CTelArPropertyPage1()\n");
	//{{AFX_DATA_INIT(CTelArPropertyPage1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	n_silence = 0;
	n_noise   = 0;
	aufnahme_datensatz = NULL;
	m_ArchivPfadMerker = X_path;
	NotifyWindowTitle = "";
	m_bControlToneWarningDisplayed = FALSE;
	m_nControlToneWarningCounter = 0;
	m_bRecordingLedBlinkState = FALSE;

	static char buffer[50];
	LANG2BUFFER(IDS_STRING97, buffer);
	m_psp.pszTitle = buffer;
	m_psp.dwFlags |= PSP_USETITLE;
}

CTelArPropertyPage1::~CTelArPropertyPage1()
{
	if (aufnahme_datensatz) delete aufnahme_datensatz;
}

void CTelArPropertyPage1::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTelArPropertyPage1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTelArPropertyPage1, CResizablePage)
	//{{AFX_MSG_MAP(CTelArPropertyPage1)
	ON_BN_CLICKED(IDC_AUFNAHME, OnAufnahme)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_ABBRECHEN, OnAbbrechen)
	ON_BN_CLICKED(IDC_BEENDEN, OnBeenden)
	ON_EN_CHANGE(IDC_GESPRAECHSPARTNER, OnChangeGespraechspartner)
	ON_EN_CHANGE(IDC_NOTIZEN, OnChangeNotizen)
	ON_BN_CLICKED(IDC_INFO, OnInfo)
	ON_BN_CLICKED(IDC_LETZTE_AUFNAHME, OnLetzteAufnahme)
	ON_WM_DRAWITEM()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_MUTE, &CTelArPropertyPage1::OnBnClickedMute)
END_MESSAGE_MAP()



BOOL CTelArPropertyPage1::OnInitDialog() 
{
	TRACE0("CTelArPropertyPage1::OnInitDialog()\n");
	CResizablePage::OnInitDialog();
	
	// preset layout
	AddAnchor(IDC_GESPRAECHSPARTNER_TEXT, TOP_LEFT);
	AddAnchor(IDC_GESPRAECHSPARTNER, TOP_LEFT, TOP_RIGHT);
	AddAnchor(IDC_NOTIZEN_TEXT, TOP_LEFT);
	AddAnchor(IDC_NOTIZEN, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_STATUS_TEXT, BOTTOM_LEFT);
	AddAnchor(IDC_SPEICHERN_IN, BOTTOM_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_AUFNAHMEPEGEL_TEXT, BOTTOM_LEFT);
	AddAnchor(IDC_PEAKLEVEL, BOTTOM_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_STATIC_AUSSTEUERUNG, BOTTOM_LEFT);
	AddAnchor(IDC_AUSSTEUERUNG, BOTTOM_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_BEENDEN, BOTTOM_LEFT);
	AddAnchor(IDC_LETZTE_AUFNAHME, BOTTOM_LEFT);
	AddAnchor(IDC_INFO, BOTTOM_LEFT);
	AddAnchor(IDC_ABBRECHEN, BOTTOM_LEFT);
	AddAnchor(IDC_AUFNAHME, BOTTOM_LEFT);
	AddAnchor(IDC_MUTE, BOTTOM_LEFT);
	AddAnchor(IDC_ADVERTISING, BOTTOM_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_VENDOR_LOGO_FRAME, BOTTOM_RIGHT, BOTTOM_RIGHT);

	char buffer[1000];

	SetTimer(6, 2000, NULL);	// erst in n Sekunden starten, wenn alles initialisiert ist
	// SetTimer(7, 1000, NULL);	// alle xxxxxxxxxx auto-mode unterbrechen damit das mmsystem nicht abstürzt - war zu Testzwecken
	SetTimer(8, 500, NULL);		// recording LED blink timer
	// Slider initialisieren
	GetDlgItem(IDC_AUSSTEUERUNG)->EnableWindow(FALSE);
	if (!X_nomixer)
		if (mixerGetNumDevs())
		{
			GetDlgItem(IDC_AUSSTEUERUNG)->EnableWindow(TRUE);
			((CSliderCtrl *)GetDlgItem(IDC_AUSSTEUERUNG))->SetRange(0, 0xffff, TRUE);
			((CSliderCtrl *)GetDlgItem(IDC_AUSSTEUERUNG))->SetPos((int)X_volume);
			SetVolume(X_volume);
		}

	// Owner Draw Buttons initialisieren

	char *aufnahme_button_texte[] = { 
		C_manuelle_aufnahme,
		C_automatik_start,
		C_aufnahme_beenden,
		C_automatik_stop
	};		
	int aufnahme_button_bitmaps[] = { 
		IDB_MANAUF,
		IDB_ROBOT,
		IDB_NO_MANAUF,
		IDB_NO_ROBOT 
	};
	odbAufnahme.InitButton(this, IDC_AUFNAHME, aufnahme_button_texte, aufnahme_button_bitmaps, 4);

	char *mute_button_texte[] = { 
		C_mute_microphone,
		C_open_microphone
	};		
	int mute_button_bitmaps[] = { 
		IDB_MUTE_MICROPHONE,
		IDB_OPEN_MICROPHONE
	};
	odbMute.InitButton(this, IDC_MUTE, mute_button_texte, mute_button_bitmaps, 2);

	char *ppc = buffer;
	LANG2BUFFER(IDS_STRING72, buffer);
	int n = IDB_INFOSIGN;
	int *pn = &n;
	odbInfo.InitButton(this, IDC_INFO, &ppc, pn, 1);

	LANG2BUFFER(IDS_STRING8, buffer);
	n = IDB_SPEAKER;
	odbLetzteAufnahme.InitButton(this, IDC_LETZTE_AUFNAHME, &ppc, pn, 1);

	LANG2BUFFER(IDS_STRING73, buffer);
	n = IDB_TRASHCAN;
	odbAbbrechen.InitButton(this, IDC_ABBRECHEN, &ppc, pn, 1);

	LANG2BUFFER(IDS_STRING74, buffer);
	n = IDB_EXIT;
	odbBeenden.InitButton(this, IDC_BEENDEN, &ppc, pn, 1);

	return TRUE; 
}

void CTelArPropertyPage1::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	CRect r;
	GetClientRect(&r);
	InvalidateRect(r);
}

// Hintergrundbitmap malen
BOOL CTelArPropertyPage1::OnEraseBkgnd( CDC* pDC )
{
	CResizablePage::OnEraseBkgnd(pDC);

	char buffer[200];
	VEND2BUFFER(IDS_STRING1, buffer);

	CRect r, fr;

	if (!strcmp(buffer, "PhoneCoach CompuCorder"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_PHONECOACH_ON_GREY, &fr, 0);
	}
	else if (!strcmp(buffer, "Actimax"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_ACTIMAX_ON_GREY, &fr, 0);
	}
	else
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_RETELL_ON_GREY, &fr, 0);
	}
	return TRUE;
}

void CTelArPropertyPage1::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	RECT pr, cr;

	GetWindowRect(&pr);

	char buffer[250];
	int nOldBkMode = dc.SetBkMode(TRANSPARENT);
	GetDlgItem(IDC_GESPRAECHSPARTNER_TEXT)->GetWindowRect(&cr);

	CFont *standardFont = dc.GetCurrentFont();
	LOGFONT FontStats;
	standardFont->GetLogFont(&FontStats);
	strcpy(FontStats.lfFaceName, "MS Sans Serif"); 
	FontStats.lfHeight  = cr.bottom-cr.top;
	FontStats.lfWidth   = 0;	// Breite relativ zur Höhe verkleinern
	FontStats.lfQuality = DEFAULT_QUALITY;
	FontStats.lfWeight	= 700;	// default weight
	CFont neuerFont;	// Font kreiren
	neuerFont.CreateFontIndirect(&FontStats);
	CFont *oldFont = dc.SelectObject(&neuerFont);	// in den device context damit

	// Statics füllen
	// Gesprächspartner
	LANG2BUFFER(IDS_STRING75, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Notizen
	GetDlgItem(IDC_NOTIZEN_TEXT)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING76, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Status
	GetDlgItem(IDC_STATUS_TEXT)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING154, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Aufnahmepegel
	GetDlgItem(IDC_AUFNAHMEPEGEL_TEXT)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING77, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Aussteuerung
	GetDlgItem(IDC_STATIC_AUSSTEUERUNG)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING78, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));

	// alten Font und BG-Mode restaurieren
	dc.SelectObject(oldFont);
	dc.SetBkMode(nOldBkMode);
}

void CTelArPropertyPage1::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpdis) 
{
	switch (nIDCtl)
	{
	case IDC_AUFNAHME:
		odbAufnahme.PerformDrawItem(lpdis);
		break;

	case IDC_MUTE:
		odbMute.PerformDrawItem(lpdis);
		break;

	case IDC_INFO:
		odbInfo.PerformDrawItem(lpdis);
		break;

	case IDC_LETZTE_AUFNAHME:
		odbLetzteAufnahme.PerformDrawItem(lpdis);
		break;

	case IDC_ABBRECHEN:
		odbAbbrechen.PerformDrawItem(lpdis);
		break;

	case IDC_BEENDEN:
		odbBeenden.PerformDrawItem(lpdis);
		break;
	}

	CResizablePage::OnDrawItem(nIDCtl, lpdis);
}

BOOL CTelArPropertyPage1::OnSetActive() 
{
/*	if (X_modus == 0)
	{
		GetDlgItem(IDC_AUTOMATIK_EMPFINDLICHKEIT)->ShowWindow(TRUE);
		int auto_empf = (X_schwellwert * 0x8000 / 100) / 300;
		char buffer[1000];
		memset(buffer, '|', auto_empf);
		buffer[auto_empf] = '\0';
		SetDlgItemText(IDC_AUTOMATIK_EMPFINDLICHKEIT, buffer);
	}
	else
		GetDlgItem(IDC_AUTOMATIK_EMPFINDLICHKEIT)->ShowWindow(FALSE);
*/
	return CResizablePage::OnSetActive();
}

void CTelArPropertyPage1::OnDestroy() 
{
//	RemoveAllAnchors();

	CResizablePage::OnDestroy();
	
	if (odbAufnahme.GetState() != MANUELLE_AUFNAHME && odbAufnahme.GetState() != AUTOMATIK_START)
	{
		WaveIn_Stop();
		WaveIn_Close();
		Normalisieren();
	}
	
	default_index.Close();
}


void CTelArPropertyPage1::Normalisieren()
{
	DF("CTelArPropertyPage1::Normalisieren()");

	GetDlgItem(IDC_AUFNAHME)->EnableWindow(TRUE);
	GetDlgItem(IDC_ABBRECHEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_GESPRAECHSPARTNER)->EnableWindow(FALSE);
	GetDlgItem(IDC_NOTIZEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_LETZTE_AUFNAHME)->EnableWindow(TRUE);
	SetDlgItemText(IDC_GESPRAECHSPARTNER, (CString)"");
	SetDlgItemText(IDC_NOTIZEN, (CString)"");
	
	if (X_modus == 1)
	{
		odbAufnahme.SetState(MANUELLE_AUFNAHME);
	}
	else
	{
		odbAufnahme.SetState(AUTOMATIK_START);
	}

	WaveIn_OpenMicrophone();
	odbMute.SetState(MUTE_MICROPHONE);
}


void CTelArPropertyPage1::OnAufnahme() 
{
	if (odbAufnahme.GetState() == MANUELLE_AUFNAHME) 
	{
		if (Record(FALSE)) 
		{
			odbAufnahme.SetState(AUFNAHME_BEENDEN);
			GetDlgItem(IDC_LETZTE_AUFNAHME)->EnableWindow(FALSE);
			SetDlgItemText(IDC_LETZTE_AUFNAHME, C_letzte_aufnahme);
			GetDlgItem(IDC_ABBRECHEN)->EnableWindow(TRUE);
			nRecordingPeak = -1;
		}

	}
	else if (odbAufnahme.GetState() == AUTOMATIK_START) 
	{
		if (X_modus == 2)
		{			
			odbAufnahme.SetState(AUTOMATIK_STOP);
		}
		else
		{
			if (Record(TRUE)) 
			{
				odbAufnahme.SetState(AUTOMATIK_STOP);
				//GetDlgItem(IDC_ABBRECHEN)->EnableWindow(TRUE);
				nRecordingPeak = 0;
			}
		}

	}
	else if (odbAufnahme.GetState() == AUFNAHME_BEENDEN) 
	{
		WaveIn_Stop();
		WaveIn_Close();
		AufnahmedatensatzSchreiben();
		Normalisieren();
		
		if (!NotifyWindowTitle.IsEmpty())
		{
			HWND hWndFind = ::FindWindow(NULL, NotifyWindowTitle.GetBuffer(0));
			if (hWndFind)
				::PostMessage(hWndFind, WM_COMMAND, 10000, (LPARAM)nRecordingPeak);
		}
	}	
	else if (odbAufnahme.GetState() == AUTOMATIK_STOP) 
	{
		WaveIn_Stop();
		WaveIn_Close();
		if (GetDlgItem(IDC_ABBRECHEN)->IsWindowEnabled())
			AufnahmedatensatzSchreiben();
		Normalisieren();
	}	
	
}


void CTelArPropertyPage1::OnBnClickedMute()
{
	if (odbMute.GetState() == MUTE_MICROPHONE) 
	{
		WaveIn_MuteMicrophone();
		odbMute.SetState(OPEN_MICROPHONE);
	}
	else	
	{
		WaveIn_OpenMicrophone();
		odbMute.SetState(MUTE_MICROPHONE);
	}
}


// Thread-Funktion für das Encrypten
UINT EncryptionThreadFunction( LPVOID pParam )
{
	tEncryptStruct *pest = (tEncryptStruct*)pParam;

	nThreadCounter++;

	if (!EncryptFile(pest->src, pest->dest, pest->password, pest->encryption_level, pest->bProgressBar))
	{
		char fmt[2000], buffer2[2000];
		LANG2BUFFER(IDS_STRING27, fmt);
		sprintf(buffer2, fmt, pest->src);
		AfxMessageBox(buffer2, MB_ICONSTOP);
	}
	else if (!DeleteFile(pest->src))
	{
		char fmt[2000], buffer2[2000];
		LANG2BUFFER(IDS_STRING28, fmt);
		sprintf(buffer2, fmt, pest->src);
		AfxMessageBox(buffer2, MB_ICONSTOP);
	}
	delete pest;
	nThreadCounter--;
	return 0;	// thread completed successfully
}


// Thread-Funktion für das Encrypten
UINT SenseSaveAudioThreadFunction( LPVOID pParam )
{
#ifdef SENSE
	long result;
	tSenseSaveAudioStruct *pest = (tSenseSaveAudioStruct*)pParam;

	nThreadCounter++;

	//save the audio for the call
	result=IvrReqUploadAudioMessage(pest->callId, "Call recorded by SCR957", pest->path, FMT_WAV, 2);//AUDIO_TYPE_CALL
	SenseError("IvrReqUploadAudioMessage()", result);
	// -> returns after file sent to server

	//only after saving the audio file we should send the ccifConShutdownCompleted message
	result = updateCall(4/*ccifConShutdownCompleted*/, 1, CS_957, 0, 0, 0, (long)pest->now, "", "", "", pest->callId);
	SenseError("updateCall(ccifConShutdownCompleted)", result);
	
	if (!DeleteFile(pest->path))
	{
		char fmt[2000], buffer2[2000];
		LANG2BUFFER(IDS_STRING28, fmt);
		sprintf(buffer2, fmt, pest->path);
		AfxMessageBox(buffer2, MB_ICONSTOP);
	}

	delete pest;
	nThreadCounter--;
#endif
	return 0;	// thread completed successfully
}


void CTelArPropertyPage1::AufnahmedatensatzSchreiben()
{
	if (!aufnahme_datensatz) return;

	/* old index file code
	struct _stat buf;
	int result;
	char pathfile[1000];

	strcpy(pathfile, X_path);
	if (*pathfile && pathfile[strlen(pathfile)-1] != '\\')
		strcat(pathfile, "\\");
	strcat(pathfile, INDEX_FILENAME);

	// für einige Sekunden warten, bis INDEX_FILENAME wieder erreichbar ist:
	extern CTelArApp theApp;
	CTime start = CTime::GetCurrentTime();
	CTime stop  = CTime::GetCurrentTime() + CTimeSpan(0,0,0,10);
	while (CTime::GetCurrentTime() < stop)
	{
		// testen, ob auf INDEX_FILENAME zugegriffen werden kann
		result = _stat(pathfile, &buf);
		if( result == 0 ) break;

		// wenn nicht: eine Sekunde warten
		CTime click = CTime::GetCurrentTime() + CTimeSpan(0,0,0,1);
		while (CTime::GetCurrentTime() < click)
			;
	}

	// zwischenzeitlicher Archivpfadwechsel?
	if (m_ArchivPfadMerker != X_path)
	{
		m_pTelArPropertyPage2->RefreshListe();
		m_ArchivPfadMerker = X_path;
	}

	if( result != 0 )
		theTabelle.Write(pathfile);	// Indexdatei initialisieren

	{
		int file_version = INDEX_FILEVERSION;
		if (!theTabelle.Read(pathfile, &file_version, TRUE)) return;
		if (file_version < INDEX_FILEVERSION)
		{
			char tmp_filename[1000];

			// damit niemand anderes gleichzeitig zugreift: Datei umbenennen
			strcpy(tmp_filename, pathfile);
			strcat(tmp_filename, ".tmp");	
			result = rename(pathfile, tmp_filename);
			if(result != 0)
			{
				char buffer[1000], formatstr[200];
				LANG2BUFFER(IDS_STRING9, formatstr);
				sprintf(buffer, formatstr, INDEX_FILENAME, aufnahme_datensatz->spalte->data.GetBuffer(0));
				AfxMessageBox(buffer, MB_ICONSTOP);
				return;
			}

			if (!theTabelle.Read(tmp_filename, &file_version, FALSE)) return;

			// hier die alten Daten aktualisieren
			if (file_version == 1)	// von Version 1 auf 2 updaten:
			{
				// die ganze Tabelle durchgehen:
				for (TMZeile *zp = theTabelle.tabelle; zp; zp = zp->next)
				{					
					zp->Spalte(SPID_DAUER) = "00:01:00";
				}
			}
			if (file_version == 2)	// von Version 2 auf 3 updaten:
			{
				// die ganze Tabelle durchgehen:
				for (TMZeile *zp = theTabelle.tabelle; zp; zp = zp->next)
				{					
					zp->Spalte(SPID_GESCHUETZT) = "0";
				}
			}
			theTabelle.Write(tmp_filename); // Indexdatei-Version der Programmversion anpassen

			result = rename(tmp_filename, pathfile);
			if(result != 0)
			{
				char buffer[1000], formatstr[200];
				LANG2BUFFER(IDS_STRING9, formatstr);
				sprintf(buffer, formatstr, INDEX_FILENAME, aufnahme_datensatz->spalte->data.GetBuffer(0));
				AfxMessageBox(buffer, MB_ICONSTOP);
				return;
			}
		}
	}
	end of old index file code */

	{
		// Gesprächspartner und Notiz erst am Ende der Aufnahme einlesen:
		CString gespraechspartner, notizen;
		GetDlgItemText(IDC_GESPRAECHSPARTNER, gespraechspartner);
		GetDlgItemText(IDC_NOTIZEN, notizen);
		aufnahme_datensatz->Spalte(SPID_GESPRAECHSPARTNER) = gespraechspartner;
		aufnahme_datensatz->Spalte(SPID_NOTIZEN) = notizen;
		SetDlgItemText(IDC_GESPRAECHSPARTNER, (CString)"");
		SetDlgItemText(IDC_NOTIZEN, (CString)"");
		GetDlgItem(IDC_GESPRAECHSPARTNER)->EnableWindow(FALSE);
		GetDlgItem(IDC_NOTIZEN)->EnableWindow(FALSE);

		// wenn nicht verschlüsselt werden soll: Endung der Datei in 'wav' ändern
		if (X_passes==0 && !strlen(X_passwort))
			if (aufnahme_datensatz->Spalte(SPID_DATEINAME).Right(3) == "trs") 
				aufnahme_datensatz->Spalte(SPID_DATEINAME) =
					aufnahme_datensatz->Spalte(SPID_DATEINAME).Left(aufnahme_datensatz->Spalte(SPID_DATEINAME).GetLength()-3) + "wav";

		// Gesprächsdauer berechnen
		CTime now = now.GetCurrentTime();
		CTimeSpan ts_dauer = now - m_aufnahmestartzeit;
		CString dauer;
		dauer.Format("%02d:%02d:%02d", (int)ts_dauer.GetTotalHours(), (int)ts_dauer.GetMinutes(), (int)ts_dauer.GetSeconds());
		aufnahme_datensatz->Spalte(SPID_DAUER) = dauer;
		
		CString temp = (CString)X_passwort;
		temp.TrimLeft();
		temp.TrimRight();
		if (temp != "")
			aufnahme_datensatz->Spalte(SPID_GESCHUETZT) = "1";
		else
			aufnahme_datensatz->Spalte(SPID_GESCHUETZT) = "0";

/*
	CTime start = CTime::GetCurrentTime();
	for (int i = 0; i < 10000; i++) // !!!!!!! CREATE TEST ENTRIES !!!!!!!!
	{ 
		now += CTimeSpan(0,0,0,1);

		CString datum, zeit;
		char formatstr[30];
		LANG2BUFFER(IDS_STRING13, formatstr);
		if (*formatstr == '*') // '*' bedeutet umgekehrte Reihenfolge in der englischen Version
			datum.Format(formatstr+1, now.GetYear(), now.GetMonth(), now.GetDay());
		else
			datum.Format(formatstr, now.GetDay(),  now.GetMonth(),  now.GetYear());
		zeit.Format("%02d:%02d:%02d", now.GetHour(), now.GetMinute(), now.GetSecond());

		aufnahme_datensatz->Spalte(SPID_DATUM) = datum;
		aufnahme_datensatz->Spalte(SPID_ZEIT)  = zeit;
		aufnahme_datensatz->Spalte(SPID_DATEINAME) = datum + zeit + ".trs";

		if (default_index.AppendRecording(aufnahme_datensatz))
			default_index.AppendAccesslog("New Recording", TRUE, aufnahme_datensatz->Spalte(SPID_DATEINAME).GetBuffer(0));
		else
		{
			CString cs = "Problem adding record to index: " + aufnahme_datensatz->Spalte(SPID_DATEINAME);
			default_index.AppendAccesslog("New Recording", FALSE, cs.GetBuffer(0));
		}
	}
	CTimeSpan dur = CTime::GetCurrentTime() - start;
	CString durstr;
	durstr.Format ("Time to create %d records: %02d:%02d:%02d", i, (int)dur.GetHours(), (int)dur.GetMinutes(), (int)dur.GetSeconds());
	DF(durstr.GetBuffer(0));
	TRACE(durstr.GetBuffer(0));
*/
/**/
#ifdef SENSE
		// und ab dafür!
		if (!_strnicmp(X_path, "sense://", 8))
		{
			long result;
			char callId[64];

			if (Reconnect2SenseServer(X_path))
			{
				LANG_MESSAGEBOX2(IDS_STRING183, MB_ICONSTOP); // "Ungültiger Pfad!"
			}	
			else if ((strncmp(X_codec, "<MS-PCM", 7) && strcmp(X_codec, "Microsoft CCITT G.711")) || X_samplingrate != 8000)
			{
				LANG_MESSAGEBOX2(IDS_STRING184, MB_ICONEXCLAMATION); // "Recording to Sense server only works with MS-PCM or G.711 codec at 8000 Hz sampling frequency. Please check hardware and codec tabs!"
			}
			else
			{
				//first we need to init a call
				result = updateCall(1/*ccifConSetup*/, 1, CS_957, (long)m_aufnahmestartzeit.GetTime(), 0, 0, 0, X_sense_caller, X_sense_called, X_sense_extension, callId);
				if (!SenseError("updateCall(ccifConSetup)", result))
				{
					//send the second message: connection established
					result = updateCall(2/*ccifConEstablished*/, 1, CS_957, 0, (long)m_aufnahmestartzeit.GetTime(), 0, 0, "", "", "", callId);
					if (!SenseError("updateCall(ccifConEstablished)", result))
					{
						//now we can start the termination of call
						result = updateCall(3/*ccifConShutdownInit*/, 1, CS_957, 0, 0, (long)now.GetTime(), 0, "", "", "", callId);
						if (!SenseError("updateCall(ccifConShutdownInit)", result))	// -> only error if connection broken
						{					
							// setup file name
							char buffer_src[2000];
							if(!GetTempPath(sizeof(buffer_src), buffer_src))
								strcpy(buffer_src, "C:\\");
							if (*buffer_src && buffer_src[strlen(buffer_src)-1] != '\\')
								strcat(buffer_src, "\\");
							strcat(buffer_src, (LPCSTR)aufnahme_datensatz->Spalte(SPID_DATEINAME));
							if (strlen(buffer_src) >= 3) 
							{
								//if (strcmp(X_codec, "Microsoft CCITT G.711")))
								//	strcpy(buffer_src+strlen(buffer_src)-3, "pcm");
								//else
									strcpy(buffer_src+strlen(buffer_src)-3, "wav");
							}

							tSenseSaveAudioStruct *pest = new tSenseSaveAudioStruct;
							strcpy(pest->callId, callId);
							strcpy(pest->path, buffer_src);
							pest->now = (time_t)now.GetTime();
							CWinThread *thread;
							thread = AfxBeginThread(&(SenseSaveAudioThreadFunction), (LPVOID)pest, THREAD_PRIORITY_LOWEST);
						}
					}
				}
			}
		}
		else
#endif
		{
			if (default_index.AppendRecording(aufnahme_datensatz))
				default_index.AppendAccesslog("New Recording", TRUE, aufnahme_datensatz->Spalte(SPID_DATEINAME).GetBuffer(0));
			else
			{
				CString cs = "Problem adding record to index: " + aufnahme_datensatz->Spalte(SPID_DATEINAME);
				default_index.AppendAccesslog("New Recording", FALSE, cs.GetBuffer(0));
			}
		}
/**/
	}



	// encrypten:
	if ((X_passes>0 || strlen(X_passwort)) && _strnicmp(X_path, "sense://", 8))
	{
		char buffer_src[2000], buffer_dest[2000];
		strcpy(buffer_dest, X_path);
		if (*buffer_dest && buffer_dest[strlen(buffer_dest)-1] != '\\')
			strcat(buffer_dest, "\\");
		strcat(buffer_dest, (LPCSTR)aufnahme_datensatz->Spalte(SPID_DATEINAME));
		strcpy(buffer_src, buffer_dest);
		if (strlen(buffer_src) >= 3) strcpy(buffer_src+strlen(buffer_src)-3, "wav");
		
		CString pw = (CString)X_passwort + aufnahme_datensatz->Spalte(SPID_DATEINAME);

		// Do Thread
		tEncryptStruct *pest = new tEncryptStruct;
		pest->src  = buffer_src;
		pest->dest = buffer_dest;
		pest->password = pw;
		pest->encryption_level = X_passes;
		if (pest->encryption_level < 1) pest->encryption_level = 1;
		pest->bProgressBar = AfxGetMainWnd()->IsWindowVisible();
		CWinThread *thread;
		thread = AfxBeginThread(&(EncryptionThreadFunction), (LPVOID)pest, THREAD_PRIORITY_LOWEST);
	}
	
	// Liste auf Playback-Screen nur aktualisieren, wenn Playback-Screen aktiv ist
	if (((CTelArPropertySheet *)GetParent())->GetActiveIndex() == 1)
	{
		m_pTelArPropertyPage2->RefreshListe();
		m_ArchivPfadMerker = X_path;
	}
}


BOOL CTelArPropertyPage1::Record(BOOL bMonitor)
{
	char buffer[1000], *cp;
	char buffer_dateiname[1000];
	CString datum, zeit;


	if (strlen(X_path) == 0)
	{
		LANG_MESSAGEBOX2(IDS_STRING10, MB_ICONEXCLAMATION); // "Aufnahme: Bitte unter 'Einstellungen' ein Verzeichnis für das Archiv wählen!"
		return FALSE;
	}

	if (X_aufnahmegeraet == -1)
	{
		LANG_MESSAGEBOX2(IDS_STRING11, MB_ICONEXCLAMATION); // "Aufnahme: Bitte unter 'Einstellungen' ein Audio-Gerät für die Aufnahme wählen!"
		return FALSE;
	}

	if (X_format_wfx == 0L)
	{
		LANG_MESSAGEBOX2(IDS_STRING12, MB_ICONEXCLAMATION); // "Aufnahme: Bitte unter 'CODECs' einen CODEC + Subformat wählen!"
		return FALSE;
	}

	// evtl. Wiedergabe stoppen
	if (m_pTelArPropertyPage2->bPlaying && m_pTelArPropertyPage2->m_hWnd) m_pTelArPropertyPage2->OnStop();

	{
		if (!_strnicmp(X_path, "sense://", 8)) 
		{
			if ((strncmp(X_codec, "<MS-PCM", 7) && strcmp(X_codec, "Microsoft CCITT G.711")) || X_samplingrate != 8000)
			{
				LANG_MESSAGEBOX2(IDS_STRING184, MB_ICONEXCLAMATION); // "Recording to Sense server only works with MS-PCM or G.711 codec at 8000 Hz sampling frequency. Please check hardware and codec tabs!"
				return FALSE;
			}

			if(!GetTempPath(sizeof(buffer), buffer))
				strcpy(buffer, "C:\\");
		}
		else
			strcpy(buffer, X_path);

		if (*buffer && buffer[strlen(buffer)-1] != '\\')
			strcat(buffer, "\\");

		CTime now = now.GetCurrentTime();                           

		if (m_SCRCTRL_filename.GetLength())
		{
			strcpy(buffer_dateiname, m_SCRCTRL_filename.GetBuffer(0));
			m_SCRCTRL_filename = "";
		}
		else
		{
			sprintf(buffer_dateiname, "%-2.2s%04d%02d%02d-%02d%02d%02d.wav", X_initialen, now.GetYear(), now.GetMonth(), now.GetDay(), now.GetHour(), now.GetMinute(), now.GetSecond());
		}
		strcat(buffer, buffer_dateiname);

		char formatstr[30];
		LANG2BUFFER(IDS_STRING13, formatstr);
		if (*formatstr == '*') // '*' bedeutet umgekehrte Reihenfolge in der englischen Version
			datum.Format(formatstr+1, now.GetYear(), now.GetMonth(), now.GetDay());
		else	// deutsches Datumsformat: %02d.%02d.%04d -- outdated with v1.74
			datum.Format(formatstr, now.GetDay(),  now.GetMonth(),  now.GetYear());
		zeit.Format ("%02d:%02d:%02d", now.GetHour(), now.GetMinute(), now.GetSecond());

		if (!bMonitor) m_aufnahmestartzeit = now;
	}
	if (bMonitor) 
		cp = NULL;
	else
	{
		cp = buffer;
	}
	int n = WaveIn_Open(cp, (unsigned int)X_aufnahmegeraet, 1, X_samplingrate, X_aufloesung, X_codec_id, X_format_wfx);
	if (!n)
	{
		if (odbAufnahme.GetState() == AUTOMATIK_STOP)
			OnAufnahme(); // damit keine weiteren Fehlermeldungen kommen
		//LANG_MESSAGEBOX2(IDS_STRING14, MB_ICONEXCLAMATION); // "Aufnahme konnte nicht gestartet werden"
		return FALSE;
	}
	else	// recording was started successfully
	{
		WaveIn_Start();
		if (!bMonitor) 
		{
			if (aufnahme_datensatz) delete aufnahme_datensatz;
			CString str1, str2, str3;
			str1.Format("%d", X_codec); str2.Format("%d", X_format); str3.Format("%d", X_modus);
			if (strlen(buffer_dateiname) >= 3) strcpy(buffer_dateiname+strlen(buffer_dateiname)-3, "trs");
			aufnahme_datensatz = new TMZeile((CString)buffer_dateiname, (CString)X_initialen, (CString)"", (CString)"", datum, zeit, str1, str2, str3, (CString)"");
			m_SCRCTRL_get_last_filename = buffer_dateiname;
			GetDlgItem(IDC_GESPRAECHSPARTNER)->EnableWindow(TRUE);
			GetDlgItem(IDC_NOTIZEN)->EnableWindow(TRUE);
			if (X_vergroessern_bei_pegel)
				if (!X_Locked && !*X_master_passwort)
				{
					SetTimer(9, X_vergroessern_bei_pegel*1000, NULL);
				}
		}
		return TRUE;
	}
}

void CTelArPropertyPage1::OnAbbrechen() 
{
	static BOOL bDSA207displayed = FALSE;

	if (odbAufnahme.GetState() == AUFNAHME_BEENDEN) 
	{
		// "This recording will be deleted  Did you really want to cancel recording (Y/N)?"
		if (DSAGetStoredValue(IDS_STRING208) || DSAMessageBox(IDS_STRING208, MB_YESNO) == IDYES)
		{
			WaveIn_Stop();
			WaveIn_Close();
			Normalisieren();
		}
		else 
			return;
	}	
	else if (odbAufnahme.GetState() == AUTOMATIK_STOP) 
	{
		if (bDSA207displayed) return;
		if (!GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled())
		{	// "Warning: The recording will not be stored if you proceed and auto-recording will be disabled. Really cancel recording?"
			//  question asked before			 or question answered with 'yes'	?
			CTime now = now.GetCurrentTime();                           
			if ((X_Nichtbeachtung && (int)(((CTimeSpan)(now-m_aufnahmestartzeit)).GetTotalSeconds()) < X_Nichtbeachtung)
				|| DSAGetStoredValue(IDS_STRING207))
			{
				WaveIn_Stop();
				WaveIn_Close();
				Normalisieren();
			}
			else
			{
				bDSA207displayed = TRUE;
				if (DSAMessageBox(IDS_STRING207, MB_YESNO) == IDYES)
				{
					bDSA207displayed = FALSE;
					WaveIn_Stop();
					WaveIn_Close();
					Normalisieren();					
				}
				else
				{
					bDSA207displayed = FALSE;
					return;
				}
			}
		}
	}	
	else 
		return;

	char buffer[2000];
	strcpy(buffer, X_path);
	if (*buffer && buffer[strlen(buffer)-1] != '\\')
		strcat(buffer, "\\");
	strcat(buffer, (LPCSTR)aufnahme_datensatz->Spalte(SPID_DATEINAME));
	if (strlen(buffer) >= 3) strcpy(buffer+strlen(buffer)-3, "wav");
	if (!DeleteFile(buffer))
	{
		char fmt[2000], buffer2[2000];
		LANG2BUFFER(IDS_STRING28, fmt);
		sprintf(buffer2, fmt, buffer);
		AfxMessageBox(buffer2, MB_ICONSTOP);
	}
}

#ifdef TAPI
void CTelArPropertyPage1::TAPIUpdateCallID(ITBasicCallControl * gpCall)
{
	if (X_vergroessern_bei_pegel && !X_Locked && !*X_master_passwort)
	{
		((CTelArPropertySheet *)GetParent())->SetActivePage(0);
		AfxGetMainWnd()->SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);					
		AfxGetMainWnd()->SetForegroundWindow();
		AfxGetMainWnd()->SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);					
		AfxGetMainWnd()->SetFocus();
	}

    //
    // get the address object of this call -- currently not used -- then get caller ID
    //

	CString csReference;
	GetDlgItemText(IDC_GESPRAECHSPARTNER, csReference);
	if (!csReference.IsEmpty()) return;

    ITCallInfo *            pCallInfo;
    ITAddress *             pAddress;

    HRESULT hr = gpCall->QueryInterface( IID_ITCallInfo, (void**)&pCallInfo );

    if ( FAILED(hr) )
    {
        gpCall->Release();
        gpCall = NULL;

        return;
    }

    hr = pCallInfo->get_Address( &pAddress );

    if ( FAILED(hr) )
    {
		pCallInfo->Release();
        gpCall->Release();
        gpCall = NULL;

        return;
    }

	ITAddressCapabilities * pAddressCaps;
	long lType = 0;
	hr = pAddress->QueryInterface(IID_ITAddressCapabilities, (void**)&pAddressCaps);

    if ( FAILED(hr) )
    {
		pAddress->Release();
		pCallInfo->Release();
        gpCall->Release();
        gpCall = NULL;

        return;
    }

	// get the caller id!

	CString csCallerName;
	{
		BSTR bstrName;

		hr = pCallInfo->get_CallInfoString(CIS_CALLERIDNAME, &bstrName);		

		if (hr == S_OK)
		{
			int nSize = (int)wcslen(bstrName);
			WideCharToMultiByte(CP_ACP, 0, bstrName, nSize, csCallerName.GetBuffer(nSize+1), nSize+1, NULL, NULL);
			csCallerName.GetBuffer(nSize+1)[nSize] = '\0';
			csCallerName.ReleaseBuffer();
			::SysFreeString(bstrName);
		}
	}

	CString csCallerNumber;
	{
		BSTR bstrNumber;

		hr = pCallInfo->get_CallInfoString(CIS_CALLERIDNUMBER, &bstrNumber);		

		if (hr == S_OK)
		{
			int nSize = (int)wcslen(bstrNumber);
			WideCharToMultiByte(CP_ACP, 0, bstrNumber, nSize, csCallerNumber.GetBuffer(nSize+1), nSize+1, NULL, NULL);
			csCallerNumber.GetBuffer(nSize+1)[nSize] = '\0';
			csCallerNumber.ReleaseBuffer();
			::SysFreeString(bstrNumber);
		}
	}

	CString csCalledName;
	{
		BSTR bstrName;

		hr = pCallInfo->get_CallInfoString(CIS_CALLEDIDNAME, &bstrName);		

		if (hr == S_OK)
		{
			int nSize = (int)wcslen(bstrName);
			WideCharToMultiByte(CP_ACP, 0, bstrName, nSize, csCalledName.GetBuffer(nSize+1), nSize+1, NULL, NULL);
			csCalledName.GetBuffer(nSize+1)[nSize] = '\0';
			csCalledName.ReleaseBuffer();
			::SysFreeString(bstrName);
		}
	}

	CString csCalledNumber;
	{
		BSTR bstrNumber;

		hr = pCallInfo->get_CallInfoString(CIS_CALLEDIDNUMBER, &bstrNumber);		

		if (hr == S_OK)
		{
			int nSize = (int)wcslen(bstrNumber);
			WideCharToMultiByte(CP_ACP, 0, bstrNumber, nSize, csCalledNumber.GetBuffer(nSize+1), nSize+1, NULL, NULL);
			csCalledNumber.GetBuffer(nSize+1)[nSize] = '\0';
			csCalledNumber.ReleaseBuffer();
			::SysFreeString(bstrNumber);
		}
	}

	if (csCallerName.GetLength()) 
		csCallerName = csCallerName + (CString)" (" + csCallerNumber + ")";
	else
		csCallerName = csCallerNumber;

	if (csCalledName.GetLength()) 
		csCalledName = csCalledName + (CString)" (" + csCalledNumber + ")";
	else
		csCalledName = csCalledNumber;

	if (csCallerName.IsEmpty() && csCalledName.IsEmpty())
		; //csReference = "";
	else if (!csCallerName.IsEmpty() && !csCalledName.IsEmpty())
		csReference = csCallerName + " -> " + csCalledName;
	else if (!csCalledName.IsEmpty())
		csReference = (CString)"-> " + csCalledName;
	else if (!csCallerName.IsEmpty())
		csReference = csCallerName + " ->";

	SetDlgItemText(IDC_GESPRAECHSPARTNER, csReference);

    pAddress->Release();

	pCallInfo->Release();
}

void CTelArPropertyPage1::TAPIConnected(ITBasicCallControl * gpCall)
{
	// automatische Aufnahme starten
	/* if (GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled()) XXXXXXXXXXXXXXX  anders! */
	{
		WaveIn_Stop();
		WaveIn_Close();
		nRecordingPeak = -1;
		if (Record(FALSE))
		{
			char tmpbuf[200];
			LANG2BUFFER(IDS_STRING17, tmpbuf); // "automatische Aufnahme läuft"

			GetDlgItem(IDC_AUFNAHME)->EnableWindow(FALSE);
			GetDlgItem(IDC_ABBRECHEN)->EnableWindow(TRUE);
			GetDlgItem(IDC_LETZTE_AUFNAHME)->EnableWindow(FALSE);
			ModifyIconTip(GetSafeHwnd(), tmpbuf);
			TAPIUpdateCallID(gpCall);
		}
	}
}

void CTelArPropertyPage1::TAPIDisconnected(ITBasicCallControl * gpCall)
{
	if (GetDlgItem(IDC_NOTIZEN)->IsWindowEnabled()/* && !GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled() XXXXXXXXXXX anders! */) 
	{
		CTime now = now.GetCurrentTime();																					// change here and
		if (X_Nichtbeachtung == 0 || (int)(((CTimeSpan)(now-m_aufnahmestartzeit)).GetTotalSeconds()) >= X_Nichtbeachtung)	// in OnAbbrechen()
		{
			WaveIn_OpenMicrophone();
			odbMute.SetState(MUTE_MICROPHONE);
			WaveIn_Stop();
			WaveIn_Close();
			AufnahmedatensatzSchreiben();
			KillTimer(5);
			if (Record(TRUE))
			{
				char tmpbuf[200];
				LANG2BUFFER(IDS_STRING214, tmpbuf); // "Warte auf TAPI-Events"

				GetDlgItem(IDC_AUFNAHME)->EnableWindow(TRUE);
				GetDlgItem(IDC_ABBRECHEN)->EnableWindow(FALSE);
				GetDlgItem(IDC_LETZTE_AUFNAHME)->EnableWindow(TRUE);
				SetDlgItemText(IDC_LETZTE_AUFNAHME, C_letzte_aufnahme);
				ModifyIconTip(GetSafeHwnd(), tmpbuf);

			}
			SetTimer(5, 100, NULL);
		}
		else
		{
			OnAbbrechen();
			OnAufnahme();
		}
	}
	else
		SetDlgItemText(IDC_GESPRAECHSPARTNER, "");

	if (X_minimize_after)
		if (!X_Locked && !*X_master_passwort)
		{
			AfxGetMainWnd()->PostMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0L);
		}
}
#endif // #ifdef TAPI

void CTelArPropertyPage1::OnTimer(UINT_PTR nIDEvent) 
{
	if (nIDEvent == 5)
	{
		// recording disabled by network license failure?
		if (X_RecordingDisabled)
		{
			if ((odbAufnahme.GetState() != MANUELLE_AUFNAHME && odbAufnahme.GetState() != AUTOMATIK_START) && GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled())
			{
				WaveIn_Stop();
				WaveIn_Close();
				Normalisieren();
			}
/*			if ((odbAufnahme.GetState() == AUFNAHME_BEENDEN || odbAufnahme.GetState() == AUTOMATIK_STOP) && GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled())
			{
				WaveIn_Stop();
				WaveIn_Close();
				Normalisieren();
			}
*/		}

		char buffer[1000];
/* !!!!!!!!!!!!!!!!!!!!!!!!
		// Flickwerk:
		if (!WaveIn_ReallocBuffer())
		{
			WaveIn_Stop();
			WaveIn_Close();
			if (GetDlgItem(IDC_ABBRECHEN)->IsWindowEnabled())
				AufnahmedatensatzSchreiben();

			if (odbAufnahme.GetState() == AUTOMATIK_STOP)
			{
				if (Record(TRUE)) 
				{
					odbAufnahme.SetState(AUTOMATIK_STOP);
					//GetDlgItem(IDC_ABBRECHEN)->EnableWindow(TRUE);
					nRecordingPeak = 0;
				}
			}
		}
*/
		if (!X_modus && X_intelligent && WaveIn_GetControlToneWarning())
		{
			if (!m_bControlToneWarningDisplayed && m_nControlToneWarningCounter-- <= 0)
			{
				if (m_nControlToneWarningCounter < 0) m_nControlToneWarningCounter = 0;
				m_bControlToneWarningDisplayed = TRUE;
				LANG_MESSAGEBOX1(IDS_STRING164);
				m_nControlToneWarningCounter = 300; // halbe Minute bis wieder angezeigt
				m_bControlToneWarningDisplayed = FALSE;
			}
		}
		else
			m_nControlToneWarningCounter = 0;

		int max, min;
		WaveIn_Peaks(&max, &min);

#ifdef _DEBUG
		sprintf(buffer, "Max: %d\r\nMin: %d", max, min);
// static Schaltfläche in proppage1 einbauen, wenn gedebugged werden soll!		SetDlgItemText(IDC_TEST, buffer);
#endif
		max = (max - min) / 2; // max ist hier der absolute größte Ausschlag
		
		if (max > nRecordingPeak) nRecordingPeak = max; // den größten Ausschlag der gesamten Aufzeichnung merken

		int max_wert = max;
		max /= 200;
		memset(buffer, '|', max);
		buffer[max] = '\0';
		SetDlgItemText(IDC_PEAKLEVEL, buffer);

		// Schwellwertbestimmung und evtl. Aufnahme toggeln
		if (X_modus == 0)	// Automatische aufnahme
		{
			if (GetDlgItem(IDC_NOTIZEN)->IsWindowEnabled())
			{
				char tmpbuf[200];
				char tmpbuf2[200];

				// Status
				LANG2BUFFER(IDS_STRING156, tmpbuf); // "Autom. Aufnahme"
				LANG2BUFFER(IDS_STRING155, tmpbuf2); // ", time elapsed: %02d:%02d:%02d"
				strcat(tmpbuf, tmpbuf2);				
				// Gesprächsdauer berechnen
				CTime now = now.GetCurrentTime();
				CTimeSpan ts_dauer = now - m_aufnahmestartzeit;
				// Text zusammensetzen und in das Statusfeld schreiben
				sprintf(tmpbuf2, tmpbuf, (int)ts_dauer.GetTotalHours(), (int)ts_dauer.GetMinutes(), (int)ts_dauer.GetSeconds());

				if (X_toggle_silence - n_silence/10 >= 2 && n_silence/10 > 0)
				{
					char formatstr[100];
					LANG2BUFFER(IDS_STRING15, formatstr); // "autom. Beenden in\n%d Sekunden"
					sprintf(buffer, formatstr, X_toggle_silence - n_silence/10 - 1);
					strcat(tmpbuf2, ", ");
					strcat(tmpbuf2, buffer);
				}

				SetDlgItemText(IDC_SPEICHERN_IN, tmpbuf2);
			}
			else
				SetDlgItemText(IDC_SPEICHERN_IN, "");

			int wert = X_schwellwert * 0x8000 / 100;

			if (max_wert < wert) 
			{
				n_noise = 0;
				n_silence++;
			}
			else
			{
				n_noise++;
				n_silence = 0;
			}

			if (odbAufnahme.GetState() == MANUELLE_AUFNAHME) 
			{	// falls in den Einstellungen auf Automatik geändert wurde
				char tmpbuf[200];
				LANG2BUFFER(IDS_STRING16, tmpbuf); // "Automatik überwacht den Leitungspegel"
				odbAufnahme.SetState(AUTOMATIK_STOP);
				if (Record(TRUE))
					ModifyIconTip(GetSafeHwnd(), tmpbuf);
			} 
			else if (((X_intelligent && WaveIn_IsActiveControlTone())
				|| (!X_intelligent && n_noise/10 >= X_toggle_noise))
				&& odbAufnahme.GetState() == AUTOMATIK_STOP 
				&& GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled()) 
			{	// automatische Aufnahme starten
				WaveIn_Stop();
				WaveIn_Close();
				nRecordingPeak = -1;
				if (Record(FALSE))
				{
					char tmpbuf[200];
					LANG2BUFFER(IDS_STRING17, tmpbuf); // "automatische Aufnahme läuft"

					GetDlgItem(IDC_AUFNAHME)->EnableWindow(FALSE);
					GetDlgItem(IDC_ABBRECHEN)->EnableWindow(TRUE);
					GetDlgItem(IDC_LETZTE_AUFNAHME)->EnableWindow(FALSE);
					ModifyIconTip(GetSafeHwnd(), tmpbuf);
					if (X_vergroessern_bei_pegel)
						if (!X_Locked && !*X_master_passwort)
						{
							SetTimer(9, X_vergroessern_bei_pegel*1000, NULL);
						}
				}
			}
			else if (((X_intelligent && !WaveIn_IsActiveControlTone())
				|| (!X_intelligent && n_silence/10 >= X_toggle_silence)
				/*|| X_RecordingDisabled*/)
				&& odbAufnahme.GetState() == AUTOMATIK_STOP
				&& !GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled())
			{	// automatische Aufnahme beenden
				CTime now = now.GetCurrentTime();																					// change here and
				if (X_Nichtbeachtung == 0 || (int)(((CTimeSpan)(now-m_aufnahmestartzeit)).GetTotalSeconds()) >= X_Nichtbeachtung)	// in OnAbbrechen()
				{
					WaveIn_OpenMicrophone();
					odbMute.SetState(MUTE_MICROPHONE);
					WaveIn_Stop();
					WaveIn_Close();
					KillTimer(5);
					AufnahmedatensatzSchreiben();
					if (Record(TRUE))
					{
						char tmpbuf[200];
						LANG2BUFFER(IDS_STRING16, tmpbuf); // "Automatik überwacht den Leitungspegel"

						GetDlgItem(IDC_AUFNAHME)->EnableWindow(TRUE);
						GetDlgItem(IDC_ABBRECHEN)->EnableWindow(FALSE);
						GetDlgItem(IDC_LETZTE_AUFNAHME)->EnableWindow(TRUE);
						SetDlgItemText(IDC_LETZTE_AUFNAHME, C_letzte_aufnahme);
						ModifyIconTip(GetSafeHwnd(), tmpbuf);

					}
					SetTimer(5, 100, NULL);
				}
				else
				{
					OnAbbrechen();
					OnAufnahme();
				}

				if (X_minimize_after)
					if (!X_Locked && !*X_master_passwort)
					{
						AfxGetMainWnd()->PostMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0L);
					}
			}
		}
		else if (X_modus == 1)	// manuelle Aufnahme
		{
			if (odbAufnahme.GetState() == MANUELLE_AUFNAHME) 
			{
				char tmpbuf[200];
				LANG2BUFFER(IDS_STRING18, tmpbuf); // "Zum manuellen Aufzeichnen die mittlere Maustaste doppelklicken"

				// wieder PhoneCoach Extrawurst
				if (!strcmp(C_vendor, "PhoneCoach CompuCorder"))
				{
					strcpy(tmpbuf, "Double click to open the CompuCorder");
				}
				
				ModifyIconTip(GetSafeHwnd(), tmpbuf);
				SetDlgItemText(IDC_SPEICHERN_IN, "");
			}
			else if (odbAufnahme.GetState() == AUFNAHME_BEENDEN)
			{
				char tmpbuf[200];
				char tmpbuf2[200];
				LANG2BUFFER(IDS_STRING19, tmpbuf); // "Zum Beenden der Aufnahme die mittlere Maustaste doppelklicken"
				ModifyIconTip(GetSafeHwnd(), tmpbuf);

				// Status
				LANG2BUFFER(IDS_STRING4, tmpbuf); // "Manuelle Aufnahme"
				LANG2BUFFER(IDS_STRING155, tmpbuf2); // ", time elapsed: %02d:%02d:%02d"
				strcat(tmpbuf, tmpbuf2);				
				// Gesprächsdauer berechnen
				CTime now = now.GetCurrentTime();
				CTimeSpan ts_dauer = now - m_aufnahmestartzeit;
				// Text zusammensetzen und in das Statusfeld schreiben
				sprintf(tmpbuf2, tmpbuf, (int)ts_dauer.GetTotalHours(), (int)ts_dauer.GetMinutes(), (int)ts_dauer.GetSeconds());
				SetDlgItemText(IDC_SPEICHERN_IN, tmpbuf2); 
			}

			if (odbAufnahme.GetState() == AUTOMATIK_START) 
				odbAufnahme.SetState(MANUELLE_AUFNAHME);
		}
		else if (X_modus == 2)	// TAPI is completely event-controlled, just do som GUI stuff...
		{
			SetDlgItemText(IDC_SPEICHERN_IN, "");
			if (odbAufnahme.GetState() == MANUELLE_AUFNAHME) 
			{	// falls in den Einstellungen auf Automatik geändert wurde
				char tmpbuf[200];
				LANG2BUFFER(IDS_STRING214, tmpbuf); // "TAPI überwacht den Leitungspegel"
				odbAufnahme.SetState(AUTOMATIK_STOP);
				ModifyIconTip(GetSafeHwnd(), tmpbuf);
			} 
		}
	}
	else if (nIDEvent == 6)	// 2 sec after InitDialog
	{
		KillTimer(6);

		if (!::DoConvert(X_path, "")) goto endtimer;

		// prepare index filename
		char pathfile[1000];
		strcpy(pathfile, X_path);

		if (*pathfile && pathfile[strlen(pathfile)-1] != '\\')
			strcat(pathfile, "\\");
		strcat(pathfile, INDEX_FILENAME);

		// open index file with new database format
		default_index.OpenCreate(pathfile, "");

		SetTimer(5, 100, NULL);
	}
	else if (nIDEvent == 7)
	{
		if (odbAufnahme.GetState() == AUTOMATIK_STOP && GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled())
		{
			WaveIn_Stop();
			WaveIn_Close();
			Record(TRUE);
		}
	}
	else if (nIDEvent == 8)	// recording LED blink timer
	{
		if (m_bRecordingLedBlinkState || GetDlgItem(IDC_NOTIZEN)->IsWindowEnabled())
		{
			m_bRecordingLedBlinkState = ~m_bRecordingLedBlinkState;	// change blink state

			// Set the icon in the status area of the taskbar
			NOTIFYICONDATA nid;
			nid.cbSize = sizeof(nid);
			nid.hWnd = AfxGetMainWnd()->m_hWnd;
			nid.uID = STATUS_ICON_ID;
			nid.uFlags = NIF_ICON;
			nid.uCallbackMessage = MYWM_NOTIFYICON;
			nid.hIcon = m_bRecordingLedBlinkState ? AfxGetApp()->LoadIcon(IDR_MAINFRAME_RECORDING) : AfxGetApp()->LoadIcon(IDR_MAINFRAME);
			Shell_NotifyIcon(NIM_MODIFY, &nid);
		}
	}
	else if (nIDEvent == 9)	// X_vergroessern_bei_pegel
	{
		KillTimer(9);

		if (GetDlgItem(IDC_GESPRAECHSPARTNER)->IsWindowEnabled())	// recording still active?
		{
			((CTelArPropertySheet *)GetParent())->SetActivePage(0);
			AfxGetMainWnd()->SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);					
			AfxGetMainWnd()->SetForegroundWindow();
			AfxGetMainWnd()->SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);					
			AfxGetMainWnd()->SetFocus();
			GetDlgItem(IDC_GESPRAECHSPARTNER)->SetFocus();
		}
	}

endtimer:
	CResizablePage::OnTimer(nIDEvent);
}


void CTelArPropertyPage1::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (nSBCode != SB_ENDSCROLL)
	{
		if (nSBCode == SB_PAGELEFT || nSBCode == SB_PAGERIGHT)
		{
			X_volume = 0xffff & ((CSliderCtrl *)GetDlgItem(IDC_AUSSTEUERUNG))->GetPos();
		}
		else
		{
			X_volume = 0xffff & nPos;
		}
			
		SetVolume(X_volume);
	}
	
	CResizablePage::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CTelArPropertyPage1::SetVolume(int volume)
{
	MMRESULT mmr;
	MIXERLINE ml;
	MIXERLINECONTROLS mlc;
	MIXERCONTROL mc;
	MIXERCONTROLDETAILS mcd;
	MIXERCONTROLDETAILS_UNSIGNED mcd_u;
	UINT uMxId;
	int source_line;

	if (X_nomixer) return;

	// eventuell gar kein Mixer device da?
	if (!mixerGetNumDevs()) { DF("CTelArPropertyPage1::SetVolume - !mixerGetNumDevs()"); return; }

	BOOL bOpen = FALSE;
	HWAVEIN hwi = WaveIn_GetDeviceHandle();
	if (!hwi)
	{	// wenn device handle noch nicht offen, dann extra öffnen!
		if (X_samplingrate == 0) X_samplingrate = 40100;
		bOpen = WaveIn_Open(NULL, (unsigned int)X_aufnahmegeraet, 1, X_samplingrate, X_aufloesung, X_codec_id, X_format_wfx);
		if (!bOpen) { DF("CTelArPropertyPage1::SetVolume - !bOpen"); return; }
		hwi = WaveIn_GetDeviceHandle();
	}

	mmr = mixerGetID((HMIXEROBJ)hwi, &uMxId, MIXER_OBJECTF_HWAVEIN);
	if (mmr != MMSYSERR_NOERROR)  { DF1("CTelArPropertyPage1::SetVolume - mixerGetID ret %d", (int)mmr); goto exit_wavein_close; }

	// Wavein device ermitteln
	ml.dwDestination = 0;
	ml.dwSource = 0;
	ml.cbStruct = sizeof(ml); 
	mmr = mixerGetLineInfo((HMIXEROBJ)hwi, &ml, MIXER_OBJECTF_HWAVEIN);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage1::SetVolume - mixerGetLineInfo(MIXER_OBJECTF_HWAVEIN) ret %d", (int)mmr); goto exit_wavein_close; }

	// Line-Information holen
	ml.cbStruct = sizeof(ml);
	source_line = (int)((CComboBox *)m_pTelArPropertyPage3->GetDlgItem(IDC_ANSCHLUSS))->GetItemData(X_anschluss);
	if (source_line < 0) source_line = X_anschluss;
	ml.dwSource = source_line;
	ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_WAVEIN;
	mmr = mixerGetLineInfo((HMIXEROBJ)uMxId, &ml, MIXER_GETLINEINFOF_SOURCE);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage1::SetVolume - mixerGetLineInfo(MIXER_GETLINEINFOF_SOURCE) ret %d", (int)mmr); goto exit_wavein_close; }
	if (!ml.cControls) { DF("CTelArPropertyPage1::OnSelchangeAnschluss !ml.cControls"); goto exit_wavein_close; } // WaveIn-Line hat keine Controls?
	
	// MUX-Control Information holen
	mlc.cbStruct = sizeof(mlc);
	mlc.dwLineID = ml.dwLineID;
	mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
	mlc.cControls = 1;
	mlc.cbmxctrl = sizeof(mc);
	mlc.pamxctrl = &mc;
	mmr = mixerGetLineControls((HMIXEROBJ)uMxId, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage1::SetVolume - mixerGetLineControls(MIXER_GETLINECONTROLSF_ONEBYTYPE) ret %d", (int)mmr); goto exit_wavein_close; }
	
	// MUX-Control-Detailinformationen (aktuelle Aufnahmequelle) holen
	mcd.cbStruct = sizeof(mcd);
	mcd.dwControlID = mc.dwControlID;
	mcd.cChannels = 1;
	mcd.cMultipleItems = 0;
	mcd.cbDetails = sizeof(mcd_u);
	mcd.paDetails = &mcd_u;
	mcd_u.dwValue=  volume;
	mmr = mixerSetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_GETCONTROLDETAILSF_VALUE);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage1::SetVolume - mixerSetControlDetails(MIXER_GETCONTROLDETAILSF_VALUE) ret %d", (int)mmr); goto exit_wavein_close; }

	// alle Werte zurücklsetzen
	// for (i = 0; i < mc.cMultipleItems; i++)
	// {					
	// 	pmcd_b[i].fValue = 0;
	// }
	// pmcd_b[X_anschluss].fValue = 1;

	// aktuelle Aufnahmequelle ändern
	// mmr = mixerSetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_SETCONTROLDETAILSF_VALUE);

exit_wavein_close:

	if (bOpen) WaveIn_Close();
}


void CTelArPropertyPage1::OnBeenden() 
{
#ifdef NDEBUG
	char tmpbuf[200];
	LANG2BUFFER(IDS_STRING20, tmpbuf); // "ACHTUNG: Hiermit wird der Telefonat Archiver deaktiviert."
	if (AfxMessageBox(tmpbuf, MB_ICONEXCLAMATION|MB_OKCANCEL|MB_DEFBUTTON2) == IDOK)
#endif
		AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0L);
}


// dafür sorgen, daß auch nach dem Gespräch 
// Gesprächspartner und Notizen eingegeben werden können:

void CTelArPropertyPage1::OnChangeGespraechspartner() 
{
	n_silence = 0;
}

void CTelArPropertyPage1::OnChangeNotizen() 
{
	n_silence = 0;
}
 

void CTelArPropertyPage1::OnInfo() 
{
	char titel[100];
	VEND2BUFFER(IDS_STRING6, titel);
	strcat(titel, " ");
	LoadString(GetModuleHandle("TELAR.EXE"), IDS_TITEL2, titel+strlen(titel), sizeof(titel));
	strcat(titel, " ");
	strcat(titel, version_string);	
	strcat(titel, " ");
	strcat(titel, build_string);	

	AfxGetMainWnd()->ShowWindow(SW_HIDE);
	CAboutDlg dlgAbout(titel);
	dlgAbout.DoModal();
	AfxGetMainWnd()->ShowWindow(SW_SHOW);
}

void CTelArPropertyPage1::OnLetzteAufnahme() 
{
	// Auf playback Seite blättern
	((CTelArPropertySheet *)GetParent())->SetActivePage(1);
	
	// alles außer der letzten Aufnahme deselektieren, letzte Aufnahme selektieren
	int n = ((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->GetItemCount();
	((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetRedraw(FALSE);
	BOOL bFoundRecordingWithProperID = FALSE;
	for (int i = n-1; i >= 0; i--)
	{
		if (!bFoundRecordingWithProperID)
		{
			TMZeile *zeile = ((CTelArPropertySheet *)GetParent())->m_Page2.SafeGetItemData(i);
			if (zeile->Spalte(SPID_INITIALEN) == (CString)X_initialen)
			{
				((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetItemState(i, LVIS_SELECTED, LVIS_SELECTED | LVIS_FOCUSED);
				bFoundRecordingWithProperID = TRUE;	// just play one recording
				continue;
			}
		}

		((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetItemState(i, 0, LVIS_SELECTED | LVIS_FOCUSED);
		
	}
	((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetRedraw(TRUE);

	// Playback starten
	if (bFoundRecordingWithProperID) ((CTelArPropertySheet *)GetParent())->m_Page2.OnPlay();
}



/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage2 property page

CTelArPropertyPage2::CTelArPropertyPage2() : CResizablePage(CTelArPropertyPage2::IDD)
{
	//{{AFX_DATA_INIT(CTelArPropertyPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	suchfilter = NULL;
	archivewizzard = NULL;
	nLastSelection = -1;
	csKillTheFile = "";
	csOrdner = C_standard_ordner;
	myItemData = NULL;
	myItemDataSize = 0;
	
	// drag&frop init
	m_bDragging = false;
	m_nDragIndex = -1;
	m_nDropIndex = -1;
	m_pDragImage = NULL;
	m_bCopyDropeffect = FALSE;


	// Change tab title
	LANG2BUFFER(IDS_STRING191, m_szMyTitle);	// 'Playback'
    m_psp.dwFlags |= PSP_USETITLE;
    m_psp.pszTitle = m_szMyTitle;

	pFolders = new TMTabelle(FOLDERS_FILEMAGIC, FOLDERS_FILECOLUMNS, FOLDERS_FILEVERSION);

}

CTelArPropertyPage2::~CTelArPropertyPage2()
{
	if (myItemData) ResetItemData(0); 
	delete pFolders;
}

void CTelArPropertyPage2::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTelArPropertyPage2)
	DDX_Control(pDX, IDC_LISTE, m_ListeLB);
	DDX_Control(pDX, IDC_ORDNER, m_OrdnerLB);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTelArPropertyPage2, CResizablePage)
	//{{AFX_MSG_MAP(CTelArPropertyPage2)
	ON_LBN_SELCHANGE(IDC_LISTE, OnSelchangeListe)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_REW, OnRew)
	ON_BN_CLICKED(IDC_FF, OnFf)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_FF2, OnFf2)
	ON_BN_CLICKED(IDC_REW2, OnRew2)
	ON_WM_HSCROLL()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_SUCHEN, OnSuchen)
	ON_BN_CLICKED(IDC_EXPORT, OnExport)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_ADD_ORDNER, OnAddOrdner)
	ON_BN_CLICKED(IDC_DEL_ORDNER, OnDelOrdner)
	ON_BN_CLICKED(IDC_EDIT_ORDNER, OnEditOrdner)
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	ON_WM_COMPAREITEM()
	ON_WM_DELETEITEM()
	ON_BN_CLICKED(IDC_ARCHIVE, OnArchive)
    ON_MESSAGE(WM_QUICKLIST_GETLISTITEMDATA, OnGetListItem) 
	ON_NOTIFY(LVN_DELETEITEM, IDC_LISTE, OnDeleteitemListe)
	ON_NOTIFY(LVN_BEGINDRAG, IDC_LISTE, OnBegindragListe)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_ORDNER, OnItemchangedOrdner)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LISTE, OnEndlabeleditListe)
	ON_NOTIFY(LVN_BEGINLABELEDIT, IDC_LISTE, OnBeginlabeleditListe)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_NOTIFY(NM_DBLCLK, IDC_LISTE, &CTelArPropertyPage2::OnNMDblclkListe)
	ON_WM_SIZE()
END_MESSAGE_MAP()


BOOL CTelArPropertyPage2::OnInitDialog() 
{
	DF("CTelArPropertyPage2::OnInitDialog()");
	CResizablePage::OnInitDialog();

	// preset layout
	AddAnchor(IDC_ORDNER, TOP_LEFT, BOTTOM_LEFT);
	AddAnchor(IDC_LISTE, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_ADD_ORDNER, BOTTOM_LEFT);
	AddAnchor(IDC_DEL_ORDNER, BOTTOM_LEFT);
	AddAnchor(IDC_EDIT_ORDNER, BOTTOM_LEFT);
	AddAnchor(IDC_ARCHIVE, BOTTOM_LEFT);
	AddAnchor(IDC_REW2, BOTTOM_LEFT);
	AddAnchor(IDC_REW, BOTTOM_LEFT);
	AddAnchor(IDC_PLAY, BOTTOM_LEFT);
	AddAnchor(IDC_PAUSE, BOTTOM_LEFT);
	AddAnchor(IDC_STOP, BOTTOM_LEFT);
	AddAnchor(IDC_FF, BOTTOM_LEFT);
	AddAnchor(IDC_FF2, BOTTOM_LEFT);
	AddAnchor(IDC_EDIT, BOTTOM_LEFT);
	AddAnchor(IDC_DELETE, BOTTOM_LEFT);	
	AddAnchor(IDC_SUCHEN, BOTTOM_LEFT);
	AddAnchor(IDC_EXPORT, BOTTOM_LEFT);
	AddAnchor(IDC_SPEAKER_ICON, BOTTOM_LEFT);
	AddAnchor(IDC_POSITION, BOTTOM_LEFT);	
	AddAnchor(IDC_SLIDER, BOTTOM_LEFT);	
	AddAnchor(IDC_SPEAKERVOLUME, BOTTOM_LEFT);	
	AddAnchor(IDC_VENDOR_LOGO_FRAME, BOTTOM_RIGHT);	

	TRACE0("CTelArPropertyPage2::OnInitDialog()\n");
	CResizablePage::OnInitDialog();

	ListView_SetExtendedListViewStyleEx(m_ListeLB.m_hWnd, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
	ListView_SetExtendedListViewStyleEx(m_ListeLB.m_hWnd, LVS_EX_SUBITEMIMAGES , LVS_EX_SUBITEMIMAGES );
	//ListView_SetExtendedListViewStyleEx(m_ListeLB.m_hWnd, LVS_EX_TRACKSELECT, LVS_EX_TRACKSELECT );
	ListView_SetExtendedListViewStyleEx(m_ListeLB.m_hWnd, LVS_EX_CHECKBOXES, LVS_EX_CHECKBOXES );
	
	m_imgList.Create(IDB_IMAGE_LIST, 16, ILC_COLOR4, RGB(255, 255, 255));
	//m_imgLargeList.Create(IDB_IMAGE_LIST_LARGE, 32, ILC_COLOR4, RGB(255, 255, 255));

	//m_ListeLB.SetBackgroundColor(RGB(255,255,255));

	m_ListeLB.SetImageList(&m_imgList, LVSIL_SMALL);

	char buffer[1000];
	LANG2BUFFER(IDS_STRING187, buffer);
	m_ListeLB.InsertColumn(0, buffer, LVCFMT_LEFT, 23);		// ID
	LANG2BUFFER(IDS_STRING188, buffer);
	m_ListeLB.InsertColumn(1, buffer, LVCFMT_LEFT, 110);	// Date/Time
	LANG2BUFFER(IDS_STRING189, buffer);
	m_ListeLB.InsertColumn(2, buffer, LVCFMT_LEFT, 50);		// Dur.
	LANG2BUFFER(IDS_STRING125, buffer);
	m_ListeLB.InsertColumn(3, buffer, LVCFMT_LEFT, 70);		// Reference
	LANG2BUFFER(IDS_STRING126, buffer);
	m_ListeLB.InsertColumn(4, buffer, LVCFMT_LEFT, 121);		// Note

#ifndef QUICKLIST_NOEMPTYMESSAGE	
	char empmessbuf[1000];
	LANG2BUFFER(IDS_STRING186, empmessbuf);
	CString csEmpMessBuf = empmessbuf;
	m_ListeLB.SetEmptyMessage(csEmpMessBuf);
#endif

	m_ListeLB.EnableToolTips(TRUE);

	// Ordner CListCtrl
	LANG2BUFFER(IDS_STRING190, buffer);
	m_OrdnerLB.InsertColumn(0, buffer, LVCFMT_LEFT, 66);		// 'Folders'	

	//((CDDListBox *)GetDlgItem(IDC_ORDNER))->Initialize();

	SetTimer(1, 1000, NULL);
	SetTimer(3, 10000, NULL);	// jede Minute nach zu löschenden Dateien checken
	bPlaying = FALSE;
	bSeeking = FALSE;
	
	// Button-Bitmaps
	// ordner
	AddOrdnerBmp.LoadBitmap(IDB_ADD_ORDNER);
	((CButton *)GetDlgItem(IDC_ADD_ORDNER))->SetBitmap(AddOrdnerBmp);
	DelOrdnerBmp.LoadBitmap(IDB_DEL_ORDNER);
	((CButton *)GetDlgItem(IDC_DEL_ORDNER))->SetBitmap(DelOrdnerBmp);
	EditOrdnerBmp.LoadBitmap(IDB_EDIT_ORDNER);
	((CButton *)GetDlgItem(IDC_EDIT_ORDNER))->SetBitmap(EditOrdnerBmp);
	ArchiveOrdnerBmp.LoadBitmap(IDB_DISC);
	((CButton *)GetDlgItem(IDC_ARCHIVE))->SetBitmap(ArchiveOrdnerBmp);
	// playback group
	Rew2Bmp.LoadBitmap(IDB_REW2);
	((CButton *)GetDlgItem(IDC_REW2))->SetBitmap(Rew2Bmp);
	RewBmp.LoadBitmap(IDB_REW);
	((CButton *)GetDlgItem(IDC_REW))->SetBitmap(RewBmp);
	PlayBmp.LoadBitmap(IDB_PLAY);
	((CButton *)GetDlgItem(IDC_PLAY))->SetBitmap(PlayBmp);
	PauseBmp.LoadBitmap(IDB_PAUSE);
	((CButton *)GetDlgItem(IDC_PAUSE))->SetBitmap(PauseBmp);
	StopBmp.LoadBitmap(IDB_STOP);
	((CButton *)GetDlgItem(IDC_STOP))->SetBitmap(StopBmp);
	FfBmp.LoadBitmap(IDB_FF);
	((CButton *)GetDlgItem(IDC_FF))->SetBitmap(FfBmp);
	Ff2Bmp.LoadBitmap(IDB_FF2);
	((CButton *)GetDlgItem(IDC_FF2))->SetBitmap(Ff2Bmp);
	// sonstige
	SuchenBmp.LoadBitmap(IDB_SUCHEN);
	((CButton *)GetDlgItem(IDC_SUCHEN))->SetBitmap(SuchenBmp);
	ExportBmp.LoadBitmap(IDB_EXPORT);
	((CButton *)GetDlgItem(IDC_EXPORT))->SetBitmap(ExportBmp);
	EditBmp.LoadBitmap(IDB_EDIT);
	((CButton *)GetDlgItem(IDC_EDIT))->SetBitmap(EditBmp);
	DeleteBmp.LoadBitmap(IDB_DELETE);
	((CButton *)GetDlgItem(IDC_DELETE))->SetBitmap(DeleteBmp);

	// Speaker volume slider initialization
	((CSliderCtrl *)GetDlgItem(IDC_SPEAKERVOLUME))->SetRange(0, 0xffff);
	DWORD dwVolume;
	MMRESULT res;
	res = waveOutGetVolume((HWAVEOUT)X_aufnahmegeraet, &dwVolume);
	if (res == MMSYSERR_NOERROR)
	{
		// take the channel whose volume is higher and set it as slider position
		WORD wVolume;
		if (LOWORD(dwVolume) > HIWORD(dwVolume))
			wVolume = LOWORD(dwVolume);
		else
			wVolume = HIWORD(dwVolume);

		((CSliderCtrl *)GetDlgItem(IDC_SPEAKERVOLUME))->SetPos(0xffff - wVolume);
	}
	else
	{
		DF1("CTelArPropertyPage2::OnInitDialog() -- waveOutGetVolume returned error %ud", (DWORD)res);
	}

	return TRUE;
}

void CTelArPropertyPage2::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	CRect r;

	// Update list box column widths
	if (m_ListeLB.m_hWnd)
	{
		m_ListeLB.GetWindowRect(&r);
		int nNoteColWidth = r.right - r.left - 273;
		m_ListeLB.SetColumnWidth(4, nNoteColWidth*3/4);
		m_ListeLB.SetColumnWidth(3, 70+nNoteColWidth-(nNoteColWidth*3/4));	// give some of the extra space to the reference column
	}

	GetClientRect(&r);
	InvalidateRect(r);
}

// Hintergrundbitmap malen
BOOL CTelArPropertyPage2::OnEraseBkgnd( CDC* pDC )
{
	CResizablePage::OnEraseBkgnd(pDC);

	char buffer[200];
	VEND2BUFFER(IDS_STRING1, buffer);

	CRect r, fr;

	if (!strcmp(buffer, "PhoneCoach CompuCorder"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_PHONECOACH_ON_GREY, &fr, 0);
	}
	else if (!strcmp(buffer, "Actimax"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_ACTIMAX_ON_GREY, &fr, 0);
	}
	else
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_RETELL_ON_GREY, &fr, 0);
	}
	return TRUE;
}

//--- Drag & Drop ---

BOOL CTelArPropertyPage2::PreTranslateMessage(MSG* pMsg) 
{
    if(pMsg->message==WM_KEYDOWN)
    {
        if(pMsg->wParam==VK_CONTROL)
			m_bCopyDropeffect = TRUE;            

	    if (m_bDragging)
			SetDragCursor(CPoint(0,0));
    }	
	
    if(pMsg->message==WM_KEYUP)
    {
        if(pMsg->wParam==VK_CONTROL)
			m_bCopyDropeffect = FALSE;            

	    if (m_bDragging)
			SetDragCursor(CPoint(0,0));
    }	
		
	return CResizablePage::PreTranslateMessage(pMsg);
}

void CTelArPropertyPage2::OnBegindragListe(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    
	POSITION p = m_ListeLB.GetFirstSelectedItemPosition();

	m_nDragIndex = pNMListView->iItem;

	SetDragCursor(pNMListView->ptAction);
	
    //// Set dragging flag and others
    m_bDragging = TRUE;    //we are in a drag and drop operation
    m_nDropIndex = -1;    //we don't have a drop index yet
    m_pDragList = &m_ListeLB; //make note of which list we are dragging from
    m_pDropWnd = &m_ListeLB;    //at present the drag list is the drop list

	*pResult = 0;
}

void CTelArPropertyPage2::SetDragCursor(POINT mousepos) 
{
    if (m_bDragging)
    {
        ReleaseCapture();

        // temporyrily End dragging image
        m_pDragImage->DragLeave(GetDesktopWindow ());
        m_pDragImage->EndDrag();
	}

    //// Create a drag image
    POINT pt;
    int nOffset = -10; //offset in pixels for drag image 
                           //(positive is up and to the left; 
                           //neg is down and to the right)
//    if(m_ListeLB.GetSelectedCount() > 1) //more than one item is selected
    pt.x = nOffset;
    pt.y = nOffset;

	if (m_pDragImage) delete m_pDragImage;
    m_pDragImage = m_ListeLB.CreateDragImage(m_nDragIndex, &pt);
    ASSERT(m_pDragImage); //make sure it was created
    //We will call delete later (in LButtonUp) to clean this up

	CBitmap bitmap;
	if(m_ListeLB.GetSelectedCount() > 1) //more than 1 item in list is selected
		if (m_bCopyDropeffect)
			bitmap.LoadBitmap(IDB_DRAGDROP_MULTI_COPY);
		else
			bitmap.LoadBitmap(IDB_DRAGDROP_MULTI);
	else
		if (m_bCopyDropeffect)
		  bitmap.LoadBitmap(IDB_DRAGDROP_COPY);
		else
		  bitmap.LoadBitmap(IDB_DRAGDROP);
	m_pDragImage->Replace(0, &bitmap, &bitmap);

    //// Change the cursor to the drag image
    ////    (still must perform DragMove() in OnMouseMove() to show it moving)
    m_pDragImage->BeginDrag(0, CPoint(nOffset, nOffset - 4));
    m_pDragImage->DragEnter(GetDesktopWindow(), mousepos);

    //// Capture all mouse messages
    SetCapture ();
}

void CTelArPropertyPage2::OnMouseMove(UINT nFlags, CPoint point) 
{
    if (m_bDragging)
    {
		//// Move the drag image
        CPoint pt(point);    //get our current mouse coordinates
        ClientToScreen(&pt); //convert to screen coordinates
        m_pDragImage->DragMove(pt); //move the drag image to those coordinates
        // Unlock window updates (this allows the dragging image to be shown 
                // smoothly)
        m_pDragImage->DragShowNolock(false);

        // Get the CWnd pointer of the window that is under the 
        // mouse cursor
        CWnd* pDropWnd = WindowFromPoint (pt);
        ASSERT(pDropWnd); //make sure we have a window
		
        //// If we drag outside current window we need 
                //   to adjust the highlights displayed
		if (pDropWnd == GetDlgItem(IDC_ORDNER))
		{
			TRACE1("drop index: %d\n", m_nDropIndex);
			if (m_nDropIndex != -1) //If we drag over the CListCtrl header, turn off the hover highlight
			{
				CListCtrl* pList = (CListCtrl*)pDropWnd;
				VERIFY (pList->SetItemState (m_nDropIndex, 0, LVIS_DROPHILITED));
				// redraw item
				VERIFY (pList->RedrawItems (m_nDropIndex, m_nDropIndex));
				pList->UpdateWindow ();
				m_nDropIndex = -1;
			}
			else //If we drag out of the CListCtrl altogether
			{
				CListCtrl* pList = (CListCtrl*)pDropWnd;
				int i = 0;
				int nCount = pList->GetItemCount();
				for(i = 0; i < nCount; i++)
				{
					pList->SetItemState(i, 0, LVIS_DROPHILITED);
				}
				pList->RedrawItems(0, nCount);
				pList->UpdateWindow();
			}
		}
		
        // Save current window pointer as the CListCtrl we are dropping onto
        m_pDropWnd = pDropWnd;

        // Convert from screen coordinates to drop target client coordinates
        pDropWnd->ScreenToClient(&pt);

        //If we are hovering over a CListCtrl we need to adjust the highlights
        if(pDropWnd == GetDlgItem(IDC_ORDNER))	// ->IsKindOf(RUNTIME_CLASS (CListCtrl)))
        {            
 			//Note that we can drop here
			SetCursor(LoadCursor(NULL, IDC_ARROW));
            UINT uFlags;
            CListCtrl* pList = (CListCtrl*)pDropWnd;

			if (m_nDropIndex != -1)
			{
				// Turn off hilight for previous drop target
				pList->SetItemState (m_nDropIndex, 0, LVIS_DROPHILITED);
				// Redraw previous item
				pList->RedrawItems (m_nDropIndex, m_nDropIndex);
			}
            
            // Get the item that is below cursor
            m_nDropIndex = ((CListCtrl*)pDropWnd)->HitTest(pt, &uFlags);
			if (m_nDropIndex != -1)
			{
				// Highlight it
				pList->SetItemState(m_nDropIndex, LVIS_DROPHILITED, LVIS_DROPHILITED);
			}

            // Redraw item
            pList->RedrawItems(m_nDropIndex, m_nDropIndex);
            pList->UpdateWindow();
        }
		else
		{
			//If we are not hovering over a CListCtrl, change the cursor
			// to note that we cannot drop here
			SetCursor(LoadCursor(NULL, IDC_NO));
		}
        // Lock window updates
        m_pDragImage->DragShowNolock(true);
    }

	CResizablePage::OnMouseMove(nFlags, point);
}


void CTelArPropertyPage2::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_bDragging)
    {
        // Release mouse capture, so that other controls 
        // can get control/messages
        ReleaseCapture ();

        // Note that we are NOT in a drag operation
        m_bDragging = FALSE;

        // End dragging image
        m_pDragImage->DragLeave (GetDesktopWindow ());
        m_pDragImage->EndDrag ();
        delete m_pDragImage; 
		m_pDragImage = NULL;
                //must delete it because it was created at the beginning of the drag
        CPoint pt (point); //Get current mouse coordinates
        ClientToScreen (&pt); //Convert to screen coordinates
        // Get the CWnd pointer of the window that is under the mouse cursor
        CWnd* pDropWnd = WindowFromPoint (pt);
        ASSERT (pDropWnd); //make sure we have a window pointer
        // If window is CListCtrl, we perform the drop

		// release hover highlighting
        if (pDropWnd == GetDlgItem(IDC_ORDNER))
        {
 			int i = 0;
			int nCount = m_OrdnerLB.GetItemCount();
			for(i = 0; i < nCount; i++)
			{
				m_OrdnerLB.SetItemState(i, 0, LVIS_DROPHILITED);
			}
			m_OrdnerLB.RedrawItems(0, nCount);
			m_OrdnerLB.UpdateWindow();

            m_pDropList = (CListCtrl*)pDropWnd; 
            //Set pointer to the list we are dropping on

			// actual drop action:
			// Transfer data between listboxes
			{
				HCURSOR oldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));

				POSITION p = m_ListeLB.GetFirstSelectedItemPosition();
				int nCopied = 0, nFailed = 0;
				int nItemCount = m_ListeLB.GetItemCount();
				int *ppnCopied = new int[nItemCount];

				// for all selected recodings list entries...
				while (p)
				{
					int nSelected = m_ListeLB.GetNextSelectedItem(p);
					TMZeile *zeile = SafeGetItemData(nSelected);

					if (zeile)
					{
						int nRet;
						if (IDOK == (nRet = KopiereListeneintrag(m_pDragList, nSelected, m_pDropList, m_nDropIndex))) 
						{	
							// list for entries that can be safely deleted
							if (!m_bCopyDropeffect)
								ppnCopied[nCopied] = nSelected;
							nCopied++;
						}
						else 
						{
							nFailed++;
							if (nRet == IDABORT) break;
						}
					}
#if defined(_DEBUG)
					else
					{
						AfxMessageBox("SafeGetItemData() returned 0");
					}
					TRACE2("nCopied == %d  nFailed == %d\n", nCopied, nFailed);
#endif
				}

				if (!m_bCopyDropeffect)
					LoescheListeneintraege(m_pDragList, ppnCopied, nCopied);

				SetCursor(oldCursor);

				{
					CString cs;
					cs.Format("%d entries successfully copied, %d failed", nCopied, nFailed);
					liste_index.AppendAccesslog(m_bCopyDropeffect ? "Copy" : "Move", TRUE, cs.GetBuffer(0));
					DF3("CTelArPropertyPage2::OnLButtonUp: %d entries successfully %s, %d failed", nCopied, m_bCopyDropeffect ? "copied" : "moved", nFailed);
				}

				delete ppnCopied;
			}
        }
    }
	
	CResizablePage::OnLButtonUp(nFlags, point);
}

void CTelArPropertyPage2::OnSelchange(CWnd *child)
{
	if (child == GetDlgItem(IDC_LISTE))
		OnSelchangeListe();
//	else if (child == GetDlgItem(IDC_ORDNER))
//		OnSelchangeOrdner();
}

int CTelArPropertyPage2::KopiereListeneintrag(CListCtrl *Source, int nSourceLBItem, CListCtrl *Dest, int nDestLBItem)
{
	DF2("CTelArPropertyPage2::KopiereListeneintrag(nSourceLBItem=%d, nDestLBItem=%d)", nSourceLBItem, nDestLBItem)
	if (Source == (CListCtrl *)GetDlgItem(IDC_LISTE) && Dest == (CListCtrl *)GetDlgItem(IDC_ORDNER))
	{
		// Listenelement nach Ordner kopieren
		POSITION p = Dest->GetFirstSelectedItemPosition();

		// for all selected recodings list entries...
		if (p)
		{
			int nSelected = Dest->GetNextSelectedItem(p);

			if (nSelected == nDestLBItem)	// soll in den aktuell geöffneten Ordner kopiert werden?
			{
				LANG_MESSAGEBOX2(IDS_STRING64, MB_ICONEXCLAMATION); // The recording is already in this folder.
				return IDABORT;
			}
		}
		else
			return IDABORT;

		// Zielpfad aus Ordnerliste herausbekommen
		CString sDest;
		sDest = m_OrdnerLB.GetItemText(nDestLBItem, 0);
		TMZeile *pDestFolderZeile = pFolders->Find(0, sDest);
		TMZeile *pSourceFolderZeile = pFolders->Find(0, csOrdner);

		// Quell- und Zielpfad aufbereiten
		char DestPath[1000];
		char SourcePath[1000];
		char DestPathWithoutFilename[1000];
		char DestPathWithIndexFilename[1000];
		if (!pDestFolderZeile)
			strcpy(DestPath, X_path);
		else
			strcpy(DestPath, pDestFolderZeile->Spalte(1));
		if (!*DestPath) return IDABORT;
		if (DestPath[strlen(DestPath)-1] != '\\') strcat(DestPath, "\\");
		if (!pSourceFolderZeile)
			strcpy(SourcePath, X_path);
		else
			strcpy(SourcePath, pSourceFolderZeile->Spalte(1));
		if (!*SourcePath) return IDABORT;
		if (SourcePath[strlen(SourcePath)-1] != '\\') strcat(SourcePath, "\\");
		strcpy(DestPathWithoutFilename, DestPath);
		strcpy(DestPathWithIndexFilename, DestPathWithoutFilename);
		strcat(DestPathWithIndexFilename, INDEX_FILENAME);

		// Dateiname zu Pfaden hinzufügen
		TMZeile *zeile = SafeGetItemData(nSourceLBItem);
		if (!zeile) return IDABORT;
		strcat(DestPath, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
		strcat(SourcePath, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));

		//--- nun den Index des Dest-Ordners ergänzen ---
		BOOL bReopenDestIndex = TRUE;
		if (dest_index.IsOpen())
			if (dest_index.GetName() == DestPathWithIndexFilename)
				bReopenDestIndex = FALSE;

		// this dest index file not already open?
		if (bReopenDestIndex)
		{
			// is there an index file in the dest. folder? 
			DWORD dw = GetFileAttributes(DestPathWithoutFilename);
			if (dw == 0xFFFFFFFF)
				dest_index.OpenCreate(DestPathWithoutFilename, "");	// if not, create one & open it
			else
			{
				// check for old-style index file
				int file_version = INDEX_FILEVERSION;	
				TMTabelle tempTabelle(INDEX_FILEMAGIC, INDEX_FILECOLUMNS, INDEX_FILEVERSION);
				if (IsOldStyleIndexFile(DestPathWithIndexFilename))
				{
					if (!DoConvert(DestPathWithoutFilename, ""))
						return IDABORT;
					else
					{
						RefreshListe();
						return IDABORT;
					}
				}
			}

			if (dest_index.IsOpen()) dest_index.Close();

			if (!dest_index.Open(DestPathWithIndexFilename))
				return FALSE;
		}

		int nMsgBoxRet;
		do
		{
			if (!CopyFile((LPCSTR)SourcePath, (LPCSTR)DestPath, FALSE)) 
			{
				char buffer[1000];
				LANG2BUFFER(IDS_STRING68, buffer);
				CString csErrorMsg;
				csErrorMsg.Format(buffer, SourcePath);
				nMsgBoxRet = AfxMessageBox(csErrorMsg.GetBuffer(0), MB_ABORTRETRYIGNORE);
				if (nMsgBoxRet == IDABORT) // Recording couldnt be kopied due to filesystem error. Please check source and destination folders.
				{
					DF2("CopyFile %s -> %s -- Recording couldn't be copied due to filesystem error.", SourcePath, DestPath)
					return IDABORT;
				}
			}
			else
			{
				DF2("CopyFile %s -> %s", SourcePath, DestPath);
				nMsgBoxRet = IDOK; // IDOK means: no msgbox shown, everything ok

				// If copied from CDROM, clear read-only attribute
				DWORD dwFileAttr = GetFileAttributes((LPCSTR)DestPath);
				if (dwFileAttr & FILE_ATTRIBUTE_READONLY)
					SetFileAttributes((LPCSTR)DestPath, dwFileAttr & ~FILE_ATTRIBUTE_READONLY);
			}
		}
		while (nMsgBoxRet == IDRETRY);
/*
		// find out if recording already exists
		{
			try
			{
				liste_index.m_pWorkspace->BeginTrans();
				CDaoQueryDef editQD(&liste_index);
				CString csSQL;
				csSQL.Format("SELECT * FROM Recordings WHERE f4 = '%s' AND f5 = '%s' AND f1 = '%s';", zeile->Spalte(SPID_DATUM), zeile->Spalte(SPID_ZEIT), zeile->Spalte(SPID_INITIALEN));
				editQD.Create("", csSQL);
		//		editQD.Open(&recordingsQD, dbOpenDynaset);
			}
			catch( CADOException* e )
			{
				if (liste_index.m_show_messages)
					AfxMessageBox( 
							e->m_pErrorInfo->m_strDescription, 
							MB_ICONEXCLAMATION );
				liste_index.AppendAccesslog("Edit", FALSE, e->m_pErrorInfo->m_strDescription.GetBuffer(0));
				DF(e->m_pErrorInfo->m_strDescription.GetBuffer(0));
				e->Delete();
				liste_index.m_pWorkspace->Rollback();
				return;
			}
*/

	//	if (dest_index.SeekRecordingDateTimeID(zeile))	// if recording already exists

		// see if existing record matches the one to copy, if existing: overwrite, if not existing: append
		if (nMsgBoxRet == IDOK)
		{
			TMZeile dummy;
			int old_show_messages = dest_index.m_show_messages;	
			dest_index.m_show_messages = FALSE;	// suppress message if record not found
			int bSeekReturn = dest_index.SeekRecordingByDateTimeID(zeile);
			if (bSeekReturn) 
				bSeekReturn = dest_index.GetNextRecording(&dummy);
			if (bSeekReturn) dest_index.EndSeekRecording();
			dest_index.m_show_messages = old_show_messages;
			if (bSeekReturn)
			{
				if (!dest_index.UpdateRecordingByDateTimeID(zeile))	
				{
					LANG_MESSAGEBOX2(IDS_STRING56, MB_ICONSTOP);	// The changes made to the list item couldn't be saved to the archive index file.
					return IDIGNORE;
				}
				int n = dest_index.m_bIsSQLite ? dest_index.m_sqlite.GetChanges() : dest_index.GetRecordsAffected();
				if (n) 
					dest_index.AppendAccesslog("Copy overwrite", TRUE, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
			}
			else
			{
				dest_index.AppendAccesslog("Copy inserted", TRUE, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
				if (!dest_index.AppendRecording(zeile))		
				{
					LANG_MESSAGEBOX2(IDS_STRING56, MB_ICONSTOP);	// The changes made to the list item couldn't be saved to the archive index file.
					return IDIGNORE;
				}
			}
		}

		return nMsgBoxRet;
	}

	return IDABORT;
}

void CTelArPropertyPage2::LoescheListeneintraege(CListCtrl *lb, int *pLBItem, int n)
{
	DF1("CTelArPropertyPage2::LoescheListeneintraege(n=%d)", n)
	if (lb == (CListCtrl *)GetDlgItem(IDC_LISTE))
	{
		int i, failed;
		CString password;

		HCURSOR oldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));

		// Liste der Dateinamen erstellen
		for (i = 0, failed = 0; i < n; i++)
		{
			TMZeile *zeile = SafeGetItemData(pLBItem[i]);

			if (zeile)
			{
				BOOL bDeleteFile = TRUE;

				// check for password
				while (atoi((LPCSTR)zeile->Spalte(SPID_GESCHUETZT)))
				{
					if (password == "")
					{   // mit PW und Dateinamen geschützt:
						CString passwort_buffer;

						{	// Passwortabfrage:
							int idd;
							
							if (!strcmp(C_language, "D")) 
								idd = IDD_PASSWORT_CHECK;
							else if (!strcmp(C_language, "GB")) 
								idd = IDD_GB_PASSWORT_CHECK;
							else if (!strcmp(C_language, "CZ")) 
								idd = IDD_CZ_PASSWORT_CHECK;
							else if (!strcmp(C_language, "NL")) 
								idd = IDD_NL_PASSWORT_CHECK;
							else if (!strcmp(C_language, "PL")) 
								idd = IDD_PL_PASSWORT_CHECK;
							else 
								idd = IDD_E_PASSWORT_CHECK;

							CPasswortCheckDlg dlg(idd, &passwort_buffer, this);
							if (dlg.DoModal() != IDOK) return;
						}
						passwort_buffer.TrimLeft();
						passwort_buffer.TrimRight();
						password = passwort_buffer; 
					}

					CString pw = password + zeile->Spalte(SPID_DATEINAME); // pw=="": nur mit Dateinamen geschützt

					// check if it's the right password
					char buffer[1000];
					TMZeile *p = pFolders->Find(0, csOrdner);
					if (!p)
						strcpy(buffer, X_path);
					else
						strcpy(buffer, (LPCSTR)p->Spalte(1));

					if (*buffer && buffer[strlen(buffer)-1] != '\\')
						strcat(buffer, "\\");
					strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
					char tempfile[1000];
					strcpy(tempfile, buffer);
					strcat(tempfile, ".tmp");
					if (DecryptFile((CString)buffer, (CString)tempfile, pw))
					{
						DeleteFile(tempfile);
						bDeleteFile = TRUE;
						break;
					}
					else
					{	
						char buffer2[2000];
						LANG2BUFFER(IDS_STRING39, buffer2);
						int nReturn = AfxMessageBox(buffer2, MB_ABORTRETRYIGNORE);
						if (nReturn == IDIGNORE)
						{
							bDeleteFile = FALSE;
							break;
						}
						else if (nReturn == IDABORT)
						{
							bDeleteFile = FALSE;
							failed += n - i;
							goto EndDeleteLoop;
						}
						else 
							password = "";	// retry with different password
					}
				}

				if (bDeleteFile && liste_index.DeleteRecordingByDateTimeID(zeile))
				{
					char buffer[1000];
					TMZeile *p = pFolders->Find(0, csOrdner);
					if (!p)
						strcpy(buffer, X_path);
					else
						strcpy(buffer, (LPCSTR)p->Spalte(1));

					if (*buffer && buffer[strlen(buffer)-1] != '\\')
						strcat(buffer, "\\");

					// delete file physically on hard drive
					strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
					if (!DeleteFile(buffer))
					{
						if (GetFileAttributes(buffer) != 0xFFFFFFFF)	// does exist?
						{
							// rollback if delete failed and file exists, re-append index file record
							liste_index.AppendRecording(zeile);
							pLBItem[i] = -1;	// don't delete from listbox
							strcat(buffer, " - file couldn't be deleted.");
							liste_index.AppendAccesslog("Delete", FALSE, buffer);
							liste_index.IncConfig("RecordingsCount", +1);
							failed++;
						}
					}
				}
				else
				{
					liste_index.AppendAccesslog("Delete", FALSE, "simply failed");
					failed++;
				}
			}
		}
EndDeleteLoop:

		SetCursor(oldCursor);

		// Message if some recordings were not deleted
		if (failed)
		{
			char buffer[1000], buffer2[1000];
			LANG2BUFFER(IDS_STRING62, buffer);
			sprintf(buffer2, buffer, n-failed, failed);
			AfxMessageBox(buffer2, MB_ICONSTOP);	// "Couldn't delete list entries."
			DF2("   %d deleted ok, %d entries failed", n-failed, failed)
			liste_index.AppendAccesslog("Delete", FALSE, buffer2);
		}
		else
		{
			CString cs;
			cs.Format("%d entries successfully deleted", n);
			liste_index.AppendAccesslog("Delete", TRUE, cs.GetBuffer(0));
		}

		// Wenn im Index gelöscht, jetzt auch in der Liste löschen
		if (n-failed)
		{
			for (i = n-1; i >= 0; i--)
			{	
				//if (pLBItem[i] != -1) ((CQuickList *)GetDlgItem(IDC_LISTE))->DeleteItem(pLBItem[i]);	-- doesn't work any more in virtual list control
				DeleteItemData(pLBItem[i]);
				int n = ((CQuickList *)GetDlgItem(IDC_LISTE))->GetItemCount();
				((CQuickList *)GetDlgItem(IDC_LISTE))->SetItemCount(n-1);
			}

			m_ListeLB.SetItemState(-1, 0, LVIS_SELECTED | LVIS_FOCUSED);
			m_ListeLB.SetRedraw(TRUE);
		}
	}
}

//--- Ordner-Steuerelemente ---


void CTelArPropertyPage2::OnItemchangedOrdner(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	POSITION p = m_OrdnerLB.GetFirstSelectedItemPosition();

	if (pNMListView->uChanged&LVIF_STATE) // changed state?
	{
		// changed select state to selected?
		if (!((pNMListView->uOldState)&LVIS_SELECTED) && ((pNMListView->uNewState)&LVIS_SELECTED))	
		{
			csOrdner = m_OrdnerLB.GetItemText(pNMListView->iItem, 0);
			nLastSelection = -1;
			RefreshListe();

			for (int i = 0; i < m_ListeLB.GetItemCount(); i++)
				m_ListeLB.SetItemState(i, 0, LVIS_SELECTED | LVIS_FOCUSED);
		}
	}

	*pResult = 0;
}

void CTelArPropertyPage2::RefreshOrdner()
{
	DF("CTelArPropertyPage2::RefreshOrdner()");

	m_OrdnerLB.DeleteAllItems();

	m_OrdnerLB.InsertItem(0, C_standard_ordner);

	extern CTelArApp theApp;
	char filename[1000];
	if (!theApp.GetFoldersFileName(filename, sizeof(filename))) return;

	int version = FOLDERS_FILEVERSION;
	if (!pFolders->Read(filename, &version, FALSE))
		pFolders->Write(filename); 

	if (*X_main_archive_path)
	{
		CFileFind ff;
		// ff.MatchesMask(FILE_ATTRIBUTE_DIRECTORY);
		char buffer[1000];
		strcpy(buffer, X_main_archive_path);
		if (buffer[strlen(buffer)-1] == '\\') buffer[strlen(buffer)-1] = '\0';
		strcat(buffer, "\\*");
		if (ff.FindFile(buffer))
		{
			while (TRUE)
			{
				BOOL bFound = ff.FindNextFile();

				pFolders->tabelle;
				CString dirpath = ff.GetFilePath();
				while (dirpath.Right(1) == ".") dirpath = dirpath.Left(dirpath.GetLength()-1);
				if (dirpath.Right(1) == "\\") dirpath = dirpath.Left(dirpath.GetLength()-1);
				CString test_indexfile = dirpath + "\\" + INDEX_FILENAME;
				DWORD attrib = GetFileAttributes(test_indexfile.GetBuffer(0));
				if ((attrib & (FILE_ATTRIBUTE_NORMAL|FILE_ATTRIBUTE_ARCHIVE)) && attrib != 0xFFFFFFFF)
				{
					CString dirname = dirpath;
					int n = dirname.ReverseFind('\\');
					if (n >= 0)
					{
						dirname = dirname.Mid(n+1);
					}
					
					if (!pFolders->Find(0, dirname))
					{
						TMZeile *tmzeile_addfolder = new TMZeile();
						tmzeile_addfolder->Spalte(0) = dirname;
						tmzeile_addfolder->Spalte(1) = dirpath;

						extern CTelArApp theApp;
						char filename[1000];
						if (!theApp.GetFoldersFileName(filename, sizeof(filename))) return;

						pFolders->Append(filename, tmzeile_addfolder);

						delete tmzeile_addfolder;
					}
				}
				if (!bFound) break;
			}
			
		}
		ff.Close();
	}

	TMZeile *p = pFolders->tabelle;
	int i = 1;
	while (p)
	{
		if (!p->Spalte(0).IsEmpty())
			m_OrdnerLB.InsertItem(i, p->Spalte(0));
		p = p->next;
		i++;
	}

	// search for string in folders list entry ...
	LVFINDINFO lvfi;
	lvfi.flags = LVFI_STRING;
	lvfi.psz = (LPCTSTR)csOrdner;
	int n = m_OrdnerLB.FindItem(&lvfi);
	// .. and select it as current folder
	m_OrdnerLB.SetItemState(n, LVIS_SELECTED, LVIS_SELECTED | LVIS_FOCUSED);	// select first item in folders list
	m_OrdnerLB.EnsureVisible(n, FALSE);
}


void CTelArPropertyPage2::OnAddOrdner() 
{
	DF("CTelArPropertyPage2::OnAddOrdner()");

	GetDlgItem(IDC_LISTE)->SetFocus();	

	int idd;
	if (!strcmp(C_language, "D")) 
		idd = IDD_ADD_FOLDER;
	else if (!strcmp(C_language, "GB")) 
		idd = IDD_GB_ADD_FOLDER;
	else if (!strcmp(C_language, "CZ")) 
		idd = IDD_CZ_ADD_FOLDER;
	else if (!strcmp(C_language, "NL")) 
		idd = IDD_NL_ADD_FOLDER;
	else if (!strcmp(C_language, "PL")) 
		idd = IDD_PL_ADD_FOLDER;
	else 
		idd = IDD_E_ADD_FOLDER;

	CAddFolder dlg(idd);
	if (dlg.DoModal() == IDOK)
	{
		if (pFolders->Find(0, dlg.m_name))
		{
			LANG_MESSAGEBOX2(IDS_STRING71, MB_ICONEXCLAMATION); // "Folder rejected. Choose a folder name that is not already used."
			return;
		}
		TMZeile *tmzeile_addfolder = new TMZeile();
		tmzeile_addfolder->Spalte(0) = dlg.m_name;
		tmzeile_addfolder->Spalte(1) = dlg.m_pfad;

		extern CTelArApp theApp;
		char filename[1000];
		if (!theApp.GetFoldersFileName(filename, sizeof(filename))) 
		{
			AfxMessageBox("GetFoldersFileName() returned error code 0");
			return;
		}
		DF2("Adding folder '%s' to folder index '%s'", tmzeile_addfolder->Spalte(0).GetBuffer(0), filename);

		pFolders->Append(filename, tmzeile_addfolder);

		delete tmzeile_addfolder;
	
		csOrdner = dlg.m_name;
		RefreshOrdner();
		RefreshListe();
	}
}

void CTelArPropertyPage2::OnDelOrdner() 
{
	GetDlgItem(IDC_LISTE)->SetFocus();	

	POSITION p = m_OrdnerLB.GetFirstSelectedItemPosition();

	// get first selected folders list entriy...
	int n;
	if (p)
		n = m_OrdnerLB.GetNextSelectedItem(p);
	else
	{
		LANG_MESSAGEBOX2(IDS_STRING66, MB_ICONEXCLAMATION);		// Please select a folder first.
		return;
	}

	if (n == 0)
	{
		LANG_MESSAGEBOX2(IDS_STRING67, MB_ICONEXCLAMATION); 
		return;
	}

	char buffer[1000];
	char buffer2[1000];
	CString s;
	LVITEM lvi;
	memset(&lvi, 0x00, sizeof(lvi));
	lvi.iItem = n;		// get nth element of folers list
	lvi.iSubItem = 0;
	lvi.mask = LVIF_TEXT;	// only get text
	lvi.pszText = s.GetBuffer(1000);
	lvi.cchTextMax = 1000;		// max 1000 characters
	m_OrdnerLB.GetItem(&lvi);
	LANG2BUFFER(IDS_STRING65, buffer);
	sprintf(buffer2, buffer, lvi.pszText);
	s.ReleaseBuffer();
	if (AfxMessageBox(buffer2, MB_YESNO) == IDYES)
	{
		extern CTelArApp theApp;
		char filename[1000];
		if (!theApp.GetFoldersFileName(filename, sizeof(filename))) return;

		int version = FOLDERS_FILEVERSION;
		if (!pFolders->Read(filename, &version, FALSE)) return;

		CString *pcs = &s;
		pFolders->DeleteZeilen(filename, &version, 0, &pcs, 1);
		
		csOrdner = C_standard_ordner;
		RefreshOrdner();
		RefreshListe();
	}
}


void CTelArPropertyPage2::OnEditOrdner() 
{
	GetDlgItem(IDC_LISTE)->SetFocus();	

	POSITION p = m_OrdnerLB.GetFirstSelectedItemPosition();

	// for all selected recodings list entries...
	int n;
	if (p)
		n = m_OrdnerLB.GetNextSelectedItem(p);
	else
	{
		LANG_MESSAGEBOX2(IDS_STRING66, MB_ICONEXCLAMATION);		// Please select a folder first.
		return;
	}

	if (n == 0)
	{
		LANG_MESSAGEBOX2(IDS_STRING69, MB_ICONEXCLAMATION);		// The properties of the default folder cannot be changed.
		return;
	}

	CString s;
	s = m_OrdnerLB.GetItemText(n, 0);
	TMZeile *tmzeile_editfolder = pFolders->Find(0, s);
	if (!tmzeile_editfolder) return;

	int idd;
	if (!strcmp(C_language, "D")) 
		idd = IDD_ADD_FOLDER;
	else if (!strcmp(C_language, "GB")) 
		idd = IDD_GB_ADD_FOLDER;
	else if (!strcmp(C_language, "CZ")) 
		idd = IDD_CZ_ADD_FOLDER;
	else if (!strcmp(C_language, "NL")) 
		idd = IDD_NL_ADD_FOLDER;
	else if (!strcmp(C_language, "PL")) 
		idd = IDD_PL_ADD_FOLDER;
	else 
		idd = IDD_E_ADD_FOLDER;

	CAddFolder dlg(idd);
	dlg.m_bModifyFolderTitle = TRUE;
	dlg.m_name = tmzeile_editfolder->Spalte(0);
	CString name_merken = dlg.m_name;
	dlg.m_pfad = tmzeile_editfolder->Spalte(1);
	if (dlg.DoModal() == IDOK)
	{
		TMZeile *tmzeile_editfolder = new TMZeile();
		tmzeile_editfolder->Spalte(0) = dlg.m_name;
		tmzeile_editfolder->Spalte(1) = dlg.m_pfad;

		extern CTelArApp theApp;
		char filename[1000];
		if (!theApp.GetFoldersFileName(filename, sizeof(filename))) return;

		int version = FOLDERS_FILEVERSION;
		if (!pFolders->UpdateZeile(filename, &version, 0, name_merken, *tmzeile_editfolder))
		{
			LANG_MESSAGEBOX2(IDS_STRING70, MB_ICONEXCLAMATION); 
			csOrdner = C_standard_ordner;
		}
		else
			csOrdner = dlg.m_name;

		delete tmzeile_editfolder;

		RefreshOrdner();
		RefreshListe();
	}
}

void CTelArPropertyPage2::OnWizard()
{
	CArchiveWizzard propSheet;

	propSheet.DoModal();
}

void CTelArPropertyPage2::OnArchive() 
{
	DF("CTelArPropertyPage2::OnArchive()");

	GetDlgItem(IDC_LISTE)->SetFocus();	

	
	if (!archivewizzard)
	{
		archivewizzard = new CArchiveWizzard(this);
		archivewizzard->DoModal(); // Create(this);
			delete archivewizzard; archivewizzard = NULL;
/*		archivewizzard->ShowWindow(SW_SHOW);
	}
	else if (archivewizzard->IsWindowVisible())
	{
		CWindowAnima wa(archivewizzard);
		wa.Wipe(WA_LEFT,16,1);
		archivewizzard->ShowWindow(SW_HIDE);		
	}
	else
	{
		archivewizzard->ShowWindow(SW_SHOW);
*/	}		
}

//--- Listen-Steuerelemente ---

void CTelArPropertyPage2::OnSelchangeListe() 
{
	DF("CTelArPropertyPage2::OnSelchangeListe()");

	//TMZeile *zeile = theTabelle.Find(SPID_DATEINAME, CString &suchstring)

	int n = ((CQuickList *)GetDlgItem(IDC_LISTE))->GetItemCount();
	if (n == LB_ERR || !n)
	{
		SetDlgItemText(IDC_NOTIZEN_OUTPUT, (CString)"");
		return;
	}

	CString cs;

	POSITION p = m_ListeLB.GetFirstSelectedItemPosition();
	if (p)
	{
		int nSelected = m_ListeLB.GetNextSelectedItem(p);
		nLastSelection = nSelected;
		TMZeile *zeile = SafeGetItemData(nSelected);

		if (zeile)
			cs = zeile->Spalte(SPID_NOTIZEN);			
	}

	// allways maintain itemdata for selected list entries in case they are being deleted or moved
	while (p)
	{
		int nSelected = m_ListeLB.GetNextSelectedItem(p);
		TMZeile *zeile = SafeGetItemData(nSelected);
	}

	SetDlgItemText(IDC_NOTIZEN_OUTPUT, cs);
}

void CTelArPropertyPage2::RefreshListe()
{
	DF("CTelArPropertyPage2::RefreshListe()");

	char pathfile[1000];

	HCURSOR oldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));

	TMZeile *p = pFolders->Find(0, csOrdner);
	if (!p)
		strcpy(pathfile, X_path);
	else
		strcpy(pathfile, (LPCSTR)p->Spalte(1));

	int file_version = INDEX_FILEVERSION;
	
	if (*pathfile && pathfile[strlen(pathfile)-1] != '\\')
		strcat(pathfile, "\\");
	strcat(pathfile, INDEX_FILENAME);

	//((CQuickList *)GetDlgItem(IDC_LISTE))->DeleteAllItems();	not needed in virtual listbox
	m_ListeLB.EnableToolTips(TRUE);

	if (IsOldStyleIndexFile(pathfile))
	{
		char empmessbuf[1000];
		LANG2BUFFER(IDS_STRING186, empmessbuf);
		CString csEmpMessBuf = empmessbuf;
		m_ListeLB.SetEmptyMessage(csEmpMessBuf);

		if (theTabelle.Read(pathfile, &file_version, FALSE))
		{
			DF("Old-style index file opened");

//			int TabStopArray[] = { 15, 170, 180, 190, 200 };
//			((CListBox *)GetDlgItem(IDC_LISTE))->SetTabStops(sizeof(TabStopArray)/sizeof(TabStopArray[0]), TabStopArray);

			// reserve some space before we know the number of items
			m_ListeLB.LockWindowUpdate();
			m_ListeLB.SetItemCount(100000);
			ResetItemData(100000);
			m_CurrentIndexType = IDXTYPE_FILE;

			int nItemCount = 0;

			TMZeile *p = theTabelle.tabelle;
			char str[100000];

			// Suchfilter
			CString sid;
			CString sge;	
			CString sno;	
			CString sdv;	
			CString sdb;	
			CString szv;	
			CString szb;	
			CString smindau;		
			CString smaxdau;
			
			if (suchfilter && suchfilter->IsWindowVisible())
			{
				sid = suchfilter->m_Identifikation;
				sge = suchfilter->m_Gespraechspartner;
				sno = suchfilter->m_Notizen;
				sdv = suchfilter->m_DatumVon;
				sdb = suchfilter->m_DatumBis;
				szv = suchfilter->m_ZeitVon;
				szb = suchfilter->m_ZeitBis;
				smindau = suchfilter->m_MinDauer;
				smaxdau = suchfilter->m_MaxDauer;
			}
			CTime ctDatumVon, ctDatumBis, ctDatum;
			
			while (p)
			{
				BOOL bDisplay = TRUE;

				CString tid = p->Spalte(SPID_INITIALEN);
				CString tge = p->Spalte(SPID_GESPRAECHSPARTNER);
				CString tno = p->Spalte(SPID_NOTIZEN);
				CString td = p->Spalte(SPID_DATUM);
				CString tz = p->Spalte(SPID_ZEIT);
				BOOL bValidDate = String2CTime(td, tz, ctDatum);

				if (suchfilter && suchfilter->IsWindowVisible())
				{
					bDisplay = FALSE;

					if (!szv.GetLength()) szv = "00:00";
					if (!szb.GetLength()) szb = "23:59";

					BOOL bCheckVon = FALSE, bCheckBis = FALSE;
					if (bValidDate)
					{
						bCheckVon = String2CTime(sdv, szv, ctDatumVon);
						bCheckBis = String2CTime(sdb, szb, ctDatumBis);
					}

					CString tdauer = p->Spalte(SPID_DAUER);

					// Dauer
					int nMindau, nMaxdau;
					BOOL bCheckMindau, bCheckMaxdau;
					if (!isdigit(*smindau) || !isdigit(smindau[1]) || smindau[2]!=':' || !isdigit(smindau[3]) || !isdigit(smindau[4])) 
						bCheckMindau = FALSE;
					else
					{
						nMindau = atoi(smindau)*60+atoi(smindau.GetBuffer(0)+3);
						bCheckMindau = TRUE;
					}
					if (!isdigit(*smaxdau) || !isdigit(smaxdau[1]) || smaxdau[2]!=':' || !isdigit(smaxdau[3]) || !isdigit(smaxdau[4])) 
						bCheckMaxdau = FALSE;
					else
					{
						nMaxdau = atoi(smaxdau)*60+atoi(smaxdau.GetBuffer(0)+3);
						bCheckMaxdau = TRUE;
					}
					int nTDauer = atoi(tdauer)*60+atoi(tdauer.GetBuffer(0)+3);

					// Suchstrings
					sid.MakeUpper(); sge.MakeUpper(); sno.MakeUpper(); tid.MakeUpper(); tge.MakeUpper(); tno.MakeUpper(); 
					
					if ((sid == "" || sid == tid)
						&& (sge == "" || tge.Find(sge) != -1)
						&& (sno == "" || tno.Find(sno) != -1)
						&& (!bCheckVon || ctDatum >= ctDatumVon)
						&& (!bCheckBis || ctDatum <= ctDatumBis)
						&& (!bCheckMindau || nMindau <= nTDauer)
						&& (!bCheckMaxdau || nMaxdau > nTDauer))
							bDisplay = TRUE;
				}

				if (bDisplay)
				{
					sprintf(str, "%-2.2s\t%-10.10s  %-8.8s  %-8.8s  %s  \t%s",
						p->Spalte(SPID_INITIALEN).GetBuffer(0),
						p->Spalte(SPID_DATUM).GetBuffer(0),
						p->Spalte(SPID_ZEIT).GetBuffer(0),
						p->Spalte(SPID_DAUER).GetBuffer(0),
						p->Spalte(SPID_GESPRAECHSPARTNER).GetBuffer(0),
						p->Spalte(SPID_NOTIZEN).GetBuffer(0));

					/*
					if (!bValidDate)	// einfach anhängen
					{
						((CQuickList *)GetDlgItem(IDC_LISTE))->AddString(str);
						((CQuickList *)GetDlgItem(IDC_LISTE))->SetItemData(
							((CQuickList *)GetDlgItem(IDC_LISTE))->GetItemCount()-1,
							(DWORD)p
						);
					}
					else	// einsortieren
					*/
					{
						//int n = EinsortierenNachDatum(&ctDatum, 0, ((CQuickList *)GetDlgItem(IDC_LISTE))->GetItemCount());
						//((CQuickList *)GetDlgItem(IDC_LISTE))->InsertString(n, str);
						SetItemData(nItemCount, p);
					}
				}
				p = p->next;
				nItemCount++;
			}

			m_ListeLB.SetItemCount(nItemCount);
			m_ListeLB.UnlockWindowUpdate();
		}
	}
	else if (!_strnicmp(pathfile, "sense://", 8)) 
	{
		m_ListeLB.SetEmptyMessage("Sense call playback not yet supported here. Use the Sense 'Calls' application to playback the calls.");

		m_ListeLB.LockWindowUpdate();
		m_ListeLB.SetItemCount(0);		// max number of items displayed
		ResetItemData(0);
		m_CurrentIndexType = IDXTYPE_SENSE;
		m_ListeLB.UnlockWindowUpdate();
	}
	else	// open new-style database based index file
	{
		int n;

		char empmessbuf[1000];
		LANG2BUFFER(IDS_STRING186, empmessbuf);
		CString csEmpMessBuf = empmessbuf;
		m_ListeLB.SetEmptyMessage(csEmpMessBuf);

		liste_index.Close();
		if (liste_index.OpenCreate(pathfile, ""))
		{
			// move to last recording
			// GetRecordCount IS NOT VERY ACCURATE: n = liste_index.recordingsRS->GetRecordCount();
			CString csRecordingsCount;
			//liste_index.GetConfig("RecordingsCount", csRecordingsCount);
			//n = atoi((LPCSTR)csRecordingsCount);
			n = liste_index.DetermineRecordingsCount();

			m_ListeLB.LockWindowUpdate();
			m_ListeLB.SetItemCount(n);		// max number of items displayed
			ResetItemData(n);
			m_CurrentIndexType = IDXTYPE_ACCESS;

			int nItemCount = 0;

			m_CurrentIndexPosition = n - 1;

			// if search filter
			if (suchfilter && suchfilter->IsWindowVisible())
			{
				TMZeile *p;				

				CString sid;
				CString sge;	
				CString sno;	
				CString sdv;	
				CString sdb;	
				CString szv;	
				CString szb;	
				CString smindau;		
				CString smaxdau;

				sid = suchfilter->m_Identifikation;
				sge = suchfilter->m_Gespraechspartner;
				sno = suchfilter->m_Notizen;
				sdv = suchfilter->m_DatumVon;
				sdb = suchfilter->m_DatumBis;
				szv = suchfilter->m_ZeitVon;
				szb = suchfilter->m_ZeitBis;
				smindau = suchfilter->m_MinDauer;
				smaxdau = suchfilter->m_MaxDauer;
				CTime ctDatumVon, ctDatumBis, ctDatum;

				sdv.TrimLeft();
				sdv.TrimRight();
				sdb.TrimLeft();
				sdb.TrimRight();
				szv.TrimLeft();
				szv.TrimRight();
				szb.TrimLeft();
				szb.TrimRight();

				if (!isdigit(sdv[0]) || !isdigit(sdv[1]) || !isdigit(sdv[2]) || !isdigit(sdv[3]) 
					|| !isdigit(sdv[5]) || !isdigit(sdv[6]) || !isdigit(sdv[8]) || !isdigit(sdv[9]) 
					|| sdv[4] != '/' || sdv[7] != '/') 
						sdv = "";
				if (sdv.GetLength() != 10 || atoi(sdv.Mid(5, 2)) > 12 || atoi(sdv.Right(2)) > 31 || atoi(sdv.Mid(5, 2)) == 0 || atoi(sdv.Right(2)) == 0) sdv = "";

				if (!isdigit(sdb[0]) || !isdigit(sdb[1]) || !isdigit(sdb[2]) || !isdigit(sdb[3]) 
					|| !isdigit(sdb[5]) || !isdigit(sdb[6]) || !isdigit(sdb[8]) || !isdigit(sdb[9]) 
					|| sdb[4] != '/' || sdb[7] != '/') 
						sdb = "";
				if (sdb.GetLength() != 10 || atoi(sdb.Mid(5, 2)) > 12 || atoi(sdb.Right(2)) > 31 || atoi(sdb.Mid(5, 2)) == 0 || atoi(sdb.Right(2)) == 0) sdb = "";

				if (!isdigit(szv[0]) || !isdigit(szv[1]) || !isdigit(szv[3]) || !isdigit(szv[4]) 
					|| szv[2] != ':') 
						szv = "";
				if (szv.GetLength() != 5 || atoi(szv.Left(2)) > 23 || atoi(szv.Right(2)) > 59) szv = "";

				if (!isdigit(szb[0]) || !isdigit(szb[1]) || !isdigit(szb[3]) || !isdigit(szb[4]) 
					|| szb[2] != ':') 
						szb = "";
				if (szb.GetLength() != 5 || atoi(szb.Left(2)) > 23 || atoi(szb.Right(2)) > 59) szb = "";

				//GetDlgItem(IDC_LISTE)->SetRedraw(FALSE);

				liste_index.SeekRecordingByPosition(0, n);	// move to first record
				while (TRUE)
				{
					p = new TMZeile;					
					if (!liste_index.GetNextRecording(p))
					{
						delete p;
						break;
					}						

					BOOL bDisplay = TRUE;

					CString tid = p->Spalte(SPID_INITIALEN);
					CString tge = p->Spalte(SPID_GESPRAECHSPARTNER);
					CString tno = p->Spalte(SPID_NOTIZEN);
					CString td = p->Spalte(SPID_DATUM);
					CString tz = p->Spalte(SPID_ZEIT);
					BOOL bValidDate = String2CTime(td, tz, ctDatum);

					if (suchfilter && suchfilter->IsWindowVisible())
					{
						bDisplay = FALSE;

						if (!szv.GetLength()) szv = "00:00:00";
						if (!szb.GetLength()) szb = "23:59:59";

						BOOL bCheckVon = FALSE, bCheckBis = FALSE;
						if (bValidDate)
						{
							bCheckVon = String2CTime(sdv, szv, ctDatumVon);
							bCheckBis = String2CTime(sdb, szb, ctDatumBis);
						}

						CString tdauer = p->Spalte(SPID_DAUER);

						// Dauer
						int nMindau, nMaxdau;
						BOOL bCheckMindau, bCheckMaxdau;
						if (!isdigit(*smindau) || !isdigit(smindau[1]) || smindau[2]!=':' || !isdigit(smindau[3]) || !isdigit(smindau[4])) 
							bCheckMindau = FALSE;
						else
						{
							nMindau = atoi(smindau)*60+atoi(smindau.GetBuffer(0)+3);
							bCheckMindau = TRUE;
						}
						if (!isdigit(*smaxdau) || !isdigit(smaxdau[1]) || smaxdau[2]!=':' || !isdigit(smaxdau[3]) || !isdigit(smaxdau[4])) 
							bCheckMaxdau = FALSE;
						else
						{
							nMaxdau = atoi(smaxdau)*60+atoi(smaxdau.GetBuffer(0)+3);
							bCheckMaxdau = TRUE;
						}
						int nTDauer = atoi(tdauer)*60+atoi(tdauer.GetBuffer(0)+3);

						// Suchstrings
						sid.MakeUpper(); sge.MakeUpper(); sno.MakeUpper(); tid.MakeUpper(); tge.MakeUpper(); tno.MakeUpper(); 
						
						if ((sid == "" || sid == tid)
							&& (sge == "" || tge.Find(sge) != -1)
							&& (sno == "" || tno.Find(sno) != -1)
							&& (!bCheckVon || ctDatum >= ctDatumVon)
							&& (!bCheckBis || ctDatum <= ctDatumBis)
							&& (!bCheckMindau || nMindau <= nTDauer)
							&& (!bCheckMaxdau || nMaxdau > nTDauer))
								bDisplay = TRUE;
					}

					if (bDisplay)
					{
						// einfach anhängen
						SetItemData(nItemCount, p);
						nItemCount++;
					}
					else
						delete p;
				}
				liste_index.EndSeekRecording();

				m_ListeLB.SetItemCount(nItemCount);
				m_ListeLB.UnlockWindowUpdate();
				m_ListeLB.RedrawItems(
						m_ListeLB.GetTopIndex(),
						m_ListeLB.GetTopIndex()+m_ListeLB.GetCountPerPage());
			}
			else // if no search filter
			{
				m_ListeLB.UnlockWindowUpdate();
				m_ListeLB.RedrawItems(
						m_ListeLB.GetTopIndex(),
						m_ListeLB.GetTopIndex()+m_ListeLB.GetCountPerPage());

/* outdated listbox code:
				// create dummy list
				GetDlgItem(IDC_LISTE)->SetRedraw(FALSE);
				for (int i = 0; i < n; i++)
				{
					((CListBox *)GetDlgItem(IDC_LISTE))->AddString("");
					((CListBox *)GetDlgItem(IDC_LISTE))->SetItemData(i, 0L);
				}

				for (i = 0; i < n; i++)
				{
					DWORD dw;
					dw = ((CListBox *)GetDlgItem(IDC_LISTE))->GetItemData(i);
				}			// was soll das bloß?
*/
			}
			//GetDlgItem(IDC_LISTE)->SetRedraw(TRUE);

			DF("List refresh with database index file");
		}
	}

	int n = ((CQuickList *)GetDlgItem(IDC_LISTE))->GetItemCount();
	if (nLastSelection != -1 && nLastSelection < n)
	{
		if (nLastSelection >= n - 5)
			((CQuickList *)GetDlgItem(IDC_LISTE))->EnsureVisible(n-1, FALSE);
		else
			((CQuickList *)GetDlgItem(IDC_LISTE))->EnsureVisible(nLastSelection, FALSE);

		((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetItemState(nLastSelection, LVIS_SELECTED, LVIS_SELECTED | LVIS_FOCUSED);
		((CQuickList *)(((CTelArPropertySheet *)GetParent())->m_Page2.GetDlgItem(IDC_LISTE)))->SetRedraw(TRUE);
	}
	else	// at least one item, which is not selected
		if (n >= 1) ((CQuickList *)GetDlgItem(IDC_LISTE))->EnsureVisible(n-1, FALSE);

	SetCursor(oldCursor);

	DF1("   RefreshListe() finished -- %d items", ((CQuickList *)GetDlgItem(IDC_LISTE))->GetItemCount());

}

// Overrideables for the owner-draw listbox --- OUTDATED: see OnGetListItem()
void CTelArPropertyPage2::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	if (nIDCtl == IDC_LISTE && lpDrawItemStruct->itemID >= 0)
	{
/*		ASSERT(lpDrawItemStruct->CtlType == ODT_LISTBOX);

		if (!((CListBox *)GetDlgItem(IDC_LISTE))->GetCount()) return;

		CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
		TMZeile *p = SafeGetItemData(lpDrawItemStruct->itemID);
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
		{
			CBrush b;
			b.CreateSolidBrush(GetSysColor(COLOR_HIGHLIGHT));
			pDC->FillRect(&lpDrawItemStruct->rcItem, &b);
			pDC->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));
		}
		else
		{
			CBrush b;
			b.CreateSolidBrush(GetSysColor(COLOR_WINDOW));
			pDC->FillRect(&lpDrawItemStruct->rcItem, &b);
			pDC->SetTextColor(GetSysColor(COLOR_WINDOWTEXT));
			pDC->SetBkColor(GetSysColor(COLOR_WINDOW));
		}

		if (!p)
		{
			pDC->TextOut(lpDrawItemStruct->rcItem.left+1, lpDrawItemStruct->rcItem.top, "- locked -", strlen("- locked -"));
			return;
		}

		CString *pcs = &p->Spalte(SPID_INITIALEN);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+1, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_DATUM);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+24, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_ZEIT);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+87, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_DAUER);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+135, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_GESPRAECHSPARTNER);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+183, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
		pcs = &p->Spalte(SPID_NOTIZEN);
		pDC->TextOut(lpDrawItemStruct->rcItem.left+260, lpDrawItemStruct->rcItem.top, pcs->GetBuffer(0), pcs->GetLength());
*/;	
	}	
	// CPropertyPage::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

LRESULT CTelArPropertyPage2::OnGetListItem(WPARAM wParam, LPARAM lParam)
{
    //wParam is a handler to the list
    //Make sure message comes from list box
    ASSERT( (HWND)wParam == m_ListeLB.GetSafeHwnd() );

    //lParam is a pointer to the data that 
    //is needed for the element
    CQuickList::CListItemData* data = 
        (CQuickList::CListItemData*) lParam;

    //Get which item and subitem that is asked for.
    int item = data->GetItem();
    int subItem = data->GetSubItem();

	
	TMZeile *p = SafeGetItemData(item);

	if (!p)
	{
		if (subItem == 1) 
			data->m_text = "- locked -";
		else
			data->m_text = "";
		data->m_tooltip = "Recording has been moved, deleted, or is locked by another user";
	}
	else
	{
		switch (subItem)
		{
			char buffer[1000];
		case 0: 
			data->m_text = p->Spalte(SPID_INITIALEN);
			LANG2BUFFER(IDS_STRING187, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			break;
		case 1:
			data->m_text = p->Spalte(SPID_DATUM) + " " + p->Spalte(SPID_ZEIT);
			LANG2BUFFER(IDS_STRING188, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			break;
		case 2:
			data->m_text = p->Spalte(SPID_DAUER);
			LANG2BUFFER(IDS_STRING189, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			break;
		case 3:
			data->m_text = p->Spalte(SPID_GESPRAECHSPARTNER);
			LANG2BUFFER(IDS_STRING125, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			data->m_allowEdit = TRUE;
			break;
		case 4:
			data->m_text = p->Spalte(SPID_NOTIZEN);
			LANG2BUFFER(IDS_STRING126, buffer);
			data->m_tooltip = (CString)buffer + ": " + data->m_text;
			data->m_allowEdit = TRUE;
			break;
		}
	}

    return 0;
}


#define CACHE_FORWARD (m_ListeLB.GetCountPerPage())

TMZeile *CTelArPropertyPage2::SafeGetItemData(int n)
{
	TMZeile *p = GetItemData(n);
	if (!p)
	{
		try	// ignore missing records
		{

			if (m_CurrentIndexType == IDXTYPE_FILE) 
				return NULL;

			// Seek in database
			liste_index.SeekRecordingByPosition(n, CACHE_FORWARD);
			m_CurrentIndexPosition = n;
			
			while (n < m_CurrentIndexPosition + CACHE_FORWARD && !p)
			{
				p = new TMZeile;
				if (!liste_index.GetNextRecording(p)) 
					break;
				SetItemData(n, p);

				n++;
				p = GetItemData(n);
			}

			liste_index.EndSeekRecording();

			p = GetItemData(m_CurrentIndexPosition);
		}
		catch( CADOException* e )
		{
			e;
			return NULL;			
		}
	}
	return p;
}


//--- administration of own itemdata for owner-draw list control

void CTelArPropertyPage2::ResetItemData(int size)
{
	if (myItemData) 
	{
		if (m_CurrentIndexType != IDXTYPE_FILE)
			for (int i = 0; i < myItemDataSize; i++)
				if (myItemData[i])
				{
					delete myItemData[i];
					myItemData[i] = NULL;
				}

		delete myItemData; 
		myItemData = NULL; 
	}

	if (size)
	{
		myItemData = (TMZeile **)new PVOID[size];
		//memset(myItemData, 0x00, size * sizeof(myItemData[0]));
		int i;
		for (i = 0; i < size; i++)
			myItemData[i] = 0;

		myItemDataSize = size;
	}
}

void CTelArPropertyPage2::SetItemData(int item, TMZeile *p)
{
	if (myItemData && item >= 0 && item < myItemDataSize)
		myItemData[item] = p;
}

TMZeile *CTelArPropertyPage2::GetItemData(int item)
{
	if (myItemData && item >= 0 && item < myItemDataSize)
		return myItemData[item];
	else
		return NULL;

}

void CTelArPropertyPage2::DeleteItemData(int item)
{
	if (myItemData && item >= 0 && item < myItemDataSize)
	{
		if (myItemData[item])
		{
			delete myItemData[item];
			myItemData[item] = NULL;
		}

		for (int i = item; i < myItemDataSize-1; i++)
			myItemData[i] = myItemData[i+1];

		myItemDataSize--;
	}
}



void CTelArPropertyPage2::OnDeleteitemListe(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	CString cs;
	cs.Format("%d", (int)pNMHDR->idFrom);
	AfxMessageBox(cs);
	/*
		if (m_CurrentIndexType != IDXTYPE_FILE)
			if (lpDeleteItemStruct->itemData) 
			{
				delete (TMZeile *)lpDeleteItemStruct->itemData;
				lpDeleteItemStruct->itemData = 0L;
			}
	*/

	*pResult = 0;
}


void CTelArPropertyPage2::OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct) 
{
	if (nIDCtl == IDC_LISTE && lpDeleteItemStruct->itemID >= 0)
	{
		ASSERT(lpDeleteItemStruct->CtlType == ODT_LISTBOX);

		if (m_CurrentIndexType != IDXTYPE_FILE)
			DeleteItemData(lpDeleteItemStruct->itemID);
	}

	CResizablePage::OnDeleteItem(nIDCtl, lpDeleteItemStruct);
}

void CTelArPropertyPage2::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	lpMeasureItemStruct->itemHeight = 13;
	
	CResizablePage::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

int CTelArPropertyPage2::OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct) 
{
	
	
	return CResizablePage::OnCompareItem(nIDCtl, lpCompareItemStruct);
}


// rekursiv-binäres suchen
int CTelArPropertyPage2::EinsortierenNachDatum(CTime *date, int begin, int end)
{
	int nCheckPos = (end - begin) / 2 + begin;
	CTime ctCheckPos;

	if (end == begin) return begin;

	TMZeile *zeile = SafeGetItemData(nCheckPos);
	if (!String2CTime(zeile->Spalte(SPID_DATUM), zeile->Spalte(SPID_ZEIT), ctCheckPos) || *date < ctCheckPos)
	{
		if (end - begin <=1) 
			return begin;
		else
			return EinsortierenNachDatum(date, begin, nCheckPos);
	}
	else
	{
		if (end - begin <=1) 
			return end;
		else
			return EinsortierenNachDatum(date, nCheckPos, end);
	}
}

BOOL CTelArPropertyPage2::OnSetActive() 
{
	DF("CTelArPropertyPage2::OnSetActive()");

	RefreshOrdner();
	RefreshListe();
	
	return CResizablePage::OnSetActive();
}


BOOL CTelArPropertyPage2::OnKillActive() 
{
	DF("CTelArPropertyPage2::OnKillActive()");

	POSITION p = m_ListeLB.GetFirstSelectedItemPosition();
	if (p)
		nLastSelection = m_ListeLB.GetNextSelectedItem(p);
	else
		nLastSelection = -1;

	if (dest_index.IsOpen()) dest_index.Close();
	
	return CResizablePage::OnKillActive();
}


//---- hier die Player-Implementation --------


void CTelArPropertyPage2::OnNMDblclkListe(NMHDR *pNMHDR, LRESULT *pResult)
{
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);

	DF("CTelArPropertyPage2::OnDblclkListe()");

	OnPlay();

	*pResult = 0;
}
//void CTelArPropertyPage2::OnDblclkListe(NMHDR* pNMHDR, LRESULT* pResult) 
//{
//	DF("CTelArPropertyPage2::OnDblclkListe()");
//
//	OnPlay();
//
//	*pResult = 0;
//}

// returns TRUE if ok
BOOL CTelArPropertyPage2::MyMciSendString(LPCSTR cmd, char *ret, int retsize, HWND hWnd)
{
	MCIERROR mciret;
	mciret = mciSendString(cmd,ret,retsize,hWnd);
	if (mciret) 
	{ 
		char buf[3000]; 
		mciGetErrorString(mciret, buf, sizeof(buf)); 

		if (!X_MessageShownOnce)
		{
			X_MessageShownOnce = TRUE;

			// Display message
			AfxMessageBox("There was some internal problem. Maybe the MCI system became unstable. If this message should show up again after rebooting, please send the current 'logXX.txt' file from the program directory to our technical support and try to describe in detail the circumstances of the incident. (Note: this message only shows up once each time you start the SCR.)", MB_OK|MB_ICONINFORMATION);
		}
		DF("__________")
		DF2("MCI command '%s': %s", cmd, buf);
		DF("^^^^^^^^^^")
		return FALSE; 
	}
	else 
		return TRUE;
}

void CTelArPropertyPage2::OnPlay() 
{
	char buf[300];

	DF("CTelArPropertyPage2::OnPlay()");

	char buffer[1000];
	char cmd[300];
	BOOL bKillTempFile = FALSE;


	if (bPlaying)
	{
		MyMciSendString("status s1 mode",buf,sizeof(buf),m_hWnd);
		if (!strcmp(buf, "paused")) // wenn Wiedergabe pausiert...
		{
			MyMciSendString("play s1",buf,sizeof(buf),m_hWnd); // ... einfach fortsetzen!
			return;
		}
		else
		{
			MyMciSendString("seek s1 to 0",buf,sizeof(buf),m_hWnd); // sonst an den anfang & spielen
			return;
		}
	}

	GetDlgItem(IDC_LISTE)->SetFocus();	

	((CTelArPropertySheet *)GetParent())->m_Page1.GetDlgItemText(IDC_AUFNAHME, buffer, sizeof(buffer));
	if (!((CTelArPropertySheet *)GetParent())->m_Page1.GetDlgItem(IDC_AUFNAHME)->IsWindowEnabled()
		|| ((CTelArPropertySheet *)GetParent())->m_Page1.odbAufnahme.GetState() == AUFNAHME_BEENDEN)
	{
		LANG_MESSAGEBOX2(IDS_STRING21, MB_ICONEXCLAMATION); // "Wiedergabe ist momentan nicht möglich, da eine Aufnahme stattfindet!"
		return;
	}
/*
	MyMciSendString("close s1",buf,sizeof(buf),m_hWnd);
	if (!csKillTheFile.IsEmpty())
	{
		DeleteFile(csKillTheFile);
		csKillTheFile = "";
	}
*/
	int n;
	POSITION pos = m_ListeLB.GetFirstSelectedItemPosition();
	if (pos)
		n = m_ListeLB.GetNextSelectedItem(pos);
	else
		return;

	TMZeile *zeile = SafeGetItemData(n);

	if (zeile)
	{
		if (zeile->Spalte(SPID_DATEINAME) == "") return;
	}
	else
		return;

	TMZeile *p = pFolders->Find(0, csOrdner);
	if (!p)
		strcpy(buffer, X_path);
	else
		strcpy(buffer, (LPCSTR)p->Spalte(1));

	if (*buffer && buffer[strlen(buffer)-1] != '\\')
		strcat(buffer, "\\");

	// *.TRS-Datei in Wav umwandeln
	strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
	if (strlen(buffer) >= 3 && strcmp(buffer+strlen(buffer)-3, "wav"))
	{
		char temp_path[1000];
		char *cp;
		CString passwort_buffer;

		if (!GetTempPath(sizeof(temp_path), temp_path)) return;
		if (*temp_path && temp_path[strlen(temp_path)-1] != '\\')
			strcat(temp_path, "\\");
		if (!(cp = strrchr(buffer, '\\'))) return;
		strcat(temp_path, cp+1);
		if (strlen(temp_path) >= 3) strcpy(temp_path+strlen(temp_path)-3, "wav");
		
		CString pw;
		if (atoi((LPCSTR)zeile->Spalte(SPID_GESCHUETZT)))
		{   // mit PW und Dateinamen geschützt:
			{	// Passwortabfrage:
				int idd;
				
				if (!strcmp(C_language, "D")) 
					idd = IDD_PASSWORT_CHECK;
				else if (!strcmp(C_language, "GB")) 
					idd = IDD_GB_PASSWORT_CHECK;
				else if (!strcmp(C_language, "CZ")) 
					idd = IDD_CZ_PASSWORT_CHECK;
				else if (!strcmp(C_language, "NL")) 
					idd = IDD_NL_PASSWORT_CHECK;
				else if (!strcmp(C_language, "PL")) 
					idd = IDD_PL_PASSWORT_CHECK;
				else 
					idd = IDD_E_PASSWORT_CHECK;

				CPasswortCheckDlg dlg(idd, &passwort_buffer, this);
				if (dlg.DoModal() != IDOK) return;
			}
			passwort_buffer.TrimLeft();
			passwort_buffer.TrimRight();
			pw = passwort_buffer; 
		}
		else
			pw = "";		
		pw += zeile->Spalte(SPID_DATEINAME); // nur mit Dateinamen geschützt

		if (DecryptFile((CString)buffer, (CString)temp_path, pw))
		{
			strcpy(buffer, temp_path);
			bKillTempFile = TRUE;
		}
		else
		{
			char fmt[2000], buffer2[2000];
			LANG2BUFFER(IDS_STRING38, fmt);
			sprintf(buffer2, fmt, buffer);
			AfxMessageBox(buffer2, MB_ICONSTOP);	
			return;
		}
	}
	else	// if wav, check RIFF header
	{
		char  headerbuffer[16];
		DWORD *pdw = (DWORD *)headerbuffer;
		CFile *cf = NULL;
		
		if (!(cf = new CFile(buffer, CFile::modeRead)))
		{ 	
			AfxMessageBox("Couldn't open wav file");
			goto ErrorLvl1; 
		}
		if (cf->Read(headerbuffer, sizeof(headerbuffer)) < 16)
		{	AfxMessageBox("Malformed wav file header"); goto ErrorLvl1; }

		if (*pdw++ != mmioFOURCC('R', 'I', 'F', 'F'))
		{	AfxMessageBox("Malformed wav file header"); goto ErrorLvl1; }
		pdw++;	// skip file length
		if (*pdw++ != mmioFOURCC('W', 'A', 'V', 'E'))
		{	AfxMessageBox("No Windows PCM-File"); goto ErrorLvl1; }
		if (*pdw++ != mmioFOURCC('f', 'm', 't', ' '))
		{	AfxMessageBox("Malformed wav file header"); goto ErrorLvl1; }
		if (cf) cf->Close();
		goto AllOk;
ErrorLvl1:						// code from pre-try-catch era
		if (cf) cf->Close();
		return;
AllOk:	;
	}
		
	bPlaying = TRUE;
	sprintf(cmd,"open \"%s\" alias s1", buffer);
	MyMciSendString(cmd,buf,sizeof(buf),m_hWnd);
	DF(cmd);
	DF(buf);
	MyMciSendString("play s1",buf,sizeof(buf),m_hWnd);
	DF("play s1");
	DF(buf);
	if (bKillTempFile) csKillTheFile = buffer;

	//Slider
	long l;
	MyMciSendString("status s1 length",buf,sizeof(buf),m_hWnd);
	l = atol(buf) / 1000;
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->SetRange(0, l);
	((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->SetPos(0);
	//((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->SetTicFreq(60);
}

void CTelArPropertyPage2::OnPause() 
{
	DF("CTelArPropertyPage2::OnPause() ");

	GetDlgItem(IDC_LISTE)->SetFocus();	

	if (!bPlaying) return;

	char buf[50];

	MyMciSendString("status s1 mode",buf,sizeof(buf),m_hWnd);
	if (!strcmp(buf, "playing")) // wenn Wiedergabe nicht schon pausiert...
		MyMciSendString("pause s1",buf,sizeof(buf),m_hWnd);
	else
		MyMciSendString("play s1",buf,sizeof(buf),m_hWnd);

	DF("pause s1");
	DF(buf);
}

void CTelArPropertyPage2::OnRew() 
{
	DF("CTelArPropertyPage2::OnRew()");

	char buf[30];
	char cmd[80];
	long l;
	GetDlgItem(IDC_LISTE)->SetFocus();	
	if (!bPlaying) return;
	MyMciSendString("status s1 position",buf,sizeof(buf),m_hWnd);
	l = atol(buf) - 10000;
	if (l < 0) l = 0;
	sprintf(cmd,"seek s1 to %ld",l);
	mciSendString(cmd,buf,sizeof(buf),m_hWnd);
	bSeeking = TRUE;
	KillTimer(2);
	SetTimer(2, 100, NULL);
}

void CTelArPropertyPage2::OnFf() 
{
	DF("CTelArPropertyPage2::OnFf()");

	char buf[30];
	char cmd[80];
	long l;
	GetDlgItem(IDC_LISTE)->SetFocus();	
	if (!bPlaying) return;
	MyMciSendString("status s1 position",buf,sizeof(buf),m_hWnd);
	l = atol(buf) + 10000;
	sprintf(cmd,"seek s1 to %ld",l);
	mciSendString(cmd,buf,sizeof(buf),m_hWnd);
	bSeeking = TRUE;
	KillTimer(2);
	SetTimer(2, 100, NULL);
}

void CTelArPropertyPage2::OnStop() 
{
	DF("CTelArPropertyPage2::OnStop()");

	GetDlgItem(IDC_LISTE)->SetFocus();	

	if (!bPlaying) return;
	bPlaying = FALSE;

	char buf[30];
	MyMciSendString("stop s1",buf,sizeof(buf),m_hWnd);
	MyMciSendString("seek s1 to start",buf,sizeof(buf),m_hWnd);
	MyMciSendString("close s1",buf,sizeof(buf),m_hWnd);
	if (csKillTheFile != "") 
	{
		DeleteFile(csKillTheFile);
		csKillTheFile = "";
		DF("   KillTheFile");
	}
}

void CTelArPropertyPage2::OnDestroy() 
{
	DF("CTelArPropertyPage2::OnDestroy()");

	RemoveAllAnchors();

	CResizablePage::OnDestroy();
	
	liste_index.Close();
	if (dest_index.IsOpen()) dest_index.Close();

	if (bPlaying) OnStop();

	ResetItemData(0);	// clear ListCtrl cache

	//SetDlgItemText(IDC_FILE, "File: ");
	KillTimer(1);

	if (suchfilter)
	{
		suchfilter->DestroyWindow();
		if (suchfilter) delete suchfilter; 
		suchfilter = NULL;
	}

	if (archivewizzard)
	{
		archivewizzard->DestroyWindow();
		if (archivewizzard) delete archivewizzard; 
		archivewizzard = NULL;
	}
}

void CTelArPropertyPage2::OnTimer(UINT_PTR nIDEvent) 
{
	DFTICK("T");

	switch (nIDEvent)
	{
	case 1:
		{
			DFTICK("1");
			if (bPlaying)
			{
				char buf[30], buf2[60];
				long l,h,m,s;
				MyMciSendString("status s1 position",buf,sizeof(buf),m_hWnd);
				l = atol(buf) / 1000;
				s = l % 60;
				m = (l / 60) % 60;
				h = (l / 3600);
			
				sprintf(buf2,"%02ld:%02ld:%02ld", h, m, s);
				SetDlgItemText(IDC_POSITION, buf2);
				((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->SetPos(l);

				MyMciSendString("status s1 mode",buf,sizeof(buf),m_hWnd);
				if (!strcmp(buf, "stopped") && bPlaying && !bSeeking)
				{
					MyMciSendString("close s1",buf,sizeof(buf),m_hWnd);
					bPlaying = FALSE;
					if (csKillTheFile != "") 
					{
						DeleteFile(csKillTheFile);
						csKillTheFile = "";

						DF("OnTimer KillTheFile (nIDEvent == 1)");
					}
				}
			}
			else
			{
				SetDlgItemText(IDC_POSITION, "00:00:00");
				((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->SetPos(0);			
			}
		}	
		break;
	
	case 2:
		{
			DFTICK("2");
			char buf[30];
			MyMciSendString("play s1",buf,sizeof(buf),m_hWnd);
			bSeeking = FALSE;
			KillTimer(2);
			KillTimer(1);
			SetTimer(1, 100, NULL);
		}
		break;

	case 3:
		if (X_AutomatischLoeschen && csOrdner == C_standard_ordner)
		{
			DFTICK("3");
			if (m_ListeLB.GetItemCount())
			{
				TMZeile *p;
				CTime now = now.GetCurrentTime(), ctBirth;
				CTimeSpan ctsAge;
				CString csDate, csTime;

				p = SafeGetItemData(0);	// Get first element of recordings list

				// item older than allowed? (number of days in X_AutomatischLoeschen)
				if (p)
				{
					csDate = p->Spalte(SPID_DATUM);
					csTime = p->Spalte(SPID_ZEIT);
					if (String2CTime(csDate, csTime, ctBirth))
					{
						ctsAge = now - ctBirth;
						if (ctsAge.GetDays() > X_AutomatischLoeschen)
						{
							POSITION pos = m_ListeLB.GetFirstSelectedItemPosition();
							if (pos)
								nLastSelection = m_ListeLB.GetNextSelectedItem(pos);
							else
								nLastSelection = -1;

							int i;
							for (i = 1; i < m_ListeLB.GetItemCount(); i++)
							{
								m_ListeLB.SetItemState(i-1, m_ListeLB.GetItemState(i, 0xffffffff), 0xffffffff);
								m_ListeLB.SetRedraw(TRUE);
							}

							if (nLastSelection > 0) 
								nLastSelection--;

							DoDeleteEintrag(p);
		
							RefreshListe();

							break;
						}
					}
				}
			}
		}
		break;
	}

	CResizablePage::OnTimer(nIDEvent);
}

void CTelArPropertyPage2::OnFf2() 
{
	DF("CTelArPropertyPage2::OnFf2()");

	char buf[30];
	char cmd[80];
	long l;
	GetDlgItem(IDC_LISTE)->SetFocus();	
	if (!bPlaying) return;
	MyMciSendString("status s1 position",buf,sizeof(buf),m_hWnd);
	l = atol(buf) + 60000;
	if (l < 0) l = 0;
	sprintf(cmd,"seek s1 to %ld",l);
	mciSendString(cmd,buf,sizeof(buf),m_hWnd);
	bSeeking = TRUE;
	KillTimer(2);
	SetTimer(2, 100, NULL);
}

void CTelArPropertyPage2::OnRew2() 
{
	DF("CTelArPropertyPage2::OnRew2()");

	char buf[30];
	char cmd[80];
	long l;
	GetDlgItem(IDC_LISTE)->SetFocus();	
	if (!bPlaying) return;
	MyMciSendString("status s1 position",buf,sizeof(buf),m_hWnd);
	l = atol(buf) - 60000;
	if (l < 0) l = 0;
	sprintf(cmd,"seek s1 to %ld",l);
	mciSendString(cmd,buf,sizeof(buf),m_hWnd);
	bSeeking = TRUE;
	KillTimer(2);
	SetTimer(2, 100, NULL);
}

void CTelArPropertyPage2::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	DF("CTelArPropertyPage2::OnHScroll()");

	long l;
	if (nSBCode != SB_ENDSCROLL)
	{
		if (X_anschluss != -1)
		{
			if (nSBCode == SB_PAGELEFT || nSBCode == SB_PAGERIGHT)
			{
				l = 0xffff & ((CSliderCtrl *)GetDlgItem(IDC_SLIDER))->GetPos();
			}
			else
			{
				l = 0xffff & nPos;
			}
			if (!bSeeking)
			{
				char cmd[30];
				char buf[30];
				if (!bPlaying) return;
				position = l * 1000;
				sprintf(cmd,"seek s1 to %ld",position);
				MyMciSendString(cmd,buf,sizeof(buf),m_hWnd);
				KillTimer(2);
				SetTimer(2, 100, NULL);
				bSeeking = TRUE;

				//do
				//	MyMciSendString("status s1 mode",buf,sizeof(buf),m_hWnd);
				//while (!strcmp(buf, "stopped") && bPlaying);	// oh je...
			}
		}
	}
	
	
	CResizablePage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTelArPropertyPage2::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	DF("CTelArPropertyPage2::OnVScroll()");

	// Speaker volume slider notification code
	WORD wVolume;
	wVolume = 0xffff - ((CSliderCtrl *)GetDlgItem(IDC_SPEAKERVOLUME))->GetPos();
	
	// distinguish time priror and after Vista: In vista there is no longer an order of devices that are both, input and output.
	// Instead, input and output plugs of a device act as separate devices!
	if (VISTA_RUNNING)
	{
		MMRESULT res;
		DWORD (__cdecl *pSetDefaultOutputVolume)(WORD);
		pSetDefaultOutputVolume = (DWORD (__cdecl *)(WORD))GetProcAddress(hSCRVistaHelper, "SetDefaultOutputVolume");
		if (pSetDefaultOutputVolume) 
		{
			res = (*pSetDefaultOutputVolume)(wVolume);
			if (res != MMSYSERR_NOERROR)
			{
				DF1("CTelArPropertyPage2::OnInitDialog() -- SetDefaultOutputVolume returned error %ud", (DWORD)res);
			}
		}	
	}
	else	// control the output volume of the device that is also used as input device
	{
		MMRESULT res;
		res = waveOutSetVolume((HWAVEOUT)X_aufnahmegeraet, (DWORD)wVolume|((DWORD)wVolume<<16));
		if (res != MMSYSERR_NOERROR)
		{
			DF1("CTelArPropertyPage2::OnInitDialog() -- waveOutSetVolume returned error %ud", (DWORD)res);
		}
	}
	
	CResizablePage::OnVScroll(nSBCode, nPos, pScrollBar);
}

//-- Edit/Delete-Knöpfe -----


void CTelArPropertyPage2::OnEdit() 
{
	DF("CTelArPropertyPage2::OnEdit()");

	GetDlgItem(IDC_LISTE)->SetFocus();	

	if (m_CurrentIndexType == IDXTYPE_FILE)
	{
		char buffer[1000];
		LANG2BUFFER(IDS_STRING178, buffer);
		if (AfxMessageBox(buffer, MB_YESNO) == IDYES) // The index file in this folder has an outdated format and needs to be converted before it can be modified. Do you want to convert it now?
		{
			char pathfile[1000];
			
			TMZeile *p = pFolders->Find(0, csOrdner);
			if (!p) return;

			strcpy(pathfile, (LPCSTR)p->Spalte(1));
			if (!DoConvert(pathfile, ""))
				return;
			else
			{
				RefreshListe();
				return;
			}
		}
		else
			return;
	}

	POSITION pos = m_ListeLB.GetFirstSelectedItemPosition();
	if (pos)
		nLastSelection = m_ListeLB.GetNextSelectedItem(pos);
	else
		nLastSelection = -1;

	if (nLastSelection < 0)
	{
		LANG_MESSAGEBOX2(IDS_STRING55, MB_ICONEXCLAMATION); // Bitte wählen Sie erst einen Listeneintrag.
		return;
	}
	
	TMZeile *zeile = SafeGetItemData(nLastSelection);
	if (!liste_index.SeekRecordingByDateTimeID(zeile)) return;
	if (!liste_index.GetNextRecording(zeile)) return;
	liste_index.EndSeekRecording();

	if (zeile)
	{
		if (zeile->Spalte(SPID_DATEINAME) == "") return;
		
		TMZeile *tmzeile_edit = new TMZeile();
		*tmzeile_edit = *zeile;

		int idd;
		if (!strcmp(C_language, "D")) 
			idd = IDD_EDIT;
		else if (!strcmp(C_language, "GB")) 
			idd = IDD_GB_EDIT;
		else if (!strcmp(C_language, "CZ")) 
			idd = IDD_CZ_EDIT;
		else if (!strcmp(C_language, "NL")) 
			idd = IDD_NL_EDIT;
		else if (!strcmp(C_language, "PL")) 
			idd = IDD_PL_EDIT;
		else 
			idd = IDD_E_EDIT;
		CEditDlg dlg(idd);
		dlg.m_partner = tmzeile_edit->Spalte(SPID_GESPRAECHSPARTNER);
		dlg.m_partner.TrimRight();
		dlg.m_notiz = tmzeile_edit->Spalte(SPID_NOTIZEN);
		dlg.m_notiz.TrimRight();
		if (dlg.DoModal() == IDOK)
		{
			BOOL bReturn;

			tmzeile_edit->Spalte(SPID_GESPRAECHSPARTNER) = dlg.m_partner;
			tmzeile_edit->Spalte(SPID_NOTIZEN) = dlg.m_notiz;
			if (!tmzeile_edit->Spalte(SPID_GESPRAECHSPARTNER).GetLength()) tmzeile_edit->Spalte(SPID_GESPRAECHSPARTNER) = " ";
			if (!tmzeile_edit->Spalte(SPID_NOTIZEN).GetLength()) tmzeile_edit->Spalte(SPID_NOTIZEN) = " ";

			bReturn = liste_index.UpdateRecordingByDateTimeID(tmzeile_edit);
			if (bReturn)
			{
				*zeile = *tmzeile_edit;
				GetDlgItem(IDC_LISTE)->RedrawWindow();
			}

			liste_index.AppendAccesslog("Edit", bReturn, tmzeile_edit->Spalte(SPID_DATEINAME).GetBuffer(0));
		}
				
		delete tmzeile_edit;
	}
	else
		return;
}

// start direct editing in listctrl
void CTelArPropertyPage2::OnBeginlabeleditListe(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;

	if (m_CurrentIndexType == IDXTYPE_FILE)
	{
		*pResult = TRUE;
		OnEdit();
		return;
	}

	// update item in case some other user in the network has changed it in the meantime
	TMZeile *zeile = SafeGetItemData(pDispInfo->item.iItem);
	if (!liste_index.SeekRecordingByDateTimeID(zeile)) return;
	if (!liste_index.GetNextRecording(zeile)) return;
	liste_index.EndSeekRecording();

	if (pDispInfo->item.iSubItem == 3)
	{
		delete pDispInfo->item.pszText;	
		pDispInfo->item.cchTextMax = zeile->Spalte(SPID_GESPRAECHSPARTNER).GetLength()+1;
		pDispInfo->item.pszText = new TCHAR[pDispInfo->item.cchTextMax];			
		strcpy(pDispInfo->item.pszText, zeile->Spalte(SPID_GESPRAECHSPARTNER).GetBuffer(0));
	}
	else if (pDispInfo->item.iSubItem == 4)
	{
		delete pDispInfo->item.pszText;	
		pDispInfo->item.cchTextMax = zeile->Spalte(SPID_NOTIZEN).GetLength()+1;
		pDispInfo->item.pszText = new TCHAR[pDispInfo->item.cchTextMax];			
		strcpy(pDispInfo->item.pszText, zeile->Spalte(SPID_NOTIZEN).GetBuffer(0));
	}

	*pResult = 0;
}

// end direct editing in listctrl
void CTelArPropertyPage2::OnEndlabeleditListe(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;

    // If pszText is NULL, editing was canceled
    if(pDispInfo->item.pszText != NULL && m_CurrentIndexType != IDXTYPE_FILE)
    {        
		TMZeile *zeile = SafeGetItemData(pDispInfo->item.iItem);

		if (pDispInfo->item.iSubItem == 3)
			zeile->Spalte(SPID_GESPRAECHSPARTNER) = pDispInfo->item.pszText;
		else if (pDispInfo->item.iSubItem == 4)
			zeile->Spalte(SPID_NOTIZEN) = pDispInfo->item.pszText;

		if (!liste_index.UpdateRecordingByDateTimeID(zeile)) return;
    }
	
	*pResult = 0;
}

void CTelArPropertyPage2::OnDelete() 
{
	DF("CTelArPropertyPage2::OnDelete()");

	if (m_CurrentIndexType == IDXTYPE_FILE)
	{
		char buffer[1000];
		LANG2BUFFER(IDS_STRING178, buffer);
		if (AfxMessageBox(buffer, MB_YESNO) == IDYES) // The index file in this folder has an outdated format and needs to be converted before it can be modified. Do you want to convert it now?
		{
			char pathfile[1000];
			
			TMZeile *p = pFolders->Find(0, csOrdner);
			if (!p) return;

			strcpy(pathfile, (LPCSTR)p->Spalte(1));
			if (!DoConvert(pathfile, ""))
				return;
			else
			{
				RefreshListe();
				return;
			}
		}
		else
			return;
	}

	char buffer[1000];

	GetDlgItem(IDC_LISTE)->SetFocus();	

	int n;
	POSITION pos = m_ListeLB.GetFirstSelectedItemPosition();
	if (pos)
		n = m_ListeLB.GetNextSelectedItem(pos);
	else
		n = -1;

	if (n < 0)
	{
		LANG_MESSAGEBOX2(IDS_STRING55, MB_ICONEXCLAMATION); // Bitte wählen Sie erst einen Listeneintrag.
		return;
	}

	LANG2BUFFER(IDS_STRING61, buffer);
	if (AfxMessageBox(buffer, MB_YESNO) != IDYES) return;

	int *items, i = 0;
	n = ((CQuickList *)(GetDlgItem(IDC_LISTE)))->GetItemCount();
	items = new int[n];

	POSITION p = m_ListeLB.GetFirstSelectedItemPosition();
	while (p)
	{
		int nSelected = m_ListeLB.GetNextSelectedItem(p);
		items[i++] = nSelected;
	}

	LoescheListeneintraege((CListCtrl *)GetDlgItem(IDC_LISTE), items, i);
	
	((CTelArPropertyPage2*)GetParent())->OnSelchange(this);

	delete items;
}

void CTelArPropertyPage2::DoDeleteEintrag(TMZeile *zeile)
{
	DF1("CTelArPropertyPage2::DoDeleteEintrag(%s)", zeile->Spalte(SPID_DATEINAME))
	char buffer[1000];

	if (m_CurrentIndexType == IDXTYPE_FILE) return;	// only for safety

	if (zeile->Spalte(SPID_DATEINAME) == "") return;
	
	TMZeile *p = pFolders->Find(0, csOrdner);
	if (!p)
		strcpy(buffer, X_path);
	else
		strcpy(buffer, (LPCSTR)p->Spalte(1));

	if (*buffer && buffer[strlen(buffer)-1] != '\\')
		strcat(buffer, "\\");

	strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
	DeleteFile(buffer);

	// delete record in database index file
	if (m_CurrentIndexType != IDXTYPE_FILE)
		liste_index.DeleteRecordingByDateTimeID(zeile);

	/* old index file code:
	if (m_CurrentIndexType == IDXTYPE_FILE)
	{
		char pathfile[1000];
		int file_version = INDEX_FILEVERSION;
		
		if (!p)
			strcpy(pathfile, X_path);
		else
			strcpy(pathfile, (LPCSTR)p->Spalte(1));

		if (*pathfile && pathfile[strlen(pathfile)-1] != '\\')
			strcat(pathfile, "\\");
		strcat(pathfile, INDEX_FILENAME);

		CString cs = zeile->Spalte(SPID_DATEINAME);
		CString *pcs = &cs;
		if (!theTabelle.DeleteZeilen(pathfile, &file_version, SPID_DATEINAME, &pcs, 1))
			LANG_MESSAGEBOX2(IDS_STRING62, MB_ICONSTOP);
	} */
}

//-- die Extra-Knöpfe: -----

void CTelArPropertyPage2::OnSuchen() 
{
	DF("CTelArPropertyPage2::OnSuchen()");

	GetDlgItem(IDC_LISTE)->SetFocus();	

	
	if (!suchfilter)
	{
		suchfilter = new CSuchfilterDlg(IDD_SUCHFILTER, this);
		suchfilter->Create(IDD_SUCHFILTER, this);
		suchfilter->ShowWindow(SW_SHOW);
	}
	else if (suchfilter->IsWindowVisible())
	{
		CWindowAnima wa(suchfilter);
		wa.Wipe(WA_LEFT,16,1);
		suchfilter->ShowWindow(SW_HIDE);		
	}
	else
	{
		suchfilter->ShowWindow(SW_SHOW);
	}

	RefreshListe();
}

//- Export ---

// Locate a driver that supports a given format and return its ID
typedef struct {
	HACMDRIVERID hadid;
	WORD  wFormatTag;
	DWORD nSamplesPerSec;
	WORD  nChannels;
	WORD  wBitsPerSample;
} FIND_DRIVER_INFO;

// callback function for format enumeration
BOOL CALLBACK find_format_enum(HACMDRIVERID hadid, LPACMFORMATDETAILS pafd, DWORD_PTR dwInstance, DWORD fdwSupport)
{
	FIND_DRIVER_INFO* pdi = (FIND_DRIVER_INFO*) dwInstance;

#if defined(_DEBUG)	
	// get some details
	ACMDRIVERDETAILS dd;
	dd.cbStruct = sizeof(dd);
	MMRESULT mmr = acmDriverDetails(hadid, &dd, 0);
	TRACE2("%s %d\n", dd.szLongName, (int)pafd->dwFormatTag);
#endif

	if (pafd->dwFormatTag == (DWORD)pdi->wFormatTag
		&& pafd->pwfx->nSamplesPerSec == (DWORD)pdi->nSamplesPerSec
		&& pafd->pwfx->nChannels == (DWORD)pdi->nChannels
		&& pafd->pwfx->wBitsPerSample == (DWORD)pdi->wBitsPerSample) {
		// found it
		pdi->hadid = hadid;
		return FALSE; // stop enumerating
	}

	return TRUE; // continue enumerating
}

// callback function for driver enumeration
BOOL CALLBACK find_driver_enum(HACMDRIVERID hadid, DWORD_PTR dwInstance, DWORD fdwSupport)
{
	FIND_DRIVER_INFO* pdi = (FIND_DRIVER_INFO*) dwInstance;

	// open the driver
	HACMDRIVER had = NULL;
	MMRESULT mmr = acmDriverOpen(&had, hadid, 0);
	if (mmr) {

		// some error
		return FALSE; // stop enumerating

	}

	// enumerate the formats it supports
	DWORD dwSize = 0;
	mmr = acmMetrics((HACMOBJ)had, ACM_METRIC_MAX_SIZE_FORMAT, &dwSize);
	if (dwSize < sizeof(WAVEFORMATEX)) dwSize = sizeof(WAVEFORMATEX); // for MS-PCM
	WAVEFORMATEX* pwf = (WAVEFORMATEX*) new char[(dwSize)];
	memset(pwf, 0, dwSize);
	pwf->cbSize = LOWORD(dwSize) - sizeof(WAVEFORMATEX);
	pwf->wFormatTag = pdi->wFormatTag;
	ACMFORMATDETAILS fd;
	memset(&fd, 0, sizeof(fd));
	fd.cbStruct = sizeof(fd);
	fd.pwfx = pwf;
	fd.cbwfx = dwSize;
	fd.dwFormatTag = pdi->wFormatTag;
	mmr = acmFormatEnum(had, &fd, find_format_enum, (DWORD_PTR)pdi, 0);  
	delete(pwf);
	acmDriverClose(had, 0);
	if (pdi->hadid || mmr) {
		// found it or some error
		return FALSE; // stop enumerating
	}

	return TRUE; // continue enumeration
}

// locate the first driver that supports a given format tag
HACMDRIVERID find_driver(WORD wFormatTag, int SamplesPerSec, int Channels, short BitsPerSample)
{
	FIND_DRIVER_INFO fdi;
	fdi.hadid = NULL;
	fdi.wFormatTag = wFormatTag;
	fdi.nSamplesPerSec = SamplesPerSec;
	fdi.nChannels = Channels;
	fdi.wBitsPerSample = BitsPerSample;
	MMRESULT mmr = acmDriverEnum(find_driver_enum, (DWORD)(VOID*)&fdi, 0); 
	if (mmr) return NULL;
	return fdi.hadid;
}

void CTelArPropertyPage2::OnExport() 
{
	DF("CTelArPropertyPage2::OnExport()");

	char buffer[1000];

	GetDlgItem(IDC_LISTE)->SetFocus();	

	int n;
	POSITION pos = m_ListeLB.GetFirstSelectedItemPosition();
	if (pos)
		n = m_ListeLB.GetNextSelectedItem(pos);
	else
		n = -1;

	if (n < 0)
	{
		LANG_MESSAGEBOX2(IDS_STRING41, MB_ICONEXCLAMATION); // Bitte wählen Sie aus der Liste eine Aufnahme zum WAV-Export!
		return;
	}

	// nochmal an den Anfang:
	pos = m_ListeLB.GetFirstSelectedItemPosition();
	POSITION pos2 = pos;	// safe it

	BOOL bSuccess = FALSE;

	while (pos)
	{
		int nSelected = m_ListeLB.GetNextSelectedItem(pos);
		TMZeile *zeile = SafeGetItemData(nSelected);

		if (zeile)
		{
			if (zeile->Spalte(SPID_DATEINAME) == "") break;
		}
		else
			break;

		TMZeile *p = pFolders->Find(0, csOrdner);
		if (!p)
			strcpy(buffer, X_path);
		else
			strcpy(buffer, (LPCSTR)p->Spalte(1));

		if (*buffer && buffer[strlen(buffer)-1] != '\\')
			strcat(buffer, "\\");

		strcat(buffer, zeile->Spalte(SPID_DATEINAME).GetBuffer(0));
		if (strlen(buffer) >= 3 && strcmp(buffer+strlen(buffer)-3, "wav"))
		{
			char temp_path[1000];
			char *cp;
			CString passwort_buffer;

			if (!(cp = strrchr(buffer, '\\'))) break;
			strcpy(temp_path, cp+1);
			if (strlen(temp_path) >= 3) strcpy(temp_path+strlen(temp_path)-3, "wav");

			CFileDialog cf(FALSE, "*.WAV", temp_path, 0, "Windows audio format (*.wav)|*.WAV||",this);
			if (cf.DoModal() != IDOK)
				break;

			else
				strcpy(temp_path, cf.GetPathName().GetBuffer(0));

			CString pw;
			if (atoi((LPCSTR)zeile->Spalte(SPID_GESCHUETZT)))
			{   // mit PW und Dateinamen geschützt:
				{	// Passwortabfrage:
					int idd;
					
					if (!strcmp(C_language, "D")) 
						idd = IDD_PASSWORT_CHECK;
					else if (!strcmp(C_language, "GB")) 
						idd = IDD_GB_PASSWORT_CHECK;
					else if (!strcmp(C_language, "CZ")) 
						idd = IDD_CZ_PASSWORT_CHECK;
					else if (!strcmp(C_language, "NL")) 
						idd = IDD_NL_PASSWORT_CHECK;
					else if (!strcmp(C_language, "PL")) 
						idd = IDD_PL_PASSWORT_CHECK;
					else 
						idd = IDD_E_PASSWORT_CHECK;


					CPasswortCheckDlg dlg(idd, &passwort_buffer, this);
					if (dlg.DoModal() != IDOK) break;
				}
				passwort_buffer.TrimLeft();
				passwort_buffer.TrimRight();
				pw = passwort_buffer; 
			}
			else
				pw = "";		
			pw += zeile->Spalte(SPID_DATEINAME); // nur mit Dateinamen geschützt

			if (DecryptFile((CString)buffer, (CString)temp_path, pw))
			{
				strcpy(buffer, temp_path);
			}
			else
			{
				char fmt[2000], buffer2[2000];
				LANG2BUFFER(IDS_STRING38, fmt);
				sprintf(buffer2, fmt, buffer);
				AfxMessageBox(buffer2, MB_ICONSTOP);	
				break;
			}
		}
		else	// if recording is in wav format, just copy
		{
			char temp_path[1000];
			char *cp;

			if (!(cp = strrchr(buffer, '\\'))) break;
			strcpy(temp_path, cp+1);

			CFileDialog cf(FALSE, "*.WAV", temp_path, 0, "Windows audio format (*.wav)|*.WAV||",this);
			if (cf.DoModal() != IDOK)
				break;

			else
			{
				CString cs = cf.GetPathName();
				if (!CopyFile(buffer, cs.GetBuffer(0), TRUE))
				{
					char bufferx[1000], formatstr[1000];
					LANG2BUFFER(IDS_STRING68, formatstr);
					sprintf(bufferx, formatstr, buffer);
					AfxMessageBox(bufferx, MB_ICONINFORMATION); // Recording couldnt be kopied due to filesystem error. Please check source and destination folders.
					break;
				}
			}

		}

		union {
			struct {
				char  riff[4];
				DWORD rifflen;
				char  wave[4];
				char  fmt[4];
				DWORD fmtlen;
				WAVEFORMATEX wfx;
			} fileheader;
			char buffer[1000];
		} wfxx;
		CFile fsource;

		// WAV-Header lesen
		if (!fsource.Open(buffer, CFile::modeRead)) 
		{
			LANG_MESSAGEBOX2(IDS_STRING29, MB_ICONSTOP);		
			break;
		}
		if (fsource.Read(wfxx.buffer, sizeof(wfxx.buffer)) != sizeof(wfxx.buffer)) 
		{
			LANG_MESSAGEBOX2(IDS_STRING42, MB_ICONSTOP);		
			fsource.Close();
			break;
		}
		fsource.Close();

		if (strncmp(wfxx.fileheader.riff, "RIFF", 4) || strncmp(wfxx.fileheader.wave, "WAVE", 4) || strncmp(wfxx.fileheader.fmt, "fmt ", 4))
		{
			LANG_MESSAGEBOX2(IDS_STRING46, MB_ICONSTOP);		
			break;
		}

		if (wfxx.fileheader.wfx.wFormatTag != WAVE_FORMAT_PCM)
		{
			
			HACMDRIVERID hadid = find_driver(wfxx.fileheader.wfx.wFormatTag, 
				wfxx.fileheader.wfx.nSamplesPerSec, 
				wfxx.fileheader.wfx.nChannels, 
				wfxx.fileheader.wfx.wBitsPerSample);
			if (!hadid) 	
			{
				LANG_MESSAGEBOX2(IDS_STRING43, MB_ICONSTOP);		
				break;
			}

			ACMDRIVERDETAILS dd;
			dd.cbStruct = sizeof(dd);
			MMRESULT mmr = acmDriverDetails(hadid, &dd, 0);
			if (mmr) 
			{
				LANG_MESSAGEBOX2(IDS_STRING43, MB_ICONSTOP);				
				break;
			}

			if (n == 1)
			{
				char bufferx[1000], formatstr[1000];
				LANG2BUFFER(IDS_STRING44, formatstr);
				sprintf(bufferx, formatstr, dd.szLongName);
				AfxMessageBox(bufferx, MB_ICONINFORMATION);
			}
			
			bSuccess = TRUE;

			/*
			ACMFORMATTAGDETAILS aftd;
			memset(&aftd, sizeof(aftd), 0x00);
			aftd.cbStruct = sizeof(aftd);
			//afd.dwFormatIndex = 0;
			aftd.dwFormatTag = wfxx.fileheader.wfx.wFormatTag;
			aftd.fdwSupport = ACMDRIVERDETAILS_SUPPORTF_CODEC;
			//afd.pwfx = &wfxx.wfx;
			//afd.cbwfx = sizeof(wfxx.buffer);
			//MMRESULT mmr = acmFormatDetails(NULL, &afd, ACM_FORMATDETAILSF_FORMAT);
			MMRESULT mmr = acmFormatTagDetails(NULL, &aftd, ACM_FORMATTAGDETAILSF_FORMATTAG);
			if (mmr) 
			{
				LANG_MESSAGEBOX2(IDS_STRING43, MB_ICONSTOP);		
				break;
			}

			char bufferx[1000], formatstr[200];
			LANG2BUFFER(IDS_STRING44, formatstr);
			sprintf(bufferx, formatstr, aftd.szFormatTag);
			AfxMessageBox(bufferx, MB_ICONINFORMATION);
			*/
		}
	}

	// Success message it: 1) a recording has been selected, 2) the loop has been entered and ran to the las element, 3) at least one recording was exported
	if (pos2 && !pos && bSuccess) LANG_MESSAGEBOX2(IDS_STRING45, MB_ICONINFORMATION); // Recording(s) successfully exported to WAV format.
}


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage3 property page

CTelArPropertyPage3::CTelArPropertyPage3() : CResizablePage(CTelArPropertyPage3::IDD)
{
	//{{AFX_DATA_INIT(CTelArPropertyPage3)
	m_radio = -1;
	m_intelligent_radio = -1;
	//}}AFX_DATA_INIT
}

CTelArPropertyPage3::~CTelArPropertyPage3()
{
}

void CTelArPropertyPage3::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTelArPropertyPage3)
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Radio(pDX, IDC_INTELLIGENT_RADIO3, m_intelligent_radio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTelArPropertyPage3, CResizablePage)
	//{{AFX_MSG_MAP(CTelArPropertyPage3)
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_DEVICE, OnSelchangeDevice)
	ON_CBN_SELCHANGE(IDC_SAMPLINGRATE, OnSelchangeSamplingrate)
	ON_CBN_SELCHANGE(IDC_ANSCHLUSS, OnSelchangeAnschluss)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio)
	ON_BN_CLICKED(IDC_ANSCHLUSS_VISTA_MUTE,OnAnschlussVistaMute)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_INTELLIGENT_RADIO2, OnIntelligentActive)
	ON_BN_CLICKED(IDC_INTELLIGENT_RADIO3, OnIntelligentInactive)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()


BOOL CTelArPropertyPage3::OnInitDialog() 
{
	DF("CTelArPropertyPage3::OnInitDialog()");
	CResizablePage::OnInitDialog();

	// preset layout
	AddAnchor(IDC_SAMPLINGRATE_FRAME, MIDDLE_CENTER);	
	AddAnchor(IDC_SAMPLINGRATE_STATIC, MIDDLE_CENTER);	
	AddAnchor(IDC_DEFAULT_STATIC, MIDDLE_CENTER);	
	AddAnchor(IDC_SAMPLINGRATE, MIDDLE_CENTER);	
	AddAnchor(IDC_GERAET_FRAME, MIDDLE_CENTER);	
	AddAnchor(IDC_GERAET_STATIC, MIDDLE_CENTER);	
	AddAnchor(IDC_DEVICE, MIDDLE_CENTER);	
	AddAnchor(IDC_ANSCHLUSS_FRAME, MIDDLE_CENTER);	
	AddAnchor(IDC_ANSCHLUSS_STATIC, MIDDLE_CENTER);	
	AddAnchor(IDC_ANSCHLUSS, MIDDLE_CENTER);	
	AddAnchor(IDC_ANSCHLUSS_VISTA_MUTE, MIDDLE_CENTER);	
	AddAnchor(IDC_ADVERTISING, MIDDLE_CENTER);	
	AddAnchor(IDC_AUFNAHMESTART_FRAME, MIDDLE_CENTER);	
	AddAnchor(IDC_AUFNAHMESTART_STATIC, MIDDLE_CENTER);	
	AddAnchor(IDC_RADIO1, MIDDLE_CENTER);	
	AddAnchor(IDC_RADIO2, MIDDLE_CENTER);	
	AddAnchor(IDC_RADIO3, MIDDLE_CENTER);	
	AddAnchor(IDC_INTELLIGENT_FRAME, MIDDLE_CENTER);	
	AddAnchor(IDC_INTELLIGENT_STATIC, MIDDLE_CENTER);	
	AddAnchor(IDC_INTELLIGENT_RADIO3, MIDDLE_CENTER);	
	AddAnchor(IDC_INTELLIGENT_RADIO2, MIDDLE_CENTER);	
	AddAnchor(IDC_VENDOR_LOGO_FRAME, BOTTOM_RIGHT);	

	SetDlgItemText(IDC_DEFAULT, X_path);

	char buffer[1000];
	int n;
	sprintf(buffer, "%d", X_samplingrate);
	if ((n = ((CComboBox *)GetDlgItem(IDC_SAMPLINGRATE))->FindString(0, buffer)) != CB_ERR)
		((CComboBox *)GetDlgItem(IDC_SAMPLINGRATE))->SetCurSel(n);
	else
		((CComboBox *)GetDlgItem(IDC_SAMPLINGRATE))->SetCurSel(0);
	
	ShowDevices();
	((CComboBox *)GetDlgItem(IDC_DEVICE))->SetCurSel(X_aufnahmegeraet);
	
	SetTimer(1, 1, NULL);

	m_radio = X_modus;
	m_intelligent_radio = X_intelligent;
	UpdateData(FALSE);

	((CButton *)GetDlgItem(IDC_INTELLIGENT_RADIO3))->EnableWindow(!X_modus);
	((CButton *)GetDlgItem(IDC_INTELLIGENT_RADIO2))->EnableWindow(!X_modus);

	LANG2BUFFER(IDS_STRING81, buffer);
	SetDlgItemText(IDC_SAMPLINGRATE_STATIC, buffer);
	LANG2BUFFER(IDS_STRING82, buffer);
	SetDlgItemText(IDC_GERAET_STATIC, buffer);
	LANG2BUFFER(IDS_STRING83, buffer);
	SetDlgItemText(IDC_ANSCHLUSS_STATIC, buffer);
	LANG2BUFFER(IDS_STRING199, buffer);
	SetDlgItemText(IDC_ANSCHLUSS_VISTA_MUTE, buffer);
	if (VISTA_RUNNING)
	{
		GetDlgItem(IDC_ANSCHLUSS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ANSCHLUSS_VISTA_MUTE)->ShowWindow(SW_SHOW);		
	}	
	LANG2BUFFER(IDS_STRING84, buffer);
	SetDlgItemText(IDC_AUFNAHMESTART_STATIC, buffer);
	LANG2BUFFER(IDS_STRING85, buffer);
	SetDlgItemText(IDC_RADIO1, buffer);
	LANG2BUFFER(IDS_STRING86, buffer);
	SetDlgItemText(IDC_RADIO2, buffer);
	//LANG2BUFFER(IDS_STRING???, buffer);	"TAPI Event" is international...
	//SetDlgItemText(IDC_RADIO3, buffer);

	LANG2BUFFER(IDS_STRING139, buffer);
	SetDlgItemText(IDC_INTELLIGENT_RADIO3, buffer);
	LANG2BUFFER(IDS_STRING140, buffer);
	SetDlgItemText(IDC_INTELLIGENT_RADIO2, buffer);

#ifdef TAPI
	GetDlgItem(IDC_RADIO3)->ShowWindow(SW_SHOW);
#endif
	DF("CTelArPropertyPage3::OnInitDialog() -- exit");
	return TRUE; 
}

void CTelArPropertyPage3::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	CRect r;
	GetClientRect(&r);
	InvalidateRect(r);
}

void CTelArPropertyPage3::OnTimer(UINT_PTR  nIDEvent) 
{
	if (nIDEvent == 1)
	{
		// wait after InitDialog is finished before trying to open a device, just to ensure a message box can be displayed in case of an error
		ShowAux();
		if (X_anschluss != -1)
		{
			((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetCurSel(X_anschluss);	
			DF1("CTelArPropertyPage3::OnTimer() -- X_anschluss set to %d", X_anschluss);
		}
		KillTimer(1);
	}
	
	CResizablePage::OnTimer(nIDEvent);
}

// Hintergrundbitmap malen
BOOL CTelArPropertyPage3::OnEraseBkgnd( CDC* pDC )
{
	CResizablePage::OnEraseBkgnd(pDC);

	char buffer[200];
	VEND2BUFFER(IDS_STRING1, buffer);

	DF("CTelArPropertyPage3::OnEraseBkgnd()");

	CRect r, fr;

	if (!strcmp(buffer, "PhoneCoach CompuCorder"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_PHONECOACH_ON_GREY, &fr, 0);
	}
	else if (!strcmp(buffer, "Actimax"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_ACTIMAX_ON_GREY, &fr, 0);
	}
	else
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_RETELL_ON_GREY, &fr, 0);
	}

	DF("CTelArPropertyPage3::OnEraseBkgnd() -- exit");
	return TRUE;
}

// Extras malen
void CTelArPropertyPage3::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	DF("CTelArPropertyPage3::OnPaint()");
	
	RECT pr, cr, clir;

	GetWindowRect(&pr);

	// char buffer[50];
	int nOldBkMode = dc.SetBkMode(TRANSPARENT);
	GetDlgItem(IDC_DEFAULT_STATIC)->GetWindowRect(&cr);

	CFont *standardFont = dc.GetCurrentFont();
	LOGFONT FontStats;
	standardFont->GetLogFont(&FontStats);
	strcpy(FontStats.lfFaceName, "MS Sans Serif"); 
	FontStats.lfHeight  = cr.bottom-cr.top;
	FontStats.lfWidth   = 0;	// Breite relativ zur Höhe verkleinern
	FontStats.lfQuality = DEFAULT_QUALITY;
	FontStats.lfWeight	= 700;	// default weight
	CFont neuerFont;	// Font kreiren
	neuerFont.CreateFontIndirect(&FontStats);
	CFont *oldFont = dc.SelectObject(&neuerFont);	// in den device context damit

	CBrush grey;
	grey.CreateSolidBrush(RGB(191, 191, 191));
	
	GetDlgItem(IDC_SAMPLINGRATE_FRAME)->GetWindowRect(&cr);
	clir.left = cr.left-pr.left;
	clir.top = cr.top-pr.top;
	clir.right = cr.right-pr.left;
	clir.bottom = cr.bottom-pr.top;
	dc.FillRect(&clir, &grey);
	DrawAndCenterBitmap(&dc, IDB_SAMPLINGRATE, &clir);

	GetDlgItem(IDC_GERAET_FRAME)->GetWindowRect(&cr);
	clir.left = cr.left-pr.left;
	clir.top = cr.top-pr.top;
	clir.right = cr.right-pr.left;
	clir.bottom = cr.bottom-pr.top;
	dc.FillRect(&clir, &grey);
	DrawAndCenterBitmap(&dc, IDB_HARDWARE, &clir);

	GetDlgItem(IDC_ANSCHLUSS_FRAME)->GetWindowRect(&cr);
	clir.left = cr.left-pr.left;
	clir.top = cr.top-pr.top;
	clir.right = cr.right-pr.left;
	clir.bottom = cr.bottom-pr.top;
	dc.FillRect(&clir, &grey);
	DrawAndCenterBitmap(&dc, IDB_ANSCHLUSS, &clir);

	GetDlgItem(IDC_AUFNAHMESTART_FRAME)->GetWindowRect(&cr);
	clir.left = cr.left-pr.left;
	clir.top = cr.top-pr.top;
	clir.right = cr.right-pr.left;
	clir.bottom = cr.bottom-pr.top;
	dc.FillRect(&clir, &grey);
	DrawAndCenterBitmap(&dc, IDB_AUFNAHMESTART, &clir);

	GetDlgItem(IDC_INTELLIGENT_FRAME)->GetWindowRect(&cr);
	clir.left = cr.left-pr.left;
	clir.top = cr.top-pr.top;
	clir.right = cr.right-pr.left;
	clir.bottom = cr.bottom-pr.top;
	dc.FillRect(&clir, &grey);
	DrawAndCenterBitmap(&dc, IDB_INTELLIGENT, &clir);

  // alten Font und BG-Mode restaurieren
	dc.SelectObject(oldFont);
	dc.SetBkMode(nOldBkMode);
	
	DF("CTelArPropertyPage3::OnPaint() -- exit");
}


void CTelArPropertyPage3::OnDestroy() 
{
	DF("CTelArPropertyPage3::OnDestroy()");
	
	RemoveAllAnchors();

	CResizablePage::OnDestroy();
}


void CTelArPropertyPage3::OnSelchangeDevice() 
{
	DF1("CTelArPropertyPage3::OnSelchangeDevice(X_aufnahmegeraet==%d)", (int)X_aufnahmegeraet);

	int Old_X_aufnahmegeraet = X_aufnahmegeraet;
	BOOL bDoIt = FALSE;

	int nTempDevice = ((CComboBox *)GetDlgItem(IDC_DEVICE))->GetCurSel();
	if (nTempDevice == X_aufnahmegeraet) 
	{
		DF("CTelArPropertyPage3::OnSelchangeDevice() -- device still the same: exit");
		return;
	}
	X_aufnahmegeraet = nTempDevice;
	CString csDeviceName;
	((CComboBox *)GetDlgItem(IDC_DEVICE))->GetLBText(nTempDevice, csDeviceName);
	strcpy(X_aufnahmegeraetname, csDeviceName.GetBuffer(0));
	X_anschluss = -1;

	// evtl. autom. Aufnahme anhalten
	if (m_pTelArPropertyPage1->odbAufnahme.GetState() == AUTOMATIK_STOP) 
	{
		m_pTelArPropertyPage1->OnAufnahme();
		bDoIt = TRUE;
	}

	ShowAux();

	// set proper line according to adapter (IRI or no IRI)
	if (IsWindowVisible())
	{
		CString csFindLine;
		CString csTemp;

		if (X_intelligent)
			csFindLine = "line-in";	// line-in for IRI
		else
			csFindLine = "microphone";	// Microphone for conventional adapter

		for (int i = csFindLine.GetLength(); i > 0; i--)
		{
			for (int j = 0; j < ((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->GetCount(); j++)
			{
				((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->GetLBText(j, csTemp);
				csTemp.MakeLower();
				if (csTemp.Left(i) == csFindLine.Left(i))
				{
					X_anschluss = j;
					((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetCurSel(X_anschluss);
					goto out_of_loop;
				}
			}
		}
out_of_loop:
		;
	}

	// ggf. autom. Aufnahme fortsetzen
	if (bDoIt && m_pTelArPropertyPage1->odbAufnahme.GetState() == AUTOMATIK_START) 
		m_pTelArPropertyPage1->OnAufnahme();

	if (Old_X_aufnahmegeraet != X_aufnahmegeraet)
	{
		DF3("CTelArPropertyPage3::OnSelchangeDevice() -- X_aufnahmegeraet set from %d to %d,  X_anschluss set to %d", Old_X_aufnahmegeraet, X_aufnahmegeraet, X_anschluss);
	}

	DF("CTelArPropertyPage3::OnSelchangeDevice() -- exit");
}


void CTelArPropertyPage3::OnSelchangeSamplingrate() 
{
	char buffer[100];
	int n;

	DF("CTelArPropertyPage3::OnSelchangeSamplingrate()");

	if ((n = ((CComboBox *)GetDlgItem(IDC_SAMPLINGRATE))->GetCurSel()) != CB_ERR)
	{
		((CComboBox *)GetDlgItem(IDC_SAMPLINGRATE))->GetLBText(n, buffer);
		X_samplingrate = atoi(buffer);
	}

	if (IsWindowVisible())
		if (DSAMessageBox(IDS_STRING161, MB_YESNO) == IDYES)
			((CTelArPropertySheet *)GetParent())->SetActivePage(3);

	DF("CTelArPropertyPage3::OnSelchangeSamplingrate() -- exit");
}

void CTelArPropertyPage3::OnAnschlussVistaMute() 
{
	DF("CTelArPropertyPage3::OnAnschlussVistaMute()");

	if (VISTA_RUNNING)
	{
		CMuteInput dlg;
		dlg.DoModal();
	}	
	
	DF("CTelArPropertyPage3::OnAnschlussVistaMute() -- exit");
}

void CTelArPropertyPage3::OnRadio() 
{
	DF("CTelArPropertyPage3::OnRadio()");

	UpdateData(TRUE);
	X_modus = m_radio;	

	// evtl. autom. Aufnahme anhalten
	if ((X_modus == 1 && m_pTelArPropertyPage1->odbAufnahme.GetState() == AUTOMATIK_STOP)
		/*|| (X_modus == 0 && m_pTelArPropertyPage1->odbAufnahme.GetState() == MANUELLE_AUFNAHME)*/) 
	{
		m_pTelArPropertyPage1->OnAufnahme();
	}

	((CButton *)GetDlgItem(IDC_INTELLIGENT_RADIO3))->EnableWindow(!X_modus);
	((CButton *)GetDlgItem(IDC_INTELLIGENT_RADIO2))->EnableWindow(!X_modus);
	
	DF("CTelArPropertyPage3::OnRadio() -- exit");
}


void CTelArPropertyPage3::OnIntelligentInactive() 
{
	DF("CTelArPropertyPage3::OnIntelligentInactive()");

	UpdateData(TRUE);
	X_intelligent = m_intelligent_radio;	

	DF("CTelArPropertyPage3::OnIntelligentInactive()");
}

void CTelArPropertyPage3::OnIntelligentActive() 
{
	DF("CTelArPropertyPage3::OnIntelligentActive()");

	UpdateData(TRUE);
	X_intelligent = m_intelligent_radio;	
	if (X_intelligent)
	{
		// X_modus = 0;
		// ((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(0);
		// ((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(1);
		// OnRadio();

		BOOL bDoIt = FALSE;

		// evtl. autom. Aufnahme anhalten
		if (m_pTelArPropertyPage1->odbAufnahme.GetState() == AUTOMATIK_STOP) 
		{
			m_pTelArPropertyPage1->OnAufnahme();
			bDoIt = TRUE;
		}

		CDetectSMC dlg;
		if (dlg.DoModal() != IDOK)
		{
			BOOL bFound = FALSE;

			if (IsWindowVisible() || X_InitialSelection)
				if (X_InitialSelection || DSAMessageBox(IDS_STRING162, MB_YESNO) == IDYES)
				{
					// scan all input lines of current device
					for (int j = 0; j < ((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->GetCount(); j++)
					{
						((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetCurSel(j);
						OnSelchangeAnschluss();

						if (dlg.DoModal() == IDOK)
						{
							WaveIn_SetALC(FALSE);
							X_anschluss = j;
							DF1("CTelArPropertyPage3::OnIntelligentActive -- X_anschluss set to %d", X_anschluss);
							bFound = TRUE;
							break;
						}		
					}
				}

			// not found
			if (!bFound)
			{
				X_intelligent = m_intelligent_radio = 0;
				UpdateData(FALSE);
				WaveIn_SetALC(X_alc);
			}
		}
		else
		{
			WaveIn_SetALC(FALSE);
		}

		// ggf. autom. Aufnahme fortsetzen
		if (bDoIt && m_pTelArPropertyPage1->odbAufnahme.GetState() == AUTOMATIK_START) 
			m_pTelArPropertyPage1->OnAufnahme();
	}
	
	DF("CTelArPropertyPage3::OnIntelligentActive() -- exit");
}


void CTelArPropertyPage3::GetData()
{
}

// only call this once when initializing the application
void CTelArPropertyPage3::ShowDevices()
{
	static struct {
		char *name;
		WORD id;
	} manufacturer_list[] = {
		"Advanced Gravis Computer Technology, Ltd.", MM_GRAVIS, 
		"Antex Electronics Corporation", MM_ANTEX, 
		"APPS Software ", MM_APPS, 
		"Artisoft, Inc.", MM_ARTISOFT, 
		"AST Research, Inc.", MM_AST, 
		"ATI Technologies, Inc.", MM_ATI, 
		"Audio, Inc.", MM_AUDIOFILE, 
		"Audio Processing Technology", MM_APT, 
		"Audio Processing Technology", MM_AUDIOPT, 
		"Auravision Corporation", MM_AURAVISION, 
		"Aztech Labs, Inc.", MM_AZTECH, 
		"Canopus, Co., Ltd.", MM_CANOPUS, 
		"Compusic", MM_COMPUSIC, 
		"Computer Aided Technology, Inc.", MM_CAT, 
		"Computer Friends, Inc.", MM_COMPUTER_FRIENDS, 
		"Control Resources Corporation", MM_CONTROLRES, 
		"Creative Labs, Inc.", MM_CREATIVE, 
		"Dialogic Corporation", MM_DIALOGIC, 
		"Dolby Laboratories, Inc.", MM_DOLBY, 
		"DSP Group, Inc.", MM_DSP_GROUP, 
		"DSP Solutions, Inc.", MM_DSP_SOLUTIONS, 
		"Echo Speech Corporation", MM_ECHO, 
		"ESS Technology, Inc.", MM_ESS, 
		"Everex Systems, Inc.", MM_EVEREX, 
		"EXAN, Ltd.", MM_EXAN, 
		"Fujitsu, Ltd.", MM_FUJITSU, 
		"I/O Magic Corporation", MM_IOMAGIC, 
		"ICL Personal Systems", MM_ICL_PS, 
		"Ing. C. Olivetti & C., S.p.A.", MM_OLIVETTI, 
		"Integrated Circuit Systems, Inc.", MM_ICS, 
		"Intel Corporation", MM_INTEL, 
		"InterActive, Inc.", MM_INTERACTIVE, 
		"International Business Machines ", MM_IBM, 
		"Iterated Systems, Inc.", MM_ITERATEDSYS , 
		"Logitech, Inc.", MM_LOGITECH, 
		"Lyrrus, Inc.", MM_LYRRUS, 
		"Matsushita Electric Corporation of America", MM_MATSUSHITA, 
		"Media Vision, Inc.", MM_MEDIAVISION, 
		"Metheus Corporation", MM_METHEUS, 
		"microEngineering Labs", MM_MELABS, 
		"Microsoft Corporation", MM_MICROSOFT, 
		"MOSCOM Corporation", MM_MOSCOM, 
		"Motorola, Inc.", MM_MOTOROLA, 
		"Natural MicroSystems Corporation", MM_NMS, 
		"NCR Corporation", MM_NCR, 
		"NEC Corporation", MM_NEC, 
		"New Media Corporation", MM_NEWMEDIA, 
		"OKI", MM_OKI, 
		"OPTi, Inc.", MM_OPTI, 
		"Roland Corporation", MM_ROLAND, 
		"SCALACS", MM_SCALACS, 
		"Seiko Epson Corporation, Inc.", MM_EPSON, 
		"Sierra Semiconductor Corporation", MM_SIERRA, 
		"Silicon Software, Inc.", MM_SILICONSOFT, 
		"Sonic Foundry", MM_SONICFOUNDRY, 
		"Speech Compression", MM_SPEECHCOMP, 
		"Supermac Technology, Inc.", MM_SUPERMAC, 
		"Tandy Corporation", MM_TANDY, 
		"Toshihiko Okuhura, Korg, Inc.", MM_KORG, 
		"Truevision, Inc.", MM_TRUEVISION, 
		"Turtle Beach Systems", MM_TURTLE_BEACH, 
		"Video Associates Labs, Inc.", MM_VAL, 
		"VideoLogic, Inc.", MM_VIDEOLOGIC, 
		"Visual Information Technologies, Inc.", MM_VITEC, 
		"VocalTec, Inc.", MM_VOCALTEC, 
		"Voyetra Technologies", MM_VOYETRA, 
		"Wang Laboratories", MM_WANGLABS, 
		"Willow Pond Corporation", MM_WILLOWPOND, 
		"Winnov, LP", MM_WINNOV, 
		"Xebec Multimedia Solutions Limited", MM_XEBEC, 
		"Yamaha Corporation of America", MM_YAMAHA
	};
	int manufacturer_list_size = sizeof(manufacturer_list)/sizeof(manufacturer_list[0]);

	static struct {
		int  fmt_id;
		char *fmt_name;
	} fmt_list[] = {
		WAVE_FORMAT_1M08, "11.025 kHz, mono, 8-bit", 
		WAVE_FORMAT_1M16, "11.025 kHz, mono, 16-bit", 
		WAVE_FORMAT_1S08, "11.025 kHz, stereo, 8-bit", 
		WAVE_FORMAT_1S16, "11.025 kHz, stereo, 16-bit", 
		WAVE_FORMAT_2M08, "22.05 kHz, mono, 8-bit", 
		WAVE_FORMAT_2M16, "22.05 kHz, mono, 16-bit", 
		WAVE_FORMAT_2S08, "22.05 kHz, stereo, 8-bit", 
		WAVE_FORMAT_2S16, "22.05 kHz, stereo, 16-bit", 
		WAVE_FORMAT_4M08, "44.1 kHz, mono, 8-bit", 
		WAVE_FORMAT_4M16, "44.1 kHz, mono, 16-bit", 
		WAVE_FORMAT_4S08, "44.1 kHz, stereo, 8-bit", 
		WAVE_FORMAT_4S16, "44.1 kHz, stereo, 16-bit"
	};
	int fmt_list_size = sizeof(fmt_list)/sizeof(fmt_list[0]);

	unsigned int n = waveInGetNumDevs();
	DF1("waveInGetNumDevs returned %d", n);

	unsigned int i;
	int j;
	MMRESULT mmr;
	WAVEINCAPS wic;

	DF("CTelArPropertyPage3::ShowDevices()");
	
	((CComboBox *)GetDlgItem(IDC_DEVICE))->ResetContent();

	BOOL bSelectByDeviceName = FALSE;
	for (i = 0; i < n; i++)
	{
		mmr = waveInGetDevCaps(i, &wic, sizeof(wic));
		if (mmr != MMSYSERR_NOERROR) 
		{
			DF1("waveInGetDevCaps returned error code %d", (int)mmr);
			break;
		}
		((CComboBox *)GetDlgItem(IDC_DEVICE))->AddString(wic.szPname);

		// log some debug info....
		DF("");
		DF("List of audio input devices:");
		DF1("   Device ID   : %d", i);
		DF1("      Device name : %s", wic.szPname);
		for (j = 0; j < manufacturer_list_size; j ++) 
			if (manufacturer_list[j].id == wic.wMid)
				break;
		if (j < manufacturer_list_size)
			DF1("      Manufacturer: %s", manufacturer_list[j].name)
		else
			DF1("      Manufacturer: unknown (ID=%d)", (int)manufacturer_list[j].id)
		DF1("      Product ID  : %d", wic.wPid);
		DF4("      Driver vers.: %d.%d.%d.%d", wic.vDriverVersion>>24, wic.vDriverVersion&&0xff0000>>16, wic.vDriverVersion&&0xff00>>8, wic.vDriverVersion&&0xff);
		char buffer[2000];
		*buffer = '\0';
		for (j = 0; j < fmt_list_size; j ++) 
			if (fmt_list[j].fmt_id & wic.dwFormats)
			{
				if (*buffer) strcat(buffer, " + ");
				strcat(buffer, fmt_list[j].fmt_name);
			}
		
		DF1("      Sup. formats: %s", buffer);
		DF1("      No. channels: %d", (int)wic.wChannels);

		if (i == X_aufnahmegeraet)
		{
			if (!*X_aufnahmegeraetname)
				strcpy(X_aufnahmegeraetname, wic.szPname);
			else
			{
				// stored device name and actual one differ? maybe plug and play soundcards changed their index number...
				if (strcmp(X_aufnahmegeraetname, wic.szPname)) bSelectByDeviceName = TRUE;				
			}
		}
	}

	if (bSelectByDeviceName)
	{
		DF("Stored device name and actual one differ. Maybe plug and play soundcards changed their index number. Trying to select by Device Name...");

		for (i = 0; i < n; i++)
		{
			CString csDeviceName;
			((CComboBox *)GetDlgItem(IDC_DEVICE))->GetLBText(i, csDeviceName);
			if (!strcmp(X_aufnahmegeraetname, csDeviceName.GetBuffer(0)))
			{
				DF2("... successful! Changed device id from %d to %d.", X_aufnahmegeraet, i);				
				X_aufnahmegeraet = i;
				break;
			}
		}
		if (i >= n) 
		{
			DF1("... not successful! Still using device id %d. Maybe soundcard has been replaced.", X_aufnahmegeraet);
		}
	}
	
	DF("CTelArPropertyPage3::ShowDevices() -- exit");
}


void CTelArPropertyPage3::OnSelchangeAnschluss() 
{
	if (VISTA_RUNNING) return;
	DF("CTelArPropertyPage3::OnSelchangeAnschluss()");
	
	X_anschluss = ((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->GetCurSel();
	DF1("CTelArPropertyPage3::OnSelchangeAnschluss -- X_anschluss set to %d", X_anschluss);

	unsigned int i;
	MMRESULT mmr;
	MIXERLINE ml;
	MIXERLINECONTROLS mlc;
	MIXERCONTROL mc;
	MIXERCONTROLDETAILS mcd;
	MIXERCONTROLDETAILS_BOOLEAN *pmcd_b =NULL;
	MIXERCONTROLDETAILS_UNSIGNED mcd_u;
	UINT uMxId;

	if (X_nomixer) return;

	// eventuell gar kein Mixer device da?
	if (!mixerGetNumDevs()) { DF("CTelArPropertyPage3::OnSelchangeAnschluss !mixerGetNumDevs()"); return; }

	BOOL bOpen = FALSE;
	HWAVEIN hwi = WaveIn_GetDeviceHandle();
	if (!hwi)
	{	// wenn device handle noch nicht offen, dann extra öffnen!
		bOpen = WaveIn_Open(NULL, (unsigned int)X_aufnahmegeraet, 1, X_samplingrate, X_aufloesung, X_codec_id, X_format_wfx);
		if (!bOpen) { DF("CTelArPropertyPage3::OnSelchangeAnschluss !bOpen"); return; }
		hwi = WaveIn_GetDeviceHandle();
	}

	mmr = mixerGetID((HMIXEROBJ)hwi, &uMxId, MIXER_OBJECTF_HWAVEIN);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::OnSelchangeAnschluss() ret=%d", (int)mmr); goto exit_wavein_close; }

	// Wavein device ermitteln
	ml.dwDestination = 0;
	ml.dwSource = 0;
	ml.cbStruct = sizeof(ml); 
	mmr = mixerGetLineInfo((HMIXEROBJ)hwi, &ml, MIXER_OBJECTF_HWAVEIN);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::OnSelchangeAnschluss() mixerGetLineInfo(MIXER_OBJECTF_HWAVEIN) ret=%d", (int)mmr); goto exit_wavein_close; }

	// Line-Information holen
	ml.cbStruct = sizeof(ml);
	ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_WAVEIN;
	mmr = mixerGetLineInfo((HMIXEROBJ)uMxId, &ml, MIXER_GETLINEINFOF_COMPONENTTYPE);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::OnSelchangeAnschluss() mixerGetLineInfo(MIXER_GETLINEINFOF_COMPONENTTYPE) ret=%d", (int)mmr); goto exit_wavein_close; }
	if (ml.cControls)  // WaveIn-Line hat Controls?
	{
		// MUX-Control Information holen
		mlc.cbStruct = sizeof(mlc);
		mlc.dwLineID = ml.dwLineID;
		mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MUX;
		mlc.cControls = 1;
		mlc.cbmxctrl = sizeof(mc);
		mlc.pamxctrl = &mc;
		mmr = mixerGetLineControls((HMIXEROBJ)uMxId, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
		
		// wenn es kein MUX gibt, dann MIXER versuchen
		if (mmr == MIXERR_INVALCONTROL) 
		{
			DF("CTelArPropertyPage3::OnSelchangeAnschluss() - no MUX, trying MIXER"); 
			mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MIXER;
			mmr = mixerGetLineControls((HMIXEROBJ)uMxId, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
		}
		if (mmr != MMSYSERR_NOERROR) goto try_mute_switches;

		{
			// MUX-Control-Detailinformationen (aktuelle Aufnahmequelle) holen
			pmcd_b = new MIXERCONTROLDETAILS_BOOLEAN[mc.cMultipleItems];
			mcd.cbStruct = sizeof(mcd);
			mcd.dwControlID = mc.dwControlID;
			mcd.cChannels = 1;
			mcd.cMultipleItems = mc.cMultipleItems;
			mcd.cbDetails = sizeof(*pmcd_b);
			mcd.paDetails = pmcd_b;
			mmr = mixerGetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_GETCONTROLDETAILSF_VALUE);
			if (mmr != MMSYSERR_NOERROR) { DF("CTelArPropertyPage3::OnSelchangeAnschluss() - no MIXER nor MUX was found"); goto try_mute_switches; }

			// alle Werte zurücklsetzen
			for (i = 0; i < mc.cMultipleItems; i++)
			{					
				pmcd_b[i].fValue = 0;
			}
			pmcd_b[X_anschluss].fValue = 1;

			// aktuelle Aufnahmequelle ändern
			mmr = mixerSetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_SETCONTROLDETAILSF_VALUE);
			if (mmr != MMSYSERR_NOERROR) 
			{ 
				DF("CTelArPropertyPage3::OnSelchangeAnschluss() - no MUX nor MIXER, trying MUTE switches");
			}
			else
				goto exit_wavein_close;
		}
	}

try_mute_switches:
	{
		DF("CTelArPropertyPage3::OnSelchangeAnschluss() - WaveIn destination has no own mixer or mux control, looking for mute controls in source lines."); 
		MIXERLINE ml_source;

		// die sourcen für das Wavein device auflisten
		for (i = 0; i < ml.cConnections; i++)
		{	
			ml_source.dwSource = i;
			ml_source.dwDestination = ml.dwDestination;
			ml_source.cbStruct = sizeof(ml_source); 
			mmr = mixerGetLineInfo((HMIXEROBJ)uMxId, &ml_source, MIXER_GETLINEINFOF_SOURCE);
			if (mmr != MMSYSERR_NOERROR) { DF2("CTelArPropertyPage3::OnSelchangeAnschluss() mixerGetLineInfo() ml_source.dwSource=%d ret=%d", i, (int)mmr); goto exit_wavein_close; }
			
			// eigentlich hier den Mute-Schalter setzen, stürzt aber ständig ab
			// ...
			// 10.05.2003: ich probiere es nochmal 
			if (ml_source.cControls)
			{
				// MUTE-Control Information holen
				mlc.cbStruct = sizeof(mlc);
				mlc.dwLineID = ml_source.dwLineID;
				mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MUTE;
				mlc.cControls = 1;
				mlc.cbmxctrl = sizeof(mc);
				mlc.pamxctrl = &mc;
				mmr = mixerGetLineControls((HMIXEROBJ)uMxId, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
				if (mmr != MMSYSERR_NOERROR) { DF2("CTelArPropertyPage3::OnSelchangeAnschluss() - mixerGetLineControls() no mute switch! ml_source.dwSource=%d ret=%d", i, (int)mmr); goto exit_wavein_close; }
	
				// MUTE-Control-Detailinformationen (aktuelle Aufnahmequelle) holen
				mcd.cbStruct = sizeof(mcd);
				mcd.dwControlID = mc.dwControlID;
				mcd.cChannels = 1;
				mcd.cMultipleItems = 0;
				mcd.cbDetails = sizeof(mcd_u);
				mcd.paDetails = &mcd_u;
				mcd_u.dwValue = !((unsigned)X_anschluss == i);	// alles außer aktuellem Anschluss auf 'mute'
				mmr = mixerSetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_GETCONTROLDETAILSF_VALUE);
				if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage1::OnSelchangeAnschluss - mixerSetControlDetails(MIXER_GETCONTROLDETAILSF_VALUE) ret %d", (int)mmr); goto exit_wavein_close; }
			}
			else
				DF1("CTelArPropertyPage3::ShowAux() source line #%i has no control", i);	
		}
	}

exit_wavein_close:

	if (pmcd_b) delete pmcd_b;
	if (bOpen) WaveIn_Close();

	DF("CTelArPropertyPage3::OnSelchangeAnschluss() -- exit");
}


void CTelArPropertyPage3::ShowAux()
{
	if (VISTA_RUNNING) return;
	unsigned int i;
	MMRESULT mmr;
	MIXERLINE ml;
	MIXERLINECONTROLS mlc;
	MIXERCONTROL mc;
	MIXERCONTROLDETAILS mcd;
	MIXERCONTROLDETAILS_LISTTEXT *pmcd_lt =NULL;
	MIXERCONTROLDETAILS_BOOLEAN *pmcd_b =NULL;
	MIXERCONTROLDETAILS_UNSIGNED mcd_u;
	UINT uMxId;

	DF("CTelArPropertyPage3::ShowAux()");
	
	((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->ResetContent();

	if (X_nomixer) return;

	// eventuell gar kein Mixer device da?
	int nMixerDevs = 0;
	if (!(nMixerDevs = mixerGetNumDevs())) { DF("CTelArPropertyPage3::ShowAux !mixerGetNumDevs()"); return; }

	BOOL bOpen = WaveIn_Open(NULL, (unsigned int)X_aufnahmegeraet, 1, X_samplingrate, X_aufloesung, X_codec_id, X_format_wfx);
	if (!bOpen) { DF("CTelArPropertyPage3::ShowAux !bOpen"); return; }

	HWAVEIN hwi = WaveIn_GetDeviceHandle();

	mmr = mixerGetID((HMIXEROBJ)hwi, &uMxId, MIXER_OBJECTF_HWAVEIN);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::ShowAux() ret=%d", (int)mmr); goto exit_wavein_close; }
	// mmr = mixerGetDevCaps(uMxId, &mcaps, sizeof(mcaps));
	// if (mmr != MMSYSERR_NOERROR) goto exit_wavein_close;

	// Wavein device ermitteln
	ml.dwDestination = 0;
	ml.dwSource = 0;
	ml.cbStruct = sizeof(ml); 
	mmr = mixerGetLineInfo((HMIXEROBJ)hwi, &ml, MIXER_OBJECTF_HWAVEIN);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::ShowAux() mixerGetLineInfo(MIXER_OBJECTF_HWAVEIN) ret=%d", (int)mmr); goto exit_wavein_close; }

	// Line-Information holen
	ml.cbStruct = sizeof(ml);
	ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_WAVEIN;
	mmr = mixerGetLineInfo((HMIXEROBJ)uMxId, &ml, MIXER_GETLINEINFOF_COMPONENTTYPE);
	if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::ShowAux() mixerGetLineInfo(MIXER_OBJECTF_HWAVEIN) ret=%d", (int)mmr); goto exit_wavein_close; }
	if (ml.cControls) // WaveIn-Line hat Controls? 
	{	
		// MUX-Control Information holen
		mlc.cbStruct = sizeof(mlc);
		mlc.dwLineID = ml.dwLineID;
		mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MUX;
		mlc.cControls = 1;
		mlc.cbmxctrl = sizeof(mc);
		mlc.pamxctrl = &mc;
		mmr = mixerGetLineControls((HMIXEROBJ)uMxId, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
		
		// wenn es kein MUX gibt, dann MIXER versuchen
		if (mmr == MIXERR_INVALCONTROL) 
		{
			DF("CTelArPropertyPage3::ShowAux() - no MUX, trying MIXER"); 
			mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MIXER;
			mmr = mixerGetLineControls((HMIXEROBJ)uMxId, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
		}
		if (mmr != MMSYSERR_NOERROR) goto try_mute_switches;
		
		// MUX-Control-Detailinformationen (Anschlussnamen) über die einzelnen Aufnahmequellen holen
		pmcd_lt = new MIXERCONTROLDETAILS_LISTTEXT[mc.cMultipleItems];
		mcd.cbStruct = sizeof(mcd);
		mcd.dwControlID = mc.dwControlID;
		mcd.cChannels = 1;
		mcd.cMultipleItems = mc.cMultipleItems;
		mcd.cbDetails = sizeof(*pmcd_lt);
		mcd.paDetails = pmcd_lt;
		mmr = mixerGetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_GETCONTROLDETAILSF_LISTTEXT);
		if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::ShowAux() mixerGetControlDetails(MIXER_GETCONTROLDETAILSF_LISTTEXT) ret=%d", (int)mmr); goto exit_wavein_close; }

		// MUX-Control-Detailinformationen (aktuelle Aufnahmequelle) holen
		pmcd_b = new MIXERCONTROLDETAILS_BOOLEAN[mc.cMultipleItems];
		mcd.cbStruct = sizeof(mcd);				// ein Genius-Soundcard Treiber
		mcd.dwControlID = mc.dwControlID;		// verändert diese, deshalb
		mcd.cChannels = 1;						// müssen die members neu gesetzt 
		mcd.cMultipleItems = mc.cMultipleItems;	// werden.
		mcd.cbDetails = sizeof(*pmcd_b);
		mcd.paDetails = pmcd_b;
		mmr = mixerGetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_GETCONTROLDETAILSF_VALUE);
		if (mmr != MMSYSERR_NOERROR) { DF1("CTelArPropertyPage3::ShowAux() mixerGetControlDetails(MIXER_GETCONTROLDETAILSF_VALUE) ret=%d", (int)mmr); goto exit_wavein_close; }

		// die sourcen für das Wavein device auflisten
		for (i = 0; i < mc.cMultipleItems; i++)
		{		
					
			((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->AddString(pmcd_lt[i].szName);

			if (pmcd_b[i].fValue)
			{
				X_anschluss = i;
				DF1("CTelArPropertyPage3::ShowAux() -- X_anschluss set to %d", X_anschluss);
				((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetCurSel(X_anschluss);
			}
		}

		// map MUX or MIXER Line to Source Line in DlgItemData of Combo box
		BOOL bFirstLoop = TRUE;
		for (i = 0; i < ml.cConnections; i++)
		{
			MIXERLINE ml_source;

			char mx_name_buffer[MIXER_LONG_NAME_CHARS+1000];
			((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->GetLBText(i, mx_name_buffer);

			int map_to = -1;
			char map_to_name[MIXER_LONG_NAME_CHARS+1000];
			*map_to_name = '\0';
			unsigned int j;
			for (j = 0; j < ml.cConnections; j++)
			{
				ml_source.dwSource = j;
				ml_source.dwDestination = ml.dwDestination;
				ml_source.cbStruct = sizeof(ml_source); 
				mmr = mixerGetLineInfo((HMIXEROBJ)uMxId, &ml_source, MIXER_GETLINEINFOF_SOURCE);
				if (mmr != MMSYSERR_NOERROR) { DF2("CTelArPropertyPage3::ShowAux() 2nd mixerGetLineInfo() ml_source.dwSource=%d ret=%d", i, (int)mmr); goto exit_wavein_close; }
				if (!strcmp(ml_source.szName, mx_name_buffer))
				{
					map_to = j;
					strcpy(map_to_name, ml_source.szName);
				}
				if (bFirstLoop) { DF2("Source line #%d: %s", j, ml_source.szName); } // Log list of source lines in first loop
			}
			bFirstLoop = FALSE;
			if (map_to >= 0)
			{
				((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetItemData(i, (DWORD)map_to);
				DF3("MIXER control %d mapped to source line %d (%s)", i, map_to, map_to_name); 
			}
			else
			{ 
				((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetItemData(i, (DWORD)-1);
				DF1("No according source line for MIXER control %s!!!", mx_name_buffer); 
			}
		}

		goto exit_wavein_close;
	}
	
	// WaveIn-Line hat keine eigenen Controls und weder MIXER noch MUX gefunden? Dann hoffen, dass die einzelnen Sources Mute-Switches haben
try_mute_switches:	
	{
		DF("CTelArPropertyPage3::ShowAux() - WaveIn destination has no own mixer controls, looking for mute controls in source lines."); 
		MIXERLINE ml_source;

		// die sourcen für das Wavein device auflisten
		for (i = 0; i < ml.cConnections; i++)
		{	
			ml_source.dwSource = i;
			ml_source.dwDestination = ml.dwDestination;
			ml_source.cbStruct = sizeof(ml_source); 
			mmr = mixerGetLineInfo((HMIXEROBJ)uMxId, &ml_source, MIXER_GETLINEINFOF_SOURCE);
			if (mmr != MMSYSERR_NOERROR) { DF2("CTelArPropertyPage3::ShowAux() mixerGetLineInfo() ml_source.dwSource=%d ret=%d", i, (int)mmr); goto exit_wavein_close; }
			
			// eigentlich hier den Mute-Schalter setzen, stürzt aber ständig ab
			// ...
			// 10.05.2003: ich probiere es nochmal 
			if (ml_source.cControls)
			{
				// MUTE-Control Information holen
				mlc.cbStruct = sizeof(mlc);
				mlc.dwLineID = ml_source.dwLineID;
				mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MUTE;
				mlc.cControls = 1;
				mlc.cbmxctrl = sizeof(mc);
				mlc.pamxctrl = &mc;
				mmr = mixerGetLineControls((HMIXEROBJ)uMxId, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
				if (mmr != MMSYSERR_NOERROR) { DF2("CTelArPropertyPage3::ShowAux() - mixerGetLineControls() no mute switch! ml_source.dwSource=%d ret=%d", i, (int)mmr); goto exit_wavein_close; }
	
				// MUTE-Control-Detailinformationen (aktuelle Aufnahmequelle) holen
				mcd.cbStruct = sizeof(mcd);
				mcd.dwControlID = mc.dwControlID;
				mcd.cChannels = 1;
				mcd.cMultipleItems = 0;
				mcd.cbDetails = sizeof(mcd_u);
				mcd.paDetails = &mcd_u;
				mcd_u.dwValue = !((unsigned)X_anschluss == i);	// alles außer aktuellem Anschluss auf 'mute'
				mmr = mixerSetControlDetails((HMIXEROBJ)uMxId, &mcd, MIXER_GETCONTROLDETAILSF_VALUE);
				if (mmr != MMSYSERR_NOERROR) 
				{ 
					DF1("CTelArPropertyPage1::ShowAux - mixerSetControlDetails(MIXER_GETCONTROLDETAILSF_VALUE) (MUTE-Control) ret %d", (int)mmr); goto exit_wavein_close;
				}
				else
				{
					DF2("CTelArPropertyPage1::ShowAux() Using MUTE-Control for line #%d (%s)", i, ml_source.szName);
				}
			}
			else
				DF1("CTelArPropertyPage3::ShowAux() source line #%i has no control", i);

			((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->AddString(ml_source.szName);	
			((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetItemData(i, (DWORD)-1);	// don't map!
		}
	}

	if (X_anschluss == -1)
	{
		X_anschluss = 0;				
		DF1("CTelArPropertyPage3::ShowAux() -- X_anschluss set from -1 to %d", X_anschluss);
		((CComboBox *)GetDlgItem(IDC_ANSCHLUSS))->SetCurSel(X_anschluss);
	}

exit_wavein_close:

	if (pmcd_lt) delete pmcd_lt;
	if (pmcd_b) delete pmcd_b;
	WaveIn_Close();
	DF("CTelArPropertyPage3::ShowAux() -- exit");
}


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage4 property page */

CTelArPropertyPage4::CTelArPropertyPage4() : CResizablePage(CTelArPropertyPage4::IDD)
{
	//{{AFX_DATA_INIT(CTelArPropertyPage4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_InitDlg = FALSE;
}

CTelArPropertyPage4::~CTelArPropertyPage4()
{
}

void CTelArPropertyPage4::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTelArPropertyPage4)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTelArPropertyPage4, CResizablePage)
	//{{AFX_MSG_MAP(CTelArPropertyPage4)
	ON_WM_DESTROY()
	ON_LBN_SELCHANGE(IDC_LISTE, OnSelchangeListe)
	ON_LBN_SELCHANGE(IDC_LISTE_FORMAT, OnSelchangeListeFormat)
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()


BOOL CTelArPropertyPage4::OnInitDialog() 
{
	TRACE0("CTelArPropertyPage4::OnInitDialog()\n");
	CResizablePage::OnInitDialog();

	// preset layout
	AddAnchor(IDC_CODEC_STATIC, TOP_LEFT, TOP_CENTER);		
	AddAnchor(IDC_LISTE, TOP_LEFT, BOTTOM_CENTER);	
	AddAnchor(IDC_FORMAT_STATIC, TOP_CENTER, TOP_RIGHT);
	AddAnchor(IDC_LISTE_FORMAT, TOP_CENTER, BOTTOM_RIGHT);	
	AddAnchor(IDC_NAME_STATIC, BOTTOM_LEFT);		
	AddAnchor(IDC_NAME, BOTTOM_LEFT, BOTTOM_RIGHT);	
	AddAnchor(IDC_FEATURES_STATIC, BOTTOM_LEFT);
	AddAnchor(IDC_FEATURES, BOTTOM_LEFT, BOTTOM_RIGHT);	
	AddAnchor(IDC_VENDOR_LOGO_FRAME, BOTTOM_RIGHT);	

	m_InitDlg = TRUE;

	DWORD_PTR X_format_save = X_format;
	
	ShowCodecs();

	((CListBox *)GetDlgItem(IDC_LISTE))->SetCurSel(0);

	for (int i = 0; i < ((CListBox *)GetDlgItem(IDC_LISTE))->GetCount(); i++)
	{
		char codec_name[1000];
		if (((CListBox *)GetDlgItem(IDC_LISTE))->GetText(i, codec_name) != LB_ERR)
			if (!strcmp(codec_name, X_codec))
			{
				((CListBox *)GetDlgItem(IDC_LISTE))->SetCurSel(i);
				X_codec_id = (DWORD)((CListBox *)GetDlgItem(IDC_LISTE))->GetItemData(i);
			}
	}
	OnSelchangeListe();

	((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->SetCurSel((int)X_format_save);
	OnSelchangeListeFormat();

/*	if ((long)X_codec == -1)
		((CListBox *)GetDlgItem(IDC_LISTE))->SetCurSel(0);
	else
	{
		((CListBox *)GetDlgItem(IDC_LISTE))->SetCurSel(X_codec);
		OnSelchangeListe();
	}
*/
	m_InitDlg = FALSE;

	return TRUE;
}

void CTelArPropertyPage4::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	CRect r;
	GetClientRect(&r);
	InvalidateRect(r);
}

// Hintergrundbitmap malen
BOOL CTelArPropertyPage4::OnEraseBkgnd( CDC* pDC )
{
	CResizablePage::OnEraseBkgnd(pDC);

	char buffer[200];
	VEND2BUFFER(IDS_STRING1, buffer);

	CRect r, fr;

	if (!strcmp(buffer, "PhoneCoach CompuCorder"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_PHONECOACH_ON_GREY, &fr, 0);
	}
	else if (!strcmp(buffer, "Actimax"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_ACTIMAX_ON_GREY, &fr, 0);
	}
	else
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_RETELL_ON_GREY, &fr, 0);
	}
	return TRUE;
}

void CTelArPropertyPage4::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	RECT pr, cr;

	GetWindowRect(&pr);

	char buffer[50];
	int nOldBkMode = dc.SetBkMode(TRANSPARENT);
	GetDlgItem(IDC_CODEC_STATIC)->GetWindowRect(&cr);

	CFont *standardFont = dc.GetCurrentFont();
	LOGFONT FontStats;
	standardFont->GetLogFont(&FontStats);
	strcpy(FontStats.lfFaceName, "MS Sans Serif"); 
	FontStats.lfHeight  = cr.bottom-cr.top;
	FontStats.lfWidth   = 0;	// Breite relativ zur Höhe verkleinern
	FontStats.lfQuality = DEFAULT_QUALITY;
	FontStats.lfWeight	= 700;	// default weight
	CFont neuerFont;	// Font kreiren
	neuerFont.CreateFontIndirect(&FontStats);
	CFont *oldFont = dc.SelectObject(&neuerFont);	// in den device context damit
	
	// Statics füllen
	// Gesprächspartner
	LANG2BUFFER(IDS_STRING79, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_FORMAT_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING80, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_NAME_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING137, buffer);
	strcpy(buffer, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_FEATURES_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING138, buffer);
	strcpy(buffer, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));

  // alten Font und BG-Mode restaurieren
	dc.SelectObject(oldFont);
	dc.SetBkMode(nOldBkMode);
}

void CTelArPropertyPage4::OnDestroy() 
{
	RemoveAllAnchors();

	CResizablePage::OnDestroy();
	
	ClearFormatLB();
}


void CTelArPropertyPage4::OnSelchangeListeFormat() 
{
	X_format = ((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetCurSel();
	X_format_wfx = ((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetItemData(X_format);
}


void CTelArPropertyPage4::GetData()
{
}


void show_error(MMRESULT mmr)
{
	char buffer[256];

	switch (mmr) {
	case ACMERR_NOTPOSSIBLE:
		AfxMessageBox("CODEC: The index specified in uMetric cannot be returned for the specified hao");
		break;
	case MMSYSERR_INVALHANDLE:
		AfxMessageBox("CODEC: The specified handle is invalid");
		break;
	case MMSYSERR_INVALPARAM:
		AfxMessageBox("CODEC: At least one parameter is invalid");
		break;
	case MMSYSERR_NOTSUPPORTED:
		AfxMessageBox("CODEC: The index specified in uMetric is not supported");
		break;
	default:
		sprintf(buffer, "CODEC: unknown Error %8.8xH", mmr);
		AfxMessageBox(buffer);
		break;
	}
}



BOOL CALLBACK FormatEnumProc(HACMDRIVERID hadid, LPACMFORMATDETAILS pafd, DWORD_PTR dwInstance, DWORD fdwSupport)
{

	if (pafd->dwFormatTag != WAVE_FORMAT_PCM)
	{
		DWORD_PTR dw;
		WAVEFORMATEX* p_wfx;

		listbox_format->AddString(pafd->szFormat);

		// LitboxItem evtl. löschen
		if (dw = listbox_format->GetItemData(listbox_format->GetCount()-1))
			free((WAVEFORMATEX*)dw);
		listbox_format->SetItemData(listbox_format->GetCount()-1, 0L);

		// neues LB-Item
		if (p_wfx = (WAVEFORMATEX*)malloc(sizeof(*p_wfx) + pafd->pwfx->cbSize))
		{
			memcpy(p_wfx, pafd->pwfx, sizeof(*p_wfx) + pafd->pwfx->cbSize);
			listbox_format->SetItemData(listbox_format->GetCount()-1, (DWORD_PTR)p_wfx);
		}
	}

	return TRUE; // continue enumerating
}

BOOL CALLBACK DriverEnumProc(HACMDRIVERID hadid, DWORD_PTR dwInstance, DWORD fdwSupport)
{
	//if (fdwSupport & ACMDRIVERDETAILS_SUPPORTF_CODEC) 
	//{
		// get some details
		ACMDRIVERDETAILS dd;
		dd.cbStruct = sizeof(dd);
		MMRESULT mmr = acmDriverDetails(hadid, &dd, 0);
		if (mmr) {
			//show_error(mmr);
#ifdef _DEBUG
			char buffer[256];
			switch (mmr) 
			{
			case ACMERR_NOTPOSSIBLE:
				sprintf(buffer, "CODEC ID %8.8xH: The index specified in uMetric cannot be returned for the specified hao", hadid);
				break;
			case MMSYSERR_INVALHANDLE:
				sprintf(buffer, "CODEC ID %8.8xH: The specified handle is invalid", hadid);
				break;
			case MMSYSERR_INVALPARAM:
				sprintf(buffer, "CODEC ID %8.8xH: At least one parameter is invalid", hadid);
				break;
			case MMSYSERR_NOTSUPPORTED:
				sprintf(buffer, "CODEC ID %8.8xH: The index specified in uMetric is not supported", hadid);
				break;
			default:
				sprintf(buffer, "CODEC ID %8.8xH: unknown Error %8.8xH", hadid, mmr);
				break;
			}
			TRACE1("%s\n", buffer);
#endif
		} else {/*
			printf("   Short name: %s\n", dd.szShortName);
			printf("   Long name:  %s\n", dd.szLongName);
			printf("   Copyright:  %s\n", dd.szCopyright);
			printf("   Licensing:  %s\n", dd.szLicensing);
			printf("   Features:   %s\n", dd.szFeatures);
			printf("   Supports %u formats\n", dd.cFormatTags);
			printf("   Supports %u filter formats\n", dd.cFilterTags);
			*/
			if (strcmp(dd.szShortName, "MS-PCM"))
			{
				listbox->AddString(dd.szShortName);
				listbox->SetItemData(listbox->GetCount()-1, (DWORD_PTR)hadid);
				if ((DWORD_PTR)X_codec == (DWORD_PTR)hadid) listbox->SetCurSel(listbox->GetCount()-1);
			}
		}
	//}
	return TRUE; // continue enumeration
}


void CTelArPropertyPage4::OnSelchangeListe() 
{
	int n = ((CListBox *)GetDlgItem(IDC_LISTE))->GetCurSel();
	if (n == -1) return;
	ClearFormatLB();
	((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->ResetContent();
	DWORD_PTR dw = ((CListBox *)GetDlgItem(IDC_LISTE))->GetItemData(n);
	X_codec_id = dw;
	((CListBox *)GetDlgItem(IDC_LISTE))->GetText(n, X_codec);
	if ((long)dw == -1)
	{
		return;
	}

	HACMDRIVERID hadid = (HACMDRIVERID)dw;
	listbox_format = (CListBox *)GetDlgItem(IDC_LISTE_FORMAT);

	// open the driver
	HACMDRIVER had = NULL;
	MMRESULT mmr = acmDriverOpen(&had, hadid, 0);
	if (mmr) {
		show_error(mmr);
	} else {
		DWORD dwSize = 0;
		mmr = acmMetrics((HACMOBJ)had, ACM_METRIC_MAX_SIZE_FORMAT, &dwSize);
		if (dwSize < sizeof(WAVEFORMATEX)) dwSize = sizeof(WAVEFORMATEX); // for MS-PCM
		WAVEFORMATEX* pwf = (WAVEFORMATEX*) malloc(dwSize);
		memset(pwf, 0, dwSize);
		pwf->cbSize = LOWORD(dwSize) - sizeof(WAVEFORMATEX);
		pwf->wFormatTag = WAVE_FORMAT_UNKNOWN;
		ACMFORMATDETAILS fd;
		memset(&fd, 0, sizeof(fd));
		fd.cbStruct = sizeof(fd);
		fd.pwfx = pwf;
		fd.cbwfx = dwSize;
		fd.dwFormatTag = WAVE_FORMAT_UNKNOWN;
		mmr = acmFormatEnum(had, &fd, FormatEnumProc, 0, 0);  
		if (mmr) {
			show_error(mmr);
		}
		free(pwf);

		acmDriverClose(had, 0);
	}
	
	ACMDRIVERDETAILS dd;
	dd.cbStruct = sizeof(dd);
	if (!acmDriverDetails(hadid, &dd, 0))
	{
		SetDlgItemText(IDC_NAME, dd.szLongName);
		SetDlgItemText(IDC_FEATURES, dd.szFeatures);
	}

	if (!m_InitDlg) SetTimer(111, 50, NULL);
}

void CTelArPropertyPage4::ShowCodecs()
{
	//char buffer[256];
	MMRESULT mmr;

	listbox = (CListBox *)GetDlgItem(IDC_LISTE);
	((CListBox *)GetDlgItem(IDC_LISTE))->ResetContent();

	listbox_format = (CListBox *)GetDlgItem(IDC_LISTE_FORMAT);
	ClearFormatLB();
	((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->ResetContent();

	// speichern in dem format, wie aufgenommen wurde
	char tmpbuf[50];
	LANG2BUFFER(IDS_STRING22, tmpbuf); // "<MS-PCM ohne CODEC>"
	listbox->AddString(tmpbuf);
	listbox->SetItemData(listbox->GetCount()-1, (DWORD)-1L);

	//if (X_codec_id == -1) ((CListBox *)GetDlgItem(IDC_LISTE))->SetCurSel(0);

	mmr = acmDriverEnum(DriverEnumProc, 0, 0); 
	if (mmr) show_error(mmr);
}

void CTelArPropertyPage4::ClearFormatLB()
{
	DWORD_PTR dw;
	int i;
	int n = ((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetCount();

	// ListboxItems löschen
	for (i = 0; i < n; i++)
	if (dw = ((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetItemData(i))
	{
		free((WAVEFORMATEX*)dw);
		((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->SetItemData(i, 0L);
	}
}

#define HZ_SYN_MAX 9
static int hz_syn_int[HZ_SYN_MAX] = {
	48000,
	44100,
	32075,
	32000,
	22050,
	16000,
	11025,
	8000,
	6000
};
static char *hz_syn_string[HZ_SYN_MAX][4] = {
	"48.000 Hz",	"48 kHz",	"48kHz",	"48,000 Hz",	
	"44.100 Hz",	"44 kHz",	"44kHz",	"44,100 Hz",	
	"32.075 Hz",	"32 kHz",	"32kHz",	"32,075 Hz",	
	"32.000 Hz",	"32 kHz",	"32kHz",	"32,000 Hz",	
	"22.050 Hz",	"22 kHz",	"22kHz",	"22,050 Hz",	
	"16.000 Hz",	"16 kHz",	"16kHz",	"16,000 Hz",	
	"11.025 Hz",	"11 kHz",	"11kHz",	"11,025 Hz",	
	"8.000 Hz",		"8 kHz",	"8kHz",		"8,000 Hz",		
	"6.000 Hz",		"6 kHz",	"6kHz",		"6,000 Hz"		
};


void CTelArPropertyPage4::OnTimer(UINT_PTR  nIDEvent) 
{

	if (nIDEvent == 111)
	{
		int sel = 0;

		if (::IsWindow(((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->m_hWnd))
		{
			TRACE0("CTelArPropertyPage4::OnTimer\n");
			KillTimer(111);

			//Element in Synonym-Tabelle suchen
			int syn;
			for (syn = 0; syn < HZ_SYN_MAX; syn++)
				if (hz_syn_int[syn] == X_samplingrate) break;
			if (syn < HZ_SYN_MAX)
			{
				//Passendes Sub-Format für CODEC finden
				int n = ((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetCount();
				int i;
				CString cs;
				int nFoundFreqAndMono = -1;
				int nFoundFreq = -1;
				for (i = 0; i < n; i++)
				{
					((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetText(i, cs);
					char *cp = cs.GetBuffer(0);

					if ((strstr(cp, hz_syn_string[syn][0]) 
						|| strstr(cp, hz_syn_string[syn][1]) 
						|| strstr(cp, hz_syn_string[syn][2]) 
						|| strstr(cp, hz_syn_string[syn][3]))
						&& !(X_samplingrate == 8000 && strstr(cp, "48"))) 
					{
						if (nFoundFreq == -1) nFoundFreq = i;

						if (strstr(cp, "mono") || strstr(cp, "Mono"))
							if (nFoundFreqAndMono == -1) nFoundFreqAndMono = i;
					}
				}

				if (nFoundFreqAndMono != -1)
					sel = nFoundFreqAndMono;
				else
					if (nFoundFreq != -1)
						sel = nFoundFreq;
			}

			((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->SetCurSel(sel);
			GetDlgItem(IDC_LISTE_FORMAT)->SetFocus();
			OnSelchangeListeFormat();
		}
	}
	
	CResizablePage::OnTimer(nIDEvent);
}






/*
		int x;
		DWORD codec;
		x = ((CListBox *)GetDlgItem(IDC_LISTE))->GetCurSel();
		if (x == -1)
		{
			AfxMessageBox("Bitte CODEC auswählen!");
			Normalisieren();
			GetDlgItem(IDC_LISTE)->SetFocus();
			return;
		}
		codec = ((CListBox *)GetDlgItem(IDC_LISTE))->GetItemData(x);
		
		DWORD format;
		if ((long)codec != -1)
		{
			x = ((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetCurSel();
			if (x == -1)
			{
				AfxMessageBox("Bitte Speicherformat auswählen!");
				Normalisieren();
				GetDlgItem(IDC_LISTE_FORMAT)->SetFocus();
				return;
			}
			format = ((CListBox *)GetDlgItem(IDC_LISTE_FORMAT))->GetItemData(x);
		}

*/


/////////////////////////////////////////////////////////////////////////////
// CTelArPropertyPage5 property page

CTelArPropertyPage5::CTelArPropertyPage5() : CResizablePage(CTelArPropertyPage5::IDD)
{
	TRACE0("CTelArPropertyPage5::CTelArPropertyPage5()\n");
	//{{AFX_DATA_INIT(CTelArPropertyPage5)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	static char buffer[50];
	LANG2BUFFER(IDS_STRING87, buffer);
	m_psp.pszTitle = buffer;
	m_psp.dwFlags |= PSP_USETITLE;
}

CTelArPropertyPage5::~CTelArPropertyPage5()
{
}

void CTelArPropertyPage5::DoDataExchange(CDataExchange* pDX)
{
	CResizablePage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTelArPropertyPage5)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTelArPropertyPage5, CResizablePage)
	//{{AFX_MSG_MAP(CTelArPropertyPage5)
	ON_BN_CLICKED(IDC_SET_ROOT_PATH, OnSetRootPath)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SET_MAINARCHIVE, OnSetMainarchive)
	ON_BN_CLICKED(IDC_AUTOSTART, OnAutostart)
	ON_BN_CLICKED(IDC_CONNECT_TO_SQL_SERVER, OnConnectToSqlServer)
	ON_WM_HSCROLL()
	ON_NOTIFY(UDN_DELTAPOS, IDC_VERGROESSERN_BEI_PEGEL_SPIN, OnDeltaposSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_START_SPIN, OnDeltaposSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_STOP_SPIN, OnDeltaposSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_NICHTBEACHTUNG_SPIN, OnDeltaposSpin)
	ON_EN_CHANGE(IDC_PASSWORT, OnChangePasswort)
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_CONNECT_TO_SENSE, &CTelArPropertyPage5::OnConnectToSense)
	ON_WM_SIZE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CTelArPropertyPage5::OnInitDialog() 
{
	TRACE0("CTelArPropertyPage5::OnInitDialog()\n");
	CResizablePage::OnInitDialog();

	// preset layout
	AddAnchor(IDC_DEFAULT_STATIC, TOP_LEFT);	
	AddAnchor(IDC_DEFAULT, TOP_LEFT, TOP_RIGHT);	
	AddAnchor(IDC_SET_ROOT_PATH, TOP_RIGHT);	
	AddAnchor(IDC_CONNECT_TO_SQL_SERVER, TOP_RIGHT);	
	AddAnchor(IDC_CONNECT_TO_SENSE, TOP_RIGHT);	
	AddAnchor(IDC_LOESCHEN1_STATIC, TOP_LEFT);	
	AddAnchor(IDC_LOESCHEN, TOP_RIGHT);	
	AddAnchor(IDC_LOESCHEN2_STATIC, TOP_RIGHT);	
	AddAnchor(IDC_MAINARCHIVE_STATIC, TOP_LEFT);	
	AddAnchor(IDC_MAINARCHIVE, TOP_LEFT, TOP_RIGHT);	
	AddAnchor(IDC_SET_MAINARCHIVE, TOP_RIGHT);	
	AddAnchor(IDC_INITIALEN_STATIC, TOP_LEFT);	
	AddAnchor(IDC_INITIALEN, TOP_LEFT);	
	AddAnchor(IDC_AUTOSTART_STATIC_LONG, TOP_RIGHT);
	AddAnchor(IDC_AUTOSTART_STATIC, TOP_RIGHT);	
	AddAnchor(IDC_AUTOSTART, TOP_RIGHT);	
	AddAnchor(IDC_PASSWORT_STATIC, TOP_LEFT);	
	AddAnchor(IDC_PASSWORT, TOP_LEFT);	
	AddAnchor(IDC_MASTERPASSWORT_STATIC, TOP_CENTER);	
	AddAnchor(IDC_MASTERPASSWORT, TOP_CENTER);	
	AddAnchor(IDC_PASSES_STATIC, TOP_RIGHT);	
	AddAnchor(IDC_PASSES, TOP_RIGHT);	
	AddAnchor(IDC_AUFNAHME_AUTOMATIK_STATIC, TOP_LEFT);
	AddAnchor(IDC_ALC_STATIC, TOP_LEFT);
	AddAnchor(IDC_ALC, TOP_RIGHT);
	AddAnchor(IDC_EMPFINDLICHKEIT_STATIC, TOP_LEFT);
	AddAnchor(IDC_EMPFINDLICHKEIT_ANZEIGE, TOP_RIGHT);
	AddAnchor(IDC_EMPFINDLICHKEIT_SLIDER, TOP_RIGHT);
	AddAnchor(IDC_START_STATIC, TOP_LEFT);
	AddAnchor(IDC_START, TOP_RIGHT);
	AddAnchor(IDC_START_SPIN, TOP_RIGHT);
	AddAnchor(IDC_STOP_STATIC, TOP_LEFT);
	AddAnchor(IDC_STOP, TOP_RIGHT);
	AddAnchor(IDC_STOP_SPIN, TOP_RIGHT);
	AddAnchor(IDC_VERGROESSERN_BEI_PEGEL_STATIC, TOP_LEFT);
	AddAnchor(IDC_VERGROESSERN_BEI_PEGEL, TOP_RIGHT);
	AddAnchor(IDC_VERGROESSERN_BEI_PEGEL_SPIN, TOP_RIGHT);
	AddAnchor(IDC_MINIMIZE_AFTER_STATIC, TOP_LEFT);
	AddAnchor(IDC_MINIMIZE_AFTER, TOP_RIGHT);
	AddAnchor(IDC_NICHTBEACHTUNG_STATIC, TOP_LEFT);
	AddAnchor(IDC_NICHTBEACHTUNG, TOP_RIGHT);
	AddAnchor(IDC_NICHTBEACHTUNG_SPIN, TOP_RIGHT);
	AddAnchor(IDC_ADVERTISING, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_VENDOR_LOGO_FRAME, BOTTOM_RIGHT);	
	AddAnchor(IDC_SENSE_EXTENSION_STATIC, TOP_LEFT);
	AddAnchor(IDC_SENSE_EXTENSION, TOP_RIGHT);	

	char buffer[1000];
	LANG2BUFFER(IDS_STRING173, buffer);
	GetDlgItem(IDC_CONNECT_TO_SQL_SERVER)->SetWindowText(buffer);
	LANG2BUFFER(IDS_STRING182, buffer);
	GetDlgItem(IDC_CONNECT_TO_SENSE)->SetWindowText(buffer);
	
	((CEdit *)GetDlgItem(IDC_INITIALEN))->LimitText(2);
	((CEdit *)GetDlgItem(IDC_EMPFINDLICHKEIT))->LimitText(3);
	((CEdit *)GetDlgItem(IDC_START))->LimitText(3);
	((CEdit *)GetDlgItem(IDC_STOP))->LimitText(3);

	EnableVoxOptions(!X_intelligent);

	return TRUE;
}

void CTelArPropertyPage5::OnSize(UINT nType, int cx, int cy)
{
	CResizablePage::OnSize(nType, cx, cy);

	CRect r;
	GetClientRect(&r);
	InvalidateRect(r);
}

// Hintergrundbitmap malen
BOOL CTelArPropertyPage5::OnEraseBkgnd( CDC* pDC )
{
	CResizablePage::OnEraseBkgnd(pDC);

	char buffer[200];
	VEND2BUFFER(IDS_STRING1, buffer);

	CRect r, fr;

	if (!strcmp(buffer, "PhoneCoach CompuCorder"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_PHONECOACH_ON_GREY, &fr, 0);
	}
	else if (!strcmp(buffer, "Actimax"))
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_ACTIMAX_ON_GREY, &fr, 0);
	}
	else
	{
		GetWindowRect(&r);
		GetDlgItem(IDC_VENDOR_LOGO_FRAME)->GetWindowRect(&fr);
		fr.top -= r.top;
		fr.left -= r.left;
		fr.right -= r.left;
		fr.bottom -= r.top;
		DrawBackgroundBitmap(pDC, IDB_RETELL_ON_GREY, &fr, 0);
	}
	return TRUE;
}

void CTelArPropertyPage5::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	RECT pr, cr;

	GetWindowRect(&pr);

	char buffer[50];
	int nOldBkMode = dc.SetBkMode(TRANSPARENT);
	GetDlgItem(IDC_DEFAULT_STATIC)->GetWindowRect(&cr);

	CFont *standardFont = dc.GetCurrentFont();
	LOGFONT FontStats;
	standardFont->GetLogFont(&FontStats);
	strcpy(FontStats.lfFaceName, "MS Sans Serif"); 
	FontStats.lfHeight  = cr.bottom-cr.top;
	FontStats.lfWidth   = 0;	// Breite relativ zur Höhe verkleinern
	FontStats.lfQuality = DEFAULT_QUALITY;
	FontStats.lfWeight	= 700;	// default weight
	CFont neuerFont;	// Font kreiren
	neuerFont.CreateFontIndirect(&FontStats);
	CFont *oldFont = dc.SelectObject(&neuerFont);	// in den device context damit
	
	// Statics füllen
	LANG2BUFFER(IDS_STRING88, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_LOESCHEN1_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING134, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_LOESCHEN2_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING135, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_MAINARCHIVE_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING104, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_INITIALEN_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING89, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_PASSWORT_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING90, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_MASTERPASSWORT_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING166, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_PASSES_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING91, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	if (!strcmp(C_language, "GB"))
		GetDlgItem(IDC_AUTOSTART_STATIC)->GetWindowRect(&cr);
	else
		GetDlgItem(IDC_AUTOSTART_STATIC_LONG)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING158, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_AUFNAHME_AUTOMATIK_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING92, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_EMPFINDLICHKEIT_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING93, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_START_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING94, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_STOP_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING95, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_VERGROESSERN_BEI_PEGEL_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING96, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_MINIMIZE_AFTER_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING198, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_ALC_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING165, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	GetDlgItem(IDC_NICHTBEACHTUNG_STATIC)->GetWindowRect(&cr);
	LANG2BUFFER(IDS_STRING105, buffer);
	dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	// Statics füllen
	if (GetDlgItem(IDC_SENSE_EXTENSION)->IsWindowVisible())
	{
		GetDlgItem(IDC_SENSE_EXTENSION_STATIC)->GetWindowRect(&cr);
		LANG2BUFFER(IDS_STRING213, buffer);
		dc.TextOut(cr.left-pr.left, cr.top-pr.top, buffer, (int)strlen(buffer));
	}

	EnableVoxOptions(!X_intelligent);

	// alten Font und BG-Mode restaurieren
	dc.SelectObject(oldFont);
	dc.SetBkMode(nOldBkMode);
}

void CTelArPropertyPage5::OnDestroy()
{
	RemoveAllAnchors();

	CResizablePage::OnDestroy();
}

void CTelArPropertyPage5::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar == GetDlgItem(IDC_EMPFINDLICHKEIT_SLIDER))
	{
		char buffer2[200];
		sprintf(buffer2, "%d%%", ((CSliderCtrl *)GetDlgItem(IDC_EMPFINDLICHKEIT_SLIDER))->GetPos());
		SetDlgItemText(IDC_EMPFINDLICHKEIT_ANZEIGE, buffer2);
	}
	
	CResizablePage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTelArPropertyPage5::OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	int nBuddyCtrlId = NULL;
	switch (pNMHDR->idFrom)
	{
	case IDC_START_SPIN:
		nBuddyCtrlId = IDC_START; break;
	case IDC_STOP_SPIN:
		nBuddyCtrlId = IDC_STOP; break;
	case IDC_VERGROESSERN_BEI_PEGEL_SPIN:
		nBuddyCtrlId = IDC_VERGROESSERN_BEI_PEGEL; break;
	case IDC_NICHTBEACHTUNG_SPIN:	
		nBuddyCtrlId = IDC_NICHTBEACHTUNG; break;
	}

	if (nBuddyCtrlId)
	{
		int nValue = GetDlgItemInt(nBuddyCtrlId);
		nValue -= pNMUpDown->iDelta;
		if (nValue < 0) nValue = 0;
		SetDlgItemInt(nBuddyCtrlId, nValue);
	}
	
	*pResult = 0;
}

BOOL CTelArPropertyPage5::OnSetActive() 
{
	TRACE0("CTelArPropertyPage5::OnSetActive()\n");

	// X_Path
	char buffer2[1000];
	strcpy(buffer2, X_path);
	if (*buffer2 && buffer2[strlen(buffer2)-1] == '\\')
		buffer2[strlen(buffer2)-1] = '\0';
	SetDlgItemText(IDC_DEFAULT, buffer2);
	SetDlgItemText(IDC_MAINARCHIVE, X_main_archive_path);
	SetDlgItemText(IDC_INITIALEN, X_initialen);
	SetDlgItemText(IDC_PASSWORT, X_passwort);
	m_pw_merken = X_passwort;
	SetDlgItemText(IDC_MASTERPASSWORT, X_master_passwort);
	m_master_pw_merken = X_master_passwort;
	SetDlgItemInt(IDC_PASSES, X_passes);
	
	// Autostart for all users
	{
		HKEY hklm;
		char autostart_path[1000];
		((CButton *)GetDlgItem(IDC_AUTOSTART))->SetCheck(0);
		if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0L, KEY_READ, &hklm) == ERROR_SUCCESS)
		{
			if (QueryKey(hklm, NULL, "TelAr", autostart_path, sizeof(autostart_path)) == ERROR_SUCCESS)
				((CButton *)GetDlgItem(IDC_AUTOSTART))->SetCheck(1);
		}
		if (hklm) RegCloseKey(hklm);
	}

	((CButton *)GetDlgItem(IDC_ALC))->SetCheck(X_alc);
	sprintf(buffer2, "%d%%", X_schwellwert);
	SetDlgItemText(IDC_EMPFINDLICHKEIT_ANZEIGE, buffer2);
	((CSliderCtrl *)GetDlgItem(IDC_EMPFINDLICHKEIT_SLIDER))->SetRange(1, 100, TRUE);
	((CSliderCtrl *)GetDlgItem(IDC_EMPFINDLICHKEIT_SLIDER))->SetPos(X_schwellwert);
	GetDlgItem(IDC_EMPFINDLICHKEIT_SLIDER)->EnableWindow();
	SetDlgItemInt(IDC_START, X_toggle_noise);
	SetDlgItemInt(IDC_STOP, X_toggle_silence);
	SetDlgItemInt(IDC_VERGROESSERN_BEI_PEGEL, X_vergroessern_bei_pegel);
	((CButton *)GetDlgItem(IDC_MINIMIZE_AFTER))->SetCheck(X_minimize_after);
	SetDlgItemInt(IDC_NICHTBEACHTUNG, X_Nichtbeachtung);
	SetDlgItemInt(IDC_LOESCHEN, X_AutomatischLoeschen);
	SetDlgItemText(IDC_SENSE_EXTENSION, X_sense_extension);
	if (!strncmp(X_path, "sense://", 8))
	{
#if defined(SENSE)
		GetDlgItem(IDC_SENSE_EXTENSION)->ShowWindow(SW_SHOW);
#else
		GetDlgItem(IDC_CONNECT_TO_SENSE)->ShowWindow(SW_HIDE);
#endif
	}
	else
	{
		GetDlgItem(IDC_SENSE_EXTENSION)->ShowWindow(SW_HIDE);
	}
	
	return CResizablePage::OnSetActive();
}

void CTelArPropertyPage5::OnAutostart() 
{
	HKEY hklm;
	HKEY hkcu;
	char autostart_path[1000];
	memset(autostart_path, 0x00, sizeof(autostart_path));
	int state = ((CButton *)GetDlgItem(IDC_AUTOSTART))->GetCheck();
	RegOpenKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hklm);
	RegOpenKey(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkcu);
	if (hklm && hkcu)
	{
		if (QueryKey(hklm, hkcu, "TelAr", autostart_path, sizeof(autostart_path)) == ERROR_SUCCESS)
		{				
			if (state)
			{
				if (SetKey(hklm, NULL, "TelAr", autostart_path) == ERROR_SUCCESS)
					RegDeleteValue(hkcu, "TelAr");
				else
				{
					LANG_MESSAGEBOX1(IDS_STRING160);
					((CButton *)GetDlgItem(IDC_AUTOSTART))->SetCheck(!state);
				}
			}
			else
			{
				if (SetKey(hkcu, NULL, "TelAr", autostart_path) == ERROR_SUCCESS)
					RegDeleteValue(hklm, "TelAr");
				else
				{
					LANG_MESSAGEBOX1(IDS_STRING160);
					((CButton *)GetDlgItem(IDC_AUTOSTART))->SetCheck(!state);
				}
			}
		}
		else
		{
			char filebuffer[1000];
			DWORD dw = GetModuleFileName(theApp.m_hInstance, filebuffer, sizeof(filebuffer));
			SetKey(hklm, NULL, "TelAr", filebuffer);
			RegDeleteValue(hkcu, "TelAr");
		}
	}
	else
	{
		AfxMessageBox("Can't open autostart key in registry!");
	}
	if (hkcu) RegCloseKey(hkcu);
	if (hklm) RegCloseKey(hklm);
}


BOOL CTelArPropertyPage5::OnKillActive() 
{
	static BOOL bMessageDisplayed = 0;

	TRACE0("CTelArPropertyPage5::OnKillActive()\n");

	// Dateiname X_path
	char buffer[1000];
	GetDlgItemText(IDC_DEFAULT, buffer, sizeof(buffer));
	if (buffer[strlen(buffer)-1] == '\\') buffer[strlen(buffer)-1] = '\0';
	
	if (!_strnicmp(buffer, "sense://", 8))
	{
		//validate the sense server is running!
		if (strcmp(X_path, buffer)) 
			if (Reconnect2SenseServer(buffer))
			{
				bMessageDisplayed = TRUE;
				LANG_MESSAGEBOX2(IDS_STRING183, MB_ICONSTOP); // "Ungültiger Pfad!"
				bMessageDisplayed = FALSE;
				GetDlgItem(IDC_DEFAULT)->SetFocus();
				return FALSE;
			}
	}
	else
	{
		DWORD attrib = GetFileAttributes(buffer);
		if ((!(attrib & FILE_ATTRIBUTE_DIRECTORY) || attrib == 0xFFFFFFFF) && !bMessageDisplayed)
		{
			bMessageDisplayed = TRUE;
			LANG_MESSAGEBOX2(IDS_STRING49, MB_ICONSTOP); // "Ungültiger Pfad!"
			bMessageDisplayed = FALSE;
			GetDlgItem(IDC_DEFAULT)->SetFocus();
			return FALSE;
		}
	}

	// if changed, reopen index file with new database location
	if (strcmp(X_path, buffer))
	{
		// X_path override if hklm local_path is set
		if (*X_local_path)
		{
			if (_strnicmp(X_local_path, buffer, strlen(X_local_path))) 
			{
				AfxMessageBox("First part of the recording path needs to match the HKLM\\SOFTWARE\\TRS\\TelAr\\local_path registry value.");
				return FALSE;
			}
			if (buffer[strlen(X_local_path)] == '\\')
			{
				strcpy(X_local_path_subfolder, buffer + strlen(X_local_path) + 1);
			}
		}

		char buffer2[1000];
		((CTelArPropertySheet *)GetParent())->m_Page1.default_index.Close();
		strcpy(buffer2, buffer);
			if (*buffer2 && buffer2[strlen(buffer2)-1] != '\\')
		strcat(buffer2, "\\");
		strcat(buffer2, INDEX_FILENAME);

		// if old-style index file: convert
		if (IsOldStyleIndexFile(buffer2))
		{
			char buffer3[1000];
			LANG2BUFFER(IDS_STRING178, buffer3);
			if (AfxMessageBox(buffer3, MB_YESNO) == IDYES) // The index file in this folder has an outdated format and needs to be converted before it can be modified. Do you want to convert it now?
			{
				DoConvert(buffer, "");
			}
		}

		((CTelArPropertySheet *)GetParent())->m_Page1.default_index.OpenCreate(buffer2, "");
	}
	strcpy(X_path, buffer);

	GetDlgItemText(IDC_MAINARCHIVE, buffer, sizeof(buffer));
	if (strlen(buffer))
	{
		if (buffer[strlen(buffer)-1] == '\\') buffer[strlen(buffer)-1] = '\0';
		DWORD attrib = GetFileAttributes(buffer);
		if ((!(attrib & FILE_ATTRIBUTE_DIRECTORY) || attrib == 0xFFFFFFFF) && !bMessageDisplayed)
		{
			bMessageDisplayed = TRUE;
			LANG_MESSAGEBOX2(IDS_STRING49, MB_ICONSTOP); // "Ungültiger Pfad!"
			bMessageDisplayed = FALSE;
			GetDlgItem(IDC_MAINARCHIVE)->SetFocus();
			return FALSE;
		}
	}
	strcpy(X_main_archive_path, buffer);
	
	// Initialen
	GetDlgItemText(IDC_INITIALEN, X_initialen, sizeof(X_initialen));
	X_initialen[2] = '\0'; *X_initialen = toupper(*X_initialen); X_initialen[1] = toupper(X_initialen[1]);

	// Passwort
	GetDlgItemText(IDC_PASSWORT, X_passwort, sizeof(X_passwort));
	if (m_pw_merken != X_passwort)
	{
		int idd;
		
		if (!strcmp(C_language, "D")) 
			idd = IDD_PASSWORT;
		else if (!strcmp(C_language, "GB")) 
			idd = IDD_GB_PASSWORT;
		else if (!strcmp(C_language, "CZ")) 
			idd = IDD_CZ_PASSWORT;
		else if (!strcmp(C_language, "NL")) 
			idd = IDD_NL_PASSWORT;
		else if (!strcmp(C_language, "PL")) 
			idd = IDD_PL_PASSWORT;
		else 
			idd = IDD_E_PASSWORT;

		CPasswortDlg dlg(idd, (CString)X_passwort, this);
		if (dlg.DoModal() != IDOK) strcpy(X_passwort, (LPCSTR)m_pw_merken);
	}

	GetDlgItemText(IDC_MASTERPASSWORT, X_master_passwort, sizeof(X_master_passwort));
	if (m_master_pw_merken != X_master_passwort)
	{
		int idd;
		
		if (!strcmp(C_language, "D")) 
			idd = IDD_PASSWORT;
		else if (!strcmp(C_language, "GB")) 
			idd = IDD_GB_PASSWORT;
		else if (!strcmp(C_language, "CZ")) 
			idd = IDD_CZ_PASSWORT;
		else if (!strcmp(C_language, "NL")) 
			idd = IDD_NL_PASSWORT;
		else if (!strcmp(C_language, "PL")) 
			idd = IDD_PL_PASSWORT;
		else 
			idd = IDD_E_PASSWORT;

		CPasswortDlg dlg(idd, (CString)X_master_passwort, this);
		if (dlg.DoModal() != IDOK) strcpy(X_master_passwort, (LPCSTR)m_master_pw_merken);
	}

	X_alc = ((CButton *)GetDlgItem(IDC_ALC))->GetCheck();
	if (X_intelligent != 1) WaveIn_SetALC(X_alc);
	
	BOOL bRet;
	int n = GetDlgItemInt(IDC_PASSES, &bRet);
	if ((!bRet || n < 0 || n > 1000) && !bMessageDisplayed)
	{
		bMessageDisplayed = TRUE;
		LANG_MESSAGEBOX2(IDS_STRING37, MB_ICONSTOP); // "Eingabefehler: Für den Verschlüsselungsgradbitte einen Wert von 1 bis 1000 angeben!"
		bMessageDisplayed = FALSE;
		GetDlgItem(IDC_PASSES)->SetFocus();
		return FALSE;
	}
	X_passes = n;

	X_schwellwert = ((CSliderCtrl *)GetDlgItem(IDC_EMPFINDLICHKEIT_SLIDER))->GetPos();

	n = GetDlgItemInt(IDC_START, &bRet);
	if ((!bRet || n < 1 || n > 100) && !bMessageDisplayed)
	{
		bMessageDisplayed = TRUE;
		LANG_MESSAGEBOX2(IDS_STRING24, MB_ICONSTOP); // "Eingabefehler: Für die Start-Signaldauer bitte einen Wert von 1 bis 100 angeben!"
		bMessageDisplayed = FALSE;
		GetDlgItem(IDC_START)->SetFocus();
		return FALSE;
	}
	X_toggle_noise = n;

	n = GetDlgItemInt(IDC_STOP, &bRet);
	if ((!bRet || n < 1 || n > 100) && !bMessageDisplayed)
	{
		bMessageDisplayed = TRUE;
		LANG_MESSAGEBOX2(IDS_STRING25, MB_ICONSTOP); // "Eingabefehler: Für die Stop-Signalausfalldauer bitte einen Wert von 1 bis 100 angeben!"
		bMessageDisplayed = FALSE;
		GetDlgItem(IDC_EMPFINDLICHKEIT)->SetFocus();
		return FALSE;
	}
	X_toggle_silence = n;

	n = GetDlgItemInt(IDC_VERGROESSERN_BEI_PEGEL, &bRet);
	if (n < 0)
	{
		n = 0;
	}
	X_vergroessern_bei_pegel = n;

	X_minimize_after = ((CButton *)GetDlgItem(IDC_MINIMIZE_AFTER))->GetCheck();


	n = GetDlgItemInt(IDC_NICHTBEACHTUNG, &bRet);
	if (n < 0)
	{
		n = 0;
	}
	X_Nichtbeachtung = n;

	n = GetDlgItemInt(IDC_LOESCHEN, &bRet);
	if (n < 0)
	{
		n = 0;
	}
	X_AutomatischLoeschen = n;

	GetDlgItemText(IDC_SENSE_EXTENSION, buffer, sizeof(buffer));
	if (!strlen(buffer))
	{
		strcpy(buffer, "0");
	}
	strcpy(X_sense_extension, buffer);

	return CResizablePage::OnKillActive();
}

void CTelArPropertyPage5::OnSetRootPath() 
{
	CString csPathBuffer;	 
	char TitleBuffer[200];

	GetDlgItemText(IDC_DEFAULT, csPathBuffer);
	LANG2BUFFER(IDS_STRING51, TitleBuffer);
	CXFolderDialog dlg(csPathBuffer);
	dlg.SetOsVersion(CXFolderDialog::XFILEDIALOG_AUTO_DETECT_OS_VERSION);
	dlg.SetTitle(TitleBuffer);
	if (dlg.DoModal() == IDOK)
	{
    	csPathBuffer = dlg.GetPath();

		if (csPathBuffer.GetLength() && csPathBuffer[csPathBuffer.GetLength()-1] == '\\')
			csPathBuffer = csPathBuffer.Left(csPathBuffer.GetLength()-1);
		SetDlgItemText(IDC_DEFAULT, csPathBuffer);
	}
}

// also consider SQLite CREATE TABLE commands in CIndexDB when making changes here
static char *sqlcrtbl[] = {
	"CREATE TABLE Recordings (f0 varchar(255), f1 char(2), f2 text, f3 text, \
f4 char(10), f5 char(8), f6 char(10), f7 char(10), f8 char(1), f9 char(8), f10 char(1), \
PRIMARY KEY (f4,f5,f1));",
	"CREATE TABLE Workstations (Computername char(15), ID char(2), Date char(10), \
Time char(8), License varchar(255), RequestKey varchar(255), \
ResponseKey varchar(255), Version varchar(255), PRIMARY KEY (Computername));",
	"CREATE TABLE Licenses (License varchar(255), PRIMARY KEY (License));",
	"CREATE TABLE Accesslog (Date char(10), Time char(8), ID char(2), \
Computername char(15), OK char(1), Operation varchar(255), Details varchar(255));",
	"CREATE TABLE Config (CFGKey varchar(255), CFGValue varchar(255), PRIMARY KEY (CFGKey));"
};

/*
*/

static char sqlcrtbl_size = sizeof(sqlcrtbl)/sizeof(sqlcrtbl[0]);

void CTelArPropertyPage5::OnConnectToSqlServer() 
{
	DSAMessageBox(IDS_STRING181);

	// Get network directory
	CString csPathBuffer;	 
	{
		char TitleBuffer[200];

		GetDlgItemText(IDC_DEFAULT, csPathBuffer);
		LANG2BUFFER(IDS_STRING51, TitleBuffer);
		CXFolderDialog dlg(csPathBuffer);
		dlg.SetOsVersion(CXFolderDialog::XFILEDIALOG_AUTO_DETECT_OS_VERSION);
		dlg.SetTitle(TitleBuffer);
		if (dlg.DoModal() == IDOK)
		{
    		csPathBuffer = dlg.GetPath();

			if (csPathBuffer.GetLength() && csPathBuffer[csPathBuffer.GetLength()-1] == '\\')
				csPathBuffer = csPathBuffer.Left(csPathBuffer.GetLength()-1);
		}
		else
			return;
	}

	// browse system and user datasources
	CString csDSN;	 
	{
		CDataSourceDialog dlg;
		if (dlg.DoModal() == IDOK)
		{
    		csDSN = dlg.m_csDSN;
		}
		else
			return;
	}

	// select ODBC data source
	CADODatabase db;
	BOOL bErrors = FALSE;
	{
		try
		{
			// ODBC Data Source Administrator
			db.SetConnectionString("");
			db.Open(csDSN); // "DSN=bugtracker auf Bugtracker"

			// create tables
			{
				int i;

				// MS SQL likes pass through Queries
				for (i = 0; i < sqlcrtbl_size; i++)
				{
					try
					{
						db.Execute(sqlcrtbl[i]);
					}
					catch( CADOException& e )
					{
						AfxMessageBox( 
							e.GetErrorMessage() + (CString)": " + (CString)sqlcrtbl[i] + " (Maybe table already exists?)", 
								MB_ICONEXCLAMATION );
						DF(e.GetErrorMessage().GetBuffer(0));
					}		
				}
			}
		}

		catch( CADOException& e )
		{
			AfxMessageBox( 
				e.GetErrorMessage(), 
					MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			return;
		}		
	}

	((CTelArPropertySheet *)GetParent())->m_Page1.default_index.Close();	// close old index before doing anything
	//((CTelArPropertySheet *)GetParent())->m_Page2.liste_index.Close();	// close old index before doing anything
	SetDlgItemText(IDC_DEFAULT, csPathBuffer);
	strcpy(X_path, csPathBuffer.GetBuffer(0));
	{
		// fill in archive folder
		char buffer2[1000];
		((CTelArPropertySheet *)GetParent())->m_Page1.default_index.Close();
		strcpy(buffer2, X_path);
			if (*buffer2 && buffer2[strlen(buffer2)-1] != '\\')
		strcat(buffer2, "\\");
		strcat(buffer2, INDEX_FILENAME);

		// previous index file already in this folder?

		CFile File;
		if (File.Open(buffer2, CFile::modeRead|CFile::shareDenyNone))
		{
			File.Close();
			char buffer3[3000];
			CTime now = CTime::GetCurrentTime();
			sprintf(buffer3, "%s - BACKUP%s", buffer2, now.Format("%Y%m%d%H%M%S").GetBuffer(0));
			if (!MoveFile(buffer2, buffer3))
			{
				DWORD dw = GetLastError();
				char buffer[2000];
				char buffer1[2000];
				LANG2BUFFER(IDS_STRING216, buffer);
				sprintf(buffer1, buffer, buffer2, buffer3);
				AfxMessageBox(buffer1, MB_ICONSTOP);	
				bErrors = TRUE;

				LPVOID lpMsgBuf; 
				FormatMessage( 
					FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
					NULL,
					dw,
					MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
					(LPTSTR) &lpMsgBuf,
					0,
					NULL 
				);
				AfxMessageBox((char *)lpMsgBuf, MB_OK|MB_ICONINFORMATION);
			}
		}

		// now write index file with dsn in it

		CFile fdestination;

		if (!bErrors)
		{
			if (!fdestination.Open(buffer2, CFile::modeWrite|CFile::modeCreate)) 
			{
				char buffer[2000];
				char buffer1[2000];
				LANG2BUFFER(IDS_STRING215, buffer);
				sprintf(buffer1, buffer, buffer2);
				AfxMessageBox(buffer1, MB_ICONSTOP);	
				bErrors = TRUE;
			}
			else
			{
				try
				{
					fdestination.Write("DSN=", 4);
					fdestination.Write(csDSN, csDSN.GetLength());
				}
				catch( CFileException* e )
				{
					char buffer[5000];
					e->GetErrorMessage(buffer, sizeof(buffer));
					AfxMessageBox(buffer, MB_ICONSTOP);
					e->Delete();
					bErrors = TRUE;
				}
			}
			
			fdestination.Close();
		}

		// finally re-open database
		((CTelArPropertySheet *)GetParent())->m_Page1.default_index.OpenCreate(buffer2, "");
		//((CTelArPropertySheet *)GetParent())->m_Page2.RefreshListe();
	}

	db.Close();

	if (!bErrors)
		LANG_MESSAGEBOX1(IDS_STRING185);
}

void CTelArPropertyPage5::OnConnectToSense()
{
	SetDlgItemText(IDC_DEFAULT, "sense://localhost:9803");
	((CEdit*)GetDlgItem(IDC_DEFAULT))->SetSel(8, 17);
	(GetDlgItem(IDC_DEFAULT))->SetFocus();
#if defined(SENSE)
	GetDlgItem(IDC_SENSE_EXTENSION)->ShowWindow(SW_SHOW);
#endif
	RedrawWindow();
}

void CTelArPropertyPage5::OnChangePasswort() 
{
	CString csPassword, csPasses;
	GetDlgItemText(IDC_PASSWORT, csPassword);
	if (!csPassword.IsEmpty())
	{
		GetDlgItemText(IDC_PASSES, csPasses);
		if (atoi((LPCSTR)csPasses) == 0) X_passes = 1;
		SetDlgItemText(IDC_PASSES, "1");
	}
}

void CTelArPropertyPage5::OnSetMainarchive() 
{
	CString csPathBuffer;	 
	char TitleBuffer[200];

	GetDlgItemText(IDC_MAINARCHIVE, csPathBuffer);
	LANG2BUFFER(IDS_STRING51, TitleBuffer);
	CXFolderDialog dlg(csPathBuffer);
	dlg.SetOsVersion(CXFolderDialog::XFILEDIALOG_AUTO_DETECT_OS_VERSION);
	dlg.SetTitle(TitleBuffer);
	if (dlg.DoModal() == IDOK)
	{
    	csPathBuffer = dlg.GetPath();

		if (csPathBuffer.GetLength() && csPathBuffer[csPathBuffer.GetLength()-1] == '\\')
			csPathBuffer = csPathBuffer.Left(csPathBuffer.GetLength()-1);
		SetDlgItemText(IDC_MAINARCHIVE, csPathBuffer);
	}
}

void CTelArPropertyPage5::EnableVoxOptions(BOOL bEnable)
{
	GetDlgItem(IDC_EMPFINDLICHKEIT)->EnableWindow(bEnable);
	GetDlgItem(IDC_START)->EnableWindow(bEnable);
	GetDlgItem(IDC_STOP)->EnableWindow(bEnable);
	GetDlgItem(IDC_START_SPIN)->EnableWindow(bEnable);
	GetDlgItem(IDC_STOP_SPIN)->EnableWindow(bEnable);
}


//--- ENCRYPTION -------------

#define TRS_MAGIC "TRSc"

// produziert aus dem String 'key' 3 int-Werte, die den 56-bin key repräsentieren
static BOOL Generate56BitKey(CString &key, int *seed_1, int *seed_2, int *offset)
{
	CString temp = key;
	unsigned char keybuf[1000];
	unsigned char key56[7];
	int i, j;

	// keine Groß-/kleinschreibung unterscheiden
	temp.MakeUpper();
	temp.TrimLeft();
	temp.TrimRight();
	int orig_length = temp.GetLength();
	if (!temp.GetLength()) return FALSE;
	
	do
	{
		temp += temp;
	}
	while (temp.GetLength() < 14);

	memset(keybuf, '\0', sizeof(keybuf));
	strcpy((char *)keybuf, temp.GetBuffer(0));

	memset(key56, '\0', sizeof(key56));

	for (i = 0; i < orig_length || i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			// drauf-xoren:
			key56[j] ^= keybuf[j+i];

			// jedes einzelne Byte 1 bit nach links cyceln:
			unsigned char carry = key56[j] & 0x80;
			key56[j] <<= 1;
			carry >>=7;
			key56[j] |= carry;
		}
	}

	*seed_1 = (int)((DWORD)((DWORD)key56[0] << 8) | key56[1]) % 31328;
	*seed_2 = (int)((DWORD)((DWORD)key56[2] << 8) | key56[3]) % 30081;
	*offset = (int)((DWORD)((DWORD)key56[4] << 16) 
				 | ((DWORD)key56[5] << 8) 
				 | key56[6]) 
				 % 30081;
	return TRUE;
}

static int win_off = 0;

static BOOL EncryptFile(CString &source, CString &destination, CString &key, int passes, BOOL bProgressBar)
{
	int i;
	CFile fsource;

	if (!fsource.Open(source, CFile::modeRead)) 
	{
		LANG_MESSAGEBOX2(IDS_STRING29, MB_ICONSTOP);		
		return FALSE;
	}

	DWORD size = (DWORD)fsource.GetLength();

	if (!size) 
	{
		LANG_MESSAGEBOX2(IDS_STRING30, MB_ICONSTOP);
		fsource.Close();
		return FALSE;
	}

	unsigned char *filebuf;

	CProgressDlg *pdlg = NULL;
	if (bProgressBar) 
	{
		pdlg = new CProgressDlg(IDS_STRING53);
		if (pdlg) 
		{
			pdlg->m_DisableParent = FALSE;
			if (nThreadCounter <= 1 || win_off > 500)
				win_off = 0;
			else 
				win_off += 25;
			pdlg->m_WindowOffset = win_off;
			pdlg->Create(AfxGetMainWnd());
			pdlg->ShowWindow(SW_SHOW);
		}
		else
			bProgressBar = FALSE;			
	}

	// Speicher für die gesamte Datei herbekommen
	try
	{
		filebuf = new unsigned char[size];
	}
	catch( CMemoryException* e )
	{
		char buffer[5000];
		e->GetErrorMessage(buffer, sizeof(buffer));
		AfxMessageBox(buffer, MB_ICONSTOP);
		e->Delete();
		fsource.Close();
		if (bProgressBar) { pdlg->EndDialog(1); delete pdlg; }
		return FALSE;
	}

	// 'Session key' generieren
	int ij, kl, offset;
	if (!Generate56BitKey(key, &ij, &kl, &offset))
	{
		fsource.Close();
		delete filebuf;
		if (bProgressBar) { pdlg->EndDialog(1); delete pdlg; }
		return FALSE;
	}	

	// Zufallsgenerator auf Startposition bringen:	
	rangen rg;
	rg.rmarin(ij, kl);
	for (i = 0; i < offset; i++)
		rg.ranmar();

	// Datei einlesen:
	if (fsource.Read(filebuf, size) != size) 
	{
		LANG_MESSAGEBOX2(IDS_STRING31, MB_ICONSTOP);		
		fsource.Close();
		delete filebuf;
		if (bProgressBar) { pdlg->EndDialog(1); delete pdlg; }
		return FALSE;
	}

	// Verschlüsselungsvorgang:
	DWORD crc;
	for (i = 0, crc = 0L; i < passes; i++)
	{
		for (int j = 0; j < (int)size; j++)
		{
			// Checksum pflegen (cyclic redundancy check):
			if (i == 0) 
			{
				DWORD carry = crc & 0x80000000;
				crc <<= 1;
				carry >>= 31;
				crc |= carry;
				crc ^= filebuf[j];
			}
			filebuf[j] ^= (unsigned char)((float)rg.ranmar() * 256.0);

			if (!(j % 1024) && bProgressBar)
			{
				if (size < 100) 
					pdlg->SetPos(0);
				else				
					pdlg->SetPos((i * size + j) / (size / 100 * passes));

				TRACE1("%d\r\n", j);
			}
		}
	}

	CFile fdestination;

	if (!fdestination.Open(destination, CFile::modeWrite|CFile::modeCreate)) 
	{
		LANG_MESSAGEBOX2(IDS_STRING32, MB_ICONSTOP);		
		fsource.Close();
		delete filebuf;
		if (bProgressBar) { pdlg->EndDialog(1); delete pdlg; }
		return FALSE;
	}

	try
	{
		fdestination.Write(TRS_MAGIC, 4);
		fdestination.Write((void *)&crc, 4);
		fdestination.Write((void *)&passes, 4);
		fdestination.Write((void *)filebuf, size);
	}
	catch( CFileException* e )
	{
		char buffer[5000];
		e->GetErrorMessage(buffer, sizeof(buffer));
		AfxMessageBox(buffer, MB_ICONSTOP);
		e->Delete();
		fdestination.Close();
		fsource.Close();
		delete filebuf;
		if (bProgressBar) { pdlg->EndDialog(1); delete pdlg; }
		return FALSE;
	}

	if (bProgressBar) { pdlg->EndDialog(1); delete pdlg; }

	fdestination.Close();
	fsource.Close();
	delete filebuf;
	return TRUE;
}

static BOOL DecryptFile(CString &source, CString &destination, CString &key)
{
	int i;
	CFile fsource;

	if (!fsource.Open(source, CFile::modeRead)) 
	{
		LANG_MESSAGEBOX2(IDS_STRING29, MB_ICONSTOP);		
		return FALSE;
	}

	DWORD size = (DWORD)fsource.GetLength();

	if (size < 8) 
	{
		LANG_MESSAGEBOX2(IDS_STRING33, MB_ICONSTOP);
		fsource.Close();
		return FALSE;
	}

	// Type-Marker im Datei-Header checken:
	char buffer[4];
	if (fsource.Read(buffer, 4) != 4) 
	{
		LANG_MESSAGEBOX2(IDS_STRING33, MB_ICONSTOP);		
		fsource.Close();
		return FALSE;
	}
	if (strncmp(buffer, TRS_MAGIC, 4)) 
	{
		LANG_MESSAGEBOX2(IDS_STRING34, MB_ICONSTOP);		
		fsource.Close();
		return FALSE;
	}
	
	// CRC-Checksumme der Datei lesen:
	DWORD crc_file;
	if (fsource.Read((void *)&crc_file, 4) != 4) 
	{
		LANG_MESSAGEBOX2(IDS_STRING33, MB_ICONSTOP);		
		fsource.Close();
		return FALSE;
	}

	// Anzahl der Durchläufe lesen:
	DWORD passes_file;
	if (fsource.Read((void *)&passes_file, 4) != 4) 
	{
		LANG_MESSAGEBOX2(IDS_STRING33, MB_ICONSTOP);		
		fsource.Close();
		return FALSE;
	}

	size -= 12; // ohne header

	unsigned char *filebuf;

	CProgressDlg dlg(IDS_STRING54);
	dlg.Create(AfxGetMainWnd());

	// Speicher für die gesamte Datei (minus header) herbekommen
	try
	{
		filebuf = new unsigned char[size];
	}
	catch( CMemoryException* e )
	{
		char buffer[5000];
		e->GetErrorMessage(buffer, sizeof(buffer));
		AfxMessageBox(buffer, MB_ICONSTOP);
		e->Delete();
		fsource.Close();
		dlg.EndDialog(1);
		return FALSE;
	}

	// 'session key' generieren
	int ij, kl, offset;
	if (!Generate56BitKey(key, &ij, &kl, &offset))
	{
		fsource.Close();
		delete filebuf;
		dlg.EndDialog(1);
		return FALSE;
	}	

	// Zufallsgenerator auf Startposition bringen:
	rangen rg;
	rg.rmarin(ij, kl);
	for (i = 0; i < offset; i++)
		rg.ranmar();

	// Datei einlesen:
	if (fsource.Read(filebuf, size) != size) 
	{
		LANG_MESSAGEBOX2(IDS_STRING35, MB_ICONSTOP);		
		fsource.Close();
		delete filebuf;
		dlg.EndDialog(1);
		return FALSE;
	}

	// Entschlüsselungsvorgang:
	DWORD crc;
	for (i = 0, crc = 0L; i < (int)passes_file; i++)
	{
		for (int j = 0; j < (int)size; j++)
		{
			filebuf[j] ^= (unsigned char)((float)rg.ranmar() * 256.0);
			// Checksum pflegen (cyclic redundancy check):
			if (i == (int)passes_file - 1) 
			{
				DWORD carry = crc & 0x80000000;
				crc <<= 1;
				carry >>= 31;
				crc |= carry;
				crc ^= filebuf[j];
			}

			if (!(j % 1024))
			{
				if (size < 100) 
					dlg.SetPos(0);
				else				
					dlg.SetPos((i * size + j) / (size / 100 * passes_file));
			}
		}
	}

	if  (crc != crc_file)
	{
		LANG_MESSAGEBOX2(IDS_STRING39, MB_ICONSTOP);		
		fsource.Close();
		delete filebuf;
		dlg.EndDialog(1);
		return FALSE;
	}

	CFile fdestination;

	if (!fdestination.Open(destination, CFile::modeWrite|CFile::modeCreate)) 
	{
		LANG_MESSAGEBOX2(IDS_STRING36, MB_ICONSTOP);		
		fsource.Close();
		delete filebuf;
		dlg.EndDialog(1);
		return FALSE;
	}

	try
	{
		fdestination.Write(filebuf, size);
	}
	catch( CFileException* e )
	{
		char buffer[5000];
		e->GetErrorMessage(buffer, sizeof(buffer));
		AfxMessageBox(buffer, MB_ICONSTOP);
		e->Delete();
		fdestination.Close();
		fsource.Close();
		delete filebuf;
		dlg.EndDialog(1);
		return FALSE;
	}

	dlg.EndDialog(1);

	fdestination.Close();
	fsource.Close();
	delete filebuf;
	return TRUE;
}
