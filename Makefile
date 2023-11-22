# Makefile para compilar projetos C++ com o GCC

# Nome do executável
TARGET = meu_programa

# Compilador
CC = g++

# Opções de compilação
CFLAGS = -Wall -Wextra

# Diretórios dos arquivos fonte, objeto e cabeçalho
SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

# Extensões dos arquivos
SRCEXT = cpp
HDREXT = h
OBJEXT = o

# Lista de arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.$(SRCEXT))

# Gera a lista de arquivos objeto
OBJECTS = $(patsubst $(SRCDIR)/%.$(SRCEXT), $(OBJDIR)/%.$(OBJEXT), $(SOURCES))

# Flags para incluir diretórios de cabeçalho
INC = -I$(INCDIR)

# Comando para criar o diretório de objetos
MKDIR_P = mkdir -p

# Comando de compilação
$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(MKDIR_P) $(BINDIR)
	$(CC) $^ -o $@

# Comando de compilação para os arquivos objeto
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@$(MKDIR_P) $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Limpar arquivos temporários e o executável
clean:
	@$(RM) -r $(OBJDIR) $(BINDIR)

# Comando para rodar o programa
run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

# Alvos que não são arquivos
.PHONY: clean run
