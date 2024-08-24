class Solution {
    double myPowCached(int n, std::unordered_map<int, double> &cache) {
        // verify if the entry is cached
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }

        // compute the value
        // and save it in cache
        int half = n / 2;
        return cache[n] = myPowCached(half, cache) * myPowCached(n - half, cache);
    }

public:
    double myPow(double x, int n) {
        // special cases
        if (n == 0 || x == 1) {
            return 1;
        }
        
        // initialize the cache
        std::unordered_map<int, double> cache;
        cache[0] = 1; cache[1] = x; cache[-1] = 1 / x;

        return myPowCached(n, cache);
    }
};
