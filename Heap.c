// Basic implementation of a Heap
// Problem Link: https://www.hackerrank.com/challenges/qheap1 

#include <stdio.h>
typedef struct heap h;
struct heap
{
	int arr[100005];
	long int size;
}hp;
void swap(long int i,long int j)
{
	int t=hp.arr[i];
	hp.arr[i]=hp.arr[j];
	hp.arr[j]=t;
}
void upsift(long int index)
{
	long int min=index;
	long int left=(index<<1)+1,right=(index<<1)+2;

	if(left<hp.size && hp.arr[min]>hp.arr[left])
		min=left;
	
	if(right<hp.size && hp.arr[min]>hp.arr[right])
		min=right;
	
	if(min!=index)
	{
		swap(min,index);
		if(index>=2 && index%2==0)
			index=index/2-1;
		else
			index/=2;
		upsift(index);
	}
}
void downsift(long int index)
{
	long int min=index;
	long int left=(index<<1)+1,right=(index<<1)+2;

	if(left<hp.size && hp.arr[min]>hp.arr[left])
		min=left;
	
	if(right<hp.size && hp.arr[min]>hp.arr[right])
		min=right;
	
	if(min!=index)
	{
		swap(min,index);
		downsift(min);
	}
}
void insert(long int m)
{
	hp.arr[hp.size]=m;
	hp.size++;
    if((hp.size-1)%2==0 && (hp.size-1)>=2)
	   upsift((hp.size-1)/2-1);
    else
        upsift((hp.size-1)/2);
}
void rem(long int m)
{
	long int i;
	for(i=0;i<hp.size;i++)
		if(hp.arr[i]==m)
		{
			hp.arr[i]=hp.arr[hp.size-1];
			break;
		}
    hp.size--;
	downsift(i);
}
void display()
{
	printf("%d\n",hp.arr[0]);
}
int main()
{
	long int q,n,m;
	hp.size=0;
	scanf("%ld",&q);
	while(q--)
	{
		scanf("%ld",&n);
		if(n==1)
            {
                 scanf("%ld",&m);
			     insert(m);
            }
		else
			if(n==2)
            {
                scanf("%ld",&m);
				rem(m);
            }
			else
				display();
	}
	return 0;
}