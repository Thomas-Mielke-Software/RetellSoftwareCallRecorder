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

// AutoUpdate.cpp : implementation file
//

#include "stdafx.h"
#include "telar.h"
#include "MyTapi.h"

#ifdef TAPI

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CMyTapi, CObject)

/////////////////////////////////////////////////////////////////////////////
// TAPI Init/Cleanup members

CMyTapi::CMyTapi()
{
	m_Initialized = FALSE;
}


CMyTapi::~CMyTapi()
{
}

HRESULT CMyTapi::Initialize()
{
    HRESULT         hr;

    //
    // cocreate the TAPI object
    //

    hr = CoCreateInstance(
                          CLSID_TAPI,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_ITTAPI,
                          (LPVOID *)&gpTapi
                         );

    if ( FAILED(hr) )
    {
        DoMessage("CoCreateInstance on TAPI failed");
        return hr;
    }

    //
    // call initialize.  this must be called before
    // any other tapi functions are called.
    //

    hr = gpTapi->Initialize();

    if ( FAILED(hr) )
    {
        DoMessage("TAPI failed to initialize");

        gpTapi->Release();
        gpTapi = NULL;

        return hr;
    }

    //
    // Create our own event notification object and register it
    // see callnot.h and callnot.cpp
    //

    CTAPIEventNotification *pTAPIEventNotification = new CTAPIEventNotification;

    hr = RegisterTapiEventInterface(pTAPIEventNotification);


    //
    // no longer need a reference to the callback object. tapi will keep a 
    // reference to it for as long as it is using it.
    //

    pTAPIEventNotification->Release();



    // Set the Event filter to only give us only the events we process
    gpTapi->put_EventFilter(TE_CALLNOTIFICATION | TE_CALLSTATE | TE_CALLMEDIA);


    //
    // find all address objects that
    // we will use to listen for calls on
    //

    hr = ListenOnAddresses();

    if ( FAILED(hr) )
    {
        DoMessage("Could not find any addresses to listen on");

        gpTapi->Release();
        gpTapi = NULL;

        return hr;
    }

    m_Initialized = TRUE;
	
    return S_OK;
}

