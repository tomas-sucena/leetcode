/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    // verify if the variable is an array
    const isArray = obj instanceof Array;

    // initialize the compacted object
    const ans = isArray ? [] : {};

    for (const key in obj) {
        let value = obj[key];

        // skip falsy values
        if (!Boolean(value)) {
            continue;
        }

        // if the value is an object, compact it
        if (typeof(value) === "object") {
            value = compactObject(value);
        }

        // update the compacted object
        if (isArray) {
            ans.push(value);
        }
        else {
            ans[key] = value;
        }
    }

    return ans;
};