/*   Stack.h    */

#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef char StackDataType;

#define	MAX_SIZE	(100)

typedef struct Stack {
	StackDataType	array[MAX_SIZE];
	int				top;	// 表示当前个数
}	Stack;

void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

void StackDestroy(Stack *pStack)
{
	pStack->top = 0;
}

void StackPush(Stack *pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);

	pStack->array[pStack->top++] = data;
}

void StackPop(Stack *pStack)
{
	assert(pStack->top > 0);

	pStack->top--;
}

StackDataType StackTop(const Stack *pStack)
{
	assert(pStack->top > 0);

	return pStack->array[pStack->top - 1];
}

int StackSize(const Stack *pStack)
{
	return pStack->top;
}

int StackFull(const Stack *pStack)
{
	return pStack->top >= MAX_SIZE;
}

int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}

int IsValid(char in[], char out[], int size)
{
	int ii = 0, io = 0;
	Stack	stack;
	StackInit(&stack);

	while (ii < size) {
		if (in[ii] == out[io]) {
			ii++;
			io++;
		}
		else {
			if (!StackEmpty(&stack) && StackTop(&stack) == out[io]) {
				StackPop(&stack);
				io++;
			}
			else {
				StackPush(&stack, in[ii]);
				ii++;
			}
		}
	}

	// 进的序列已经全部结束
	while (!StackEmpty(&stack)) {
		if (StackTop(&stack) != out[io]) {
			return 0;
		}

		StackPop(&stack);
		io++;
	}

	return 1;
}

void TestValid()
{
	char *in = "abcd";
	char *out1 = "dcab";
	printf("%s\n", IsValid(in, out1, strlen(in)) ? "合法" : "不合法");
	
}
