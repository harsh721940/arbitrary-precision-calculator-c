
#include "APC_header.h"


extern int neg_flag;
Status division(cal* head1,cal* tail1,cal* head2,cal* tail2,cal** head3,cal** tail3)
{
	int stop_flag=0;
	int count = 0,flag,result = 0; 			//declare the all variables
	cal* temp;
	while(stop_flag != 1)
	{							 
		if(result % 2 == 0)							//if result value is even
		{
			count++;
			sub(head1,tail1,head2,tail2,head3,tail3); //perform subtraction operation
			temp = *head3;
		}
		else
		{
			count++;
			sub(*head3,*tail3,head2,tail2,&head1,&tail1);				//perform sutraction and swap the lists
			temp = head1;
		}
		stop_flag = check_node(&temp,&head2);			//if result is greater than denominator
		if(stop_flag == 1)
		{
			break;											//stop process
		}
		else
		{
			if(result % 2 == 0)
				free_node(&head1,&tail1);			//based on result value free the nodes
			else
				free_node(head3,tail3);
			result++;
		}
	}
	printf("Result is : ");
	if(neg_flag)
		printf("-");	//directly add count in list and print result
	printf("%d\n",count);
}
/*Function to check the bigger node*/
int check_node(cal** head1,cal** head2)
{
	cal* temp1 = *head1;
	cal* temp2 = *head2;
	while(temp1)
	{
		if(temp1->data > temp2->data)			//if first list data is greater than second list data return 0
			return 0;
		else if(temp1->data < temp2->data)		//if it is vice versa result 1
			return 1;
		temp1 = temp1->next;
		temp2 = temp2->next;						//traverse till end of list
	}
	return 0;										//if equal return 0
}
