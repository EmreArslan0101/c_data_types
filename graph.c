#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	int connections;
	void *parentGraph;
	struct Node **linkedNodes;
} node_t;

typedef struct Graph {
	int size;
	node_t **nodes;
} graph_t;

graph_t *creategraph(){
	
	graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
	
	graph->size = 0;
	
	graph->nodes = NULL;
	
	return graph;
	
};

void removegraph(graph_t *graph){
	
	for(int i = 0;i<graph->size;i++){
		free(graph->nodes[i]);
	};
	
	free(graph);
	
};

void createedge(node_t *node1,node_t *node2){
	
	if(node1->linkedNodes == NULL){
		node1->linkedNodes = (node_t **)malloc(sizeof(node_t));
		if(node1->linkedNodes == NULL){
			printf("Allocation Error on node1");
			exit(1);
		};
		node1->linkedNodes[0] = node2;
		node1->connections++;
	}
	else{
		node1->linkedNodes = (node_t **)realloc(node1->linkedNodes,sizeof(node_t)*(++node1->connections));
		if(node1->linkedNodes == NULL){
			printf("Allocation Error on node1");
			exit(1);
		};
		node1->linkedNodes[node1->connections - 1] = node2;
	};
	
	if(node2->linkedNodes == NULL){
		node2->linkedNodes = (node_t **)malloc(sizeof(node_t));
		if(node2->linkedNodes == NULL){
			printf("Allocation Error on node2");
			exit(1);
		};
		node2->linkedNodes[0] = node1;
		node2->connections++;
	}
	else{
		node2->linkedNodes = (node_t **)realloc(node2->linkedNodes,sizeof(node_t)*(++node2->connections));
		if(node2->linkedNodes == NULL){
			printf("Allocation Error on node2");
			exit(1);
		};
		node2->linkedNodes[node2->connections - 1] = node1;
	};
	
};

node_t *createnode(graph_t *graph,int data){
	
	node_t *node = (node_t *)malloc(sizeof(node_t));
	
	if (node == NULL) {
        printf("Allocation Error on createnode");
        exit(1);
    }
	
	node->connections = 0;
	
	node->data = data;
	
	node->linkedNodes = NULL;
	
	if(graph->nodes == NULL){
		graph->nodes = (node_t **)malloc(sizeof(node_t));
		if(graph->nodes == NULL){
			printf("Allocation Error on graph");
			exit(1);
		};
		graph->nodes[0] = node;
		graph->size++;
	}
	else{
		graph->nodes = (node_t **)realloc(graph->nodes,(++graph->size)*sizeof(node_t));
		if(graph->nodes == NULL){
			printf("Allocation Error on ALL_NODES");
			graph->size--;
			exit(1);
		};
		graph->nodes[graph->size-1] = node;
	};
	
	return node;
	
};

int main(int argc, char** argv) {
	
	graph_t *graph0 = creategraph();
	
	node_t *node = createnode(graph0,4);
	node_t *_node = createnode(graph0,5);
	node_t *_node0 = createnode(graph0,6);
	
	createedge(node,_node);
	createedge(node,_node0);

	removegraph(graph0);
	return 0;
}