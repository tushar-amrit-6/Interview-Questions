Initialize three pointers prev as NULL, curr as head and next as NULL.
Iterate through the linked list. In loop, do following. 
// Before changing next of current, 
// store next node 
next = curr->next
// Now change next of current 
// This is where actual reversing happens 
curr->next = prev 
// Move prev and curr one step forward 
prev = curr 
curr = next
void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
