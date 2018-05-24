#include<stdio.h>

int stack[100];
int top=-1;

void infixtopostfix(char *,char *);
void push(char);
char pop();
int priority(char );
int  main(int argc, char *argv[])
{
  char infix[100];
  char postfix[100];
  printf("enter the infix");
  scanf("%s",infix);
  printf("\ninfix\n");
  printf("%s\n",infix);
  printf("postfix\n");
  infixtopostfix(infix,postfix);
  return 0;
}

void push(char ch)
{
  stack[++top]=ch;
}

char  pop()
{
  if(top>=0)
  return stack[top--];
}

void infixtopostfix(char *infix,char *postfix)
{
  //  printf("RE\n");
  int px=0;
  int ix=0;
  char temp;
  while(infix[ix])
    {
      if(infix[ix]=='(')
	push(infix[ix]);
      else if(infix[ix]>='0' && infix[ix]<='9')
	postfix[px++]=infix[ix++];
      else if(infix[ix]=='+'||infix[ix]=='-'||infix[ix]=='*'||infix[ix]=='/')
	{
	while(top>-1&&priority(infix[ix])>=priority(stack[top]))
	     postfix[px++]=temp;
	}
      ix++;
    }

  postfix[px]='\0';
   printf("%s",postfix);
}
int priority(char ch)
{
  if(ch=='(')
    return 0;
  if(ch=='+')
    return 1;
  if(ch=='-')
    return 1;
  if(ch=='*')
    return 2;
  if(ch=='/')
    return 2;
  if(ch=='^')
    return 3;
  if(ch=='%')
    return 1;
  return 0;
}
