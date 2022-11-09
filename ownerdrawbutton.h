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
*	COwnerDrawButton header file
*	
*	$Log:   D:/pvcsarch/telar/ownerdrawbutton.h_v  $
* 
*    Rev 1.45   Dec 19 2007 17:27:34   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.44   Oct 11 2007 10:15:08   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.43   Sep 21 2007 15:47:22   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.42   Aug 14 2007 14:09:12   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.41   May 09 2007 10:23:50   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.40   Nov 16 2006 14:59:50   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.39   Nov 13 2006 13:26:28   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.38   Jun 12 2006 15:13:26   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.37   Nov 25 2005 01:32:26   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.36   Nov 23 2005 16:11:26   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.35   Nov 11 2005 09:51:02   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.34   Jul 11 2005 08:52:40   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.33   Jul 05 2005 01:50:24   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.32   Jun 28 2005 01:46:30   tmielke
* v1.72 build 1250
* 
*    Rev 1.31   Jun 02 2005 01:30:32   tmielke
* v1.72 build 1207
* 
*    Rev 1.30   May 18 2005 13:47:14   tmielke
* v1.72 build 1200
* 
*    Rev 1.29   Mar 18 2005 16:12:04   tmielke
*  
* 
*    Rev 1.28   Mar 12 2005 07:08:36   tmielke
* v1.69
* 
*    Rev 1.27   Feb 22 2005 16:53:24   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.26   Nov 21 2004 01:29:18   tmielke
* v1.66 build 883
* 
*    Rev 1.25   Dec 04 2003 03:36:46   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.24   Nov 18 2003 09:39:44   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.23   Oct 03 2003 01:22:12   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.22   Sep 23 2003 01:48:06   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.21   Sep 12 2003 01:12:12   tmielke
*  
* 
*    Rev 1.20   Sep 11 2003 04:04:06   tmielke
*  
* 
*    Rev 1.19   Sep 04 2003 00:55:28   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.18   Aug 04 2003 00:35:04   tmielke
* v1.64
* 
*    Rev 1.17   Jun 09 2003 15:25:18   tmielke
* v1.63 final
* 
*    Rev 1.16   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.15   May 05 2002 11:56:24   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.14   Mar 15 2002 20:21:58   tmielke
* v1.60
* 
*    Rev 1.13   Nov 07 2001 02:08:24   tmielke
* v1.59 bugfix release
* 
*    Rev 1.12   Nov 06 2001 05:27:02   tmielke
* v1.58a
* 
*    Rev 1.11   Oct 12 2001 16:22:52   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.10   Sep 14 2001 04:12:36   
* v1.57
* 
*    Rev 1.9   06 Jun 2001 02:00:24   tmielke
* offizielle release 1.55
* 
*    Rev 1.8   17 May 2001 02:01:16   tmielke
* v1.54
* 
*    Rev 1.7   12 Feb 2001 19:36:56   tmielke
* v1.53
* 
*    Rev 1.6   20 Dec 2000 18:18:36   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.5   04 Dec 2000 02:23:04   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.4   19 Oct 2000 02:28:50   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.3   29 Jul 2000 03:55:30   tmielke
* Aufnahme-Screen redesign fertig
* 
*    Rev 1.2   23 Jul 2000 21:32:24   tmielke
* Owner-draw bitmap+text button fertig
* 
*    Rev 1.1   23 Jul 2000 19:17:32   tmielke
* zwischendurch
* 
*    Rev 1.0   23 Jul 2000 17:32:32   tmielke
* initial checkin
*/

#ifndef __COWNERDRAWBUTTON_H__
#define __COWNERDRAWBUTTON_H__

// wieviele verschiedene Texte/Bitmaps kann der Knopf haben:
#define ODB_MAX_STATES 4

class COwnerDrawButton : CObject
{
public:	
	void InitButton(CWnd *pPar, int ctrl_id, char **text_array, int *bitmap_array, int nNumberOfStates);
	void PerformDrawItem(LPDRAWITEMSTRUCT lpdis);
	void SetState(int n);
	int  GetState();

private:
	void ButtonFocusState(LPDRAWITEMSTRUCT lpdis);
	void ButtonSelectedState(LPDRAWITEMSTRUCT lpdis);
	void DrawButton(HDC hDC, RECT *r, BOOL bPressed);
	
	// stored values from init
	CWnd   *pParent;
	int		m_ctrl_id;
	CString m_text[ODB_MAX_STATES];
	CBitmap cbmButtonBitmap[ODB_MAX_STATES];
	BITMAP	bm[ODB_MAX_STATES];
	int		active_state;		// 1 bis ODB_MAX_STATES

	CSize   csizeRectDim;   // used for text rectangle dimensions
	RECT    rectHi,         // rectangle around up button
			rectHiDown,     // rectangle around down button
			rectDraw,		// rectangle to draw the text in for up button
			rectDrawDown;	// rectangle to draw the text in for down button
	int     nSpaceWidth,    // space between text and dashed focus
			nSpaceHeight,   //   rectangle
            nOldBkMode;     // original text background mode
	CDC    *pDC;            // pointer to device context of various wins
	DWORD   dwSize;         // size of bitmap
};

#endif