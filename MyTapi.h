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

#if !defined(AFX_MYTAPI_H__AFA596F8_337C_4691_90C1_AEB004B4C929__INCLUDED_)
#define AFX_MYTAPI_H__AFA596F8_337C_4691_90C1_AEB004B4C929__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTapi.h : header file
//

#ifdef TAPI

#include <tapi3.h>
#include "callnot.h"

class CMyTapi : public CObject
{
public:
// Construction
	CMyTapi();   // standard constructor
	~CMyTapi();	 // destructor
	DECLARE_DYNAMIC( CMyTapi )

public:
	BOOL m_Initialized;
	HRESULT Initialize();
	void Shutdown();
	ITTAPI *                gpTapi;
	ITBasicCallControl *    gpCall;
	ULONG                   gulAdvise;

// Overrides
protected:
//	virtual void Notification();

// Implementation
protected:

	HRESULT AnswerTheCall();
	HRESULT DisconnectTheCall();
	void ReleaseTheCall();
	HRESULT RegisterTapiEventInterface(CTAPIEventNotification *pTAPIEventNotification);
	HRESULT ListenOnAddresses();
	HRESULT ListenOnThisAddress(ITAddress * pAddress);
	BOOL AddressSupportsMediaType(ITAddress * pAddress, long lMediaType);
	void DoMessage(char *pszMessage);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTAPI_H__AFA596F8_337C_4691_90C1_AEB004B4C929__INCLUDED_)

#endif // #ifdef TAPI