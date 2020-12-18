#include<stdio.h>
#include<stdlib.h>
#define Max 5

int flag=0;

struct Queue
{
	int rear;
	int front;
	int* arr;
}*s=NULL;

//-1
struct Queue* initialise_structure()
{
	s=(struct Queue*)calloc(1,sizeof(struct Queue));
	s->rear=s->front=-1;
	
	return s;
}

//0
int* initialise_array()
{
	s->rear=s->front=0;
	return s->arr=(int*)calloc(Max,sizeof(int));
}

//1
struct Queue* insert_rear(int val)
{
	if((s->rear+1)%Max==s->front)	
	{
		printf("\n\nError: Overflow.");
		return NULL;
	}
	
	if(s->rear==-1)
	{
		if(!initialise_array())
		{
			printf("\n\nError: Dynamic allocation failed.");
			return NULL;	
		}
		else
		flag=2;
		
		s->rear=-1;
	}
	
	s->rear=(s->rear+1)%Max;
	s->arr[s->rear]=val;
	
	return s;
}

//2
struct Queue* insert_front(int val)
{
	if((s->rear+1)%Max==s->front)	
	{
		printf("\n\nError: Overflow.");
		return NULL;
	}
	
	if(s->rear==-1)
	{		
		if(!initialise_array())
		{
			printf("\n\nError: Dynamic allocation failed.");
			return NULL;	
		}
		else
		flag=2;
		
		s->front=1;
	}
	
	s->front=(Max-1)-((Max-s->front)%Max);
	s->arr[s->front]=val;
	
	return s;
}

//3
struct Queue*  delete_rear(int* val)
{
	if(s->rear==-1)
	{
		if(flag==2)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	*val=s->arr[s->rear];
	
	if(s->front==s->rear)
	{
		s->front=s->rear=-1;
		free(s->arr);
		s->arr=NULL;
	}
	
	else
	s->rear=(Max-1)-((Max-s->rear)%Max);
	
	return s;
}

//4
struct Queue* delete_front(int* val)
{
	if(s->rear==-1)
	{
		if(flag==2)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	*val=s->arr[s->front];
	
	if(s->front==s->rear)
	{
		s->front=s->rear=-1;
		free(s->arr);
		s->arr=NULL;
	}
	
	else
	s->front=((s->front)+1)%Max;	
	
	return s;
}

//5
struct Queue* front(int* val)
{	
	if(s->rear==-1)
	{
		if(flag==2)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	*val=s->arr[s->front];
	
	return s;
}

//6
struct Queue* back(int* val)
{
	if(s->rear==-1)
	{
		if(flag==2)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	*val=s->arr[s->rear];
	
	return s;
}

//7
int size()
{	
	if(s->rear==-1)
	{
		printf("\n\nError: The circular queue is empty.");
		return 0;
	}
	
	int cnt=0,ind=s->front;
	
	while(ind!=s->rear)
	{
		ind=(ind+1)%Max;
		cnt++;
	}
	
	cnt++;
	
	return cnt;
}

//8
int* empty()
{
	return s->arr;
}

//9
int* full()
{
	if((s->rear+1)%Max!=s->front)	
	return NULL;
	
	return s->arr;
	
}

//10
struct Queue* display()
{
	if(s->rear==-1)
	{
		if(flag==1)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		printf("\n\nError: The circular queue is empty.");
		return NULL;
	}
	
	int ind=s->front;
	
	printf("\n\n");
	
	while(ind!=s->rear)
	{
		printf("%d ",s->arr[ind]);
		ind=(ind+1)%Max;
	}
	
	printf("%d ",s->arr[ind]);
	
