#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "functions.h"
node *createnode(int data)
{
  node *temp=(node *)malloc(sizeof(node));
  temp->data=data;
  temp->link=NULL;
  return temp;
}
node *push(node *start,int data)
{
  if(!start)
    {
      start=createnode(data);
      return start;
    }
  node *temp=createnode(data);
  temp->link=start;
  start=temp;
  return start;
}
int pop(node **start)
{
  if(*start==NULL)
    return INT_MIN;
  int data=(*start)->data;
  node *temp=*start;
  (*start)=(*start)->link;
  free(temp);
  return data;
}
int peep(node *start)
{
  if(start==NULL)
    return INT_MIN;
  return start->data;
}
void display(node *start)
{
  if(start==NULL)
    return ;
  node *temp=start;
  while(temp)
    {
    printf("%d ",temp->data);
    temp=temp->link;
    }
  printf("\n");
  return;
}
