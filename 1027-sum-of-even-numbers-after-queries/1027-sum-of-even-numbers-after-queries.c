/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // compute the initial sum of even numbers
    int sum = 0;

    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i] * (nums[i] % 2 == 0);
    }

    // initialize the answer
    int *ans = malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    // apply the queries and compute
    for (int i = 0; i < queriesSize; ++i) {
        int *query = queries[i],       // pointer to the query 
            *numPtr = nums + query[1], // pointer to the affected number
            num = *numPtr;             // the affected number 

        // if the number is even, remove it from the sum
        if (num % 2 == 0) {
            sum -= num;
        }

        // update the number
        *numPtr = (num += query[0]);

        // if the updated number is even, add it to the sum
        sum += num * (num % 2 == 0);

        // update the answer
        ans[i] = sum;
    }

    return ans;
}