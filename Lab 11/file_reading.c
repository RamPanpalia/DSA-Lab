#include <stdio.h>
#include <stdlib.h>

int main(){
    // FILE *fileo = fopen("h_indices.txt","r");
    // if(fileo==NULL){
    //     printf("Couldn't open the file\n");
    //     return 0;
    // }
    // // while loop till the file ends
    // while(!feof(fileo)){
    //     int sz;
    //     fscanf(fileo,"%d,[",&sz);
    //     int *arr = (int*)malloc(sz*sizeof(int));
    //     for(int i=0;i<sz-1;i++){
    //         fscanf(fileo,"%d, ",&arr[i]);
    //     }
    //     fscanf(fileo,"%d]",&arr[sz-1]);
    //     for(int i=0;i<sz;i++){
    //         printf("%d ",arr[i]);
    //     }
    //     printf("\n");
    // }
    // fclose(fileo);

    FILE *file = fopen("dat1000.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }
    while(!feof(file)){
        int a;
        char b[100];
        int c,d,e;
        fscanf(file, "%d,%[^,],%d,%d,%d\n", &a, b, &c, &d, &e);
        // use strtok to seperate the string into first name and last name
        char *token = strtok(b, " ");
        // printf("%d %s %d %d %d\n", a, b, c, d, e);
        int sizu=0;
        char **arr = (char**)malloc(5*sizeof(char*));
        // while(token!=NULL){
        //     printf("%s ",token);
        //     token = strtok(NULL, " ");
        // }
        while(token!=NULL){
            arr[sizu] = (char*)malloc(100*sizeof(char));
            strcpy(arr[sizu],token);
            sizu++;
            token = strtok(NULL, " ");
        }
        printf("%d ", a);
        printf("Frst Name: %s ", arr[0]);
        printf("Last Name: %s ", arr[1]);
        printf("%d %d %d\n", c, d, e);
    }
    fclose(file);

    return 0;
}