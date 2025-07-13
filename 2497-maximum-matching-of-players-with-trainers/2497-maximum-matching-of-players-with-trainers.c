int lessThan(const void *a, const void *b) {
    return *((const int *) a) - *((const int *) b);
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    // sort the players
    qsort(players, playersSize, sizeof(int), lessThan);

    // sort the trainers
    qsort(trainers, trainersSize, sizeof(int), lessThan);

    // match the players with the trainers
    int ans;
    int trainerIndex = 0;

    for (ans = 0; ans < playersSize; ++ans) {
        int player = players[ans];

        while (trainerIndex < trainersSize && player > trainers[trainerIndex]) {
            ++trainerIndex;
        }
        
        if (trainerIndex++ == trainersSize) {
            break;
        }
    }

    return ans;
}