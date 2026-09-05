#include "dll.h"

int main(int argc , char*argv[ ])
{

    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;
    Dlist *res_head = NULL;
    Dlist *res_tail = NULL;
      
    if (validation(argc,argv) == FAILURE)
    {
        printf("Invalid arguments\n");
        return FAILURE;
    }
    printf("************************************************************\n");
    printf("Arguments are valid \nLets proceed with operations\n");

    if(insertion(argv,&head1,&tail1,&head2,&tail2,&res_head,&res_tail) == FAILURE)
    {
        printf("Insertion failed in linked list\n");
        return FAILURE;
    }
    printf("Insertion done in linked list\n");

    remove_leading_zeroes(&head1 , &tail1);
    remove_leading_zeroes(&head2 , &tail2);

    switch(argv[2][0])
    {
    case '+':
        if(addition(head1,tail1,head2,tail2,&res_head,&res_tail) == FAILURE)
        {
            printf("Addition failed\n");
            return FAILURE;
        }
            printf("Addition = ");
            print_list(res_head);
            printf("\nAddition done\n");
            break;
    case '-':
        if(subtraction(head1,tail1,head2,tail2,&res_head,&res_tail) == FAILURE)
        {
            printf("Subtraction failed\n");
            return FAILURE;
        }
            printf("Subtraction = ");
            int ret = compare_list(head1,head2);
            if(ret == 2)
                printf("-");
            print_list(res_head);
            printf("\nSubtraction done\n");

            break;
    case 'x':
    case 'X':

        if(multiplication(head1,tail1,head2,tail2,&res_head,&res_tail) == FAILURE)
        {
            printf("Multiplication failed\n");
            return FAILURE;
        }
            printf("Multiplication = ");
            print_list(res_head);
            printf("\nMultiplication done\n");
            break;
    
    case '/':

        if(division(head1,tail1,head2,tail2,&res_head,&res_tail) == FAILURE)
        {
            printf("Division failed\n");
            return FAILURE;
        }
            printf("Division = ");
            print_list(res_head);
            printf("\nDivision done\n");
            break;
    }
    printf("************************************************************\n");
    return SUCCESS;
}





