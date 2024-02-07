class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        std::vector<int> folders;
        
        for (auto it = input.begin(); it != input.end();) {
            // count the tabs
            int tabs = 0;

            while (*it == '\t') {
                ++tabs;
                ++it;
            }

            for (int i = folders.size(); i > tabs; --i)
                folders.pop_back();

            // get the resource
            string resource;

            while (it != input.end() && *it != '\n')
                resource += *it++;

            if (*it == '\n') ++it;

            // verify if the resource is a file
            if (resource.size() > 3 && resource.find('.') != std::string::npos) {
                int pathSize = 0;

                for (int i = 0; i < tabs; ++i)
                    pathSize += folders[i];

                pathSize += resource.size();            
                res = std::max(res, pathSize);
                
                continue;
            }
            
            folders.emplace_back(resource.size() + 1);
        }
        
        return res;
    }
};