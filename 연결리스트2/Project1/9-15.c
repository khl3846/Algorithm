#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void list_sum(ListNode* head) {
	int sum = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {
		sum += p->data;
	}
	printf("%d", sum);
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

void search_list(ListNode* head, element item) {
	int count = 0; 
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == item) {
			count++;
		}
	}
	printf("%d는 연결리스트에서 %d번 나타납니다.", item, count);
}

ListNode* search_delete(ListNode* head, element item) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == item) {
			p = delete_first(p);
		}
		p = p->link;
	}
	p = head;
	return head;
}

void print_Mm(ListNode* head) {
	int max = -1, min=10000;
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data > max)
			max = p->data;
		else if (p->data < min)
			min = p->data;
	}
	printf("\n최대값은 %d이고 최소값은 %d입니다.", max, min);
}
/*
ListNode* search_delete(ListNode* head, element item) {
	ListNode* p = head;
	while (p != NULL) {
		if (p == head && p->data == item) {
			delete_first(head);
		}
		else if (p->data == item) {
			delete_first(p);
		}
		p = p->link;
	}
	return head;
}*/

int main(void) {
	ListNode* head = NULL;
	int n, data, s;

	printf("노드의 개수 : ");
	scanf("%d", &n);

	int* exp = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		printf("노드 #%d 데이터 : ", i+1);
		scanf("%d", &data);
		exp[i] = data;
	}

	for (int i = n; i > 0; i--) {
		head = insert_first(head, exp[i - 1]);
	}

	printf("생성된 연결 리스트: ");
	print_list(head);
	printf("연결 리스트 노드의 개수 = %d\n", n);
	printf("연결 리스트 데이터 합: ");
	list_sum(head);
	printf("\n탐색할 값을 입력하시오: ");
	scanf("%d", &s);
	search_list(head, s);

	printf("\n삭제할 값을 입력하시오: ");
	scanf("%d", &s);
	head = search_delete(head, s);
	print_list(head);

	print_Mm(head);
}