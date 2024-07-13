class Solution {
public:
    void binarySearch(vector<int>& nums, int& index) {
        int num = nums[index];
        int lower = index, upper = nums.size() - 1;

        while (lower <= upper) {
            int middle = (lower + upper) / 2;

            if (nums[middle] == num) {
                lower = middle + 1;
            }
            else {
                upper = middle - 1;
            }
        }

        // update the index
        index = upper;
    }

    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int unique = 0;

        while (index < nums.size()) {
            // search for the highest index where containing the current number
            binarySearch(nums, index);
            nums[unique++] = nums[index++];
        }

        return unique;
    }

    /**
    // my original solution
    int removeDuplicates(vector<int>& nums) {
        int unique = 1;
        int prev = nums[0];

        for (int num : nums) {
            if (num == prev) {
                continue;
            }

            nums[unique++] = num;
            prev = num;
        }

        return unique;
    }**/
};