	return s;
}

void free_all()
{
	if(s->arr)
	{
		free(s->arr);
		s->arr=NULL;
	}
	
	free(s);
	s=NULL;
}

void main_menu()
{
	printf(" MAIN-MENU:\n------------\n");
	printf("\n1) Input Restricted.");
	printf("\n2) Output Restricted.");
	printf("\n3) No Restrictions.");
	printf("\n4) Re-display the menu.");
	printf("\n0) Exit.");
}

void input_restricted_menu()
{
	printf("\n\n SUB-MENU:\n-----------\n");
	printf("\n1)  Insert rear.");
	printf("\n2)  Delete rear.");
	printf("\n3)  Delete front.");
	printf("\n4)  Front.");	
	printf("\n5)  Back.");
	printf("\n6)  Size");
	printf("\n7)  Empty.");
	printf("\n8)  Full.");
	printf("\n9)  Display.");
	printf("\n10) Re-display the sub-menu.");
	printf("\n0)  Exit.");
}

void output_restricted_menu()
{
	printf("\n\n SUB-MENU:\n-----------\n");
	printf("\n1)  Insert Rear.");
	printf("\n2)  Insert Front.");
	printf("\n3)  Delete Rear.");
	printf("\n4)  Front.");
	printf("\n5)  Back.");	
	printf("\n6)  Size.");
	printf("\n7)  Empty.");
	printf("\n8)  Full.");
	printf("\n9)  Display.");
	printf("\n10) Re-display the sub-menu.");
	printf("\n0)  Exit.");
}

void no_restrictions_menu()
{
	printf("\n\n SUB-MENU:\n-----------\n");
	printf("\n1)  Insert Rear.");
	printf("\n2)  Insert Front.");
	printf("\n3)  Delete Rear.");
	printf("\n4)  Delete front.");
	printf("\n5)  Front.");
	printf("\n6)  Back.");	
	printf("\n7)  Size.");
	printf("\n8)  Empty.");
	printf("\n9)  Full.");
	printf("\n10) Display.");
	printf("\n11) Re-display the sub-menu.");
	printf("\n0)  Exit.");
}

void input_restricted()
{
	if(!flag && !(initialise_structure()))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return;
	}
	
	input_restricted_menu();
	
	int i,ch,val;
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
						
	while(ch)
	{
		switch(ch)
		{
			case 1:		printf("\n\nEnter the value to be inserted from rear: ");
						scanf("%d",&val);
						if(insert_rear(val))
						printf("\n\nMessage: Successfully inserted the value from rear '%d' inside the double ended queue.",val);
						break;
								
			case 2:		if(delete_rear(&val))						
						printf("\n\nMessage: The item successfully deleted out from rear of the double ended queue is: %d",val);
						break;
								
			case 3:		if(delete_front(&val))						
						printf("\n\nMessage: The item successfully deleted out of from front of the double ended queue is: %d",val); 	
						break;
								
			case 4:		if(front(&val))
						printf("\n\nMessage: The item pointed by the front in the double ended queue is: '%d'",val);
						break;
								
			case 5:		if(back(&val))
						printf("\n\nMessage: The item pointed by the rear in the double ended queue is: '%d'",val);
						break;
								
			case 6:		printf("\n\nMessage: The number of elements present in the double ended queue is: '%d'",size());	
						break;
											
			case 7:		if(!empty())
						{
							if(flag==2)
							printf("\n\nMessage: Underflow.");
							
							else
							printf("\n\nMessage: The double ended queue is empty.");
						}
						
						else
						printf("\n\nMessage: The double ended queue is not empty.");
						
						break;
								
			case 8:		if(!full())
						printf("\n\nMessage: The double ended queue is not full.");
						
						else
						printf("\n\nMessage: Overflow.");
						break;
								
			case 9:		printf("\n\nMessage: Displaying the whole double ended queue.");
						if(display())
						printf("\n\nMessage: Successfully displayed the whole double ended queue.");	
						break;	
								
			case 10:	printf("\n\nMessage: Re-displaying the menu.\n\n");
						input_restricted_menu();	
						break;		
											
			default: 	printf("\n\nError: Wrong choice.");	
						break;
		};
							
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	flag=1;
}

void output_restricted()
{
	if(!flag && !(initialise_structure()))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return;
	}
	
	output_restricted_menu();
	
	int i,ch,val;
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
						
