@echo off

for /l %%i in (1, 1, 500) do (
	test_gen.exe > test.inp
	test.exe < test.inp > test.out
	test_trau.exe < test.inp > test.ans
	fc test.out test.ans > 0 || echo TEST %%i [WA] && goto :out
	echo TEST %%i [AC]
)

:out

