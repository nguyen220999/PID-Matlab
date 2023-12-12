set "VSCMD_START_DIR=%CD%"

call "E:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\..\..\VC\Auxiliary\Build\VCVARSALL.BAT" AMD64


call  "\\'hostname' is not recognized as an internal or external command,
operable program or batch file.\E$\Program Files\MATLAB\R2018a\bin\win64\checkMATLABRootForDriveMap.exe" "\\'hostname' is not recognized as an internal or external command,
operable program or batch file.\E$\Program Files\MATLAB\R2018a"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n
cd .

if "%1"=="" (nmake MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f pid_C2000.mk all) else (nmake MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f pid_C2000.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
