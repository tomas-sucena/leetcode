/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    // initialize the cache
    const cache = {};

    return function(...args) {
        // fetch the cache entry
        return cache[args] ??= fn(...args);
    }
}


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