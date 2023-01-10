@echo off
pushd %~dp0\..\
call cmake -B build/projects -G "Visual Studio 17 2022"
popd

PAUSE
