#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct node n;

struct node {
	int data;
	n *left;
	n *right;
} *root;

n* init(int data) {
	n *vertex = (n*)malloc(sizeof(n));
	vertex -> data = data;
	vertex -> left = vertex -> right = NULL;
	return vertex;
}

void insert(int num) {
	bool done = false;
	n *temp = root;
	while(!done) {
		if (temp -> data < num) {
			if (temp -> right != NULL) {
				temp = temp -> right;
			} else {
				temp -> right = init(num);
				done = true;
			}
		} else {
			if (temp -> left != NULL) {
				temp = temp -> left;
			} else {
				temp -> left = init(num);
				done = true;
			}
		}
	}
}

void inorderStack() {
	stack <n*> st;
    bool done = false;
    n *temp = root;
    while (!done) {
        if (temp != NULL) {
            st.push(temp);
            temp = temp -> left;
            continue;
        }
        if (!st.empty()) {
            temp = st.top();
            st.pop();
            cout << temp -> data << " ";
            temp = temp -> right;
        } else {
            done = 1;
        }
    }
}

void inorderRecursion(n *root) {
	if (root -> left != NULL) {
		inorderRecursion(root -> left);
	}
	cout << root -> data << " ";
	if (root -> right != NULL) {
		inorderRecursion(root -> right);
	}
}

void preorderRecursion(n *root) {
	cout << root -> data << " ";
	if (root -> left != NULL) {
		inorderRecursion(root -> left);
	}
	if (root -> right != NULL) {
		inorderRecursion(root -> right);
	}
}

void postorderRecursion(n *root) {
	if (root -> left != NULL) {
		inorderRecursion(root -> left);
	}
	if (root -> right != NULL) {
		inorderRecursion(root -> right);
	}
	cout << root -> data << " ";
}

int main() {
	int arr[] = {1, 2, 4, 5};
	root = init(3);
	for (int i = 0; i < 4; i++) {
		insert(arr[i]);
	}
	cout << "Inorder:\n"; 
	inorderRecursion(root);
	cout << "\nPreorder:\n"; 
	preorderRecursion(root);
	cout << "\nPostorder:\n"; 
	postorderRecursion(root);
	return 0;
}