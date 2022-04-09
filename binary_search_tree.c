#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct Node {
	char *word;
	int count;
	struct Node *left, *right;
} Node;

Node *addtree(Node *p, char *w) {
	int cond;
	if (p == NULL) { 
		p = (Node *)malloc(sizeof(Node));  
		p->word = strdup(w); 
								
		p->count = 1;        
		p->left = NULL;     
		p->right = NULL;
	}
	else
		if ((cond = strcmp(w, p->word)) == 0) 
			p->count++;  
		else
			if (cond < 0)   
				p->left = addtree(p->left, w);
			else            
				p->right = addtree(p->right, w);

	return p;
}

void treeclear(Node *tree) { 
	if (tree != NULL) {
		treeclear(tree->left);
		treeclear(tree->right);
		free(tree);
	}
}

void treeprint(Node *p) {  
	if (p != NULL) {       
		treeprint(p->left);
		printf("%s\n", p->word);
		treeprint(p->right);

	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	Node *root = NULL;
	char word[100];
	while (scanf("%s", word) == 1) 
	{
		root = addtree(root, word);
	}

	treeprint(root);  
	treeclear(root);  


	return 0;
}
