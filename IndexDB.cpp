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
*	CIndexDB.cpp : implementation file
*	Klasse zur Verwaltung der SCR Indexdatei
*	
*	$Log:   D:/pvcsarch/telar/IndexDB.cpv  $
* 
*    Rev 1.35   Dec 19 2007 17:27:28   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.34   Oct 11 2007 10:15:00   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.33   Sep 21 2007 15:47:16   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.32   Aug 14 2007 14:09:06   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.31   May 09 2007 10:23:42   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.30   Nov 16 2006 14:59:44   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.29   Nov 13 2006 13:26:20   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.28   Jun 12 2006 15:13:20   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.27   May 31 2006 09:19:04   tmielke
* zur Sicherheit vor Lautstärkeregler für Audio-Ausgabe
* 
*    Rev 1.26   Mar 17 2006 13:16:18   tmielke
* v1.77 build 1818
* 
*    Rev 1.25   Nov 25 2005 01:32:14   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.24   Nov 23 2005 16:11:18   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.23   Nov 11 2005 09:50:56   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.22   Nov 03 2005 00:25:16   tmielke
* added suggestions according to #491
* 
*    Rev 1.21   Oct 19 2005 12:22:22   tmielke
* solved problems when accessing file-based index files.
* 
*    Rev 1.20   Jul 11 2005 08:52:30   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.19   Jul 06 2005 06:12:52   tmielke
* changed SetConfig because of "ODBC call failed" message
* 
*    Rev 1.18   Jul 05 2005 01:50:16   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.17   Jun 28 2005 01:46:24   tmielke
* v1.72 build 1250
* 
*    Rev 1.16   Jun 02 2005 01:30:24   tmielke
* v1.72 build 1207
* 
*    Rev 1.15   May 18 2005 13:47:08   tmielke
* v1.72 build 1200
* 
*    Rev 1.14   Mar 18 2005 16:11:58   tmielke
*  
* 
*    Rev 1.13   Mar 12 2005 07:08:30   tmielke
* v1.69
* 
*    Rev 1.12   Feb 22 2005 16:53:20   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.11   Dec 17 2004 10:14:38   tmielke
* v1.66 build 950
* 
*    Rev 1.10   Dec 11 2004 10:06:12   tmielke
* RecordsCount
* 
*    Rev 1.9   Dec 11 2004 04:52:34   tmielke
* v1.66 build 886
* 
*    Rev 1.8   Nov 21 2004 01:29:14   tmielke
* v1.66 build 883
* 
*    Rev 1.7   Nov 20 2004 01:03:38   tmielke
* v1.66 build 880
* 
*    Rev 1.6   Sep 22 2004 05:20:32   tmielke
* v1.66 build 869 
* improved db-index file creation & cleaned up moving files
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


#include "stdafx.h"
#include "TelAr.h"
#include <io.h>

#if defined(DEBUGFILE)
#if defined(_DEBUG) 
#define SQL(cmd) { if (!m_sqlite.DirectStatement(cmd)) { DF2(">>>>>> %s -- %s <<<<<<", cmd, m_sqlite.LastError()); ::MessageBox(AfxGetMainWnd()->m_hWnd, m_sqlite.LastError(), cmd, MB_ICONEXCLAMATION); } }
#else
#define SQL(cmd) { if (!m_sqlite.DirectStatement(cmd)) { DF2(">>>>>> %s -- %s <<<<<<", cmd, m_sqlite.LastError()); } }
#endif
#else
#define SQL(cmd) ;
#endif

#define SQLERROR(title) { DF2(">>>>>> %s -- %s <<<<<<", title, m_sqlite.LastError()); ::MessageBox(AfxGetMainWnd()->m_hWnd, (CString)"Operation failed: " + title, m_sqlite.LastError(), MB_ICONEXCLAMATION); }

static long recordings_fieldsizes[INDEX_FILECOLUMNS] = { 
	/* SPID_DATEINAME */			255,
	/* SPID_INITIALEN */			2,
	/* SPID_GESPRAECHSPARTNER */	0,
	/* SPID_NOTIZEN */				0,
	/* SPID_DATUM */				10, 
	/* SPID_ZEIT */					8,
	/* SPID_CODEC */				10,
	/* SPID_FORMAT */				10,
	/* SPID_MODUS */				1,
	/* SPID_DAUER */				8,
	/* SPID_GESCHUETZT */			1
};


// Constructor
CIndexDB::CIndexDB() : CADODatabase()
{
	recordingsRS = NULL;
	workstationsRS = NULL;
	recordingsRS_SQLite = NULL;
	licensesRS = NULL;
	accesslogRS = NULL;
	configRS = NULL;

	m_show_messages = TRUE;

	m_AppendRecordingRecursionLevel = 0;

	m_bIsSQLite = FALSE;
}


// Constructor
CIndexDB::~CIndexDB()
{
	if (recordingsRS_SQLite)
	{
		delete recordingsRS_SQLite;
		recordingsRS_SQLite = NULL;
	}
}

// Cleate -- a new database -- if needed
BOOL CIndexDB::OpenCreate(LPCTSTR lpszName, LPCTSTR lpszConnect)
{
	DF("CIndexDB::OpenCreate()");
	if (GetFileAttributes(lpszName) == 0xFFFFFFFF)	// does not exist?
	{
		BOOL ret;
		ret = Create(lpszName, lpszConnect);
		Close();
		if (!ret) return ret;
	}
	return Open(lpszName);
}


// Open -- an existing database
BOOL CIndexDB::Open(LPCTSTR lpszName)
{
	if (!_strnicmp(lpszName, "sense://", 8)) return FALSE;
	
	BOOL bRet = FALSE;

	// check for old-style index file
	CFile File;
	char magic_buffer[20];
	if (File.Open(lpszName, CFile::modeRead|CFile::shareDenyNone))
	{
		File.Seek(0, CFile::begin);
		File.Read(magic_buffer, sizeof(magic_buffer));
		File.Close();
	}
	else
	{
		char outcome_buffer[1000];
		if (m_show_messages)
		{
			char buffer[1000];
			LANG2BUFFER(IDS_STRING57, buffer);
			sprintf(outcome_buffer, buffer, lpszName);
			MessageBox(AfxGetMainWnd()->m_hWnd,
					outcome_buffer, 
					"Index File Open Error",
					MB_ICONEXCLAMATION );
		}
		DF2("CIndexDB::Open(%s) -- ", lpszName, outcome_buffer);
		return FALSE;
	}

	DWORD dwFileStat = GetFileAttributes(lpszName);
	m_bFileReadOnly = FALSE;
	if (dwFileStat != 0xffffffff)
		if (dwFileStat & FILE_ATTRIBUTE_READONLY) m_bFileReadOnly = TRUE;

	if (!strcmp(magic_buffer, "SQLite format 3"))
	{
		DF1("CIndexDB::Open(%s) -- SQLite index file", lpszName);
		bRet = SQLiteOpen(lpszName);	
	}
	else if (!strncmp(magic_buffer, "DSN=", 4))
	{
		DF1("CIndexDB::Open(%s) -- Microsoft Jet index file", lpszName);
		bRet = MSJetOpen(lpszName);	
	}
	else if (!strcmp(magic_buffer+4, "Standard Jet DB"))
	{
		DF1("CIndexDB::Open(%s) -- Microsoft Jet index file", lpszName);
		bRet = MSJetOpen(lpszName);	
	}
	else
	{
		if (m_show_messages)
		{
			char buffer[1000];
			LANG2BUFFER(IDS_STRING58, buffer);
			MessageBox(AfxGetMainWnd()->m_hWnd,
					buffer, 
					"Index File Open Error",
					MB_ICONEXCLAMATION );
		}
		DF1("CIndexDB::Open(%s) -- >>>>>> unknown index file format <<<<<<", lpszName);
		return FALSE;		
	}

	return bRet;
}		

