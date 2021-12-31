class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root)[0];
    }
private:
    vector<int> helper(TreeNode* root){
        if(!root) return {0, INT_MAX, INT_MIN};
        vector<int> l = helper(root->left),
                                    r = helper(root->right);
        int mn = min({l[1], r[1], root->val});
        int mx = max({l[2], r[2], root->val});
        int ans = max({l[0], r[0], root->val - mn, mx - root->val});
        return {ans, mn, mx};
    }
};