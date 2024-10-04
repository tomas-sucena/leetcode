int lessThan(const void *a, const void *b) {
    return *((int*) a) - *((int*) b);
}

long long dividePlayers(int* skill, int skillSize) {
    // sort the players by skill
    qsort(skill, skillSize, sizeof(int), lessThan);

    // pair up the players
    int teamSkill = *skill + skill[--skillSize]; 
    long long chemistry = *skill * skill[skillSize];

    for (int i = 1; i < skillSize; ++i) {
        int currTeamSkill = skill[i] + skill[--skillSize];

        // verify if the current team meets the skill requirement
        if (currTeamSkill != teamSkill) {
            return -1;
        }

        chemistry += skill[i] * skill[skillSize];
    }

    return chemistry;
}