// Open -- an existing database
BOOL CIndexDB::SQLiteOpen(LPCTSTR lpszName)
{
	DF("CIndexDB::SQLiteOpen()");

	m_bIsSQLite = TRUE;

	if (!m_sqlite.Open(lpszName))
	{
		char outcome_buffer[1000];
		if (m_show_messages)
		{
			char buffer[1000];
			LANG2BUFFER(IDS_STRING57, buffer);
			sprintf(outcome_buffer, buffer, lpszName);
			MessageBox(AfxGetMainWnd()->m_hWnd,
					outcome_buffer, 
					"Index File Open Error",
					MB_ICONEXCLAMATION );
		}
		DF2("CIndexDB::SQLiteOpen(%s) -- ", lpszName, outcome_buffer);
		return FALSE;
	}
/*	
		{
				CSqlStatement* stmt = m_sqlite.Statement("SELECT COUNT(*) FROM Config WHERE Config.CFGKey = 'notfound';");
				if (!stmt->Execute()) SQLERROR("SQL Error")
				delete stmt;
		}
		{
				CSqlStatement* stmt = m_sqlite.Statement("INSERT INTO Config VALUES ('abc1','123');");
		//	if (!stmt->Reset()) return FALSE;

		//	if (stmt->ValueInt(0))
			{
		//		CSqlStatement* stmt = m_sqlite.Statement(csSQLUpdate);	// then update
				if (!stmt->Execute()) SQLERROR("SQL Error")
				delete stmt;
			
		}
*/

	// Try for 10 seconds to commit a database update
	m_sqlite.SetBusyTimeout(10000);

	// Check if database needs update or was already updated by a more advanced version
	if (!m_bFileReadOnly) CheckUpgrade();

	// update Workstations table
	if (!m_bFileReadOnly) UpdateWorkstation();

	return TRUE;	
}

// Open -- an existing database
BOOL CIndexDB::MSJetOpen(LPCTSTR lpszName)
{
	DF("CIndexDB::MSJetOpen()");

	m_bIsSQLite = FALSE;

	CFile File;
	char magic_buffer[2000];
	memset(magic_buffer, 0x00, sizeof(magic_buffer));

	if (File.Open(lpszName, CFile::modeRead|CFile::shareDenyNone))
	{
		File.Seek(0, CFile::begin);
		File.Read(magic_buffer, sizeof(magic_buffer));
		File.Close();
	}

	try
	{
		if (IsOpen()) Close();	// sicher ist sicher...
		// testen, ob auf INDEX_FILENAME zugegriffen werden kann
		if (!_access(lpszName, 06))
		{
			//CString strConnection = _T("");
			//strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;"
			//			  "Data Source=");
			//strConnection += (CString)lpszName;
			//SetConnectionString(strConnection);

			CADODatabase::Open(magic_buffer+4);	// try to open in read-write
		}
		else
		{
			//CString strConnection = _T("");
			//strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;"
			//			  "Data Source=");
			//strConnection += (CString)lpszName;
			//SetConnectionString(strConnection);
			SetConnectionMode(CADODatabase::connectModeRead);

			CADODatabase::Open(magic_buffer+4);	// try to open in read-only
		}
/*
CADODatabaseInfo dbinfo;
int nQueries1 = m_pWorkspace->GetDatabaseCount();
for ( int i = 0; i < nQueries1; i++ )
{
	m_pWorkspace->GetDatabaseInfo(i, dbinfo);
	AfxMessageBox(dbinfo.m_strName);
	AfxMessageBox(dbinfo.m_strConnect);		// 
	AfxMessageBox(GetConnect());			// strange incoherence...
	
			
}
*/
//		CString csJetVersion = GetVersion();
//		DF1("Jet Version: %s", csJetVersion.GetBuffer(0));

		recordingsRS = new CADORecordset(this);
		if (!recordingsRS->Open("Recordings", CADORecordset::openTable))
		{
			DF("CIndexDB::MSJetOpen() -- recordingsRS table couldn't be opened");
			return FALSE;
		}

		workstationsRS = new CADORecordset(this);
		if (!workstationsRS->Open("Workstations", CADORecordset::openTable))
		{
			DF("CIndexDB::MSJetOpen() -- workstationsRS table couldn't be opened");
			return FALSE;
		}

		licensesRS = new CADORecordset(this);
		if (!licensesRS->Open("Licenses", CADORecordset::openTable))
		{
			DF("CIndexDB::MSJetOpen() -- licensesRS table couldn't be opened");
			return FALSE;
		}

		accesslogRS = new CADORecordset(this);
		if (!accesslogRS->Open("Accesslog", CADORecordset::openTable))
		{
			DF("CIndexDB::MSJetOpen() -- accesslogRS table couldn't be opened");
			return FALSE;
		}

		configRS = new CADORecordset(this);
		if (!configRS->Open("Config", CADORecordset::openTable))
		{
			DF("CIndexDB::MSJetOpen() -- configRS table couldn't be opened");
			return FALSE;
		}

//		if (CanUpdate())
		{
			// Check if database needs update or was already updated by a more advanced version
			CheckUpgrade();

			// update Workstations table
			UpdateWorkstation();
		}
	}
	catch( CADOException &e )
	{
		if (m_show_messages)
		{
			CString csErrorText = e.GetErrorMessage();
			if (e.GetError() == E_FAIL)
				csErrorText += " -- Note: If you accessed an SQL-connected database with v1.92 (or earlier) and now updated to v1.93 (or later) you need to remove the Telar_Index.dat file from the Archive Path on the server and rebuild it by clicking on the Connect to SQL button on the options tab (and just ignore the CREATE TABLE messages). This is necessary because v1.93 uses the more recent ADO database interface by Microsoft where v1.92 and older version used DAO. Please update all old versions of the Software Call Recorder that are connected to the SQL server. Sorry for the inconvinience.";
			MessageBox(AfxGetMainWnd()->m_hWnd,
					csErrorText.GetBuffer(0), 
					"Index File Open Error",
					MB_ICONEXCLAMATION );
		}
		else
		{
			DF(e.GetErrorMessage().GetBuffer(0));
			return FALSE;
		}
	}
	return TRUE;
}


