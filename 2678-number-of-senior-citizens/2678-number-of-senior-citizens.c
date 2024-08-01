int countSeniors(char ** details, int detailsSize){
    int acc = 0;

    for (int i = 0; i < detailsSize; ++i) {
        acc += ((details[i][11] - '0') * 10 + details[i][12] - '0') > 60;
    }

    return acc;
}