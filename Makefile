OBJ = main.o
INC = -I "./"
LIB = -lgdi32
NAME = RT
CC = g++

$(NAME): $(OBJ)
	$(CC) *.o $(INV) $(LIB) -o $(NAME)
	
*.o:
	$(CC) -c *.cpp $(INC) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)