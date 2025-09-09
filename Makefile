

NM_SRC	=	$(shell find src/ -name '*.c')

#OBJ_SRC =	$(shell find objdmp/src/ -name '*.c')

NM_OBJ	=	$(NM_SRC:.c=.o)

#OBJ_OBJ =	$(OBJ_SRC:.c=.o)

VAL_FLAG1	=	--track-origins=yes

VAL_FLAG2	=	--leak-check=full

VAL_FLAG3	=	--leak-cresolution=high

VAL_FLAG4	=	--track-fds=yes

VAL_FLAGS	=	$(VAL_FLAGS1) $(VAL_FLAGS2)

NM_EXEC	=	my_nm

#OBJ_EXEC = my_objdump

all:	nm

nm:	$(NM_OBJ)
	@echo -e "\e[05;01;34m=====EXEC COMPILING=====\e[00;01;34m"
	gcc -o $(NM_EXEC) $(NM_OBJ) -g3

#objdump:	$(OBJ_OBJ)
#	@echo -e "\e[05;01;34m=====EXEC COMPILING=====\e[00;01;34m"
#	gcc -o $(OBJ_EXEC) $(OBJ_OBJ) -g3

%.o:	%.c
	@echo -e "\e[05;01;32m=====COMPILING .C TO .O=====\e[00;01;32m"
	gcc -o $@ -c $< -g3

test_run:	$(UNIT_SRC)
		gcc -o unit_test $(UNIT_SRC) --coverage -lcriterion
		./unit_test
		gcovr --exclude ./tests
		gcovr --exclude ./tests --branches
deb:
	@echo -e "\e[05;01;36m=====DEBUG COMPILING=====\e[00;01;36m"
	gcc $(SRC) -g3
	@echo -e "\e[00;00m"

clean:
	@echo -e "\e[05;01;35m=====.O REMOVING=====\e[00;01;35m"
#	rm -f $(OBJ_OBJ)
	rm -f $(NM_OBJ)

fclean:	clean
	@echo -e "\e[05;01;31m=====EXEC REMOVING=====\e[00;01;31m"
	rm -f $(NM_EXEC)
#	rm -f $(OBJ_EXEC)

re: fclean all
