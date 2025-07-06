// the sorting function
int lessThan(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

// returns the absolute value of a number
int abs(int x) {
    return (x > 0) ? x : -x;
}

// returns the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// returns the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// removes all duplicate elements in an array and returns the updated size
int removeDuplicates(int *arr, int arrSize) {
    int newSize = 0;

    for (int i = 0; i < arrSize; ) {
        int curr = arr[i++];
        arr[newSize++] = curr;

        // skip equal elements
        for (; i < arrSize && arr[i] == curr; ++i);
    }

    return newSize;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    // sort the houses
    qsort(houses, housesSize, sizeof(int), lessThan);
    housesSize = removeDuplicates(houses, housesSize);

    // sort the heaters
    qsort(heaters, heatersSize, sizeof(int), lessThan);
    heatersSize = removeDuplicates(heaters, heatersSize);

    // compute the minimum heat radius
    int ans = 0;
    int houseIndex = 0, heaterIndex = 0;

    for (; houseIndex < housesSize; ++houseIndex) {
        int house = houses[houseIndex];

        // find the heater that is closest to the house
        for (; heaterIndex < heatersSize; ++heaterIndex) {
            int heater = heaters[heaterIndex];
            int nextHeater = heaters[min(heaterIndex + 1, heatersSize - 1)];
            int distToHeater = abs(house - heater);

            if (distToHeater <= abs(house - nextHeater)) {
                ans = max(ans, distToHeater);
                break;
            }
        }
    }

    return ans;
}