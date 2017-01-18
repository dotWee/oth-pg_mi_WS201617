all: compile
	./mysql_sample2

compile:
	cc mysql_sample1.c -o mysql_sample1 `mysql_config --cflags --libs`
	cc mysql_sample2.c -o mysql_sample2 `mysql_config --cflags --libs`

