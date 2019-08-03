# Compiling and Running CPP Programs

## <u>General Overview</u>
These are the instructions for setting up, compiling, building, and debugging C++ programs per platform. The settings included in this repo should work on any computer with Visual Studio Code. You will need to have compilers and debuggers installed (see below). The instructions below assume the default directories for the compilers.

## <u>Installing (Do these Once)</u>
### Windows Installation
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


### Mac Installation

### Linux Installation

## <u>Using</u>

1. Open up the workspace using the file "_LaunchThis.code-workspace". This should open up VSC as a workspace with all of the necessary settings. If it is not already associated with VSC, do so.
2. Create a new, blank file ("File->New File") from VSC. 

> #### File Names
> All files MUST be named correctly as the assignment instructions dictate. This includes spacing (don't use any!), capitalization, and the correct extensions. Major points will be taken off for incorrect file names and/or missing files. 
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