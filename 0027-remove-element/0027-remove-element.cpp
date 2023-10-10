class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        vector<int> res;
        
        for (int i : nums) {
            if (i == val)
                --k;
            else 
                res.push_back(i);
        }
        
        nums = std::move(res);        
        return k;
    }
};