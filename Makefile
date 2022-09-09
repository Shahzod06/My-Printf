CC = gcc
OUT = my_printf
run:
	${CC} -o ${OUT} my_printf.c
clean:
	rm -f ${OUT}
