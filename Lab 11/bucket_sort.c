void bucket_sort(int* A, int n){
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    int bucket[max + 1];
    for (int i = 0; i < max + 1; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[A[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max + 1; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            A[k++] = i;
        }
    }
}