class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> halves = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> st;

        for (const char& c : s) {
            auto it = halves.find(c);

            if (it != halves.end()){
                st.push(it->second);
                continue;
            }
            
            if (st.empty() || st.top() != c)
                return false;
            
            st.pop();
        }

        return st.empty();   
    }
};