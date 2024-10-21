@echo off
gen >in
stupid <in >ans
sol <in >out
type ans
type out
fc out ans /N
if errorlevel 1 exit
test
