#include <stdio.h>
#include <stdlib.h>

#include "student.h"

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }
    student* studentList = (student*)malloc(10000*sizeof(student));
    int iter=0;
    while(iter!=10001) {
        studentList[iter].id=(char*)malloc(16*sizeof(char));
        fscanf(file, "%[^,], %lf", studentList[iter].id, &studentList[iter].cg);
        iter++;
    }
    fclose(file);
    file = fopen("data2.txt", "w+");
    for(int i=0; i<iter-1; i++) {
        fprintf(file, "%s, %.15f \n", studentList[i].id, studentList[i].cg);
    }
    fclose(file);
    printf("Data copied to data2.txt");
    return 0;
}