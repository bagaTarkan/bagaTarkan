

#*****************************************************#
#    file    :   makefile                             #
#    author  :   Halis AKBAL                          #
#    update  :   31/05/2022                           #
#                                                     #
#    Aim     : We want to compile(linking),	          #
#              run, clean rapidly		     		  #
#              					      				  #
#*****************************************************#





all: clean compile run

compile: main.c
	
	@echo "\n\033[1;34mCompiling...\033[0m\n"

	@gcc main.c -c
	@gcc -o hakbal main.c -lm

run:
	@echo "\n\033[1;32mRunning...\033[0m\n"
	@./hakbal

clean:
	@echo "\n\033[1;31mRemoving compiled files...\033[0m\n"
	@rm -rf *.o
	@rm -rf *.out
	@rm -rf hakbal
