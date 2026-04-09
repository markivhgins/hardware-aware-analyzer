#ifndef PERF_H
#define PERF_H

typedef struct{
    long long cycles;
    long long instructions;
    long long cache_misses;
    long long branch_misses;
} PerfMetrics;

void perf_start();
PerfMetrics perf_stop();

#endif
     