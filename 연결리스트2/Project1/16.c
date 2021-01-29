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

ListNode* insert_end(ListNode* head, element value) {
	ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p;

	if (head == NULL) {
		pre->data = value;
		pre->link = head;
		head = pre;
		return head;
	}
	else {
		pre->data = value;
		pre->link = NULL;
		ListNode* p;
		for (p = head; p->link != NULL; p = p->link) {
		}
		p->link = pre;
		return head;
	}
	if (p != NULL) {
		for (p = head; p->link != NULL; p = p->link) {
		}
		p->link = pre;
	}
	
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

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

/*
void delete_odd(ListNode* head) {
	int count = 1;
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (count % 2 == 1) {
			p = delete_first(p);
		}
		else {
			printf("%d -> ", p->data);
		}
		count++;
	}
}*/

ListNode* alternate(ListNode* head1, ListNode* head2, ListNode* head3) {
	ListNode* a = head1;
	ListNode* b = head2;

	while (a && b) {
		head3 = insert_end(head3, a->data);
		head3 = insert_end(head3, b->data);
		a = a->link;
		b = b->link;
	}
	for (; a != NULL; a = a->link)
		head3 = insert_end(head3, a->data);
	for (; b != NULL; b = b->link)
		head3 = insert_end(head3, b->data);

	return head3;
}

ListNode* ascending(ListNode* head1, ListNode* head2, ListNode* head3) {
	ListNode* a = head1;
	ListNode* b = head2;

	while (a && b) {
		if (a->data < b->data) {
			head3 = insert_end(head3, a->data);
			a = a->link;
		}
		else {
			head3 = insert_end(head3, b->data);
			b = b->link;
		}
	}
	for (; a != NULL; a = a->link)
		head3 = insert_end(head3, a->data);
	for (; b != NULL; b = b->link)
		head3 = insert_end(head3, b->data);

	return head3;
}

void split_list(ListNode* head) {
	ListNode* a = NULL;
	ListNode* b = NULL;
	int count = 1;
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (count % 2 == 1) {
			a = insert_first(&a, p->data);
		}
		else {
			b = insert_first(&b, p->data);
		}
		count++;
	}
	print_list("연결리스트 A : ", a);
	print_list("연결리스트 B : ", b);
	return;
}

int main(void) {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	int n, data, s;
	
	printf("노드의 개수 : ");
	scanf("%d", &n);

	int* exp = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf("%d", &data);
		exp[i] = data;
	}

	for (int i = n; i > 0; i--) {
		head1 = insert_first(head1, exp[i - 1]);
	}

	printf("생성된 연결 리스트: ");
	print_list(head1);
/*
	printf("노드의 개수 : ");
	scanf("%d", &n);

	int* exp1 = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf("%d", &data);
		exp1[i] = data;
	}

	for (int i = n; i > 0; i--) {
		head2 = insert_first(head2, exp1[i - 1]);
	}

	printf("생성된 연결 리스트: ");
	print_list(head2);
	*/

	//head3 = ascending(head1, head2, head3);
	//print_list(head3);
	split_list(head1);
}