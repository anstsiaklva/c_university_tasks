#include <stdio.h>
#include <stdlib.h>



struct list
{
	int data;
	struct list *next;
};
void Print(struct list *u)
{
    freopen("output.txt", "wt", stdout);
	struct list *p = u;
	while (p)
	{
        printf("%d ", p->data);
		p = p->next;
	}

}
struct list * Find(struct list *u, int x)
{
	struct list *p = u;
	while (p)
	{
		if (p->data == x)
			return p;
		p = p->next;
	}
	return 0;
}


void Insert(struct list **u, int x)
{
	struct list *p = (struct list*)malloc(sizeof(struct list));
	p->data = x;

	struct list *t = *u;
	if (t->data >= p->data)
	{
		p->next = t;
		*u = p;
		return;
	}
	struct list *t1 = t->next;
	while (t1)
	{
		if (t->data < p->data && p->data <= t1->data)
		{
			t->next = p;
			p->next = t1;
			return;
		}
		t = t1;
		t1 = t1->next;
	}
	t->next = p;
	p->next = 0;
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



int main()
{

  freopen("input.txt", "rt", stdin);

        int d;
        struct list *u;
        u = (struct list*)malloc(sizeof(struct list));
        scanf("%d", &d);
        u->data = d;
        u->next = NULL;

         while (scanf("%d", &d) == 1)
        {
            if(!Find(u, d))
                Insert(&u, d);
        }

	Print(u);
	Clear(&u);

return 0;
}
