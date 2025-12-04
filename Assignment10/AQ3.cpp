#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    // Print array initially
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");

    // Hash table (key = number, value = count)
    int hashSize = size * 2;
    int *hashKey = (int *)calloc(hashSize, sizeof(int));
    int *hashVal = (int *)calloc(hashSize, sizeof(int));

    // Insert and count frequency
    for (int i = 0; i < size; i++) {
        int key = abs(nums[i]) % hashSize;
        
        // If same number already at hashed index → increment count
        if (hashKey[key] == nums[i]) {
            hashVal[key]++;
        } 
        else { // store new number + set count to 1
            hashKey[key] = nums[i];
            hashVal[key] = 1;
        }
    }

    // Print frequency result
    printf("\nFrequency of each element:\n");
    for (int i = 0; i < hashSize; i++) {
        if (hashVal[i] > 0) {
            printf("%d : %d times\n", hashKey[i], hashVal[i]);
        }
    }

    free(hashKey);
    free(hashVal);
    return 0;
}