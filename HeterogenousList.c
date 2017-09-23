#include <stdio.h>
#include <stdlib.h>

struct element1 {
	int data;
	void *next;
};

struct element2 {
	char data;
	void *next;
};

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
	return 0;
}