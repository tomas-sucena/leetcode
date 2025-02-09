/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // special case: empty list
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, int> nodes;
        vector<Node*> newNodes;

        // O(n)
        for (int index = 0; head; ++index, head = head->next) {
            nodes.emplace(head, index);
            newNodes.emplace_back(new Node{head->val, head->next, head->random});
        }

        // build the linked list
        // O(n)
        for (auto it = newNodes.begin(); it != newNodes.end();) {
            Node *node = *it++;

            // set the 'next' attribute
            if (node->next) {
                node->next = *it;
            }

            // set the 'random' attribute
            if (node->random) {
                node->random = newNodes[nodes.at(node->random)];
            }
        }

        return newNodes.front();
    }
};