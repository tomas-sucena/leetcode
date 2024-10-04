struct Node {
    int val;
    struct Node *next;
};

typedef struct {
    struct Node *head;
    unsigned length;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    // initialize the linked list
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL; obj->length = 0;

    return obj;
}

// O(n)
int myLinkedListGet(MyLinkedList* obj, int index) {
    // ensure the index is valid
    if (index >= obj->length) {
        return -1;
    }

    struct Node *node;
    for (node = obj->head; index--; node = node->next);

    return node->val;
}

// O(1)
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct Node *newHead = malloc(sizeof(struct Node));
    
    newHead->val = val;
    newHead->next = obj->head;
    obj->head = newHead;

    // increment the length of the linked list
    ++obj->length;
}

// O(n)
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    // if the linked list is empty,
    // the new tail is also the new head
    if (obj->length == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct Node *newTail = malloc(sizeof(struct Node));
    
    newTail->val = val;
    newTail->next = NULL;

    // find the tail of the linked list
    struct Node *currTail;
    for (currTail = obj->head; currTail->next; currTail = currTail->next);
    
    // add the new tail to the linked list
    currTail->next = newTail;

    // increment the length of the linked list
    ++obj->length;
}

// O(n)
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    // ensure the index is valid within the linked list
    if (index > obj->length) {
        return;
    }
    else if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    
    // initialize the new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = val;

    // find the current index^th node of the linked list
    struct Node *node;
    for (node = obj->head; --index; node = node->next);

    // add the new node to the linked list
    newNode->next = node->next;
    node->next = newNode;

    // increment the length of the linked list
    ++obj->length;
}

// O(n)
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    // ensure the index is valid within the linked list
    if (index >= obj->length) {
        return;
    }

    struct Node *node;

    // delete the head
    if (index == 0) {
        node = obj->head;
        obj->head = node->next;
    }
    else {
        // find the node that comes before the node we want to delete
        struct Node *prev;
        for (prev = obj->head; --index; prev = prev->next);

        // remove the node from the linked list
        node = prev->next;
        prev->next = prev->next->next;
    }

    // free the node
    free(node);
    
    // decrement the length of the linked list
    --obj->length;
}

void myLinkedListFree(MyLinkedList* obj) {
    // free the nodes of the linked list
    for (struct Node *curr = obj->head; curr;) {
        struct Node *temp = curr;
        curr = curr->next;

        // free the node
        free(temp);
    }

    // free the linked list
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/