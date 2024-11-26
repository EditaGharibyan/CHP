@echo off
title Network and File Utilities

:MENU
cls
echo ===========================
echo       Utility Menu
echo ===========================
echo 1. Display IPv4 and IPv6 addresses
echo 2. Trace network path to a hostname
echo 3. Get the IP address of a hostname
echo 4. Encrypt a file or text
echo 5. Decrypt a file or text
echo 6. Compress a file or text
echo 7. Restore a compressed file or text
echo 8. Calculate a file's checksum (hash)
echo 9. Exit
echo ===========================
set /p choice=Enter your choice [1-9]:

if "%choice%"=="1" goto GET_IP
if "%choice%"=="2" goto TRACE_ROUTE
if "%choice%"=="3" goto GET_HOST_IP
if "%choice%"=="4" goto ENCRYPT
if "%choice%"=="5" goto DECRYPT
if "%choice%"=="6" goto COMPRESS
if "%choice%"=="7" goto RESTORE
if "%choice%"=="8" goto CALC_CHECKSUM
if "%choice%"=="9" exit

goto MENU

:GET_IP
cls
echo Getting IP addresses...
echo.
ipconfig | findstr /i "IPv4 IPv6"
pause
goto MENU

:TRACE_ROUTE
cls
set /p hostname=Enter hostname or IP address for trace route: 
echo Tracing route to %hostname%...
tracert %hostname%
pause
goto MENU

:GET_HOST_IP
cls
set /p hostname=Enter hostname or URL: 
echo Resolving IP address for %hostname%...
nslookup %hostname%
pause
goto MENU

:ENCRYPT
cls
set /p text=Enter text to encrypt: 
echo %text% > temp.txt
certutil -encode temp.txt encrypted.txt
del temp.txt
echo File encrypted as encrypted.txt
pause
goto MENU

:DECRYPT
cls
set /p filename=Enter filename to decrypt (encrypted.txt): 
certutil -decode %filename% decrypted.txt
echo File decrypted as decrypted.txt
pause
goto MENU

:COMPRESS
cls
set /p filename=Enter filename to compress: 
tar -cf %filename%.tar %filename%
echo File compressed as %filename%.tar
pause
goto MENU

:RESTORE
cls
set /p filename=Enter compressed filename to restore (e.g., filename.tar): 
tar -xf %filename%
echo File restored from %filename%.
pause
goto MENU

:CALC_CHECKSUM
cls
set /p filename=Enter filename to calculate checksum: 
certutil -hashfile %filename% SHA256
pause
goto MENU
