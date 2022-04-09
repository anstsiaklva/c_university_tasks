#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



struct Data
{
	int a;
};
struct list
{
	struct Data data;
	struct list *next;
};

void Print(struct list *u)

{
	struct list *p = u;
	while (p)
	{
		printf("%d ", p->data.a);
		p = p->next;
	}
	//printf("\n");
}

void Clear(struct list **u)
{
	if (*u == 0) return;
	struct list *p = *u;
	struct list *t;
	while (p)
	{
		t = p;
		p = p->next;
		free(t);
	}
	*u = 0;
}
void Add_Beg(struct list **u, int x)
{
	struct list *t = (struct list*)malloc(sizeof(struct list));
	t->data.a = x;
	t->next = *u;
	*u = t;
}
void Add_End(struct list **u, int x)
{
	struct list *p = (struct list*)malloc(sizeof(struct list));
	p->data.a = x;
	struct list *t = *u;
	struct list *t1 = t->next;
	while (t1)
	{
		t = t1;
		t1 = t1->next;
	}
	t->next = p;
	p->next = 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int data = 0; int N, M, i;
	struct list *u1 = NULL;
	u1 = (struct list*)malloc(sizeof(struct list));
	struct list *u2 = NULL;
	u2 = (struct list*)malloc(sizeof(struct list));

	scanf("%d %d", &N, &M);


	scanf("%d", &data);
	u1->data.a = data;
	u1->next = NULL;

	for (i = 0; i < N - 1; i++)
	{
		scanf("%d", &data);
		Add_End(&u1, data);
	}


	scanf("%d", &data);
	u2->data.a = data;
	u2->next = NULL;
	for (i = 0; i < M - 1; i++)
	{
		scanf("%d", &data);
		Add_End(&u2, data);
	}


	struct list *newlist = NULL;
	newlist = (struct list*)malloc(sizeof(struct list));

	if (u1->data.a < u2->data.a)
	{
		newlist->data.a = u1->data.a;
		newlist->next = NULL;
		u1 = u1->next;
	}
	else
	{
		newlist->data.a = u2->data.a;
		newlist->next = NULL;
		u2 = u2->next;
	}

	while (u1 != NULL && u2 != NULL)
	{
		if (u1->data.a < u2->data.a)
		{
			Add_Beg(&newlist, u1->data.a);
			u1 = u1->next;

		}
		else
		{
			Add_Beg(&newlist, u2->data.a);
			u2 = u2->next;

		}
	}
		
	if (u1 == NULL || u2 == NULL)
		{
			if (u1 == NULL)
			{
				while (u2 != NULL)
				{
					Add_Beg(&newlist, u2->data.a);
					u2 = u2->next;
				}
			}
			else if (u2 == NULL)
			{
				while (u1 != NULL)
				{
					Add_Beg(&newlist, u1->data.a);
					u1 = u1->next;
				}
			}
		}



	Print(newlist);
	Clear(&u1);
	Clear(&u2);
	Clear(&newlist);


	return 0;
}
