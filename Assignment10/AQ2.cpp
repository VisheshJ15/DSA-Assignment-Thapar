#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    // Print both arrays initially
    printf("Array A: ");
    for (int i = 0; i < sizeA; i++) printf("%d ", A[i]);
    printf("\nArray B: ");
    for (int i = 0; i < sizeB; i++) printf("%d ", B[i]);
    printf("\n");

    int hashSize = sizeA + sizeB;
    int *hash = (int *)calloc(hashSize, sizeof(int));

    for (int i = 0; i < sizeA; i++) {
        int key = abs(A[i]) % hashSize;
        hash[key] = A[i];
    }

    printf("Common Elements: ");
    int found = 0;
    for (int i = 0; i < sizeB; i++) {
        int key = abs(B[i]) % hashSize;
        if (hash[key] == B[i]) {
            printf("%d ", B[i]);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    free(hash);
    return 0;
}