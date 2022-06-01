
/* ***** --------------- HW 10 (171044080.c (main.c)) ------- * CSE 102 / 2021-2022 Spring /// Halis AKBAL \\\ ***171044080*** /


/************************************************************************#
#    file    :   171044080.c                               	 	         #
#    author  :   Halis AKBAL                                	         #
#    update  :   01/06/2022                                 	         #
#                                                           	         #
#    Aim     : To do implement the tower of hanoi problem using stack,   #
#              which is one of the abstract data structures.             #
#              Also, we implement a solution to tower-of-hanoi problem   #
#              without recursion.                                        #
#                                                                        #
*************************************************************************/



#include <stdio.h>    /* printf(), scanf(), fprintf(). Asks input from the user.It transmits the message, the output to the user.*/
#include <stdlib.h>   /* malloc(), calloc(), realloc(), free() functions (for dynamic memory management)*/



/* macros */

#define  MYEXIT          0
#define  _HYPHEN_       '-'
#define _NEW_LINE_      '\n'
#define _EQUAL_         '='
#define Myerr           -100
#define MyCond          -1
#define _SIZE_int_      sizeof(int)
#define divide_two       2
#define  MYEXIT          0
#define  _HYPHEN_       '-'
#define _NEW_LINE_      '\n'
#define _EQUAL_         '='
#define OneBy            1
#define MyOne           '1'
#define MyTwo           '2'
#define MyThree         '3'
#define remainThree      3
#define STACK_BLOCK_SIZE 10



#define my_sizeof(type)       (char *)(&type+1)-(char*)(&type)
#define _PRINT_NEW_LINE_()    (printf("%c",_NEW_LINE_))                                             /* macro functions*/
#define _PRINT_WELCOME_()     (printf("\t\t  \e[0;30;47m## WELCOME TO MY PROGRAM  ##\e[0m"))
#define _MY_NAME_()           (printf("\t\t \e[1;32;43m## STUDENT NAME: HALIS AKBAL ##\e[0m"))
#define _GOODBYE_()           (printf("\t\t\e[5;33;42m I hope our story ends lovely here.\e[0m"))
#define _ARRAY_SIZE_(x)       (sizeof(x) / sizeof(x[0]))
#define _GET_NUMBER_()        (printf("Please, Enter tower size: "))
#define _PRINT_EQUAL()              (printf("%c",_EQUAL_))
#define _Print_Move()               (printf("Move the disk "))
#define _Print_disc_Num(number)     (printf("%d ",number))
#define _Print_from(origin)         (printf("from \'%c\' ",origin))
#define _Printt_to(target)          (printf("to \'%c\'",target))
      


typedef struct {

    int * array;
    int currentsize;
    int maxsize;

} Stack;

// int push(stack * s, int d); /* the stack array will grow STACK_BLOCK_SIZE entries at
// a time */

// int pop(stack * s); /* the stack array will shrink STACK_BLOCK_SIZE entries at a
// time */

// stack * init_return(); /* initializes an empty stack */

// int init(stack * s); /* returns 1 if initialization is successful */


void red () ;

void yellow();

void reset ();

void purple();

void blue ();

void cyan ();

void green();

void newline();

void hypen();

void printequal();

int my_power_function(int basement, int power);

Stack * init_return(); /* initializes an empty stack */

int init(Stack * s); /* returns 1 if initialization is successful */


Stack* createStack(unsigned maxsize);

void my_stack_function(int my_stack_size, Stack *my_source, Stack *aux, Stack *my_destination);






int main()
{

	int my_stack_size;


    newline();
    _PRINT_WELCOME_();
    newline();
    _MY_NAME_();
    newline();
    cyan();
    _GET_NUMBER_();
    reset();

	
	scanf("%d", &my_stack_size);

	Stack *my_source, *my_destination, *aux;


	my_source = createStack(my_stack_size);
	aux = createStack(my_stack_size);
	my_destination = createStack(my_stack_size);



    // sourceDisc = init_return(my_stack_size);
    // auxilaryDisc = init_return(my_stack_size);
    // destinationDisc = init_return(my_stack_size);

    if(init(my_source) == MYEXIT ) {

        printf("Initialization of the stack(sourceDisc) is unsuccessful");
        newline();
        exit(OneBy);
    }

    if(init(aux) == MYEXIT){
        printf("Initialization of the stack(auxiliaryDisc) is unsuccessful");
        newline();
        exit(OneBy);
    }

    if(init(my_destination) == MYEXIT){
        printf("Initialization of the stack(destinationDisc) is unsuccessful");
        newline();
        exit(OneBy);
    }


    system("clear");
    newline();

    yellow();
    printequal();
    printequal();
    _PRINT_NEW_LINE_();
    purple();
    hypen();
    printf("Here are the steps");
    hypen();
    _PRINT_NEW_LINE_();
    blue();
    printequal();
    printequal();

    reset();
    newline();
    newline();
	my_stack_function(my_stack_size, my_source, aux, my_destination);
    newline();
    _GOODBYE_();
    newline();
    newline();
    return MYEXIT;




	return 0;
}



