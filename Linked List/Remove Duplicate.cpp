Sorted
void removeDuplicates(Node* head)
{
    /* Pointer to traverse the linked list */
    Node* current = head;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    Node* next_next;
     
    /* do nothing if the list is empty */
    if (current == NULL)
    return;
 
    /* Traverse the list till last node */
    while (current->next != NULL)
    {
    /* Compare current node with next node */
    if (current->data == current->next->data)
    {
        /* The sequence of steps is important*/       
        next_next = current->next->next;
        free(current->next);
        current->next = next_next;
    }
    else /* This is tricky: only advance if no deletion */
    {
        current = current->next;
    }
    }
}


Unsorted
void removeDuplicates(struct Node *start)
{
    // Hash to store seen values
    unordered_set<int> seen;
 
    /* Pick elements one by one */
    struct Node *curr = start;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
}
