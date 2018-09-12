/*
so this problem is same as
"maximum subarray sum"
in this question you are required to answer q qeuries 
and each query will demand you to tell the maximum subarray sum 
between l and r range.[l,r]

The idea here is,
any segment suppose [a,b] can be splitted into [a,c] and [c+1,b]
here if b = a+1 (e.g.[4,5]) then c = a and c+1 = b (leaf node in segment tree).

now maximum subarray sum  in [a,b] can be "in" either [a,c] or [c+1,d] or 
by combining ending part in [a,c] and starting part in [c+1,d] ...

so analyse carefully if maxsubsum overlaps in [a,c] and [c+1,d].
so these will be represented by nodes in segment tree.

Then you need to know the maxsubsum in [a,c] and maxsubsum in [c+1,d] 
and  "prefix_max" and "suffix_max" of both [a,c] and [c+1,d]
for calculating overlapping sum of these segments 
suffix_max of [a,c] and prefix_max = [c+1,d] will give you the overlapping maximum sum.it need not be the answer.

https://discuss.codechef.com/questions/96902/spoj-gss1-problem 
 */
 
#include<bits/stdc++.h>
using namespace std;

#define watchme(x) printf("%s = %d\n",#x,x);
#define size 50010

 struct Node
{
  int value;
  int all;
  int prefix_max;
  int suffix_max;
};
typedef struct Node node;

int ar[size];
node seg[size<<2];

//merge function
node merge(node a,node b)
{
  if(a.value == INT_MIN)return b;
  if(b.value == INT_MIN)return a;
  node temp;
  temp.all = a.all + b.all;
  temp.prefix_max = max(a.prefix_max ,a.all + b.prefix_max);
  temp.suffix_max = max(b.suffix_max ,a.suffix_max + b.all);
  temp.value = (max((a.all + b.all),(a.suffix_max + b.prefix_max)));
  temp.value = max(temp.value,max(a.value,b.value));
  return temp;
}

node query(int start,int end,int rstart,int rend,int index)
{
  node temp;temp.value=INT_MIN;
  if(rstart > end || rend <start)
    return temp;
  if(rstart <= start && rend >= end)
    return seg[index];
  int mid = (start + end)/2;
 node seg1= query(start,mid,rstart,rend,index<<1);
 node seg2= query(mid+1,end,rstart,rend,index<<1|1);
 return merge(seg1,seg2);
}
			  
void build(int start,int end ,int index)
{
  if(start == end)
    {
      seg[index].value = ar[start];
      seg[index].prefix_max = ar[start];
      seg[index].suffix_max = ar[end];
      seg[index].all = seg[index].value;
      return ;
    }
  int mid = (start + end)/2;
  build(start,mid,index<<1);
  build(mid+1,end,index<<1|1);
  seg[index] = merge(seg[index<<1],seg[index<<1|1]);
  return ;
}

void update(int start,int end,int to_change,int value,int index)
{
  if( to_change < start || to_change > end )
    return;
  if(start == end)
    {
      seg[index].value = value;
      seg[index].prefix_max = value;
      seg[index].suffix_max = value;
      seg[index].all = value;
      return ;
    }
  int mid = (start+end)/2;
  update(start,mid,to_change,value,index<<1);
  update(mid+1,end,to_change,value,index<<1|1);
  seg[index] = merge(seg[index<<1],seg[index<<1|1]);
  return ;
}

int main()
{
  int n,i=1;
  cin>>n;
  while(i<=n)cin>>ar[i++];
  int start =1,end = n,index =1;
  build(start,end,index);
  int q,type,rstart,rend;
  cin>>q;

  //i=1;while(i < 4*n)cout<<seg[i++].value<<endl;
  
  node hold;
  while(q--)
    {
      cin>>type>>rstart>>rend;
      if(type)
	{
	  hold = query(start,end,rstart,rend,index);
	  cout<<hold.value<<endl;
	}
      else
	update(start,end,rstart,rend,index);
    }
  return 0;
}
