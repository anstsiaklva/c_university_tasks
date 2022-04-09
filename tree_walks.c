#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node *addtree(Node *p, int x) {  //этот код точно такой же, что и в прошлой задаче, только вот
    if (p == NULL) {
        p = (Node *)malloc(sizeof(Node));
        p->key = x;
        p->left = NULL;
        p->right = NULL;
    } else
        if ( p->key == x ); //сравнивает напрямую по числам, так как элементы узлов - числа
            else
                if (x < p->key)
                p->left = addtree(p->left, x);
                    else
                        p->right = addtree(p->right, x);

    return p;
}

void treeclean(Node *tree) {
    if (tree != NULL) {
        treeclean(tree->left);
        treeclean(tree->right);
        free(tree);
    }
}

void treeprint_r(Node *p) {
    if (p != NULL) {
        treeprint_r(p->left);
        treeprint_r(p->right);
        printf("%d ", p->key);
    }
}

void treeprint(Node *p) {
    if (p != NULL) {
        printf("%d ", p->key);
        treeprint(p->left);
        treeprint(p->right);
    }
}



int main()
{
    Node *root = NULL;
    int data;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%d", &data) == 1) {
        root = addtree(root, data);
    }

    treeprint(root);
    printf("\n");
    treeprint_r(root);
    treeclean(root);

    return 0;
}
