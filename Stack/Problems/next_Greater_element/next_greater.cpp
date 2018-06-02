#include<bits/stdc++.h>

#define watchint(me) printf("%s=%d\n",#me,me);
#define si(a) scanf("%d",&a);
#define sl(a) scanf("%ld",&a);
#define sll(a) scanf("%lld",&a);

typedef long long int ll;
using namespace std;

vector<int> next_greater(vector<int>&vec,int size)
{
  stack<int>s;
  s.push(0);
  int in_stack=0;
  vector<int>res(size,-1);
  for(int i=1;i<size;i++)
    {
      //if next element is smaller then push in stack
      if(!s.empty() && vec[i]<=vec[s.top()])
	s.push(i);

      //if greater than top element
      else
	{
	  while(!s.empty() && vec[s.top()]<vec[i])
	    {
	      in_stack=s.top();
	      s.pop();        
	      res[in_stack]=i;
	    }
	  s.push(i);
	}
    }
  return res;
}


int main(int argc, char *argv[])
{
  int n;
  cin>>n;
  int i=0;
  vector<int>ar(n);
  while(i<n)
    cin>>ar[i++];
  vector<int>queries=next_greater(ar,n);
  int q;
  cin>>q;
  int index;
  while(q--)
    {
      cin>>index;
      cout<<queries[index]<<" ";
    }
  cout<<endl;
  return 0;
}

