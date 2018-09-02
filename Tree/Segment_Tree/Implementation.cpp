#include<bits/stdc++.h>
using namespace std;

//macro for debugging
#define watchme(x) printf("%s = %d",#x,x);

//here  3rd parameter node signifies that at any level we are evaluating
//the value of this node in segment tree...

void segment(vector<int>&ar,vector<int>&seg,int node,int i,int j)
{
  if(i==j)
    {
      seg[node]=ar[i];
      return;
    }
  int mid=(i+j)/2;
  
  segment(ar,seg,node*2+1,i,mid);
  segment(ar,seg,node*2+2,mid+1,j);
  
  seg[node] = min(seg[2*node+1],seg[node*2+2]);
  return;
}

//helper function to update the value at "postion" index in actual array.
void update(vector<int>&ar,vector<int>&seg,int node ,int start,int end,int pos,int value)
{
  //for debugging
  /*
  watchme(node);
  cout<<" ";
  watchme(sennng[node]);
  cout<<endl;
  */
  if((start == end)&& (start == pos))
    {
      seg[node]=value;
      return;
    }

  //as we changes the node's value
  // we need to update the original node
  int org_node = node;
  int mid = (start+end)/2;

  if(pos <= mid)
    node = node*2+1,end=mid;
  else
    node = node*2+2,start=mid+1;
    
  update(ar,seg,node,start,end,pos,value);
  seg[org_node] = min(seg[2*org_node+1],seg[2*org_node+2]);
  
}

int query(vector<int>&seg,int l,int r,int start,int end,int node)
{
  //   watchme(start);cout<<" ";watchme(end);cout<<endl;
   //   watchme(l);cout<<" ";watchme(r);cout<<endl;

  //required segment covers current node's segment.
  if( l <= start && r >= end )
    {
      return seg[node];
    }

  //required segment does not covers
  if(r < start || end < l)
    return INT_MAX;
  int mid = (start+end)/2;
  
  //partially covers
  return min(query(seg,l,r,start,mid,node*2+1),query(seg,l,r,mid+1,end,node*2+2));
}


//helper function to print the segment tree
void print_tree(vector<int>&seg,int n)
{
  cout<<"printing start"<<endl;
  int i=0;

  //there can be at max 2*n nodes in the full binary tree
  n=2*n;
  while(i<n)
    {
      if(seg[i]!=INT_MAX)
	cout<<i<<" "<<seg[i]<<" "<<endl;
      i++;
    }
  cout<<"printing ends\n";
}

//implementation of segment tree.
int main()
{
  int n,q;
  cin>>n>>q;
  vector<int>ar(n);
  int i=0;

  //input
  while(i<n)cin>>ar[i++];
  vector<int>seg(4*n+50,INT_MAX);
  
  //building tree
  segment(ar,seg,0,0,n-1);

  char ch;int l,r;
  while(q--)
    {
      cin>>ch>>l>>r;
      l--,r--;
      if(ch == 'u')
	update(ar,seg,0,0,n-1,l,++r);
      else 
	cout<<query(seg,l,r,0,n-1,0)<<endl;
    }
}

