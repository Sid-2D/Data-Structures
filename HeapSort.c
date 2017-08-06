#include <stdio.h>

typedef struct heap h;

struct heap  {
	int *arr;
	int size;
};

void display(int a[], int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
void swap(int *a, int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}
void heapify(h *hp, int idx) {
	int left = (idx << 1) + 1, right = (idx<<1) + 2, largest = idx;
	
	if(left < hp->size && hp->arr[left] > hp->arr[largest]) {
		largest=left;
	}
	
	if(right < hp->size && hp->arr[right] > hp->arr[largest]) {
		largest=right;
	}
	
	if(largest != idx) {
		swap(hp->arr, largest, idx);
		heapify(hp, largest);
	}
}
h* create(int a[], int size) {
	h *hp = (h*) malloc(sizeof(h));
	hp->arr = a;
	hp->size = size;
	int i;
	for(i = (hp->size-2) / 2; i >= 0; i--) {
		heapify(hp, i);
	}
	return hp;
}
void heapsort(int a[], int size) {
	h *hp = create(a,size);
	while(hp->size > 1) {
		swap(hp->arr, 0, --hp->size);
		heapify(hp, 0);
	}
}
int main() {
	int a[] = {10, 9, 11, 5, 1, 7};
	display(a, 6);
	heapsort(a, 6);
	display(a, 6);
	return 0;
}