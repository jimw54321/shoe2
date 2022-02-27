#.PHONY = shoe2
shoe2:

CXX = g++

random_ints.o : random_ints.cpp random_ints.h card.h

shoe2.o : shoe2.cpp card.h random_ints.h random_ints.h

super_deck.o : super_deck.cpp super_deck.h

%.o : %.cpp
	$(CXX) -I. -c $<

shoe2: random_ints.o shoe2.o super_deck.o
	$(CXX) -I. $+ -o $@

clean:
	$(RM) -f *.o

realclean: clean
	$(RM) -f shoe2
