@echo off
chcp 65001 >nul
title C++ Class Generator (Menu-based Includes)
setlocal enabledelayedexpansion

echo Current dir: %cd%
echo Script dir: %~dp0

if not exist "%~dp0include" (
    echo ERROR: include folder not found!
    pause
    exit /b
)
if not exist "%~dp0src" (
    echo ERROR: src folder not found!
    pause
    exit /b
)

:loop
echo.
set "className="
set /p "className=Enter class name (e.g. Person): "

if "!className!"=="" (
    echo Name cannot be empty.
    goto loop
)
echo !className!| findstr /r "[^a-zA-Z0-9_]" >nul
if not errorlevel 1 (
    echo Only letters, numbers, underscore allowed.
    goto loop
)

:: ---------- Base Class ----------
set "baseClass="
set "hasBase=n"
:askBase
set /p "hasBase=Inherit from a base class? (y/n, default n): "
if /i "!hasBase!"=="y" (
    set /p "baseClass=Enter base class name (e.g. Person): "
    if "!baseClass!"=="" (
        echo Base class name cannot be empty.
        goto askBase
    )
    echo !baseClass!| findstr /r "[^a-zA-Z0-9_]" >nul
    if not errorlevel 1 (
        echo Only letters, numbers, underscore allowed.
        goto askBase
    )
) else if /i "!hasBase!"=="n" (
    set "baseClass="
) else (
    echo Please enter y or n
    goto askBase
)

:: ---------- Temp files ----------
set "varFile=%temp%\class_vars_%random%.tmp"
set "funcFile=%temp%\class_funcs_%random%.tmp"
set "incFile=%temp%\class_includes_%random%.tmp"
if exist "!varFile!" del "!varFile!"
if exist "!funcFile!" del "!funcFile!"
if exist "!incFile!" del "!incFile!"

:: ---------- Member Variables ----------
set "hasVars=n"
:askVars
set /p "hasVars=Add member variables? (y/n, default n): "
if /i "!hasVars!"=="y" (
    echo Enter each variable declaration on a new line.
    echo Leave empty line to finish.
    :addVarLoop
    set "varLine="
    set /p "varLine=  > "
    if "!varLine!"=="" goto endVarLoop
    set "varLine=!varLine!"
    if not "!varLine:~-1!"==";" set "varLine=!varLine!;"
    echo !varLine!>>"!varFile!"
    goto addVarLoop
    :endVarLoop
    echo Variables added.
) else if /i "!hasVars!"=="n" (
    set "hasVars=n"
) else (
    echo Please enter y or n
    goto askVars
)

:: ---------- Member Functions ----------
set "hasFuncs=n"
:askFuncs
set /p "hasFuncs=Add member functions? (y/n, default n): "
if /i "!hasFuncs!"=="y" (
    echo Enter each function declaration on a new line.
    echo Leave empty line to finish.
    :addFuncLoop
    set "funcLine="
    set /p "funcLine=  > "
    if "!funcLine!"=="" goto endFuncLoop
    set "funcLine=!funcLine!"
    if not "!funcLine:~-1!"==";" set "funcLine=!funcLine!;"
    echo !funcLine!>>"!funcFile!"
    goto addFuncLoop
    :endFuncLoop
    echo Functions added.
) else if /i "!hasFuncs!"=="n" (
    set "hasFuncs=n"
) else (
    echo Please enter y or n
    goto askFuncs
)

:: ---------- Extra Headers (Direct Menu, no y/n) ----------
echo.
echo Add extra #include headers?
echo Enter each header on a new line, empty line to finish.
echo Shortcuts (enter number):
echo   [1] ^<string^>
echo   [2] ^<vector^>
echo   [3] ^<algorithm^>
echo   [4] ^<fstream^>
echo Custom: type with ^< ^> or quotes, e.g., ^<my.h^> or "my.h"
:addIncLoop
set "incLine="
set /p "incLine=  > "
if "!incLine!"=="" goto endIncLoop
if "!incLine!"=="1" set "incLine=<string>"
if "!incLine!"=="2" set "incLine=<vector>"
if "!incLine!"=="3" set "incLine=<algorithm>"
if "!incLine!"=="4" set "incLine=<fstream>"
echo !incLine!>>"!incFile!"
goto addIncLoop
:endIncLoop
echo Headers added (if any).

