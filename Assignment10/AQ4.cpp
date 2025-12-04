#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[] = {4, 5, 1, 2, 0, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    // Print array initially
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");

    int hashSize = size * 2;
    int *hashKey = (int *)calloc(hashSize, sizeof(int));
    int *hashVal = (int *)calloc(hashSize, sizeof(int));

    for (int i = 0; i < size; i++) {
        int key = abs(nums[i]) % hashSize;
        if (hashKey[key] == nums[i]) {
            hashVal[key]++;
        } else {
            hashKey[key] = nums[i];
            hashVal[key] = 1;
        }
    }

    int found = 0;
    for (int i = 0; i < size; i++) {
        int key = abs(nums[i]) % hashSize;
        if (hashVal[key] == 1) {
            printf("\nFirst non-repeating element: %d\n", nums[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nNo non-repeating element found\n");

    free(hashKey);
    free(hashVal);
    return 0;
}