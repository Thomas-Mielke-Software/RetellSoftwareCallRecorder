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
*	Beschreibung: class TMTabelle
*	
*	Tabelle.cpp : implementation file
*	Klasse zur dateimäßigen Repräsentation von Tabellen
*	
*	$Log:   D:/pvcsarch/telar/tmtabelle.cpv  $
* 
*    Rev 1.69   Dec 19 2007 17:27:42   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.68   Oct 11 2007 10:15:18   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.67   Sep 21 2007 15:47:30   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.66   Aug 14 2007 14:09:20   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.65   May 09 2007 10:24:00   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.64   Nov 16 2006 14:59:58   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.63   Nov 13 2006 13:26:36   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.62   Jun 12 2006 15:13:32   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.61   Nov 25 2005 01:32:36   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.60   Nov 23 2005 16:11:36   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.59   Nov 11 2005 09:51:10   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.58   Jul 11 2005 08:52:54   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.57   Jul 05 2005 01:50:34   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.56   Jun 28 2005 01:46:38   tmielke
* v1.72 build 1250
* 
*    Rev 1.55   Jun 02 2005 01:30:40   tmielke
* v1.72 build 1207
* 
*    Rev 1.54   May 18 2005 13:47:22   tmielke
* v1.72 build 1200
* 
*    Rev 1.53   Mar 18 2005 16:12:12   tmielke
*  
* 
*    Rev 1.52   Mar 12 2005 07:08:50   tmielke
* v1.69
* 
*    Rev 1.51   Feb 22 2005 16:53:30   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.50   Nov 21 2004 01:29:24   tmielke
* v1.66 build 883
* 
*    Rev 1.49   Jun 01 2004 05:07:24   tmielke
* v1.66 build 846
* improved stability
* 
*    Rev 1.48   Dec 04 2003 03:36:54   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.47   Nov 18 2003 09:39:48   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.46   Oct 03 2003 01:22:16   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.45   Sep 23 2003 01:48:12   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.44   Sep 12 2003 01:12:18   tmielke
*  
* 
*    Rev 1.43   Sep 11 2003 04:04:10   tmielke
*  
* 
*    Rev 1.42   Sep 04 2003 00:55:34   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.41   Aug 04 2003 00:35:08   tmielke
* v1.64
* 
*    Rev 1.40   Jun 09 2003 15:25:24   tmielke
* v1.63 final
* 
*    Rev 1.39   Apr 07 2003 09:53:22   tmielke
* pre release 28 - speeded up delete and move recordings
* 
*    Rev 1.38   Mar 27 2003 05:26:56   tmielke
* Data Link DLL speeded up
* recording delay fix
* 
*    Rev 1.37   Jun 05 2002 19:32:00   tmielke
* v1.62
* 
*    Rev 1.36   May 05 2002 11:57:12   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.35   Mar 15 2002 20:23:04   tmielke
* v1.60
* 
*    Rev 1.34   Nov 07 2001 02:40:58   tmielke
* v1.59 bugfix release
* 
*    Rev 1.33   Nov 06 2001 05:28:22   tmielke
* v1.58a
* 
*    Rev 1.32   Oct 12 2001 16:24:26   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.31   Sep 14 2001 04:13:22   
* v1.57
* 
*    Rev 1.30   06 Jun 2001 02:02:14   tmielke
* offizielle release 1.55
* 
*    Rev 1.29   17 May 2001 02:02:30   tmielke
* v1.54
* 
*    Rev 1.28   12 Feb 2001 19:38:02   tmielke
* v1.53
* 
*    Rev 1.27   20 Dec 2000 18:20:26   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.26   04 Dec 2000 02:24:36   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.25   19 Oct 2000 02:30:22   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.24   19 Jun 2000 15:55:16   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.23   24 Mar 2000 22:37:02   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.22   18 Mar 2000 11:41:02   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.21   17 Mar 2000 05:32:34   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.20   05 Mar 2000 05:21:44   tmielke
* v1.43
* 
*    Rev 1.19   05 Mar 2000 01:23:04   tmielke
* safety check-in
* 
*    Rev 1.18   28 Feb 2000 00:31:10   tmielke
* v1.42
* 
*    Rev 1.17   24 Feb 2000 15:28:30   tmielke
* v1.41
* 
*    Rev 1.16   24 Feb 2000 03:23:00   tmielke
* schnelle Ändeerungen für Retell
* 
*    Rev 1.15   24 Feb 2000 01:23:40   tmielke
* v1.39
* 
*    Rev 1.14   18 Feb 2000 00:39:24   tmielke
* v1.38
* 
*    Rev 1.13   15 Dec 1999 03:34:30   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.12   01 Dec 1999 18:45:48   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.11   16 Aug 1999 10:31:50   tmielke
* v1.34
* 
*    Rev 1.10   14 Aug 1999 06:49:44   tmielke
* Passwortschutz verfeinert
* 
*    Rev 1.9   09 Aug 1999 07:51:08   tmielke
* Encryption eingebaut
* 
*    Rev 1.8   07 Jun 1999 18:37:04   tmielke
* Multi Language Version
* 
*    Rev 1.7   05 Apr 1999 09:39:36   tmielke
* Nachtrag v1.32
* 
*    Rev 1.6   05 Apr 1999 08:14:30   tmielke
* Info-Screen Logo verändert
* Website www.bpsgmbh.de/trs als hotlink in der hilfebox
* E-Mail support@bpsgmbh.de als hotlink in der hilfebox
* 
*    Rev 1.5   22 Mar 1999 16:26:32   tmielke
* v1.31 Letzte-Aufnahme-Button und Logo
* 
*    Rev 1.4   20 Mar 1999 18:52:36   tmielke
* v1.3
* 
*    Rev 1.3   18 Mar 1999 13:27:42   tmielke
* v0.8 - Demoversion fertig gemacht
* 
*    Rev 1.2   03 Mar 1999 13:40:26   tmielke
* Version Label v0.6
* 
*    Rev 1.1   01 Mar 1999 12:47:06   tmielke
* Indexdatei eingebaut, Gesprächspartner & Notizen, Gesprächslänge...
* 
*    Rev 1.0   01 Mar 1999 05:53:36   tmielke
* initial revision
* 
*/

