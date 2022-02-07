he problem can be solved using only one stack. The idea is to mark each node of the binary tree by assigning a value,
called status code with each node such that value 1 represents that the node is currently visiting in preorder traversal, 
value 2 represents the nodes is currently visiting in inorder traversal and value 3 represents the node is visiting in the postorder traversal.

Initialize a stack < pair < Node*, int>> say S.
Push the root node in the stack with status as 1, i.e {root, 1}.
Initialize three vectors of integers say preorder, inorder, and postorder.
Traverse the stack until the stack is empty and check for the following conditions:
If the status of the top node of the stack is 1 then update the status of the top node of the stack to 2 and 
  push the top node in the vector preorder and insert the left child of the top node if it is not NULL in the stack S.
If the status of the top node of the stack is 2 then update the status of the top node of the stack to 3 and
    push the top node in the vector inorder and insert the right child of the top node if it is not NULL in the stack S.
If the status of the top node of the stack is 3 then push the top node in vector postorder and then pop the top element.
Finally, print vectors preorder, inorder, and postorder

void allTraversal(Node* root)
{
    // Stores preorder traversal
    vector<int> pre;
 
    // Stores inorder traversal
    vector<int> post;
 
    // Stores postorder traversal
    vector<int> in;
 
    // Stores the nodes and the order
    // in which they are currently visited
    stack<pair<Node*, int> > s;
 
    // Push root node of the tree
    // into the stack
    s.push(make_pair(root, 1));
 
    // Traverse the stack while
    // the stack is not empty
    while (!s.empty()) {
 
        // Stores the top
        // element of the stack
        pair<Node*, int> p = s.top();
 
        // If the status of top node
        // of the stack is 1
        if (p.second == 1) {
 
            // Update the status
            // of top node
            s.top().second++;
 
            // Insert the current node
            // into preorder, pre[]
            pre.push_back(p.first->data);
 
            // If left child is not NULL
            if (p.first->left) {
 
                // Insert the left subtree
                // with status code 1
                s.push(make_pair(
                    p.first->left, 1));
            }
        }
 
        // If the status of top node
        // of the stack is 2
        else if (p.second == 2) {
 
            // Update the status
            // of top node
            s.top().second++;
 
            // Insert the current node
            // in inorder, in[]
            in.push_back(p.first->data);
 
            // If right child is not NULL
            if (p.first->right) {
 
                // Insert the right subtree into
                // the stack with status code 1
                s.push(make_pair(
                    p.first->right, 1));
            }
        }
 
        // If the status of top node
        // of the stack is 3
        else {
 
            // Push the current node
            // in post[]
            post.push_back(p.first->data);
 
            // Pop the top node
            s.pop();
        }
    }
 
    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << "\n";
 
    // Printing Inorder
    cout << "Inorder Traversal: ";
 
    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << "\n";
 
    // Printing Postorder
    cout << "Postorder Traversal: ";
 
    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
    cout << "\n";
}
