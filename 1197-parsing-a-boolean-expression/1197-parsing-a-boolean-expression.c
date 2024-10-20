bool recursiveDescent(const char **expressionPtr) {
    const char *expr = *expressionPtr;
    bool value;

    switch (*expr++) {
        case 't':
            value = true;
            break;

        case 'f':
            value = false;
            break;

        case '!':
            // skip the opening parenthesis
            ++expr;

            // compute the value of the subexpression
            value = !recursiveDescent(&expr);

            // skip the closing parenthesis
            ++expr;
            break;

        case '&':
            // compute the value of the subexpression
            value = true;

            do {
                // skip the opening parenthesis or comma
                ++expr;

                // compute the value of the subexpression's operand
                value &= recursiveDescent(&expr);
            }
            while (*expr == ',');
            
            // skip the closing parenthesis      
            ++expr;
            break;

        case '|': {
            // compute the value of the subexpression
            value = false;

            do {
                // skip the opening parenthesis or comma
                ++expr;

                // compute the value of the subexpression's operand
                value |= recursiveDescent(&expr);
            }
            while (*expr == ',');
            
            // skip the closing parenthesis      
            ++expr;
            break;
        }
    }

    *expressionPtr = expr;
    return value;
}

bool parseBoolExpr(char* expression) {
    return recursiveDescent(&expression);
}