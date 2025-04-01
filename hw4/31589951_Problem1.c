#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// Radix Sort for unsigned number
void radix_sort(unsigned int A[], unsigned int n) {
    unsigned int bucket0[SIZE], bucket1[SIZE];
    unsigned int mask, count0, count1;

    for (int d = 0; d < 32; d++) {
        mask = 1 << d;
        count0 = count1 = 0;

        // Classify bits
        for (int i = 0; i < n; i++) {
            if ((A[i] & mask) == 0) {
                bucket0[count0++] = A[i];
            } else {
                bucket1[count1++] = A[i];
            }
        }

        // joining buckets
        for (int i = 0; i < count0; i++) {
            A[i] = bucket0[i];
        }
        for (int i = 0; i < count1; i++) {
            A[count0 + i] = bucket1[i];
        }
    }
}

// signed num
void radix_sort_floats(float A[], int n) {
    unsigned int intArray[SIZE];
    
    //  float to  unsigned int 
    for (int i = 0; i < n; i++) {
        unsigned int *p = (unsigned int *)&A[i];
        intArray[i] = *p ^ ((A[i] < 0) ? 0xFFFFFFFF : 0x80000000);
    }
    radix_sort(intArray, n);

    //reconstruct float
    for (int i = 0; i < n; i++) {
        unsigned int *p = (unsigned int *)&A[i];
        *p = intArray[i] ^ ((A[i] < 0) ? 0xFFFFFFFF : 0x80000000);
    }
}

int main() {
    int n;
    float A[SIZE];

    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    if (n < 1 || n > SIZE) {
        printf("Err: Out of range.\n");
        return 1;
    }

    printf("Enter  %d real nums:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &A[i]);
    }

    radix_sort_floats(A, n);

    printf("\nOrdered sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\n", A[i]);
    }

    return 0;
}
