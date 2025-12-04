#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsDuplicate(int* nums, int numsSize) {
    int hashSize = numsSize * 2;
    int* hash = (int*)calloc(hashSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int key = abs(nums[i]) % hashSize;

        if (hash[key] == nums[i]) {   // Found duplicate
            free(hash);
            return true;
        }
        hash[key] = nums[i];
    }

    free(hash);
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    // Print the array initially
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Check duplicate
    if (containsDuplicate(nums, size))
        printf("Contains duplicate: true");
    else
        printf("Contains duplicate: false");

    return 0;
}