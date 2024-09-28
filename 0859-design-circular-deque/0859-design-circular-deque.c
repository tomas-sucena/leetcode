struct Element {
    int val;
    struct Element *prev, *next;
};

typedef struct {
    int size, maxSize;
    struct Element *front, *back;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    // initialize the deque
    MyCircularDeque *obj = malloc(sizeof(MyCircularDeque));
    
    obj->maxSize = k; obj->size = 0;
    obj->front = obj->back = NULL;

    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    // ensure the deque is not full
    if (obj->size == obj->maxSize) {
        return false;
    }

    ++obj->size;

    // initialize the new element
    struct Element *front = malloc(sizeof(struct Element));
    front->val = value;

    if (obj->front == NULL) {
        obj->back = front;
        front->next = NULL;
    }
    else {
        front->next = obj->front;
        obj->front->prev = front;
    }

    front->prev = NULL;
    obj->front = front;

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    // ensure the deque is not full
    if (obj->size == obj->maxSize) {
        return false;
    }

    ++obj->size;

    // initialize the new element
    struct Element *back = malloc(sizeof(struct Element));
    back->val = value;

    if (obj->back == NULL) {
        obj->front = back;
        back->prev = NULL;
    }
    else {
        back->prev = obj->back;
        obj->back->next = back;
    }

    back->next = NULL;
    obj->back = back;
    
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    // verify if the deque is empty
    if (obj->front == NULL) {
        return false;
    }

    // fix the pointers
    struct Element *front = obj->front;

    if (--obj->size == 0) {
        obj->front = obj->back = NULL;
    }
    else {
        obj->front = front->next;
    }

    // free the element
    free(front);

    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    // verify if the deque is empty
    if (obj->back == NULL) {
        return false;
    }

    // fix the pointers
    struct Element *back = obj->back;

    if (--obj->size == 0) {
        obj->front = obj->back = NULL;
    }
    else {
        obj->back = back->prev;
    }

    // free the element
    free(back);

    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return obj->front
        ? obj->front->val
        : -1;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return obj->back
        ? obj->back->val
        : -1;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->maxSize;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    // free all the elements
    for (struct Element *curr = obj->front; obj->size--; ) {
        struct Element *temp = curr;
        curr = curr->next;

        // free the element
        free(temp);
    }

    // free the deque itself
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/