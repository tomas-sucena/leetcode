struct Row {
    int index;
    int soldiers;

    Row(int index, vector<int> &row) : index(index), soldiers(0) {
        for (int n : row)
            soldiers += n;
    }

    bool operator<(const Row &rhs) const {
        if (soldiers == rhs.soldiers)
            return index < rhs.index;

        return soldiers < rhs.soldiers;    
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<Row> rows;
        
        for (int i = 0; i < mat.size(); ++i)
            rows.insert(Row(i, mat[i]));

        vector<int> res;

        for (auto it = rows.begin(); k; --k)
            res.push_back(it++->index);

        return res;
    }
};