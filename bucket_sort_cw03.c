#include <stdio.h>
#include <stdlib.h>

// Insertion Sort for individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // Create buckets
    float buckets[n][n];  // each bucket can hold at most n elements
    int bucketCount[n];   // keep track of elements in each bucket

    for (int i = 0; i < n; i++)
        bucketCount[i] = 0;

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];  // index in bucket
        buckets[bi][bucketCount[bi]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    // Concatenate all buckets into arr[]
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");

    return 0;
}
