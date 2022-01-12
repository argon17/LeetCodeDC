class Solution {
public:
        int sumRootToLeaf(TreeNode* root, int val = 0) {
            if (!root) return 0;
            val = (val * 2 + root->val);
            // root->left == root->right => A very nice way to check if it's a leaf node.
            // if it's a leaf node, no recursive call further.
            return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};