#include "Tree.h"
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

void Ex1();
void Ex2();
void PrintInOrder(bstree tree);
void Ex3();
void PrintTreeLevelOrder(bstree tree);
void Ex4();
void FreeTree(node *tmp);

int main() {
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu one or cyclically?\n (once- enter 0, cyclically-enter any other number )\n");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do {
			for (i = 1; i <= 4; i++)
				printf("Ex %d--->%d\n", i, i);
			printf("Exit--->0\n");
			do {
				select = 0;
				printf("please select 0-4: \n");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 4));
			switch (select) {
			case 1:
				Ex1();
				break;
			case 2:
				Ex2();
			case 3:
				Ex3();
			case 4:
				Ex4();
				break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

void Ex1(){
	bstree tree;
	int temp;
	createBstree(&tree);
	printf("Please Enter Your  Element 'X' to the Tree( till you push negative number) \n");
	scanf("%d", &temp);
	while (temp>0) {

		insert(&tree, temp);
		scanf("%d", &temp);
	}


	printTree(tree.root);

	
}


void Ex2() {
	bstree tree;
	int temp;
	createBstree(&tree);
	printf("Please Enter Your  Element 'X' to the Tree( till you push negative number) \n");
	scanf("%d", &temp);
	while (temp>0){
		
		insert(&tree, temp);
		scanf("%d", &temp);
	}

	PrintInOrder(tree);
	

}


void PrintInOrder(bstree tree)
{
	node *current, *pre;

	if (tree.root == NULL)
		return;

	current = tree.root;
	printf("Your Tree Displayed inorder:\n" );
	while (current != NULL){
		if (current->left == NULL){
			printf("%2d", current->data);
			current = current->right;
		}
		else{
			
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			if (pre->right == NULL){
				pre->right = current;
				current = current->left;
			}

			else{
				pre->right = NULL;
				printf("%2d", current->data);
				current = current->right;
			} 
		} 
	} 
	printf("/n");
}
void Ex3() {
	bstree tree;
	int temp;
	createBstree(&tree); //create binary tree
	printf("Please Enter Your  Element 'X' to the Tree( till you push negative number) \n");
	scanf("%d", &temp);
	while (temp>0) {

		insert(&tree, temp);
		scanf("%d", &temp);
	}

	PrintTreeLevelOrder(tree);

}
void PrintTreeLevelOrder(bstree tree){      //The problem some where here.....
	queue *pq = (queue*)malloc(sizeof(queue)); // is struct of : *front, *rear
	int items_num;
	node *current;// is struct of : root
	 create_queue(&pq);//create queue- items_num = 0,front = NULL,rear = NULL
	
	 if (tree.root == NULL) {
		 printf("Your Tree Is Empty:\n");
		 return;
	 }
	current = tree.root;
	enqueue(current, &pq); 
	printf("Your Tree Displayed As Queue:\n");
	while ((size_of_queue(&pq) )!=0) {
		current = pq->front;
		printf("%d ", current->data);
		if (current->left != NULL) 
			enqueue(current->left, &pq);

		if (current->right) 
			enqueue(current->right, &pq);
			dequeue(&pq, &current);
			
	}
	
}




void Ex4() {
	bstree tree;
	int temp;
	createBstree(&tree);
	printf("Please Enter Your  Element 'X' to the Tree( till you push negative number) \n");
	scanf("%d", &temp);
	while (temp>0) {

		insert(&tree, temp);
		scanf("%d", &temp);
	}


	printTree(tree.root);
	FreeTree(tree.root);
}

void FreeTree(node *tmp) {
	if (!tmp)
		return;
	FreeTree(tmp->left);
	FreeTree(tmp->right);
	free(tmp);
}