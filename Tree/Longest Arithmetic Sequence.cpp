/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int maxS = 0;
void dfs(Tree* root, int diff, int l) {
    maxS = max(maxS, l);
    if (!root) {
        return;
    }
    if (root->left) {
        if (root->left->val - root->val == diff) {
            dfs(root->left, diff, l + 1);
        } else {
            dfs(root->left, root->left->val - root->val, 2);
        }
    }
    if (root->right) {
        if (root->right->val - root->val == diff) {
            dfs(root->right, diff, l + 1);
        } else {
            dfs(root->right, root->right->val - root->val, 2);
        }
    }
}
int solve(Tree* root) {
    if (root) {
        maxS = 1;
    } else {
        return 0;
    }
    dfs(root, 0, 1);
    return maxS;
}
