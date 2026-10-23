
#include "APC_header.h"



Status add(cal *head1,cal *tail1,cal *head2,cal *tail2,cal **head3,cal **tail3){
	int carry=0,sum=0,res=0,car=0;					//initially declare all variables

	cal *temp1 = tail1;
	cal *temp2 = tail2;

	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1->prev == NULL && temp2->prev != NULL)
		{
			add_res(&head1,&tail1,0);								//if both linked lists are not same add 0s at starting
		}
		else if(temp2->prev == NULL && temp1->prev != NULL)
		{
			add_res(&head2,&tail2,0);
		}
		res = (temp1->data) + (temp2->data) + carry;				//logic to find the addition
		car = res / 10;												//find carry to update in next iteration
		res = res % 10;												//update result value
		sum =  res;

		add_res(head3,tail3,sum);									//add sum in list

		temp1 = temp1->prev;
		temp2 = temp2->prev;
		carry = car;
	}
	if(carry != 0)
	{
		add_res(head3,tail3,carry);								//at last if carry is not 0 add carry also
	}

	return success;
}
Status add_res(cal **head3,cal **tail3,int sum)			//function to insert at first
{
	cal* new = malloc(sizeof(cal));							//allocate memory dynamically
	if(new == NULL)
	{
		printf("Memory allocation failed\n");								//if memory is not allocated return failure
		return failure;
	}

	new->data = sum;														//add data part with sum
	new->prev = NULL;
	new->next = NULL;														//update link parts with NULL
	if( *head3 == NULL)
	{	
		*head3 = new;													    //if list is empty update head and tail
		*tail3 = new;
	}
	else
	{
		new->next = *head3;													//update next part with head address
		(*head3)->prev = new;												
		*head3 = new;														//update head3 with new
	}
	return success;															//return success
}
