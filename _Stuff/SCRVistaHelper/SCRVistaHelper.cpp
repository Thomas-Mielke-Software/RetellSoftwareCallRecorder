/ Vista Helper Functions DLL Source File

#include "stdafx.h"
#include "SCRVistaHelper.h"
#include <shlobj.h>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

#pragma warning(disable: 4996)
extern "C" BOOL GetCommonAppDataPath(char *path)
{
	*path = '\0';

	if (SHGetSpecialFolderPath(NULL, path, CSIDL_COMMON_APPDATA, TRUE))
	{
		strcat(path, "\\Retell Software Call Recorder");
		DWORD dwFileStat = GetFileAttributes(path);
		if (dwFileStat == 0xffffffff)	// no Retell app directory yet?
			CreateDirectory(path, NULL);	// create it

		dwFileStat = GetFileAttributes(path);	// 2nd try
		if (dwFileStat == 0xffffffff || !(dwFileStat & FILE_ATTRIBUTE_DIRECTORY))
			return FALSE;

		return TRUE;
	}

	return FALSE;
}

extern "C" DWORD SetDefaultOutputVolume(WORD wVolume)
{
    HRESULT hr = S_OK;
    CoInitialize(NULL);

	IMMDeviceEnumerator *deviceEnumerator = NULL;

    //    Instantiate an endpoint volume object.
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	if (hr == S_OK)
	{
		IMMDevice *defaultDevice = NULL;

		hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &defaultDevice);
		deviceEnumerator->Release();
		deviceEnumerator = NULL;
		if (hr == S_OK)
		{
			IAudioEndpointVolume *endpointVolume = NULL;
			hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
			defaultDevice->Release();
			defaultDevice = NULL;
			if (hr == S_OK)
			{
				hr = endpointVolume->SetMasterVolumeLevelScalar((float)wVolume / (float)65536.0 , NULL);
				endpointVolume->Release();
				endpointVolume = NULL;
			}
		}
	}

    CoUninitialize();
	return hr;
}

extern "C" BOOL GetControlPanelPath(char *path)
{
    HRESULT hr = S_OK;
    *path = '\0';
	LPWSTR pwcPath = NULL;

    CoInitialize(NULL);

    IKnownFolderManager *pFolderManager = NULL;
    if ((hr = CoCreateInstance(__uuidof(KnownFolderManager), NULL, CLSCTX_INPROC_SERVER, __uuidof(IKnownFolderManager), (LPVOID *)&pFolderManager)) == S_OK)
	{
		IKnownFolder *pControlPanelFolder = NULL;
		if ((hr = pFolderManager->GetFolder(FOLDERID_ControlPanelFolder, &pControlPanelFolder)) == S_OK)
		{
			hr = pControlPanelFolder->GetPath(0, &pwcPath); // <-- always fail, control panel has no directory path

			if (hr == S_OK && pwcPath)
			{
				int nSize = wcslen(pwcPath);
				WideCharToMultiByte(CP_ACP, 0, pwcPath, nSize, path, nSize+2, NULL, NULL);
				path[nSize] = '\0';
				CoTaskMemFree(pwcPath);
			}

			pControlPanelFolder->Release();
			pControlPanelFolder = NULL;
		}

		pFolderManager->Release();
		pFolderManager = NULL;
	}

    CoUninitialize();

	return (hr == S_OK);
}