#include "APC_header.h"



Status insert_args(cal **head1,cal** tail1,cal** head2,cal** tail2,char* argv1,char* argv2)
{
	insert_at_last(head1,tail1,argv1);		//Function calls to insert the arguments
	insert_at_last(head2,tail2,argv2);

}
Status insert_at_last(cal** head,cal** tail,char* argv)		//Perform insert at last function
{
	for(int i=0;i<strlen(argv);i++)										//Till end of argument vector run loop
	{
		cal* new = malloc(sizeof(cal));					//Allocate memory dynamically
		if(new == NULL)
		{
			printf("Memory allocation failed\n");						//if memory not allocated return failure
			return failure;
		}
		if(argv[i] != '-' && argv[i] != '+')						//If there were any signs ignore
		{
			new->data = argv[i] - 48;										//convert character into decimal
			if(new->data >= 0 && new->data <= 9)							//if it is between 0 and 9
			{
				new->prev = NULL;
				new->next = NULL;										//update link parts with NULL
				if(*head == NULL)
				{
					*head = new;								//if list is empty directly update the list with new address
					*tail = new;
				}
				else
				{
					new->prev = *tail;						//if not update the new prev with tail
					(*tail)->next = new;					//update tail next with new 
					*tail = new;							//at last update tail with new
				}
			}
		}
	}
	return success;
}
/*Function to free all nodes*/
Status free_all(cal** head1,cal** tail1,cal** head2,cal** tail2,cal** head3,cal** tail3)
{
	free_node(head1,tail1);
	free_node(head2,tail2);			//call function to free each node
	free_node(head3,tail3);
}
/*Free each node*/
void free_node(cal** head,cal** tail)
{
	cal* temp = (*head);
	cal* back_up = NULL;
	while(temp != NULL)						//run loop till end of list and free each node
	{
		back_up = temp->next;				//update back up with next address
		free(temp);								//free temp 
		temp = back_up;					//and then update temp with back up
	}
	*head = NULL;						//update head and tail with NULL
	*tail = NULL;
}
/*Function to find bigger based on lists*/
int find_bigger(cal** head1,cal** head2)
{
	cal* temp = *head1;
	cal* temp2 = *head2;
	while(temp && temp2)
	{
		if(temp->data > temp2->data)
			return 1;
		else if(temp2->data > temp->data)
			return 3;
		temp = temp->next;
		temp2 = temp2->next;

	}
	return 0;
}
/*Print result function to print data of node*/
void print_res(cal** head,cal** tail)
{
	printf("Result is ");
	cal* temp = *head;
	while(temp != NULL)
	{
		if(temp->data == '-')
		{
			printf("%c",'-');
		}
		else
		{
			printf("%d",temp->data);
		}
		temp = temp->next;
	}
	printf("\n");
}
/*Find length of argument ignoring the signs*/
int find_len(char* argv)
{
	int i = 0,count = 0;
	while(argv[i] != '\0')
	{
		if(argv[i] == '-' || argv[i] == '+')
		{
			i++;
			continue;
		}
		else
		{
			count++;
			i++;
		}
	}
	return count;
}
