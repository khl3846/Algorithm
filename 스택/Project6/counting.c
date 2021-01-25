#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

void counting(char exp[]) {
	int i = 0, countA = 1, countB = 1;
	char ch;
	int len = strlen(exp);
	StackType s1;
	StackType s2;
	init_stack(&s1);
	init_stack(&s2);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch)
		{
		case 'A':
			push(&s1, countA++);
			break;
		case 'a':
			push(&s1, countA++);
			break;
		case 'B':
			push(&s2, countB++);
			break;
		case 'b':
			push(&s2, countB++);
			break;
		}
	}
	printf("%da", pop(&s1));
	printf("%db", pop(&s2));
}

int main() {
	char* s = "aaaAbBb";
	counting(s);
}