const char *recursiveDescent(const char *expression, bool *ans, bool isSet) {
    switch (*expression++) {
        case 't':
            *ans = true;
            break;

        case 'f':
            *ans = false;
            break;

        case '!':
            expression = recursiveDescent(++expression, ans, isSet);
            *ans ^= 1;

            ++expression; // skip the closing parenthesis
            break;

        case '&': {
            bool subExpr = true;
            
            // parse the operands
            do {
                bool operand;
                expression = recursiveDescent(++expression, &operand, isSet);

                subExpr &= operand;
            }
            while (*expression == ',');
            
            // update the answer
            *ans = isSet
                ? *ans & subExpr
                : subExpr;
            
            ++expression; // skip the closing parenthesis
            break;
        }

        case '|': {
            bool subExpr = false;
            
            // parse the operands
            do {
                bool operand;
                expression = recursiveDescent(++expression, &operand, isSet);

                subExpr |= operand;
            }
            while (*expression == ',');

            // update the answer
            *ans = isSet
                ? *ans | subExpr
                : subExpr;

            ++expression; // skip the closing parenthesis
            break;
        }
    }

    isSet = true;
    return expression;
}

bool parseBoolExpr(char* expression) {
    bool ans;
    recursiveDescent(expression, &ans, false);

    return ans;
}