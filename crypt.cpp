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
* 
* Note: This is rather a pseudo encryption. Don't use in new projects.
*
*	Beschreibung:
*	
*	Encryption/Decryption Hilfsfunktionen und Zufallsgenerator
*	
*	$Log:   D:/pvcsarch/telar/crypt.cpv  $
* 
*    Rev 1.56   Dec 19 2007 17:27:30   tmielke
* Adaptions to Windows Vista
* 
*    Rev 1.55   Oct 11 2007 10:15:02   tmielke
* Made the soundcard recognition more flexible in case plug and play
* soundcards have switched places.
* 
*    Rev 1.54   Sep 21 2007 15:47:18   tmielke
* Added Dutch translations and some additional debug code.
* 
*    Rev 1.53   Aug 14 2007 14:09:08   tmielke
* v1.83 resolved issues with voice modems and other exotic audio devices.
* 
*    Rev 1.52   May 09 2007 10:23:44   tmielke
* Word wrap now also enabled for edit box in edit record entry dialog.
* Changed the 'Maximise on line signal' checkbox to a numeric value holding 
* the number of seconds before the window maximizes to prevent the software 
* from popping up if a noise sets the recording off. 
* Added an option 'Minimize after automatic recording'.
* Improved usability of options screen by using sliders and spin buttons.
* 
*    Rev 1.51   Nov 16 2006 14:59:46   tmielke
* v1.80 -- Resolves compatibility issues with Windows NT and 9X version. 
* (SHGetSpecialFolder now from redisributable shfolder.dll included in the 
* setup rather than shell32.dll)
* 
*    Rev 1.50   Nov 13 2006 13:26:22   tmielke
* v1.79 build 2100 -- final network licensable version
* 
*    Rev 1.49   Jun 12 2006 15:13:22   tmielke
* v1.78:
*  - If a recording has been done using a password, this password is required to delete the recording (#211)
* - Now using a word-wrap edit box for the notes field (#336)
* - Playback volume control added (#314)
* 
*    Rev 1.48   Nov 25 2005 01:32:18   tmielke
* v1.76: several bugfixes
* 
*    Rev 1.47   Nov 23 2005 16:11:20   tmielke
* v1.75 solves the following issues:
* - Master master password wasn't queried when opening the scr window by clicking on the icon in the start menu
* - the application window will now really get the focus when automatically opened with 'maximize on signal'
* - same with master password when window maximized after clicking on the system tray icon (but not when maximized with start menu icon)
* - crash after FTP update is now prohibited
* - the software will now start after setup if the check on the last setup screen is set.
* 
*    Rev 1.46   Nov 11 2005 09:50:58   tmielke
* v1.74 release
* New layout of the playback tab with tabular list, including in-field
* editing of name and reference (F2 key).
* Abandoned Microsoft database engine. The new index file is now more robust
* in multiuser environments.
* 
*    Rev 1.45   Jul 11 2005 08:52:34   tmielke
* v1.74 build 1632 (alphatest version)
* - SQLite index file
* - CListCtrls on playback tab
* - Workstations table support
* 
*    Rev 1.44   Jul 05 2005 01:50:18   tmielke
* improved performance & stability when copying or deleting recordings
* 
*    Rev 1.43   Jun 28 2005 01:46:26   tmielke
* v1.72 build 1250
* 
*    Rev 1.42   Jun 02 2005 01:30:26   tmielke
* v1.72 build 1207
* 
*    Rev 1.41   May 18 2005 13:47:10   tmielke
* v1.72 build 1200
* 
*    Rev 1.40   Mar 18 2005 16:12:00   tmielke
*  
* 
*    Rev 1.39   Mar 12 2005 07:08:32   tmielke
* v1.69
* 
*    Rev 1.38   Feb 22 2005 16:53:22   tmielke
* v1.67 build 960
* Added support for 957 Data Integration Linc to allow access in automatic recording mode.
* 
*    Rev 1.37   Nov 21 2004 01:29:16   tmielke
* v1.66 build 883
* 
*    Rev 1.36   Dec 04 2003 03:36:42   tmielke
* v1.66 buid 730 -- Database Index File Pre-Release
* 
*    Rev 1.35   Nov 18 2003 09:39:42   tmielke
* komisch, Workfile älter als Archive...
* Checkin anyway...
* 
*    Rev 1.34   Oct 03 2003 01:22:08   tmielke
* v1.65 build 572:
* - Added support for master password.
* - Fixed spelling of export message.
* - Fixed export with encryption level 0.
* 
* 
*    Rev 1.33   Sep 23 2003 01:48:04   tmielke
* v1.64 build 557 (improved control tone detection)
* 
*    Rev 1.32   Sep 12 2003 01:12:10   tmielke
*  
* 
*    Rev 1.31   Sep 11 2003 04:04:04   tmielke
*  
* 
*    Rev 1.30   Sep 04 2003 00:55:26   tmielke
* v1.64 build 514
* C: drive licensing problem solved
* added build count to better determine versions
* fixed problem with disk key licensing
* 
*    Rev 1.29   Aug 04 2003 00:34:58   tmielke
* v1.64
* 
*    Rev 1.28   Jun 09 2003 15:25:16   tmielke
* v1.63 final
* 
*    Rev 1.27   Jun 05 2002 19:31:54   tmielke
* v1.62
* 
*    Rev 1.26   May 05 2002 11:56:16   tmielke
* added machine name to subject line when requesting code via MAPI
* auto-inserted separators in search screen
* 
*    Rev 1.25   Mar 15 2002 20:21:50   tmielke
* v1.60
* 
*    Rev 1.24   Jan 28 2002 16:11:10   tmielke
* License confirmation
* 
*    Rev 1.23   Nov 07 2001 02:08:14   tmielke
* v1.59 bugfix release
* 
*    Rev 1.22   Nov 06 2001 05:26:50   tmielke
* v1.58a
* 
*    Rev 1.21   Oct 12 2001 16:22:42   tmielke
* v1.58 bugfix wav export
* 
*    Rev 1.20   Sep 14 2001 04:12:28   
* v1.57
* 
*    Rev 1.19   06 Jun 2001 02:00:06   tmielke
* offizielle release 1.55
* 
*    Rev 1.18   17 May 2001 02:01:04   tmielke
* v1.54
* 
*    Rev 1.17   12 Feb 2001 19:36:46   tmielke
* v1.53
* 
*    Rev 1.16   20 Dec 2000 18:18:16   tmielke
* letzter check-in der VC++ 4.2 Version vor Wechsel auf Defeloper Studio 6.0
* 
*    Rev 1.15   04 Dec 2000 02:22:50   tmielke
* v1.52
* TPT-Anpassungen: Fernsteuerung, Folder scannen, Passwortsperre
* 
*    Rev 1.14   19 Oct 2000 02:28:38   tmielke
* v1.51:
* - ALC
* Wenn Hauptfenster minimized, progress bar nicht anzeigen
* wav-Dateien löschen beim Abbruch der Aufzeichnung
* Nullabgleich beim Signal
* (v1.50 war alles von dem 1.8.00)
* 
* 
*    Rev 1.13   19 Jun 2000 15:54:02   tmielke
* v1.44 letzte TRS-Version
* 
*    Rev 1.12   24 Mar 2000 22:36:12   tmielke
* v1.44 encrypting im hintergrund
* 
*    Rev 1.11   18 Mar 2000 11:40:10   tmielke
* zur sicherheit eingecheckt
* 
*    Rev 1.10   17 Mar 2000 05:31:44   tmielke
* v1.6 jetzt tauglich für Österreich/Schweitz
* 
*    Rev 1.9   05 Mar 2000 05:20:46   tmielke
* v1.43
* 
*    Rev 1.8   28 Feb 2000 00:30:30   tmielke
* v1.42
* 
*    Rev 1.7   24 Feb 2000 15:27:48   tmielke
* v1.41
* 
*    Rev 1.6   24 Feb 2000 01:22:38   tmielke
* v1.39
* 
*    Rev 1.5   18 Feb 2000 00:38:44   tmielke
* v1.38
* 
*    Rev 1.4   15 Dec 1999 03:33:34   tmielke
* v1.37 CAboutDlg auf OnEraseBkgnd umgestellt und Archivpfad prüfen
* 
*    Rev 1.3   01 Dec 1999 18:45:16   tmielke
* v1.36 BPS -> Frohberg GmbH
* 
*    Rev 1.2   01 Dec 1999 16:57:32   tmielke
* v1.34
* 
*    Rev 1.1   25 Aug 1999 12:29:56   tmielke
* ECL - mit fester Länge
* 
*    Rev 1.0   25 Aug 1999 05:57:36   tmielke
* EC, DC und Zufallsgenerator in crypt.h ausgelagert
*/

#if !defined(_USE_AFX_)
#include <windows.h>
#else
#include "stdafx.h"
#endif

#include <stdio.h>
#include <time.h>
#include "crypt.h"

// dest hat die Größe von 3 x source + 12 ( + Nullzeichen ) 
void EC(int m, int n, char *source, char *dest)
{
	ECL(m, n, source, dest, strlen(source));
}

void ECL(int m, int n, char *source, char *dest, int length)
{
	unsigned char o;
	DWORD crc = 0L;

	m %= 31328;
	n %= 30081;
	unsigned char *cp1 = (unsigned char *)source;
	char *cp2 = dest;

	rangen rg;

	rg.rmarin(m, n);

	while (cp1 - (unsigned char *)source < length)
	{
		DWORD carry = crc & 0x80000000;
		crc <<= 1;
		carry >>= 31;
		crc |= carry;
		crc ^= *cp1;

		o = *cp1 ^ (unsigned char)((float)rg.ranmar() * 256);
		sprintf(cp2, "%03d", (int)o);

		cp2 += 3;
		cp1++;
	}

	// crc mit encrypten!
	unsigned char a = (unsigned char)((float)rg.ranmar() * 256);
	unsigned char b = (unsigned char)((float)rg.ranmar() * 256);
	unsigned char c = (unsigned char)((float)rg.ranmar() * 256);
	unsigned char d = (unsigned char)((float)rg.ranmar() * 256);

	a ^= (BYTE)((DWORD)(crc >> 24));
	b ^= (BYTE)((DWORD)(crc >> 16) & 0xff);
	c ^= (BYTE)((DWORD)(crc >> 8)  & 0xff);
	d ^= (BYTE)((DWORD) crc        & 0xff);

	sprintf(cp2, "%03d%03d%03d%03d", (int)a, (int)b, (int)c, (int)d);
	cp2+=12;
	*cp2='\0';
}


// dest hat die Größe von source / 3 - 4 ( + Nullzeichen!!! ) 
BOOL DC(int m, int n, char *source, char *dest)
{
	unsigned char o;
	DWORD crc = 0L;

	m %= 31328;
	n %= 30081;
	char *cp1 = source;
	unsigned char *cp2 = (unsigned char *)dest;

	rangen rg;
	rg.rmarin(m, n);

	while (*cp1)
	{
		char buffi[4];
		strncpy(buffi, cp1, 3);
		buffi[3] = '\0';
		o = (unsigned char)atoi(buffi);

		*cp2 = o ^ (unsigned char)((float)rg.ranmar() * 256);

		if (strlen(cp1) > 12)
		{
			DWORD carry = crc & 0x80000000;
			crc <<= 1;
			carry >>= 31;
			crc |= carry;
			crc ^= *cp2;
		}

		cp2++;
		cp1+=3;
	}
	*cp2='\0';

	DWORD dcrc =  (cp2[-4] << 24)
				| (cp2[-3] << 16)
				| (cp2[-2] << 8)
				| (cp2[-1]);

	return (dcrc == crc);
}


#pragma optimize("p", off)

// random number Generator //

rangen::rangen()
{
	bTest = FALSE;
}

void rangen::rmarin(int ij, int kl)
{
/*
C This is the initialization routine for the random number generator RANMAR()
C NOTE: The seed variables can have values between:    0 <= IJ <= 31328
C                                                      0 <= KL <= 30081
C The random number sequences created by these two seeds are of sufficient 
C length to complete an entire calculation with. For example, if sveral 
C different groups are working on different parts of the same calculation,
C each group could be assigned its own IJ seed. This would leave each group
C with 30000 choices for the second seed. That is to say, this random 
C number generator can create 900 million different subsequences -- with 
C each subsequence having a length of approximately 10^30.
C 
C Use IJ = 1802 & KL = 9373 to test the random number generator. The
C subroutine RANMAR should be used to generate 20000 random numbers.
C Then display the next six random numbers generated multiplied by 4096*4096
C If the random number generator is working properly, the random numbers
C should be:
C           6533892.0  14220222.0  7275067.0
C           6172232.0  8354498.0   10633180.0
*/
	int i, j, k, l, ii, jj, m;
	float s, t;
	
	ij %= 31328;
	kl %= 30081;

	i = (ij/177)%177 + 2;
	j = ij%177 + 2;
	k = (kl/169)%178 + 1;
	l = kl%169;
	
	for (ii=1; ii<=97; ii++) {
		s = (float)0.0;
		t = (float)0.5;
		for (jj=1; jj<=24; jj++) {
			m = (((i*j)%179)*k) % 179;
			i = j;
			j = k;
			k = m;
			l = (53*l + 1) % 169;
			if ((l*m)%64 >= 32) s += t;
			t *= (float)0.5;
		}
		u[ii] = s;
	}

	c = (float)362436.0 / (float)16777216.0;
	cd = (float)7654321.0 / (float)16777216.0;
	cm = (float)16777213.0 / (float)16777216.0;
	
	i97 = 97;
	j97 = 33;
	
	bTest = TRUE;
}

float rangen::ranmar()
/*
C This is the random number generator proposed by George Marsaglia in 
C Florida State University Report: FSU-SCRI-87-50
*/
{
	float uni;
	
	// auto-seed:
	if (bTest==FALSE)
	{
		rmarin(rand() % 31328, time( NULL ) % 30081);
	}

	uni = u[i97] - u[j97];
	if (uni < 0.0) uni += (float)1.0;
	u[i97] = uni;
	i97--;
	if (i97==0) i97 = 97;
	j97--;
	if (j97==0) j97 = 97;
	c -= cd;
	if (c<0.0) c += cm;
	uni -= c;
	if (uni<0.0) uni += (float)1.0;
	return uni;
}

#pragma optimize( "", on ) 

