// Problem link: http://www.spoj.com/problems/DICT/

#include <stdio.h>
#include <stdlib.h>

typedef struct node n;
struct node {
	n *a[26];	
	int end;
} *root;

char buff[25];

int bufflen=0;

n* init() {
	int i;
	n *p;
	p = (n*) malloc (sizeof(n));
	for (i = 0;i < 26; i++) {
		p->a[i] = NULL;
	}
	p->end = 0;
	return p;
}

void insert(char s[]) {
	n *temp = root, *p;
	int i = 0, pos;
	while(s[i] != '\0') {
		pos = s[i] - 97;
		if (temp->a[pos] == NULL) {
			p = init();
			temp->a[pos] = p;
		}
		temp = temp->a[pos];
		i++;
	}
	temp->end = 1;
}

void disp(n* temp, int j) {
	if (j != -1) {
		buff[bufflen++] = (char)(97+j);
		buff[bufflen] = '\0';
		if(temp->end == 1) {
			printf("%s\n",buff);
		}
	}
	int i, chk = 0;
	for (i = 0;i < 26; i++) {
		if (temp->a[i] != NULL) {
			disp(temp->a[i], i);
			chk = 1;
		}
	}
	if (chk == 0) {
		if(j == -1) {
			printf("No match.\n");
		}
		else {
			buff[--bufflen] = '\0';
		}
	}
	else {
		if (i == 26) {
			buff[--bufflen] = '\0';
		}
	}
}

void query(char s[]) {
	n *temp = root;
	int i = 0, pos;
	while(temp != NULL && s[i] != '\0') {
		pos = s[i] - 97;
		temp = temp->a[pos];
		buff[bufflen++] = s[i];
		i++;
	}
	buff[bufflen] = '\0';
	if(temp == NULL) {
		printf("No match.\n");
	}
	else {
		disp(temp, -1);
	}
	bufflen = 0;
}

int main()
{
	root = init();
	char wd[25];
	int n, k, i;
	scanf("%d", &n);
	gets(wd);
	while(n--) {
		gets(wd);
		insert(wd);
	}
	scanf("%d", &k);
	gets(wd);
	i = 1;
	while(k--) {
		gets(wd);
		printf("Case #%d:\n", i);
		query(wd);
		i++;
	}
    return 0;
}