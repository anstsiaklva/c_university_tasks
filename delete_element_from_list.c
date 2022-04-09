#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int value;
	struct List *next;
} List;

typedef struct LinkedList {
	List *head;
	List *tail;
} LinkedList;

LinkedList* createLinkedList() {
	LinkedList* tmp = (LinkedList*)malloc(sizeof(LinkedList));
	tmp->head = tmp->tail = NULL;

	return tmp;
}
void deleteLinkedList(LinkedList **list) {
	List* prev = NULL;
	while ((*list)->head->next) {
		prev = (*list)->head;
		(*list)->head = (*list)->head->next;
		free(prev);
	}
	free((*list)->head);
	free(*list);
	*list = NULL;
}

void printList(LinkedList *list) {
	List *p = list->head;
	while (p) {
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}



void shift(LinkedList *list, int value) {
	List *tmp = (List*)malloc(sizeof(List));

	tmp->next = NULL;
	tmp->value = value;
	if (list->tail) {
		list->tail->next = tmp;
	}
	list->tail = tmp;
	if (list->head == NULL) {
		list->head = tmp;
	}
}

void DeleteElements(LinkedList *list) {
	List *p = list->head;
	while (p) {
		if ((p->next != NULL) && (p->value == p->next->value))
		{
			List *elm = p->next;
			p->next = p->next->next;
			free(elm);

		}
		else
		{
			p = p->next;

		}
	}

}


int main()
{
	LinkedList *list = createLinkedList();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int data;

	while (scanf("%d", &data) == 1)
		shift(list, data);



	DeleteElements(list);
	printList(list);
	deleteLinkedList(&list);



	return 0;
}
