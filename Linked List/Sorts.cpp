MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); /* a and b are two halves */
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
 
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
 
/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
/* Function to insert a node at the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}





// Returns the last node of the list
struct Node* getTail(struct Node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end,
                       struct Node** newHead,
                       struct Node** newEnd)
{
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
// here the sorting happens exclusive of the end node
struct Node* quickSortRecur(struct Node* head,
                            struct Node* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    Node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    struct Node* pivot
        = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(struct Node** headRef)
{
    (*headRef)
        = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
