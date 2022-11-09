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
*	Beschreibung: GetProgramVerion implementation file
*	
*	Die erste gültige Versionsnummer aus den Resourcen einer MFC-Applikation holen:
*	
*	Beispiel für den Aufruf:
*
*		...
*
*		char version_string[50];
*		HMODULE hExe = GetModuleHandle("TELAR.EXE");
*		VS_FIXEDFILEINFO vs_ffi;
*		if (hExe) 
*		{
*			GetProgramVerion(hExe, &vs_ffi);	
*			sprintf(version_string, "v%0lu.%0lu", vs_ffi.dwProductVersionMS >> 16, vs_ffi.dwProductVersionMS & 0xffff);
*			// version_string enthält dann "v2.0" oder so ähnlich
*		}
*		else 
*			*version_string = '\0';
*
*		...
*
*	$Log:   D:/pvcsarch/telar/getprogramversion.cpv  $
* 
*    Rev 1.66   Dec 19 2007 17:27:34   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.65   Oct 11 2007 10:15:06   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.64   Sep 21 2007 15:47:22   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.63   Aug 14 2007 14:09:12   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.62   May 09 2007 10:23:48   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.61   Nov 16 2006 14:59:50   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.60   Nov 13 2006 13:26:28   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.59   Jun 12 2006 15:13:26   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.58   Nov 25 2005 01:32:26   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.57   Nov 23 2005 16:11:24   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.56   Nov 11 2005 09:51:02   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.55   Jul 11 2005 08:52:38   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.54   Jul 05 2005 01:50:24   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.53   Jun 28 2005 01:46:30   tmielke
* v1.72 build 1250
* 
*    Rev 1.52   Jun 02 2005 01:30:30   tmielke
* v1.72 build 1207
* 
*    Rev 1.51   May 18 2005 13:47:14   tmielke
* v1.72 build 1200
* 
*    Rev 1.50   Mar 18 2005 16:12:02   tmielke
*  
* 
*    Rev 1.49   Mar 12 2005 07:08:36   tmielke
* v1.69
* 
*    Rev 1.48   Feb 22 2005 16:53:24   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.47   Nov 21 2004 01:29:18   tmielke
* v1.66 build 883
* 
*    Rev 1.46   Dec 04 2003 03:36:46   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.45   Nov 18 2003 09:39:44   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.44   Oct 03 2003 01:22:12   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.43   Sep 23 2003 01:48:06   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.42   Sep 12 2003 01:12:12   tmielke
*  
* 
*    Rev 1.41   Sep 11 2003 04:04:06   tmielke
*  
* 
*    Rev 1.40   Sep 04 2003 00:55:28   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.39   Aug 04 2003 00:35:02   tmielke
* v1.64
* 
*    Rev 1.38   Jun 09 2003 15:25:18   tmielke
* v1.63 final
* 
*    Rev 1.37   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.36   May 05 2002 11:56:22   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.35   Mar 15 2002 20:21:56   tmielke
* v1.60
* 
*    Rev 1.34   Nov 07 2001 02:08:22   tmielke
* v1.59 bugfix release
* 
*    Rev 1.33   Nov 06 2001 05:27:00   tmielke
* v1.58a
* 
*    Rev 1.32   Oct 12 2001 16:22:50   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.31   Sep 14 2001 04:12:34   
* v1.57
* 
*    Rev 1.30   06 Jun 2001 02:00:20   tmielke
* offizielle release 1.55
* 
*    Rev 1.29   17 May 2001 02:01:12   tmielke
* v1.54
* 
*    Rev 1.28   12 Feb 2001 19:36:54   tmielke
* v1.53
* 
*    Rev 1.27   12 Feb 2001 13:40:26   tmielke
* GetProgramVersion gefixt
* DSP-Dateien gefixt
* Bug: Liste wurde bei Aufnahme nicht richtig aktualisiert
* 
*    Rev 1.10   21 Dec 2000 02:07:34   tmielke
* Letzte Version vor Umstellung auf DS60
* 
*    Rev 1.9   30 Sep 2000 18:03:24   tmielke
* v1.9
* 
*    Rev 1.8   19 Jun 2000 01:35:00   tmielke
* v1.8
* 
*    Rev 1.7   03 Apr 2000 01:27:38   tmielke
* v1.7b
* 
*    Rev 1.6   18 Mar 2000 11:36:14   tmielke
* v1.7
* 
*    Rev 1.5   17 Mar 2000 05:36:24   tmielke
* v1.6 österr./schweitzer Version
* 
*    Rev 1.4   28 Jan 2000 03:10:36   tmielke
* v1.5
* 
*    Rev 1.3   27 Jan 2000 19:53:56   tmielke
* v1.4
* 
*    Rev 1.2   04 Dec 1999 15:01:12   tmielke
* v1.4
* 
*    Rev 1.1   18 Nov 1999 02:31:44   tmielke
* v1.3 UmSt-Erklärung und E/Ü-Rechnung
* 
*    Rev 1.0   18 Nov 1999 02:30:08   tmielke
* Initial Check In
* 
*    Rev 1.10   07 Jun 1999 18:36:56   tmielke
* Multi Language Version
* 
*    Rev 1.9   05 Apr 1999 09:39:32   tmielke
* Nachtrag v1.32
* 
*    Rev 1.8   05 Apr 1999 08:14:26   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
* 
*    Rev 1.7   22 Mar 1999 16:26:28   tmielke
* v1.31 Letzte-Aufnahme-Button und Logo
* 
*    Rev 1.6   20 Mar 1999 18:52:32   tmielke
* v1.3
* 
*    Rev 1.5   18 Mar 1999 13:27:30   tmielke
* v0.8 - Demoversion fertig gemacht
* 
*    Rev 1.4   03 Mar 1999 13:40:24   tmielke
* Version Label v0.6
* 
*    Rev 1.3   03 Mar 1999 10:54:52   tmielke
* zur Sicherheit eingecheckt
* 
*    Rev 1.0   02 Mar 1999 10:01:30   tmielke
* GetProgramVersion eingebaut.
* 
* 
*/

