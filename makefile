SRC = *.cpp
OBJ = *.o
TARG = td
CC = g++
CFLAG = -W
VALGRIND = valgrind
VALGRIND_OPTS = --leak-check=full --show-leak-kinds=all

all: $(TARG)

$(TARG): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(TARG)

$(OBJ): $(SRC)
	$(CC) $(CFLAG) -c $(SRC)
clean:
	rm -f $(TARG) $(OBJ)

run: $(TARG)
	./$(TARG)

valgrind: $(TARG)
	$(VALGRIND) $(VALGRIND_OPTS) ./$(TARG)