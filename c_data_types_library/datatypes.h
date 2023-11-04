#ifndef _MY_LIB_
#define _MY_LIB_

// Queue

typedef struct Queue {
	int size;
	int *data;
} queue_t;

// Initializes a queue
queue_t createQueue();

// Adds value to queue
void enqueuef(queue_t* queue, int value);

// Removes and returns the removed value of the queue
int dequeuef(queue_t* queue);

// Stack

typedef struct Stack {
	int size;
	int *data;
} stack_t;

// Initializes a Stack
stack_t createStack();

// Adds value to stack
void pushf(stack_t *stack, int value);

// Removes value from stack and returns the removed value of the stack
int popf(stack_t *stack);


// Map

// [Key,Value] pair of Map
typedef struct KeyValuePair {
        char* key;
        int value;
} kvpair_t;

// Main struct of Map
typedef struct Map {
        int size;
        kvpair_t *pairs;
} map_t;

// Initializes a map
map_t *createmap();

// Removes a key and equavilent value from "kvpair_t *pairs" array
void mremove(map_t *map,char* key);

// Adds a key and equavilent value to "kvpair_t *pairs" array
void mset(map_t *map,char* key,int value);

// Equavilent value of the given key from the map
int mget(map_t *map,char* key);

// Prints the map
void mprintf(map_t *map);

//Frees the map
void mfree(map_t *map);


//Linked List

typedef struct Node{
	int val;
	struct Node* next;
} ListNode;

// Prints the linked list
void llprintf(ListNode* head);

// Adds node to the linked list
// If you don't know about this data type to much or
// If you want to shortener the code, you can use this.
// However it is not mandatory, you can use it if you want to
// or you can add nodes manually
void addNode(ListNode* head, int val);

// Adds node to the nth part of given index
// It does not remove the data if there is a
// data available in this index. In this situation,
// It inserts data before the given index
void insertNode(ListNode* head, int val, int index);

// Removes the whole list
// Head of the linked list must bi passed
// for preventing future bugs. There is another
// function for removing nodes individually
void removeList(ListNode* head /*Use for whole list*/);

// Removes nodes individually
// If you wanna remove head of the list
// you must pass the output value of the function to the
// current variable that holds the pointer of head value.
// However for any node else, you do not have to do any value passing.
// You can use this function standalone in this situations 
void *removeNode(ListNode* head, int val /*Use for a node*/);

//Graph

// Node struct for Graph
typedef struct GNode {
	int data;
	int connections;
	void *parentGraph;
	struct GNode **linkedNodes;
} gnode_t;

// Main struct for graph
typedef struct Graph {
	int size;
	gnode_t **nodes;
} graph_t;

// Initializes a graph
graph_t *createGraph();

// Removes a graph
void removeGraph(graph_t *graph);

// Creates edge between two graph nodes
void createEdge(gnode_t *node1,gnode_t *node2);

// Initializes graph node
gnode_t *createGraphNode(graph_t *graph,int data);

// Binary Search Tree - BST

typedef struct BinarySearchTree{
	unsigned short int val;
	struct BinarySearchTree* right;
	struct BinarySearchTree* left;
}bst_t;

// Adds value to the tree
bst_t* bstinsertf(bst_t* root,int val);

// Removes the tree
void bstfree(bst_t* root);

// Prints the tree
void bstprintf(bst_t* root);

//Set

typedef struct Set {
    int *values;
    int size;
} set_t;

// Adds value to the set
void addValue(set_t* set, int val);

// Returns indice of the value if it is there, if it isn't it returns -1
int has(set_t* set, int val);

// Prints the set
void setPrintf(set_t* set);

// Removes value from the set
void removeVal(set_t* set, int val);

// Removes the set
void freeSet(set_t* set);

#endif
