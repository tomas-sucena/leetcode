#define PRICE  0
#define BEAUTY 1

int comparator(const void *a, const void *b) {
    // fetch the items
    int *itemA = *((int **) a), *itemB = *((int **) b);

    // compare the items by price
    return itemA[PRICE] - itemB[PRICE];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
    // sort the items by price
    qsort(items, itemsSize, sizeof(int*), comparator);

    // determine, for each item, the most beautiful
    // item that isn't more expensive
    int maxBeauty = -1;

    for (int i = 0; i < itemsSize; ++i) {
        int beauty = items[i][BEAUTY];

        if (maxBeauty < beauty) {
            maxBeauty = beauty;
        }
        else {
            items[i][BEAUTY] = maxBeauty;
        }
    }

    // initialize the answer
    int *ans = (int *) malloc(queriesSize * sizeof(int));

    // answer the queries
    for (int i = 0; i < queriesSize; ++i) {
        // binary search
        int lower = 0, upper = itemsSize - 1;

        while (lower <= upper) {
            int mid = (lower + upper) / 2;

            if (queries[i] < items[mid][PRICE]) {
                upper = mid - 1;
            }
            else {
                lower = mid + 1;
            }
        }

        ans[i] = (upper < 0)
            ? 0 // no item exists
            : items[upper][BEAUTY];
    }

    *returnSize = queriesSize;
    return ans;
}