#define MIN_BUILD_NEEDED "1305"
// ... for any application accessing the index file to not mess it up

// automatically updates an old-versioned database according to 'MinBuildNeeded' config entry
void CIndexDB::CheckUpgrade()
{
	CString min_build;
	if (!GetConfig("MinBuildNeeded", min_build))
	{
		min_build = "1";	// asume this is a new database, with "1" omit conversion messages
	}
	if (atoi(build_string+6) < atoi(min_build.GetBuffer(0)))
	{
		LANG_MESSAGEBOX1(IDS_STRING174);	// "You need to install a newer version of the software in order to access this archive folder properly. WARNING: Working with this folder without updating might lead to problems!"
	}

	// update auf build 910
	// Count number of entries in recording table if this config value does not already exist
	// outdated since v1.74 build 13XX
	CString csRecordingsCount;
	int n;
	if (!GetConfig("RecordingsCount", csRecordingsCount)/* || atoi(min_build) < 1300*/)
	{
		if (atoi(min_build) > 1)
			LANG_MESSAGEBOX1(IDS_STRING175);

		if (m_bIsSQLite) SQL("BEGIN EXCLUSIVE")
		n = DetermineRecordingsCount();
		csRecordingsCount.Format("%d", n);
		SetConfig("RecordingsCount", csRecordingsCount);
		if (m_bIsSQLite) SQL("COMMIT")
	}

	// only german version: eventually convert date from %02d.%02d.%04d to %04d/%02d/%02d
	if (!strcmp(C_language, "D") && m_bIsSQLite/* currently only SQLite */)
	{
		// CString ger_date_checked;
		// if (!GetConfig("GermanDateFormatChecked", ger_date_checked)) ger_date_checked = "0";		
		// if (ger_date_checked == "0")

		CString csSQL;
		csSQL = "SELECT COUNT(*) FROM recordings WHERE f4 < '2000' OR f4 >2099;";
		int n;
		if (m_bIsSQLite)
		{
			CSqlStatement* stmt = m_sqlite.Statement(csSQL);
			stmt->NextRow();
			n = stmt->ValueInt(0);
			stmt->NextRow();
			delete stmt;
		}

		// found some Dates with years before 2000 or after 2099? -> suspicious! Check for german date format.
		if (n > 0)
		{
			CString csSQL;
			// ACCESS DOESN'T WORK: csSQL = "UPDATE recordings SET f4=MID(f4,7)+'/'+MID(f4,4,2)+'/'+MID(f4,1,2) WHERE f4 LIKE '__.__.____';";
			// regular SQL would be like this: csSQL = "UPDATE recordings SET f4=CONCAT(SUBSTR(f4,7,4),'/',SUBSTR(f4,4,2),'/',SUBSTR(f4,1,2)) WHERE f4 LIKE '__.__.____';";
			csSQL = "UPDATE recordings SET f4=SUBSTR(f4,7,4)||'/'||SUBSTR(f4,4,2)||'/'||SUBSTR(f4,1,2) WHERE f4 LIKE '__.__.____';";

/*			if (m_bIsSQLite)
*/			{
				CSqlStatement* stmt = m_sqlite.Statement(csSQL);	// then update
				if (!stmt->Execute()) 
					{ SQLERROR(csSQL.GetBuffer(0)); delete stmt; DF("Conversion of recordings table to YYYY/MM/DD format failed."); }
				else
				{ 
					DF1("Converted recordings table to YYYY/MM/DD format: %d records", n); 
					delete stmt; 

					// stmt = m_sqlite.Statement("REINDEX recordings");	// then reindex
					// if (!stmt->Execute()) 
					// 	{ SQLERROR(csSQL.GetBuffer(0)); delete stmt; DF("Conversion of recordings table to YYYY/MM/DD format failed while reindexing."); }
				}
			}
/*			else	// MS-ACCESS & SQL SERVER not supported, currently only SQLite 
			{
				if (recordingsRS)
				{
					try
					{
						CDaoQueryDef editQD(this);
						Execute(csSQL);
						DF("Converted recordings table to YYYY/MM/DD format.");
					}
					catch( CADOException& e )
					{
						if (m_show_messages)
							AfxMessageBox( 
									e.GetErrorMessage(), 
									MB_ICONEXCLAMATION );
						DF(e->m_pErrorInfo->m_strDescription.GetBuffer(0));
						e->Delete();
						DF("Conversion of recordings table to YYYY/MM/DD format failed.");
					}		
				}
			}
			
			ger_date_checked = "1";
			SetConfig("GermanDateFormatChecked", ger_date_checked);
*/
		}
	}

	// update to current MIN_BUILD_NEEDED 
//	if (atoi(min_build) < atoi(MIN_BUILD_NEEDED))
//		SetConfig("MinBuildNeeded", (CString)MIN_BUILD_NEEDED);
}


// designed to be used in Open/CheckUpgrade member...
int CIndexDB::DetermineRecordingsCount()
{
	int n;

	if (m_bIsSQLite)
	{
		CSqlStatement* stmt = m_sqlite.Statement(_T("SELECT COUNT(*) FROM Recordings"));
		stmt->NextRow();
		n = stmt->ValueInt(0);
		stmt->NextRow();
		delete stmt;
	}
	else
	{
		// hopefully SQL servers deliver the correct COUNT(*)
		if (!recordingsRS) return NULL;

		COleVariant var;
		CString value;

		try
		{
			n = (int)recordingsRS->GetRecordCount();
		}
		catch( CADOException& e )
		{
			//if (m_show_messages)
			//	AfxMessageBox( 
			//			e-m_pErrorInfo->m_strDescription, 
			//			MB_ICONEXCLAMATION );
			//DF(e.GetErrorMessage().GetBuffer(0));
			e;
			return FALSE;
		}		
	}
	return n;
}

