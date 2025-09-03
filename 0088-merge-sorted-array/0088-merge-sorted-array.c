void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // save a copy of the first array
    int *temp = (int *) malloc(m * sizeof(int));
    memcpy(temp, nums1, m * sizeof(int));

    // merge the arrays
    nums1Size = m;
    m = 0; n = 0;

    for (int index = 0;; ++index) {
        // copy the remainder of the second array
        if (m == nums1Size) {
            memcpy(nums1 + index, nums2 + n, (nums2Size - n) * sizeof(int));
            break;
        }
        // copy the remainder of the first array
        else if (n == nums2Size) {
            memcpy(nums1 + index, temp + m, (nums1Size - m) * sizeof(int));
            break;
        }

        nums1[index] = (temp[m] < nums2[n])
            ? temp[m++]
            : nums2[n++];
    }

    free(temp);
}