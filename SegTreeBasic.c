#include <stdio.h>

int tree[100005];
int arr[100005];

int build(int node,int start,int end)
{
	if(start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start+end)/2;
		build(2*node+1,start,mid);
		build(2*node+2,mid+1,end);
		tree[node] = tree[2*node+1]+tree[2*node+2];
	}
}

int query(int node,int start,int end,int l,int r)
{
	if(r<start || l>end)
		return 0;
	if(l<=start && r>=end)
		return tree[node];
	int mid = (start + end)/2;
	int p1 = query(2*node+1,start,mid,l,r);
	int p2 = query(2*node+2,mid+1,end,l,r);
	return p1+p2;
}

void update(int node,int start,int end,int idx,int value)
{
	if(start == end)
	{
		tree[node] = value;
		arr[idx] = value;
	}
	else
	{
		int mid = (start+end)/2;
		if(start<=idx && idx<=mid)
			update(2*node+1,start,mid,idx,value);
		else
			update(2*node+2,mid+1,end,idx,value);
		tree[node] = tree[2*node+1]+tree[2*node+2];
	}
}

int main()
{
	int i;
	for(i=0;i<5;i++)
		arr[i] = i+1;
	arr[2] = -1;
	for(i=0;i<5;i++)
		printf("%d ",arr[i]);
	printf("\n");
	build(0,0,4);
	printf("%d\n",query(0,0,4,0,4));
	update(0,0,4,4,-5);
	for(i=0;i<5;i++)
		printf("%d ",arr[i]);
	printf("\n");
	printf("%d\n",query(0,0,4,0,4));
	return 0;
}