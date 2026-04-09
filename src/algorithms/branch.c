#include <stdlib.h>

#include "../include/algorithms.h"

void run_branch_predictable(int size){
    long long sum=0;

    for(int i=0;i<size;i++){
        if(i%2==0){
            sum+=i;
        } else {
            sum-=i;
        }
    }

    volatile long long temp = sum;
    (void) temp;
}

void run_branch_random(int size){
    long long sum=0;

    for(int i =0; i<size;i++){
        if(rand()%2==0){
            sum+=i;
        }else{
            sum-=i;
        }
    }

    volatile long long temp = sum;
    (void) temp;
}