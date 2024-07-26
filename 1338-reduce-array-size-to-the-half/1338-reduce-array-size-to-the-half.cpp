class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // count the number of occurrences of each element
        std::unordered_map<int, int> occurrences;

        for (int i : arr) {
            auto it = occurrences.find(i);

            if (it == occurrences.end()) {
                occurrences[i] = 1;
                continue;
            }

            ++it->second;
        }

        // sort the elements by occurrence
        vector<int> sorted(occurrences.size());
        
        for (auto &p : occurrences) {
            sorted.emplace_back(p.second);
        }

        std::sort(sorted.begin(), sorted.end());

        // count the minimum number of elements that must be removed
        // so that the size of the array is halved
        int minElements = 0;
        int half = arr.size() / 2;

        for (auto it = sorted.rbegin(); half > 0; it++) {
            half -= *it;
            ++minElements;
        }

        return minElements;
    }
};