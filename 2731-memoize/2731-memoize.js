/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    // initialize the cache
    const cache = new Map();

    return function(...args) {
        // fetch the arguments
        const [a, b] = args;

        // compute the key
        // NOTE: 17 is the number of bits of 10^5
        const key = (b << 17) | a;

        // fetch the cache entry
        let entry = cache.get(key);

        // verify if the cache entry exists
        if (entry === undefined) {
            // if the entry doesn't exist,
            // compute it and store it in the cache
            entry = fn(...args);
            cache.set(key, entry);
        }

        return entry;
    }
}

// a simpler but slower solution
/* function memoize(fn) {
    // initialize the cache
    const cache = {};
    return function(...args) {
        // fetch the cache entry
        return cache[args] ??= fn(...args);
    }
} */


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