// Create -- a new database
BOOL CIndexDB::Create(LPCTSTR lpszName, LPCTSTR lpszConnect)
{
	DF("CIndexDB::Create ...");

if (!_strnicmp(lpszName, "sense://", 8)) return FALSE;

	// create a Jet DB only if an ODBC connect string is submitted, SQLite in every other case
	if (!strlen(lpszConnect))
	{
		m_bIsSQLite = TRUE;

		if (!m_sqlite.Open(lpszName))
		{
			char outcome_buffer[1000];
			if (m_show_messages)
			{
				char buffer[1000];
				LANG2BUFFER(IDS_STRING49, buffer);
				sprintf(outcome_buffer, buffer, lpszName);
				MessageBox(AfxGetMainWnd()->m_hWnd,
						outcome_buffer, 
						"Index File Create Error",
						MB_ICONEXCLAMATION );
			}
			DF2("CIndexDB::Create(%s) -- ", lpszName, outcome_buffer);
			return FALSE;
		}

		// also consider SQL Server CREATE TABLE commands in CPropertyPage5 when making changes here
		static char *sqlcrtbl[] = {
			"CREATE TABLE Recordings (f0 TEXT, f1 TEXT, f2 TEXT, f3 TEXT, f4 TEXT, f5 TEXT, f6 TEXT, f7 TEXT, f8 TEXT, f9 TEXT, f10 TEXT, PRIMARY KEY (f4,f5,f1));",
			"CREATE TABLE Workstations (Computername TEXT, ID TEXT, Date TEXT, Time TEXT, License TEXT, RequestKey TEXT, ResponseKey TEXT, Version TEXT, PRIMARY KEY (Computername));",
			"CREATE TABLE Licenses (License TEXT, PRIMARY KEY (License));",
			"CREATE TABLE Accesslog (Date TEXT, Time TEXT, ID TEXT, Computername TEXT, OK TEXT, Operation TEXT, Details TEXT);",
			"CREATE TABLE Config (CFGKey TEXT, CFGValue TEXT, PRIMARY KEY (CFGKey));"
		};		
		static char sqlcrtbl_size = sizeof(sqlcrtbl)/sizeof(sqlcrtbl[0]);

		// create tables
		{
			int i;

			// MS SQL likes pass through Queries
			for (i = 0; i < sqlcrtbl_size; i++)
			{
				if (!m_sqlite.DirectStatement(sqlcrtbl[i]))
				{
					CString csMessage = "Index file create error" + (CString)": " + (CString)sqlcrtbl[i] + " (Maybe table already existing?)";
					DF(csMessage.GetBuffer(0));
					if (AfxMessageBox(csMessage, MB_OKCANCEL) == IDCANCEL)
						return FALSE;
				}		
			}
		}
		
		DF1("CIndexDB::Create(%s) -- SQLite index file created", lpszName);
	}
	else
	{
		m_bIsSQLite = FALSE;

		DF2("CIndexDB::Create(%s, %s) -- MSJet index file not created, we do not support this any more since v1.93 !!!!!!!!!!!!!!", lpszName, lpszConnect);

		return FALSE;
	}
		
	AppendAccesslog("Create", TRUE, "");

	return TRUE;
}


// Close -- all tables
void CIndexDB::Close()
{
	DF("CIndexDB::Close()");
	if (!m_bIsSQLite)
	{
		try
		{
			if (recordingsRS) {   recordingsRS->Close();   delete recordingsRS;   recordingsRS = NULL; }
			if (workstationsRS) { workstationsRS->Close(); delete workstationsRS; workstationsRS = NULL; }
			if (licensesRS) {     licensesRS->Close();     delete licensesRS;     licensesRS = NULL; }
			if (accesslogRS) {    accesslogRS->Close();    delete accesslogRS;    accesslogRS = NULL; }
			if (configRS) {       configRS->Close();       delete configRS;       configRS = NULL; }
		}
		catch( CADOException& e )
		{
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			return;
		}

		CADODatabase::Close();
	}
	else
	{
		m_sqlite.Close();
	}
}


BOOL CIndexDB::IsOpen()
{
	if (!m_bIsSQLite)
	{
		return CADODatabase::IsOpen();
	}
	else
	{
		if (m_sqlite.GetName().GetLength())
			return TRUE;
		else
			return FALSE;
	}
}


CString CIndexDB::GetName()
{
	if (!m_bIsSQLite)
	{
		return "SQL Index for SCR Recordings";
	}
	else
	{
		return m_sqlite.GetName();
	}
}


//--- Workstations -----------------

// SetConfig -- write config data
// the value parameter takes the value to be written to the database
// return: FALSE if failed or TRUE if successful
void CIndexDB::UpdateWorkstation()
{
	DF("CIndexDB::UpdateWorkstation()");

	// only write complete workstation information
	if (!*X_NPLK || !*X_rqk || !*X_ConfigData) return;

	// prepare data to write to Workstations table:
	//	Computername
	char sComputerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD dwSize = sizeof(sComputerName);
	GetComputerName(sComputerName, &dwSize);
	//	Date/Time
	CTime now = now.GetCurrentTime();                           
	CString csDate, csTime; 
	csDate.Format("%04d/%02d/%02d", now.GetYear(), now.GetMonth(), now.GetDay());
	csTime.Format("%02d:%02d:%02d", now.GetHour(), now.GetMinute(), now.GetSecond());

	CString cdVersionBuild = (CString)version_string + " " + (CString)build_string;
	//assemble SQL command
	CString csSQLSelect, csSQLUpdate, csSQLInsert;
	char computernameEscaped[MAX_COMPUTERNAME_LENGTH*3];
	EscapeString(sComputerName, computernameEscaped, sizeof(computernameEscaped));
	csSQLSelect.Format("SELECT COUNT(*) FROM Workstations WHERE Workstations.Computername = '%s';", computernameEscaped);
	char *cpTablename;
	if (m_bIsSQLite)
		cpTablename = "";
	else
		cpTablename = "Workstations.";
	csSQLUpdate.Format("UPDATE Workstations SET %sID = '%s', %sDate = '%s', %sTime = '%s', %sLicense = '%s', %sRequestKey = '%s', %sResponseKey = '%s', %sVersion = '%s' WHERE %sComputername = '%s';",
		cpTablename, X_initialen, 
		cpTablename, csDate.GetBuffer(0), 
		cpTablename, csTime.GetBuffer(0), 
		cpTablename, X_NPLK, 
		cpTablename, X_rqk, 
		cpTablename, X_ConfigData, 
		cpTablename, cdVersionBuild.GetBuffer(0), 
		cpTablename, sComputerName);
	csSQLInsert.Format("INSERT INTO Workstations VALUES ('%s','%s','%s','%s','%s','%s','%s','%s');", 
		sComputerName, X_initialen, csDate.GetBuffer(0), csTime.GetBuffer(0), X_NPLK, X_rqk, X_ConfigData, cdVersionBuild.GetBuffer(0));

	if (m_bIsSQLite)
	{
		//int nErr;

		BOOL bDoOwnTransaction = m_sqlite.GetAutoCommit(); // if no transaction currently active, do my own one
		if (bDoOwnTransaction) SQL("BEGIN EXCLUSIVE")
		//if (!bDoOwnTransaction || nErr == SQLITE_OK)
		{
			// key already exists in config table?
			CSqlStatement* stmt = m_sqlite.Statement(csSQLSelect);
			stmt->NextRow();

			if (stmt->ValueInt(0))
			{
				CSqlStatement* stmt = m_sqlite.Statement(csSQLUpdate);	// then update
				if (!stmt->Execute()) SQLERROR(csSQLUpdate.GetBuffer(0))
				delete stmt;
			}
			else
			{
				CSqlStatement* stmt = m_sqlite.Statement(csSQLInsert);	// insert otherwise
				if (!stmt->Execute()) SQLERROR(csSQLInsert.GetBuffer(0))
				delete stmt;
			}
			while (stmt->NextRow())
				;
			delete stmt;

			if (bDoOwnTransaction) SQL("COMMIT")
		}		
	}
	else
	{
		if (!workstationsRS) return;

		CString csSQL;

		try
		{
			BeginTransaction();

			BOOL bFound = FALSE;
			CString csComputername;
			workstationsRS->MoveFirst();
			while (!workstationsRS->IsEOF())
			{
				workstationsRS->GetFieldValue("Computername", csComputername);
				if (csComputername == sComputerName)
				{
					bFound = TRUE;
					break;
				}
				workstationsRS->MoveNext();
			}

			if (bFound)
			{
				csSQL = csSQLUpdate;
				Execute(csSQLUpdate);	// dbFailOnError | 
			}
			else
			{
				csSQL = csSQLInsert;
				Execute(csSQLInsert);	// if update failed, try inserting
			}

			CommitTransaction();
		}
		catch( CADOException& e )
		{	
			// if UPDATE didn't work:
/*			if (m_show_messages)
				AfxMessageBox( 
						e->m_pErrorInfo->m_strDescription, 
						MB_ICONEXCLAMATION );
*/			DF(e.GetErrorMessage().GetBuffer(0));
			csSQL = "Error Message Box suppressed -- SQL statement causing the trouble: " + csSQL;
			DF(csSQL.GetBuffer(0));
			RollbackTransaction();
			return;
		}	
	}
	return;
}


