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
*	Beschreibung: class CIndexDB
*	
*	CIndexDB.cpp : header file
*	Klasse zur Verwaltung der SCR Indexdatei
*	
*	$Log:   D:/pvcsarch/telar/IndexDB.h_v  $
* 
*    Rev 1.29   Dec 19 2007 17:27:28   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.28   Oct 11 2007 10:15:00   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.27   Sep 21 2007 15:47:16   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.26   Aug 14 2007 14:09:06   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.25   May 09 2007 10:23:42   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.24   Nov 16 2006 14:59:44   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.23   Nov 13 2006 13:26:20   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.22   Jun 12 2006 15:13:20   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.21   Mar 17 2006 13:16:20   tmielke
* v1.77 build 1818
* 
*    Rev 1.20   Nov 25 2005 01:32:16   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.19   Nov 23 2005 16:11:18   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.18   Nov 11 2005 09:50:56   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.17   Oct 19 2005 12:22:22   tmielke
* solved problems when accessing file-based index files.
* 
*    Rev 1.16   Jul 11 2005 08:52:30   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.15   Jul 05 2005 01:50:16   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.14   Jun 28 2005 01:46:24   tmielke
* v1.72 build 1250
* 
*    Rev 1.13   Jun 02 2005 01:30:24   tmielke
* v1.72 build 1207
* 
*    Rev 1.12   May 18 2005 13:47:08   tmielke
* v1.72 build 1200
* 
*    Rev 1.11   Mar 18 2005 16:11:58   tmielke
*  
* 
*    Rev 1.10   Mar 12 2005 07:08:30   tmielke
* v1.69
* 
*    Rev 1.9   Feb 22 2005 16:53:20   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.8   Dec 17 2004 10:14:38   tmielke
* v1.66 build 950
* 
*    Rev 1.7   Dec 11 2004 10:06:12   tmielke
* RecordsCount
* 
*    Rev 1.6   Nov 21 2004 01:29:14   tmielke
* v1.66 build 883
* 
*    Rev 1.5   Jun 25 2004 23:25:42   tmielke
* added database index file versioning (Config key 'MinBuildNeeded')
* 
*    Rev 1.4   Jun 01 2004 05:07:20   tmielke
* v1.66 build 846
* improved stability
* 
*    Rev 1.3   Dec 04 2003 03:36:40   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.2   Nov 06 2003 05:18:26   tmielke
* MDB-index Zwischenversion
* 
*    Rev 1.1   Oct 21 2003 03:42:16   tmielke
* started database index file
* 
*    Rev 1.0   Oct 20 2003 21:25:04   tmielke
* initial checkin
* 
*/

#ifndef __INDEXDB__
#define __INDEXDB__

//#include <afxado.h> 
//... replaced by this:
#include "ado2.h"

#include "TMTabelle.h"
#include "DBSQLite.h"

#pragma warning(disable:4995)

class CIndexDB : public CADODatabase
{
// Construction
public:
	CIndexDB();
	~CIndexDB();
	BOOL OpenCreate(LPCTSTR lpszName, LPCTSTR lpszConnect);
	BOOL Open(LPCTSTR lpszName);
	BOOL Create(LPCTSTR lpszName, LPCTSTR lpszConnect);
	void Close();
	BOOL IsOpen();
	CString GetName();
	BOOL UpdateRecordingByDateTimeID(TMZeile *record);
	BOOL DeleteRecordingByDateTimeID(TMZeile *zeile);
	void EndSeekRecording();
	BOOL AppendRecording(TMZeile *record);
	BOOL SeekRecordingByPosition(int offset, int limit);
	BOOL SeekRecordingByDateTimeID(TMZeile *record);
	BOOL GetNextRecording(TMZeile *record);
	void UpdateWorkstation();
	BOOL AppendAccesslog(char *Operation, BOOL OK, char *Details);
	BOOL SetConfig(char *key, CString &value);
	BOOL IncConfig(char *key, int value);
	BOOL GetConfig(char *key, CString &value);
	BOOL MSSQLFix();
	int DetermineRecordingsCount();
	int EscapeString(char *szOrig, char *szEscaped, int bufSize);
	CSqlStatement *recordingsRS_SQLite;

	// default recordsets representing the 5 tables, openend using CADORecordset::openTable
	CADORecordset *recordingsRS;	
	CADORecordset *workstationsRS;
	CADORecordset *licensesRS;
	CADORecordset *accesslogRS;
	CADORecordset *configRS;

	BOOL m_show_messages;
	CDbSQLite m_sqlite;
	BOOL m_bIsSQLite;
	BOOL m_bFileReadOnly;

// Implementation
protected:
	BOOL SQLiteOpen(LPCTSTR lpszName);
	BOOL MSJetOpen(LPCTSTR lpszName);
	void FillVariant(COleVariant & var, LPCTSTR lpszSrc);
	void CheckUpgrade();

	int m_AppendRecordingRecursionLevel;
};

#endif