#include "dll.h"

int insert_at_first(Dlist **res_head ,Dlist **res_tail , int data)
{
    // creating new node
    
    Dlist *new = malloc(sizeof(Dlist));
    if ( new == NULL )
        return FAILURE;
        
    new -> data = data;
    new->prev = NULL;

    // if list is empty
    if(*res_head == NULL)
    {
        new -> next = *res_head;
        *res_head = new;
        *res_tail = new;
        return SUCCESS;
    }
    // if list is not empty
    else
    {
        new -> next = *res_head;
        (*res_head)->prev = new;
        *res_head = new;
    }
}


int compare_list(Dlist *head1,Dlist *head2)
{
    int count1 = 0 , count2 = 0;
    
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;
    
    Dlist *c_temp1 = head1;
    Dlist *c_temp2 = head2;
    //counting nodes in the list
    
    while ( c_temp1 != NULL)
    {
        count1++;
        c_temp1 = c_temp1->next;
    }

    while ( c_temp2 != NULL)
    {
        count2++;
        c_temp2 = c_temp2->next;
    }

    if(count1 > count2)
    {
        return 1; // list1 having more digits than list2
    }
    else if(count1 < count2)
    {
        return 2; // list2 having more digits than list1
    }
     
    // if same checking msb bits for which is greater
    else
    {
        while(temp1 != NULL && temp2 != NULL ) // checking each digit 
        {
            if(temp1 -> data > temp2 -> data)
                return 1;
            else if(temp1 -> data < temp2 -> data)
                return 2;
            else
            {
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
        }
    }
    return 0; // if both numbers are same
}

// checking operands for division operation
int compare_div(Dlist *head1,Dlist *head2)
{
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    if(temp1 == 0 ) // if numerator is 0
        return 0;
    else if ( temp2 == 0) // if deniminator is 0
        return -1;
    else // checking which number is greater 
    {
        while(temp1 != NULL && temp2 != NULL )
        {
            if(temp1->data > temp2->data)
                return 1;
            else if(temp1 -> data < temp2->data)
                return 2;
            else
            {
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
        }
    }
    return 0; // if both numbers are equal
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
    // checking for list is empty
    if(*head == NULL )
        return FAILURE;
    
    Dlist *temp = *head;
    Dlist *next;
    
    //deleting each node one by one from head
    while(temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    
    // making head and tail pointers to null
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    //creating node and intializing
    Dlist *new = malloc(sizeof(Dlist));
    
    if(new == NULL)
        return FAILURE;
    
    new -> data = data;
    new -> next = NULL;
    new -> prev = NULL;
    
    //if the list is empty 
    if( *head == NULL)
    {
        new->prev = NULL;
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    //if the list is not empty
    else
    {
        new->prev = *tail;
        (*tail) -> next = new;
        *tail = new;
        return SUCCESS;
    }
}
    void remove_leading_zeroes ( Dlist **head , Dlist **tail)
    {
        if(*head == NULL )
            return;
        while (*head != NULL && (*head)->data == 0 && (*head)->next != NULL)
        {
            Dlist *temp = *head;
            *head = (*head)->next;
            (*head)->prev = NULL;
            free(temp);
        }

        Dlist *t = *head;
        while(t != NULL && t->next != NULL)
            t = t->next;
        *tail = t;
    }
