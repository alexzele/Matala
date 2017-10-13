#pragma once

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *father;
} node;

typedef struct {
	node *root;
} bstree;

void createBstree(bstree *tree);

void insert(bstree *tree, int data);

node *minNode(node *tmp);

node *sucessorNode(node *tmp);

void printTree(node *tmp);

node *findInTree(node *tmp, int data);

node *deleteInTree(bstree *tree, node *tmp);



