
#include "APC_header.h"


extern int neg_flag;
Status mul(cal* head1,cal* tail1,cal* head2,cal* tail2,cal** head3,cal** tail3)
{
	int result = 0,count= 0,multiply = 0,carry = 0;		//declare the variables
	cal* temp1 = tail1;
	cal* temp2 = tail2;
	cal* result_head1 = NULL;
	cal* result_tail1 = NULL;
	cal* result_head2 = NULL;			//declare the temporary variables to traverse back
	cal* result_tail2 = NULL;
	while(temp2)								//run loop till reaching NULL
	{
		carry=0;								//declare carry as 0 every time
		temp1 = tail1;							//update temp with tail everytime
		while(temp1)							//run loop till end of list
		{
			multiply =  carry;							//update mult with carry every time
			for(int i = 0;i<temp2->data;i++)
			{
				multiply = multiply + temp1->data;			//logic to find multipication
			}
			carry = multiply / 10;						//find carry and update the mult variable
			multiply = multiply % 10;
			if(count == 0)
			{
				add_res(&result_head1,&result_tail1,multiply);			//for first time add result in head1
			}
			else
			{
				add_res(&result_head2,&result_tail2,multiply);			//remaining all times update in head2
			}

			temp1 = temp1->prev;										//traverse through the list
		}
		if(carry > 0 && count > 0)
		{
			add_res(&result_head2,&result_tail2,carry);				//if carry is there add carry also
		}
		if(count==0)
		{
			if(carry > 0)
			{
				add_res(&result_head1,&result_tail1,carry);				//add carry
			}
			add_res(&result_head1,&result_tail1,0);						//add 0 for next iteration
		}
		if(count >= 1)
		{
			for(int i = 1;i<=count;i++)
			{
				insert_last(&result_head2,&result_tail2);					//add 0 at last for making nodes equal
			}
			if(count%2 == 1)
			{
				//based on count add result in one node
				add(result_head1,result_tail1,result_head2,result_tail2,head3,tail3);
				free_node(&result_head2,&result_tail2);			//free nodes after adding results
				free_node(&result_head1,&result_tail1);
				add_res(head3,tail3,0);
			}
			else
			{
				//based on count add result in another node
				add(*head3,*tail3,result_head2,result_tail2,&result_head1,&result_tail1);
				free_node(head3,tail3);
				free_node(&result_head2,&result_tail2);				//free the nodes after adding results
				add_res(&result_head1,&result_tail1,0);
			}
		}
		temp2 = temp2->prev;
		count++;
	}
	if(count%2)
	{
		free_first(&result_head1);			//free the 0 at starting and print result and add negative sign
		if(neg_flag)
			add_res(&result_head1,&result_tail1,'-');
		print_res(&result_head1,&result_tail1);
	}
	else
	{
		free_first(head3);					//free 0 and print result based on flag add negative sign
		if(neg_flag)
			add_res(head3,tail3,'-');
		print_res(head3,tail3);
	}
	free_node(&result_head1,&result_tail1);
	free_node(&result_head2,&result_tail2);
	return success;
}
/*Insert at last function*/
void insert_last(cal** head,cal** tail)
{
	cal* new = malloc(sizeof(cal));
	if(new == NULL)
	{
		printf("Memory allocation failed\n");
	}
	else
	{
		new->data = 0;
		new->prev = *tail;
		(*tail)->next = new;
		new->next = NULL;
		*tail = new;
	}
}
/*Function to free the first node*/
void free_first(cal** head)
{
	cal* temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