#include "stdafx.h"
#include "TMTabelle.h"
#include "telar.h"
#include "ProgDlg.h"

//--- Zeile ----

TMZeile::TMZeile()
{
	spalte = NULL;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1)
{
	spalte = new TMZelle;
	spalte->data = c1;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2, CString &c3)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	spalte->next->next = new TMZelle;
	spalte->next->next->data = c3;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2, CString &c3, CString &c4)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	spalte->next->next = new TMZelle;
	spalte->next->next->data = c3;
	spalte->next->next->next = new TMZelle;
	spalte->next->next->next->data = c4;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2, CString &c3, CString &c4, CString &c5)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	spalte->next->next = new TMZelle;
	spalte->next->next->data = c3;
	spalte->next->next->next = new TMZelle;
	spalte->next->next->next->data = c4;
	spalte->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->data = c5;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2, CString &c3, CString &c4, CString &c5, CString &c6)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	spalte->next->next = new TMZelle;
	spalte->next->next->data = c3;
	spalte->next->next->next = new TMZelle;
	spalte->next->next->next->data = c4;
	spalte->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->data = c5;
	spalte->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->data = c6;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2, CString &c3, CString &c4, CString &c5, CString &c6, CString &c7, CString &c8)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	spalte->next->next = new TMZelle;
	spalte->next->next->data = c3;
	spalte->next->next->next = new TMZelle;
	spalte->next->next->next->data = c4;
	spalte->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->data = c5;
	spalte->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->data = c6;
	spalte->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->data = c7;
	spalte->next->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->next->data = c8;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2, CString &c3, CString &c4, CString &c5, CString &c6, CString &c7, CString &c8, CString &c9)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	spalte->next->next = new TMZelle;
	spalte->next->next->data = c3;
	spalte->next->next->next = new TMZelle;
	spalte->next->next->next->data = c4;
	spalte->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->data = c5;
	spalte->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->data = c6;
	spalte->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->data = c7;
	spalte->next->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->next->data = c8;
	spalte->next->next->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->next->next->data = c9;
	next   = NULL;
}

TMZeile::TMZeile(CString &c1, CString &c2, CString &c3, CString &c4, CString &c5, CString &c6, CString &c7, CString &c8, CString &c9, CString &c10)
{
	spalte = new TMZelle;
	spalte->data = c1;
	spalte->next = new TMZelle;
	spalte->next->data = c2;
	spalte->next->next = new TMZelle;
	spalte->next->next->data = c3;
	spalte->next->next->next = new TMZelle;
	spalte->next->next->next->data = c4;
	spalte->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->data = c5;
	spalte->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->data = c6;
	spalte->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->data = c7;
	spalte->next->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->next->data = c8;
	spalte->next->next->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->next->next->data = c9;
	spalte->next->next->next->next->next->next->next->next->next = new TMZelle;
	spalte->next->next->next->next->next->next->next->next->next->data = c10;
	next   = NULL;
}

