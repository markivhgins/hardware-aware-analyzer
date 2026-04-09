#define _GNU_SOURCE

#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <sys/syscall.h>
#include <string.h>

#include "../include/perf.h"

static int fd_cycles = -1;
static int fd_instructions = -1;
static int fd_cache_misses = -1;
static int fd_branch_misses = -1;

static int perf_event_open(struct perf_event_attr *hw_event){
    return syscall(__NR_perf_event_open, hw_event, 0, -1, -1, 0);
}

static long long read_counters(int fd){
    long long value = 0;
    read(fd, &value, sizeof(long long));
    return value;
}

static int setup_counter(int config){
    struct perf_event_attr pe;
    memset(&pe, 0, sizeof(pe));

    pe.type = PERF_TYPE_HARDWARE;
    pe.size = sizeof(pe);
    pe.config = config;

    pe.disabled = config;
    pe.exclude_kernel = 1;
    pe.exclude_hv = 1;

    return perf_event_open(&pe);
}

void perf_start(){
    fd_cycles=setup_counter(PERF_COUNT_HW_CPU_CYCLES);
    fd_instructions=setup_counter(PERF_COUNT_HW_INSTRUCTIONS);
    fd_cache_misses=setup_counter(PERF_COUNT_HW_CACHE_MISSES);
    fd_branch_misses=setup_counter(PERF_COUNT_HW_BRANCH_MISSES);

    ioctl(fd_cycles, PERF_EVENT_IOC_RESET,0);
    ioctl(fd_instructions, PERF_EVENT_IOC_RESET,0);
    ioctl(fd_cache_misses, PERF_EVENT_IOC_RESET,0);
    ioctl(fd_branch_misses, PERF_EVENT_IOC_RESET,0);

    ioctl(fd_cycles, PERF_EVENT_IOC_ENABLE, 0);
    ioctl(fd_instructions, PERF_EVENT_IOC_ENABLE, 0);
    ioctl(fd_cache_misses, PERF_EVENT_IOC_ENABLE, 0);
    ioctl(fd_branch_misses, PERF_EVENT_IOC_ENABLE, 0);
}

PerfMetrics perf_stop(){
    PerfMetrics m = {0};

    ioctl(fd_cycles, PERF_EVENT_IOC_DISABLE, 0);
    ioctl(fd_instructions, PERF_EVENT_IOC_DISABLE, 0);
    ioctl(fd_cache_misses, PERF_EVENT_IOC_DISABLE, 0);
    ioctl(fd_branch_misses, PERF_EVENT_IOC_DISABLE, 0);

    m.cycles = read_counters(fd_cycles);
    m.instructions = read_counters(fd_instructions);
    m.cache_misses = read_counters(fd_cache_misses);
    m.branch_misses = read_counters(fd_branch_misses);

    close(fd_cycles);
    close(fd_instructions);
    close(fd_cache_misses);
    close(fd_branch_misses);

    return m;
}