	while(ch)
	{
		switch(ch)
		{
			case 1:		printf("\n\nEnter the value to be inserted from rear: ");
						scanf("%d",&val);
						if(insert_rear(val))
						printf("\n\nMessage: Successfully inserted the value from rear '%d' inside the double ended queue.",val);
						break;
								
			case 2:		printf("\n\nEnter the value to be inserted from front: ");
						scanf("%d",&val);
						if(insert_front(val))
						printf("\n\nMessage: Successfully inserted the value from front '%d' inside the double ended queue.",val);
						break;
								
			case 3:		if(delete_rear(&val))						
						printf("\n\nMessage: The item successfully deleted out of from rear of the double ended queue is: %d",val); 	
						break;
								
			case 4:		if(front(&val))
						printf("\n\nMessage: The item pointed by the front in the double ended queue is: '%d'",val);
						break;
								
			case 5:		if(back(&val))
						printf("\n\nMessage: The item pointed by the rear in the double ended queue is: '%d'",val);
						break;
								
			case 6:		printf("\n\nMessage: The number of elements present in the double ended queue is: '%d'",size());	
						break;
											
			case 7:		if(!empty())
						{
							if(flag==2)
							printf("\n\nMessage: Underflow.");
							
							else
							printf("\n\nMessage: The double ended queue is empty.");
						}
						
						else
						printf("\n\nMessage: The double ended queue is not empty.");
						
						break;
								
			case 8:		if(!full())
						printf("\n\nMessage: The double ended queue is not full.");
						
						else
						printf("\n\nMessage: Overflow.");
						break;
								
			case 9:		printf("\n\nMessage: Displaying the whole double ended queue.");
						if(display())
						printf("\n\nMessage: Successfully displayed the whole double ended queue.");	
						break;	
								
			case 10:	printf("\n\nMessage: Re-displaying the menu.\n\n");
						output_restricted_menu();	
						break;		
											
			default: 	printf("\n\nError: Wrong choice.");	
						break;
		};
							
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	flag=1;
}

void no_restrictions()
{
	if(!flag && !(initialise_structure()))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return;
	}
	
	no_restrictions_menu();
	
	int i,ch,val;
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
						
	while(ch)
	{
		switch(ch)
		{
			case 1:		printf("\n\nEnter the value to be inserted from rear: ");
						scanf("%d",&val);
						if(insert_rear(val))
						printf("\n\nMessage: Successfully inserted the value from rear '%d' inside the double ended queue.",val);
						break;
								
			case 2:		printf("\n\nEnter the value to be inserted from front: ");
						scanf("%d",&val);
						if(insert_front(val))
						printf("\n\nMessage: Successfully inserted the value from front '%d' inside the double ended queue.",val);
						break;
								
			case 3:		if(delete_rear(&val))						
						printf("\n\nMessage: The item successfully deleted out of from rear of the double ended queue is: %d",val); 	
						break;
						
			case 4:		if(delete_front(&val))						
						printf("\n\nMessage: The item successfully deleted out of from front of the double ended queue is: %d",val); 	
						break;
								
			case 5:		if(front(&val))
						printf("\n\nMessage: The item pointed by the front in the double ended queue is: '%d'",val);
						break;
								
			case 6:		if(back(&val))
						printf("\n\nMessage: The item pointed by the rear in the double ended queue is: '%d'",val);
						break;
								
			case 7:		printf("\n\nMessage: The number of elements present in the double ended queue is: '%d'",size());	
						break;
											
			case 8:		if(!empty())
						{
							if(flag==2)
							printf("\n\nMessage: Underflow.");
							
							else
							printf("\n\nMessage: The double ended queue is empty.");
						}
						
						else
						printf("\n\nMessage: The double ended queue is not empty.");
						
						break;
								
			case 9:		if(!full())
						printf("\n\nMessage: The double ended queue is not full.");
						
						else
						printf("\n\nMessage: Overflow.");
						break;
								
			case 10:	printf("\n\nMessage: Displaying the whole double ended queue.");
						if(display())
						printf("\n\nMessage: Successfully displayed the whole double ended queue.");	
						break;	
								
			case 11:	printf("\n\nMessage: Re-displaying the menu.\n\n");
						no_restrictions_menu();	
						break;		
											
			default: 	printf("\n\nError: Wrong choice.");	
						break;
		};
							
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	flag=1;
}


int main()
{
	main_menu();
	
	int i,ch,val;
	
	printf("\n\n");
	
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	while(ch)
	{
		switch(ch)
		{
			case 1:		input_restricted();
						printf("\n\n");
						main_menu();
						break;
			
			case 2: 	output_restricted();
						printf("\n\n");
						main_menu();						
						break;
			
			case 3:		no_restrictions();
						printf("\n\n");
						main_menu();
						break;
						
			case 4:		printf("\n\nMessage: Re-displaying the menu.\n\n");
						main_menu();
						break;
			
			default:	printf("\n\nError: Wrong choice.");
						break;
		};
		
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	free_all();
	
	printf("\n\nMessage: Program successfully exited.");
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\n");
}
