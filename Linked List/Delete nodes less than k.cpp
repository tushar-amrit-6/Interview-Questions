void deleteLesserNodes(Node** head_ref, int K)
{
    Node *temp = *head_ref, *prev;
 
    // If head node itself holds the value lesser than 'K'
    while (temp != NULL && temp->data < K) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        temp = *head_ref; // Change temp
    }
 
    // Delete occurrences other than head
    while (temp != NULL) {
 
        // Search for the node to be deleted,
        // keep track of the previous node as we
        // need to change 'prev->next'
        while (temp != NULL && temp->data >= K) {
            prev = temp;
            temp = temp->next;
        }
 
        // If required value node was not present
        // in linked list
        if (temp == NULL)
            return;
 
        // Unlink the node from linked list
        prev->next = temp->next;
 
        delete temp; // Free memory
 
        // Update Temp for next iteration of
        // outer loop
        temp = prev->next;
    }
}
