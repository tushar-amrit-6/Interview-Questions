This method takes O(n) time and O(1) extra space. 
1) Get the middle of the linked list. 
2) Reverse the second half of the linked list. 
3) Check if the first half and second half are identical. 
4) Construct the original linked list by reversing the second half again and attaching it back to the first half

bool isPalindrome(struct Node* head)
{
    struct Node *slow_ptr = head, *fast_ptr = head;
    struct Node *second_half, *prev_of_slow_ptr = head;
     
    // To handle odd size list
    struct Node* midnode = NULL;
     
    // initialize result
    bool res = true;
 
    if (head != NULL && head->next != NULL)
    {
         
        // Get the middle of the list. Move slow_ptr by 1
        // and fast_ptrr by 2, slow_ptr will have the middle
        // node
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
 
            // We need previous of the slow_ptr for
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // fast_ptr would become NULL when there
        // are even elements in list. And not NULL
        // for odd elements. We need to skip the
        // middle node for odd case and store it
        // somewhere so that we can restore the
        // original list
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // Now reverse the second half and
        // compare it with first half
        second_half = slow_ptr;
         
        // NULL terminate first half
        prev_of_slow_ptr->next = NULL;
         
        // Reverse the second half
        reverse(&second_half);
         
        // compare
        res = compareLists(head, second_half);
 
        // Construct the original list back
        reverse(&second_half); // Reverse the second half again
 
        // If there was a mid node (odd size case)
        // which was not part of either first half
        // or second half.
        if (midnode != NULL)
        {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}
 
// Function to reverse the linked list
// Note that this function may change
// the head
void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
     
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
// Function to check if two input
// lists have same data
bool compareLists(struct Node* head1,
                  struct Node* head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
 
    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
 
    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL)
        return 1;
 
    // Will reach here when one is NULL
    // and other is not
    return 0;
}
