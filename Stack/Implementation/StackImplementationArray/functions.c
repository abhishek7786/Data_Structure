#include<stdio.h>
#define wathcint(x) printf("%s=%d\n",#x,x);
int push(int *stack,int size,int *top,int data)
{
  //check for overflow
  if(size == *top)
    return -1;
  wathcint(*top);
  stack[(*top)++]=data;
  return 1;
}
int pop(int *stack,int *top)
{
  //check of underflow
  if(*top <= 0)
    return -1;
    wathcint(*top);
  return stack[--(*top)];
}
int peek(int *stack ,int top)
{
  //check for underflow
  if(top <0)
    return -1;
  return stack[top];
}
int isEmpty(int top)
{
  if(top < 0)
    return -1;
 return 1;
}
int display(int *stack,int top)
{
  if(top<=0)
    return -1;
  while(top>0)
    printf("%d ",stack[--top]);
  printf("\n");
  return 1;
}
