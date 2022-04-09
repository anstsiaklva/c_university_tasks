#include <stdio.h>
#include <stdlib.h>

typedef struct cord {
    int x, y, time;
} cord;

char a[100][100]; 
int m, n;
cord s, f;     

typedef struct queue {  
    cord value;
	struct queue *next;
}queue;

void push_back(queue **head, cord data) {   
	queue *p = (queue*)malloc(sizeof(queue)), *t;
	if (*head == NULL) {
		p->value = data;
		p->next = NULL;
		*head = p;
	}
	else {
		p->value = data;
		p->next = NULL;
		t = *head;
		while (t->next) t = t->next;
		t->next = p;
	}
}

cord qpop(queue **head) {  
	queue *p = (queue*)(malloc(sizeof(queue)));
	cord value;
	p = (*head);
	*head = (*head)->next;
	value = p->value;
	free(p);
	return value;
}

int bfs(void) {
    int i, j;
    cord value;
    queue *head = NULL;
    cord pos;

    push_back(&head, s);
    while ( head ) {
        pos = qpop(&head);

        i = pos.x;
        j = pos.y;
        if (i == f.x && j == f.y) {  
            printf("%d", pos.time);
            return 1;
        }

        if ( i + 1 < n && a[i + 1][j] == 1) {  
            a[i + 1][j] = 2;      
            value.x = i + 1;
            value.y = j;
            value.time = pos.time + 1;
            push_back(&head, value);           
        }
        if ( j + 1 < m && a[i][j + 1] == 1) {  
            a[i][j + 1] = 2;
            value.x = i;
            value.y = j + 1;
            value.time = pos.time + 1;
            push_back(&head, value);
        }
        if ( i - 1 >= 0 && a[i - 1][j] == 1 ) {  
            a[i - 1][j] = 2;
            value.x = i - 1;
            value.y = j;
            value.time = pos.time + 1;
            push_back(&head, value);
        }
        if ( j - 1 >= 0 && a[i][j - 1] == 1) { 
            a[i][j - 1] = 2;
            value.x = i;
            value.y = j - 1;
            value.time = pos.time + 1;
            push_back(&head, value);
        }
    }

    return -1;
}

int main()
{
    int i, j;
    char inp;

    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%c", &inp);
    for (i = 0; i < n; i++)  
    for (j = 0; j < m; j++) {
        if (j == m - 1) {
            scanf("%c\n", &inp); 
        } else {
            scanf("%c", &inp);
        }

        if (inp == '.')    
            a[i][j] = 1;
        if (inp == 'X')  
            a[i][j] = 0;
        if (inp == 'F') {  
            a[i][j] = 1;
            f.x = i;
            f.y = j;
        }
        if (inp == 'S') {  
            a[i][j] = 1;
            s.x = i;
            s.y = j;
        }
    }

    s.time = 0;

    i = bfs();    
    if (i == -1)
        printf( "%d", i);


    return 0;
}
