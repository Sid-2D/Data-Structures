#include <stdio.h>
#include <stdlib.h>

typedef struct node n;

struct node {
	int data;
	n *next;
};

n* init(int num) {
	n *tmp = (n*)malloc(sizeof(n));
	tmp -> data = num;
	tmp -> next = NULL;
	return tmp;
}

void display(n *start) {
	while(start != NULL) {
		printf("%d ", start -> data);
		start = start -> next;
	}
	printf("\n");
}

int floydCycle(n *list) {
   n *p1 = list, *p2 = list;
   while (p1 != NULL) {
       if (p2 -> next != NULL) {
           if (p2 -> next -> next != NULL) {
               p2 = p2 -> next -> next;
           } else {
               break;
           }
       } else {
           break;
       }
       p1 = p1 -> next;
       if (p1 == p2) {
           return 1;
       }
   }
   return 0;
}

void reverse(n *root) {
	n *prev = NULL, *cur = root, *next = root -> next;
	while (cur != NULL) {
		// printf("%d", cur -> data);
		next = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = next;
	}
	root = prev;
	display(root);
}

int main() {
	// No loops
	int i, arr[] = {1, 2, 3, 4, 5};
	n *root = init(arr[0]), *temp = root;
	for (i = 1; i < 5; i++) {
		n *vertex = init(arr[i]);
		temp -> next = vertex;
		temp = temp -> next;
	}
	display(root);
	reverse(root);
	// display(root);
	if (!floydCycle(root)) {
		printf("Does not contain a loop\n");
	} else {
		printf("Contains a loop\n");
	}
	// Create a loop
	temp = root;
	for (i = 0; i < 3; i++) {
		temp = temp -> next;
	}
	temp -> next = root;
	// display(root);
	if (!floydCycle(root)) {
		printf("Does not contain a loop\n");
	} else {
		printf("Contains a loop\n");
	}
	return 0;
}