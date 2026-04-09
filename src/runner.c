#include <stdio.h>
#include <string.h>

#include "include/perf.h"
#include "include/runner.h"
#include "include/algorithms.h"
#include "include/timer.h"

int run_experiment(const char *type, int size, int runs){

    printf("=====================================\n");
    printf("Experiment: %s\n", type);
    printf("Input size:%d\n", size);
    printf("Runs:%d\n", runs);
    printf("=====================================\n");

    double total_time=0.0;

    for(int i=0; i<runs;i++){
        perf_start();
        timer_start();

        if(strcmp(type, "array")==0){
            run_array(size);
        }else if(strcmp(type,"linkedlist")==0){
            run_linkedlist(size);
        }else if(strcmp(type, "matrix_naive")==0){
            run_matrix_naive(size);
        }else if (strcmp(type, "matrix_opt") == 0){
            run_matrix_optimized(size);
        }else if (strcmp(type, "branch_pred") == 0){
            run_branch_predictable(size);
        }else if (strcmp(type, "branch_rand") == 0){
            run_branch_random(size);
        }else{
            printf("Didn't match with any experiments");
            return 1;
        }

        double elapsed = timer_stop();
        PerfMetrics m =perf_stop();
        total_time+=elapsed;

        printf("Run %d: %.3f ms | Cycles: %lld | Instructions: %lld | Cache Misses: %lld | Branch Misses: %lld\n",
         i + 1,
         elapsed,
         m.cycles,
         m.instructions,
         m.cache_misses,
         m.branch_misses);
    }

    double avg = total_time/runs;

    printf("=====================================\n");
    printf("Average Time: %.3f ms\n", avg);
    printf("=====================================\n");

    return 0;
}