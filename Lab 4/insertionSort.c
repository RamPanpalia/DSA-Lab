#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

/* Print Person Array */
void printPerson(struct person p){
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %d\n", p.height);
    printf("Weight: %d\n", p.weight);
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
    clock_t start = clock();
    printf("Start time: %ld\n", start);
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

    FILE *file = fopen("dat1000.csv", "r");
    if (file == NULL){
        printf("Error: File not found\n");
        return 1;
    }
    int n = 1000;
    struct person people[1000];
    /*
    CSV File format:
        0,Donald Scantling,39,77,231
        1,Levi Maier,56,77,129
        2,Barbara Donnelly,63,78,240
        3,Dorothy Helton,47,72,229
    */
    for (int i = 0; i < n; i++){
        struct person p;
        // read the data from the file
        fscanf(file, "%d[^,],%c[^,],%d[^,],%d[^,],%d[^,],\n", &p.id, p.name, &p.age, &p.height, &p.weight);
        printf("Read: %d,%s,%d,%d,%d\n", p.id, p.name, p.age, p.height, p.weight);
        people[i] = p;
    }
    // printPersonArray(people, 5);

    fclose(file);
    
    clock_t end = clock();
    printf("End time: %ld\n", end);   
    return 0;
}