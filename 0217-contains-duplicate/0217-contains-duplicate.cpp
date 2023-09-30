class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique;

        for (int i : nums)
            if (!unique.insert(i).second)
                return true;   

        return false; 
    }
};