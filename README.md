# Compiling and Running CPP Programs

## <u>**General Overview**</u>
These are the instructions for setting up, compiling, building, running, and debugging C++ programs per platform. The settings included in this repo should work on any computer with Visual Studio Code. You will also need to have compilers and debuggers installed (see below). These instructions assume the default directories for the compilers.


## <u>**Using VSC**</u>
Installation instructions for specific platforms are found in the next section. These next steps assume you have VSC and your compiler installed.

1. Open up the workspace using the file "_LaunchThis.code-workspace". This should open up VSC as a workspace with all of the necessary settings. If it is not already associated with VSC, do so.
2. Create a new, blank file ("File->New File") from VSC. 

> #### File Names
> All files MUST be named correctly as the assignment instructions dictate. This includes spacing (don't use any!), capitalization, and the correct extensions (**.cpp**). Major points will be taken off for incorrect file names and/or missing files. 
>
> #### Header Information
> Please include all requested documents for this assignment in this repository. Each file MUST include a **COMMENT AREA** near the top of the page. The comment area must include the following three lines. All assignments for the remainder of this course must contain a variation of the following three lines. You will need to fill in the bracketed sections with the appropriate information (without the square brackets).
> ```
> Project Name: [Title of the Project]
> Author: [Your Full Name]
> Date Last Modified: [Date Modified]
> ```

3. Compile and run by hitting [Ctrl]+[Shift]+B or "Terminal->Run Build Task...". Select "Build and Run C/C++ Application".
4. To debug, you can select [F5] or "Debug->Start Debugging"

#
## <u>**Installing (do these once)**</u>
### <u>General Installation (all platforms)</u>
#### Install Visual Studio Code ( https://code.visualstudio.com/ )
1. Go to the website above. Download and install the version appropriate to your computer.
2. The first time you launch VSC, it will probably try to install a few plugins for handling cpp files. This is good! If it needs a little push, you can start the plugin manager (Ctrl+Shift+X) and install "C/C++ for Visual Studio Code".
3. Generally, you will start projects using the file "_LaunchThis.code-workspace". This should open up VSC as a workspace with all of the necessary settings. If it is not already associated with VSC, do so.


### <u>Windows Installation Specifics</u>
#### Install MinGW ( http://www.mingw.org )

1. Install the default installer (mingw-get-setup.exe) with the default options (in the default location--C:\\MinGW\\).
   You
2. The default installer will do a few things and then take you to the installation manager.
3. From here, under "Basic Setup", select "mingw32-gcc-g++" and "mingw32-base".
4. Click the menu "Installation", then "Apply Changes" and apply the pending actions.
5. Installer will take a while to download and install necessary components. Make sure to reboot when done.

#### Set your Path
1. Click the start button and type "advanced system settings" to bring up the System Properties window.
2. Click on "Environment Variables" button.
3. In the "System variables" box at the bottom, select "Path" and press the "Edit" button (at the bottom!).
4. Click the "New" button and type "C:\MinGW\bin".
5. Close all windows and make sure to reboot when done.

#### Optional: Install OpenGL and GLUT ( http://www.transmissionzero.co.uk/software/freeglut-devel/ )
1. Grab the latest version of FreeGLUT for MinGW from the link above and extract the files to your computer. Make sure to get the version for MinGW!
2. Go to the subdirectories of that archive and find three folders: "bin", "include", and "lib". Each of these contains files that need to be copied to the correct location for your program to compile and run. Just use the 32-bit versions (ignore any x64 files or subfolders).
3. Copy the file "freeglut.dll" from bin to the MinGW/bin directory (by default, this should be something like "C:\MinGW\bin").
4. Copy the four files in the folder "GL" under include to the MinGW/include/GL directory (by default, this should be "C:\MinGW\include\GL").
5. Copy the two "a" ("libfreeglut.a" and "libfreeglut_static.a") files from lib to the MinGW/lib directory (by default, this should be "C:\MinGW\lib").
6. Finally, be sure to include the libraries for GLUT by uncommenting the GPP_LIBS setting below.


### <u>Mac Installation Specifics</u>
#### Install C++
--HELP!!!!

#### Optional: Install OpenGL and GLUT (  )
--HELP!!!!

### <u>Linux Installation Specifics</u>
#### Install C++
--HELP!!!!

#### Optional: Install OpenGL and GLUT (  )
--HELP!!!!
