/*  

    Time Complexity: O(L * log(L))
    Space Complexity: O(log(L))
    
    Where 'L' is the number of nodes in the Linked-List.

*/

// Function to find the mid node and the number of elements in first half of the list.
Node * findMid(Node *head, int &elementsInLeftList) {
    // If the current head node is NULL then return it.
    if (head == NULL) {
        return NULL;
    }

    elementsInLeftList = 1;
    Node *fast = head, *slow = head;

    // Update fast pointer by two nodes and slow by one node.
    while (fast->next != NULL && fast->next->next != NULL) {
        elementsInLeftList++;
        fast = fast->next->next;
        slow = slow->next;
    }
    // When fast pointer reaches at end, slow pointer will denote the middle element of the list, thus return it.
    return slow;
}

// Function to merge two sorted lists.
Node * merge(Node *left, Node *right, long long int &inversionCnt, int elementsInLeftList) {
    // Base cases - if left or right list is empty.
    if (left == NULL) {
        return (left);
    } else if (right == NULL) {
        return (right);
    }

    Node *dummyResult = new Node(-1);

    // This node will store the head of the merged nodes of the given two linked list parts.
    Node *result = dummyResult;
    int curPositionInLeftList = 0;

    // Iterate both the left and right list till any one reaches at end.
    while (left != NULL && right != NULL) {
        // If left pointer has smaller or equal data in the node than right list.
        if (left->data <= right->data) {
            curPositionInLeftList++;
            result->next = left;
            result = left;
            left = left->next;
        }
        // If right pointer has smaller data in the node than left list.
        else {
            // Update inversionCnt in this case by the number of elements remaining elements in the left list,
            // (including the left current element). 
            inversionCnt += elementsInLeftList - curPositionInLeftList;
            result->next = right;
            result = right;
            right = right->next;
        }
    }

    // Append the non-empty left or right list to the result.
    if (left != NULL) {
        result->next = left;
    } else {
        result->next = right;
    }

    // Make result to be head of the linked list and free the dummy result node.
    result = dummyResult->next;
    dummyResult->next = NULL;
    delete dummyResult;

    // Return the merged list.
    return result;
}

// Function to sort the linked list.
Node * MergeSort(Node *head, long long int &inversionCnt) {
    // Base case -- length of current linkes list starting with head is 0 or 1.
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    Node *a = head;

    // Variable to count the number of elements on left side of the mid element.
    int elementsInLeftList = 0;

    // Calling findMid function to find the middle node of the list.
    Node *mid = findMid(head, elementsInLeftList);
    Node *b = mid->next;
    mid->next = NULL;

    // Recursively sort the sublists.
    Node *left = MergeSort(a, inversionCnt);
    Node *right = MergeSort(b, inversionCnt);

    // Merging the two sorted lists together.
    head = merge(left, right, inversionCnt, elementsInLeftList);
    return head;
}

long long int calculateInversionCnt(Node *head) {
    // If linked list is empty or has only one element, return 0 as no inversions possible.
    if (head == NULL || head->next == NULL) {
        return 0;
    }

    // Variable to store the inversion count for the given list.
    long long int inversionCnt = 0;

    // Calling the MergeSort function which will update the inversion count value in the variable inversionCnt.
    head = MergeSort(head, inversionCnt);

    // Return the inversion count of the given linked list.
    return inversionCnt;
}
