OBJ = picture.o main.o screen.o
APPNAME = picture.a

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm
%.o : %.c
	gcc -c -o $@ $<
clean  :
	rm $(OBJ) $(APPNAME)
