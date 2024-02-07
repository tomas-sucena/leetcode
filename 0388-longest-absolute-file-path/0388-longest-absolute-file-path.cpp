class Solution {
public:
    int lengthLongestPath(string input) {
        return getDepth(input.c_str(), {});
    }

    int getDepth(const char *s, std::vector<int> folders) {
        // base case
        if (*s == '\0') return 0;

        // count the tabs
        int tabs = 0;

        while (*s == '\t') {
            ++tabs;
            ++s;
        }

        for (int i = folders.size(); i > tabs; --i)
            folders.pop_back();

        // get the resource
        string resource;

        while (*s != '\0' && *s != '\n')
            resource += *s++;

        if (*s == '\n') ++s;

        // verify if the resource is a file
        if (resource.size() > 3 && resource.find('.') != std::string::npos) {
            int pathSize = 0;

            for (int i = 0; i < tabs; ++i)
                pathSize += folders[i];
            
            pathSize += resource.size();            
            return std::max(pathSize, getDepth(s, folders));
        }

        folders.emplace_back(resource.size() + 1);
        return getDepth(s, folders);
    }
};