#include "stdafx.h"
#include "resource.h"

// statics:
static char szBuffer[80]; // print buffer for EnumResourceTypes  
static DWORD cbWritten;   // number of bytes written to res. info. file 
static int cbString;      // length of string in sprintf 

// Prototypen:
// Declare callback functions. 
static int __stdcall EnumTypesFunc( 
	HANDLE hModule, 
	LPTSTR lpType, 
	LONGLONG lParam); 

static int __stdcall EnumNamesFunc( 
	HANDLE hModule, 
	LPCTSTR lpType, 
	LPTSTR lpName, 
	LONGLONG lParam);

static int __stdcall EnumLangsFunc( 
	HANDLE hModule, 
	LPCTSTR lpType, 
	LPCTSTR lpName, 
	WORD wLang, 
	LONGLONG lParam);


void GetProgramVerion(HMODULE hExe, VS_FIXEDFILEINFO *vs)
{
	if (hExe != NULL)
	{
		EnumResourceTypes(hExe,              // module handle 
			(ENUMRESTYPEPROC)EnumTypesFunc,  // callback function 
			(LONGLONG)vs);                       // extra parameter 
	}

}
 

// --- die callbacks -----

//    FUNCTION: EnumTypesFunc(HANDLE, LPSTR, LONG) 
// 
//    PURPOSE:  Resource type callback 
 
