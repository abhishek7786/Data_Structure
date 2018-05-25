/*

Operators supported are:- ^ * / + -
Infix can be of the form  -> (a+(b^2)-c)*(c/2)
Then post fix will be -> ab2^+c-c2

*/

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

//returns precedence of operators
int precedence(char op)
{
  switch(op)
    {
    case '^':return 3;
    case '*':return 2;
    case '/':return 2;
    case '+':return 1;
    case '-':return 1;
    }
  return 0;
}


class intop
{
private:
  std::string infix;
  std::string postfix;
public:
  intop(std::string str);//constructor to check for valid string
  void convert();//if valid then convert infix to postfix
  void evaluate();
  void print();//
};

intop::intop(std::string str)
{
  //cases of invalid string
  //1st case->> 2++3   i.e two consecutive operator
  //2nd case->> (/3)   i.e operator without preceding operand
  //3rd case->> (2/3)) i.e more closing parenthesis
  //4th case->> ((2+3)+(2+3+(2*4) i.e less closing parenthesis
  bool flag=0;
  int paren=0;
  for(auto it:str)
    {
      // std::cout<<it;
      if(isalnum(it))
	flag=1;
      else if(precedence(it)>=1 && precedence(it)<=3)
	{
	  if(flag==1)
	    flag=0;
	  else
	    throw invalid_argument("Invalid infix: consecutive operator or operator without two operand\n");
	}
      else if(it=='(')
	paren++;
      else if(it==')')
	paren --;
    }
  if(paren!=0)
    throw invalid_argument("Invalid infix: Imbalanced parenthesis\n");
  
  //if no exception occurs then proceed further
  infix+='(';
  infix+=str;
  infix+=')';
}

void intop::convert()
{
  int digit=0;
  //stack to hold operator
  std::stack<char>op;

  for(auto &it:infix)
    {
      if(it=='(')
	{
	op.push(it);
	continue;
	}


      if(it == ')')
	{
	  postfix+=' ';
	  while(op.top()!='(')
	    {
	      postfix+=op.top();
	      op.pop();
	    }
	  if(op.top()== '(')
	    op.pop();
	}
      
      //if digit or variable then append to postfix
      else  if(isdigit(it))
	{
	  //if more than one digit in number it will have one space
	    postfix+=it;
	    digit++;
	    // cout<<it<<" ";
	}
      
      //if it is operator
      else
	{
	  // if(digit>1)
	  postfix+=' ';
	  digit=0;
	  //if stack is empty or there is '('...insert operator...
	  if(op.empty() || op.top()=='(')
	    op.push(it);
	  
	  //some operator present already
	  else
	    {
	      //check for precedence
	      if(precedence(it) >= precedence(op.top()))//if top element has low precendence then push
		  op.push(it);

	      //if top has higher precedence then remove it...
	      else
		{

		  postfix+=op.top();
		  postfix+=' '; 
		  op.pop();
		  op.push(it);
		}//end of higher precendence else
	    }//end of else some operator present already 
	}//end of main else ....i.e when it is a operator
    }//end of iterator loop
}//end of convert

float eval(char op,float op1,float op2)
{
  switch(op)
    {
    case '+':return op1+op2;
    case '-':return op1-op2;
    case '*':return op1*op2;
    case '/':
      {
	// if(op2< 0.00001  && op2>-0.00001)
	if(op2==0)
	throw std::overflow_error("Divide by zero\b");
      return(op1/op2);
      }
    case '^':return (pow(op1,op2));
    }
  return -1;
}

//function to evaluate
void  intop::evaluate()
{
  stack<float>hold;
  float  op1=0,op2=0;
  float temp=0;
  for(auto it:postfix)
    {
      if(it==' ')
	{
	  if(temp > 0)
	  hold.push(temp);
	  temp=0;
	}
      else if(isdigit(it))
	{
	  //if number is more than one digit
	  temp=temp*10+it-'0';
	}
      else
	{
	  op1=hold.top();
	  hold.pop();
	  op2=hold.top();
	  hold.pop();
	  hold.push(eval(it,op2,op1));
	}
    }
  cout<<hold.top()<<endl;

  //just to empty the stack
  hold.pop();
}

void intop::print()
{
  cout<<"Infix-->> "<<infix<<endl;
  cout<<"Postfix-->> "<<postfix<<endl;
}
  

int main(int argc, char *argv[])
{
  string infix="(1+2)*(2*3+4)*(200/0)";
  
  //default constructor for cheking valid infix expression
  intop obj(infix);

  //converting to postfix
  obj.convert();

  //printing the infix and postfix
  obj.print();

  //evaluating the postfix expression
  obj.evaluate();
  return 0;
}


