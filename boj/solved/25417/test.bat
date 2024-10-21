@echo off
gen >in
sol <in >ans
wrong <in >out
type ans
type out
fc out ans /N
if errorlevel 1 exit
test
