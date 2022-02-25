/*

	Time complexity: O((N * M) * log(min(N,M)))
	Space complexity: O(N * M)
	
	where N is the number of rows and M is the number of columns in the matrix.

*/

int findSum(int r1, int c1, int r2, int c2, int n, int m, vector<vector<int>> &pref)
{
	int sum = pref[r2][c2];
	if ((c1 - 1) >= 0)
	{
		sum -= pref[r2][c1 - 1];
	}
	if ((r1 - 1) >= 0)
	{
		sum -= pref[r1 - 1][c2];
	}
	if ((c1 - 1) >= 0 && (r1 - 1) >= 0)
	{
		sum += pref[r1 - 1][c1 - 1];
	}
	return sum;
}

int largestSquareSubmatrix(vector<vector<int>> &mat, int n, int m, int k)
{
	// Find the prefix sum of the matrix
	vector<vector<int>> pref(n, vector<int>(m, 0));

	// Row-wise sum
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			pref[i][j] = mat[i][j];
			if ((j - 1) >= 0)
			{
				pref[i][j] += pref[i][j - 1];
			}
		}
	}

	// Column-wise sum
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if ((i - 1) >= 0)
			{
				pref[i][j] += pref[i - 1][j];
			}
		}
	}

	int ans = 0;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			int l = 0, low = 1, high = min(n - r, m - c);

			// Finding largest l using binary search
			while (low <= high)
			{
				int mid = (low + high) / 2;
				int sum = findSum(r, c, r + mid - 1, c + mid - 1, n, m, pref);
				if (sum <= k)
				{
					l = mid;
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			ans = max(ans, l * l);
		}
	}
	return ans;
}

