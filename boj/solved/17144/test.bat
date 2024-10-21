@echo off
gen >in
python3 sol.py <in >out
sol <in >ans
type out
type ans
fc out ans /N
if errorlevel 1 exit
test
