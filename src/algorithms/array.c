#include <stdio.h>
#include <stdlib.h>

#include "../include/algorithms.h"

void run_array(int size){

    int *arr = malloc(size * sizeof(int));

    if(arr==NULL){
        return;
    }

    for(int i=0; i<size; i++){
        arr[i]=i;
    }

    long long sum=0;

    for(int i=0; i<size; i++){
        sum+=arr[i];
    }

    volatile long long temp = sum;
    (void) temp;

    free(arr);


}
