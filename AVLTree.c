#include <stdio.h>

typedef struct node n;

struct node {
	int key;
	n *a[2];
	int height;
} *root = NULL, *tmp;

n* init(int ele) {
	tmp = (n*)malloc(sizeof(n));
	tmp->a[0] = tmp->a[1] = NULL;
	tmp->key = ele;
	tmp->height = 1;
	return tmp;
}

int getheight(n *x) {
	if(x == NULL)
		return 0;
	return x->height;
}

int bf(n* x) {
	return getheight(x->a[0])-getheight(x->a[1]);
}

int max(int x, int y) {
	return x > y ? x : y;
}

n* leftrotate(n *x) {
	n *y = x->a[1];
	n *t2 = y->a[0];
	
	y->a[0] = x;
	x->a[1] = t2;
	
	x->height = max(getheight(x->a[0]), getheight(x->a[1])) + 1;
	y->height = max(getheight(y->a[0]), getheight(y->a[1])) + 1;
	
	return y;
}

n* rightrotate(n *y) {
	n *x = y->a[0];
	n *t2 = x->a[1];
	
	x->a[1] = y;
	y->a[0] = t2;
	
	x->height = max(getheight(x->a[0]), getheight(x->a[1])) + 1;
	y->height = max(getheight(y->a[0]), getheight(y->a[1])) + 1;
	
	return x;
}

n* insert(n* x,int ele) {
	if(x == NULL)
		return (init(ele));
	
	if (ele < x->key) {
		x->a[0] = insert(x->a[0], ele);
	}
	else {
		x->a[1] = insert(x->a[1], ele);
	}
	
	x->height = max(getheight(x->a[0]), getheight(x->a[1])) + 1;
	
	int balnce = bf(x);
	
	if (balnce > 1 && ele < x->a[0]->key) {
		return rightrotate(x);
	}
	if(balnce > 1 && ele > x->a[0]->key) {
		x->a[0] = leftrotate(x->a[0]);
		return rightrotate(x);
	}
	if(balnce < -1 && ele > x->a[1]->key) {
		return leftrotate(x);
	}
	if(balnce < -1 && ele < x->a[1]->key) {
		x->a[1] = rightrotate(x->a[1]);
		return leftrotate(x);
	}
	return x;
}

void preorder(n* root) {
	printf("%d ", root->key);
	if (root->a[0] != NULL) {
		preorder(root->a[0]);
	}
	if(root->a[1] != NULL) {
		preorder(root->a[1]);
	}
}

int main() {
	int n = 3, a;
	while(n--) {
		scanf("%d", &a);
		root = insert(root, a);
	}
	preorder(root);
	return 0;
}