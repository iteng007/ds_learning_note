CC = gcc
CFLAGS =  -g -I../include -fsanitize=address

# 编译并链接
%: ../src/%.c  %.c  ../src/Algorithms.c
	$(CC) $(CFLAGS) -o $@ $^



