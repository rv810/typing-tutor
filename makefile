type: main.c type_utilities.c type.h
	gcc -o type main.c startPlay.c type_utilities.c	progBar.c

ctest: test_main.c type_utilities.c type.h
	gcc -o ctest --coverage test_main.c startPlay.c type_utilities.c progBar.c
