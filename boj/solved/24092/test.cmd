@echo off
gen >in
sol <in >out1
sol3 <in >out3
fc out1 out3 /N
if errorlevel 1 exit
test