void printequal(){

    for(int i=0;i<37;i++)
        _PRINT_EQUAL();
   // printf("\n");
    //_PRINT_NEW_LINE_();
}

Stack* createStack(unsigned maxsize)
{
	Stack* stack =(Stack*) malloc(sizeof(Stack));
	stack -> maxsize = maxsize;
	stack -> currentsize = MyCond;
	stack -> array =(int*) malloc(stack -> maxsize * _SIZE_int_);

	return stack;
}


int complete( Stack* stack)
{
return (stack->currentsize == stack->maxsize - OneBy);
}

int idle( Stack* stack)
{
return (stack->currentsize == MyCond);
}


void push( Stack *stack, int item)
{
	if (complete(stack))
		return;
	stack -> array[++stack -> currentsize] = item;
}


int pop( Stack* stack)
{
	if (idle(stack))

		return Myerr;

	return stack -> array[stack -> currentsize--];
}


void print_action(char origin, char target, int disk)
{   
    blue();
    _Print_Move();               
    
    reset();
    green();
     _Print_disc_Num(disk);    
    
    reset();
    red();
     _Print_from(origin);              
    reset();
    yellow();
    
    _Printt_to(target);
    reset();
    newline();

}

void newline(){
    /*to call the function to insert a space above or below, instead of using a continuous newline character*/
    for(int i=0;i<3;i++)
        _PRINT_NEW_LINE_();
}

void motion_hoop( Stack *my_source, Stack *my_destination, char source, char destination)
{
	int stick1 = pop(my_source);

	int stick2 = pop(my_destination);

	
	if (stick1 == Myerr)
	{
		push(my_source, stick2);
		print_action(destination, source, stick2);
	}

	
	else if (stick2 == Myerr)
	{
		push(my_destination, stick1);
		print_action(source, destination, stick1);
	}

	
	else if (stick1 > stick2)
	{
		push(my_source, stick1);
		push(my_source, stick2);
		print_action(destination, source, stick2);
	}

	
	else
	{
		push(my_destination, stick2);
		push(my_destination, stick1);
		print_action(source, destination, stick1);
	}
}


void my_stack_function(int my_stack_size, Stack *my_source, Stack *aux, Stack *my_destination)
{
	int i;
    int Number_of_Moves;

	char source = MyOne;
    char my_desk = MyThree;
    char auxilary = MyTwo;


	if (my_stack_size % divide_two == MYEXIT)
	{
		char temp = my_desk;
		my_desk = auxilary;
		auxilary = temp;
	}
	Number_of_Moves = my_power_function(divide_two, my_stack_size) - OneBy;


	for (i = my_stack_size; i >= OneBy; i--)
		push(my_source, i);

	for (i = OneBy; i <= Number_of_Moves; i++)
	{
		if (i % remainThree == OneBy)
		motion_hoop(my_source, my_destination, source, my_desk);

		else if (i % remainThree == divide_two)
		motion_hoop(my_source, aux, source, auxilary);

		else if (i % remainThree == MYEXIT)
		motion_hoop(aux, my_destination, auxilary, my_desk);
	}
}







void red () {
    printf("\033[1;31m");
}

void yellow(){
    printf("\033[1;33m");
}

void reset () {
    printf("\033[0m");      /*colors codes*/
}

void purple(){
    printf("\033[5;35m");

}

void blue () {
    printf("\033[1;34m");
}

void cyan () {
    printf("\033[1;36m");
}

void green(){
    printf("\033[1;32m");
}


void hypen(){

    for(int i=0;i<28;i++)
        printf("%c",_HYPHEN_);
    //_PRINT_NEW_LINE_();
}





Stack * init_return(){



} /* initializes an empty stack */





int init(Stack * s){

    if(s == NULL) {

        return 0;


    }

    else
        return 1;



} /* returns 1 if initialization is successful */


int my_power_function(int basement, int power)
{

    if(power < MYEXIT)
     return MyCond;

        
    int outcome = OneBy;
    while (power)
     {
        if (power & OneBy)
             outcome *= basement;
        power >>= OneBy;
        basement *= basement;
    }

    return outcome;

}