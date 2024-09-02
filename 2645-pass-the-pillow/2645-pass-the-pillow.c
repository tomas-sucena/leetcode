int passThePillow(int n, int time) {
    // determine the direction in which the pillow
    // will be passed around during the final round
    bool rightToLeft = (time / --n) & 1;
    time %= n;

    // NOTE: The +1 is required because indices start from 1
    // in this exercise.
    return 1 + (rightToLeft
        ? n - time
        : time);
}