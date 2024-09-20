/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a = 0, b = 1;

    // first two numbers
    yield a; yield b;

    for (;;) {
        const c = a + b;
        yield c;

        // prepare the next iteration
        [a, b] = [b, c];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */