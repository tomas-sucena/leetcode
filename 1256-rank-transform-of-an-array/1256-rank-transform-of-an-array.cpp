class Solution {
public:
    // O(n * log(n))
    vector<int> arrayRankTransform(vector<int>& arr) {
        // create a sorted copy of the array
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // assign a rank to each distinct element
        unordered_map<int, int> ranks;
        int rank = 0;
        
        for (int el : sortedArr) {
            // only assign a rank to an element if it doesn't have one
            if (ranks.find(el) == ranks.end()) {
                ranks.emplace(el, ++rank);
            }
        }

        // replace each element in the original array with its rank
        for_each(arr.begin(), arr.end(), [&ranks](int &el) {
            el = ranks[el];
        });

        return arr;
    }
};