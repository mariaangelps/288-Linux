#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

void radixSort(int arr[], int n) {
    int i, j, exp, max, bucket[16], temp[n];

    // Find max number to determine the number of digits
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (exp = 1; max / exp > 0; exp *= 16) {
        // Initialize the bucket to zero
        for (i = 0; i < 16; i++) {
            bucket[i] = 0;
        }

        // Put the elements inside the buckets
        for (i = 0; i < n; i++) {
            bucket[(arr[i] / exp) % 16]++;
        }

        // Update index
        for (i = 1; i < 16; i++) {
            bucket[i] += bucket[i - 1];
        }

        // Output array temp[] in sorted order
        for (i = n - 1; i >= 0; i--) {
            temp[bucket[(arr[i] / exp) % 16] - 1] = arr[i];
            bucket[(arr[i] / exp) % 16]--;
        }

        // Copy sorted elements into the original array
        for (i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
}

void sortAndPrint(int arr[], int n) {
    int posCount = 0, negCount = 0;
    int posArr[MAX_SIZE], negArr[MAX_SIZE];

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negArr[negCount++] = arr[i];
        } else {
            posArr[posCount++] = arr[i];
        }
    }

    // Sort both arrays separately
    radixSort(negArr, negCount);
    radixSort(posArr, posCount);

    // Print negative numbers first in descending order
    for (int i = negCount - 1; i >= 0; i--) {
        printf("%d\n", negArr[i]);
    }

    // Print positive numbers
    for (int i = 0; i < posCount; i++) {
        printf("%d\n", posArr[i]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    // Prompt the user to enter the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Check if the number of integers is valid
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of integers. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Prompt the user to enter the integers
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array and print it
    printf("Sorted integers:\n");
    sortAndPrint(arr, n);

    return 0;
}

