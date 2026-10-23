

#include "APC_header.h"


/*Function to perform subtraction*/
Status sub(cal *head1,cal *tail1,cal *head2,cal *tail2,cal **head3,cal **tail3)
{
	int sub=0;
	cal* temp1 = tail1;
	cal* temp2 = tail2;									//take temporary variables to pint last nodes of list
	cal* temp3 = temp1;

	while( temp1 != NULL || temp2 != NULL)						//run loop till NULL
	{
		if( temp1->data >= temp2->data)								//if first data is greater than second data directly 
		{
			sub = (temp1->data) - (temp2->data);						//do subtraction
		}
		else
		{
			temp3 = temp1->prev;									//if not take one temp for traversal
			while( temp3 != NULL)										//run loop till NULL
			{
				if( temp3->data > 0 )									//if any data found which is greater tha 0
				{
					(temp3->data)--;									//decrement by one and stop process
					break;
				}
				else if ( temp3->data == 0 && temp3->prev != NULL)		//if zero came
				{
					temp3->data = 9;									//update it with 9
				}
				temp3 = temp3->prev;									//traverse backwards
			}

			sub = ( (temp1->data) +10) - (temp2->data);					//add borrow and do subtraction
		}
		add_res(head3,tail3,sub);									//add the result in resultatnt list
		temp1 = temp1->prev;												//traverse backwards for previous data
		temp2 = temp2->prev;
	}
}
