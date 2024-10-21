@echo off
gen >in
sol <in >out
python3 main.py <in >ans
type out
type ans
fc out ans /N
if errorlevel 1 exit
test
