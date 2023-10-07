class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long acc = 0;

        std::unordered_map<double, long> ratios;
        for (int i = 0; i < rectangles.size(); ++i) {
            auto it = ratios.insert({double(rectangles[i][0]) / double(rectangles[i][1]), 0}).first;
            if (!it->second++) continue;

            acc += it->second - 1;
        }
            
        return acc;
    }
};