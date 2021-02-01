#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head);
	printf("%d -> ", p->data);
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
ListNode* search(ListNode* L, element data) {
	ListNode* p;
	int count = 0;
	p = L->link;
	do {
		if (p->data == data)
			count++;
		p = p->link;
	} while (p != L);
	if (count == 0)
		printf("\n%d은(는) 존재하지 않습니다.", data);
	else printf("\n%d은(는) %d번 있습니다.", data, count);
}

int get_size(ListNode* L) {
	ListNode* p;
	int count = 1;
	p = L->link;
	do {
		count++;
		p = p->link;
	} while (p != L);
	return count;
}
int main(void) {
	ListNode* head = NULL;
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	search(head, 50);
	printf("\n%d개", get_size(head));
	return 0;
}