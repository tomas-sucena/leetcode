struct Stack {
    char **paths;           // the subpaths
    unsigned *pathLengths;  // the length of the subpaths
    unsigned size, length;  // the size and length of the stack
};

struct Stack *initStack(unsigned size) {
    struct Stack *stack = malloc(sizeof(struct Stack));
    
    // initialize the stack
    stack->paths = malloc(size * sizeof(char*));
    stack->pathLengths = malloc(size * sizeof(unsigned));
    stack->size = size, stack->length = 0;

    return stack;
}

void pushStack(struct Stack *stack, char *path, unsigned pathLength) {
    // increase the size of the arrays if needed
    if (stack->length == stack->size) {
        stack->paths = realloc(stack->paths, (stack->size *= 2) * sizeof(char*));
        stack->pathLengths = realloc(stack->pathLengths, stack->size * sizeof(unsigned));
    }

    stack->paths[stack->length] = path;
    stack->pathLengths[stack->length++] = pathLength;
}

char *popStack(struct Stack *stack) {
    return stack->length
        ? stack->paths[--stack->length]
        : NULL;
}

char* simplifyPath(char* path) {
    // initialize the stack
    struct Stack *stack = initStack(1);

    for (;;) {
        // skip slashes
        for (; *path == '/'; ++path);
        
        // verify if we have reached the end of the path
        if (*path == '\0') {
            break;
        }

        // read the next subpath
        unsigned length = 0;
        for (; path[length] && path[length] != '/'; ++length);

        // verify if the subpath is '..'
        if (length == 2 && *path == '.' && path[1] == '.') {
            // pop the last path
            popStack(stack);
        }
        // verify if the subpath is NOT '.'
        else if (length != 1 || *path != '.') {
            // copy the subpath
            char *subpath = malloc(length * sizeof(char));
            memcpy(subpath, path, length * sizeof(char));

            // push the subpath to the stack
            pushStack(stack, subpath, length);
        }

        path += length;
    }

    // create the simplified path
    if (stack->length == 0) {
        return "/";
    }

    char *ans = malloc(3000 * sizeof(char)), *temp = ans;
    *temp = '/';

    for (int i = 0; i < stack->length; ++i) {
        unsigned pathLength = stack->pathLengths[i];

        // concatenate the subpath to the simplified path
        memcpy(++temp, stack->paths[i], pathLength);

        // add a trailing slash
        temp += pathLength;
        *temp = '/';
    }

    *temp = '\0';
    return ans;
}