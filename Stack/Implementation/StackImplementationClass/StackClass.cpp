/*
Implementation of stack using class and template 
For reading about template please visit 1st link---very neat and concise explanation of templates...
For printing struct data members using template its difficult if possible....I don't know any way to print UDT and primitive data type in one 
function using the template....

https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part
https://stackoverflow.com/questions/48767748/print-any-struct-in-template-function
y
 */

#include<iostream>
#include<climits>

//I should not use namespace std...but this is small code so please bear this....
using namespace std;

//class for stack
template<typename T>
class stack
{
private:
  int size;
  int topvariable;
  T *ptr;//pointer to "typename" type...e-g- int * ptr...
public:
  stack(int s);//first constructor for initializing the stack of size "s"
  stack(T arr[],int s);//second constructor for filling up the values through array
  ~stack();//destructor as there will be dynamic memory allocation to avoid memory leak
  
  //bunch of regular functions associated with stack
  void print();
  void push(T element);//will throw exception for overflow
  T pop();//will throw exception fo underflow
  T peek(int position);//exception of underflow if position does not exist.
  T top();//top element or exception underflow...
};

//definition of first constructor
template<typename T>
stack<T>::stack(int s)
{
  ptr=new T[s];
  size=s;
  topvariable=-1;//arrays are 0-indexed..so before pushing we will increment it..
}

//second constructor ...for array
template<typename T>
stack<T>::stack(T arr[],int s)
{
  ptr=new T[s];
  size=s;
   for(int i=0;i<size;i++)
    ptr[i]=arr[i];
   topvariable=size-1;//setting the topvariable 
}

//output the element of stack
template<typename T>
void stack<T>::print()
{
  for(int i=0;i<=topvariable;i++)
	cout<<*(ptr+i)<<" ";
  cout<<endl;
}


template<typename T>
void stack<T>::push(T element)
{
  if(topvariable==size-1)
        throw out_of_range("stack<>::push(): Stack Overflow");
  else
    topvariable++;
  *(ptr+topvariable)=element;
}


//pop() return the element at top or underflow
template <typename T>
T stack<T>::pop()
{
  if(topvariable<0)
    {
      throw out_of_range("Stack<>::pop():  Stack Underflow\n");
    }
  return *(ptr+(topvariable--));
}
 
//top() return the element at top if underflow return the INT_MIN
template <typename T>
T stack<T>::top()
{
  if(topvariable<=0)
    throw out_of_range("Stack<>::top() Stack Underflow\n");
  return *(ptr+topvariable);
}
  
//peek-> Element at given position "from top"
template<typename T>
T stack<T>::peek(int position)
{
  position=topvariable-position+1;
  if(position>=0)
    return *(ptr+position);
  else
    throw out_of_range("Stack<>::peek() Position doesnot exist\n");
}

//destructor to avoid memory leak
template<typename T>
stack<T>::~stack()
{
  delete []ptr;
}


//struct datatype for inserting into the element
typedef struct 
{
  int day;
  int month;
  int year;
  string to_string()
  {
    //look for the apt use of namespace std here ....as struct also has a member function to_string... 
    return std::to_string(day)+":"+std::to_string(month)+":"+std::to_string(year);
  }
}date;


//main function, all began here -;
int main(int argc, char *argv[])
{
  //initializing by using first constructor
  int size=5;
  stack<int>s_int(size);
  int i=5;
  
  while(i)//manually pushing the elements into the stack
  s_int.push(i--);
  
  cout<<"stack contains:\n";;
  s_int.print();

  //popping the element
  
  cout<<"popped :"<< s_int.pop();
  cout<<endl;
  cout<<"popped :"<<s_int.pop();
  cout<<endl;
  
  //after popping two element   
  s_int.print();
  
  //destructor
  // s_int.~stack();//calling destructor explicitily
  /*
    why destructor should not be invoked explicitly on local objects..
    https://www.geeksforgeeks.org/possible-call-constructor-destructor-explicitly/
   */

  //working with char input and array
  //using the second costructor of stack
  size=9;
  char str[]="boomchick";
  stack<char>s_char(str,size);

  //elements in stack
  cout<<"stack contains:\n";;
  s_char.print();
  
  i=5;//popping the 5 characters
  while(i--)
    s_char.pop();//5 charaters of "boomchick" will be popped
  
  //remaining element in stack
  s_char.print();//after 5 characters popped

  // UDT->user defined data type -->> date...definition of date is above main
  //populating the array with some data
  date array_of_date[5];
  i=0;
  int day=10;
  int month=1;
  int year=1995;
  while(i<5)
    {
      array_of_date[i].day=day++;
      array_of_date[i].month=month++;
      array_of_date[i].year=year++;
      i++;
    }
  //creation and population of array ends here
  
  
  //stack of date is being created here
  size=5;
  stack<date>s_date(array_of_date,size);

  date temp;//temporary variable to hold popped element
  i=3;//three element will be popped

  //popping the three element
  while(i)
    {
      temp=s_date.pop();
      cout<<temp.to_string();
      cout<<endl;
      i--;
    }
  //we can't use the print function of the stack class as c++ lacks something called the reflection "yet"
  //two options either write new function inside stack class for this user defined type..
  //or write a function inside the struct class..
  //1st option may no be feasible....as we may not have the permission to change the "stack" class..
  //2nd option seems feasible here...but it is slow as we have to conert the other data type to string...
  
  return 0;
}

