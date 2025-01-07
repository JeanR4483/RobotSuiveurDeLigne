SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=gnu99
LDFLAGS=
EXEC=robotSuiveurDeLigne

all : $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/librobot.a
	$(CC) $(LDFLAGS) -o $@ $< -lrobot -lwiringPi -lwiringPiDev -Llib

$(LIBDIR)/librobot.a : $(SRCDIR)/Moteur.o $(SRCDIR)/Suiveur.o $(SRCDIR)/capteurDistance.o 
	$(AR)  -r $@  $^

$(LIBDIR)/lib%.a : $(SRCDIR)/%.o
	$(AR)  -r $@  $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)  

clean : 
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
