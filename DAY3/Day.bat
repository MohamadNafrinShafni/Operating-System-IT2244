@echo off
:: Get date using WMIC for consistent format (yyyy-MM-dd)
for /f "tokens=2 delims==" %%I in ('"wmic os get LocalDateTime /value"') do set datetime=%%I

:: Extract parts from the datetime string
:: Format: yyyyMMddhhmmss.ssssss±UUU
set year=%datetime:~0,4%
set month=%datetime:~4,2%
set day=%datetime:~6,2%

:: Get weekday name
for /f %%A in ('powershell -command "(Get-Date).DayOfWeek"') do set weekday=%%A

:: Display results
echo Year: %year%
echo Month: %month%
echo Day: %day%
echo Weekday: %weekday%

pause
