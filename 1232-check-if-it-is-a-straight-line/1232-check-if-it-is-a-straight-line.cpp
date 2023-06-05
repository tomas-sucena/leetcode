class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 2) return false;

        int delta_x = coordinates[1][0] - coordinates[0][0];

        if (!delta_x){
            // vertical line
            for (int i = 2; i < coordinates.size(); ++i) {
                if (coordinates[i][0] != coordinates[0][0])
                    return false;
            }

            return true;
        }

        // y = mx + b
        float m = (float) (coordinates[1][1] - coordinates[0][1]) / delta_x;
        float b = (float) coordinates[0][1] - m * coordinates[0][0];

        for (int i = 1; i < coordinates.size(); ++i) {
            if (m * coordinates[i][0] + b != coordinates[i][1])
                return false;
        }

        return true;
    }
};