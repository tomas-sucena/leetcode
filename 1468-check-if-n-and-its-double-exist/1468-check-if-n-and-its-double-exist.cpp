class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // create a hash map to count the number
        // of times each element appears in the array
        std::unordered_map<int, int> nums;

        for (int i : arr) {
            auto it = nums.find(i);
            
            if (it == nums.end()) {
                nums.emplace(i, 1);
            }
            else {
                ++it->second;
            }
        }

        // determine if the double of any element also appears in the array
        return std::any_of(arr.begin(), arr.end(), [nums](int i) {
            auto it = nums.find(2 * i);
            return it != nums.end() && it->second > (i == 0);
        });
    }
};