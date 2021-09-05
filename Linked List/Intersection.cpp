struct Node* sortedIntersect(struct Node* a,
                             struct Node* b)
{
     
    // base case
    if (a == NULL || b == NULL)
        return NULL;
 
    /* If both lists are non-empty */
 
    /* Advance the smaller list and
       call recursively */
    if (a->data < b->data)
        return sortedIntersect(a->next, b);
 
    if (a->data > b->data)
        return sortedIntersect(a, b->next);
 
    // Below lines are executed only
    // when a->data == b->data
    struct Node* temp = (struct Node*)malloc(
                  sizeof(struct Node));
    temp->data = a->data;
 
    // Advance both lists and call recursively
    temp->next = sortedIntersect(a->next,
                                 b->next);
    return temp;
}
