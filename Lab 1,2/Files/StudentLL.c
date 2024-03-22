#include <stdio.h>
#include <stdlib.h>

#include "studentLL.h"

int main(){
    // FILE *file = fopen("data.txt", "r");

    // if (file == NULL) {
    //     printf("File not found\n");
    //     return 1;
    // }
    // StudentLL *studentList = (StudentLL*)malloc(sizeof(StudentLL));

    StudentLL* stdll = createStudentLL();
    char* chr=(char*)malloc(50*sizeof(char));
    chr="Ram Panpalia";
    float cg=9.98;
    addStudentFirst(stdll,createStudent(chr,cg));
    printStudentLL(stdll);

    return 0;
}