#include <stdio.h>
#include <stdlib.h>

int size = 0;

typedef struct Node{
	int val;
	struct Node* next;
	void(*nprintf)(struct Node*);
	int size;
} ListNode;

int main(int argc, char** argv) {
	ListNode* node = (ListNode *)malloc(sizeof(ListNode));
	if(node == NULL) return 1;
	node->val = 1;
	size = 1;
	ListNode* writerhead = (ListNode *)malloc(sizeof(ListNode));
	if(writerhead == NULL) return 1;
	size = 2;
	node->next = writerhead;
	for(int i = 0;i<0xf0000;i++){
		writerhead->val = i+2;
		writerhead->next = (ListNode *)malloc(sizeof(ListNode));
		if(node == NULL) return 1;
		writerhead = writerhead->next;
		size++;
	};
	free(node);
	return 0;
};