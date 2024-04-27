CC = gcc
CFLAGS =  -g -I../include -fsanitize=address

# 编译并链接
%: ../src/%.c  %.c
	$(CC) $(CFLAGS) -o $@ $^



