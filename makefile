type: main.c type_utilities.c type.h
	gcc -o type main.c startPlay.c type_utilities.c	progBAr.c

ctest: main.c type_utilities.c type.h
	gcc -o ctest --coverage test_main.c startPlay.c type_utilities.c progBAr.c
