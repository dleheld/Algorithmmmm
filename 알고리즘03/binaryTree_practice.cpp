#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <iostream>

using namespace std;
#define MAX_V 10000

struct node {
	int num;
	int count;

	struct node* left;
	struct node* right;
};
struct node* root;
struct node* pfirst;
int numcall = 0;

struct node* treealloc(void) { //node �����
	return (struct node*) malloc(sizeof(struct node));
}

struct node* addnode(struct node* p, int myNum, int childNum) {
	int cond = 0;
	//���� node�� �� ����: V
	p = treealloc(); //��� ��� ����� �Ҵ��ϱ�
	p->count = 0; //�׻� 1���� ����
	p->num = myNum;
	p->left = p->right = NULL;

	if (numcall == 0) {
		p->num = 1;
		pfirst = p;
	}//ù ���(1)����
	else if (p->count == 0) {
		p->count++;
		p->left = addnode(p->left, childNum, 0);
	}
	else if (p->count == 1) {
		p->count++;
		p->right = addnode(p->right, childNum, 0);
	}
	++numcall;
	return p;
}
void showtree(struct node* p) {
	if (p != NULL) {
		showtree(p->left);
		printf("%4d", p->num);
		showtree(p->right);
	}
}
int V, E, tg1, tg2;
int parentNum, childNum;
int main() {
	cin >> V >> E;
	cin >> tg1 >> tg2;
	struct node* root = NULL;
	root = addnode(root, 1, 0);
	for (int i = 0; i < E; ++i) {
		cin >> parentNum >> childNum;
		root = addnode(root, parentNum, childNum);
	}
	cout << "#" << t << ' ' <<  << endl;
	return 0;
}