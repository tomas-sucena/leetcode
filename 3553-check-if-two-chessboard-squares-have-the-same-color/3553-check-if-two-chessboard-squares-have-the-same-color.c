bool isBlack(char *coordinate) {
    int col = coordinate[0] - 'a', row = coordinate[1] - '1';
    return (row & 1) == (col & 1);
}

bool checkTwoChessboards(char* coordinate1, char* coordinate2) {
    return isBlack(coordinate1) == isBlack(coordinate2);
}