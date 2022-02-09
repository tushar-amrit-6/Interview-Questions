//Pre + Inorder
struct Node* buildTree(char in[], char pre[], int inStrt,
                       int inEnd, unordered_map<char, int>& mp)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
    char curr = pre[preIndex++];
    struct Node* tNode = newNode(curr);
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = mp[curr];
 
    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
 
    return tNode;
}
 
// This function mainly creates an unordered_map, then
// calls buildTree()
struct Node* buldTreeWrap(char in[], char pre[], int len)
{
    // Store indexes of all items so that we
    // we can quickly find later
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
 
    return buildTree(in, pre, 0, len - 1, mp);
}


//Post + Inorder
Node* buildUtil(int in[], int post[], int inStrt,
    int inEnd, int* pIndex, unordered_map<int, int>& mp)
{
    // Base case
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from Postorder traversal 
    using postIndex and decrement postIndex */
    int curr = post[*pIndex];
    Node* node = newNode(curr);
    (*pIndex)--;
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return node;
 
    /* Else find the index of this node in Inorder
    traversal */
    int iIndex = mp[curr];
 
    /* Using index in Inorder traversal, construct
    left and right subtress */
    node->right = buildUtil(in, post, iIndex + 1,
                            inEnd, pIndex, mp);
    node->left = buildUtil(in, post, inStrt,
                           iIndex - 1, pIndex, mp);
 
    return node;
}
 
// This function mainly creates an unordered_map, then
// calls buildTreeUtil()
struct Node* buildTree(int in[], int post[], int len)
{
    // Store indexes of all items so that we
    // we can quickly find later
    unordered_map<int, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
 
    int index = len - 1; // Index in postorder
    return buildUtil(in, post, 0, len - 1,
                     &index, mp);
}
 

//Pre+Post
// A recursive function to construct Full from pre[] and post[].
// preIndex is used to keep track of index in pre[].
// l is low index and h is high index for the current subarray in post[]
node* constructTreeUtil (int pre[], int post[], int* preIndex,
                                int l, int h, int size)
{
    // Base case
    if (*preIndex >= size || l > h)
        return NULL;
 
    // The first node in preorder traversal is root. So take the node at
    // preIndex from preorder and make it root, and increment preIndex
    node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
 
    // If the current subarray has only one element, no need to recur
    if (l == h)
        return root;
 
    // Search the next element of pre[] in post[]
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
 
    // Use the index of element found in postorder to divide
        // postorder array in two parts. Left subtree and right subtree
    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex,
                                                l, i, size);
        root->right = constructTreeUtil (pre, post, preIndex,
                                                 i + 1, h-1, size);
    }
 
    return root;
}
 
// The main function to construct Full Binary Tree from given preorder and
// postorder traversals. This function mainly uses constructTreeUtil()
node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}
