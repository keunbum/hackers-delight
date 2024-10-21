@echo off
gen 1 5 3 >in
sol <in >ans
w <in >out
::type ans
::type out
fc out ans /N
if errorlevel 1 exit
test
