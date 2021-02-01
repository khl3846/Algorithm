#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == NULL) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void reverse(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("%d ", p->data);
	}
	printf("\n");
}
DListNode* search(DListNode* phead, element data) {
	DListNode* p;
	int count = 0;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p->data == data)
			count++;
	}
	printf("\n%d��(��) %d�� �ֽ��ϴ�.", data, count);
}

int main(void) {
	int n;
	element temp;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");
	/*for (int i = 0; i < 5; i++) {
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}*/
	printf("�������� ������ �Է��Ͻÿ� : ");
	scanf("%d", &n);

	printf("\n");
	for (int i = 1; i <= 3; i++) {
		printf("��� #%d�� �����͸� �Է��Ͻÿ�: ", i);
		scanf("%d", &temp);
		dinsert(head, temp);
	}
	printf("\n");

	reverse(head);

	search(head, 3);
	free(head);
	return 0;
}