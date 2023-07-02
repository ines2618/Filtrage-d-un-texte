CC=clang
CFLAGS=-std=c17 -Wall
OBJ=filtrage.o ABR.o


filtre: $(OBJ)
	$(CC)  -o  $@  $^

filtrage: filtrage.c filtrage.h ABR.c
	$(CC)  $(CFLAGS) -c  -o  $@  $<


ABR:  ABR.c ABR.h
	$(CC) $(CFLAGS)  -c  -o $@  $<



clean:
	rm -f *.o