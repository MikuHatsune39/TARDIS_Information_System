@ECHO OFF
rem echo Converting Line Endings...
rem powershell -Command (Get-Content "main.c") | Set-Content "main.c"
echo Converting for Windows
powershell  "& "".\linux2windows.ps1"""
rem echo Fixing Path to Files...
rem cscript replace.vbs "main.c" "./db/" ".\\db\\"
rem echo Changing "clear" to "cls"...
rem cscript replace.vbs "main.c" "clear" "cls"
echo Done