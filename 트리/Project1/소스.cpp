#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL)return NULL;
	if (key == node->key)return node;
	else if (key < node->key)return search(node->left, key);
	else return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);
	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key) root->left = delete_node(root->left, key);
	else if (key > root->key) root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root == NULL) return;
	preorder(root->right);
	printf("[%d] ", root->key);
	preorder(root->left);

}

element sum_node(TreeNode* root) {
	int sum = 0;
	if (root == NULL)
		return 0;
	sum = root->key;
	sum = sum + sum_node(root->right) + sum_node(root->left);
	return sum;
}

void min_than_root(TreeNode* root, int x) {
	if (root) {
		min_than_root(root->left, x);
		if(root->key < x)
			printf("%d보다 작은 노드: %d\n", x, root->key);
		min_than_root(root->right, x);
	}
}
element child_node(TreeNode* root) {
	int n = 0;
	if (root == NULL) return 0;
	if (root->right != NULL && root->left == NULL) n += 1;
	else if (!root->right == NULL && root->left != NULL) n += 1;
	n = n + child_node(root->right) + child_node(root->left);
	return n;
}

int min(int a, int b) {
	if (a < b)
		return a;
	else return b;
}

int findmin(TreeNode* root) {
	if (root == NULL) return 10000;
	int m = root->key;
	m = min(m, findmin(root->right));
	m = min(m, findmin(root->left));
	return m;
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* tree = NULL;
	TreeNode* tmp = NULL;
	int sum = 0;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);

	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함\n");
	else
		printf("이진 탐색 트리에서 30을 발견못함\n");

	sum = sum_node(root);
	printf("\n노드의 합은 %d입니다.\n", sum);

	min_than_root(root, 30);

	sum = child_node(root);
	printf("\n%d", sum);

	sum = findmin(root);
	printf("\nmin : %d\n", sum);

	int list[11] = { 11, 3, 4, 1, 56, 5, 6, 2, 98, 32, 23 };

	for (int i = 0; i < 11; i++)
		tree = insert_node(tree, list[i]);
	
	printf("\n이진 트리 오름차순 순회 결과\n");
	inorder(tree);
	printf("\n");

	printf("\n이진 트리 내림차순 순회 결과\n");
	preorder(tree);
	printf("\n");

	return 0;
}