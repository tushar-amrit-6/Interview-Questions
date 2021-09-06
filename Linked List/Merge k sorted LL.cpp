struct compare {
    bool operator()(
        struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};
 
// function to merge k sorted linked lists
struct Node* mergeKSortedLists(
    struct Node* arr[], int k)
{
    // priority_queue 'pq' implemented
    // as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;
 
    // push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);
     
      // Handles the case when k = 0
      // or lists have no elements in them   
      if (pq.empty())
        return NULL;
   
      struct Node *dummy = newNode(0);
      struct Node *last = dummy;
   
    // loop till 'pq' is not empty
    while (!pq.empty()) {
 
        // get the top element of 'pq'
        struct Node* curr = pq.top();
        pq.pop();
 
          // add the top element of 'pq'
          // to the resultant merged list
        last->next = curr;
          last = last->next; 
       
          // check if there is a node
        // next to the 'top' node
        // in the list of which 'top'
        // node is a member
        if (curr->next != NULL)
            // push the next node of top node in 'pq'
            pq.push(curr->next);
    }
 
    // address of head node of the required merged list
    return dummy->next;
}
 
