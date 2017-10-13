#pragma once

#define MAX 100
#define MIN_INT 1<<31

typedef struct {
	int top;
	int items[MAX];
} stackT;

void createStack(stackT* stack);

void push(stackT* stack, int x);

int pop(stackT* stack);

int top(stackT* stack);

unsigned char stackIsEmpty(stackT* stack);

unsigned char stackIsFull(stackT* stack);

void PrintStack(stackT* stack);
