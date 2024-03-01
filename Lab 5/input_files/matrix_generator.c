#include <stdio.h>

int main(void) {
    // Asks user for n as input and creates a square matrix of size nxn
    // populating it with random integers
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    // int matrix[n][n];
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}