class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        auto it = intervals.begin();

        // sort the intervals by their start time
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &lhs, const vector<int> &rhs) { return lhs[0] < rhs[0]; } );

        // push the first interval
        ans.emplace_back(*it); 

        for (; it != intervals.end(); ++it) {
            auto &last = ans.back();

            // verify if the next interval is completely within the current
            if (last.back() >= it->back()) {
                continue;
            }

            if (last.back() >= it->front()) {
                last.back() = it->back();
            }
            else {
                ans.emplace_back(*it);
            }
        }

        return ans;
    }
};