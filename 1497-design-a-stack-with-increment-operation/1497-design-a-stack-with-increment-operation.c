


typedef struct {
    int *nums;
    int size, maxSize;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    // initialize the stack
    CustomStack *obj = malloc(sizeof(CustomStack));

    obj->nums = malloc(maxSize * sizeof(int));
    obj->size = 0; obj->maxSize = maxSize;

    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->size < obj->maxSize) {
        obj->nums[obj->size++] = x;
    }
}

int customStackPop(CustomStack* obj) {
    // verify if the stack is empty
    if (obj->size == 0) {
        return -1;
    }

    return obj->nums[--obj->size];
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    k = (k < obj->size)
        ? k
        : obj->size;

    for (int i = 0; i < k; ++i) {
        obj->nums[i] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/