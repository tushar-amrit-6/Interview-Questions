// function to reverse the linked list;
Node* reverse_list(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    Node *Next = NULL;
    while(curr != NULL){
       Next = curr -> next;
       curr -> next = prev;
       prev = curr;
       curr = Next;
    }
    return prev;
}
/* function to Delete all nodes that have a greater value on the right side*/
Node* delete_nodes(Node *head){
  // First I have to reverse the linked list
  Node *rev_head = reverse_list(head);
  head = rev_head;
  // traverse the linked list
  int max_so_far = INT_MIN;
  Node *prev = rev_head;
  while(rev_head != NULL){ 
    int data = rev_head -> value;
    if(data >= max_so_far){
       prev = rev_head;
       rev_head = rev_head -> next;
       max_so_far = data; 
    }
    else { // delete the current node
       Node *temp = rev_head;
      prev->next = rev_head -> next;
      rev_head = rev_head -> next;
      delete temp;
    }
  }
// reverse the result and return
 return reverse_list(head);
}
