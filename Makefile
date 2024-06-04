# compiler
compiler = gcc

# compiler flags
include = -I lib/include
lib = -L lib -mwindows -lmingw32 -lSDL2main -lSDL2 -static-libgcc

# source files
src = src
sources = $(src)/main.c

# output
out_dir = out
out = $(out_dir)/output

# targets
all: $(out)

$(out): $(sources)
	@if not exist $(out_dir) mkdir $(out_dir)
	$(compiler) $(include) -o $(out) $(sources) $(lib)

clean:
	rm -f $(out)

.PHONY: all clean