static int __stdcall EnumTypesFunc( 
    HANDLE hModule,   // module handle 
    LPTSTR lpType,    // address of resource type 
	LONGLONG lParam)  // extra parameter, could be 
                      // used for error checking 
{ 
	BOOL bFound = FALSE;
 
    // Write the resource type to a resource information file. 
    // The type may be a string or an unsigned decimal 
    // integer, so test before printing. 
 
    if ((ULONG)lpType & 0xFFFF0000) 
	{ 
		if (!strcmp(lpType, "RT_VERSION")) bFound = TRUE;
    } 
    else 
	{ 
 		if ((USHORT)lpType == (USHORT)RT_VERSION) bFound = TRUE;
    } 
 
	if (bFound)
	{
		// Find the names of all resources of type lpType. 
		EnumResourceNames((HINSTANCE) hModule, 
			lpType, 
			(ENUMRESNAMEPROC)EnumNamesFunc, 
			lParam); 
	    return FALSE; // stop!
	}
	
    return TRUE; 
} 
 
//    FUNCTION: EnumNamesFunc(HANDLE, LPSTR, LPSTR, LONGLONG) 
// 
//    PURPOSE:  Resource name callback 
 
static int __stdcall EnumNamesFunc( 
    HANDLE hModule,   // module handle 
    LPCTSTR lpType,   // address of resource type 
    LPTSTR lpName,    // address of resource name 
	LONGLONG lParam)      // extra parameter, could be 
                      // used for error checking 
{ 
	BOOL bFound = FALSE;
 
     // Write the resource name to a resource information file. 
     // The name may be a string or an unsigned decimal 
     // integer, so test before printing. 
 
    if ((ULONG)lpName & 0xFFFF0000) 
	{ 
		if (!strcmp(lpName, "VS_VERSION_INFO")) bFound = TRUE;
    } 
    else 
	{ 
  		if ((USHORT)lpName == VS_VERSION_INFO) bFound = TRUE;
    } 
 
 
     // Find the the 1st languages of resources of type 
     // lpType and name lpName. 
 
	if (bFound)
	{
		EnumResourceLanguages((HINSTANCE) hModule, 
			lpType, 
			lpName, 
			(ENUMRESLANGPROC)EnumLangsFunc, 
			lParam); 
		return FALSE; 
	}
	
    return TRUE; 
} 
 
//    FUNCTION: EnumLangsFunc(HANDLE, LPSTR, LPSTR, WORD, LONGLONG) 
// 
//    PURPOSE:  Resource language callback 
 
static int __stdcall EnumLangsFunc( 
    HANDLE hModule,  // module handle 
    LPCTSTR lpType,  // address of resource type 
    LPCTSTR lpName,  // address of resource name 
    WORD wLang,      // resource language 
    LONGLONG lParam)     // extra parameter, could be 
{ 
    HANDLE hResInfo; 
 
    hResInfo = FindResourceEx((HINSTANCE)hModule, lpType, lpName, wLang); 
	
	if (hResInfo)
	{
		HGLOBAL hGlobal = LoadResource((HINSTANCE)hModule, (HRSRC)hResInfo);
		if (hGlobal)
		{
			WORD *p = (WORD *)LockResource(hGlobal);
			if (p)
			{
				// wLength
				// Specifies the length of the VS_VERSION_INFO structure. 
				// This length does not include any padding that aligns the 
				// subsequent version structure on a 32-bit boundary. 
				p++;
				
				// wValueLength
				// Specifies the length of the Value member. This value is zero 
				// if there is no Value member associated with the current version 
				// structure. 
				ASSERT(*p == sizeof(VS_FIXEDFILEINFO));
				p++;

				// bText
				// Specifies the type of data in the version resource. This member 
				// is 1 if the version resource contains text data and 0 if the 
				// version resource contains binary data. 
				ASSERT(*p == 0);
				p++;
				
				// szKey
				// Contains "VS_VERSION_INFO". 
				p += strlen("VS_VERSION_INFO");	// wide chars!

				// Padding1
				// Contains as many zero bytes as necessary to align the Value 
				// member on the _next_ 32-bit boundary. 
				p += 2 - (((DWORD)p & 0x0003) >> 1/*da WORD*/);
							
				memcpy((VS_FIXEDFILEINFO *)lParam, (VS_FIXEDFILEINFO *)p, sizeof(VS_FIXEDFILEINFO));
				return FALSE;	// stop!
			}
		}
	}
	
	return TRUE; // weiter!
} 
