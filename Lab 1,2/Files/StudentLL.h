#include <stdio.h>
#include <stdlib.h>
#include "student.h"

typedef struct StudentNode {
    student student;
    struct StudentNode *next;
} StudentNode;

typedef struct StudentLL {
    StudentNode *head;
    int size;
} StudentLL;

StudentLL* createStudentLL();
student createStudent(char* id, float cg);
void addStudentFirst(StudentLL *list, student student);
void addStudentLast(StudentLL *list, student student);
void removeStudentFirst(StudentLL *list);
void removeStudentLast(StudentLL *list);
// void addStudentAfter(StudentLL *list, student* student);
void printStudentLL(StudentLL *list);

student createStudent(char* id, float cg){
    student s;
    s.id=id;
    s.cg=cg;
    return s;
}

/* Correct */
StudentNode* createStudentNode(student s){
    StudentNode* node=(StudentNode*)malloc(sizeof(StudentNode));
    node->student=s;
    node->next=NULL;
    return node;
}

/* Correct */
StudentLL* createStudentLL(){
    StudentLL* list= (StudentLL*)malloc(sizeof(StudentLL));
    list->head=NULL;
    list->size=0;
}

void addStudentFirst(StudentLL *lst, student stdnt){
    StudentNode* tmp=createStudentNode(stdnt);
    if(lst->head==NULL){
        lst->head=createStudentNode(stdnt);
        return;
    }
    tmp->next=lst->head;
    lst->head=tmp;
}

// void addStudentLast(StudentLL *lst, student stdnt){
//     StudentNode* tmp=lst->head;
//     StudentNode* tmp2=createStudent(stdnt.id, stdnt.cg);
//     if(tmp==NULL){
//         lst->head=tmp2;
//         return;
//     }
//     while(tmp->next!=NULL) tmp=tmp->next;
//     tmp->next=tmp2;
//     return;
// }

// void removeStudentFirst(StudentLL* stdnt){
//     if(stdnt->size==0) return;
//     StudentNode* tmp = stdnt->head;
//     stdnt->head=stdnt->head->next;
//     free(tmp);
// }

void printStudentLL(StudentLL* stdnt){
    StudentNode* iter=stdnt->head;
    while(iter!=NULL){
        printStudent(iter->student);
        iter=iter->next;
    }
}