void CMyTapi::Shutdown()
{
	if (!m_Initialized) return;

    //
    // if there is still a call, release it
    //

    if (NULL != gpCall)
    {
        gpCall->Release();
        gpCall = NULL;
    }

    //
    // release main object.
    //

    if (NULL != gpTapi)
    {
        gpTapi->Shutdown();
        gpTapi->Release();
    }

	m_Initialized = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// TAPI Notification Handling

HRESULT CMyTapi::RegisterTapiEventInterface(CTAPIEventNotification *pTAPIEventNotification)
{
    HRESULT                       hr = S_OK;
    IConnectionPointContainer   * pCPC;
    IConnectionPoint            * pCP;


    hr = gpTapi->QueryInterface(
                                IID_IConnectionPointContainer,
                                (void **)&pCPC
                               );

    if ( FAILED(hr) )
    {
        return hr;
    }

    hr = pCPC->FindConnectionPoint(
                                   IID_ITTAPIEventNotification,
                                   &pCP
                                  );

    pCPC->Release();

    if ( FAILED(hr) )
    {
        return hr;
    }

    hr = pCP->Advise(
                      pTAPIEventNotification,
                      &gulAdvise
                     );

    pCP->Release();


    return hr;

}


////////////////////////////////////////////////////////////////////////
// ListenOnAddresses
//
// This procedure will find all addresses that support audioin and audioout
// and will call ListenOnThisAddress to start listening on it.
////////////////////////////////////////////////////////////////////////

HRESULT CMyTapi::ListenOnAddresses()
{
    HRESULT             hr = S_OK;
    IEnumAddress *      pEnumAddress;
    ITAddress *         pAddress;

    //
    // enumerate the addresses
    //

    hr = gpTapi->EnumerateAddresses( &pEnumAddress );

    if ( FAILED(hr) )
    {
        return hr;
    }

    while ( TRUE )
    {
        //
        // get the next address
        //

        hr = pEnumAddress->Next( 1, &pAddress, NULL );

        if (S_OK != hr)
        {
            break;
        }

        //
        // does the address support audio?
        //

        if ( AddressSupportsMediaType(pAddress, TAPIMEDIATYPE_AUDIO) )
        {
            //
            // If it does then we'll listen.
            //

            hr = ListenOnThisAddress( pAddress );

            if ( FAILED(hr) )
            {
                DoMessage("Listen failed on an address");
            }
        }

        pAddress->Release();
    }

    pEnumAddress->Release();

    return S_OK;
}


///////////////////////////////////////////////////////////////////
// ListenOnThisAddress
//
// We call RegisterCallNotifications to inform TAPI that we want
// notifications of calls on this address. We already resistered
// our notification interface with TAPI, so now we are just telling
// TAPI that we want calls from this address to trigger events on
// our existing notification interface.
//
///////////////////////////////////////////////////////////////////

HRESULT CMyTapi::ListenOnThisAddress(ITAddress * pAddress)
{

    //
    // RegisterCallNotifications takes a media type bitmap indicating
    // the set of media types we are interested in. We know the
    // address supports audio, but let's add in video as well
    // if the address supports it.
    //

    long lMediaTypes = TAPIMEDIATYPE_AUDIO;

    if ( AddressSupportsMediaType(pAddress, TAPIMEDIATYPE_VIDEO) )
    {
        lMediaTypes |= TAPIMEDIATYPE_VIDEO;
    }


    HRESULT  hr;
    long     lRegister;

    hr = gpTapi->RegisterCallNotifications(
                                           pAddress,
                                           VARIANT_TRUE,
                                           VARIANT_TRUE,
                                           lMediaTypes,
                                           0,
                                           &lRegister
                                          );

    return hr;
}

/////////////////////////////////////////////////////////////////////
// Answering / Releasing a call

HRESULT CMyTapi::AnswerTheCall()
{
    HRESULT                 hr;
    ITCallInfo *            pCallInfo;
    ITAddress *             pAddress;



    if (NULL == gpCall)
    {
        return E_UNEXPECTED;
    }


    //
    // get the address object of this call
    //

    hr = gpCall->QueryInterface( IID_ITCallInfo, (void**)&pCallInfo );

    if ( FAILED(hr) )
    {
        gpCall->Release();
        gpCall = NULL;

        return hr;
    }

    hr = pCallInfo->get_Address( &pAddress );

    pCallInfo->Release();

    if ( FAILED(hr) )
    {
        gpCall->Release();
        gpCall = NULL;

        return hr;
    }

    //
    // get CallerID, etc.
    //

	//pAddress-> ... get some information on the address

    pAddress->Release();

    //
    // Now we can actually answer the call
    //

    hr = gpCall->Answer();

    return hr;
}

HRESULT CMyTapi::DisconnectTheCall()
{
    HRESULT         hr = S_OK;

    if (NULL != gpCall)
    {
        hr = gpCall->Disconnect( DC_NORMAL );

        // Do not release the call yet, as that would prevent
        // us from receiving the disconnected notification.

        return hr;
    }

    return S_FALSE;
}

void CMyTapi::ReleaseTheCall()
{
    if (NULL != gpCall)
    {
        gpCall->Release();
        gpCall = NULL;
    }
}

/////////////////////////////////////////////////////////////////////
// Misc Members

BOOL CMyTapi::AddressSupportsMediaType(ITAddress * pAddress, long lMediaType)
{
    VARIANT_BOOL     bSupport = VARIANT_FALSE;
    ITMediaSupport * pMediaSupport;

    if ( SUCCEEDED( pAddress->QueryInterface( IID_ITMediaSupport,
                                              (void **)&pMediaSupport ) ) )
    {
        //
        // does it support this media type?
        //

        pMediaSupport->QueryMediaType(
                                      lMediaType,
                                      &bSupport
                                     );

        pMediaSupport->Release();
    }

    return (bSupport == VARIANT_TRUE);
}


void CMyTapi::DoMessage(char *pszMessage)
{
    DF(pszMessage);
}



/*
get addres name this way:

		BSTR bstrAdressName;
		CString csAdressName;

		hr = pAddress->get_AddressName(&bstrAdressName);		

		if (hr == S_OK)
		{
			int nSize = wcslen(bstrAdressName);
			WideCharToMultiByte(CP_ACP, 0, bstrAdressName, nSize, csAdressName.GetBuffer(nSize+1), nSize+1, NULL, NULL);
			csAdressName.GetBuffer(nSize+1)[nSize] = '\0';
			::SysFreeString(bstrAdressName);
			SetDlgItemText(IDC_GESPRAECHSPARTNER, csAdressName);
		}
		else
		{
			DF("No displayable TAPI Address name.");
		}


get some address capabilities:

	hr = pAddressCaps->get_AddressCapability( AC_CALLERIDSUPPORT, &lType );

	pAddressCaps->Release();

    if ( FAILED(hr) )
    {
	    pAddress->Release();
		pCallInfo->Release();
        gpCall->Release();
        gpCall = NULL;

        return;
    }

	CString csTapiStatusMessage;
	char buffer[250];
	BOOL bGetTheName = FALSE;
	BOOL bGetTheNumber = TRUE;
	if ( SUCCEEDED(hr) )
	{
		if (lType & LINECALLPARTYID_NAME) // Party identifier information consists of the party's name.
		{
			bGetTheName = TRUE;
			LANG2BUFFER(IDS_STRING214, buffer);
			csTapiStatusMessage += (CString)buffer + " ";
		}
		if (lType & LINECALLPARTYID_ADDRESS) // Party identifier information consists of the party's address.
		{
			bGetTheName = TRUE;
			LANG2BUFFER(IDS_STRING215, buffer);
			csTapiStatusMessage += (CString)buffer + " ";
		}
		if (lType & LINECALLPARTYID_BLOCKED) // Party identifier information is not available because it has been blocked by the remote party.
		{
			bGetTheNumber = FALSE;
			LANG2BUFFER(IDS_STRING216, buffer);
			csTapiStatusMessage += (CString)buffer + " ";
		}
		if (lType & LINECALLPARTYID_OUTOFAREA) // Caller ID information for the call is not available because it is not propagated all the way by the network.
		{
			bGetTheNumber = FALSE;
			LANG2BUFFER(IDS_STRING217, buffer);
			csTapiStatusMessage += (CString)buffer + " ";
		}
		if (lType & LINECALLPARTYID_PARTIAL) // Party identifier information is valid but it is limited to partial information only.
		{
			bGetTheName = TRUE;
			LANG2BUFFER(IDS_STRING218, buffer);
			csTapiStatusMessage += (CString)buffer + " ";
		}
		if (lType & LINECALLPARTYID_UNAVAIL || lType & LINECALLPARTYID_UNKNOWN) // Party identifier information is not available.
		{
			bGetTheNumber = TRUE;
			LANG2BUFFER(IDS_STRING219, buffer);
			csTapiStatusMessage += (CString)buffer + " ";
		}
		SetDlgItemText(IDC_SPEICHERN_IN, csTapiStatusMessage);
	}


*/

#endif #ifdef TAPI