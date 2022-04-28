###############################################################################
# Tyler Perkins
# 9-23-21
# Makefile
#

CC = g++

FLAGS  = -pipe

CFLAGS  = -Wall
CFLAGS += -Ofast
CFLAGS += -g
#CFLAGS += -pg

LIBRARIES = -lpthread

SRC = $(shell find ./src -name '*.cpp')
OBJ = $(subst .cpp,.o,$(SRC))
BIN = ./bin

PREFIX    = /usr/local
MANPREFIX = $(PREFIX)/share/man

TARGET = crowtest

MAKEFLAGS += --jobs=4

OPTIONS  = -DCROW_ENABLE_COMPRESSION -lz
#OPTIONS += -DCROW_ENABLE_SSL -lssl

all : $(OBJ)
	@echo LD $@
	@$(CC) $(FLAGS) $(CFLAGS) -o $(BIN)/$(TARGET) $(OBJ) $(LIBRARIES) $(OPTIONS)

.cpp.o :
	@echo CC $<
	@$(CC) $(FLAGS) $(CFLAGS) $(LIBRARIES) $(OPTIONS) $(DEFINITIONS) -c $< -o $@

install : all

uninstall :

clean :
	find . -type f -name '*.o' -delete
	rm -rf $(BIN)/*
