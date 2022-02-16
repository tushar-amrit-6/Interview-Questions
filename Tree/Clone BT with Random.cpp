Modifying the Tree
The idea is to modify the given tree to store the cloned nodes temporarily. 
We will insert each cloned node between the current node and the left child of the current node without copying 
the random pointer of the current node. Then we will traverse the tree once again to copy the random pointers to the cloned nodes. 
And finally, we will traverse the tree once again to restore the original structure of the tree and to separate the cloned tree.
  
TreeNode<int> *changeLeftChild(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    //    Create new cloned node.
    TreeNode<int> *clone = new TreeNode<int>(root->data);

    //    Insert the cloned node between the current node and the left child.
    TreeNode<int> *leftChild = root->left;
    root->left = clone;
    clone->left = leftChild;

    //    Recur for the left subtree.
    if (leftChild != NULL)
    {
        leftChild->left = changeLeftChild(leftChild);
    }

    //    Recur for the right subtree.
    clone->right = changeLeftChild(root->right);

    return root->left;
}

//    Function for setting the random pointers of the cloned nodes.
void setRandom(TreeNode<int> *root, TreeNode<int> *clone)
{
    if (root == NULL)
    {
        return;
    }

    //    If the random node is null.
    if (root->random == NULL)
    {

        clone->random = NULL;
    }
    //    Set the left child of the random node of the current node as the random node of the cloned node.
    else
    {
        clone->random = root->random->left;
    }

    //  Recur for the left subtree.
    if (clone->left != NULL)
    {
        setRandom(root->left->left, clone->left->left);
    }

    //    Recur for the right subtree
    setRandom(root->right, clone->right);
}

//    Function to restore the structure of the original tree and the cloned tree.
void restoreTree(TreeNode<int> *root, TreeNode<int> *clone)
{
    if (root == NULL)
    {
        return;
    }

    if (clone->left == NULL)
    {
        root->left = NULL;
    }
    else
    {
        //    Remove the cloned node from the original tree.
        TreeNode<int> *leftClone = clone->left->left;
        root->left = clone->left;
        clone->left = leftClone;
    }

    //    Recur for the left and the right subtree.
    restoreTree(root->left, clone->left);
    restoreTree(root->right, clone->right);
}

TreeNode<int> *cloneBinaryTreeRandomPointer(TreeNode<int> *root)
{

    //    Insert the cloned nodes in the original tree.
    TreeNode<int> *clone = changeLeftChild(root);

    //    Set random pointers for the cloned nodes.
    setRandom(root, clone);

    //    Restore the original structure of the tree.
    restoreTree(root, clone);

    //    Return the clonde tree.
    return clone;
}

////////////////HASHMAP WALA/////////////////////////
#include <unordered_map>

//    Function to clone the tree without setting the random pointers.
TreeNode<int> *cloneTree(TreeNode<int> *root, unordered_map<TreeNode<int> *, TreeNode<int> *> &clonedNodes)
{
    if (root == NULL)
    {
        return NULL;
    }

    //    Create a new node.
    TreeNode<int> *clone = new TreeNode<int>(root->data);

    //    Insert the current node into the HashMap
    clonedNodes[root] = clone;

    //    Recur for the left and right subtrees.
    clone->right = cloneTree(root->right, clonedNodes);
    clone->left = cloneTree(root->left, clonedNodes);

    return clone;
}

//    Function for setting the random pointer of the cloned tree.
void setRandom(TreeNode<int> *root, TreeNode<int> *clone, unordered_map<TreeNode<int> *, TreeNode<int> *> &clonedNodes)
{
    if (clone == NULL)
    {
        return;
    }

    //    Set the random pointer of the cloned node using the HashMap.
    clone->random = clonedNodes[root->random];

    //    Recur for the left and the right subtrees.
    setRandom(root->left, clone->left, clonedNodes);
    setRandom(root->right, clone->right, clonedNodes);
}

TreeNode<int> *cloneBinaryTreeRandomPointer(TreeNode<int> *root)
{

    //    HashMap for storing tree nodes.
    unordered_map<TreeNode<int> *, TreeNode<int> *> clonedNodes;

    //    Clone the tree
    TreeNode<int> *clonedTree = cloneTree(root, clonedNodes);

    //    Set the random pointers
    setRandom(root, clonedTree, clonedNodes);

    //    Return the cloned tree.
    return clonedTree;
}