//--- Recordings ---------------------


// UpdateRecordingByDateTimeID -- change the data in a record
// return: FALSE if failed or TRUE if successful
BOOL CIndexDB::UpdateRecordingByDateTimeID(TMZeile *zeile)
{
	DF1("CIndexDB::UpdateRecordingByDateTimeID(%s)", zeile->Spalte(SPID_DATEINAME).GetBuffer(0));

	// assemble SQL update statement
	char scFilenameEscaped[20000], scPartnerEscaped[20000], scNotizEscaped[20000];
	EscapeString(zeile->Spalte(SPID_DATEINAME).GetBuffer(0), scFilenameEscaped, 20000);
	EscapeString(zeile->Spalte(SPID_GESPRAECHSPARTNER).GetBuffer(0), scPartnerEscaped, 20000);
	EscapeString(zeile->Spalte(SPID_NOTIZEN).GetBuffer(0), scNotizEscaped, 20000);
	CString csSQL;
	csSQL.Format("UPDATE Recordings SET f0 = '%s', f2 = '%s', f3 = '%s', f6 = '%s', f7 = '%s', f8 = '%s', f9 = '%s', f10 = '%s' WHERE f4 = '%s' AND f5 = '%s' AND f1 = '%s';", 
		scFilenameEscaped, scPartnerEscaped, scNotizEscaped, 
		zeile->Spalte(SPID_CODEC), zeile->Spalte(SPID_FORMAT), zeile->Spalte(SPID_MODUS), 
		zeile->Spalte(SPID_DAUER), zeile->Spalte(SPID_GESCHUETZT), 
		zeile->Spalte(SPID_DATUM), zeile->Spalte(SPID_ZEIT), zeile->Spalte(SPID_INITIALEN));

	if (m_bIsSQLite)
	{
		CSqlStatement* stmt = m_sqlite.Statement(csSQL);	// then update
		if (!stmt->Execute()) { SQLERROR(csSQL.GetBuffer(0)); delete stmt; SQL("ROLLBACK"); return FALSE; }
		delete stmt;
	}
	else
	{
		if (!recordingsRS) return FALSE;

		try
		{
			Execute(csSQL);
		}
		catch( CADOException& e )
		{
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			return FALSE;
		}		
	}
	return TRUE;
}


// DeleteRecordingByDateTimeID -- delete a record
// return: FALSE if failed or TRUE if successful
BOOL CIndexDB::DeleteRecordingByDateTimeID(TMZeile *zeile)
{
	DF1("CIndexDB::DeleteRecordingByDateTimeID(%s)", zeile->Spalte(SPID_DATEINAME).GetBuffer(0));

	// assemble SQL delete statement
	CString csSQL;
	csSQL.Format("DELETE FROM Recordings WHERE f4 = '%s' AND f5 = '%s' AND f1 = '%s';", 
		zeile->Spalte(SPID_DATUM), zeile->Spalte(SPID_ZEIT), zeile->Spalte(SPID_INITIALEN));

	if (m_bIsSQLite)
	{
		SQL("BEGIN EXCLUSIVE")
		CSqlStatement* stmt = m_sqlite.Statement(csSQL);	// delete
		if (!stmt->Execute()) { SQLERROR(csSQL.GetBuffer(0)); delete stmt; SQL("ROLLBACK"); return FALSE; }
		if (!IncConfig("RecordingsCount", -1)) { SQLERROR(csSQL.GetBuffer(0)); delete stmt; SQL("ROLLBACK"); return FALSE; }
		delete stmt;
		SQL("COMMIT")
	}
	else
	{
		if (!recordingsRS) return FALSE;

		try
		{
			Execute(csSQL);	
			int n = GetRecordsAffected();
			IncConfig("RecordingsCount", -n);
		}
		catch( CADOException& e )
		{
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			csSQL = "SQL statement causing the trouble: " + csSQL;
			DF(csSQL.GetBuffer(0));
			return FALSE;
		}		
	}
	return TRUE;
}


