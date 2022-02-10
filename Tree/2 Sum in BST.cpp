/*
    Time Complexity: O(N)
    Space Complexity: O(logN)
    
    Where 'N' denotes the number of nodes in the given BST
*/

#include<stack>

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    
    /*
        Stack 'start' and 'end' to store the smaller and larger 
        values of BST respectively.
    */
    stack<BinaryTreeNode<int>*> start, end;

    BinaryTreeNode<int> *currNode = root;
    
    // Storing left values of BST in 'start'.
    while (currNode != NULL)
    {
        start.push(currNode);
        currNode = currNode -> left;
    }

    // Setting currNode again pointing to root.
    currNode = root;
    
    // Storing right values of BST in 'end'.
    while (currNode != NULL)
    {
        end.push(currNode);
        currNode = currNode -> right;
    }

    while (start.top() != end.top())
    {
        
        // Storing top node's value of 'start' stack in 'val1'.
        int val1 = start.top() -> data;
        
        // Storing top node's value of 'end' stack in 'val2'.
        int val2 = end.top() -> data;

        // If sum of 'val1' and 'val2' is equal to 'k' then return "true".
        if (val1 + val2 == k)
        {
            return true;
        }

        // Move to the next greatest closer value.
        if (val1 + val2 < k)
        {
            currNode = start.top() -> right;
            start.pop();
            
            while (currNode != NULL)
            {
                start.push(currNode);
                currNode = currNode -> left;
            }
        }

        // Move to the next smallest closer value.
        else
        {
            currNode = end.top() -> left;
            end.pop();

            while (currNode != NULL)
            {
                end.push(currNode);
                currNode = currNode -> right;
            }
        }
    }

    // If no two nodes is found, return false.
    return false;
}
