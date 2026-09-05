#include "dll.h"

int validation(int argc, char *argv[])
{
    //checking argument count 
    
    if (argc != 4)
        return FAILURE;

    // checking operators
    
    if (argv[2][0] != '+' &&
        argv[2][0] != '-' &&
        (argv[2][0] != 'x' && argv[2][0] != 'X') &&
        argv[2][0] != '/')
    {
        return FAILURE;
    }

    // ckecing entered operands are digits or not 
    
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return FAILURE;
    }

    for (int i = 0; argv[3][i] != '\0'; i++)
    {
        if (argv[3][i] < '0' || argv[3][i] > '9')
            return FAILURE;
    }
    return SUCCESS;
}

int insertion(char * argv[ ],Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **res_head, Dlist **res_tail)
{
    int data;
    
    //inserting data into linked list
    // operand 1

    for ( int i = 0 ; argv[1][i] != '\0' ; i++ )
    {
        data = argv[1][i] - 48;
        insert_at_last(head1, tail1, data);
    }

    //operand 2

    for ( int i = 0 ; argv[3][i] != '\0' ; i++ )
    {
        data = argv[3][i] - 48;
        insert_at_last(head2, tail2, data);
    }
    return SUCCESS;
} 

//printing list function

void print_list(Dlist *res_head)
{
	if (res_head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (res_head)		
	    {
		    printf("%d", res_head -> data);
		    res_head = res_head -> next;
	    }
	}
}