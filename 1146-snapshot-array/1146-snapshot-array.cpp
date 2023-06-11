class SnapshotArray {
private:
    int curr;
    vector<vector<pair<int, int>>> snapshots;

public:
    SnapshotArray(int length) : curr(0) {
        for (int i = 0; i < length; ++i)
            snapshots.push_back({make_pair(curr, 0)});
    }
    
    void set(int index, int val) {
        auto &el = snapshots[index];

        if (el.back().first < curr)
            el.emplace_back(curr, 0);

        el.back().second = val;
    }
    
    int snap() {
        return curr++;
    }
    
    int get(int index, int snap_id) {
        auto &el = snapshots[index];
        
        // special case
        if (el.back().first <= snap_id)
            return el.back().second;
        
        // binary search
        int upper = (int) el.size() - 1;
        int lower = 0;
        
        int middle = (upper + lower) / 2;

        for (; lower <= upper; middle = (upper + lower) / 2) {
            if (el[middle].first <= snap_id)
                lower = middle + 1;
            else
                upper = middle - 1;
        }

        return el[middle].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */