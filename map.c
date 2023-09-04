#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KeyValuePair {
	char* key;
	int value;
} kvpair_t;

typedef struct Map {
	int size;
	kvpair_t *pairs;
} map_t;

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
	
	map->pairs = (map_t *)realloc(map->pairs,sizeof(kvpair_t)*map->size);
	
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


int main(int argc, char** argv) {
	
	map_t *map = createmap();
	
	mset(map,"TEST",1);
	mset(map,"TEST",2);
	mset(map,"TEST0",4);
	
	mprintf(map);
	
	mfree(map);
	
	return 0;
	
};