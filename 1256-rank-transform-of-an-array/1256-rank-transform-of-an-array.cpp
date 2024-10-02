class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // create a sorted copy of the array
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());

        // assign a rank to each distinct element
        unordered_map<int, int> ranks;
        int acc = 1;

        for (int el : copy) {
            // only add the element if it is not already in the map
            if (ranks.find(el) == ranks.end()) {
                ranks.emplace(el, acc++);
            }
        }

        // create the answer by replacing each element in the
        // original array with its rank
        vector<int> ans;

        for (int el : arr) {
            ans.emplace_back(ranks[el]);
        }

        return ans;
    }
};