/*	$Header:   D:/pvcsarch/recordat/wavein/wavein.h_v   1.78   Dec 19 2007 17:27:26   tmielke  $
*
*	Beschreibung:
*
*	Wave-Device Recorder DLL - header file
*
*	$Log:   D:/pvcsarch/recordat/wavein/wavein.h_v  $
* 
*    Rev 1.78   Dec 19 2007 17:27:26   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.77   Oct 11 2007 10:15:00   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.76   Sep 21 2007 15:47:16   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.75   Aug 14 2007 14:09:04   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.74   May 09 2007 10:23:40   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.73   Nov 16 2006 14:59:42   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.72   Nov 13 2006 13:26:18   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.71   Jun 12 2006 15:13:20   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.70   Nov 25 2005 01:32:14   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.69   Nov 23 2005 16:11:16   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.68   Nov 11 2005 09:50:56   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.67   Jul 11 2005 08:52:28   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.66   Jul 05 2005 01:50:16   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.65   Jun 28 2005 01:46:22   tmielke
* v1.72 build 1250
* 
*    Rev 1.64   Jun 02 2005 01:30:24   tmielke
* v1.72 build 1207
* 
*    Rev 1.63   May 18 2005 13:47:08   tmielke
* v1.72 build 1200
* 
*    Rev 1.62   Mar 18 2005 16:11:58   tmielke
*  
* 
*    Rev 1.61   Mar 12 2005 07:08:28   tmielke
* v1.69
* 
*    Rev 1.60   Feb 22 2005 16:53:20   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.59   Nov 21 2004 01:29:14   tmielke
* v1.66 build 883
* 
*    Rev 1.58   Dec 04 2003 03:36:40   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.57   Nov 18 2003 09:39:40   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.56   Oct 03 2003 01:22:08   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.55   Sep 23 2003 01:48:02   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.54   Sep 12 2003 01:12:08   tmielke
*  
* 
*    Rev 1.53   Sep 11 2003 04:04:04   tmielke
*  
* 
*    Rev 1.52   Sep 11 2003 04:03:38   tmielke
* This version should fix the NT40 problems (waveinAddBuffer deadlock).
* I also removed the animated window code for opening info and search screens.
*
*    Rev 1.51   Sep 04 2003 00:55:24   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
*
*    Rev 1.50   Aug 04 2003 00:34:58   tmielke
* v1.64
*
*    Rev 1.49   Aug 04 2003 00:34:22   tmielke
* optional ALC, corrected spelling, and setup script modification
*
*    Rev 1.48   Jun 09 2003 15:25:14   tmielke
* v1.63 final
*
*    Rev 1.47   Jan 27 2003 01:14:04   tmielke
* Polish language support
*
*    Rev 1.46   Nov 20 2002 03:56:00   tmielke
* Dutch language support
*
*    Rev 1.45   Oct 25 2002 11:28:30   tmielke
* Sicherheits-CheckIn vor level control auf mixer umgestellt
*
*    Rev 1.44   Sep 24 2002 15:13:52   tmielke
* Total vermurxt alles... :(
*
*    Rev 1.43   Sep 11 2002 20:13:32   tmielke
* Mixer Architektur in hardware screen eingebaut
*
*    Rev 1.42   Aug 16 2002 20:03:44   tmielke
* control tone
*
*    Rev 1.41   Jun 05 2002 19:31:54   tmielke
* v1.62
*
*    Rev 1.40   May 05 2002 11:56:12   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
*
*    Rev 1.39   Apr 19 2002 07:27:26   tmielke
* Czech translation added
*
*    Rev 1.38   Mar 15 2002 20:21:30   tmielke
* v1.60
*
*    Rev 1.37   Nov 07 2001 02:08:10   tmielke
* v1.59 bugfix release
*
*    Rev 1.36   Nov 06 2001 05:26:46   tmielke
* v1.58a
*
*    Rev 1.35   Oct 12 2001 16:22:40   tmielke
* v1.58 bugfix wav export
*
*    Rev 1.34   Sep 14 2001 04:12:28
* v1.57
*
*    Rev 1.33   06 Jun 2001 02:00:02   tmielke
* offizielle release 1.55
*
*    Rev 1.32   17 May 2001 02:01:02   tmielke
* v1.54
*
*    Rev 1.31   17 May 2001 00:34:52   tmielke
* Spanische Sprach-DLL hinzugefügt
*
*    Rev 1.30   12 Feb 2001 19:36:44   tmielke
* v1.53
*
*    Rev 1.29   20 Dec 2000 18:18:10   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
*
*    Rev 1.28   04 Dec 2000 02:22:46   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
*
*    Rev 1.27   19 Oct 2000 02:28:34   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
*
*
*    Rev 1.26   18 Oct 2000 20:34:24   tmielke
* Alpha version ALC
*
*    Rev 1.25   19 Jun 2000 15:54:00   tmielke
* v1.44 letzte TRS-Version
*
*    Rev 1.24   24 Mar 2000 22:36:10   tmielke
* v1.44 encrypting im hintergrund
*
*    Rev 1.23   18 Mar 2000 11:40:10   tmielke
* zur sicherheit eingecheckt
*
*    Rev 1.22   17 Mar 2000 05:31:42   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
*
*    Rev 1.21   05 Mar 2000 05:20:44   tmielke
* v1.43
*
*    Rev 1.20   28 Feb 2000 00:30:28   tmielke
* v1.42
*
*    Rev 1.19   24 Feb 2000 15:27:46   tmielke
* v1.41
*
*    Rev 1.18   24 Feb 2000 01:22:36   tmielke
* v1.39
*
*    Rev 1.17   18 Feb 2000 00:38:42   tmielke
* v1.38
*
*    Rev 1.16   15 Dec 1999 03:33:32   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
*
*    Rev 1.15   01 Dec 1999 18:45:16   tmielke
* v1.36 BPS -> Frohberg GmbH
*
*    Rev 1.14   16 Aug 1999 10:31:36   tmielke
* v1.34
*
*    Rev 1.13   09 Aug 1999 07:50:58   tmielke
* Encryption eingebaut
*
*    Rev 1.12   07 Jun 1999 19:09:04   tmielke
* Multi Language version number update: v1.33
*
*    Rev 1.11   05 Apr 1999 08:16:20   tmielke
* sync
*
*    Rev 1.10   20 Mar 1999 18:51:54   tmielke
* v1.3
*
*    Rev 1.9   18 Mar 1999 13:28:34   tmielke
* v0.8 - Demoversion fertig gemacht
*
*    Rev 1.8   03 Mar 1999 13:40:46   tmielke
* Version Label v0.6
*
*    Rev 1.7   28 Feb 1999 09:19:44   tmielke
* Leitungspegel-Automatik eingebaut.
*
*    Rev 1.6   28 Feb 1999 07:05:42   tmielke
* Aufnahmepegel eingebaut.
* Monitor Modus eingebaut.
*
*    Rev 1.5   28 Feb 1999 01:10:02   tmielke
* Dateiheader/keywords verschönert
*
*    Rev 1.4   28 Feb 1999 01:07:58   tmielke
*
* keywords hinzugefügt
*
*/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// erweiterte keywords für Microsoft DLL-Im/Exporte
#if !defined(DllExport)
	#define DllExport	__declspec( dllexport )
