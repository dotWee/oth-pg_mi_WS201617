
all: queuetest
	gcc main.c queue.o -o queue_sample2

queuetest: queuelib
	gcc queue_test.c queue.o -o queue_test
	./queue_test

queuelib:
	gcc -c queue.c -o queue.o
