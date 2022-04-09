#include <stdio.h>
#include <stdlib.h>



struct list
{
	int data;
	struct list *next;
};
void Print(struct list *u)
{
    int i = 0;
    freopen("output.txt", "wt", stdout);
	struct list *p = u;
	while (p)
	{
	    if(!((p->data)%7)&&((p->data)<0))
            i++;
		p = p->next;
	}
	printf("%d", i);

}

void Add_Beg(struct list **u, int x)
{
	struct list *t = (struct list*)malloc(sizeof(struct list));
	t->data = x;
	t->next = *u;
	*u = t;
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
           Add_Beg(&u, d);
        }

	Print(u);
	Clear(&u);


return 0;
}
