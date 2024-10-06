/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const ans = {};
    
    for (const el of this) {
        // compute the key
        const key = fn(el);

        // initialize the entry, if it doesn't exist
        if (ans[key] === undefined) {
            ans[key] = [];
        }
        
        // add the element to the entry
        ans[key].push(el);
    }

    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */