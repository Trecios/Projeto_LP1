INCLUDE = ./include
SRC = ./src
BIN = ./bin
BUILD = ./build
LIB = ./lib
DOC = ./doc
CC = g++
ARCHIVE = ar
FLAGS = -Wall -pedantic -std=c++11
DEBUG = -O0 -g -pg

.PHONY: all clean debug doxy doc

all: \
	include \
	app \
	prog_estatico \
	prog_dinamico

include: \
	$(BUILD)/mathbasic.o \
	lib	

app: \
	$(BIN)/main

prog_estatico: 
	$(CC) $(SRC)/main.cpp $(LIB)/*.a -I $(INCLUDE) $(FLAGS) -o $(BIN)/prog_estatico

prog_dinamico: 
	$(CC) $(SRC)/main.cpp $(LIB)/*.so -I $(INCLUDE) $(FLAGS) -o $(BIN)/prog_dinamico

lib: \
	$(LIB)/mathbasic.a \
	$(LIB)/mathbasic.so

debug: FLAGS += $(DEBUG)

debug: all

$(BUILD)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) -c $< -I $(INCLUDE) $(FLAGS) -o $@ 

$(BIN)/%: $(SRC)/%.cpp
	$(CC) $< $(BUILD)/*.o -I $(INCLUDE) $(FLAGS) -o $@

$(LIB)/%.a: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(ARCHIVE) rcs $@ $(BUILD)/*.o
	@echo "+++ biblioteca estática criada em $@ +++ "

$(LIB)/%.so: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) -shared -fPIC $(BUILD)/*.o -o $@
	@echo "+++ biblioteca dinâmica criada em $@ +++ "

config: 
	mkdir $(BIN)
	mkdir $(BUILD)
	mkdir $(LIB)
	mkdir $(DOC)

run:
	$(BIN)/main
	$(BIN)/prog_estatico
	$(BIN)/prog_dinamico

gdb:
	gdb $(BIN)/main

doxy:
	doxygen -g

doc:
	rm -rf $(DOC)/*
	doxygen

clean:
	rm $(BIN)/*
	rm $(BUILD)/*
	rm $(LIB)/*