// AppendRecording -- append a new record to database and write record data
// the TMZeile parameter takes the values to be written to the database
// return: FALSE if failed or TRUE if successful
BOOL CIndexDB::AppendRecording(TMZeile *record)
{
	DF1("CIndexDB::AppendRecording(%s)", record->Spalte(SPID_DATEINAME).GetBuffer(0));
	BOOL bReturn = TRUE;

	CString csSQL;
	csSQL = "INSERT INTO Recordings VALUES ('";

	// add values list
	for (int i = 0; i < INDEX_FILECOLUMNS; i++)
	{
		CString val, valEscaped;

		val = record->Spalte(i);
		EscapeString(val.GetBuffer(0), valEscaped.GetBuffer(val.GetLength()*4), val.GetLength()*4);
		valEscaped.ReleaseBuffer();

		if (i) csSQL += "','";
		if (valEscaped.GetLength() == 0) 
			valEscaped = " ";
		csSQL += valEscaped;
	}

	csSQL += "');";

	if (m_bIsSQLite)
	{
		SQL("BEGIN EXCLUSIVE")
		CSqlStatement* stmt = m_sqlite.Statement(csSQL);	
		if (!stmt->Execute()) SQLERROR(csSQL.GetBuffer(0))
		stmt->Reset();
		delete stmt;
		IncConfig("RecordingsCount", 1);
		SQL("COMMIT")
	}
	else
	{
		m_AppendRecordingRecursionLevel++;

		if (!recordingsRS) return FALSE;
		COleVariant var;

		CString csErrorText = "CIndexDB::AppendRecording(): ";
		try
		{
			Execute(csSQL);
			IncConfig("RecordingsCount", 1);
		}
		catch( CADOException& e )
		{
			if (TRUE)
			{
				// wait one second
				CTime start = CTime::GetCurrentTime();
				CTime stop  = CTime::GetCurrentTime() + CTimeSpan(0,0,0,1 * m_AppendRecordingRecursionLevel);
				while (CTime::GetCurrentTime() < stop)
					;

				// testing if access is possible again
				int retry = m_AppendRecordingRecursionLevel < 10 ? IDRETRY : IDCANCEL;

				csErrorText += e.GetErrorMessage();
				if (m_show_messages && m_AppendRecordingRecursionLevel >= 10)
				{
					retry = AfxMessageBox(csErrorText, MB_RETRYCANCEL);
				}

				if (retry == IDRETRY) 
				{
					CString csExtErrorText;
					csExtErrorText.Format("%s - retry #%d", csErrorText.GetBuffer(0), m_AppendRecordingRecursionLevel);
					DF(csExtErrorText.GetBuffer(0));

					AppendRecording(record);	// recursive call
				}
			}
			else
			{
				if (m_show_messages)
				{
					csErrorText += e.GetErrorMessage();
					AfxMessageBox(csErrorText, MB_ICONEXCLAMATION);
					DF(csErrorText.GetBuffer(0));
				}
			}

			m_AppendRecordingRecursionLevel--;
			return FALSE;
		}		
		m_AppendRecordingRecursionLevel--;
	}
	return bReturn;
}


// SeekRecordingDateTimeID -- find a recording that fits the DateTimeID index
// only the Date, Time, and ID parts of the TMZeile parameter are used
// return: FALSE if failed, TRUE if successful
BOOL CIndexDB::SeekRecordingByDateTimeID(TMZeile *record)
{
	DF("CIndexDB::SeekRecordingByDateTimeID()");

	// assemble SQL command
	CString csSQL;
	csSQL.Format("SELECT * FROM Recordings WHERE f4='%s' AND f5='%s' AND f1='%s'", record->Spalte(SPID_DATUM), record->Spalte(SPID_ZEIT), record->Spalte(SPID_INITIALEN));

	if (m_bIsSQLite)
	{
		if (recordingsRS_SQLite) delete recordingsRS_SQLite;
		recordingsRS_SQLite = m_sqlite.Statement(csSQL);
	}
	else
	{
		if (!recordingsRS) return FALSE;

		try
		{
			recordingsRS->Close();
			if (!recordingsRS->Open(csSQL, CADORecordset::openQuery)) return FALSE;
			//recordingsRS->MoveFirst();

		}
		catch( CADOException& e )
		{
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			return FALSE;
		}	
	}
	return TRUE;
}


// SeekRecordingByPosition -- prepares the recordset 
// return: FALSE if failed
BOOL CIndexDB::SeekRecordingByPosition(int offset, int limit)
{
	DF2("CIndexDB::SeekRecordingByPosition(offset=%d, limit=%d)", offset, limit);

	// assemble SQL command
	CString csSQL, csLimit;
	if (limit)
		csLimit.Format(" LIMIT %d", limit);
	else
		csLimit = "";
	csSQL.Format("SELECT * FROM Recordings ORDER BY f4,f5,f1%s OFFSET %d;", csLimit.GetBuffer(0), offset);

	if (m_bIsSQLite)
	{
		if (recordingsRS_SQLite) delete recordingsRS_SQLite;
		recordingsRS_SQLite = m_sqlite.Statement(csSQL);
	}
	else
	{
		if (!recordingsRS) return FALSE;

		try
		{
			recordingsRS->Close();
			if (!recordingsRS->Open(csSQL, CADORecordset::openQuery)) return FALSE;
			//recordingsRS->MoveFirst();
		}
		catch( CADOException& e )
		{
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			return FALSE;
		}
	}

	return TRUE;
}


// GetNextRecording -- retrieve the next row in recordings table after a SeekRecordingXXX
// TMZeile with the requested data
// return: FALSE if failed, TRUE if successful
BOOL CIndexDB::GetNextRecording(TMZeile *record)
{
	DF("CIndexDB::GetNextRecording()");

	if (m_bIsSQLite)
	{
		if (!recordingsRS_SQLite) return FALSE;

		if (!recordingsRS_SQLite->NextRow()) 
		{ 
			delete recordingsRS_SQLite; 
			recordingsRS_SQLite = NULL; 
			return FALSE; 
		}
		for (int i = 0; i < INDEX_FILECOLUMNS; i++)		
			record->Spalte(i) = recordingsRS_SQLite->ValueString(i);
	}
	else
	{
		if (!recordingsRS) return NULL;
		COleVariant var;	

		try
		{
			if (recordingsRS->IsEOF()) 
			{
				return FALSE;
			}

			CString name;

			for (int i = 0; i < INDEX_FILECOLUMNS; i++)
			{
				name.Format("f%d", i);		
				recordingsRS->GetFieldValue(name, record->Spalte(i));
			}

			recordingsRS->MoveNext();
		}
		catch( CADOException& e )
		{
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			return FALSE;
		}	
	}

	return TRUE;
}


// EndSeekRecording -- end pending SQL statement in SQLite mode to allow new commands
void CIndexDB::EndSeekRecording()
{
	DF("CIndexDB::EndSeekRecording()");

	if (m_bIsSQLite && recordingsRS_SQLite)
		while (recordingsRS_SQLite->NextRow())	// end eventually pending preceeding db operations
			;
}


//--- Accesslog ---------------------


