// Link - http://www.spoj.com/problems/LITE/
// Simple Implementation of a Segment Tree

#include <stdio.h>
typedef long long int lld;
lld arr[100005];
lld tree[400005];
lld lazy[400005],l,r;
 
lld query(lld node,lld start,lld end)
{
	if(start>end||start>r||end<l)
		return 0;
	
	if(lazy[node]!=0)
	{
		if(lazy[node]&1)
			tree[node] = end-start+1-tree[node];
		
		if(start!=end)
		{
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start>=l&&end<=r)
		return tree[node];
	
	lld mid = (start+end)/2;
	lld p1 = query(2*node+1,start,mid);
	lld p2 = query(2*node+2,mid+1,end);
	return p1+p2;
}
 
void update(lld node,lld start,lld end)
{
	if(lazy[node])
	{
		if(lazy[node]&1)
			tree[node] = end-start+1-tree[node];
		
		if(start!=end)
		{
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start>end||start>r||end<l)
		return;
	
	if(start>=l&&end<=r)
	{
		tree[node] = end-start+1-tree[node];
		if(start!=end)
		{
			lazy[2*node+1]++;
			lazy[2*node+2]++;
		}
		return;
	}
	
	lld mid = (start+end)/2;
	update(2*node+1,start,mid);
	update(2*node+2,mid+1,end);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}
 
int main()
{
	lld n,m,ch;
	scanf("%lld%lld",&n,&m);
	while(m--)
	{
		scanf("%lld%lld%lld",&ch,&l,&r);
		l--;
		r--;
		if(ch)
			printf("%lld\n",query(0,0,n-1));
		else
			update(0,0,n-1);
	}
	return 0;
} 