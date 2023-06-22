class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lower = 0;
        int upper = (int) nums.size() - 1;

        while (lower <= upper) {
            int middle = (upper + lower) / 2;
            
            if (nums[middle] < target) {
                lower = middle + 1;
                continue;
            }
            else if (nums[middle] > target) {
                upper = middle - 1;
                continue;
            }

            return middle;
        }

        return lower;
    }
};