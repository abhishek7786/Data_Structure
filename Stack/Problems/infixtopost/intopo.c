#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define watchi(me) printf("%s=%d\n",#me,me);
#define watchstr(me) printf("%s \n",me);

struct operator
{
  int precedence;
  char op;
}operator;

typedef struct operator oper;

oper oparray[5];

void initialize()
{
  oparray[0].op='+';oparray[0].precedence=1;
  oparray[1].op='-';oparray[1].precedence=1;
  oparray[2].op='*';oparray[2].precedence=2;
  oparray[3].op='/';oparray[0].precedence=2;
}

int check(char first,char second)
{


  int firstp,secondp;
  int i=0;
  while(i<4)
    {
      if(oparray[i].op==first)
	firstp=oparray[i].precedence;
      if(oparray[i].op==second)
	secondp=oparray[i].precedence;
      i++;
    }
  return firstp-secondp;
}

int main()
{
  initialize();
  char infix[100];
  char ch;
  int i=0,res=0;
  //  watchstr("start point");
  while((ch=getchar())!='\n')
    infix[i++]=ch;
  infix[i]='\0';
   //  watchstr(infix);
  char stack[100];int top=-1;
  char Postfix[100];
  int j=0; i=0;
  while(infix[i]!='\0')
    {
      if(infix[i]>=97 && infix[i]<124)
	{
	  //  watchstr("reading variables");
	  Postfix[j++]=infix[i];
	}
       if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
	{
	  // watchstr(infix[i]);
	  // printf("%c\n",infix[i]);
	  if(top== -1)
	    stack[++top]=infix[i];
	  else
	    {
	      res=(check(infix[i],stack[top]));
	      if(res>=0)
		stack[++top]=infix[i];
	       else
		 Postfix[j++]=infix[i];
	    }//else
	}// if
      i++;
    }//while
  Postfix[j]='\0';
  printf("Postfix= %s",Postfix);
      return 0;
}//main
