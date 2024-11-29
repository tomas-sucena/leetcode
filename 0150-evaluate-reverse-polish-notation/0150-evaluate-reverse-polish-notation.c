struct Stack {
    int *els;
    int size, length;
};

struct Stack *stackInit(int size) {
    // initialize the object
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));

    // initialize the array that will store the elements
    stack->els = (int *) malloc(size * sizeof(int));
    stack->size = size;
    stack->length = 0;

    return stack;
}

void stackAdd(struct Stack *stack, int num) {
    // resize the stack, if needed
    if (stack->length == stack->size) {
        stack->els = realloc(stack->els, (stack->size *= 2) * sizeof(int));
    }

    // push the element
    stack->els[stack->length++] = num; 
}

int stackPop(struct Stack *stack) {
    return stack->els[--stack->length];
}

int parseNumber(char *token) {
    // parse the (optional) sign
    bool isNegative = (*token == '-');
    token += isNegative;

    // parse the number
    int num = 0;
    for (; *token; ++token) {
        num = num * 10 + (*token - '0');
    }

    return (isNegative)
        ? -num
        : num;
}

int evalRPN(char** tokens, int tokensSize) {
    // initialize the stack
    struct Stack *stack = stackInit(8);

    for (int i = 0; i < tokensSize; ++i) {
        char *token = tokens[i];

        // parse the token
        switch (*token + token[1]) {
            case '+':
                stackAdd(stack, stackPop(stack) + stackPop(stack));
                break;

            case '-': {
                int rhs = stackPop(stack);
                int lhs = stackPop(stack);

                stackAdd(stack, lhs - rhs);
                break;
            }

            case '*':
                stackAdd(stack, stackPop(stack) * stackPop(stack));
                break;

            case '/': {
                int rhs = stackPop(stack);
                int lhs = stackPop(stack);

                stackAdd(stack, lhs / rhs);
                break;
            }

            default:
                stackAdd(stack, parseNumber(token));
                break;
        }
    }

    // fetch the result
    int ans = stackPop(stack);

    // free the stack
    free(stack);

    return ans;
}