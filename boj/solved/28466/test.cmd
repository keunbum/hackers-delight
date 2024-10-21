@echo off
gen 10 >in
sol <in >ans
wrong3 <in >out
::type ans
::type out
fc out ans /N
if errorlevel 1 exit
test
