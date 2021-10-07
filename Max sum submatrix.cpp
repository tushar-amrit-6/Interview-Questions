/*
    Time complexity: O(N * M * M)
    Space complexity: O(N)
    
    Where N denotes the number of rows of the matrix and M denotes the number of columns of the matrix.

*/

int kadaneAlgorithm(int arr[], int n)
{
	int sum = 0;
	
	int maxSum = INT_MIN;
    
    // Traverse the array.
	for(int currIndex = 0; currIndex < n; currIndex++)
	{
		sum += arr[currIndex];

		if(maxSum < sum)
		{
			maxSum = sum;
		}
		
		if(sum < 0)
		{
			sum = 0;
		}
	}

	return maxSum;
}

int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
	int maxSum = INT_MIN;
	
    // Initialize a 1-D array.
	int temp[n];
    
    // heck for all possible left and right boundaries.
	for(int left = 0; left < m; left++)
	{
		for(int i = 0; i < n; i++)
		{
			temp[i] = 0;
		}

		for(int right = left; right < m; right++)
		{
			for(int i = 0; i < n; i++)
			{
				temp[i] += arr[i][right];
			}
            
            // Function to find maximum sum of sub array of array 'temp'.
			int sum = kadaneAlgorithm(temp, n);
            
            // Update 'maxSum'.
			if(sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	return maxSum;
}
