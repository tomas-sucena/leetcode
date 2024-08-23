// The following implementation of Euclid's algorithm was taken from
// https://stackoverflow.com/questions/19738919/gcd-function-for-c
int gcd(int a, int b){
    if (a && b) for(;(a %= b) && (b %= a););
    return a | b;
}

char *parsePrefix(char *expression, int *nominator, int *denominator) {
    // parse the optional '-'
    bool negative = false;

    if (*expression == '-') {
        negative = true;
        ++expression;
    }

    // parse the nominator
    for (*nominator = 0; *expression != '/'; ++expression) {
        *nominator *= 10;
        *nominator += *expression - '0';
    }

    if (negative) {
        *nominator = -*nominator;
    }

    // skip the '/'
    ++expression;

    // parse the denominator
    for (*denominator = 0; *expression >= '0' && *expression <= '9'; ++expression) {
        *denominator *= 10;
        *denominator += *expression - '0';
    }

    return expression;
}

char *parseInfix(char *expression, int *nominator, int *denominator) {
    // parse the operator
    bool subtraction = (*expression++ == '-');
    
    // parse the second operand
    int nom, denom;
    expression = parsePrefix(expression, &nom, &denom);

    if (subtraction) {
        nom *= -1;
    }
 
    // perform the operation
    *nominator = *nominator * denom + nom * *denominator;
    *denominator *= denom;

    // reduce the fraction
    int divisor = gcd(*nominator, *denominator);

    *nominator /= divisor;
    *denominator /= divisor;

    return expression;
}

char* fractionAddition(char* expression) {
    int len = strlen(expression) + 1;

    // parse the first fraction
    int nominator, denominator;
    expression = parsePrefix(expression, &nominator, &denominator);

    // parse any infix expressions
    while (*expression) {
        expression = parseInfix(expression, &nominator, &denominator);
    }

    // if the denominator is negative,
    // change its signal
    if (denominator < 0) {
        denominator *= -1;
        nominator *= -1;
    }

    // write the fraction as a string
    char *ans = malloc(len);
    sprintf(ans, "%d/%d", nominator, denominator);

    return ans;
}