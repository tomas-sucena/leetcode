class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> aux;

        for (int i = 0; i < nums.size(); ++i){
            auto it = aux.find(target - nums[i]);

            if (it == aux.end()){
                aux[nums[i]] = i;
                continue;
            }

            return {i, it->second};
        }

        return {};
    }
};