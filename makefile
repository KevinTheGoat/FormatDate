#makefile
#Description: complies all source files for program which are included in FILES
# -pedantic -ansi makes sure code is in ansi standard

CC = gcc -pedantic -ansi
FILE = validateDate.c
FILE2 = formatDate.c

.PHONY: makefile

build: $(FILE FILE2)
	$(CC) -o validateDate $(FILE)
	$(CC) -o formatDate $(FILE2)
clean:
	rm -f *.out