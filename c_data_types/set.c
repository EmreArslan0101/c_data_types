#include <stdio.h>
#include <stdlib.h>

typedef struct Set {
	int *values;
	int size;
} set_t;

/* It returns indice of the value if it is there, if it isn't it returns -1*/
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

int main(int argc, char** argv) {

	set_t *set = malloc(sizeof(set_t));
	set->size = 0;
	if(set == NULL) return 1;
	addValue(set,2);
	addValue(set,4);
	setPrintf(set);
	freeSet(set);
	printf("\n");
	return 0;

}
