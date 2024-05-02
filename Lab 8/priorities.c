#include <stdio.h>
#include <stdlib.h>

struct heap {
    int* data;
    int size;
    int capacity;
    int depth;
};

typedef struct heap* Heap;

Heap create_heap(int capacity){
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->data = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    h->depth = 0;
    return h;
}

void print_heap(Heap h){
    // print "heap of size n is as follows: "
    printf("Heap of size %d is as follows: ", h->size);
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

int parent(int i) {
    return (i - 1) / 2;
}

int left_child(int i) {
    return 2 * i + 1;
}

int right_child(int i) {
    return 2 * i + 2;
}

void add_to_heap(Heap h, int value) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (int*)realloc(h->data, h->capacity * sizeof(int));
    }
    h->data[h->size] = value;
    int chk=h->size;
    h->size++;
    while(chk>0){
        if(parent(chk)<0){
            break;
        }else if(h->data[parent(chk)]<h->data[chk]){
            int temp=h->data[parent(chk)];
            h->data[parent(chk)]=h->data[chk];
            h->data[chk]=temp;
            chk=parent(chk);
        }else{
            break;
        }
    }
}

void insert(Heap h, int value) {
    add_to_heap(h, value);
    // Complete the function here
    return;
}

int maximum(Heap h) {
    if (h->size == 0)
        return -1;  // -1 denotes that the heap is empty
    else
        return h->data[0];
}

int extract_maximum(Heap h) {
    int max = maximum(h);
    // Complete the function here
    int i=0;
    while(left_child(i)<h->size || right_child(i)<h->size){
        if(left_child(i)<h->size && right_child(i)<h->size){
            if(h->data[left_child(i)]>h->data[right_child(i)]){
                h->data[i]=h->data[left_child(i)];
                i=left_child(i);
            }else{
                h->data[i]=h->data[right_child(i)];
                i=right_child(i);
            }
        }else if(right_child(i)<h->size){
            h->data[i]=h->data[right_child(i)];
            i=right_child(i);
        }else if(left_child(i)<h->size){
            h->data[i]=h->data[left_child(i)];
            i=left_child(i);
        }
    }
    h->size--;
    return max;
}

void increase_key(Heap h, int x, int k) {
    h->data[x] = k;
    // Complete the function here
    return;
}

Heap build_max_heap(int* arr, int n){
    Heap h = create_heap(n);
    for (int i = 0; i < n; i++) {
        insert(h, arr[i]);
    }
    return h;
}

int main(){
    // int *arr = (int*)malloc(10 * sizeof(int));
    // for (int i = 0; i < 10; i++) {
    //     arr[i] = i;
    // }
    // Heap h = build_max_heap(arr,10);
    // print_heap(h);
    // for(int i=0;i<10;i++){
    //     printf("%d ",extract_maximum(h));
    //     printf("\n New size after removing max. value of heap: %d\n",h->size);
    // }
    FILE *file = fopen("playlist.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }
    while(1){
        char buffer[100];
        fscanf(file, "%[^\n]\n", buffer);
        printf("%s\n", buffer);
    }
    return 0;
}