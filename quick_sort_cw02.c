#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int st, int end) {
    int pivot = arr[end];
    int idx = st - 1;

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(&arr[j], &arr[idx]);
        }
    }

    idx++;
    swap(&arr[end], &arr[idx]);
    return idx;
}

void quickSort(int arr[], int st, int end) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx - 1);  
        quickSort(arr, pivIdx + 1, end);  
    }
}

int main() {
    int arr[] = {5, 1, 3, 9, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
