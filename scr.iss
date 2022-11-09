; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=Retell Software Call Recorder
AppVerName=Retell Software Call Recorder v2.0 build 2300
AppPublisher=Retell
AppPublisherURL=http://www.retell.co.uk
AppSupportURL=http://www.retell.co.uk
AppUpdatesURL=http://www.retell.co.uk

DefaultDirName={commonpf}\Retell Software Call Recorder
DefaultGroupName=Retell Software Call Recorder
OutputBaseFilename=SCR_Setup
OutputDir=.\Setup
Compression=zip
PrivilegesRequired=admin
 
[Messages]
WelcomeLabel2=This will install the [name/ver] on your computer.%n%nIMPORTANT NOTICE:%n%nIf you want to update an allready fully licensed copy of the software, it is recommended that you deactivate the SCR (if it is now running). DON'T UNINSTALL the SCR prior to applying this update and don't install to an other directory than you have before!%n%nIf you install this software to run as a demo, you will have a period of 65 days until the software stops working.

[Types]
Name: English; Description: English language
Name: German; Description: German language
Name: Spanish; Description: Spanish language
Name: Czech; Description: Czech language
Name: Dutch; Description: Dutch language
Name: Polish; Description: Polish language

[Components]
Name: English; Types: English; Description: Components for English language support
Name: German; Types: German; Description: Components for German language support
Name: Spanish; Types: Spanish; Description: Components for Spanish language support
Name: Czech; Types: Czech; Description: Components for Czech language support
Name: Dutch; Types: Dutch; Description: Components for Dutch language support
Name: Polish; Types: Polish; Description: Components for Polish language support

[Tasks]
Name: desktopicon; Description: Create a &desktop icon; GroupDescription: Additional icons:; MinVersion: 4,4

[Files]
Source: .\Release\Telar.exe; DestDir: {app}; Flags: restartreplace ignoreversion
Source: .\TelarVendorRetell\Release\TelarVnd.dll; DestDir: {app}; Flags: restartreplace ignoreversion
Source: .\Release\wavein.dll; DestDir: {app}; Flags: restartreplace ignoreversion
Source: .\Release\SCRVistaHelper.dll; DestDir: {app}; Flags: restartreplace ignoreversion
Source: .\w32SQLite3\Release\w32SQLite3.dll; DestDir: {app}; Flags: restartreplace ignoreversion
Source: .\ivrlla.dll; DestDir: {app}; Flags: restartreplace ignoreversion
Source: .\TrsIndex\Release\ReIndex.exe; DestDir: {app}; Flags: restartreplace ignoreversion
Source: .\Dokumentation\SCR 957 Manual.pdf; DestDir: {app}; Flags: ignoreversion
Source: .\Dokumentation\ReadMe.txt; DestDir: {app}; Flags: ignoreversion

Source: .\_Stuff\SCRLicServer\SCRLicServerps.dll; DestDir: {app}; Flags: regserver restartreplace
Source: .\TelArLangEnglish\Release\Telarlng.dll; DestDir: {app}; Components: English; Flags: restartreplace ignoreversion
Source: .\TelArLangDeutsch\Release\Telarlng.dll; DestDir: {app}; Components: German; Flags: restartreplace ignoreversion
Source: .\TelArLangEspanol\Release\Telarlng.dll; DestDir: {app}; Components: Spanish; Flags: restartreplace ignoreversion
Source: .\TelArLangCzech\Release\Telarlng.dll; DestDir: {app}; Components: Czech; Flags: restartreplace ignoreversion
Source: .\TelArLangNL\Release\Telarlng.dll; DestDir: {app}; Components: Dutch; Flags: restartreplace ignoreversion
Source: .\TelArLangPolish\Release\Telarlng.dll; DestDir: {app}; Components: Polish; Flags: restartreplace ignoreversion
; Source: .\InstalledLibraries\shfolder.dll; DestDir: {sys}; Flags: restartreplace
; Jet 3.5 files -- msjet35.dll 3.51.3328.0, msjint35.dll 3.51.623.0, msjter35.dll 3.51.623.0
; Source: .\InstalledLibraries\msjet35.dll; DestDir: {sys}; Flags: restartreplace sharedfile
; Source: .\InstalledLibraries\msjint35.dll; DestDir: {sys}; Flags: restartreplace sharedfile
; Source: .\InstalledLibraries\msjter35.dll; DestDir: {sys}; Flags: restartreplace sharedfile
; Source: .\InstalledLibraries\dao350.dll; DestDir: {dao}; Flags: sharedfile regserver restartreplace

[Registry]
Root: HKLM; Subkey: Software\TRS
Root: HKLM; Subkey: Software\TRS\Telar
Root: HKLM; Subkey: Software\TRS\Telar; ValueType: string; ValueName: InstallPath; ValueData: {app}
Root: HKCU; Subkey: Software\TRS
Root: HKCU; Subkey: Software\TRS\Telar
Root: HKCU; Subkey: Software\TRS\Telar; ValueType: string; ValueName: InstallPath; ValueData: {app}
Root: HKCU; Subkey: Software\Microsoft
Root: HKCU; Subkey: Software\Microsoft\Windows
Root: HKCU; Subkey: Software\Microsoft\Windows\CurrentVersion
Root: HKCU; Subkey: Software\Microsoft\Windows\CurrentVersion\Run
Root: HKCU; Subkey: Software\Microsoft\Windows\CurrentVersion\Run; ValueType: string; ValueName: TelAr; ValueData: {app}\Telar.exe; Flags: uninsdeletevalue

[Icons]
Name: {group}\SCR 957 Application; Filename: {app}\Telar.exe
Name: {group}\SCR 957 Manual; Filename: {app}\SCR 957 Manual.pdf
Name: {group}\Read Me!; Filename: {app}\ReadMe.txt
Name: {userdesktop}\SCR 957 Application; Filename: {app}\Telar.exe; MinVersion: 4,4; Tasks: desktopicon

[Run]
Filename: {app}\Telar.exe; Description: Retell SCR 957; Flags: nowait postinstall skipifsilent

[Languages]
Name: default; MessagesFile: compiler:Default.isl
