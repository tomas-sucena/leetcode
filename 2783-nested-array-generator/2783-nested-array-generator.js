/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    for (const el of arr) {
        // if the element is an integer, yield it
        if (typeof(el) !== 'object') {
            yield el;
            continue;
        }

        // if the element is an array, recursively yield its elements
        yield * inorderTraversal(el);
    }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */