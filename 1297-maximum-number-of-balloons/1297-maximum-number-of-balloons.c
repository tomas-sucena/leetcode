int min(int a, int b) {
    return (a < b)
        ? a
        : b;
}

int maxNumberOfBalloons(char* text) {
    // count the occurrences of each letter
    int letters[26];

    for (; *text; ++text) {
        ++letters[*text % 'a'];
    }

    // determine how many times the word 'balloon'
    // can be formed
    return min(letters[1],          // 'b'
        min(letters[0],             // 'a' 
        min(letters['l' - 'a'] / 2, // 'l'
        min(letters['o' - 'a'] / 2, // 'o'
        letters['n' - 'a']          // 'n'
    ))));
}