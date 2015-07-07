SRC_FILES = src/hex.cpp
CC_FLAGS = -Weverything -g 
CC = g++

all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o hex
