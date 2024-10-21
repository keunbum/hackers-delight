@echo off
gen 10000 50 >in
sol <in >ans
sol2 <in >out
::type ans
::type out
fc out ans /N
if errorlevel 1 exit
test
