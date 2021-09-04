class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0]++;
        
        int total = 0;
        helper(root, 0, sum, total, m);
        return total;
    }
    
    void helper(TreeNode *p, int cur, int sum, int &total, unordered_map<int, int> &m) {
        if (!p) return;
        
        cur += p->val;
        if (m.find(cur - sum) != m.end()) total += m[cur - sum];
        m[cur]++;
        
        helper(p->left, cur, sum, total, m);
        helper(p->right, cur, sum, total, m);
        
        m[cur]--;
    }
};
