.PHONY: all clean test format

CXX = g++
OFLAGS = -O2 -Wall -DNDEBUG
LDFLAGS = -lUnitTest++

SOURCES=TableCipher.cpp main.cpp
HEADERS=headers/modifedTableCipher.hpp
EXECUTABLE=unit

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(SOURCES) -o $(EXECUTABLE) $(OFLAGS) $(LDFLAGS)
	
test: $(EXECUTABLE)
	./$(EXECUTABLE)
	

format:
	astyle $(SOURCES) $(HEADERS)

clean:
	rm -f $(EXECUTABLE) *.orig
