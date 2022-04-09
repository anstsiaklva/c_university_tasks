#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

struct list{
	int data;
	struct list *next;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	struct list *p, *head = NULL, *u, *t;
	int i = 0; int s = 0;
	int d, n;
	p = (struct list*)malloc(sizeof(struct list));
	scanf("%d", &d);
	p->data = d;
	p->next = NULL;
	s = d;
	i = 1;
	head = p;
	while (scanf("%d", &d) == 1){
		u = (struct list*) malloc(sizeof(struct list));
		s = s + d;
		i++;
		u->data = d;
		u->next = NULL;
		t = head;
		while (t->next != NULL)
			t = t->next;
		t->next = u;
		free(u);
	}
	printf("%d", (s / i));
	free(head);
	return(0);

}
