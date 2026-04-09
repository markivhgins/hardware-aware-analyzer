#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include "../include/timer.h"

static struct timespec start_time;

int timer_start(){
    clock_gettime(CLOCK_MONOTONIC, &start_time);
}

double timer_stop(){
    struct timespec end_time;

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    double seconds = end_time.tv_sec - start_time.tv_sec;
    double nanoseconds = end_time.tv_nsec - start_time.tv_nsec;

    if (nanoseconds < 0) {
        seconds -= 1;
        nanoseconds += 1000000000;
    }

    double elapsed_ms = (seconds/1000.0) + (nanoseconds/1e6);

     return elapsed_ms;
}
