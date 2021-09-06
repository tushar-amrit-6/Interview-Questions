Node* merge(Node* a, Node* b)
{
     
    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;
 
    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;
 
    // Compare the data members of the two linked
    // lists and put the larger one in the result
    Node* result;
 
    if (a->data < b->data)
    {
        result = a;
        result->down = merge(a->down, b);
    }
 
    else
    {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}
 
Node* flatten(Node* root)
{
     
    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;
 
    // Recur for list on right
    root->right = flatten(root->right);
 
    // Now merge
    root = merge(root, root->right);
 
    // Return the root
    // it will be in turn merged with its left
    return root;
}
