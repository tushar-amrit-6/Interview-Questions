//APPROACH--1
O(n^2) if skew
TreeNode *buildBST(TreeNode* &root, int ele) {
        if(!root)
            return root = new TreeNode(ele);
        
        if(root->val > ele)
            root->left = buildBST(root->left, ele);
        else
            root->right = buildBST(root->right, ele);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode *root = NULL;
        
        for(auto x : pre)
            buildBST(root, x);
        
        return root;
    }

//APPROACH--2
Check if value at pos in the current range:
if yes then left or right according to the value
if no then backtract to parent.

class Solution {  
    TreeNode *getNewnode(int val)
    {
        TreeNode *newnode = new TreeNode;
        newnode->val = val;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    
    int construct_BST(vector<int> &preorder,int n,int pos,TreeNode *curr,int left,int right)
    {
        if(pos==n || preorder[pos]<left || preorder[pos]>right) //Boundary case
            return pos;
        
        if(preorder[pos]<curr->val)     //Insert in left-subtree
        {
            curr->left = getNewnode(preorder[pos]);
            pos += 1;
            pos = construct_BST(preorder,n,pos,curr->left,left,curr->val-1);
        }
        
        if(pos==n || preorder[pos]<left || preorder[pos]>right)
            return pos;
        
        //Insert in right-subtree
        curr->right = getNewnode(preorder[pos]);
        pos += 1;
        pos = construct_BST(preorder,n,pos,curr->right,curr->val+1,right);
        return pos;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        if(n==0)
            return NULL;
        
        TreeNode *root = getNewnode(preorder[0]);
        if(n==1)
            return root;

        construct_BST(preorder,n,1,root,INT_MIN,INT_MAX);
        return root;
    }
};
