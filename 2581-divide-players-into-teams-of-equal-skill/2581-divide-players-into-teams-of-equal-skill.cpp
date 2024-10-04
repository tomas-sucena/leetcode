class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // pair up the strongest player with the weakest
        int weakest = INT_MAX, strongest = INT_MIN;

        for (int i : skill) {
            weakest = min(i, weakest);
            strongest = max(i, strongest);
        }

        // compute the skill of this team
        int teamSkill = weakest + strongest;
        
        // create a hash map for storing the number of players
        // with a particular skill
        unordered_map<int, int> playersWithSkill;

        for (int i : skill) {
            auto it = playersWithSkill.find(i);

            if (it == playersWithSkill.end()) {
                playersWithSkill.emplace(i, 1);
                continue;
            }

            ++it->second;
        }

        // attempt to match each player with another whose
        // skill adds up to the skill of the original team
        long long chemistry = 0;

        for (int i : skill) {
            int skillNeeded = teamSkill - i;
            auto it = playersWithSkill.find(skillNeeded);
            
            // if there doesn't exist a player with the required skill,
            // it is impossible to form balanced teams, so return -1
            if (it == playersWithSkill.end() || it->second == 0) {
                return -1;
            }

            --it->second;
            chemistry += i * skillNeeded;
        }

        return chemistry / 2;
    }
};