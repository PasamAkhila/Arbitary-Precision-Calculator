#include "dll.h"

int addition(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail)
{
    int data;
    int sum , carry = 0;
    while(tail1 != NULL && tail2 != NULL)
    {
        sum = tail1->data + tail2->data+carry; // addition from the lsb
        data = sum % 10; // getting last digit
        carry = sum/10; // generating carry
        insert_at_first(res_head , res_tail , data); //inserting result in list
        tail1 = tail1 -> prev;
        tail2 = tail2 -> prev;
    }
    while ( tail1 != NULL) // for remaining digits in list1
    {
        sum = tail1 -> data + carry;
        data = sum % 10;
        carry = sum / 10;
        insert_at_first(res_head , res_tail , data);
        tail1 = tail1->prev;
    }
    while ( tail2 != NULL) // for remaining digits in list2
    {
        sum = tail2 -> data + carry;
        data = sum % 10;
        carry = sum / 10;
        insert_at_first(res_head , res_tail , data);
        tail2 = tail2->prev;
    }
    if(carry != 0) // if carry is left 
    {
        insert_at_first(res_head, res_tail, carry);
    }
    return SUCCESS;
}
int subtraction(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail)
{
    int ret = compare_list(head1, head2);
    int diff, data;

    if (ret == 0) // if both digits are same 
    {
        insert_at_first(res_head, res_tail, 0);
        return SUCCESS;
    }
    if (ret == 1) // if list 1 is greater than list2
    {
        while (tail1 != NULL && tail2 != NULL)
        {
            if (tail1->data >= tail2->data)
            {
                data = tail1->data - tail2->data; // subtraction if no borrow
            }
            else
            {
                Dlist *borrow = tail1->prev; // if borrow is there
                while (borrow != NULL && borrow->data == 0)  // if zeros are there in operand 1 
                {
                    borrow->data = 9;
                    borrow = borrow->prev;
                }
                if (borrow != NULL) // digit other than 0
                {
                    borrow->data -= 1;
                }
                tail1->data += 10;  // after taking borrow from previous number it is added with 10
                data = tail1->data - tail2->data;
            }
            insert_at_first(res_head, res_tail, data); // then the result insert in first
            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        while (tail1 != NULL) // for remaining digits
        {
            insert_at_first(res_head, res_tail, tail1->data);
            tail1 = tail1->prev;
        }
    }
    else if (ret == 2) // for list 2 is greater than list 1 
    {
        while (tail1 != NULL && tail2 != NULL)
        {
            if (tail2->data >= tail1->data)
            {
                data = tail2->data - tail1->data;
            }
            else
            {
                Dlist *borrow = tail2->prev;
                while (borrow != NULL && borrow->data == 0)
                {
                    borrow->data = 9;
                    borrow = borrow->prev;
                }
                if (borrow != NULL)
                {
                    borrow->data -= 1;
                }
                tail2->data += 10;
                data = tail2->data - tail1->data;
            }
            insert_at_first(res_head, res_tail, data);
            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        while (tail2 != NULL)
        {
            insert_at_first(res_head, res_tail, tail2->data);
            tail2 = tail2->prev;
        }
    }
    // for removing leading zeroes
    remove_leading_zeroes(res_head , res_tail);
    return SUCCESS;
}
int division(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail)
{
    int count = 0;
    if (head2->data == 0) // if denominator is 0 
    {
        return FAILURE;
    }
    if (compare_list(head1,head2) == 2) // if numerator is 0
    {
        insert_at_first(res_head, res_tail, 0);
        return SUCCESS;
    }
    if (compare_list(head1,head2) == 0) // if both digits are same
    {
        insert_at_first(res_head, res_tail, 1);
        return SUCCESS;
    }

     Dlist *new_head = NULL;
     Dlist *new_tail = NULL;
    
    // countig the occurence of subtraction until the remainder greater than divisor 
    while (compare_list(head1, head2) == 1 || compare_list(head1, head2) == 0)    
    {
        count++;
        subtraction(head1, tail1,head2, tail2,&new_head, &new_tail);
        head1 = new_head;
        tail1 = new_tail;

        new_head = NULL;
        new_tail = NULL;
    }
    // if count is greater than 2 digits
    while (count > 0)
    {
        insert_at_first(res_head, res_tail, count % 10);
        count = count / 10;
    }
    return SUCCESS;
}
int multiplication(Dlist *head1, Dlist *tail1,Dlist *head2, Dlist *tail2,Dlist **res_head, Dlist **res_tail)
{
    // defining partial results lists
   
    Dlist *res_head1 = NULL;
    Dlist *res_tail1 = NULL;

    Dlist *res_head2 = NULL;
    Dlist *res_tail2 = NULL;

    Dlist *res_head3 = NULL;
    Dlist *res_tail3 = NULL;

    int carry;
    int res = 0;
    
    Dlist *temp = tail1;
    int shift = 0; // it uses for adding zeroes when shift occurs
    while(tail2 != NULL )
    {
        tail1 = temp;
        carry = 0;

        while(tail1 != NULL)
        {
            res = tail1->data * tail2->data + carry;
            if(shift == 0) // for first operation shift is zero
                insert_at_first(&res_head1, &res_tail1, res % 10);
            else
                insert_at_first(&res_head2, &res_tail2, res % 10);

            carry = res / 10;
            tail1 = tail1->prev;
        }
        for ( int i = 0 ; i < shift ; i++ ) // adding zeroes for shift times in the list 2
        {
            insert_at_last(&res_head2, &res_tail2,0);
        }
        
        /* addition of partial list 1 and list 2
           then list 2 and list 3 are deleted
           result becomes partial list 1
        */
        if(shift !=  0)
        {
            addition(res_head1,res_tail1,res_head2,res_tail2,&res_head3,&res_tail3);
            dl_delete_list(&res_head1 , &res_tail1);
            dl_delete_list(&res_head2 , &res_tail2);
            res_head1 = res_head3,res_tail1 = res_tail3;
            
            // resetting the list3
            res_head3 = NULL;
            res_tail3 = NULL;
        }
        shift++;
        tail2 = tail2 -> prev;
    }
    if(carry != 0) // for remaining carry
    {
        insert_at_first(res_head,res_tail, carry);
    }
    *res_head = res_head1;
    *res_tail = res_tail1;
    return SUCCESS;
}
