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
*	Wave-Device Recorder DLL - implementation file
*
*	$Log:   D:/pvcsarch/recordat/wavein/wavein.cpv  $
* 
*    Rev 1.99   Dec 19 2007 17:27:26   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.98   Oct 11 2007 10:14:58   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.97   Sep 21 2007 15:47:16   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.96   Aug 14 2007 14:09:04   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.95   May 09 2007 10:23:40   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.94   Nov 16 2006 14:59:42   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.93   Nov 13 2006 13:26:18   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.92   Nov 12 2006 17:16:44   tmielke
* v1.79 build 2095 -- messed up version: auto-recording broken
* 
*    Rev 1.91   Jun 12 2006 15:13:20   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.90   Nov 25 2005 01:32:12   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.89   Nov 23 2005 16:11:16   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.88   Nov 11 2005 09:50:54   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.87   Jul 11 2005 08:52:28   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.86   Jul 05 2005 01:50:16   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.85   Jun 28 2005 01:46:22   tmielke
* v1.72 build 1250
* 
*    Rev 1.84   Jun 02 2005 01:30:24   tmielke
* v1.72 build 1207
* 
*    Rev 1.83   May 18 2005 13:47:08   tmielke
* v1.72 build 1200
* 
*    Rev 1.82   Mar 18 2005 16:11:58   tmielke
*  
* 
*    Rev 1.81   Mar 12 2005 07:08:28   tmielke
* v1.69
* 
*    Rev 1.80   Feb 22 2005 16:53:18   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.79   Nov 21 2004 01:29:14   tmielke
* v1.66 build 883
* 
*    Rev 1.78   Dec 04 2003 03:36:40   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.77   Nov 18 2003 09:39:40   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.76   Oct 03 2003 01:22:06   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.75   Sep 23 2003 11:08:26   tmielke
* v1.64 build 557 (improved control tone detection)
* last changes
* 
*    Rev 1.74   Sep 23 2003 01:48:02   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.73   Sep 12 2003 01:12:08   tmielke
*  
* 
*    Rev 1.72   Sep 12 2003 01:11:24   tmielke
* NT40 no CODECS problem fixed
* 
*    Rev 1.69   Sep 04 2003 00:55:24   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.68   Aug 04 2003 00:34:58   tmielke
* v1.64
* 
*    Rev 1.67   Aug 04 2003 00:34:22   tmielke
* optional ALC, corrected spelling, and setup script modification
* 
*    Rev 1.66   Jun 09 2003 15:25:14   tmielke
* v1.63 final
* 
*    Rev 1.65   May 13 2003 04:28:48   tmielke
* IRI problem w. 22kHz samplingr. fixed
* 
*    Rev 1.64   Mar 04 2003 01:13:42   tmielke
* pre release 20 - Actimax manufacturer
* 
*    Rev 1.61   Jan 27 2003 01:14:04   tmielke
* Polish language support
* 
*    Rev 1.60   Jan 26 2003 23:13:12   tmielke
* ?
* 
*    Rev 1.59   Jan 15 2003 16:12:38   tmielke
* v1.63 pre 13
* 
*    Rev 1.58   Dec 31 2002 07:36:30   tmielke
*     - having the lines combo box work with the genius soundcard
*     - changed the way the software stores wav files to solve problems with the Windows multimedia command interface
*     - added comprehensive multimedia command interface error messages
*     - changed the buffering for recording to better work with 11025 Hz samplingrate and others
*  
* 
*    Rev 1.57   Dec 31 2002 04:53:14   tmielke
* auf dem Win98 Rechner gemachte Änderungen
* 
*    Rev 1.56   Dec 18 2002 15:45:44   tmielke
* recording level has no more any time delay
* 
*    Rev 1.55   Nov 28 2002 02:14:36   tmielke
* Some Spanish translations
* 
*    Rev 1.54   Nov 24 2002 01:36:48   tmielke
* Vendor DLL für Ron Telekom, NL Übers. Änderungen
* 
*    Rev 1.53   Nov 20 2002 03:56:00   tmielke
* Dutch language support 
* 
*    Rev 1.52   Oct 25 2002 15:52:18   tmielke
*     - improved userfriendlyness when switching IRI on and off
*     - IRI detection with countdown now
* 
*    Rev 1.51   Oct 25 2002 11:28:30   tmielke
* Sicherheits-CheckIn vor level control auf mixer umgestellt
* 
*    Rev 1.50   Oct 12 2002 00:43:30   tmielke
* - suppressed multiple popup of message box 'Couldn't start recording' and other
* - redesigned the applications frame window which should avoid problems with newer 
*   windows versions
* - fixed IRI recording
* 
*    Rev 1.49   Oct 08 2002 00:30:06   tmielke
* Vor Einbau PrpSheetFrame
* 
*    Rev 1.48   Sep 24 2002 15:13:52   tmielke
* Total vermurxt alles... :(
* 
*    Rev 1.47   Sep 11 2002 20:13:32   tmielke
* Mixer Architektur in hardware screen eingebaut
* 
*    Rev 1.46   Aug 16 2002 20:03:44   tmielke
* control tone
* 
*    Rev 1.45   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.44   May 05 2002 11:56:10   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.43   Apr 19 2002 07:27:24   tmielke
* Czech translation added
* 
*    Rev 1.42   Mar 15 2002 20:21:30   tmielke
* v1.60
* 
*    Rev 1.41   Nov 07 2001 02:08:08   tmielke
* v1.59 bugfix release
* 
*    Rev 1.40   Nov 06 2001 05:26:44   tmielke
* v1.58a
* 
*    Rev 1.39   Oct 12 2001 16:22:38   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.38   Sep 14 2001 04:12:26   
* v1.57
* 
*    Rev 1.37   20 Jul 2001 02:29:42   tmielke
* v1.56
* 
*    Rev 1.36   06 Jun 2001 01:59:58   tmielke
* offizielle release 1.55
* 
*    Rev 1.35   17 May 2001 02:01:00   tmielke
* v1.54
* 
*    Rev 1.34   17 May 2001 00:34:50   tmielke
* Spanische Sprach-DLL hinzugefügt
*
*    Rev 1.33   12 Feb 2001 19:36:42   tmielke
* v1.53
*
*    Rev 1.32   20 Dec 2000 18:14:46   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
*
*    Rev 1.31   04 Dec 2000 02:22:46   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
*
*    Rev 1.30   19 Oct 2000 02:28:32   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
*
*
*    Rev 1.29   18 Oct 2000 20:34:22   tmielke
* Alpha version ALC
*
*    Rev 1.28   19 Jun 2000 15:53:58   tmielke
* v1.44 letzte TRS-Version
*
*    Rev 1.27   24 Mar 2000 22:36:08   tmielke
* v1.44 encrypting im hintergrund
*
*    Rev 1.26   18 Mar 2000 11:40:08   tmielke
* zur sicherheit eingecheckt
*
*    Rev 1.25   17 Mar 2000 05:31:42   tmielke
* v1.6 jetzt tauglich für Österreich/Schweiz
*
*    Rev 1.24   05 Mar 2000 05:20:42   tmielke
* v1.43
*
*    Rev 1.23   28 Feb 2000 00:30:28   tmielke
* v1.42
*
*    Rev 1.22   24 Feb 2000 15:27:44   tmielke
* v1.41
*
*    Rev 1.21   24 Feb 2000 01:22:34   tmielke
* v1.39
*
*    Rev 1.20   18 Feb 2000 00:38:42   tmielke
* v1.38
*
*    Rev 1.19   15 Dec 1999 03:33:32   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
*
*    Rev 1.18   01 Dec 1999 18:45:14   tmielke
* v1.36 BPS -> Frohberg GmbH
*
*    Rev 1.17   16 Aug 1999 10:31:36   tmielke
* v1.34
*
*    Rev 1.16   09 Aug 1999 07:50:56   tmielke
* Encryption eingebaut
*
*    Rev 1.15   07 Jun 1999 19:09:02   tmielke
* Multi Language version number update: v1.33
*
*    Rev 1.14   05 Apr 1999 08:16:16   tmielke
* sync
*
*    Rev 1.13   20 Mar 1999 18:51:54   tmielke
* v1.3
*
*    Rev 1.12   20 Mar 1999 17:50:10   tmielke
* Fehler in Zeile 2290: (delete pwfx) wurde bei PCM ausgelöst
*
*    Rev 1.11   18 Mar 1999 13:28:34   tmielke
* v0.8 - Demoversion fertig gemacht
*
*    Rev 1.10   03 Mar 1999 13:40:46   tmielke
* Version Label v0.6
*
*    Rev 1.9   03 Mar 1999 12:06:38   tmielke
* Speicherleck gekittet.
*
*    Rev 1.8   28 Feb 1999 09:19:44   tmielke
* Leitungspegel-Automatik eingebaut.
*
*    Rev 1.7   28 Feb 1999 07:05:42   tmielke
* Aufnahmepegel eingebaut.
* Monitor Modus eingebaut.
*
*    Rev 1.6   28 Feb 1999 01:10:02   tmielke
* Dateiheader/keywords verschönert
*
*    Rev 1.5   28 Feb 1999 01:07:58   tmielke
*
* keywords hinzugefügt
*
*/

#define _CRT_SECURE_NO_WARNINGS

#ifdef _DEBUG
//#include "..\stdafx.h"
#define TRACE0(a) ::OutputDebugString(a)
#define TRACE1(a,b) { char buffer[10000]; sprintf(buffer, a, b); ::OutputDebugString(buffer); }
#define TRACE2(a,b,c) { char buffer[10000]; sprintf(buffer, a, b, c); ::OutputDebugString(buffer); }
#define TRACE3(a,b,c,d) { char buffer[10000]; sprintf(buffer, a, b, c, d); ::OutputDebugString(buffer); }
#endif

#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <mmreg.h>
#include <msacm.h>	// Audio Compression Manager
#include <math.h>

#define WaveIn_Export
#include "WaveIn.h"

// Daten zum Öffnen des Wave-Devices:
static HWAVEIN hwi = NULL;
static WAVEFORMATEX wfx;
static WAVEFORMATEX wfx_mono;
static DWORD_PTR dwCallback;
static DWORD_PTR dwCallbackInstance;
static DWORD_PTR fdwOpen;
static DWORD_PTR codec_id;
static DWORD_PTR format_info;
static BOOL bMonitorModus;
static BOOL bMessageShown = 0;

// Statistik-Daten:
static int nUeberlaeufe = 0;
static int nRatio = 0;
static int nMaxPeak = 0;
static int nMinPeak = 0;

// Multi-Buffering zum Abspielen der Waves: 20 x 1/10 sec.
#define ANZAHL_WAVE_IT_BUFFER 4
static struct {
	HGLOBAL	hMem;
	BYTE far	*pMem;
	WAVEHDR	wh;
	HWND hWnd;
	BOOL bReallocatable;
} wave_it[ANZAHL_WAVE_IT_BUFFER];
BOOL bRecreateBuffers = TRUE;

// wav file attributes
static FILE *fp = NULL;
static DWORD GesamtlaengeOffset;
static DWORD DatenlaengeOffset;
static int dwDataSize = 0L;

// DLL instance handle
static HINSTANCE WaveIn_Instance = NULL;
CRITICAL_SECTION waveInMutex;

// Init instance of dll
BOOL APIENTRY DllMain(HANDLE hModule, 
                      DWORD  ul_reason_for_call, 
                      LPVOID lpReserved)
{
    switch( ul_reason_for_call ) {
    case DLL_PROCESS_ATTACH:
		WaveIn_Instance = (HINSTANCE)hModule;
		InitializeCriticalSection(&waveInMutex);
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		DeleteCriticalSection(&waveInMutex);
		break;
    }
    return TRUE;
}

/* old-style dll entry point
int FAR PASCAL LibMain (HINSTANCE hInst, WORD wDataSeg,
                       WORD cbHeapSize, LPSTR lpszNotUsed)
{
	WaveIn_Instance = hInst;

	return 1;
}
*/

// language used for messages 0=D 1=GB 2=E
static int language = 0;

DllTrade void WaveIn_SetLanguage(int lang)
{
	language = lang;
}

// parent window handle used for messages 0=D 1=GB
HWND hParentWnd = NULL;

DllTrade void WaveIn_SetHWND(DWORD hWnd)
{
	hParentWnd = (HWND)hWnd;
}

// Fehlerhandling:
static BOOL MMCheck(MMRESULT result, int line)
{
	if (result != MMSYSERR_NOERROR)
	{
		char buffer[1000], buffer2[1000];
		waveInGetErrorText(result, buffer, sizeof(buffer));
		sprintf(buffer2, "WAVEIN.DLL code %d ", line);
		strcat(buffer2, __DATE__);
		if (!bMessageShown)
		{
			bMessageShown = TRUE;
			MessageBox(hParentWnd, buffer, buffer2, MB_OK | MB_ICONSTOP | MB_TASKMODAL);
			bMessageShown = FALSE;
		}
#ifdef _DEBUG
		else
		{
			strcat(buffer, "\n");
			TRACE0(buffer);
		}
#endif
		return FALSE;
	}
	return TRUE;
}

// auto recording level control FALSE=aus TRUE=ein
static BOOL alc = FALSE;
// control tones vom super modular connector FALSE=aus TRUE=ein
static BOOL control_tone = FALSE;
static int control_tone_channel = 0;
static int control_tone_active = 0;
static BOOL control_tone_warning = FALSE;
static int control_tone_warning_counter = 0;	// see IRI_WARNING_AFTER
static BOOL probe_control_tone_channel_mode = FALSE;
static int probe_control_tone_channel_result = -1; // -1: noch kein ergebnis, 0: kein Signal, 1: linker Kanal 2: rechter Kanal 3: beide Kanäle
static int nullabgleich_akt = 0; // aktueller offset zum Signal
static int nullabgleich_ziel = 0; // Ziel- oder Soll-offset zum Signal
static int verstaerkungsfaktor_akt = 65536; // 65536 = einfache Verstärkung
static int verstaerkungsfaktor_ziel = 65536; // Ziel- oder Soll-Verstärkung
static BOOL mute_microphone = FALSE;
#define MAX_SIGNAL 32767		// max. physikalisch mögliches Signal
#define MAX_ABS_VERSTAERKUNG 75 // auf max. 75% des physikalisch möglichen Signals verstärken (== +-24575)
#define MAX_REL_VERSTAERKUNG 8 // auf max. das 8fache des urspr. Signals verstärken (verstaerkungsfaktor_akt == 655360)
#define LAENGE_DER_RAMPE 10 // eine 10tel Sekunde
#define IRI_WARNING_AFTER 50 // Warnung wenn innerhalb von 5 Sekunden (50 Buffern) kein IRI Signal

DllTrade void WaveIn_SetALC(BOOL alc_param)
{
	alc = alc_param;
}

DllTrade void WaveIn_SetControlTone(BOOL control_tone_param)
{
	control_tone = control_tone_param;
}

DllTrade void WaveIn_SetControlToneChannel(int control_tone_channel_param)
{
	control_tone_channel = control_tone_channel_param;
}

// probe_control_tone_channel_mode_param == TRUE: anfangen FALSE: beenden
DllTrade void WaveIn_ProbeControlToneChannel(BOOL probe_control_tone_channel_mode_param)
{
	probe_control_tone_channel_mode = probe_control_tone_channel_mode_param;
	probe_control_tone_channel_result = -1;
}

// probe_control_tone_channel_mode abfragen
DllTrade int WaveIn_GetProbeControlToneChannelResult()
{
	return probe_control_tone_channel_result;
}

// probe control tone according to control_tone_channel
DllTrade BOOL WaveIn_IsActiveControlTone()
{
	return control_tone_active;
}

DllTrade BOOL WaveIn_GetControlToneWarning()
{
	return control_tone_warning;
}

// device handle abfragen
DllTrade HWAVEIN WaveIn_GetDeviceHandle()
{
	return hwi;
}

DllTrade void WaveIn_MuteMicrophone()
{
	mute_microphone = TRUE;
}

DllTrade void WaveIn_OpenMicrophone()
{
	mute_microphone = FALSE;
}

// some static prototypes
static BOOL PrepBuffer(int i);
static void UnprepBuffer(int i);
static WAVEFORMATEX* ConvertOpen();
static BOOL ConvertBuffer(BYTE *pSrcData, DWORD SrcBytes, BYTE **ppDst, DWORD *pDstBytes);
static void ConvertClose();

// wenn filename == NULL : öffnen im Monitor-Modus
DllTrade BOOL WaveIn_Open(char *filename, unsigned int device, int channels, int samplerate, int bitspersample, DWORD_PTR codec, DWORD_PTR format)
{
#ifdef _DEBUG
	char dbgbuf[3000];
	sprintf(dbgbuf, "WaveIn_Open(filename=\"%s\", device=%u, channels=%d, bitspersample=%d, codec=%u, format=%d)\n", filename, device, channels, bitspersample, codec, format);
	TRACE0(dbgbuf);
#endif
	int i;
	int n;
	MMRESULT result;

	if (!filename)
	{
		bMonitorModus = TRUE;
		codec_id = (unsigned)-1L;
	}
	else
	{
		bMonitorModus = FALSE;

		// ALC zurücksetzen:
		nullabgleich_akt = 0; // aktueller offset zum Signal
		nullabgleich_ziel = 0; // Ziel- oder Soll-offset zum Signal
		verstaerkungsfaktor_akt = 65536; // 65536 = einfache Verstärkung
		verstaerkungsfaktor_ziel = 65536; // Ziel- oder Soll-Verstärkung
	}

	codec_id = codec;
	format_info = format;

	// Wave-Struktur aufbereiten ...
	wfx.wFormatTag = WAVE_FORMAT_PCM;					// Standard
	wfx.nChannels = channels + (control_tone ? 1 : 0);	// mono/stereo?
	wfx.nSamplesPerSec = samplerate;
	wfx.wBitsPerSample = bitspersample;
	wfx.nBlockAlign = wfx.nChannels * (wfx.wBitsPerSample / 8); // should allwazs be equal to the product of nChannels and wBitsPerSample divided by 8 (bits per byte). 
		      // old; (wfx.wBitsPerSample+7) / 8 * (channels + (control_tone ? 1 : 0));	// = wBitsPerSample / 8   aufgerundet
	wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;	// = nSamplesPerSec * wBitsPerSample / 8 * Channels
	wfx.cbSize = 0;						// zusätzliche Daten wenn wFormatTag != PCM

	dwDataSize = 0L;
	bRecreateBuffers = TRUE;

	// copy & transform waveformat for a mono version of the format
	memcpy(&wfx_mono, &wfx, sizeof(WAVEFORMATEX));
	wfx_mono.nAvgBytesPerSec /= wfx.nChannels;
	wfx_mono.nBlockAlign /= wfx.nChannels;
	wfx_mono.nChannels = 1;
	
	// wenn schon ein handle geöffnet ist, dann vor nem neu-öffnen erstmal schließen...
	if (hwi)
		WaveIn_Close();

	// alle Ausgabepuffer als leer markieren
	for (i = 0; i < ANZAHL_WAVE_IT_BUFFER; i++)
		wave_it[i].hMem = 0;

	// Device-Handle zurücksetzen
	hwi = (HWAVEIN)device;

	// wenn mindestens ein Device vorhanden
	if (n = waveInGetNumDevs())
	{
		// Wave-Device öffnen
		{
			EnterCriticalSection(&waveInMutex);
			dwCallback = (DWORD_PTR)WaveInFunc;		// meine Callback-Funktion
			dwCallbackInstance = (DWORD_PTR)WaveIn_Instance;	// Instance-Handle dieser DLL
			fdwOpen = CALLBACK_FUNCTION;
			result = waveInOpen(&hwi, device, &wfx, dwCallback,
								 dwCallbackInstance, fdwOpen);			// und Feuer!!!
			LeaveCriticalSection(&waveInMutex);

			if (!MMCheck(result, __LINE__))
			{
				hwi = NULL;
				return FALSE;
			}
		}
	}
	else
	{
		hwi = NULL;
		return FALSE;
	}

	// Buffer reservieren und preparieren
	{
		// alle buffer preparieren:
		for (i = 0; i < ANZAHL_WAVE_IT_BUFFER; i++)
		{
			if (!wave_it[i].hMem)
				if (PrepBuffer(i))
					MMCheck(waveInAddBuffer(hwi, &(wave_it[i].wh), sizeof(wave_it[i].wh)), __LINE__);

		}
	}

	// close file if open
	if (fp) fclose(fp);
	fp = NULL;

	// auch bei control_tone nur einen Kanal abspeichern
//	wfx.nChannels = channels;
//	wfx.nBlockAlign = (bitspersample+7) / 8;	// = wBitsPerSample / 8   aufgerundet
//	wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;

	if (!bMonitorModus)
	{
		// open file for write
		fp = fopen(filename, "wb");
		if (!fp)
		{
			WaveIn_Close();
			if (!bMessageShown)
			{
				bMessageShown = TRUE;
				switch (language)
				{
				case WAVEIN_LANG_D:
					MessageBox(hParentWnd, "Fehler beim Öffnen der Datei", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				default:
				case WAVEIN_LANG_GB:
					MessageBox(hParentWnd, "File open error", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_E:
					MessageBox(hParentWnd, "Error fichero abierto", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_CZ:
					MessageBox(hParentWnd, "Chyba pri otevírání souboru", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_NL:
					MessageBox(hParentWnd, "Fout: bestand open", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_PL:
					MessageBox(hParentWnd, "Blad otwarcia pliku", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				}
				bMessageShown = FALSE;
			}
			return FALSE;
		}

		// write wav format header
		{
			char buffer[1000];
			DWORD *pdw = (DWORD *)buffer;

			*pdw++ = mmioFOURCC('R', 'I', 'F', 'F');
			GesamtlaengeOffset = (DWORD)pdw - (DWORD)buffer;
			*pdw++ = 0L; // Gesamtlänge wird bei Close eingetragen
			*pdw++ = mmioFOURCC('W', 'A', 'V', 'E');

			// format chunk
			*pdw++ = mmioFOURCC('f', 'm', 't', ' ');	// jetzt kommt WAVEFORMAT-Header

			// wenn genaus so gespeichert werden soll, wie aufgenommen wurde ...
			WAVEFORMATEX *pwfx;
			if ((long)codec_id == -1L)
			{// den Original-WAVEFORMAT-Header benutzen
				pwfx = &wfx;

				// wf (ohne ex) ergänzen, d.h. die Längenangabe des
				// extended headers wird ignoriert in der Datei
				*pdw++ = sizeof(*pwfx) - sizeof(pwfx->cbSize);
				memcpy(pdw, pwfx, sizeof(*pwfx) - sizeof(pwfx->cbSize));
				pdw  = (DWORD *)((char *)pdw + sizeof(*pwfx) - sizeof(pwfx->cbSize));
			}
			else
			{// sonst den Ziel-CODEC-WAVEFORMAT-Header benutzen
				if (!(pwfx = ConvertOpen()))
				{
					WaveIn_Close();
					//fclose(fp);
					//waveInClose(hwi);
					//hwi = NULL;
					return NULL;
				}

				// den vollen wfex ergänzen
				*pdw++ = sizeof(*pwfx) + pwfx->cbSize;
				memcpy(pdw, pwfx, sizeof(*pwfx) + pwfx->cbSize);
				pdw  = (DWORD *)((char *)pdw + sizeof(*pwfx) + pwfx->cbSize);
			}

			if ((long)codec_id != -1L)
			{
				// wurde in ConvertOpen gemalloct
				delete (pwfx);
			}

			// pcm daten chunk
			*pdw++ = mmioFOURCC('d', 'a', 't', 'a');
			DatenlaengeOffset = (DWORD)pdw - (DWORD)buffer;
			*pdw++ = 0; // Länge der PCM daten wird bei Close eingetragen

			// unvollständigen header schreiben
			if (fwrite(buffer, (DWORD)pdw - (DWORD)buffer, 1, fp) != 1)
			{
				WaveIn_Close();
				//fclose(fp);
				//waveInClose(hwi);
				//hwi = NULL;
				return NULL;
			}

		}
	}

	return TRUE;
}

DllTrade void WaveIn_Close()
{
#ifdef _DEBUG
	if (!hwi) 
		TRACE0("WaveIn_Close(): WaveIn-Handle == NULL!\n");
	else
		TRACE0("WaveIn_Close\n");

#endif
	if (!hwi)
	{
	/*	if (!bMonitorModus)
		{
			// close file if open
			if (fp) fclose(fp);
			fp = NULL;
		}
	*/
		return;
	}

	bRecreateBuffers = FALSE;

	MMCheck(waveInReset(hwi), __LINE__);

	for (int i = 0; i < ANZAHL_WAVE_IT_BUFFER; i++)
		UnprepBuffer(i);

	MMCheck(waveInClose(hwi), __LINE__);

	if (!bMonitorModus)
	{
		// Complete file header with length information
		if (dwDataSize && fp)
		{
			fpos_t file_len;
			DWORD l;
			BOOL result = TRUE;

			if (fgetpos(fp, &file_len))
			{
				file_len = (fpos_t)0;
			}
			else
			{
				if (!fseek(fp, GesamtlaengeOffset, SEEK_SET))
				{
					l = (DWORD)(file_len - sizeof(DWORD) - GesamtlaengeOffset);
					fwrite((char *)&l, sizeof(DWORD), 1, fp);
				}

				if (!fseek(fp, DatenlaengeOffset, SEEK_SET))
				{
					l = (DWORD)(file_len - sizeof(DWORD) - DatenlaengeOffset);
					fwrite((char *)&l, sizeof(DWORD), 1, fp);
				}
			}
		}

		// close file if open
		if (fp) fclose(fp);
		fp = NULL;
	}

	if ((long)codec_id != -1L && !bMonitorModus)
		ConvertClose();

	hwi = NULL;
}

DllTrade void WaveIn_Start()
{
#ifdef _DEBUG
	if (!hwi) 
		TRACE0("WaveIn_Start(): WaveIn-Handle == NULL!\n");
	else
		TRACE0("WaveIn_Start()\n");
#endif
	if (!hwi) return;

	bRecreateBuffers = TRUE;
	MMCheck(waveInStart(hwi), __LINE__);
}

DllTrade void WaveIn_Stop()
{
#ifdef _DEBUG
	if (!hwi) 
		TRACE0("WaveIn_Stop(): WaveIn-Handle == NULL!\n");
	else
		TRACE0("WaveIn_Stop()\n");
#endif
	if (!hwi) return;

	bRecreateBuffers = FALSE;
	MMCheck(waveInReset(hwi), __LINE__);
	MMCheck(waveInStop(hwi), __LINE__);
}

DllTrade void WaveIn_Stats(int *kr, int *ul, int *al)
{
	*kr = nRatio;
	*ul = nUeberlaeufe;

	// n zählt freie Puffer
	int n = 0;
	for (int i = 0; i < ANZAHL_WAVE_IT_BUFFER; i++)
		if (wave_it[i].bReallocatable || !wave_it[i].wh.dwBytesRecorded) n++;
	*al = 100 - (100 * n / ANZAHL_WAVE_IT_BUFFER);
}

DllTrade void WaveIn_Peaks(int *pnMaxPeak, int *pnMinPeak)
{
	*pnMaxPeak = nMaxPeak;
	*pnMinPeak = nMinPeak;

	// evtl. bytes auf words strecken
	if (wfx.wBitsPerSample <= 8)
	{
		*pnMaxPeak <<= 8;
		*pnMinPeak <<= 8;
	}
}

// return: 0 - nichts gefunden; 1 - 550Hz-inaktiv-Ton; 2 - 900Hz-aktiv-Ton
// max amplitude is written to parameter level
static int DetectControlTone(int channel, int x, WAVEHDR* whx, int *max_level)
{										// x = Nummer des Buffers, whx = Waveheader Daten
	if (wfx.nChannels != 2) return 0;
	
	BYTE *bp = wave_it[x].pMem	// start of audio data
		+ ((whx->dwBytesRecorded / 2) / wfx.nBlockAlign * wfx.nBlockAlign)	// only check half of the audio data, starting in the middle, and make sure it is block-aligned
		+ (channel * (wfx.wBitsPerSample / 8)); // add offset if right channel (1)
	BYTE *bp_end = wave_it[x].pMem + whx->dwBytesRecorded;
	int   bp_inc = (wfx.wBitsPerSample / 8) * wfx.nChannels;
	int sample;						// aktueller sample-Wert
	int akt_anzahl_samples = 0;		// ... die über 0 liegen
	int min_anzahl_samples = 48000;	// ... die über 0 liegen
	int max_anzahl_samples = 0;		// ... die über 0 liegen
	int min_sample_level = 32767;	// zur Berechnung von *max_level
	int max_sample_level = -32768;	// - '' -
	BOOL bUeberNull = FALSE;
	int	normalization_offset;

	BYTE *save_bp = bp;	// save start pointer value bp
	while (bp < bp_end)
	{
		// samples zählen, die jeweils pro Schwingung über 0 liegen
		if (wfx.wBitsPerSample / 8 == 1)
		{	// byte samples
			sample = *(signed char *)bp;
		}
		else
		{	// word samples
			sample = *(signed short *)bp;
		}

		if (sample < min_sample_level) min_sample_level = sample;
		if (sample > max_sample_level) max_sample_level = sample;

		bp += bp_inc;
	}
	bp = save_bp;	// restore start pointer value bp
	normalization_offset = (max_sample_level + min_sample_level) / 2;	// compute normalization offset
	sample -= normalization_offset;	// normalize
	*max_level = max_sample_level - normalization_offset;	// return signal level	

	// erste Halbwelle überspringen
	while (bp < bp_end)
	{
		// samples zählen, die jeweils pro Schwingung über 0 liegen
		if (wfx.wBitsPerSample / 8 == 1)
		{	// byte samples
			sample = *(signed char *)bp;
		}
		else
		{	// word samples
			sample = *(signed short *)bp;
		}
		sample -= normalization_offset;	// normalize

		if (sample >= 0) break;

		bp += bp_inc;
	}

	// zweite Halbwelle überspringen
	while (bp < bp_end)
	{
		// samples zählen, die jeweils pro Schwingung über 0 liegen
		if (wfx.wBitsPerSample / 8 == 1)
		{	// byte samples
			sample = *(signed char *)bp;
		}
		else
		{	// word samples
			sample = *(signed short *)bp;
		}
		sample -= normalization_offset;	// normalize

		if (sample < 0) break;

		bp += bp_inc;
	}

	while (bp < bp_end)
	{
		// samples zählen, die jeweils pro Schwingung über 0 liegen
		if (wfx.wBitsPerSample / 8 == 1)
		{	// byte samples
			sample = *(signed char *)bp;
		}
		else
		{	// word samples
			sample = *(signed short *)bp;
		}
		sample -= normalization_offset;	// normalize

		if (sample >= 0)
		{
			if (!bUeberNull) 
			{
				akt_anzahl_samples = 0;	// Zähler am Anfang der Halbschwingung zurücksetzen
				bUeberNull = TRUE;
			}
			akt_anzahl_samples++;
		}
		else
		{
			if (bUeberNull) 
			{
				// Zähler am Ende der Halbwelle mit min_anzahl_samples abgleichen
				if (akt_anzahl_samples < min_anzahl_samples) min_anzahl_samples = akt_anzahl_samples;
				if (akt_anzahl_samples > max_anzahl_samples) max_anzahl_samples = akt_anzahl_samples;
				
				bUeberNull = FALSE;
			}			
		}

		bp += bp_inc;
	}

	if (max_anzahl_samples >= min_anzahl_samples)	// gültig?
	{
		// 1 Schwingung besteht aus Samplingrate / Schwingungsfrequenz Schwingungen
		// hiervon die Hälfte ist die durchschn. Anzahl Samples pro Halbschwingung
		int probe_samples = wfx.nSamplesPerSec / 900 / 2;	// 900 Hz control tone
		// 20% + 1 Sample als Toleranz...
		if (min_anzahl_samples >= probe_samples - probe_samples/3 - 1
			&& max_anzahl_samples <= probe_samples + probe_samples/7 + 1)
		{
#ifdef _DEBUG
			TRACE0("DetectControlTone() hat 900-Hz-aktiv-Ton erkannt\n");
#endif
			return 2;
		}

		// 550-Hz-inaktiv-Ton testen
		probe_samples = wfx.nSamplesPerSec / 550 / 2;	// 550 Hz control tone
		if (min_anzahl_samples >= probe_samples - probe_samples/5 - 1
			&& max_anzahl_samples <= probe_samples + probe_samples/5 + 1) 
		{
#ifdef _DEBUG
			TRACE0("DetectControlTone() hat 550-Hz-inaktiv-Ton erkannt\n");
#endif
			return 1;
		}
	}


#ifdef _DEBUG
	TRACE0("DetectControlTone() hat nichts erkannt\n");
#endif
	// nichts erkannt:
	return 0;
}

// RETURN: TRUE wenn erfolgreich den Sprachkanal dupliziert
static BOOL ConvertBufferToMono(int x, WAVEHDR* whx)
{
	if (wfx.nChannels != 2 || !control_tone) 
	{
#ifdef _DEBUG
		TRACE0("ConvertBufferToMono(): return FALSE\n");
#endif
		return FALSE;
	}
#ifdef _DEBUG
	TRACE0("ConvertBufferToMono()\n");
#endif

	BYTE *bp  = wave_it[x].pMem + ((!control_tone_channel)*(wfx.wBitsPerSample / 8));	// source
	BYTE *bp2 = wave_it[x].pMem;														// destination
	BYTE *bp_end  = wave_it[x].pMem + whx->dwBytesRecorded;
	BYTE *bp2_end = wave_it[x].pMem + whx->dwBytesRecorded / wfx.nChannels;	// mono buffer ist half in size
	int   bp_inc  = wfx.wBitsPerSample / 8 * wfx.nChannels;
	int   bp2_inc = wfx.wBitsPerSample / 8;

	while (bp < bp_end)
	{
		if (wfx.wBitsPerSample == 16)
			*(signed short *)bp2 = *(signed short *)bp;
		else
			*bp2 = *bp;

		bp  +=  bp_inc;
		bp2 +=  bp2_inc;
	}

	// copy & transform waveheader:
	whx->dwBytesRecorded /= wfx.nChannels;

	return TRUE;
}

// Call this function from timer event or MYWM_REALLOCATE_WAVEIN_BUFFER message handler
DllTrade BOOL WaveIn_ReallocBuffer()
{
	int i;

#ifdef _DEBUG
	if (!hwi) 
		TRACE0("WaveIn_ReallocBuffer(): WaveIn-Handle == NULL!\n");
	else
		TRACE0("WaveIn_ReallocBuffer()\n");
#endif
	if (!hwi) return FALSE;

	for (i = 0; i < ANZAHL_WAVE_IT_BUFFER; i++)
		if (wave_it[i].bReallocatable)
		{
			EnterCriticalSection(&waveInMutex);
			if (bRecreateBuffers)
			{
				// MMCheck(waveInUnprepareHeader(hwi, &wave_it[i].wh, sizeof(WAVEHDR)), __LINE__);
				// memset(&wave_it[i], 0, sizeof(WAVEHDR));
				// MMCheck(waveInUnprepareHeader(hwi, &wave_it[i].wh, sizeof(WAVEHDR)), __LINE__);
				wave_it[i].bReallocatable = FALSE;
				wave_it[i].wh.dwBytesRecorded = 0;
				MMCheck(waveInAddBuffer(hwi, &wave_it[i].wh, sizeof(WAVEHDR)), __LINE__);
#ifdef _DEBUG
				TRACE1("buffer #%d\n", i);
#endif
			}
			LeaveCriticalSection(&waveInMutex);
		}

		return TRUE;
}

static BOOL PrepBuffer(int i)
{
#ifdef _DEBUG
	TRACE1("PrepBuffer(%d)\n", i);
#endif

	BOOL bReturn = FALSE;
	EnterCriticalSection(&waveInMutex);

	// speicher holen:
	wave_it[i].hMem = GlobalAlloc(GMEM_MOVEABLE, wfx.nAvgBytesPerSec / 10 / 4 * 4);	//  / 4 * 4: dafür sorgen, dass Buffer eine durch 4 teilbare Länge erhält
	if (wave_it[i].hMem)
	{
		wave_it[i].pMem = (BYTE *)GlobalLock(wave_it[i].hMem);
		wave_it[i].bReallocatable = FALSE;

		// Wave-Block Buffer vorbereiten....
		{
			wave_it[i].wh.lpData = (char *)wave_it[i].pMem;   // address of the waveform buffer
			wave_it[i].wh.dwBufferLength = wfx.nAvgBytesPerSec / 10 / 4 * 4;   // length, in bytes, of the buffer - 1 buffer == 1/10 sec
			wave_it[i].wh.dwBytesRecorded = 0;      // only used by waveIn
			wave_it[i].wh.dwUser = (DWORD)i;     // 32 bits of user data - not needed yet
			wave_it[i].wh.dwFlags = 0;
			wave_it[i].wh.dwLoops = 0;              // see below
			wave_it[i].wh.lpNext = 0;				// reserved; must be zero
			wave_it[i].wh.reserved = 0;             // reserved; must be zero
			bReturn = MMCheck(waveInPrepareHeader(hwi, &wave_it[i].wh, sizeof(wave_it[i].wh)), __LINE__);
		}
	}
	LeaveCriticalSection(&waveInMutex);

	return bReturn;
}

// releases PCM wave block (called by callback)
static void UnprepBuffer(int i)
{
#ifdef _DEBUG
	TRACE1("UnprepBuffer(%d)\n", i);
#endif
	
	///////////////////////
	if (wave_it[i].hMem == NULL) MessageBox(hParentWnd, "wave_it[i].hMem == NULL", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);

	EnterCriticalSection(&waveInMutex);

	MMCheck(waveInUnprepareHeader(hwi, &wave_it[i].wh, sizeof(wave_it[i].wh)), __LINE__);

	GlobalUnlock(wave_it[i].hMem);
	GlobalFree(wave_it[i].hMem);
	wave_it[i].hMem = NULL;

	LeaveCriticalSection(&waveInMutex);
}


static int sine_pos = 0;	// remember phase of the mute sine tone
#define MUTE_FREQUENCY 800
#define MUTE_AMPLITUDE 10000

void CALLBACK  WaveInFunc(HWAVEIN	hWaveIn,
						  UINT		wMsg,
						  DWORD_PTR	dwInstance,
						  DWORD_PTR	dwParam1,
						  DWORD_PTR	dwParam2)
{
	//MMRESULT result;

	switch (wMsg)
	{
	case WIM_CLOSE: // Sent when the device is closed using the waveInClose function.

#ifdef _DEBUG
		TRACE0("WaveInFunc() WIM_CLOSE\n");
#endif
		break;

	case WIM_DATA: // Sent when the device driver is finished with a data block sent using the waveInAddBuffer function.

#ifdef _DEBUG
		TRACE0("WaveInFunc() WIM_DATA\n");
#endif
		{
			int x = ((WAVEHDR*)dwParam1)->dwUser;
			WAVEHDR* whx = (WAVEHDR*)dwParam1;

			if ((fp || bMonitorModus) && ((WAVEHDR*)dwParam1)->dwBytesRecorded)
			{
				BYTE *p;
				DWORD dw;

				// monitor peak
				{
					int nMaxPeak2 = -32768;
					int nMinPeak2 = 32767;
					BYTE *bp;
					int   bp_inc;
					if (control_tone)	// wenn control tone, dann den signal-channel nicht bei der peak berechnung berücksichtigen
					{
						bp = wave_it[x].pMem + (!control_tone_channel * (wfx.wBitsPerSample / 8));
						bp_inc = (wfx.wBitsPerSample / 8) * wfx.nChannels;
					}
					else
					{
						bp = wave_it[x].pMem;
						bp_inc = wfx.wBitsPerSample / 8;
					}
					BYTE *bp_end = wave_it[x].pMem + whx->dwBytesRecorded;
					
					while (bp < bp_end)
					{
						if (wfx.wBitsPerSample / 8 == 1)
						{	// byte samples
							if (nMinPeak2 > *(signed char *)bp) nMinPeak2 = *(signed char *)bp;
							if (nMaxPeak2 < *(signed char *)bp) nMaxPeak2 = *(signed char *)bp;
						}
						else
						{	// word samples
							if (nMinPeak2 > *(signed short *)bp) nMinPeak2 = *(signed short *)bp;
							if (nMaxPeak2 < *(signed short *)bp) nMaxPeak2 = *(signed short *)bp;
						}
						bp += bp_inc;
					}
					nMaxPeak = nMaxPeak2;
					nMinPeak = nMinPeak2;
				}

				// herausfinden, auf welchem Kanal der control tone liegt
				if (probe_control_tone_channel_mode && wfx.nChannels == 2)	//  + (control_tone ? 1 : 0)
				{
					int left_result, right_result, left_level, right_level;
					left_result = DetectControlTone(0, x, whx, &left_level);	// links
					right_result = (DetectControlTone(1, x, whx, &right_level) << 2);	// rechts
					probe_control_tone_channel_result = 0;
					if (left_result && right_result)	// if there is a signal from both channels, decide by considering the signal level
					{
						if (left_level > right_level)
							probe_control_tone_channel_result = left_result;
						else
							probe_control_tone_channel_result = right_result;
					}
					if (left_result) probe_control_tone_channel_result = left_result;
					if (right_result) probe_control_tone_channel_result = right_result;
					
					control_tone_warning = FALSE;
				}

				// auf einem bestimmten kanal nach dem control tone suchen
				if (control_tone)
				{
					int signal_level; // we don't use it in the moment

					int n =	DetectControlTone(control_tone_channel, x, whx, &signal_level);
					if (n & 2) control_tone_active = TRUE;
					if (n & 1) control_tone_active = FALSE;
					if (!n)
						control_tone_warning_counter++;
					else
						control_tone_warning_counter = 0;


					if (control_tone_warning_counter > IRI_WARNING_AFTER)
						control_tone_warning = TRUE;
					else
						control_tone_warning = FALSE;

				}
				else
					control_tone_warning = FALSE;
				
				// Mute Funktion
				if (!mute_microphone) sine_pos = 0;
				if (!bMonitorModus && mute_microphone)
				{
					BYTE *bp = wave_it[x].pMem;
					BYTE *bp_end = wave_it[x].pMem + whx->dwBytesRecorded;
					int   bp_inc = wfx.wBitsPerSample / 8;

					while (bp < bp_end)
					{
						float sine_value = sin((float) sine_pos++ * MUTE_FREQUENCY / wfx.nSamplesPerSec);
						if (sine_pos > (int)(wfx.nSamplesPerSec / MUTE_FREQUENCY)) sine_pos = 0;					

						if (wfx.wBitsPerSample == 16)	// 16-bit recording
						{
							*(signed short *)bp = (signed short)(sine_value * MUTE_AMPLITUDE);
							bp += 2;
						}
						else
							*bp++ = (signed char)(sine_value * MUTE_AMPLITUDE / 256);					// 8-bit recording
					}
				}
				else
				// Auto Level Control (nur für 16bit-Aufzeichnungen zulassen)
				if (alc && wfx.wBitsPerSample == 16 && (nMaxPeak | nMinPeak))
				{										// doppelte Sicherheit gegen div-by-zero-exception
					BYTE *bp = wave_it[x].pMem;
					BYTE *bp_end = wave_it[x].pMem + whx->dwBytesRecorded;
					int   bp_inc = wfx.wBitsPerSample / 8;

					// aktuellen Verstärkungsfaktor und Signal-offset merken (egal, ob Ziele bereits erreicht wurden)
					int nullabgleich_alt = nullabgleich_akt;
					int verstaerkungsfaktor_alt = verstaerkungsfaktor_akt;
if (!bp_inc) MessageBox(hParentWnd, "Please report this message to retell support: bp_inc", NULL, MB_OK);
					// Anzahl Schritte, die benötigt werden, um die Länge der Rampe abzuarbeiten
					int schritte_um_anzupassen = (bp_end - bp) / bp_inc / LAENGE_DER_RAMPE;

					// Nullabgleich
					nullabgleich_ziel = -(nMinPeak + nMaxPeak) / 2;
					int nNormPeak = nMaxPeak + nullabgleich_ziel;
					if (!nNormPeak) nNormPeak = 1;	// doppelte Sicherheit gegen div-by-zero-exception
					int delta_nullabgleich = nullabgleich_ziel - nullabgleich_alt;

					// aus dem normalisierten Peak den nötigen Verstärkungsfaktor berechnen
					int limit = MAX_SIGNAL * MAX_ABS_VERSTAERKUNG / 100;
if (!nNormPeak) MessageBox(hParentWnd, "Please report this message to retell support: nNormPeak", NULL, MB_OK);
					verstaerkungsfaktor_ziel = 65536 * limit / nNormPeak;
					if (verstaerkungsfaktor_ziel < 65536*MAX_ABS_VERSTAERKUNG/100) verstaerkungsfaktor_ziel = 65536*MAX_ABS_VERSTAERKUNG/100; // nicht abschwächen, wenn Signal zu groß
					if (verstaerkungsfaktor_ziel > 65536 * MAX_REL_VERSTAERKUNG)
						verstaerkungsfaktor_ziel = 65536 * MAX_REL_VERSTAERKUNG; // nicht über einen gewissen Faktor hinaus verstärken!
					int delta_verstaerkungsfaktor = verstaerkungsfaktor_ziel - verstaerkungsfaktor_alt;

					int i = 0;
					while (bp < bp_end)
					{
						int nAktSignal = (int)(*(signed short *)bp);

						if (i < schritte_um_anzupassen)
						{
if (!schritte_um_anzupassen) MessageBox(hParentWnd, "Please report this message to retell support: s_u_a", NULL, MB_OK);
							nullabgleich_akt = nullabgleich_alt + (delta_nullabgleich * i / schritte_um_anzupassen);
							verstaerkungsfaktor_akt = verstaerkungsfaktor_alt + (delta_verstaerkungsfaktor / schritte_um_anzupassen * i);
						}

						nAktSignal += nullabgleich_akt;
						nAktSignal *= (verstaerkungsfaktor_akt/MAX_REL_VERSTAERKUNG);
						nAktSignal /= (65536/MAX_REL_VERSTAERKUNG);

						// evtl. Übersteuerung abfangen
						BOOL bRecalc = FALSE;
						if (nAktSignal > MAX_SIGNAL*MAX_ABS_VERSTAERKUNG/100)
						{
							nAktSignal = MAX_SIGNAL*MAX_ABS_VERSTAERKUNG/100;
							bRecalc = TRUE;
						}
						if (nAktSignal < -MAX_SIGNAL*MAX_ABS_VERSTAERKUNG/100)
						{
							nAktSignal = -MAX_SIGNAL*MAX_ABS_VERSTAERKUNG/100;
							bRecalc = TRUE;
						}
						if (bRecalc)
						{
							;
						}

						*(signed short *)bp = (signed short)nAktSignal;
						bp += 2;
						i++;
					}
				}

				if (!bMonitorModus)
				{
					if (wfx.nChannels == 2 && control_tone) 
						ConvertBufferToMono(x, whx);

					// als PCM wegspeichern ...
					if ((long)codec_id == -1L)
					{
						p = wave_it[x].pMem;
						dw = whx->dwBytesRecorded;
					}
					// ... oder über CODEC komprimieren
					else
					{	// better do this with a PostMessage?
						if (!ConvertBuffer(wave_it[x].pMem, whx->dwBytesRecorded, &p, &dw)) goto Out;
					}

					if (dw)
					{
						if (fwrite(p, dw, 1, fp) != 1)
							WaveIn_Close();
						else
						{
							dwDataSize += whx->dwBytesRecorded;
							whx->dwBytesRecorded = 0;
						}
					}
				}

			}
/*
			result = waveInUnprepareHeader(hwi, ((WAVEHDR*)dwParam1), sizeof(WAVEHDR));
#ifdef _DEBUG
				if (result != MMSYSERR_NOERROR)
				{
					char buffer[200];
					waveInGetErrorText(result, buffer, sizeof(buffer));
					MessageBox(hParentWnd, buffer, "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				}
#endif
			result = waveInPrepareHeader(hwi, ((WAVEHDR*)dwParam1), sizeof(WAVEHDR));
#ifdef _DEBUG
				if (result != MMSYSERR_NOERROR)
				{
					char buffer[200];
					waveInGetErrorText(result, buffer, sizeof(buffer));
					MessageBox(hParentWnd, buffer, "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				}
#endif
*/
Out:
			// Überläufe?
			int i;
			int bFlag = FALSE;
			for (i = 0; i < ANZAHL_WAVE_IT_BUFFER; i++)
				if (wave_it[i].bReallocatable || !wave_it[i].wh.dwBytesRecorded) bFlag = TRUE;
			if (!bFlag) nUeberlaeufe++;

			// Buffer wieder zur Verfügung stellen
			if (bRecreateBuffers && hParentWnd)
			{
				PostMessage(hParentWnd, MYWM_REALLOCATE_WAVEIN_BUFFER, i, 0L);
			}

			wave_it[x].bReallocatable = TRUE;	// wird in diesem Durchlauf wohl noch gebraucht, NT40 hat Probleme gemacht
		}
		break;

	case WIM_OPEN: // Sent when the device is opened using the waveInOpen function.

#ifdef _DEBUG
		TRACE0("WaveInFunc() WIM_OPEN\n");
#endif
		break;
	}

}


//------------ ab hier Konvertierungs-Krempel -----------------------------


// Locate a driver that supports a given format and return its ID
typedef struct {
	HACMDRIVERID hadid;
	WORD  wFormatTag;
	DWORD nSamplesPerSec;
	WORD  nChannels;
	WORD  wBitsPerSample;
} FIND_DRIVER_INFO;

// callback function for format enumeration
BOOL CALLBACK find_format_enum(HACMDRIVERID hadid, LPACMFORMATDETAILS pafd, DWORD_PTR dwInstance, DWORD_PTR fdwSupport)
{
	FIND_DRIVER_INFO* pdi = (FIND_DRIVER_INFO*) dwInstance;
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
BOOL CALLBACK find_driver_enum(HACMDRIVERID hadid, DWORD_PTR dwInstance, DWORD_PTR fdwSupport)
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
	mmr = acmFormatEnum(had, &fd, (ACMFORMATENUMCBA)find_format_enum, (DWORD_PTR)(VOID*)pdi, 0);
	delete(pwf);
	acmDriverClose(had, 0);
	if (pdi->hadid || mmr) {
		// found it or some error
		return FALSE; // stop enumerating
	}

	return TRUE; // continue enumeration
}

// locate the first driver that supports a given format tag
HACMDRIVERID find_driver(WORD wFormatTag)
{
	FIND_DRIVER_INFO fdi;
	fdi.hadid = NULL;
	fdi.wFormatTag = wFormatTag;
	MMRESULT mmr = acmDriverEnum((ACMDRIVERENUMCB)find_driver_enum, (DWORD_PTR)(VOID*)&fdi, 0);
	if (mmr) return NULL;
	return fdi.hadid;
}

// get a description of the first format supported for a given tag
WAVEFORMATEX* get_driver_format(HACMDRIVERID hadid, WORD wFormatTag, DWORD nSamplesPerSec, WORD nChannels, WORD wBitsPerSample)
{
	// open the driver
	HACMDRIVER had = NULL;
	MMRESULT mmr = acmDriverOpen(&had, hadid, 0);
	if (mmr) {
		return NULL;
	}

	// allocate a structure for the info
	DWORD dwSize = 0;
	mmr = acmMetrics((HACMOBJ)had, ACM_METRIC_MAX_SIZE_FORMAT, &dwSize);
	if (dwSize < sizeof(WAVEFORMATEX)) dwSize = sizeof(WAVEFORMATEX); // for MS-PCM
	WAVEFORMATEX* pwf = (WAVEFORMATEX*) new char[(dwSize)];
	memset(pwf, 0, dwSize);
	pwf->cbSize = LOWORD(dwSize) - sizeof(WAVEFORMATEX);
	pwf->wFormatTag = wFormatTag;

	ACMFORMATDETAILS fd;
	memset(&fd, 0, sizeof(fd));
	fd.cbStruct = sizeof(fd);
	fd.pwfx = pwf;
	fd.cbwfx = dwSize;
	fd.dwFormatTag = wFormatTag;

	// set up a struct to control the enumeration
	FIND_DRIVER_INFO fdi;
	fdi.hadid = NULL;
	fdi.wFormatTag = wFormatTag;
	fdi.nSamplesPerSec = nSamplesPerSec;
	fdi.nChannels = nChannels;
	fdi.wBitsPerSample = wBitsPerSample;

	mmr = acmFormatEnum(had, &fd, (ACMFORMATENUMCBA)find_format_enum, (DWORD_PTR)(VOID*)&fdi, 0);
	acmDriverClose(had, 0);
	if ((fdi.hadid == NULL) || mmr) {
		delete(pwf);
		return NULL;
	}

	return pwf;
}



//------------ hier kommt das Eingemachte: -------------------------------------------

static ACMDRIVERDETAILS WaveIn_dd;

static HACMDRIVERID hadid;
static HACMDRIVER had = NULL;
static BYTE *pSrcDataBuffer = NULL;
static DWORD dwSrcSamples;
static DWORD dwSrcBytes;

static WAVEFORMATEX* pwfPCM;	// Meta-Format
static HACMSTREAM hstr = NULL;
static ACMSTREAMHEADER strhdr;	// Meta-Konverter-Stream
static BYTE* pDst1Data = NULL;
static DWORD dwDst1Bytes;
static DWORD dwDst1Samples;

static WAVEFORMATEX* pwfDrv;	// Ziel-Format
static HACMSTREAM hstr2 = NULL;
static ACMSTREAMHEADER strhdr2; // Ziel-Konverter-Stream
static BYTE *pDst2Data = NULL;
static DWORD dwDst2Bytes;

static int ConvertSemaphore = 0;

static WAVEFORMATEX* ConvertOpen()
{
	MMRESULT mmr;

#ifdef _DEBUG
	if (!hwi) TRACE0("ConvertOpen(): WaveIn-Handle == NULL!\n");
#endif

	// Select a format to convert to
	// WORD wFormatTag = WAVE_FORMAT_ADPCM;
	// WORD wFormatTag = WAVE_FORMAT_IMA_ADPCM;
	// WORD wFormatTag = WAVE_FORMAT_GSM610;
	// WORD wFormatTag = WAVE_FORMAT_ALAW;
	// WORD wFormatTag = WAVE_FORMAT_MULAW;
	// WORD wFormatTag = 0x32; // MSN
	// WORD wFormatTag = WAVE_FORMAT_DSPGROUP_TRUESPEECH;

	hadid = (HACMDRIVERID)codec_id;

	// Now we locate a CODEC that supports the destination format tag
	///hadid = find_driver(wFormatTag);
	///if (hadid == NULL) {
	///	MessageBox(hParentWnd, "CODEC-Treiber konnte nicht gefunden werden!", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
	///	return NULL;
	///}
	//printf("Driver found (hadid: %4.4lXH)\n", hadid);

	// show some information about the driver
	WaveIn_dd.cbStruct = sizeof(WaveIn_dd);
	mmr = acmDriverDetails(hadid, &WaveIn_dd, 0);
	/*
	printf("   Short name: %s\n", dd.szShortName);
	printf("   Long name:  %s\n", dd.szLongName);
	printf("   Copyright:  %s\n", dd.szCopyright);
	printf("   Licensing:  %s\n", dd.szLicensing);
	printf("   Features:   %s\n", dd.szFeatures);
	*/

	// get the details of the format
	// Note: this is just the first of one or more possible formats for the given tag
	///pwfDrv = get_driver_format(hadid, wFormatTag);

	pwfPCM = NULL;

	if (format_info != 0xffffffff)
	{
		WAVEFORMATEX *p_wfx = (WAVEFORMATEX *)format_info;
		pwfDrv = (WAVEFORMATEX*)new char[(sizeof(*p_wfx) + p_wfx->cbSize)];
		memcpy(pwfDrv, p_wfx, sizeof(*p_wfx) + p_wfx->cbSize);
		WORD wFormatTag = pwfDrv->wFormatTag;

		// get a PCM format tag the driver supports
		// Dabei an dem Aufnahmeformat orientieren und bei control tone als mono behandeln!
		if (wfx.nChannels == 2 && control_tone) 
			pwfPCM = get_driver_format(hadid, WAVE_FORMAT_PCM, wfx_mono.nSamplesPerSec, wfx_mono.nChannels, wfx_mono.wBitsPerSample);
		else
			pwfPCM = get_driver_format(hadid, WAVE_FORMAT_PCM, wfx.nSamplesPerSec, wfx.nChannels, wfx.wBitsPerSample);
	}

	if (pwfPCM == NULL) {
		if (!bMessageShown)
		{
			bMessageShown = TRUE;
			switch (language)
			{
			case WAVEIN_LANG_D:
				MessageBox(hParentWnd, "Der CODEC-Treiber konnte nicht entsprechend dem Aufnahmeformat eingestellt werden!", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			default:
			case WAVEIN_LANG_GB:
				MessageBox(hParentWnd, "The CODEC driver coudn't be adjusted according to the recording format", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_E:
				MessageBox(hParentWnd, "El driver CODEC no se pudo regular conforme al formato de grabación", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_CZ:
				MessageBox(hParentWnd, "Ovladac kodéru/dekodéru (CODEC) se nepodarilo nastavit podle formátu záznamu.", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_NL:
				MessageBox(hParentWnd, "De CODEC driver kon niet worden aangepast aan de opname formaat.", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_PL:
				MessageBox(hParentWnd, "Sterownik KODEKA nie mógl byc ustawiony do formatu nagrywania", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			}
			bMessageShown = FALSE;
		}
		return NULL;
	}
	delete pwfPCM;

	////////////////////////////////////////////////////////////////////////////////
	// convert the source wave to the PCM format supported by the CODEC
	// we use any driver that can do the PCM to PCM conversion
/*	hstr = NULL;
	mmr = acmStreamOpen(&hstr,
						NULL, // any driver
						&wfx, // source format
						pwfPCM, // destination format
						NULL, // no filter
						NULL, // no callback
						0, // instance data (not used)
						ACM_STREAMOPENF_NONREALTIME); // flags
	if (mmr) {
		MessageBox(hParentWnd, "Konnte keinen ACM_Stream für PCM-nach-PCM-Konvertierung öffnen!", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
		return NULL;
	}

	// allocate a buffer for max 1 sec
	dwSrcSamples = wfx.nSamplesPerSec;
	dwSrcBytes = dwSrcSamples * wfx.wBitsPerSample / 8 * wfx.nChannels;
	if (pSrcDataBuffer) delete pSrcDataBuffer;
	pSrcDataBuffer = new BYTE [dwSrcBytes];

	dwDst1Samples = dwSrcSamples * pwfPCM->nSamplesPerSec / wfx.nSamplesPerSec;
	dwDst1Bytes = dwDst1Samples * pwfPCM->wBitsPerSample / 8 * pwfPCM->nChannels;
	if (pDst1Data) delete pDst1Data;
	pDst1Data = new BYTE [dwDst1Bytes];

	// fill in the conversion info
	memset(&strhdr, 0, sizeof(strhdr));
	strhdr.cbStruct = sizeof(strhdr);
	strhdr.pbSrc = pSrcDataBuffer; // the source data to convert
	strhdr.cbSrcLength = dwSrcBytes;
	strhdr.pbDst = pDst1Data;
	strhdr.cbDstLength = dwDst1Bytes;

	// prep the header
	mmr = acmStreamPrepareHeader(hstr, &strhdr, 0);
*/
	///////////////////////////////////////////////////////////////////////////////////
	// convert the intermediate PCM format to the final format

	// open the driver
	had = NULL;
	mmr = acmDriverOpen(&had, hadid, 0);
	if (mmr) {
		if (!bMessageShown)
		{
			bMessageShown = TRUE;
			switch (language)
			{
			case WAVEIN_LANG_D:
				MessageBox(hParentWnd, "CODEC-Treiber konnte nicht geöffnet werden!", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			default:
			case WAVEIN_LANG_GB:
				MessageBox(hParentWnd, "The CODEC driver coudn't be opened", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_E:
				MessageBox(hParentWnd, "El driver CODEC no se pudo abrir", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_CZ:
				MessageBox(hParentWnd, "Ovladac (rídící program) kodéru/dekodéru (CODEC) se nepodarilo spustit", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_NL:
				MessageBox(hParentWnd, "De CODEC driver kon niet worden geopend", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_PL:
				MessageBox(hParentWnd, "Nie mozna uruchomic sterownika KODEKA", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			}
			bMessageShown = FALSE;
		}
		return NULL;
	}

	// open the conversion stream
	// Note the use of the ACM_STREAMOPENF_NONREALTIME flag. Without this
	// some software compressors will report error 512 - not possible
	hstr2 = NULL;
	if (wfx.nChannels == 2 && control_tone) 
		mmr = acmStreamOpen(&hstr2,
							had, // driver handle
							&wfx_mono, // source format
							pwfDrv, // destination format
							NULL, // no filter
							NULL, // no callback
							0, // instance data (not used)
							0/*ACM_STREAMOPENF_NONREALTIME*/); // flags
	else
		mmr = acmStreamOpen(&hstr2,
							had, // driver handle
							&wfx, // source format
							pwfDrv, // destination format
							NULL, // no filter
							NULL, // no callback
							0, // instance data (not used)
							0/*ACM_STREAMOPENF_NONREALTIME*/); // flags
	if (mmr) {
		if (!bMessageShown)
		{
			bMessageShown = TRUE;
			switch (language)
			{
			case WAVEIN_LANG_D:
				MessageBox(hParentWnd, "Konnte keinen ACM (Audio Compression Manager) Stream für PCM-nach-Treiber-Konvertierung öffnen (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			default:
			case WAVEIN_LANG_GB:
				MessageBox(hParentWnd, "Couldn't open an ACM (Audio Compression Manager) stream for pcm-to-driver conversion (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_E:
				MessageBox(hParentWnd, "No se pudo abrir un flujo ACM (Audio Compression Manager) para conversión pcm-driver (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_CZ:
				MessageBox(hParentWnd, "Nepodarilo se spustit tok ACM (Audio Compression Manager) pro konverzi PCM - ovladac (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_NL:
				MessageBox(hParentWnd, "Kan een ACM (Audio Compression Manager) stream voor PCM naar driver conversie niet openen (PCM=Puls Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			case WAVEIN_LANG_PL:
				MessageBox(hParentWnd, "Nie mozna otworzyc strumienia ACM dla konwersji PCM-sterownik", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
				break;
			}
			bMessageShown = FALSE;
		}
		return NULL;
	}

	// allocate a source buffer for max 1 sec
	if (wfx.nChannels == 2 && control_tone) 
		dwSrcSamples = wfx_mono.nSamplesPerSec;
	else
		dwSrcSamples = wfx.nSamplesPerSec;
	if (!wfx.nChannels) MessageBox(hParentWnd, "Please report this message to retell support: wfx.nChannels", NULL, MB_OK);
	if (wfx.nChannels == 2 && control_tone) 
		dwSrcBytes = dwSrcSamples * wfx_mono.wBitsPerSample / 8 * wfx_mono.nChannels;
	else
		dwSrcBytes = dwSrcSamples * wfx.wBitsPerSample / 8 * wfx.nChannels;
	if (pSrcDataBuffer) delete pSrcDataBuffer;
	pSrcDataBuffer = new BYTE [dwSrcBytes];

	// allocate a buffer for the result of the conversion.
	// compute the output buffer size based on the average byte rate
	// and add a bit for randomness
	// the IMA_ADPCM driver fails the conversion without this extra space
	dwDst2Bytes = pwfDrv->nAvgBytesPerSec; // * dwDst1Samples / pwfPCM->nSamplesPerSec;
	dwDst2Bytes = dwDst2Bytes * 3 / 2; // add a little room
	if (pDst2Data) delete pDst2Data;
	pDst2Data = new BYTE [dwDst2Bytes];

	// fill in the conversion info
	memset(&strhdr2, 0, sizeof(strhdr2));
	strhdr2.cbStruct = sizeof(strhdr2);
	strhdr2.pbSrc = pSrcDataBuffer; // the source data to convert
	strhdr2.cbSrcLength = dwSrcBytes;
	strhdr2.pbDst = pDst2Data;
	strhdr2.cbDstLength = dwDst2Bytes;

	// prep the header
	mmr = acmStreamPrepareHeader(hstr2, &strhdr2, 0);

	nUeberlaeufe = 0;
	nRatio = 0;
	ConvertSemaphore = 0;

	return pwfDrv;
}

static BOOL ConvertBuffer(BYTE *pSrcData, DWORD SrcDataBytes, BYTE **ppDst, DWORD *pDstBytes)
{
#ifdef _DEBUG
	if (!hwi) TRACE0("ConvertBuffer(): WaveIn-Handle == NULL!\n");
#endif

	MMRESULT mmr;
/*
#ifdef _DEBUG
	// fill the dest buffer with zeroes just so we can see if anything got
	// converted in the debugger
	memset(pDst1Data, 0, dwDst1Bytes);
#endif

	// fill in the conversion info
	memcpy(strhdr2.pbSrc, pSrcData, SrcDataBytes);
	strhdr2.cbSrcLength = SrcDataBytes;

	// convert the data
	//printf("Converting to intermediate PCM format...\n");
	mmr = acmStreamConvert(hstr, &strhdr, 0);
	if (mmr) {
		MessageBox(hParentWnd, "Konnte keine PCM-nach-PCM-Konvertierung durchführen!", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
		return FALSE;
	}
*/
#ifdef _DEBUG
	// fill the dest buffer with zeroes just so we can see if anything got
	// converted in the debugger
	memset(pDst2Data, 0, dwDst2Bytes);
#endif

	// fill in the conversion info
	memcpy(strhdr2.pbSrc, pSrcData, SrcDataBytes);
	strhdr2.cbSrcLength = SrcDataBytes;

	// convert the data
	if (ConvertSemaphore > 0)
	{
		nUeberlaeufe++;
		*ppDst     = pDst2Data;
		*pDstBytes = 0;
	}
	else
	{
		ConvertSemaphore++;
		mmr = acmStreamConvert(hstr2, &strhdr2, 0);
		if (mmr) {
			WaveIn_Stop();
			if (!bMessageShown)
			{
				bMessageShown = TRUE;
				switch (language)
				{
				case WAVEIN_LANG_D:
					MessageBox(hParentWnd, "Konnte keine PCM-nach-Treiber-Konvertierung durchführen. (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				default:
				case WAVEIN_LANG_GB:
					MessageBox(hParentWnd, "Couldn't perform a pcm-to-driver conversion. (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_E:
					MessageBox(hParentWnd, "No se pudo hacer una conversión pcm-driver. (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_CZ:
					MessageBox(hParentWnd, "Nepodarilo se uskutecnit konverzi PCM - ovladac. (PCM = Pulse Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_NL:
					MessageBox(hParentWnd, "Kan een PCM naar driver conversie niet uitvoeren (PCM=Puls Code Modulation)", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				case WAVEIN_LANG_PL:
					MessageBox(hParentWnd, "Nie mozna przeprowadzic konwersji PCM-sterownik", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				}
				bMessageShown = FALSE;
			}
			ConvertSemaphore--;
			return FALSE;
		}

		*ppDst     = pDst2Data;
		*pDstBytes = strhdr2.cbDstLengthUsed;

/* this doesn't work:
		if (!*pDstBytes) 
		{
			//WaveIn_Stop();
			if (!bMessageShown)
			{
				bMessageShown = TRUE;
				switch (language)
				{
				case WAVEIN_LANG_D:
					MessageBox(hParentWnd, "Die Konvertierung lieferte einen leeren Ergebnispuffer. Entweder der CODEC funktioniert nicht richtig oder er lieferte aus einem anderen Grund keine Konvertierung (z.B. weil Probezeitraum oder Konvertier-Volumen abgelaufen bzw. überschritten ist).", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				default:
				case WAVEIN_LANG_E:
				case WAVEIN_LANG_CZ:
				case WAVEIN_LANG_NL:
				case WAVEIN_LANG_PL:
				case WAVEIN_LANG_GB:
					MessageBox(hParentWnd, "The conversion lead to an empty result buffer. Either the CODEC used doesn't work properly or it didn't convert for another reason (e.g. trial period or volume expired/exceeded).", "WAVEIN.DLL", MB_OK | MB_ICONSTOP | MB_TASKMODAL);
					break;
				}
				bMessageShown = FALSE;
			}
			ConvertSemaphore--;
			return FALSE;
		}
*/

#ifdef _DEBUG
TRACE2("Source data bytes: %d  Destination data bytes: %d\n\r", SrcDataBytes, *pDstBytes);
#endif

if (!SrcDataBytes) MessageBox(hParentWnd, "Please report this message to retell support: SrcDataBytes", NULL, MB_OK);

		nRatio = 100 * *pDstBytes / SrcDataBytes;
		ConvertSemaphore--;
	}

	return TRUE;
}


static void ConvertClose()
{
#ifdef _DEBUG
	if (!hwi) TRACE0("ConvertClose(): WaveIn-Handle == NULL!\n");
#endif

	MMRESULT mmr;

	//mmr = acmStreamUnprepareHeader(hstr, &strhdr, 0L);
	strhdr2.cbSrcLength = dwSrcBytes;
	mmr = acmStreamUnprepareHeader(hstr2, &strhdr2, 0L);

	// close the streams and driver
	//mmr = acmStreamClose(hstr, 0);	hstr  = NULL;
	mmr = acmStreamClose(hstr2, 0);	hstr2 = NULL;
	mmr = acmDriverClose(had, 0);	had   = NULL;

	if (pDst1Data) delete pDst1Data;
	pDst1Data = NULL;
	if (pDst2Data) delete pDst2Data;
	pDst2Data = NULL;
	if (pSrcDataBuffer) delete pSrcDataBuffer;
	pSrcDataBuffer = NULL;

	// show the conversion stats
	//printf("Source wave had %lu bytes\n", dwSrcBytes);
	//printf("Converted wave has %lu bytes\n", strhdr2.cbDstLengthUsed);
	//printf("Compression ratio is %f\n", (double) dwSrcBytes / (double) strhdr2.cbDstLengthUsed);

	return;
}




