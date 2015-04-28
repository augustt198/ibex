CC=clang
CFLAGS=-Wall -g `llvm-config --cflags`
LD=clang++
LDFLAGS=`llvm-config --cxxflags --ldflags --libs core executionengine jit interpreter analysis native bitwriter --system-libs`

INCLUDES=-Iincludes/ -Iincludes/util/
SOURCES=$(wildcard src/*.c) $(wildcard src/util/*.c)

all: ${SOURCES}
	@mkdir -p bin
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o bin/ixc

clean:
	@rm -rf .*
	@rm bin/ixc
