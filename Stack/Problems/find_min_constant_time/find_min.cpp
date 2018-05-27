/*

https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
here trick is to use encoding and decoding...
when we are pushing the element into the stack just keem track of minimum...

if current element to be inserted is less than current minimum...
then the value which will be inserted into the stack is stack_current= 2*x-prev_min;
now current minimum will be = x;

suppose elemets to be inserted are:-

   element are===   5 4 3 2 1
   current_min===   5 4 3 2 1

   how to push??
   stack holds===   5 3 3 1 1  /// 2*(new_element)-min(if new_element is less than current_min)
   
   how to pop??
   if top_elemen is >= current_min then simply pop
   else 
   pop top_element and calulate prev_min= 2*current_min-top_element;
   for original element entered is= (prev_min+top_element)/2

 */

#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;


//we can even use linked list..
//here array is used...

class min_stack
{
private:
  int *ar;
  int top;
  int size;
  int min_element;
public:
  min_stack(int n1);
  void push(int element);
  int pop();
  void print();
  int min();
  bool isempty();
};
bool min_stack::isempty()
{
  return top==-1;
}
min_stack::min_stack(int n1)
{
  size=n1;
  ar=new int[size];
  top=-1;
}
void min_stack::print()
{
  cout<<"Stack is ";
  for(int i=top;i>=0;i--)
    cout<<ar[i]<<" ";
  cout<<endl;
}
void min_stack::push(int element)
{
  //overflow
  if(top==size-1)
    return ;
  //first element
  if(top==-1)
    {
      ar[++top]=element;
      min_element=element;
    }
  else if(element>=min_element)
    ar[++top]=element;
  else if(element<min_element)
    {
      //encode value to store in stack-> encoded_value=2*element-min_element
      int to_push=2*element-min_element;
      ar[++top]=to_push;
      
      //change the min_element as element is minimum
      min_element=element;
    }
}
int min_stack::pop()
{
  //underflow
  if(top<0)
    {
      throw out_of_range("underflow\n");
    }
  int actual=0;
  if(ar[top]>=min_element)
    {
      actual=ar[top];
      top--;
      cout<<"acutal element was "<< actual<<endl;;
    }
  else if(ar[top]<min_element)
    {
      //decode the encoded value;
      //to decode we will need the previous min value
      //because prev_min was used to encode(think it as a key to encode)
      int prev_min=2*min_element-ar[top];
      actual=(ar[top]+prev_min)/2;
      min_element=prev_min;
      top--;
      cout<<"acutal element was "<< actual<<endl;;
    }
  return actual;
}
int main(int argc, char *argv[])
{
  int size=6;
  min_stack obj(size);

  //test data
  obj.push(3);    obj.push(5);    obj.push(2);    obj.push(1);    obj.push(1);    obj.push(-1);
  obj.print();

  //two pop operations
  obj.pop();
  obj.pop();
  
  obj.print();
  
  return 0;
}

