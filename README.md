# RetellSoftwareCallRecorder

Analogous telephone recording software for Windows, using a soundcard and Retell adapter

This software has been in use around the 2000s and now was released as free software to give customers, who still use it, the chance to adapt it to their needs and maintain operation as they see fit.

The source code is therefore not a good example on how to use C++ in a modern world and rather has to be conceived as a historic document. Indeed it is often more C-style than C++.

## Build

To build, you need Microsoft Visual Studio 2022 (Preview) with C++ and MFC support. You also need a static build of the ResizableLib https://github.com/ppescher/resizablelib.
Before Running, copy SCRVistaHelper.dll and a vendor dll into your debug or release folder. Packaging is done using InnoSetup.

## License

This software war released under the GNU General Public License v3.0.
