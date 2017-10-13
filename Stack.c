//אלכס זלנצוב 321233256
//מייק רוז 312691207

#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>


void createStack(stackT* stack)
{
	stack->top = -1;
}

void push(stackT* stack, int x)
{
	// if there is a room in stack add x and return 1 - true
	if (stack->top < MAX - 1) {
		stack->top++;
		stack->items[stack->top] = x;
	}
	// ככה זה יותר מתנשא אבל לא באמת חייבים
	//		stack->items[++stack->top] = x;

	// If no room return 0 - false
	else
		printf("You Stack is FULL:\n");

}


int pop(stackT* stack)
{
	if (stack->top > -1) {
		stack->top--;
		return stack->items[stack->top + 1];
	}
	else {
	
			return MIN_INT;


	}
}

int top(stackT* stack)
{
	if (stack->top > -1) {
		return stack->items[stack->top];
	}
	else {

		return MIN_INT;
	}
}

unsigned char stackIsEmpty(stackT* stack)
{
	return stack->top == -1;
}

unsigned char stackIsFull(stackT* stack)
{
	return stack->top == MAX - 1;
}

void PrintStack(stackT* stack) {
	stackT *temp = stack;

	printf("You Stack is:\n");
	printf("|      |\n");
	while (temp->top != -1) {

		printf("|   %d  |:\n", pop(temp));
	}
	printf("|______|\n");
}
