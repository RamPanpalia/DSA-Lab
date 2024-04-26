void cnt_sort(int* A, int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(A[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

void radix_sort(int* A, int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        cnt_sort(A, n, exp);
    }
}

void exc_sort_helper(int *A, int n, int exp){
    int start = 0;
    int end = n - 1;
    while (start < end) {
        while ((A[start] / exp) % 10 == 0) {
            start++;
        }
        while ((A[end] / exp) % 10 == 1) {
            end--;
        }
        if (start < end) {
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }
}

void radix_exchange_sort(int* A, int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        exc_sort_helper(A, n, exp);
    }
}