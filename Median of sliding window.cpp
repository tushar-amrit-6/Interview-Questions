class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hash;                          // count numbers to be deleted
        priority_queue<int, vector<int>> bheap;                // heap on the bottom
        priority_queue<int, vector<int>, greater<int>> theap;  // heap on the top
        
        int i = 0;
        
        // Initialize the heaps
        while (i < k)  { bheap.push(nums[i++]); }
        for (int count = k/2; count > 0; --count) {
            theap.push(bheap.top()); bheap.pop();
        }
        
        while (true) {
            // Get median
            if (k % 2) medians.push_back(bheap.top());
            else medians.push_back( ((double)bheap.top() + theap.top()) / 2 );
            
            if (i == nums.size()) break;
            int m = nums[i-k], n = nums[i++], balance = 0;
            
            // What happens to the number m that is moving out of the window
            if (m <= bheap.top())  { --balance;  if (m == bheap.top()) bheap.pop(); else ++hash[m]; }
            else                   { ++balance;  if (m == theap.top()) theap.pop(); else ++hash[m]; }
            
            // Insert the new number n that enters the window
            if (!bheap.empty() && n <= bheap.top())  { ++balance; bheap.push(n); }
            else                                     { --balance; theap.push(n); }
            
            // Rebalance the bottom and top heaps
            if      (balance < 0)  { bheap.push(theap.top()); theap.pop(); }
            else if (balance > 0)  { theap.push(bheap.top()); bheap.pop(); }
            
            // Remove numbers that should be discarded at the top of the two heaps
            while (!bheap.empty() && hash[bheap.top()])  { --hash[bheap.top()]; bheap.pop(); }
            while (!theap.empty() && hash[theap.top()])  { --hash[theap.top()]; theap.pop(); }
        }
        
        return medians;
    }
};


PBDS Implementation
// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Policy based data structure
typedef tree<int, null_type,
			less_equal<int>, rb_tree_tag,
			tree_order_statistics_node_update>
	Ordered_set;

// Function to find and return the
// median of every window of size k
void findMedian(int arr[], int n,
				int k)
{

	Ordered_set s;

	for (int i = 0; i < k; i++)
		s.insert(arr[i]);

	if (k & 1) {

		// Value at index k/2
		// in sorted list.
		int ans = *s.find_by_order(k / 2);

		cout << ans << " ";

		for (int i = 0; i < n - k; i++) {

			// Erasing Element out of window.
			s.erase(s.find_by_order(
				s.order_of_key(
					arr[i])));

			// Inserting newer element
			// to the window
			s.insert(arr[i + k]);

			// Value at index k/2 in
			// sorted list.
			ans = *s.find_by_order(k / 2);

			cout << ans << " ";
		}
		cout << endl;
	}
	else {

		// Getting the two middle
		// median of sorted list.
		float ans = ((float)*s.find_by_order(
						(k + 1) / 2 - 1)
					+ (float)*s.find_by_order(k
											/ 2))
					/ 2;

		printf("%.2f ", ans);

		for (int i = 0; i < n - k; i++) {
			s.erase(s.find_by_order(
				s.order_of_key(arr[i])));

			s.insert(arr[i + k]);

			ans = ((float)*s.find_by_order(
					(k + 1) / 2 - 1)
				+ (float)*s.find_by_order(k
											/ 2))
				/ 2;

			printf("%.2f ", ans);
		}
		cout << endl;
	}
}

// Driver Code
int main()
{
	int arr[] = { -1, 5, 13, 8, 2,
				3, 3, 1 };
	int k = 3;

	int n = sizeof(arr)
			/ sizeof(arr[0]);
	findMedian(arr, n, k);

	return 0;
}
