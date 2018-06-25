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
	$(BUILD)/anfibio.o \
	$(BUILD)/animal.o \
	$(BUILD)/animal_silvestre.o \
	$(BUILD)/ave.o \
	$(BUILD)/exotico.o \
	$(BUILD)/funcionario.o \
	$(BUILD)/mamifero.o \
	$(BUILD)/nativo.o \
	$(BUILD)/reptil.o \
	$(BUILD)/tratador.o \
	$(BUILD)/veterinario.o \
	lib	

app: \
	$(BIN)/main

prog_estatico: 
	$(CC) $(SRC)/main.cpp $(LIB)/*.a -I $(INCLUDE) $(FLAGS) -o $(BIN)/prog_estatico

prog_dinamico: 
	$(CC) $(SRC)/main.cpp $(LIB)/*.so -I $(INCLUDE) $(FLAGS) -o $(BIN)/prog_dinamico

lib:
# Bibliotecas estáticas. 
	$(LIB)/anfibio.a \
	$(LIB)/animal.a \
	$(LIB)/animal_silvestre.a \
	$(LIB)/ave.a \
	$(LIB)/exotico.a \
	$(LIB)/funcionario.a \
	$(LIB)/mamifero.a \
	$(LIB)/nativo.a \
	$(LIB)/reptil.a \
	$(LIB)/tratador.a \
	$(LIB)/veterinario.a \
# Bibliotecas dinâmicas.
	$(LIB)/anfibio.so \
	$(LIB)/animal.so \
	$(LIB)/animal_silvestre.so \
	$(LIB)/ave.so \
	$(LIB)/exotico.so \
	$(LIB)/funcionario.so \
	$(LIB)/mamifero.so \
	$(LIB)/nativo.so \
	$(LIB)/reptil.so \
	$(LIB)/tratador.so \
	$(LIB)/veterinario.so \

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
