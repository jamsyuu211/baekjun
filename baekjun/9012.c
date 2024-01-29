#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		fprintf(stderr, "스텍 포화 에러\n");
		return;
	}
	else (s->data[++(s->top)] = item);
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[(s->top)--]);
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else return (s->data[s->top]);
}

void vps(char tmp[]) {
	int i;
	int len = strlen(tmp);
	char n;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		n = tmp[i];
		switch (n) {
		case '(':
			push(&s, n);
			break;
		case ')':
			if (is_empty(&s)) {
				printf("NO\n");
				return;
			}
			else {
				pop(&s);
				break;
			}
		}
	}
	if (is_empty(&s)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main(void) {
	int num, i;
	char input[50];
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%s", input);
		if (strlen(input) >= 2) {
			vps(input);
		}
	}
	return 0;
}