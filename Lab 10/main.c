#include <stdio.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(int Ls[], int i, int j) {
    int temp = Ls[i];
    Ls[i] = Ls[j];
    Ls[j] = temp;
}

int select(int L[], int n, int k) {
    if (k == 0) return L[0];
    if (n <= 5) {
        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                if (L[j] > L[j + 1])
                    swap(L, j, j + 1);
                else
                    break;
        return L[k - 1];
    }
    // partition L into subsets of five elements each
    // (there will be n/5 subsets total).
    int numGroups;
    if (n % 5 == 0)
        numGroups = n / 5;
    else
        numGroups = n / 5 + 1;
    // int medians[numGroups];
    int *medians = (int *)malloc(numGroups * sizeof(int));
    for (int i = 0; i < numGroups; i++) {
        medians[i] =
            select(L + i * 5, min(5, n - i * 5), min(5, n - i * 5) / 2);
    }
    int M = select(medians, numGroups, (numGroups + 1) / 2);
    // Partition array into two halves, L1, {M} and L2, such that
    // L1 contains elements <= M, {M} contains one instance of M and L2
    // contains all elements > M
    int mInd;
    for (int i = 0; i < n; i++) {
        if (L[i] == M) {
            mInd = i;
            break;
        }
    }
    int pInd = part(L, 0, n - 1, mInd);
    if (k <= pInd)
        return select(L, pInd, k);
    else if (k > pInd + 1)
        return select(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return L[pInd];
}

int qselect(int L[], int n, int k) {
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = part(L, lo, hi, pivot);
    if (k <= pInd)
        return qselect(L, pInd, k);
    else if (k > pInd + 1)
        return qselect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return L[pInd];
}

int part(int Ls[], int lo, int hi, int pInd) {
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt) {
        for (; lt <= hi && Ls[lt] <= pv; lt++)
            ;
        for (; Ls[rt] > pv; rt--)
            ;
        if (lt < rt) {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
    return pivPos;
}

int lomutoPart(int Ls[], int lo, int hi, int pInd) {
    swap(Ls, pInd, hi);
    int pivot = Ls[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (Ls[j] <= pivot) {
            i++;
            swap(Ls, i, j);
        }
    }
    swap(Ls, i + 1, hi);
    return i + 1;
}

int threePart(int Ls[], int lo, int hi, int pInd) {
    swap(Ls, pInd, hi - 1);
    int pivPos, lt, rt, mid, pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = Ls[hi - 1];
    while (mid <= rt) {
        if (Ls[mid] < pv) {
            swap(Ls, lt, mid);
            lt++;
            mid++;
        } else if (Ls[mid] > pv) {
            swap(Ls, mid, rt);
            rt--;
        } else {
            mid++;
        }
    }
    swap(Ls, mid, hi - 1);
    return mid;
}

void swapPerson(struct person Ls[], int i, int j) {
    struct person temp = Ls[i];
    Ls[i] = Ls[j];
    Ls[j] = temp;
}

int partPerson(struct person Ls[], int lo, int hi, int pInd) {
    swapPerson(Ls, pInd, lo);
    int pivPos, lt, rt;
    lt = lo + 1;
    rt = hi;
    int pv = Ls[lo].height;
    while (lt < rt) {
        for (; lt <= hi && Ls[lt].height <= pv; lt++)
            ;
        for (; Ls[rt].height > pv; rt--)
            ;
        if (lt < rt) {
            swapPerson(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt].height < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swapPerson(Ls, lo, pivPos);
    return pivPos;
}

int lomutoPartPerson(struct person Ls[], int lo, int hi, int pInd) {
    swapPerson(Ls, pInd, hi);
    int pivot = Ls[hi].height;
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (Ls[j].height <= pivot) {
            i++;
            swapPerson(Ls, i, j);
        }
    }
    swapPerson(Ls, i + 1, hi);
    return i + 1;
}

int threePartPerson(struct person Ls[], int lo, int hi, int pInd) {
    swapPerson(Ls, pInd, hi - 1);
    int pivPos, lt, rt, mid;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    int pv = Ls[hi - 1].height;
    while (mid <= rt) {
        if (Ls[mid].height < pv) {
            swapPerson(Ls, lt, mid);
            lt++;
            mid++;
        } else if (Ls[mid].height > pv) {
            swapPerson(Ls, mid, rt);
            rt--;
        } else {
            mid++;
        }
    }
    swapPerson(Ls, mid, hi - 1);
    return mid;
}

void segregateZeroAndOne(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        while (a[left] == 0 && left < right) {
            left++;
        }
        while (a[right] == 1 && left < right) {
            right--;
        }

        if (left < right) {
            a[left] = 0;
            a[right] = 1;
            left++;
            right--;
        }
    }
}

void quicksort(int Ls[], int lo, int hi, int pInd, int method) {
    if (lo < hi) {
        int pivPos;
        if (method == 1) {
            pivPos = part(Ls, lo, hi, pInd);
        } else if (method == 2) {
            pivPos = lomutoPart(Ls, lo, hi, pInd);
        } else if (method == 3) {
            pivPos = threePart(Ls, lo, hi, pInd);
        }
        quicksort(Ls, lo, pivPos - 1, pInd, method);
        quicksort(Ls, pivPos + 1, hi, pInd, method);
    }
}

void quicksortPerson(struct person Ls[], int lo, int hi, int pInd, int method) {
    if (lo < hi) {
        int pivPos;
        if (method == 1) {
            pivPos = partPerson(Ls, lo, hi, pInd);
        } else if (method == 2) {
            pivPos = lomutoPartPerson(Ls, lo, hi, pInd);
        } else if (method == 3) {
            pivPos = threePartPerson(Ls, lo, hi, pInd);
        }
        quicksortPerson(Ls, lo, pivPos - 1, pInd, method);
        quicksortPerson(Ls, pivPos + 1, hi, pInd, method);
    }
}

int main() {
    // TASK 1
    // FILE *file = fopen("dat1000.csv", "r");
    // if (file == NULL) {
    //     printf("Failed to open the file.\n");
    //     return 1;
    // }

    // // count the number of lines in the file
    // int numLines = 0;
    // char ch;
    // while ((ch = fgetc(file)) != EOF) {
    //     if (ch == '\n') {
    //         numLines++;
    //     }
    // }
    // rewind(file);

    // struct person persons[numLines];

    // // read the data from the file into the array
    // for (int i = 0; i < numLines; i++) {
    // fscanf(file, "%d,%[^,],%d,%d,%d\n", &persons[i].id, persons[i].name,
    // &persons[i].age, &persons[i].weight, &persons[i].height);
    // }

    // // close the file
    // fclose(file);

    // // use part and threePart on the array
    // int lo = 0;
    // int hi = numLines - 1;
    // int pInd = 0;

    // int pivPos = partPerson(persons, lo, hi, pInd);
    // printf("Partition position: %d\n", pivPos);

    // pivPos = threePartPerson(persons, lo, hi, pInd);
    // printf("Three partition position: %d\n", pivPos);

    // TASK 2
    // int arr[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // segregateZeroAndOne(arr, size);

    // printf("Segregated array: ");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    // TASK 3

    return 0;
}