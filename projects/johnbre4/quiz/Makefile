CFLAGS = -Wall -fpic -coverage -lm

test: testme.o
	g++ testme.o -o testme  $(CFLAGS)

%.o: %.cpp %.hpp
	g++ -c $<

clean:
	rm -f *.o testme