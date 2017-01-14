// Link - http://www.spoj.com/problems/PHONELST/
// Simple implementation of Trie Data Structure

#include <stdio.h>
typedef struct node n;
struct node
{
	n* a[10];
	int end;
}*root;
n* init()
{
	int i;
	n *p;
	p=(n*)malloc(sizeof(n));
	for(i=0;i<10;i++)
		p->a[i]=NULL;
	p->end=0;
	return p;
}
int insert(char s[])
{
	n *temp=root;
	int i=0,pos;
	while(s[i]!='\0')
	{
		if(temp->end==1)
			return 1;
		pos=s[i]-48;
		if(temp->a[pos]==NULL)
			temp->a[pos]=init();
		temp=temp->a[pos];
		i++;
	}
	for(i=0;i<10;i++)
	{
		if(temp->a[i]!=NULL)
			return 1;
	}
	temp->end=1;
	return 0;
}
int main()
{
	int t,n,chk;
	char ph[15];
	scanf("%d",&t);
	while(t--)
	{
		chk=0;
		root=init();
		scanf("%d",&n);
		gets(ph);
		while(n--)
		{
			gets(ph);
			if(chk==0)
				chk=insert(ph);
		}
		if(chk)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
} 