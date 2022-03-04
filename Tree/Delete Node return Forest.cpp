class Solution {
public:
    unordered_set<int> um;
    
    TreeNode* find(vector<TreeNode*>& ans,TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        
        root->left  = find(ans, root->left);
        root->right = find(ans, root->right);
        
        if(um.find(root->val) != um.end())
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        um.clear();
        
        for(auto it: to_delete)
            um.insert(it);
        
        vector<TreeNode*> ans;
        root = find(ans, root);
        if(root) ans.push_back(root);
        
        return ans;
    }
};
