@echo off
set /a A = 0
set /a B = %1
set /a C=%B% %% 4
set /a D=%B% %% 400
set /a E=%B% %% 100
if %C% equ %A% (goto 1) else (goto noleap)

:1
if %E% neq %A% (goto leap) else (goto 2)

:2
if %D% equ %A% (goto leap) else (goto noleap)

:leap
echo %1 is leap year
goto break

:noleap
echo %1 is NOT a leap year
goto break

:break
