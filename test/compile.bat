@echo off
title  a.cpp
pushd %~d0
g++ -std=c++11 a.cpp&&a
pause