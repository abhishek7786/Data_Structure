//how to use lazy propogation
/*
how to update the segment.
1-> Whenever a recursive call will be called we will see whether it needs updation 
2-> After updating whether it lies in range completely then return 
3-> if lies partially then calculate for both the children
 
*/
#include<bits/stdc++.h>
using namespace std;
int size = 100005;
#define ll long long int
vector<ll >seg(size*4);
vector<ll >lazy(size*4);

void update(ll start,ll end,ll qstart,ll qend,ll value,ll node)
{

  if(lazy[node])
    {
      seg[node] += lazy[node]*(end - start + 1);
      //if not leaf node propogate further
      if(start !=end)
	{
	  lazy[node<<1] += lazy[node];
	  lazy[node<<1|1] += lazy[node];
	}
      lazy[node] = 0;
    }

  if(qstart > end || qend < start)
    return;

  if(qstart <= start && qend >= end)
    {
      seg[node] += value*(end - start+ 1);
      if(start != end)
	{
	  lazy[node<<1] += value;
	  lazy[node<<1|1] += value;
	}
      return ;
    }
  ll mid= (start+end)/2;
  update(start,mid,qstart,qend,value,node<<1);
  update(mid+1,end,qstart,qend,value,node<<1|1);
  seg[node] = seg[node<<1] + seg[node<<1|1];
}


ll query(ll start,ll end,ll qstart,ll qend,ll node)
{
  //out of range
  if(qend < start || qstart > end)
    return 0;

      if(lazy[node])
	{
	  seg[node] += lazy[node]*(end - start +1);
	  if(start != end)
	    {
	      lazy[node<<1] += lazy[node];
	      lazy[node<<1|1] += lazy[node];
	    }
	  lazy[node] = 0;
	}
  //lies completely
  if(qstart <= start && qend >= end)
    {	
      return seg[node];
    }

  //lies paritally
  ll mid = (start+end)/2;
  return (query(start,mid,qstart,qend,node<<1) + query(mid+1,end,qstart,qend,node<<1|1));
}

int  main()
{
  ll t;cin>>t;
  while(t--)
    {
      ll n,q;
      cin>>n>>q;
      ll type,start=1,end=n,node=1;
      ll value;
      ll qstart,qend;

      memset(&seg[0],0,seg.size()*sizeof (seg[0]));
      memset(&lazy[0],0,lazy.size()*sizeof(lazy[0]));

      while(q--)
	{
	  cin>>type>>qstart>>qend;
	  if(!type)
	    {
	      cin>>value;
	      update(start,end,qstart,qend,value,node);
	    }
	  else cout<<query(start,end,qstart,qend,node)<<endl;;
	  //ll i=0;         
	 // for(;i<2*n;i++)cout<<i<<": "<<seg[i]<<"  "<<lazy[i]<<endl;
	}
    }
}
