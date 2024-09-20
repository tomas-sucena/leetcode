/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    // base case
    if (n == 0) {
        return arr;
    }

    // flatten the array
    const ans = [];

    for (const el of arr) {
        if (typeof(el) !== 'object') {
            ans.push(el);
            continue;
        }

        const flattened = flat(el, n - 1);
        ans.push(...flattened);
    }

    return ans;
};