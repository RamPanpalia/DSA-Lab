#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "radix.c"

// Function to take input an array A and return an array B after performing
// counting sort on it with array C
int* counting_sort(int* A, int* B, int k, int n) {
    // Initialize array C with all 0s
    // int C[k];
    int* C = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        C[i] = 0;
    }

    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    return B;
}

char* cntSort(char* str){
    int cnt[26]={0};
    for(int i=0;str[i]!='\0';i++){
        cnt[str[i]-'a']++;
    }
    int k=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<cnt[i];j++){
            str[k++]='a'+i;
        }
    }
    return str;
}

// void preprocess(int* A, int* B, int k, int n){
//     int* C = (int*)malloc(k * sizeof(int));
//     for (int i = 0; i < k; i++) {
//         C[i] = 0;
//     }

//     for (int j = 0; j < n; j++) {
//         C[A[j]]++;
//     }

//     for (int i = 1; i < k; i++) {
//         C[i] = C[i] + C[i - 1];
//     }
//     for (int j = n - 1; j >= 0; j--) {
//         B[C[A[j]] - 1] = A[j];
//         C[A[j]]--;
//     }
// }

// int query(int* B, int a, int b){
//     if(B[b]-B[a-1]>0){
//         return 1;
//     }
//     return 0;
// }


// Driver code to test the above function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    // int A[n];
    int* A = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int k = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > k) {
            k = A[i];
        }
    }
    // int B[n];
    int* B = (int*)malloc(n * sizeof(int));
    int* sorted_array = counting_sort(A, B, k + 1, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");


    















    // // Task 2
    
    // FILE* file = fopen("n_integers.txt", "r");
    // if (file == NULL) {
    //     printf("File not found!\n");
    //     return 0;
    // }
    // int n1;
    // fscanf(file, "%d", &n1);
    // int* A1 = (int*)malloc(n1 * sizeof(int));
    // for (int i = 0; i < n1; i++) {
    //     fscanf(file, "%d", &A1[i]);
    //     if(A1[i]>k){
    //         k=A1[i];
    //     }
    // }
    // preprocess(A1, B, k + 1, n1);
    // int a, b;
    // printf("Enter the values of a and b: ");
    // scanf("%d %d", &a, &b);
    // int ans = query(B, a, b);
    // if (ans == 1) {
    //     printf("Yes, the picked integer falls into the range [%d, %d]\n", a, b);
    // } else {
    //     printf("No, the picked integer does not fall into the range [%d, %d]\n", a, b);
    // }
    // fclose(file);


    return 0;
}