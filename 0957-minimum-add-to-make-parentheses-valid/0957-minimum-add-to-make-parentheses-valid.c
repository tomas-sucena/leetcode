int minAddToMakeValid(char* s) {
    int ans = 0, openParen = 0;

    for (; *s; ++s) {
        // if the current character is an open parenthesis,
        // simply increment the counter
        if (*s == '(') {
            ++openParen;
        }
        // if the current character is a closing parenthesis,
        // verify if there are any open parenthesis to close it
        else if (openParen > 0) {
            --openParen;
        }
        else {
            // there were no open parenthesis to match the closing
            // parenthesis with, so increment the answer
            ++ans;
        }
    }

    return ans + openParen;
}