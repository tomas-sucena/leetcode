class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto it = nums.begin();
        int min = *it, max = *it++;

        for (; it != nums.end(); ++it) {
            if (*it < min)
                min = *it;
            else if (*it > max)
                max = *it;
        }

        return std::gcd(min, max);
    }
};