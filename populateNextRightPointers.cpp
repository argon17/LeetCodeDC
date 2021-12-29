class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left || !root->right) return root;
        
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : nullptr;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};

// O(1) space

class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        while(cur && cur->left){
            Node* nex = cur->left;
            while(cur){
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : nullptr;
                cur = cur->next;
            }
            cur = nex;
        }
        return root;
    }
};