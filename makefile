CC= g++
CFLAGS= -std=gnu++17 -I.
DEPS= forma.h shared.h

gauss: forma.o endotatio.o main.o 
	$(CC) -o gauss forma.o endotatio.o main.o $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o core untitled gauss a.out
