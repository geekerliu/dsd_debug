OBJ=test
SRC=main.c debug.c
all:
	$(CC) -o $(OBJ) $(SRC) 
clean:
	$(RM) $(OBJ) 
