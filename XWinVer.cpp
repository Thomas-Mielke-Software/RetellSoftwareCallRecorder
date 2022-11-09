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
*/

#include "stdafx.h"
#include "XWinVer.h"


BOOL Is2000OrGreater()
{
	OSVERSIONINFO osinfo;
	osinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osinfo);

	DWORD dwPlatformId   = osinfo.dwPlatformId;
	DWORD dwMajorVersion = osinfo.dwMajorVersion;

	return ((dwPlatformId == 2) && 
			(dwMajorVersion >= 5));
}

BOOL Is2000()
{
	OSVERSIONINFO osinfo;
	osinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osinfo);

	DWORD dwPlatformId   = osinfo.dwPlatformId;
	DWORD dwMajorVersion = osinfo.dwMajorVersion;
	DWORD dwMinorVersion = osinfo.dwMinorVersion;

	return ((dwPlatformId == 2) && 
			(dwMajorVersion == 5) && 
			(dwMinorVersion == 0));
}

BOOL IsXP()
{
	OSVERSIONINFO osinfo;
	osinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osinfo);

	DWORD dwPlatformId   = osinfo.dwPlatformId;
	DWORD dwMajorVersion = osinfo.dwMajorVersion;
	DWORD dwMinorVersion = osinfo.dwMinorVersion;

	return ((dwPlatformId == 2) && 
			(dwMajorVersion == 5) && 
			(dwMinorVersion >= 1));
}

BOOL IsVista()
{
	OSVERSIONINFO osinfo;
	osinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osinfo);

	DWORD dwPlatformId   = osinfo.dwPlatformId;
	DWORD dwMajorVersion = osinfo.dwMajorVersion;

	return ((dwPlatformId == 2) && 
			(dwMajorVersion >= 6));
}
