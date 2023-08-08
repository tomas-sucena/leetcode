class Solution {
public:
    int search(vector<int>& nums, int target) {
        int upper = nums.size() - 1;
        int lower = 0;

        // find the index where the array rotates
        while (lower < upper) {
            int middle = (lower + upper) / 2;
            int next = min(middle + 1, upper);

            if (nums[middle] > nums[next]) {
                lower = next;
                break;
            }

            if (nums[middle] > nums[upper])
                lower = next;
            else
                upper = middle;
        }

        // binary search
        upper = nums.size() - 1;

        if (target > nums[upper]) {
            upper = max(lower - 1, 0);
            lower = 0;
        }

        while (lower < upper) {
            int middle = (lower + upper) / 2;

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

        return (nums[lower] == target) ? lower : -1;
    }
};