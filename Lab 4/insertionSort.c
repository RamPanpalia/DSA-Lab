#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

/* Print Person Array */
void printPerson(struct person p){
    printf("ID: %d, ", p.id);
    printf("Name: %s, ", p.name);
    printf("Age: %d, ", p.age);
    printf("Height: %d, ", p.height);
    printf("Weight: %d ", p.weight);
}
void printPersonArray(struct person A[], int n){
    for (int i = 0; i < n; i++){
        printPerson(A[i]);
        printf("\n");
    }
}

/*  SORT AN ARRAY OF PERSON    */

void insertInOrderPerson(struct person x, struct person A[], int n){
    int i = n - 1;
    while (i >= 0 && A[i].height > x.height){
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
}
void insertionSortHeight(struct person A[], int n){
    for (int j = 1; j < n; j++)    {
        insertInOrderPerson(A[j], A, j);
    }
}

/* SORT AN ARRAY OF INTEGERS */

void insertInOrder(int x, int A[], int n){
    int i = n - 1;
    while (i >= 0 && A[i] > x){
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
}

void insertionSort(int A[], int n){
    for (int j = 1; j < n; j++)    {
        insertInOrder(A[j], A, j);
    }
}

int main(){
    // struct person people[5] = {
    //     {1, "Sokka", 15, 150, 45},
    //     {2, "Aang", 112, 137, 35},
    //     {3, "Zuko", 16, 160, 50},
    //     {4, "Katara", 14, 145, 38},
    //     {5, "Toph", 12, 113, 30}
    // };
    // printf("Before sorting:\n");
    // printPersonArray(people, 5);
    // insertionSortHeight(people, 5);
    // printf("After sorting:\n");
    // printPersonArray(people, 5);

    FILE *fp = fopen("dat100000.csv", "r");
    if (fp == NULL){
        printf("Error: File not found\n");
        return 1;
    }
    int n = 100000;
    struct person people[100000];
    /*
    CSV File format:
        0,Donald Scantling,39,77,231
        1,Levi Maier,56,77,129
        2,Barbara Donnelly,63,78,240
        3,Dorothy Helton,47,72,229
    */
    for (int i = 0; i < 100000; i++){
        char *buff1=malloc(110*sizeof(char));
        struct person p;
        fscanf(fp, "%d, %[^,], %d, %d, %d\n", &p.id, buff1, &p.age, &p.height, &p.weight);
        p.name=buff1;
        people[i] = p;
    }
    insertionSortHeight(people,100000);
    printPersonArray(people, 100000);

    fclose(fp);   
    return 0;
}