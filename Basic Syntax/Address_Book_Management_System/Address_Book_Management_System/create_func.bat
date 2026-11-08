@echo off
chcp 65001 >nul
title C++ Function File Generator
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
set /p "funcName=Enter function name (e.g. Add_Contact): "

if "%funcName%"=="" (
    echo Name cannot be empty.
    goto loop
)
echo %funcName%| findstr /r "[^a-zA-Z0-9_]" >nul
if not errorlevel 1 (
    echo Only letters, numbers, underscore allowed.
    goto loop
)

set "retType=void"
:askRet
set /p "customRet=Custom return type? (y/n, default n = void): "
if /i "%customRet%"=="y" (
    set /p "retType=Enter return type: "
) else if /i "%customRet%"=="n" (
    set "retType=void"
) else (
    echo Please enter y or n
    goto askRet
)

set "params="
:askParams
set /p "customParams=Custom parameters? (y/n, default n = none): "
if /i "%customParams%"=="y" (
    set /p "params=Enter parameters (e.g. int a, string b): "
) else if /i "%customParams%"=="n" (
    set "params="
) else (
    echo Please enter y or n
    goto askParams
)

:askIncludes
echo.
echo Select extra headers:
echo [1] None
echo [2] string
echo [3] vector
echo [4] algorithm
echo [5] fstream
echo [6] Custom (type your own, e.g. "my.h" or <mylib>)
set /p "includeChoice=Enter choice (1-6): "

if "%includeChoice%"=="1" (
    set "extraIncludes="
    set "customInclude=0"
) else if "%includeChoice%"=="2" (
    set "extraIncludes=string"
    set "customInclude=0"
) else if "%includeChoice%"=="3" (
    set "extraIncludes=vector"
    set "customInclude=0"
) else if "%includeChoice%"=="4" (
    set "extraIncludes=algorithm"
    set "customInclude=0"
) else if "%includeChoice%"=="5" (
    set "extraIncludes=fstream"
    set "customInclude=0"
) else if "%includeChoice%"=="6" (
    set /p "extraIncludes=Enter header names (space separated, with <> or ""): "
    set "customInclude=1"
) else (
    echo Invalid choice, enter 1-6
    goto askIncludes
)

echo Generating %funcName%.h ...
> "%~dp0include\%funcName%.h" echo #pragma once
>> "%~dp0include\%funcName%.h" echo.
>> "%~dp0include\%funcName%.h" echo %retType% %funcName%(%params%);

if exist "%~dp0include\%funcName%.h" (
    echo OK: include\%funcName%.h
) else (
    echo FAILED: include\%funcName%.h
)

echo Generating %funcName%.cpp ...
> "%~dp0src\%funcName%.cpp" echo #include "%funcName%.h"
>> "%~dp0src\%funcName%.cpp" echo #include ^<iostream^>

if not "%extraIncludes%"=="" (
    if "%customInclude%"=="1" (
        :: For custom, output exactly as user typed (no extra angle brackets)
        for %%i in (%extraIncludes%) do (
            >> "%~dp0src\%funcName%.cpp" echo #include %%i
        )
    ) else (
        :: For preset choices, add angle brackets
        for %%i in (%extraIncludes%) do (
            >> "%~dp0src\%funcName%.cpp" echo #include ^<%%i^>
        )
    )
)

>> "%~dp0src\%funcName%.cpp" echo using namespace std;
>> "%~dp0src\%funcName%.cpp" echo.
>> "%~dp0src\%funcName%.cpp" echo %retType% %funcName%(%params%) {
>> "%~dp0src\%funcName%.cpp" echo }

if exist "%~dp0src\%funcName%.cpp" (
    echo OK: src\%funcName%.cpp
) else (
    echo FAILED: src\%funcName%.cpp
)

echo.
echo Done.

:again
echo.
set /p "cont=Create another? (y/n): "
if /i "%cont%"=="y" (
    goto loop
) else if /i "%cont%"=="n" (
    goto end
) else (
    echo Please enter y or n
    goto again
)

:end
echo.
pause
exit