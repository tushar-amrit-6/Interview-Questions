Length == number of edges in the path
   class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l=0,r=0,resl=0,resr=0;
        if(node->left)
        l = dfs(node->left, lup);
       if(node->right)
        r = dfs(node->right, lup);
       if(node->left&&node->left->val == node->val)
        resl = l+1;
        if(node->right && node->right->val == node->val)
        resr = r+1;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};
