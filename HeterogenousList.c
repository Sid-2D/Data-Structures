#include <stdio.h>
#include <stdlib.h>

typedef struct node n;

struct element1 {
	int data;
	void *next;
};

struct element2 {
	char data;
	void *next;
};

struct node {
	void *data;
	int type;
	n *next;
};

n* init() {
	n *tmp = (n*)malloc(sizeof(n));
	tmp -> data = NULL;
	tmp -> type = 0;
	tmp -> next = NULL;
}

struct element1* init1(int num) {
	struct element1 *tmp = (struct element1*)malloc(sizeof(struct element1));
	tmp -> data = num;
	tmp -> next = NULL;
	return tmp;
}

struct element2* init2(char data) {
	struct element2 *tmp = (struct element2*)malloc(sizeof(struct element2));
	tmp -> data = data;
	tmp -> next = NULL;
	return tmp;	
}

int main() {
	struct element1 *root = init1(1);
	struct element2 *node = init2('v');
	root -> next = node;
	n *genRoot = init();
	n *nextNode = init();
	int data1 = 10;
	char data2 = 'x';
	genRoot -> data = &data1;
	nextNode -> data = &data2;
	nextNode -> type = 1;
	genRoot -> next = nextNode;
	n *temp = genRoot;
	while (temp != NULL) {
		if (temp -> type == 0) {
			printf("%d\n", *(int *)temp -> data);
		} else {
			printf("%c\n", *(char *)temp -> data);
		}
		temp = temp -> next;
	}
	return 0;
}