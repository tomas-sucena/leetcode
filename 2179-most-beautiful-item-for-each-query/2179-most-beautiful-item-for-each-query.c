int comparator(const void *a, const void *b) {
    int *itemA = *((int **) a), *itemB = *((int **) b);

    // compare the items by price
    return itemA[0] - itemB[0];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    // sort the items by price
    qsort(items, itemsSize, sizeof(int*), comparator);

    // determine the most beatiful item for
    // each price
    int maxBeauty = -1;

    for (int i = 0; i < itemsSize; ++i) {
        int beauty = items[i][1];

        if (maxBeauty < beauty) {
            maxBeauty = beauty;
        }
        else {
            items[i][1] = maxBeauty;
        }
    }

    // initialize the answer
    int *ans = (int *) malloc(queriesSize * sizeof(int));

    // answer the queries
    for (int i = 0; i < queriesSize; ++i) {
        // binary search
        int low = 0, upper = itemsSize - 1;

        while (low <= upper) {
            int mid = (low + upper) / 2;

            if (queries[i] < items[mid][0]) {
                upper = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        ans[i] = (low > 0)
            ? items[low - 1][1]
            : 0; // no item exists
    }

    *returnSize = queriesSize;
    return ans;
}