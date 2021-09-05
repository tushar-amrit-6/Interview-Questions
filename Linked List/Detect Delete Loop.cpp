int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}



/////////////////////////////REMOVE BY COUNTING LOOP SIZE THEN K DISTANCE//////////////////////////////////////
int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indicate that there is no loop*/
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;
 
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
 
    // Fix one pointer to head
    ptr1 = head;
 
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
 
    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
 
    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
We do not need to count number of nodes in Loop.
After detecting the loop, if we start slow pointer from head 
and move both slow and fast pointers at same speed until fast don’t meet,
they would meet at the beginning of the loop.
  Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time
       
m + k = (x-2y)*n

Which means m+k is a multiple of n. 
Thus we can write, m + k = i*n or m = i*n - k.
Hence, distance moved by slow pointer: m, is equal to distance moved by fast pointer:
i*n - k or (i-1)*n + n - k (cover the loop completely i-1 times and start from n-k).
  
 void detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
           
        // this check is needed when slow
        // and fast both meet at the head of the LL
          // eg: 1->2->3->4->5 and then
        // 5->next = 1 i.e the head of the LL
          if(slow == fast) {
              while(fast->next != slow) fast = fast->next;
        }
          else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}
