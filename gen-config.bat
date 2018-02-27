:: input file
set astInput=%cd%\src\config\config.cpp
 
:: generate temp ast file for traversing 
clang -emit-ast %astInput% -o tmp.ast
 
:: save header.inc & macro.inc
ConfigMaker tmp.ast
 
:: print result
::type header.inc
::type macro.inc

copy header.inc %cd%\src\config\config.h
copy macro.inc  %cd%\src\config\manager\ConfigManagerMacro.inc

del header.inc
del macro.inc
del tmp.ast