@echo off
gen 4 5 >in
sol < in > ans
java -Xms1024m -Xmx1920m -Xss512m -Dfile.encoding=UTF-8 Main < in > out
type out
type ans
fc out ans /N
if errorlevel 1 exit
test
