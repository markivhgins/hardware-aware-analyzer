#include <stdio.h>
#include <stdlib.h>
#include "runner.h"

int main(int argc, char *argv[]){

    if(argc!=4){
        printf("Usage: %s <experiment> <size> <runs>\n", argv[0]);
        return 1;
    }

const char *experiment = argv[1];
int size = atoi(argv[2]);
int runs = atoi(argv[3]);

if(size<=0 || runs<=0){
    printf("Error: size and runs must be postive numbers");
    return 1;
}

int status =  run_experiment(experiment, size, runs);

if(status!=0){
    return 1;
}

return 0;

}