#endif
#if !defined(DllImport)
	#define DllImport	__declspec( dllimport )
#endif

// 'DllTrade' setzen, je nachdem, ob importiert oder exportiert werden soll
#if defined(WaveIn_Export)
	#define DllTrade DllExport
#else
	#define DllTrade DllImport
#endif

DllTrade void WaveIn_SetLanguage(int lang);
DllTrade void WaveIn_SetHWND(DWORD hWnd);
DllTrade void WaveIn_SetALC(BOOL alc_param);
DllTrade void WaveIn_SetControlTone(BOOL control_tone_param);
DllTrade void WaveIn_SetControlToneChannel(int control_tone_channel_param);
DllTrade void WaveIn_ProbeControlToneChannel(BOOL probe_control_tone_channel_mode_param);
DllTrade int  WaveIn_GetProbeControlToneChannelResult();
DllTrade BOOL WaveIn_IsActiveControlTone();
DllTrade BOOL WaveIn_GetControlToneWarning();
DllTrade HWAVEIN WaveIn_GetDeviceHandle();
DllTrade void WaveIn_MuteMicrophone();
DllTrade void WaveIn_OpenMicrophone();
DllTrade BOOL WaveIn_Open(char *filename, unsigned int device, int channels, int samplerate, int bitspersample, DWORD_PTR codec, DWORD_PTR format);
DllTrade void WaveIn_Close();
DllTrade void WaveIn_Start();
DllTrade void WaveIn_Stop();
DllTrade void WaveIn_Stats(int *kr, int *ul, int *al);
DllTrade void WaveIn_Peaks(int *pnMaxPeak, int *pnMinPeak);
DllTrade BOOL WaveIn_ReallocBuffer();
void CALLBACK  WaveInFunc(HWAVEIN	hWaveIn,
						  UINT		wMsg,
						  DWORD_PTR	dwInstance,
						  DWORD_PTR	dwParam1,
						  DWORD_PTR	dwParam2);

#define WAVEIN_LANG_D	(0)
#define WAVEIN_LANG_GB	(1)
#define WAVEIN_LANG_E	(2)
#define WAVEIN_LANG_CZ	(3)
#define WAVEIN_LANG_NL	(4)
#define WAVEIN_LANG_PL	(5)

// user-defined windows message for reallocating wavein buffers
#define MYWM_REALLOCATE_WAVEIN_BUFFER		(WM_APP+123)