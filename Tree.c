#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>


int Max(int a, int b) {
	return a>b ? a : b;
}

void createBstree(bstree *tree)
{
	tree->root = NULL;
}

void insertToNode(node *theNode, node *tmp)
{
	if (tmp->data < theNode->data) {
		if (!theNode->left) {
			theNode->left = tmp;
			tmp->father = theNode;
		}
		else {
			insertToNode(theNode->left, tmp);
		}
	}
	else {
		if (!theNode->right) {
			theNode->right = tmp;
			tmp->father = theNode;
		}
		else {
			insertToNode(theNode->right, tmp);
		}
	}

}

void insert(bstree *tree, int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	if (!tree->root) {
		tmp->father = NULL;
		tree->root = tmp;

	}
	else {
		insertToNode(tree->root, tmp);


	}

}


node *minNode(node *tmp)
{
	if (!tmp->left) {
		return tmp;
	}
	else {
		return minNode(tmp->left);
	}

}

node *sucessorNode(node *tmp)
{
	if (!tmp) {
		return NULL;
	}
	else {
		if (tmp->right) {

			return minNode(tmp->right);
		}
		else {
			node *father = tmp->father;

			while (father != NULL) {
				if (father->left == tmp) {
					return father;
				}
				tmp = tmp->father;
				father = tmp->father;

			}
			return NULL;

		}
	}
}

void printTree(node *tmp)
{

	if (tmp->left) {
		printTree(tmp->left);
	}
	printf("%d\n", tmp->data);
	if (tmp->right) {
		printTree(tmp->right);
	}

}

node *findInTree(node *tmp, int data)
{
	node *subTree = NULL;
	if (tmp->data == data) {
		return tmp;
	}
	else if (tmp->data > data) {
		subTree = tmp->left;
	}
	else {
		subTree = tmp->right;
	}


	if (subTree) {
		return findInTree(subTree, data);
	}
	else {
		return NULL;
	}
}

node *deleteInTree(bstree *tree, node *tmp)
{
	node *nodeToDelete = tmp;
	node *child, *father;


	// If there are 2 children of node, its successor 
	// should be deleted,
	// else the node itself should be deleted
	if (tmp->left && tmp->right) {
		nodeToDelete = sucessorNode(tmp);
		// copy the data from successor to the node
		tmp->data = nodeToDelete->data;
	}

	father = nodeToDelete->father;

	// Find the child of node, the node cant have 2 children,
	// handled in previous if
	if (nodeToDelete->left) {
		child = nodeToDelete->left;
	}
	else if (nodeToDelete->right) {
		child = nodeToDelete->right;
	}
	else {
		child = NULL;
	}

	// Connect child to the node's father
	if (child) {
		child->father = nodeToDelete->father;
	}

	// If node has father, connect the father to child
	// If node has no father - it root
	if (father) {
		if (father->left == nodeToDelete) {
			father->left = child;
		}
		else {
			father->right = child;
		}
	}
	else {
		tree->root = child;
	}
	free(nodeToDelete);
}
