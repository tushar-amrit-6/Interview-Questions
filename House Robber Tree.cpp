class Solution {
public:
    map<TreeNode*, int> memo;
    
    int rob(TreeNode* root) {
        // non-existent node contributes 0 to robbed amount
		if(root == NULL) return 0;
		// Since there are repeated subproblems (a node calculates for its left and right children 
		// whereas the grandparent node may already have initiatied the same computation)
		// , thus we check if value for this node has already been calculated.
        if(memo[root]) return memo[root];
        
		// use accumulating variable for readability
        int val = 0;
		
		// left child's children
        if(root->left)
            val += rob(root->left->left) + rob(root->left->right);

		// right child's children
        if(root->right)
            val += rob(root->right->left) + rob(root->right->right);
        
        memo[root] = max(
            root->val + val, // take current node and its left & right grandchildren
			// OR
            rob(root->left) + rob(root->right) // leave current node and take its left and right children
			);
        
		// return value after memoizing
        return memo[root];
    }
};


/////////////////////////////////////////////////////////////////////////////

class Solution {
private:
    int rob(TreeNode* root, int &robMax, int &notRobMax) {
        if (!root) return 0;
        int leftRobMax = 0, leftNotRobMax = 0, rightRobMax = 0, rightNotRobMax = 0;
        int leftMax = rob(root->left, leftRobMax, leftNotRobMax);
        int rightMax = rob(root->right, rightRobMax, rightNotRobMax);
        robMax = root->val + leftNotRobMax + rightNotRobMax;
        notRobMax = leftMax + rightMax;
        return max(robMax, notRobMax);
    }
public:
    int rob(TreeNode* root) {
        int robMax = 0, notRobMax = 0;
        return rob(root, robMax, notRobMax);
    }
};
