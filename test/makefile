CC = gcc
CFLAGS =  -g -I../include -fsanitize=address

%: ../src/%.c %.c
	$(CC) $(CFLAGS) -o $@ $^

LinkList: ../src/LinkList.c LinkList.c ../src/Algorithms.c
	$(CC) $(CFLAGS) -o $@ $^
CirLinkList: ../src/CirLinkList.c ../src/LinkList.c CirLinkList.c ../src/Algorithms.c
	$(CC) $(CFLAGS) -o $@ $^
DCirLinkList: ../src/DCirLinkList.c ../src/DNode.c DCirLinkList.c ../src/Algorithms.c
	$(CC) $(CFLAGS) -o $@ $^
DLinkListFreq: ../src/DLinkListFreq.c ../src/DNode.c DLinkListFreq.c ../src/Algorithms.c
	$(CC) $(CFLAGS) -o $@ $^



