#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree{
	unsigned short int val;
	struct BinarySearchTree* right;
	struct BinarySearchTree* left;
}bst_t;

bst_t* bstinsertf(bst_t* root,unsigned short int val){
	
	if(root == NULL){
		root = (bst_t *)malloc(sizeof(bst_t));
		root->val = val;
		root->left = NULL;
		root->right = NULL;
		return root;
	};
	
	if(val < root->val){
		root->right = bstinsertf(root->right,val);
	}
	else if(val > root->val){
		root->left = bstinsertf(root->left,val);
	};
	
};

void bstfree(bst_t* root){
	if(root){
		bstfree(root->left);
		bstfree(root->right);
		free(root);
	};
};

void bstprintf(bst_t* root){
	if(root != NULL){
		printf("%u ",root->val);
		bstprintf(root->left);
		bstprintf(root->right);
	}
	else{
		printf("X ");
	};
};

int main(int argc, char** argv) {	
	srand(time(NULL));
	bst_t* root = NULL;
	root = bstinsertf(root,10);
	bstinsertf(root,20);
	bstinsertf(root,30);
	bstinsertf(root,8);
	bstprintf(root);
	bstfree(root);
	return 0;
};
