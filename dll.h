#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

// list structure
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

// function prototypes
int validation(int argc , char *argv[ ]);
int insertion(char * argv[] , Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **res_head, Dlist **res_tail);
int compare_list(Dlist *head1,Dlist *head2);
int insert_at_first(Dlist **res_head ,Dlist **res_tail , int data);
int addition(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail);
int subtraction(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail);
int multiplication(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail);
int division(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail);
void print_list(Dlist *res_head);
int compare_div(Dlist *head1,Dlist *head2);
int dl_delete_list(Dlist **head , Dlist **tail);
int insert_at_last(Dlist **head, Dlist **tail, int data);
void remove_leading_zeroes ( Dlist **head , Dlist **tail);


#endif