TMZeile::~TMZeile()
{
	TMZelle *p, *p_temp;
	p = spalte;
	while (p)
	{
		p_temp = p;
		p = p->next;
		delete p_temp;
	}
	spalte = NULL;
}

CString &TMZeile::Spalte(int spalte_nr)
{
	int i;
	TMZelle **spp = &spalte;

	i = 0; 
	while (TRUE)
	{
		// wenn nötig: Spalte erzeugen...
		if (!*spp)
		{
			*spp = new TMZelle;
		}
		if (i >= spalte_nr) break;
		spp = &((*spp)->next);
		i++;
	}
	return (*spp)->data;
}

TMZeile &TMZeile::operator=(TMZeile &tmz)
{
	// alte zeile löschen
	TMZelle *p, *p_temp;
	p = spalte;
	while (p)
	{
		p_temp = p;
		p = p->next;
		delete p_temp;
	}
	spalte = NULL;

	// kopieren
	TMZelle **spp_src = &tmz.spalte;
	TMZelle **spp_dest = &spalte;
	while (*spp_src)
	{
		*spp_dest = new TMZelle;
		(*spp_dest)->data = (*spp_src)->data;

		spp_src = &((*spp_src)->next);
		spp_dest = &((*spp_dest)->next);
	}
	return *this;
}

//--- Spalte ---

TMZelle::TMZelle()
{
	next   = NULL;
}

TMZelle::~TMZelle()
{
}

//--- Tabelle -------------------------

TMTabelle::TMTabelle(char *magic_id, int n_spalten, int version)
{
	m_magic = (CString)magic_id;
	m_spaltenzahl = n_spalten;
	m_version = version;
	tabelle = NULL;
}

TMTabelle::~TMTabelle()
{
	Erase();
}

void TMTabelle::Erase()
{
	TMZeile *p, *p_temp;
	p = tabelle;
	while (p)
	{
		p_temp = p;
		p = p->next;
		delete p_temp;
	}
	tabelle = NULL;
}

TMZeile *TMTabelle::Find(int spalte_nr, CString &suchstring)
{
	TMZeile *p;
	int i;

	p = tabelle;
	while (p)
	{
		TMZelle *sp = p->spalte;

		for (i = 0; i < spalte_nr && sp; i++)
			sp = sp->next;

		if (sp)
			if (sp->data == suchstring) return p;

		p = p->next;
	}
	return NULL;
}


// TRUE zurück wenn ok
// *version wird mit der wirklich gelesenen Versionsnummer gefüttert
BOOL TMTabelle::Read(char *filename, int *version, BOOL only_header)
{
	CFile pFile;
	char *liste;
	int  size_of_liste;

	if (!only_header) Erase();

	// Datei lesen
	if (pFile.Open(filename, CFile::modeRead|CFile::shareDenyNone))
	{
		size_of_liste = (int)pFile.GetLength() + 3;
		if (only_header && size_of_liste > 10000)
			size_of_liste = 10000;	// sollte für den header reichen
		liste = new char[size_of_liste]; 
		
		
		memset(liste+size_of_liste-3, '\0', 3);
		
		pFile.Seek(0, CFile::begin);
		pFile.Read(liste, size_of_liste-3);

		pFile.Close();
	}
	else
	{
		//char buffer[1000], buffer2[200];
		//LANG2BUFFER(IDS_STRING57, buffer2);
		//sprintf(buffer, buffer2, filename);	// "Die Datei '%s' konnte nicht geöffnet werden!"
		//AfxMessageBox(buffer, MB_ICONSTOP);
		return FALSE;
	}
	
	return ReadIn(&pFile, liste, size_of_liste, version, only_header);
}


