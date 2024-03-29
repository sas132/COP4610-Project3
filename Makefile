CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = disk-manager.o locations.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch core main
