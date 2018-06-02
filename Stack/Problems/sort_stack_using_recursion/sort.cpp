#include<bits/stdc++.h>

#define watchint(me) printf("%s=%d\n",#me,me);
#define si(a) scanf("%d",&a);
#define sl(a) scanf("%ld",&a);
#define sll(a) scanf("%lld",&a);

typedef long long int ll;
using namespace std;

stack<int>s;



void insert(int x)
{
  if(s.empty())
    s.push(x);
  else
    {
      if(x<=s.top())
	{
	  s.push(x);
	}
      else
	{
	  int hold=s.top();
	  s.pop();
	  insert(x);
	  s.push(hold);
	}
    }
}

void sort()
{
  if(s.empty())
    return ;
  int to=s.top();
  s.pop();
  sort();
  insert(to);
}
  

int main(int argc, char *argv[])
{
  // int i=0;
  s.push(7);s.push(8);s.push(1);s.push(3);s.push(2);

  sort();
  while(!s.empty())
    cout<<s.top(),s.pop();
  cout<<endl;
  return 0;
}