// TRUE zurück wenn ok
// *version wird mit der wirklich gelesenen Versionsnummer gefüttert
BOOL TMTabelle::UpdateZeile(char *filename, int *version, int spalte_nr, CString &suchstring, TMZeile &zeile)
{
	CFile pFile;
	char *liste;
	int  size_of_liste;

	Erase();

	// Datei lesen
	if (pFile.Open(filename, CFile::modeReadWrite|CFile::shareExclusive))
	{
		liste = new char[(size_of_liste = (int)pFile.GetLength() + 3)]; 
		
		memset(liste+size_of_liste-3, '\0', 3);
		
		pFile.Seek(0, CFile::begin);
		pFile.Read(liste, size_of_liste-3);
	}
	else
	{
		//char buffer[1000], buffer2[200];
		//LANG2BUFFER(IDS_STRING57, buffer2);
		//sprintf(buffer, buffer2, filename);	// "Die Datei '%s' konnte nicht geöffnet werden!"
		//AfxMessageBox(buffer, MB_ICONSTOP);
		return FALSE;
	}
	
	BOOL ret = ReadIn(&pFile, liste, size_of_liste, version, FALSE);

	if (ret != TRUE) goto ExitClose;

	TMZeile *ptmz;
	if (!(ptmz = Find(spalte_nr, suchstring)))
	{
		ret = FALSE;
		goto ExitClose;
	}

	// Zeile kopieren
	*ptmz = zeile;

	WriteWithoutOpen(&pFile);

ExitClose:
	pFile.Close();
	return ret;
}


// TRUE zurück wenn ok
// *version wird mit der wirklich gelesenen Versionsnummer gefüttert
BOOL TMTabelle::DeleteZeilen(char *filename, int *version, int spalte_nr, CString **psuchstrings, int n)
{
	CFile pFile;
	char *liste;
	int  size_of_liste;
	int i;
	CProgressDlg dlg(IDS_STRING157);

	Erase();

	// Datei lesen
	if (pFile.Open(filename, CFile::modeReadWrite|CFile::shareExclusive))
	{
		liste = new char[(size_of_liste = (int)pFile.GetLength() + 3)]; 
		
		memset(liste+size_of_liste-3, '\0', 3);
		
		pFile.Seek(0, CFile::begin);
		pFile.Read(liste, size_of_liste-3);
	}
	else
	{
		//char buffer[1000], buffer2[200];
		//LANG2BUFFER(IDS_STRING57, buffer2);
		//sprintf(buffer, buffer2, filename);	// "Die Datei '%s' konnte nicht geöffnet werden!"
		//AfxMessageBox(buffer, MB_ICONSTOP);
		return FALSE;
	}
	
	BOOL ret = ReadIn(&pFile, liste, size_of_liste, version, FALSE);

	if (ret != TRUE) goto ExitClose;

	dlg.Create(AfxGetMainWnd());
	dlg.SetRange(0, n);
	dlg.SetPos(0);
	dlg.ShowWindow(SW_SHOW);

	for (i = 0; i < n; i++)
	{
		dlg.SetPos(i);

		TMZeile *ptmz;
		if ((ptmz = Find(spalte_nr, *psuchstrings[i])))
		{
			// Zeile löschen
			{
				TMZeile **ppt = &tabelle;

				while (*ppt)
				{
					if (ptmz == *ppt) 
					{
						*ppt = (*ppt)->next;
						delete ptmz;
						break;
					}
					ppt = &((*ppt)->next);
				}
			}
		}
	}

	dlg.EndDialog(1);

	WriteWithoutOpen(&pFile);

ExitClose:
	pFile.Close();
	return ret;
}