:: ---------- Review and Confirm ----------
:confirm
echo.
echo ====== Summary ======
echo Class name : !className!
if not "!baseClass!"=="" (
    echo Base class : !baseClass!
) else (
    echo Base class : (none)
)
echo.
echo Member variables:
if exist "!varFile!" (
    for /f "delims=" %%i in (!varFile!) do (
        set "line=%%i"
        echo   !line!
    )
) else echo   (none)
echo.
echo Member functions:
if exist "!funcFile!" (
    for /f "delims=" %%i in (!funcFile!) do (
        set "line=%%i"
        echo   !line!
    )
) else echo   (none)
echo.
echo Extra headers:
if exist "!incFile!" (
    for /f "delims=" %%i in (!incFile!) do (
        set "inc=%%i"
        echo   #include !inc!
    )
) else echo   (none)
echo ====================
echo.
set /p "confirm=Confirm and generate? (y/n): "
if /i "!confirm!"=="n" (
    echo.
    echo Resetting... You can re-enter all information.
    if exist "!varFile!" del "!varFile!"
    if exist "!funcFile!" del "!funcFile!"
    if exist "!incFile!" del "!incFile!"
    goto loop
) else if /i "!confirm!"=="y" (
    goto generate
) else (
    echo Please enter y or n.
    goto confirm
)

:generate
:: ---------- Generate Header ----------
echo Generating !className!.h ...
> "%~dp0include\!className!.h" echo #pragma once
>> "%~dp0include\!className!.h" echo.
>> "%~dp0include\!className!.h" echo #include ^<iostream^>
if exist "!incFile!" (
    for /f "delims=" %%i in (!incFile!) do (
        set "inc=%%i"
        >> "%~dp0include\!className!.h" echo #include !inc!
    )
)
>> "%~dp0include\!className!.h" echo.

if not "!baseClass!"=="" (
    >> "%~dp0include\!className!.h" echo class !className! : public !baseClass! {
) else (
    >> "%~dp0include\!className!.h" echo class !className! {
)

>> "%~dp0include\!className!.h" echo public:
>> "%~dp0include\!className!.h" echo     !className!();
>> "%~dp0include\!className!.h" echo     ~!className!();

if exist "!funcFile!" (
    >> "%~dp0include\!className!.h" echo.
    for /f "delims=" %%i in (!funcFile!) do (
        set "line=%%i"
        >> "%~dp0include\!className!.h" echo     !line!
    )
)

if exist "!varFile!" (
    >> "%~dp0include\!className!.h" echo.
    >> "%~dp0include\!className!.h" echo private:
    for /f "delims=" %%i in (!varFile!) do (
        set "line=%%i"
        >> "%~dp0include\!className!.h" echo     !line!
    )
)
>> "%~dp0include\!className!.h" echo };
>> "%~dp0include\!className!.h" echo.

if exist "%~dp0include\!className!.h" (
    echo OK: include\!className!.h
) else (
    echo FAILED: include\!className!.h
)

:: ---------- Generate Source ----------
echo Generating !className!.cpp ...
> "%~dp0src\!className!.cpp" echo #include "!className!.h"
>> "%~dp0src\!className!.cpp" echo #include ^<iostream^>
if exist "!incFile!" (
    for /f "delims=" %%i in (!incFile!) do (
        set "inc=%%i"
        >> "%~dp0src\!className!.cpp" echo #include !inc!
    )
)
>> "%~dp0src\!className!.cpp" echo.
>> "%~dp0src\!className!.cpp" echo !className!::!className!() {
>> "%~dp0src\!className!.cpp" echo }
>> "%~dp0src\!className!.cpp" echo.
>> "%~dp0src\!className!.cpp" echo !className!::~!className!() {
>> "%~dp0src\!className!.cpp" echo }
>> "%~dp0src\!className!.cpp" echo.

if exist "%~dp0src\!className!.cpp" (
    echo OK: src\!className!.cpp
) else (
    echo FAILED: src\!className!.cpp
)

:: Cleanup
if exist "!varFile!" del "!varFile!"
if exist "!funcFile!" del "!funcFile!"
if exist "!incFile!" del "!incFile!"

echo.
echo Done.

:again
echo.
set /p "cont=Create another? (y/n): "
if /i "!cont!"=="y" (
    goto loop
) else if /i "!cont!"=="n" (
    goto end
) else (
    echo Please enter y or n
    goto again
)

:end
echo.
pause
exit