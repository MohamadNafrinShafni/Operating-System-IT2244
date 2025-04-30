
@echo off
setlocal enabledelayedexpansion

set /p birthyear=Enter your birth year: 

for /f "tokens=2 delims==" %%i in ('wmic os get localdatetime /value') do set datetime=%%i
::set year=!datetime:~0,4!
set year=%datetime:~0,4%
set month=%datetime:~5,2%
set day=%datetime:~8,2%

set /a age=%year% - %birthyear%

echo You are %age% years old.

pause