BOOL TMTabelle::ReadIn(CFile *pFile, char *liste, int size_of_liste, int *version, BOOL only_header)
{
	BOOL bReturn = TRUE;
	int leerspalten = 0;

	// fileheader
	char *cp = liste;
	CString file_magic   = cp; cp += file_magic.GetLength()   + 1;
	CString file_version = cp; cp += file_version.GetLength() + 1;
	CString file_spalten = cp; cp += file_spalten.GetLength() + 1;
	if (file_magic != m_magic)
	{
		LANG_MESSAGEBOX2(IDS_STRING58, MB_ICONSTOP);	// "Ungültiges Dateiformat."
		bReturn = FALSE;
		goto ErrorDeleteListe;
	}
	if (atoi(file_version.GetBuffer(0)) > m_version)
	{
		LANG_MESSAGEBOX2(IDS_STRING59, MB_ICONSTOP);	// "Die Datei wurde mit einer neueren Version des Programms gespeichert und kann mit dieser veralteten Version nicht mehr gelesen werden!"
		bReturn = FALSE;
		goto ErrorDeleteListe;
	}
	*version = atoi(file_version.GetBuffer(0));
	if (atoi(file_spalten.GetBuffer(0)) != m_spaltenzahl)
	{
		// wenn Datei weniger Spalten hat als Programm: Spalten leer lassen
		if (atoi(file_spalten.GetBuffer(0)) < m_spaltenzahl)
			leerspalten = m_spaltenzahl - atoi(file_spalten.GetBuffer(0));
		else // ansonsten Fehler:
		{
			LANG_MESSAGEBOX2(IDS_STRING60, MB_ICONSTOP);	// "Die Tabellen-Spaltenzahl der Datei differiert mit der des Programms."
			bReturn = FALSE;
			goto ErrorDeleteListe;
		}
	}

	if (only_header) goto ErrorDeleteListe;

	// tabelle füllen
	{
		TMZeile **zpp = &tabelle;
		while (cp < liste + size_of_liste-3)	// solange noch nicht Ende der Datei
		{
			int i;
			*zpp = new TMZeile;
			TMZelle **spp = &((*zpp)->spalte);
			
			// solange noch nicht Ende der Zeile
			for (i = 0; i < atoi(file_spalten.GetBuffer(0)) && cp < liste + size_of_liste-3; i++)		
			{
				*spp = new TMZelle;
				
				(*spp)->data = cp;	// Zelle mit Daten füllen
				cp += (*spp)->data.GetLength()+1;
//if ((*spp)->data == "RH20040423-155509.wav")
//{
//	int xxx = 1;	// break here
//}
				spp = &((*spp)->next);
			}

			// Leerspalten erzeugen
			for (i = 0; i < leerspalten; i++)		
			{
				*spp = new TMZelle;
				spp = &((*spp)->next);
			}

			zpp = &((*zpp)->next);
		}
	}

ErrorDeleteListe:

	delete liste;
	return bReturn;
}

void TMTabelle::WriteCStringToFile(CString &cs, CFile *pFile)
{
	pFile->Write(cs.GetBuffer(0), cs.GetLength()+1);
}

void TMTabelle::Write(char *filename)
{
	CFile File;

	if (File.Open(filename, CFile::modeWrite | CFile::modeCreate))
	{
		WriteWithoutOpen(&File);
		File.Close();
	}
}


void TMTabelle::WriteWithoutOpen(CFile *pFile)
{
	char buffer[100];

	pFile->Seek(0, CFile::begin);

	WriteCStringToFile(m_magic, pFile);
	sprintf(buffer, "%d", m_version);
	WriteCStringToFile((CString)buffer, pFile);
	sprintf(buffer, "%d", m_spaltenzahl);
	WriteCStringToFile((CString)buffer, pFile);

	// tabelle füllen
	{
		TMZeile *zp = tabelle;
		while (zp)	// solange noch nicht Ende der Tabelle
		{
			int i;
			TMZelle *sp = zp->spalte;
			
			// solange noch nicht Ende der Zeile
			for (i = 0; i < m_spaltenzahl; i++)		
			{
				if (sp)
				{
					WriteCStringToFile(sp->data, pFile);					
					sp = sp->next;
				}
				else
					WriteCStringToFile((CString)"", pFile);	
			}

			zp = zp->next;
		}
	}
	pFile->SetLength(pFile->GetPosition());
}

void TMTabelle::Append(char *filename, TMZeile *zeile)
{
	CFile pFile;

	TRY
	{
		if (pFile.Open(filename, CFile::modeWrite|CFile::modeRead|CFile::shareExclusive))
		{
			pFile.SeekToEnd();

			// zeile schreiben
			{
				int i;
				TMZelle *sp = zeile->spalte;
				
				// solange noch nicht Ende der Zeile
				for (i = 0; i < m_spaltenzahl; i++)		
				{
					if (sp)
					{
						WriteCStringToFile(sp->data, &pFile);					
						sp = sp->next;
					}
					else
						WriteCStringToFile((CString)"", &pFile);	
				}
			}

			pFile.Close();
		}
	}
	CATCH( CFileException, e )
	{	
		CString csError;
		csError.Format("Unable to add line '%s...' to index file '%s'", zeile->Spalte(0).GetBuffer(0), filename);
		DF(csError.GetBuffer(0));
		AfxMessageBox(csError);
		return;	// close instance
	}
	END_CATCH
}
