#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "intMerge.h"
#include "intMergeAux.h"

struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// void merge(int A[], int s, int mid, int e){
//     int *C = (int *)malloc(sizeof(int) * (e - s + 1));
//     mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
//     for(int i = 0; i < e - s + 1; i++){
//         A[s + i] = C[i];
//     }
//     free(C);
// }
// void mergeAux(int A[], int s1, int e1, int B[], int s2, int e2, int C[], int s3, int e3){
//     int i,j,k;
//     // Traverse both arrays
//     i=s1; j=s2; k=s3;
//     while (i <= e1 && j <= e2) {
//         // Check if current element of first array is smaller
//         // than current element of second array
//         // If yes, store first array element and increment first
//         // array index. Otherwise do same with second array
//         if (A[i] < B[j])
//             C[k++] = A[i++];
//         else
//             C[k++] = B[j++];
//     }
//     // Store remaining elements of first array
//     while (i <= e1)
//         C[k++] = A[i++];
//     // Store remaining elements of second array
//     while (j <= e2)
//         C[k++] = B[j++];
// }

// void mergeSort(int A[], int st, int en)
// {
//     if (en - st < 1) return;
//     int mid = (en-st) / 2 + st; // mid is the floor of (st+en)/2
//     mergeSort(A, st, mid); // sort the first half
//     mergeSort(A, mid + 1, en); // sort the second half
//     merge(A, st, mid, en); // merge the two halves
// }
void mergeAuxPerson(struct person A[], int s1, int e1, struct person B[], int s2, int e2, struct person C[], int s3, int e3){
    int i,j,k;
    // Traverse both arrays
    i=s1; j=s2; k=s3;
    while (i <= e1 && j <= e2) {
        // Check if current element of first array is smaller
        // than current element of second array
        // If yes, store first array element and increment first
        // array index. Otherwise do same with second array
        if (A[i].height < B[j].height)
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    // Store remaining elements of first array
    while (i <= e1)
        C[k++] = A[i++];
    // Store remaining elements of second array
    while (j <= e2)
        C[k++] = B[j++];    
}

void mergePerson(struct person A[], int s, int mid, int e){
    struct person *C = (struct person *)malloc(sizeof(struct person) * (e - s + 1));
    mergeAuxPerson(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++){
        A[s + i] = C[i];
    }
    free(C);
}

void mergeSortPerson(struct person A[], int st, int en){
    if(st>=en) return;
    int mid=(en-st)/2 + st;
    mergeSortPerson(A,st,mid);
    mergeSortPerson(A,mid+1,en);
    mergePerson(A,st,mid,en);
}

void printPerson(FILE * fp, struct person p){
    fprintf(fp,"%d, ", p.id);
    fprintf(fp,"%s, ", p.name);
    fprintf(fp,"%d, ", p.age);
    fprintf(fp,"%d, ", p.height);
    fprintf(fp,"%d ", p.weight);
}
void printPersonArray(FILE * fp, struct person A[], int n){
    for (int i = 0; i < n; i++){
        printPerson(fp, A[i]);
        fprintf(fp, "\n");
    }
}

int main(){
    FILE *fp = fopen("dat100000.csv", "r");
    if (fp == NULL){
        printf("Error: File not found\n");
        return 1;
    }
    int n = 100000;
    struct person people[100000];
    for (int i = 0; i < 100000; i++){
        char *buff1=malloc(110*sizeof(char));
        struct person p;
        fscanf(fp, "%d, %[^,], %d, %d, %d\n", &p.id, buff1, &p.age, &p.height, &p.weight);
        p.name=buff1;
        people[i] = p;
    }
    mergeSortPerson(people, 0, 99999);
    fclose(fp);
    FILE * fp1=fopen("sorted1.csv", "w+");
    printPersonArray(fp1, people, 100000);
    return 0;
}