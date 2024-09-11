/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    struct ListNode *list;
    int size;
} Solution;

// initializes the solution
Solution* solutionCreate(struct ListNode* head) {
    Solution *obj = malloc(sizeof(Solution));
    obj->list = head;

    // compute the size of the linked list
    obj->size = 0;

    for (; head; head = head->next) {
        ++obj->size;
    }

    return obj;
}

// returns the value of a random node of the linked list
int solutionGetRandom(Solution* obj) {
    struct ListNode *node = obj->list;
    
    for (int n = rand() % obj->size; n; --n) {
        node = node->next;
    }

    return node->val;
}

// frees the memory allocated by the solution
void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/