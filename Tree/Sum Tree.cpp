bool isLeaf(TreeNode<int> *node)
{
    if (node != NULL and node->left == NULL and node->right == NULL)
    {
        return true;
    }

    return false;
}

// Finding the sum of the subtree
int sum(TreeNode<int> *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (isLeaf(node) == true)
    {
        return node->val;
    }
    else
    {
        return 2 * node->val;
    }
}

bool isSumTree(TreeNode<int> *node)
{
    // Base case
    if (node == NULL or isLeaf(node))
    {
        return true;
    }

    // Check if both left and right subtrees are sum tree
    if (isSumTree(node->left) == true and isSumTree(node->right) == true)
    {
        // Finding the sum of nodes in left and right subtree
        int leftSum = sum(node->left);
        int rightSum = sum(node->right);

        // If the given condition is satisfied, then return true else return false.
        if (leftSum + rightSum == node->val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}
