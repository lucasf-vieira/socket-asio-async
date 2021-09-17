CC := g++ # Compilador
BUILDDIR := build
LIBDIR := lib
TARGET := ../server.out

DIRS := bin doc include lib src

SRCEXT  := cpp

SOURCES1 := $(wildcard lib/*.o lib/*.so) $(wildcard src/*.cpp)
SRCOBJS := $(patsubst src/%, $(BUILDDIR)/%, $(SOURCES1:.$(SRCEXT)=.o))

SOURCES2 := $(wildcard include/*.cpp)
INCOBJS := $(patsubst include/%, $(BUILDDIR)/%, $(SOURCES2:.$(SRCEXT)=.o))

OBJECTS := $(INCOBJS) $(SRCOBJS)
CXXFLAGS:= -std=c++17 -Wall -Wextra -pedantic-errors # FLAGS de compilacao
LIB     := -lpthread -pthread # Bibliotecas utilizadas
INC     := -I include

# Bibliotecas compiladas
BUILD := *.so

# Comando para limpar arquivos
RM := rm -rf

.PHONY: all clean mkdirs

all: mkdirs $(TARGET)

# Cria os diretórios necessários
mkdirs:
	@mkdir -p $(BUILDDIR) $(DIRS)

# Compila e executa o programa
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: src/%.$(SRCEXT)
	$(CC) $(CXXFLAGS) $(INC) -c -o $@ $<

$(BUILDDIR)/%.o: include/%.$(SRCEXT)
	$(CC) $(CXXFLAGS) $(INC) -c -o $@ $<

# Apaga todos os arquivos .o e o executável criado
clean:
	@echo "Cleaning..."; 
	$(RM) $(BUILDDIR) $(TARGET)

#------------------------------------------------------------------------------#
