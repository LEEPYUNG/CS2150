#Pyung Lee
#PKL4FR
#4/20/2020
#
# Makefile for CS 2150 post-lab 9
# This Makefile shows how to link assembly with C/C++

# Defines the C compiler we'll be using
CXX	= clang -m64

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -g

# Defines the assembler
AS	= nasm

# Defines the flags for the assembler
ASFLAGS	= -f elf64 -g

# All of the .o files for our program
OFILES	= linkedlist.c

.SUFFIXES: .o .cxx

.SUFFIXES: .o .s

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~


