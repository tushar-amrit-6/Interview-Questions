void solve(Node* root,Node* &Head, Node* &prev)
{
  if(!root)
    return ;
  solve(root->left,head,prev);
  if(head==null)
  {
    head = prev;
    prev = root;
  }
  else
  {
    prev -> right = root;
    prev -> right -> left = prev;
    prev = prev -> right;
  }
  solve(root->right, head, prev);
}
Node * btoDLL(Node *root)
{
  Node* head = NULL;
  Node* prev = NULL;
  solve(root,head,prev);
  return head;
}
