@echo off
gen 4 3 5 >in
sol <in >ans
python sol.py <in >out
::type ans
::type out
fc out ans /N
if errorlevel 1 exit
test
