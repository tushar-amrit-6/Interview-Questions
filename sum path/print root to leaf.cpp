class Solution {
public:
    
   void fun(vector<int>curr,int sum,vector<vector<int>>&v,TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left ==NULL &&root->right==NULL)
        {
            if(sum==root->val)
            {   curr.push_back(root->val);
                v.push_back(curr);
             return ;
            }
            else
                return;
        }
        curr.push_back(root->val);
        fun(curr,sum-(root->val),v,root->left);
        fun(curr,sum-(root->val),v,root->right);
        return ;


    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>v;
        vector< vector<int> > ans;
        fun(v,sum,ans,root);
        return ans;
    }
};
