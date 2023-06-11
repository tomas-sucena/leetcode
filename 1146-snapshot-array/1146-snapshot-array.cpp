class SnapshotArray {
private:
    int curr;
    vector<unordered_map<int, int>> snapshots;

public:
    SnapshotArray(int length) : curr(0) {
        snapshots.resize(length);

        for (int i = 0; i < length; ++i)
            snapshots[i][curr] = 0;
    }
    
    void set(int index, int val) {
        snapshots[index][curr] = val;
    }
    
    int snap() {
        return curr++;
    }
    
    int get(int index, int snap_id) {
        auto &el = snapshots[index];

        for (int i = snap_id; i >= 0; --i) {
            auto it = el.find(i);
            if (it == el.end()) continue;

            return it->second;
        }

        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */