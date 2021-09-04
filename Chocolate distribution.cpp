O(n) Time and O(1) space

Consider variables i, j initially pointing to first element, val = 1, res = 0.

After traversing through the array res gives the total number of chocolates distributed.

val while iterating index j (in increasing/flat subarray) represents the number of chocolates received by the person at j

If the subarray is increasing or a flat sequence, val is added to res; i, j are moved forward and val is updated according to next value (a[j + 1]).

If the subarray is decreasing, i is pointed to the starting point of subarray and j is moved forward till next transition point.
val, res are not updated till the end of the subarray. In this case val holds the value of the peak element obtained from previous subarray.
At the end of the decreasing sequence res is updated using get_sum function & val is updated to point to the number of chocolates held by the next person.
  
// C++ program for above approach

#include <iostream>
using namespace std;

// Helper function to get sum of decreasing sequence
int get_sum(int peak, int start, int end)
{
	/* peak is the value obtained at peak point
	from previous flat/increasing sequence */

	/* value obtained from decreasing sequence
	also the count of values in the sequence*/
	int count = end - start + 1;

	/* assigning max of values obtained from
	increasing and decreasing sequences */
	peak = max(peak, count);

	/* sum of count - 1 values & peak value
	sum of natural numbers : (n * (n + 1))/2 */
	int s = peak + (((count - 1) * count) >> 1);

	return s;
}

// Function to return minimum number of chocolates
int minChocolates(int a[], int n)
{
	int i = 0, j = 0;
	int res = 0, val = 1;

	while (j < n - 1) {

		if (a[j] > a[j + 1]) {
			// decreasing sequence
			j += 1;
			continue;
		}

		if (i == j)
			// add the chocolates received by that person
			res += val;
		else {
			// end point of decreasing sequence
			res += get_sum(val, i, j);
			val = 1; // reset value at that index
		}

		if (a[j] < a[j + 1])
			// increasing sequence
			val += 1;
		else
			// flat sequence
			val = 1;

		j += 1;
		i = j;
	}
	// add value of chocolates at position n-1
	if (i == j)
		res += val;
	else
		res += get_sum(val, i, j);

	return res;
}

// Driver code
int main()
{

	int a[] = { 5, 5, 4, 3, 2, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Minimum number of chocolates = "
		<< minChocolates(a, n) << "\n";
	return 0;
}

// This code is contributed by saitejagampala
  
