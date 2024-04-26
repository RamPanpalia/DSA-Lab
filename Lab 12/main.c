#include <stdio.h>

struct student{
    long long int ID;
    char name[30];
};

/*
Try the following hash functions and compare the number of collisions:
1. ID % size
2. ID % power_of_2_just_less_than_size
3. ID % a_prime_number_just_less_than_size
4. Multiplicative hash with A = 0.6180339887, m = size
5. ID % prime_less_than_0.9_times_size
6. (ID * a_prime_number_just_less_than_size) % size
*/

int hashFun1(int ID, int size) {
    return ID % size;
}

int hashFun2(int ID, int size) {
    int p = 1;
    while (p * 2 <= size) {
        p *= 2;
    }
    return ID % p;
}

int hashFun3(int ID, int size) {
    int p = size - 1;
    while (1) {
        int flag = 1;
        for (int i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            break;
        }
        p--;
    }
    return ID % p;
}

int hashFun4(int ID, int size) {
    double a = 0.6180339887;
    double frac = ID * a - (int)(ID * a);
    return (int)(size * frac);
}

int hashFun5(int ID, int size) {
    int p = size * 0.9;
    while (1) {
        int flag = 1;
        for (int i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            break;
        }
        p--;
    }
    return ID % p;
}

int hashFun6(int ID, int size) {
    int p = size - 1;
    while (1) {
        int flag = 1;
        for (int i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            break;
        }
        p--;
    }
    return (ID * p) % size;
}

struct hashTable {
    struct student *data;
    int size;
};

typedef struct hashTable hashTable;

void insert(hashTable *table, struct student s, int (*hashFun)(int, int)) {
    int index = hashFun(s.ID, table->size);
    while (table->data[index].ID != -1) {
        index = (index + 1) % table->size;
    }
    table->data[index] = s;
}

int main() {
    // read data from t1_data.txt
    FILE *fp = fopen("t1_data.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }
    int n;
    fscanf(fp, "%d", &n);
    struct student students[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%lld, %[^\n]", &students[i].ID, students[i].name);
    }
    fclose(fp);

    hashTable table1;
    table1.size = 100;
    return 0;
}