// AppendAccesslog -- append a new line of log information to database 
// 
// return: FALSE if failed or TRUE if successful
BOOL CIndexDB::AppendAccesslog(char *Operation, BOOL OK, char *Details)
{
	DF("CIndexDB::Accesslog()");
	if (m_bFileReadOnly) return TRUE;	// don't add log entries to a read-only-file

	BOOL bReturn = TRUE;

	// prepare data to write to access log
	CTime now = now.GetCurrentTime();                           
	CString csDate, csTime; 
	csDate.Format("%04d/%02d/%02d", now.GetYear(), now.GetMonth(), now.GetDay());
	csTime.Format("%02d:%02d:%02d", now.GetHour(), now.GetMinute(), now.GetSecond());
	char sComputerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD dwSize = sizeof(sComputerName);
	GetComputerName(sComputerName, &dwSize);

	// prepare sql statement
	char OperationEscaped[1000];
	char DetailsEscaped[2000];
	EscapeString(Operation, OperationEscaped, sizeof(OperationEscaped));
	EscapeString(Details, DetailsEscaped, sizeof(DetailsEscaped));
	CString csSQL;
	csSQL.Format("INSERT INTO Accesslog VALUES ('%s','%s','%s','%s','%s','%s','%s');", csDate.GetBuffer(0), csTime.GetBuffer(0), X_initialen, sComputerName, (OK ? "1" : "0"), OperationEscaped, DetailsEscaped);

	if (m_bIsSQLite)
	{
		CSqlStatement* stmt = m_sqlite.Statement(csSQL);	
		if (!stmt->Execute()) SQLERROR(csSQL.GetBuffer(0))
		delete stmt;
	}
	else
	{
		if (!accesslogRS) return FALSE;
		COleVariant var;

		try
		{
			Execute(csSQL);
		}
		catch( CADOException& e )
		{
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			return FALSE;
		}		
	}

	return bReturn;
}


//--- Config stuff ---------------------

// SetConfig -- write config data
// the value parameter takes the value to be written to the database
// return: FALSE if failed or TRUE if successful
BOOL CIndexDB::SetConfig(char *key, CString &value)
{
	DF("CIndexDB::SetConfig()");

	// for SQLite and some MS SQL Server use field names with preceeding 'CFG' (MS SQL Server making problems with theses 'keywords')
	char *cpCFG = m_bIsSQLite || MSSQLFix() ? "CFG" : "";

	// assemble SQL command
	CString csSQLSelect, csSQLUpdate, csSQLInsert;
	char keyEscaped[20000], valueEscaped[20000];
	EscapeString(key, keyEscaped, 20000);
	EscapeString(value.GetBuffer(0), valueEscaped, 20000);
	csSQLSelect.Format("SELECT COUNT(*) FROM Config WHERE Config.%sKey = '%s';", cpCFG, keyEscaped);
	csSQLUpdate.Format("UPDATE Config SET Config.%sValue = '%s' WHERE Config.%sKey = '%s';", cpCFG, valueEscaped, cpCFG, keyEscaped);
	csSQLInsert.Format("INSERT INTO Config VALUES ('%s','%s');", keyEscaped, valueEscaped);
	
	if (m_bIsSQLite)
	{
		BOOL bDoOwnTransaction = m_sqlite.GetAutoCommit(); // if no transaction currently active, do my own one
		if (bDoOwnTransaction) SQL("BEGIN EXCLUSIVE")
		{
			// key already exists in config table?
			CSqlStatement* stmt = m_sqlite.Statement(csSQLSelect);
			stmt->NextRow();

			if (stmt->ValueInt(0))
			{
				CSqlStatement* stmt = m_sqlite.Statement(csSQLUpdate);	// then update
				if (!stmt->Execute()) SQLERROR(csSQLUpdate.GetBuffer(0))
				delete stmt;
			}
			else
			{
				CSqlStatement* stmt = m_sqlite.Statement(csSQLInsert);	// insert otherwise
				if (!stmt->Execute()) SQLERROR(csSQLInsert.GetBuffer(0))
				delete stmt;
			}
			while (stmt->NextRow())
				;
			delete stmt;
		}
		if (bDoOwnTransaction) SQL("COMMIT")
	}
	else
	{
		if (!configRS) return FALSE;

		CString csSQL;

		try
		{
			BeginTransaction();
			/*
				CDaoQueryDef editQD(this);
				csSQL.Format("UPDATE Config SET Config.%sValue = '%s' WHERE Config.%sKey = '%s';", cpCFG, valueEscaped, cpCFG, keyEscaped);
				editQD.Create("", csSQL);
				editQD.Execute(dbFailOnError);
				if (editQD.GetRecordsAffected())
			*/

			CString csCount;
			if (GetConfig("RecordingsCount", csCount))
			{
				csSQL = csSQLUpdate;
				Execute(csSQLUpdate);
			}
			else 
			{
				csSQL = csSQLInsert;
				Execute(csSQLInsert);	// if RecordingsCount entry wasn't already there, use insert
			}
			CommitTransaction();
		}
		catch( CADOException& e )
		{	
			// if UPDATE didn't work:
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			csSQL = "SQL statement causing the trouble: " + csSQL;
			DF(csSQL.GetBuffer(0));
			RollbackTransaction();
			return FALSE;
		}		
	}
	return TRUE;
}


