#include<bits/stdc++.h>

#define watchint(me) printf("%s=%d\n",#me,me);
#define si(a) scanf("%d",&a);
#define sl(a) scanf("%ld",&a);
#define sll(a) scanf("%lld",&a);

typedef long long int ll;
using namespace std;

//playing around template
//structure nof linked list
template<typename t>
struct node
{
  t data;
  struct node  *next;
  struct node *prev;
};
//we can't use typedef with template its somewhere statically incorrect...

//function to create node
template<typename t>
node<t> *create_node(t data)
{
  // node<t> temp;
  node<t> *temp;
  temp=(node<t>*)malloc(sizeof(node<t>));
  temp->data=data;
  temp->next=NULL;
  temp->prev=NULL;
  return temp;
}

//class
template<typename t>
class stack_middle
{
private:
  node<t> *head;
  node<t> *middle;
  node<t> *end;
  int size;
public:
  stack_middle();
  void push(t);
  void pop();
  t top();
  t findmiddle();
  bool is_empty();
  void deletemiddle();
  void print();
};


//constructor to initialize head ptr
template<typename t>
stack_middle<t>::stack_middle()
{
  head=NULL;
  middle=NULL;
  end=NULL;
  size=0;
}


template<typename t>
void stack_middle<t>::push(t data)
{
  //treat as insert in front
  if(head==NULL)
    {
      head=create_node(data);
      end=head;
      middle=head;
      size++;
      return ;
    }
  node<t> *temp=create_node(data);
  temp->prev=NULL;
  temp->next=head;
  head->prev=temp;
  head=temp;
  size++;
  //cout<<"push not complete";
  if(size>2 && (size&1))
       middle=middle->prev;
  //cout<<"push coomplete";
}

template<typename t>
void stack_middle<t>::pop()
{
  //think it as delete at beg
  if(head==NULL)
    return ;
  node<t> *temp=head;
  head=head->next;
  free(temp);
  size--;
  if((size&1))//if size is even
       middle=middle->next;
}
  
template<typename t>
t stack_middle<t>::top()
{
  if(head==NULL)
    return 1;//this will be default value
  return head->data;
}

template<typename t>
void stack_middle<t>::print()
{
  node<t> *temp=head;
  while(temp)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  cout<<endl;
}


template<typename t>
bool stack_middle<t>::is_empty()
{
  if(head==NULL)
    return 1;
  else return 0;
}

template<typename t>
t stack_middle<t>::findmiddle()
{

  if(head==NULL)
    return -1;//treat it as default value of t datatype
  return middle->data;
}
int main(int argc, char *argv[])
{
  stack_middle<int> obj;
  int i=5;
  while(i--)
    obj.push(i);
  obj.print();
  obj.pop();
  obj.print();
  
  cout<<obj.findmiddle()<<endl;
  obj.pop();
  obj.print();
    cout<<obj.findmiddle()<<endl;
  return 0;
}

