// Vista Helper Functions DLL Header File

extern "C" __declspec(dllexport) BOOL GetCommonAppDataPath(char *path);
extern "C" __declspec(dllexport) DWORD SetDefaultOutputVolume(WORD wVolume);
extern "C" __declspec(dllexport) BOOL GetControlPanelPath(char *path);