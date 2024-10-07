int minLength(char *s){
    char stack[50], *stackTop = stack;
    int length = 0;

    for (; *s; ++s, ++length) {
        char c = *s;

        switch (c) {
            case 'A':
            case 'C':
                // push the character to the stack
                *stackTop++ = c + 1;
                break;

            case 'B':
            case 'D':
                // pop the stack and verify if the character is the expected
                if (stackTop > stack && *--stackTop == c) {
                    length -= 2;
                    break;
                }

            default:
                // clear the stack
                stackTop = stack;
        }
    }

    return length;    
}