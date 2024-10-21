@echo off
gen >in
sol <in >ans
python3 main.py <in >out
type out
type ans
fc out ans /N
if errorlevel 1 exit
test
