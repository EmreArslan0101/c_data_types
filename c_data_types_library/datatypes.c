#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include <string.h>

queue_t createQueue() {
	queue_t queue;
	queue.data = (int *)malloc(sizeof(int));
	queue.size = 0;
	return queue;
}

void enqueuef(queue_t *queue, int value) {
    queue->size++;
    queue->data = (int *)realloc(queue->data, (queue->size) * sizeof(int));
    if (queue->data == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    queue->data[queue->size - 1] = value;
}


int dequeuef(queue_t *queue) {

	int returnval = queue->data[0];
	
	queue->data[0] = 0;
	
	for(int i = 1;i<queue->size;i++){
		queue->data[i-1] = queue->data[i];
	};

	queue->size--;
	
    queue->data = (int *)realloc(queue->data, (queue->size) * sizeof(int));
    if (queue->data == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    
    return returnval;
};

stack_t createStack() {
	stack_t stack;
	stack.data = (int *)malloc(sizeof(int));
	stack.size = 0;
	return stack;
}

void pushf(stack_t *stack, int value) {
    stack->size++;
    stack->data = (int *)realloc(stack->data, (stack->size) * sizeof(int));
    if (stack->data == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
    stack->data[stack->size - 1] = value;
}

int popf(stack_t *stack) {

	int returnval = stack->data[stack->size - 1];

	stack->data[stack->size - 1] = 0;

	stack->size--;

    stack->data = (int *)realloc(stack->data, (stack->size) * sizeof(int));
    if (stack->data == NULL) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    return returnval;
};

map_t *createmap(){
	
	map_t *map = (map_t *)malloc(sizeof(map_t));
	
	map->size = 0;
	
	map->pairs = NULL;
	
	return map;
	
};

void mremove(map_t *map,char* key){
	
	char startremove = 0;
	
	for(int i = 0;i<map->size;i++){
		
		if(!strcmp(map->pairs[i].key,key)) startremove = 1;
		
		if(startremove) map->pairs[i-1] = map->pairs[i];
		
	};
	
	if(startremove){
		
		map->size--;
		
		map->pairs = (kvpair_t *)realloc(map->pairs,map->size*sizeof(kvpair_t));
		
	};
	
};

void mset(map_t *map,char* key,int value){
	
	for(int i = 0;i<map->size;i++){
		if(key[0] == map->pairs[i].key[0]){
			if(!strcmp(map->pairs[i].key,key)){
				map->pairs[i].value = value;
				return;	
			};
		};
	};
	
	kvpair_t pair;
	
	pair.key = (char *)malloc(strlen(key)+1);
	
	pair.key[strlen(key)] = '\0';
	
	pair.value = value;
	
	strcpy(pair.key,key);
	
	map->size++;
	
	map->pairs = (kvpair_t *)realloc(map->pairs,sizeof(kvpair_t)*map->size);
	
	if(map->pairs == NULL){
		printf("Allocation Error on set:map->pairs");
        exit(1);
	};
	
	map->pairs[map->size - 1] = pair;
	
};

int mget(map_t *map,char* key){
	
	for(int i = 0;i<map->size;i++){
		
		if(!strcmp(map->pairs[i].key,key)) return map->pairs[i].value;
		
	};
	
};

void mprintf(map_t *map){
	
	printf("[");
	
	for(int i = 0;i<map->size;i++){
		
		printf("%s=>%d%c",map->pairs[i].key,map->pairs[i].value,i == map->size-1 ? ']' : ',');

	};
	
};

void mfree(map_t *map){
	
	for(int i = 0;i<map->size;i++){
		free(map->pairs[i].key);
	};
	
	free(map);
	
};

void llprintf(ListNode* head) {

	ListNode *clone = head;

	while(clone) {
		printf("%d>",clone->val);
		clone = clone->next;
	};
	printf("NULL\n");

}

void addNode(ListNode* head, int val) {

	ListNode *clone = head;
	while(clone->next) {
		clone = clone->next;
	};

	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	if(newNode == NULL) exit(1);
	newNode->val = val;
	newNode->next = NULL;
	clone->next = newNode;

}

void insertNode(ListNode* head, int val, int index) {

	if(head == NULL) {
		head = (ListNode *)malloc(sizeof(ListNode));
		head->val = val;
		head->next = NULL;
		return;
	}

	ListNode *clone = head;
	while(clone && (--index >= 0)) {
		clone = clone->next;
	};

	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	if(newNode == NULL) exit(1);
	if(clone != NULL) {
		newNode->val = val;
		newNode->next = clone->next;
		clone->next = newNode;
	}
	else {
		clone = head;
		while(clone->next) {
			clone = clone->next;
		};
		newNode->val = val;
		newNode->next = clone->next;
		clone->next = newNode;
	};

};

void removeList(ListNode* head /*Use for whole list*/) {

	if(head == NULL) return;

	ListNode *next;

	while(head) {
		next = head->next;
		free(head);
		head = next;
	};

};

void *removeNode(ListNode* head, int val /*Use for a node*/) {
    if (head == NULL) {
        return NULL; // The list is empty.
    }

    // Special case: if the head node needs to be removed
    if (head->val == val) {
    	ListNode* temp = head;
        head = head->next;
        free(temp);
        return (void *)head;
    }

    ListNode* current = head;
    while (current->next != NULL && current->next->val != val) {
        current = current->next;
    }

    if (current->next != NULL) {
        ListNode* temp = current->next;
        current->next = temp->next;
        free(temp);
   }
}

graph_t *createGraph(){
	
	graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
	
	graph->size = 0;
	
	graph->nodes = NULL;
	
	return graph;
	
};

void removeGraph(graph_t *graph){
	
	for(int i = 0;i<graph->size;i++){
		free(graph->nodes[i]);
	};
	
	free(graph);
	
};

void createEdge(gnode_t *node1,gnode_t *node2){
	
	if(node1->linkedNodes == NULL){
		node1->linkedNodes = (gnode_t **)malloc(sizeof(gnode_t));
		if(node1->linkedNodes == NULL){
			printf("Allocation Error on node1");
			exit(1);
		};
		node1->linkedNodes[0] = node2;
		node1->connections++;
	}
	else{
		node1->linkedNodes = (gnode_t **)realloc(node1->linkedNodes,sizeof(gnode_t)*(++node1->connections));
		if(node1->linkedNodes == NULL){
			printf("Allocation Error on node1");
			exit(1);
		};
		node1->linkedNodes[node1->connections - 1] = node2;
	};
	
	if(node2->linkedNodes == NULL){
		node2->linkedNodes = (gnode_t **)malloc(sizeof(gnode_t));
		if(node2->linkedNodes == NULL){
			printf("Allocation Error on node2");
			exit(1);
		};
		node2->linkedNodes[0] = node1;
		node2->connections++;
	}
	else{
		node2->linkedNodes = (gnode_t **)realloc(node2->linkedNodes,sizeof(gnode_t)*(++node2->connections));
		if(node2->linkedNodes == NULL){
			printf("Allocation Error on node2");
			exit(1);
		};
		node2->linkedNodes[node2->connections - 1] = node1;
	};
	
};

gnode_t *createGraphNode(graph_t *graph,int data){
	
	gnode_t *node = (gnode_t *)malloc(sizeof(gnode_t));
	
	if (node == NULL) {
        printf("Allocation Error on createnode");
        exit(1);
    }
	
	node->connections = 0;
	
	node->data = data;
	
	node->linkedNodes = NULL;
	
	if(graph->nodes == NULL){
		graph->nodes = (gnode_t **)malloc(sizeof(gnode_t));
		if(graph->nodes == NULL){
			printf("Allocation Error on graph");
			exit(1);
		};
		graph->nodes[0] = node;
		graph->size++;
	}
	else{
		graph->nodes = (gnode_t **)realloc(graph->nodes,(++graph->size)*sizeof(gnode_t));
		if(graph->nodes == NULL){
			printf("Allocation Error on ALL_NODES");
			graph->size--;
			exit(1);
		};
		graph->nodes[graph->size-1] = node;
	};
	
	return node;
	
};

bst_t* bstinsertf(bst_t* root,int val){
	
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

int has(set_t* set, int val) {
    int l = 0, r = set->size - 1, mid;

    while (l <= r) {
        mid = (l + r) / 2;

        if (set->values[mid] == val)
            return mid;

        if (set->values[mid] > val)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

void addValue(set_t* set, int val) {

    if(&(set->size) == NULL || set->size == 0) {
        set->values = (int *)malloc(sizeof(int));
        set->size = 1;
        set->values[0] = val;
        return;
    };

    if(has(set,val) != -1) return;

    set->values = (int *)realloc(set->values,sizeof(int)*(++set->size));
    set->values[set->size-1] = val;

    int index = set->size - 2,temp;

    while(set->values[index] > set->values[index+1] && index >= 0) {
        temp = set->values[index];
        set->values[index] = set->values[index+1];
        set->values[index+1] = temp;
    }

};

void setPrintf(set_t* set) {

    printf("{");
    for(int i = 0;i<set->size;i++) {
        printf("%d%s",set->values[i], i == (set->size - 1) ? "" : ", ");
    }
    printf("}\n");

}

void removeVal(set_t* set, int val) {

    int index = has(set,val);

    if(index == -1) return;

    if(index == set->size-1) {

        set->values = (int *)realloc(set->values,sizeof(int)*(--set->size));

        if(set->values == NULL) exit(1);

        return;

    };

    while(index < set->size-1) {
        set->values[index] = set->values[index+1];
        index++;
    };

    set->values = (int *)realloc(set->values,sizeof(int)*(--set->size));

    if(set->values == NULL) exit(1);

}

void freeSet(set_t* set) {

    if(set->size > 0) free(set->values);
    free(set);

}
