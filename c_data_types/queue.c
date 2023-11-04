#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int size;
	int *data;
} queue_t;

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


int main(int argc, char** argv) {
	queue_t queue = createQueue();
	enqueuef(&queue,6);
	enqueuef(&queue,7);
	enqueuef(&queue,8);
	enqueuef(&queue,9);
	dequeuef(&queue);
	enqueuef(&queue,10);
	
	for (int i = 0; i < queue.size; i++) {
        printf("%d%c", queue.data[i],i<queue.size-1 ? '<' : '\0');
    }
	free(queue.data);
	return 0;
}