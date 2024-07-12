class Solution {
public:
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
    }
};