/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    // create a map to link each element with its ID
    const ids = new Map();

    // add the elements from the first array to the map
    arr1.forEach(el => ids.set(el.id, el));

    // create a function for merging elements
    // with the same ID
    function merge(obj1, obj2) {
        const obj = {...obj1};

        for (const key in obj2) {
            obj[key] = obj2[key];
        }

        return obj;
    }

    // add the elements from the second array to the map
    for (const el of arr2) {
        const elToMerge = ids.get(el.id);

        ids.set(el.id, elToMerge === undefined
            ? el
            : merge(elToMerge, el));
    }

    // create the joined array by appending all elements
    // in the map to a new array and sorting it
    return [...ids.values()]
        .sort((el1, el2) => el1.id - el2.id);
};