@echo off
gen >in
sol <in >out1
sol2 <in >out2
fc out1 out2 /N
if errorlevel 1 exit
test
