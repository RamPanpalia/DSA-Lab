typedef struct student{
    char* id;
    double cg;
}student;

typedef struct student* Student;

// student createBasicStudent(char* id, float cg){
//     student s;
//     s.id=id;
//     s.cg=cg;
//     return s;
// } 

void printStudent(student s){
    printf("%s %f \n",s.id, s.cg);
}