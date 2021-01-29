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
	printf("%d�� ���Ḯ��Ʈ���� %d�� ��Ÿ���ϴ�.", item, count);
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
	printf("\n�ִ밪�� %d�̰� �ּҰ��� %d�Դϴ�.", max, min);
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

	printf("����� ���� : ");
	scanf("%d", &n);

	int* exp = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		printf("��� #%d ������ : ", i+1);
		scanf("%d", &data);
		exp[i] = data;
	}

	for (int i = n; i > 0; i--) {
		head = insert_first(head, exp[i - 1]);
	}

	printf("������ ���� ����Ʈ: ");
	print_list(head);
	printf("���� ����Ʈ ����� ���� = %d\n", n);
	printf("���� ����Ʈ ������ ��: ");
	list_sum(head);
	printf("\nŽ���� ���� �Է��Ͻÿ�: ");
	scanf("%d", &s);
	search_list(head, s);

	printf("\n������ ���� �Է��Ͻÿ�: ");
	scanf("%d", &s);
	head = search_delete(head, s);
	print_list(head);

	print_Mm(head);
}