// IncConfig -- increment numeric config data
// the value parameter takes the value to be added to the specified key
// return: FALSE if failed or TRUE if successful
BOOL CIndexDB::IncConfig(char *key, int value)
{
	//if (m_bIsSQLite && !strcmp(key, "recordingsCount")) return TRUE;	// SQLITE works correctly with its own counter
	DF("CIndexDB::IncConfig()");

	// for SQLite and some MS SQL Server use field names with preceeding 'CFG' (MS SQL Server making problems with theses 'keywords')
	char *cpCFG = m_bIsSQLite || MSSQLFix() ? "CFG" : "";
	char *cpTablename = m_bIsSQLite ? "" : "Config.";		// SQLite doesn't like explicit table name in this expression

	// assemble SQL command
	CString csSQLSelect, csSQLUpdate, csSQLInsert;
	char keyEscaped[20000];
	EscapeString(key, keyEscaped, 20000);
	csSQLSelect.Format("SELECT COUNT(*) FROM Config WHERE Config.%sKey = '%s';", cpCFG, keyEscaped);
	csSQLUpdate.Format("UPDATE Config SET %s%sValue = %s%sValue%c%d WHERE %s%sKey = '%s';", cpTablename, cpCFG, cpTablename, cpCFG, value<0? ' ' : '+', value, cpTablename, cpCFG, keyEscaped);
	csSQLInsert.Format("INSERT INTO Config VALUES ('%s','%d');", keyEscaped, value);
	
	if (m_bIsSQLite)
	{
		BOOL bDoOwnTransaction = m_sqlite.GetAutoCommit(); // if no transaction currently active, do my own one
		if (bDoOwnTransaction) SQL("BEGIN EXCLUSIVE")
		{
			// key already exists in config table?
			CSqlStatement* stmt = m_sqlite.Statement(csSQLSelect);
			stmt->NextRow();

			if (stmt->ValueInt(0))
			{
				CSqlStatement* stmt = m_sqlite.Statement(csSQLUpdate);	// then update
				if (!stmt->Execute()) SQLERROR(csSQLUpdate.GetBuffer(0))
				delete stmt;
			}
			else
			{
				CSqlStatement* stmt = m_sqlite.Statement(csSQLInsert);	// insert otherwise
				if (!stmt->Execute()) SQLERROR(csSQLInsert.GetBuffer(0))
				delete stmt;
			}
			while (stmt->NextRow())
				;
			delete stmt;
		}
		if (bDoOwnTransaction) SQL("COMMIT")
	}
	else
	{
		if (!configRS) return NULL;

		try
		{
			// for MS SQL Server use other field names
			char *cpCFG = MSSQLFix() ? "CFG" : "";

			BeginTransaction();
			CString cdDummy;
			if (GetConfig(key, cdDummy))
			{			
				Execute(csSQLUpdate);
			}
			else
			{
				Execute(csSQLInsert);
			}
			CommitTransaction();
		}
		catch( CADOException& e )
		{	
			// if UPDATE didn't work:
			if (m_show_messages)
				AfxMessageBox( 
						e.GetErrorMessage(), 
						MB_ICONEXCLAMATION );
			DF(e.GetErrorMessage().GetBuffer(0));
			RollbackTransaction();
			return FALSE;
		}		
	}
	return TRUE;
}


// GetConfig -- read out config data
// returns config key value
// return: FALSE if failed or TRUE if not 
BOOL CIndexDB::GetConfig(char *key, CString &value)
{
	DF("CIndexDB::GetConfig()");

	// for SQLite and some MS SQL Server use field names with preceeding 'CFG' (MS SQL Server making problems with theses 'keywords')
	char *cpCFG = m_bIsSQLite || MSSQLFix() ? "CFG" : "";

	// assemble SQL command
	CString csSQL;
	char keyEscaped[20000];
	EscapeString(key, keyEscaped, 20000);
	csSQL.Format("SELECT * FROM Config WHERE Config.%sKey = '%s';", cpCFG, keyEscaped);

	if (m_bIsSQLite)
	{
		CSqlStatement* stmt = m_sqlite.Statement(csSQL);
		if (!stmt->NextRow()) { delete stmt; return FALSE; }
		value = stmt->ValueString(1);
		while (stmt->NextRow())
			;
		delete stmt;
	}
	else
	{
		if (!configRS) return NULL;

		COleVariant var;

		try
		{	
			//csSQL.Format("Config.%sKey = '%s'", cpCFG, keyEscaped);
			//if (!configRS->GetRecordCount()) return FALSE;
			CADORecordset findkeyRS(this);
			findkeyRS.Open(csSQL);
			try
			{
				//configRS->FindFirst(csSQL);	
				if (!findkeyRS.GetRecordCount()) return FALSE;
			}
			catch( _com_error &e )
			{
				if (e.Error() == 0x800a0cc1) // not found? may happen...
					return FALSE;
				else	// other errors are not allowed to happen unnoticed:
				{
					_bstr_t bstrSource(e.Source());
					_bstr_t bstrDescription(e.Description());

					DF( "Exception thrown for configRS->FindFirst(csSQL):");
					DF1( "\tCode = %08lx\n",      e.Error());
					DF1( "\tCode meaning = %s\n", e.ErrorMessage());
					DF1( "\tSource = %s\n",       (LPCTSTR) bstrSource);
					DF1( "\tDescription = %s\n",  (LPCTSTR) bstrDescription);
					return FALSE;
				}
			}
	
			csSQL.Format("%sValue", cpCFG);
			//configRS->GetFieldValue(csSQL, value); 
			findkeyRS.GetFieldValue(csSQL, value); 
		}
		catch( CADOException& e )
		{
			//if (m_show_messages)
			//	AfxMessageBox( 
			//			e->m_pErrorInfo->m_strDescription, 
			//			MB_ICONEXCLAMATION );
			//DF(e->m_pErrorInfo->m_strDescription.GetBuffer(0));
			e;
			return FALSE;
		}		
	}

	return TRUE;
}

// for MS SQL Server use other field names 
// ( 'key' and 'value' fields being not being interpreted by stupid MS SQL command parser )
BOOL CIndexDB::MSSQLFix()
{
	CString csSQL;

	CADORecordset configRSFieldNames(this);
	csSQL = "SELECT * FROM Config WHERE 1 = 0;";	// just get the tables fields 
	configRSFieldNames.Open(GetActiveConnection(), csSQL, CADORecordset::openQuery);

	CADOFieldInfo dfi;
	configRSFieldNames.GetFieldInfo(0, &dfi);	// query first column
	CString csName = dfi.m_strName;
	csName.MakeLower();
	if (csName == "cfgkey" || csName == "cfgvalue")
		return TRUE;
	else if (csName == "key" || csName == "value")
		return FALSE;
	else
	{
		DF(">>>>>>> Unable to identify config table field names.");
		return FALSE;
	}
}

//----- helper -----

// modifies a string to be used in a SQL statement
int CIndexDB::EscapeString(char *szOrig, char *szEscaped, int bufSize)
{
	int newLen = 0;
	int origLen = (int)strlen(szOrig);

	for(int i = 0; i < origLen; i++)
	{
		switch(szOrig[i])
		{
			case '\'':
				if (bufSize > newLen + 2)
				memcpy(&szEscaped[newLen], "''", 2);
				newLen += 2;
				break;
			default:
				if (bufSize > newLen + 1)
				szEscaped[newLen] = szOrig[i];
				newLen++;
				break;
		}
	}

	if (newLen < bufSize)
		szEscaped[newLen] = '\0';

	return newLen;
}

// FillVariant -- helper function to write recordset values
void CIndexDB::FillVariant(COleVariant & var, LPCTSTR lpszSrc)
{
    var.vt=VT_BSTR;
    if (lpszSrc==NULL)
        var.bstrVal=NULL;
    else
    {
#ifndef _UNICODE
    int nLen = lstrlen(lpszSrc);
    var.bstrVal = SysAllocStringByteLen(lpszSrc, nLen);
#else
    var.bstrVal = SysAllocString(lpszSrc);
#endif
    }
}

