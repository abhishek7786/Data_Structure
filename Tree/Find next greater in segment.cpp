/* 
    
Problem -> Given x find the smallest number greater than or equal to x in given segment.
    
what I learned?
2-Dimensional DataStructure
Segment tree as 2-D Data Structure.
In this problem each node in segment tree has one more data structure
here we use vector. i.e. array...
    
*/  
    
#include<bits/stdc++.h>
using namespace std;
#define watchint(x) printf("%s = %d\n",#x,x);
    
int rows = 200,cols = 50,val = 0;
vector< vector<int> > seg(100, vector<int> (0, val)); 
vector<int>ar(50,0);
    
void build(int start,int end,int node)
{   
  if(start>end)return;
  if(start == end)
    {
      seg[node] = vector<int>(1,ar[start]);
      return ;
    }
  int mid = (start+end)/2;
  build(start,mid,node<<1);
  build(mid+1,end,node<<1|1);
  merge(seg[node<<1].begin(),seg[node<<1].end(),seg[node<<1|1].begin(),seg[node<<1|1].end(),back_inserter(seg[node]));
  return ;
}   
    
int query(int start,int end,int rstart,int rend,int value,int index)
{   
  if(index < start || index > end)
    return INT_MAX;
  if(start == end)
    {
      if(value ==  ar[start])
      return ar[start];
      else return INT_MAX;
    }

  if(rstart<=start && rend>=end)
    {
      auto it = lower_bound(seg[index].begin(),seg[index].end(),value);
      /* 
      watchint(start);watchint(end);
      if(it == seg[index].end())
    	//watchint(INT_MAX);
	cout<<INT_MAX<<endl;
      else cout<<*it<<endl;// watchint(*it);
      */   
      if(it == seg[index].end())
    	return INT_MAX;
      else return *it;
    }
    
  int mid=(start+end)/2;
      int q1 = query(start,mid,rstart,rend,value,index<<1);
      int q2 = query(mid+1,end,rstart,rend,value,index<<1|1);
  return min(q1,q2);
}   
    
    
int main()
{   
  int n,i = 1;cin>>n;
  while(i <= n)cin>>ar[i++];
  int start = 1,end = n,node = 1;
  build(start,end,node);

  //printing the segment tree
  /*
  for(i=1;i<=n*2;i++)
    {
      for(auto it:seg[i])
    	cout<<it;
      cout<<endl;
    }
   */ 
  int q,rstart,rend,value,temp;//,index=1;
  cin>>q;
    
  while(q--)
    {
      cin>>rstart>>rend>>value;
      temp=query(start,end,rstart,rend,value,node);
      if(temp == INT_MAX)
	cout<<"-1";
      else cout<<temp;
      cout<<endl;
    }
  return 0;
}   
    
    
