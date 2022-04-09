#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list {
	int data;
	struct list *next;
};
struct list *head = NULL;
struct list *p, *t;

typedef struct stack {
	struct list* top; 
} Stack;

int empty(Stack *s) {
	return (s->top == NULL);
}

int pop(Stack *s) {
	int a;
	struct list *q;
	q = s->top;
	a = q->data;
	s->top = q->next;
	free(q);
	return a;
}

void push(int a, Stack *s) {
	struct list *q;
	q = (struct list *)malloc(sizeof(struct list));
	q->data = a;
	q->next = s->top;
	s->top = q;
}

int prior(char c) {
	if (c == '*' || c == '/')
		return 5;
	if (c == '+' || c == '-')
		return 4;
	if (c == '(')
		return 1;
	if (c == ')')
		return 2;
	return 0;
}
int per(char c) {
	int a;
	if (c <= '9' && c >= '0')
		a = c - '0';
	else
		a = c - 'a' + 10;
	return a;
}

int main() {
	int i = 0, j = -1, k = 0, x, y, z;
	char s[1000];
	char c;
	Stack *S;
	S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%s", s) == 1) {
		c = s[i];
		while (s[i] != 0) {
			if (c >= '0' && c <= '9') {
				k = k * 10 + per(c);
				i++;
				j = k;
				c = s[i];
			}
			else {
				c = s[i];
				i++;
			}
		}
		i = 0;
		if (j != -1)
			push(k, S);
		k = 0;
		j = -1;
		switch (c) {
		case '+': y = pop(S);
			x = pop(S);
			z = x + y;
			push(z, S);
			break;
		case '-': y = pop(S);
			x = pop(S);
			z = x - y;
			push(z, S);
			break;
		case '*': y = pop(S);
			x = pop(S);
			z = x * y;
			push(z, S);
			break;
		case '/': y = pop(S);
			x = pop(S);
			z = x / y;
			push(z, S);
			break;
		}
	}
	k = pop(S);
	printf("%d", k);
	return 0;
}
