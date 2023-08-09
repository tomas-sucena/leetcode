class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.empty()) return res; // special case

        // find the first occurrence
        int lower = 0;
        int upper = nums.size() - 1;

        while (lower < upper) {
            int middle = (lower + upper) / 2;

            if (nums[middle] < target)
                lower = middle + 1;
            else
                upper = middle;
        }

        if (nums[lower] != target) return res;
        res[0] = lower;

        // find the last occurrence
        upper = nums.size() - 1;

        while (lower <= upper) {
            int middle = (lower + upper) / 2;

            if (nums[middle] > target)
                upper = middle - 1;
            else
                lower = middle + 1; 
        }

        res[1] = upper;
        return res;
    }
};