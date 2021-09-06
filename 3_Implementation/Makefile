SRC = main.c\
src/add.c\
src/search.c\
src/list.c

OBJ = main.o\
add.o\
search.o\
list.o

INC = inc
CFLAGS = -I$(INC)


all.exe : $(OBJ)
	gcc $^ -I$(INC) -o $@

%.o:src/%.c
	gcc $^ -I$(INC) -c

run: target
	./all.exe

clean:
	rm all.exe *.o src/*.o
	