class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::unordered_map<int, int> nums;

        for (int i : target) {
            ++nums[i];
        }

        // verify if every 'arr' has the same elements
        // as 'target', irrespective of their order
        for (int i : arr) {
            auto it = nums.find(i);

            if (it == nums.end()) {
                return false;
            }

            --it->second;
        }

        return std::none_of(nums.begin(), nums.end(),
            [](const auto &p) { return p.second > 0; });
    }
};