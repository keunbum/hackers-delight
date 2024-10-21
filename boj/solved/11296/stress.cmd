@echo off
gen 1000 100 1 >in
sol <in >ans
kyo20111 <in >out
::type ans
::type out
fc out ans /N
if errorlevel 1 exit
stress
