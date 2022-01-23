BIN := main
SRC := src/main.cpp 
EXT_HPP := include/list.hpp include/stack.hpp include/queue.hpp
HEADERS := include/header.hpp #-I $(EXT_HPP)
CC := g++
CFLAGS := 
LDFLAGS :=

$(BIN): $(SRC) 
	clear && $(CC) -I$(HEADERS) $(SRC) $(CFLAGS) $(LDFLAGS) -o bin/$(BIN)

clean:
	rm -rf bin/$(BIN)