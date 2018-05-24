#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
  int size,choice,ifsuccess,top=0,data;//ifsuccess flag for checking the value returned by the various functions
  printf("Enter the initial size of stak\n");
  scanf("%d",&size);
  int stack[size];
  while(1)
    {
      printf("1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.Display\n6.Exit\n");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:
	  printf("Enter data to push\n");
	  scanf("%d",&data);
	  if(push(stack,size,&top,data)<0)
	    printf("Stack Overflow\n");
	  break;
	case 2:
	  ifsuccess=pop(stack,&top);
	  if(ifsuccess<0)
	    printf("Stack Underflow\n");
	  else
	    printf("%d popped\n",ifsuccess);
	  break;
	case 3:
	  ifsuccess=peek(stack,top);
	  if(ifsuccess<0)
	    printf("Stack Underflow\n");
	  else
	    printf("Top is %d\n",ifsuccess);
	  break;
	case 4:
	if(isEmpty(top)<0)
	  printf("Sprintftack is empty\n");
	break;
	case 5:
	  display(stack,top);
	  break;
	case 6:exit(0);
	  break;
	default:
	  printf("wrong choice enter again\n");
	}
    }
}
