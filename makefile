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

# Default e gerar executável para Linux.
all: \
		linux

include: \
		$(BUILD)/anfibio.o \
		$(BUILD)/exotico.o \
		$(BUILD)/animal.o \
		$(BUILD)/funcionario.o \
		$(BUILD)/tratador.o \
		$(BUILD)/veterinario.o \
		$(BUILD)/animal_silvestre.o \
		$(BUILD)/ave.o \
		$(BUILD)/ave_nativa.o \
		$(BUILD)/ave_exotica.o \
		$(BUILD)/mamifero.o \
		$(BUILD)/nativo.o \
		$(BUILD)/reptil.o \
		$(BUILD)/gerencia.o

# Flag para gerar executável do Windows.
windows: \
		include \
		lib_windows \
		$(BIN)/petfera_windows.exe

# Flag para gerar executável do Linux.
linux:\
		include \
		lib_linux \
		$(BIN)/petfera_linux

# Flag para gerar bibliotecas dinâmicas para o Windows.
lib_windows: \
		$(LIB)/anfibio.dll \
		$(LIB)/animal.dll \
		$(LIB)/animal_silvestre.dll \
		$(LIB)/ave.dll \
		$(LIB)/ave_nativa.dll \
		$(LIB)/ave_exotica.dll \
		$(LIB)/exotico.dll \
		$(LIB)/mamifero.dll \
		$(LIB)/nativo.dll \
		$(LIB)/reptil.dll \
		$(LIB)/tratador.dll \
		$(LIB)/veterinario.dll \
		$(LIB)/funcionario.dll \
		$(LIB)/gerencia.dll

# Flag para gerar bibliotecas dinâmicas para o Linux.
lib_linux: \
		$(LIB)/anfibio.so \
		$(LIB)/animal.so \
		$(LIB)/animal_silvestre.so \
		$(LIB)/ave.so \
		$(LIB)/ave_nativa.so \
		$(LIB)/ave_exotica.so \
		$(LIB)/exotico.so \
		$(LIB)/mamifero.so \
		$(LIB)/nativo.so \
		$(LIB)/reptil.so \
		$(LIB)/tratador.so \
		$(LIB)/veterinario.so \
		$(LIB)/funcionario.so \
		$(LIB)/gerencia.so 

debug: FLAGS += $(DEBUG)

debug: all

# Gera os .o.
$(BUILD)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) -c $< -I $(INCLUDE) $(FLAGS) -fPIC -o $@ 

# Gera os executável Linux.
$(BIN)/petfera_linux: $(SRC)/petfera.cpp
	$(CC) $< $(LIB)/*.so -I $(INCLUDE) $(FLAGS) -o $@

# Gera os executável Windows.
$(BIN)/petfera_windows.exe: $(SRC)/petfera.cpp
	$(CC) $< $(LIB)/*.dll -I $(INCLUDE) $(FLAGS) -o $@

# Gera bibliotecas estática .a para Linux.
$(LIB)/%.a: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(ARCHIVE) rcs $@ $(BUILD)/*.o

# Gera bibliotecas dinâmicas .so para Linux.
$(LIB)/%.so: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) -shared -fPIC $(BUILD)/*.o -o $@

# Gera bibliotecas estática .lib para Windows.
$(LIB)/%lib: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(ARCHIVE) rcs $@ $(BUILD)/*.o

# Gera bibliotecas dinâmicas .dll para Windows.
$(LIB)/%.dll: $(SRC)/%.cpp $(INCLUDE)/%.h
	$(CC) -shared $(BUILD)/*.o -o $@

# Cria as pastas necessária para as compilações e documentação.
config: 
	mkdir $(BIN)
	mkdir $(BUILD)
	mkdir $(LIB)
	mkdir $(DOC)

# Executa o programa.
run:
	$(BIN)/petfera_*

# Executa o gdb.
gdb:
	gdb $(BIN)/petfera_*

# Gera Doxyfile.
doxy:
	doxygen -g

# Gera documentação automática com o doxygem.
doc:
	rm -rf $(DOC)/*
	doxygen

# Remove arquivos das pastas build, bin e lib.
clean:
	rm $(BUILD)/*
	rm $(LIB)/*
	rm $(BIN)/*
