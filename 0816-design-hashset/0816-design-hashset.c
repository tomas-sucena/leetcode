#define FREE_ENTRY INT_MIN

/**
 * @brief A hash set.
 * @param values an array for storing the values of the hash set
 * @param size the current size of the hash set
 * @param length the number of elements currently stored in the hash set
 */
typedef struct {
    int *values;
    int size, length;
} MyHashSet;

/* private functions */
void initHashSet(MyHashSet *obj, int size) {
    // initialize the array
    obj->values = malloc(size * sizeof(int));
    obj->size = size; obj->length = 0;

    // mark all entries as free
    for (int i = 0; i < size; ++i) {
        obj->values[i] = FREE_ENTRY;
    }
}

void addToHashSet(MyHashSet *obj, int key) {
    int hash = key % obj->size;

    while (obj->values[hash] != FREE_ENTRY) {
        // if the element is already in the hash set, do nothing
        if (obj->values[hash] == key) {
            return;
        }

        // linear probing
        hash = (hash + 1) % obj->size;
    }

    obj->values[hash] = key;
    ++obj->length;
}

void copyHashSet(MyHashSet *src, MyHashSet *dest) {
    for (int i = 0; i < src->size; ++i) {
        if (src->values[i] >= 0) {
            addToHashSet(dest, src->values[i]);
        }
    }
}

/* API */
MyHashSet* myHashSetCreate() {
    MyHashSet *obj = malloc(sizeof(MyHashSet));
    initHashSet(obj, 8);

    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    // create a bigger set, if needed
    if (obj->length >= 3 * obj->size / 4) {
        MyHashSet *newObj = malloc(sizeof(MyHashSet));
        initHashSet(newObj, obj->size * 2);

        // copy all elements to the new set
        copyHashSet(obj, newObj);

        // switch the hash set for the new one
        memcpy(obj, newObj, sizeof(MyHashSet));
        free(newObj);
    }

    // add the element to the hash set
    addToHashSet(obj, key);
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int hash = key % obj->size;

    while (obj->values[hash] != FREE_ENTRY) {
        // if the element is in the hash set,
        // mark its entry as a tombstone
        if (obj->values[hash] == key) {
            obj->values[hash] *= -1;
            --obj->length;

            return;
        }

        // linear probing
        hash = (hash + 1) % obj->size;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int hash = key % obj->size;

    while (obj->values[hash] != FREE_ENTRY) {
        // if the element is in the hash set, return true
        if (obj->values[hash] == key) {
            return true;
        }

        // linear probing
        hash = (hash + 1) % obj->size;
    }

    return false;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->values);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/