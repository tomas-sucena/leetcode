typedef struct {
    char *ptr;
    unsigned size;
    unsigned length;
} Array;

/*
 * Initializes an empty array.
 */
void initArray(Array *array) {
    array->size = 8;
    array->length = 0;
    array->ptr = malloc(array->size * sizeof(char));
}

/*
 * Appends an element to the end of the array.
 */
void push(Array *array, char c) {
    // append the character to the array
    array->ptr[array->length++] = c;

    // resize the array if necessary
    if (array->length == array->size) {
        array->ptr = realloc(array->ptr, array->size *= 2 * sizeof(char));
    }
}

/*
 * Removes the last element of the array and returns it.
 */
char pop(Array *array) {
    return array->length
        ? array->ptr[--array->length]
        : '\0'; // if the array is empty, return the null character
}

bool isValid(char* s) {
    _Bool valid = 1;

    // initialize the array that will store the open brackets
    Array array;
    initArray(&array);

    while (*s) {
        char c = *s++;

        switch (c) {
            case '(':
            case '[':
            case '{':
                push(&array, c);
                continue;

            case ')':
                c = '(';
                break;

            case ']':
                c = '[';
                break;

            case '}':
                c = '{';
                break;
        }

        // ensure the closing bracket matches the
        // corresponding opening bracket
        if (c != pop(&array)) {
            valid = 0;
            break;
        }
    }

    // free the memory occupied by the array
    free(array.ptr);

    // ensure the array is empty
    return valid && !array.length;
}