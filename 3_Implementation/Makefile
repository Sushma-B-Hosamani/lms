SRC = main.c\
src/temp.c

OBJ = main.o\
temp.o

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
