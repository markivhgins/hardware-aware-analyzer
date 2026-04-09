#include <stdlib.h>
#include <stdio.h>

#include "../include/algorithms.h"

static int init_matrices(int n, int **A, int **B, int **C) {
    *A = malloc(n * n * sizeof(int));
    *B = malloc(n * n * sizeof(int));
    *C = malloc(n * n * sizeof(int));

    if (!(*A) || !(*B) || !(*C)) {
        return 0; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*A)[i*n + j] = i + j;
            (*B)[i*n + j] = i - j;
            (*C)[i*n + j] = 0;
        }
    }

    return 1;
}


static void free_matrices(int *A, int *B, int *C) {
    free(A);
    free(B);
    free(C);
}

void run_matrix_naive(int n) {
    int *A, *B, *C;

    if (!init_matrices(n, &A, &B, &C)) {
        return;
    }
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i*n + j] += A[i*n + k] * B[k*n + j];
            }
        }
    }

    volatile int temp = C[0];
    (void) temp;

    free_matrices(A, B, C);

}

void run_matrix_optimized(int n) {
    int *A, *B, *C;

    if (!init_matrices(n, &A, &B, &C)) {
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i*n + j] += A[i*n + k] * B[k*n + j];
            }
        }
    }

    volatile int temp = C[0];
    (void)temp;

    free_matrices(A, B, C);
}