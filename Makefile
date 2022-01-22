BIN := main
SRC := main.cpp 
EXT_CPP := /Users/dmitry/Programming/C/Lists/lists.c
EXT_H := /Users/dmitry/Programming/C/Lists/list_header.h
CC := g++
CFLAGS := -I
LDFLAGS :=

$(BIN): $(SRC)
	clear && $(CC) $(SRC) $(EXT_CPP) $(CFLAGS) $(EXT_H) $(LDFLAGS) -o $(BIN)

clean:
	rm -rf $(BIN)