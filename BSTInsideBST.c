// Link - https://www.codechef.com/DEC15/problems/PLANEDIV
// This problem was solved using a Binary Search Tree, where every node also 
// contained another Binary Search Tree.
 
#include <stdio.h>
typedef long long int lld;
typedef struct node n;
typedef struct link list;
lld max;
struct link
{
	long double c;
	list *left;
	list *right;
}*tp;
struct node 
{
	long double m;
	lld size;
	list *constants;
	n *left;
	n *right;
}*rooty,*rootx,*tmp,*trav;
list *make(long double con)
{
	tp=(list*)malloc(sizeof(list));
	tp->c=con;
	tp->left=tp->right=NULL;
	return tp;
}
n* init(long double m,long double c)
{
	tmp=(n*)malloc(sizeof(n));
	tmp->m=m;
	tmp->left=tmp->right=NULL;
	tmp->size=1;
	tmp->constants=make(c);
	return tmp;
}
void check(n *nod,long double con)
{
	list *ctrav=nod->constants;
	while(1)
	{
		if(ctrav->c-con==0)
			break;
		else
		{
			if(con > ctrav->c)
			{
				if(ctrav->right==NULL)
				{
					if(++(nod->size) > max)
						max=nod->size;
					ctrav->right=make(con);
					break;
				}
				else
					ctrav=ctrav->right;
			}
			else
			{
				if(ctrav->left==NULL)
				{
					if(++(nod->size) > max)
						max=nod->size;
					ctrav->left=make(con);
					break;
				}
				else
					ctrav=ctrav->left;
			}
		}
	}
}
void insert(lld a,lld b,lld c)
{
	if(b!=0)
	{
		long double m=a;
		m/=b;
		long double con=c;
		con/=b;
		if(rooty==NULL)
			rooty=init(m,con);
		else
		{
			trav=rooty;
			while(1)
			{
				if(m-trav->m==0)
				{
					check(trav,con);
					break;
				}
				else
					if(m>trav->m)
					{
						if(trav->right==NULL)
						{
							trav->right=init(m,con);
							break;
						}
						else
							trav=trav->right;
					}
					else
					{
						if(trav->left==NULL)
						{
							trav->left=init(m,con);
							break;
						}
						else
							trav=trav->left;
					}
			}
		}
	}
	else
	{
		long double con=c;
		con/=a;
		if(rootx==NULL)
			rootx=init(0,con);
		else
			check(rootx,con);		
	}
}
int main()
{
	lld t,a,b,c,nm;
	scanf("%lld",&t);
	while(t--)
	{
		rooty=rootx=NULL;
		max=1;
		scanf("%lld",&nm);
		while(nm--)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			insert(a,b,c);
		}
		printf("%lld\n",max);
	}
	return 0;
} 