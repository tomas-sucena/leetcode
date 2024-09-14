void connectAux(struct Node *left, struct Node *right) {
    if (left == NULL) {
        return;
    }

    left->next = right;
    connectAux(left->left, left->right);
    connectAux(left->right, right->left);
}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
struct Node* connect(struct Node* root) {
    if (root) {
        connectAux(root->left, root->right);
        connect(root->right);
    }

    return root;
}