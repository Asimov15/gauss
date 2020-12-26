CC=g++
CFLAGS= -std=gnu++17 -I.
DEPS= main.h forma.h shared.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
gauss: endotatio.o forma.o main.o 
	$(CC) -o gauss forma.o endotatio.o main.o $(CFLAGS)
	
clean:
	rm -f *.o core untitled gauss a.out
