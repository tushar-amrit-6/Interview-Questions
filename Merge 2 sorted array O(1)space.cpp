// C++ program to merge two sorted arrays with O(1) extra space. O(n*m)
#include <bits/stdc++.h> 
using namespace std; 

// Merge ar1[] and ar2[] with O(1) extra space 
void merge(int ar1[], int ar2[], int m, int n) 
{ 
	// Iterate through all elements of ar2[] starting from 
	// the last element 
	for (int i=n-1; i>=0; i--) 
	{ 
		/* Find the smallest element greater than ar2[i]. Move all 
		elements one position ahead till the smallest greater 
		element is not found */
		int j, last = ar1[m-1]; 
		for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
			ar1[j+1] = ar1[j]; 

		// If there was a greater element 
		if (j != m-2 || last > ar2[i]) 
		{ 
			ar1[j+1] = ar2[i]; 
			ar2[i] = last; 
		} 
	} 
} 

// Driver program 
int main(void) 
{ 
	int ar1[] = {1, 5, 9, 10, 15, 20}; 
	int ar2[] = {2, 3, 8, 13}; 
	int m = sizeof(ar1)/sizeof(ar1[0]); 
	int n = sizeof(ar2)/sizeof(ar2[0]); 
	merge(ar1, ar2, m, n); 

	cout << "After Merging nFirst Array: "; 
	for (int i=0; i<m; i++) 
		cout << ar1[i] << " "; 
	cout << "nSecond Array: "; 
	for (int i=0; i<n; i++) 
		cout << ar2[i] << " "; 
return 0; 
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////////
O((n+m)*log(n+m))
  
  // Merging two sorted arrays with O(1)
// extra space
#include <bits/stdc++.h>
using namespace std;

// Function to find next gap.
int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void merge(int* arr1, int* arr2, int n, int m)
{
	int i, j, gap = n + m;
	for (gap = nextGap(gap);
		gap > 0; gap = nextGap(gap))
	{
		// comparing elements in the first array.
		for (i = 0; i + gap < n; i++)
			if (arr1[i] > arr1[i + gap])
				swap(arr1[i], arr1[i + gap]);

		// comparing elements in both arrays.
		for (j = gap > n ? gap - n : 0;
			i < n && j < m;
			i++, j++)
			if (arr1[i] > arr2[j])
				swap(arr1[i], arr2[j]);

		if (j < m) {
			// comparing elements in the second array.
			for (j = 0; j + gap < m; j++)
				if (arr2[j] > arr2[j + gap])
					swap(arr2[j], arr2[j + gap]);
		}
	}
}

// Driver code
int main()
{
	int a1[] = { 10, 27, 38, 43, 82 };
	int a2[] = { 3, 9 };
	int n = sizeof(a1) / sizeof(int);
	int m = sizeof(a2) / sizeof(int);

	// Function Call
	merge(a1, a2, n, m);

	printf("First Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", a1[i]);

	printf("\nSecond Array: ");
	for (int i = 0; i < m; i++)
		printf("%d ", a2[i]);
	printf("\n");
	return 0;
}
