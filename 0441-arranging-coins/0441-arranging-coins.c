int arrangeCoins(int n) {
    int ans = 0;

    while (n > ans) {
        n -= ++ans;
    }

    return ans;
}