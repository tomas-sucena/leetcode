void mergeSort(int *nums, int size, int *array) {
    // if the array has one element,
    // it is sorted
    if (size == 1) {
        return; 
    }

    int half = size / 2;

    mergeSort(nums, half, array);                      // sort the first half
    mergeSort(nums + half, size - half, array + half); // sort the second half

    // merge the halves
    int i = 0, j = half;

    for (;;) {
        // first half fully merged
        if (i == half) {
            while (j < size) {
                *array++ = nums[j++];
            }

            break;
        }
        // second half fully merged
        else if (j == size) {
            while (i < half) {
                *array++ = nums[i++];
            }

            break;
        }

        *array++ = (nums[i] < nums[j])
            ? nums[i++]
            : nums[j++];
    }

    memcpy(nums, array - size, size * sizeof(int));
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int *array = malloc(numsSize * sizeof(int));
    memcpy(array, nums, numsSize * sizeof(int));

    // sort the array
    mergeSort(nums, numsSize, array);

    *returnSize = numsSize;
    return array;
}