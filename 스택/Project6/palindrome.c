#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef char element;

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
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

void palindrome(char exp[]) {
	int i = 0;
	char ch;
	int len = strlen(exp);
	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch >= 'A' && ch <= 'Z') {
			tolower(ch);
			push(&s, ch);
		}
		else if (ch >= 'a' && ch <= 'z') {
			push(&s, ch);
		}
		else continue;
	}

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch >= 'A' && ch <= 'Z') {
			if (ch != pop(&s)) {
				printf("ȸ���� �ƴմϴ�.");
				return;
			}
		}
		else if (ch >= 'a' && ch <= 'z') {
			if (ch != pop(&s)) {
				printf("ȸ���� �ƴմϴ�.");
				return;
			}
		}
		else continue;
	}
	printf("ȸ���Դϴ�.");
	return;
}


int main() {
	char* s = "race car";
	palindrome(s);
}