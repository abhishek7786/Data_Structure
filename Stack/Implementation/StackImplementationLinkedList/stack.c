#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "functions.h"

int main()
{
  node *start=NULL;
  int data=0,choice=0;
  while(1)
    {
      printf("1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\n6.IsEmpty\n");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:
	  printf("Enter data\n");
	  scanf("%d",&data);
	  start=push(start,data);
	  break;
	case 2: 
	  data=pop(&start);
	  if(data == INT_MIN)
	    printf("Stack Underflow\n");
	  else 
	  printf("%d popped\n",data);
	  break;
	case 3:
	  data=peep(start);
	  if(data == INT_MIN)
	    printf("Stack Underflow\n");
	  else 
	    printf("Data is %d\n",data);
	  break;
	case 4:
	  display(start);
	  break;
	case 5:
	  exit(0);
	  break;
	case 6: 
	  if(peep(start)==INT_MIN)
	    printf("Stack Underflow\n");
	  break;
	default:printf("wrong choice\n");
	}
    }
}
