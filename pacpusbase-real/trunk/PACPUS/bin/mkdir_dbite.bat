@echo off
echo Create the DBITE directory where data will be stored and move inside it
SET DATEDBITE=%DATE%
SET DBITEDIR=%DATEDBITE:~6,4%_
SET DBITEDIR=%DBITEDIR%%DATEDBITE:~3,2%_
SET DBITEDIR=%DBITEDIR%%DATEDBITE:~0,2%_
SET DBITEDIR=%DBITEDIR%%TIME%
SET DBITEDIR=%DBITEDIR::=_%
SET DBITEDIR=%DBITEDIR:~0,-3%
MKDIR %DBITEDIR%
rem CD %DBITEDIR%