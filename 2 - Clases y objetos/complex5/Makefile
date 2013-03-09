CC = g++
CFLAGS = -g -Wall -O2
SRC = main.cpp
OBJ = main.o
EXE = main.exe

all : clean $(EXE)

clean:
	$(RM) $(OBJ) $(EXE)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)	
	
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)