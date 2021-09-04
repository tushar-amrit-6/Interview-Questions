Initialize maximumXOR as 0.
Insert the binary representation of all the numbers in the given array arr[] in the Tree. While inserting in the trie if the current bit 0 then create a node in the left else create a node in the right of the current head node.
Now, traverse the given array and for each element do the following:
Initialize the currentXOR value as 0.
Traverse the binary representation of the current number.
If ith bit is 1 and node->left exists then update currentXOR as currentXOR + pow(2, i) and update node as node->left. Else update node = node->right.
If ith bit is 0, and node->right exists then update currentXOR as currentXOR + pow(2, i) and update node as node->right. Else update node = node->left.
For each array element in the above step, update the maximumXOR value if maximumXOR is greater than currentXOR.
Print the value of maximumXOR after the above steps.
  
  // C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of Trie
class node {
public:
	node* left;
	node* right;
};

// Function to insert binary
// representation of element x
// in the Trie
void insert(int x, node* head)
{
	// Store the head
	node* curr = head;

	for (int i = 30; i >= 0; i--) {

		// Find the i-th bit
		int val = (x >> i) & 1;

		if (val == 0) {

			// If curr->left is NULL
			if (!curr->left)
				curr->left = new node();

			// Update curr to curr->left
			curr = curr->left;
		}
		else {

			// If curr->right is NULL
			if (!curr->right)
				curr->right = new node();

			// Update curr to curr->right
			curr = curr->right;
		}
	}
}

// Function that finds the maximum
// Bitwise XOR value for all such pairs
int findMaximumXOR(int arr[], int n)
{
	// head Node of Trie
	node* head = new node();

	// Insert each element in trie
	for (int i = 0; i < n; i++) {
		insert(arr[i], head);
	}

	// Stores the maximum XOR value
	int ans = 0;

	// Traverse the given array
	for (int i = 0; i < n; i++) {

		// Stores the XOR with current
		// value arr[i]
		int curr_xor = 0;

		int M = pow(2, 30);

		node* curr = head;

		for (int j = 30; j >= 0; j--) {

			// Finding ith bit
			int val = (arr[i] >> j) & 1;

			// Check if the bit is 0
			if (val == 0) {

				// If right node exists
				if (curr->right) {

					// Update the currentXOR
					curr_xor += M;
					curr = curr->right;
				}

				else {
					curr = curr->left;
				}
			}

			else {

				// Check if left node exists
				if (curr->left) {

					// Update the currentXOR
					curr_xor += M;
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}

			// Update M to M/2 for next set bit
			M /= 2;
		}

		// Update the maximum XOR
		ans = max(ans, curr_xor);
	}

	// Return the maximum XOR found
	return ans;
}

// Driver Code
int main()
{
	// Given array arr[]
	int arr[] = { 1, 2, 3, 4 };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << findMaximumXOR(arr, N);

	return 0;
}
