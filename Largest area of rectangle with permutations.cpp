Let’s say for each index i.e. (i, j) pair, we store a value which corresponds to the number of consecutive cells having 1
as their value which are directly above that cell starting from the given cell itself. Lets store this value in an array 
called count. Thus count[i][j] will denote the number of consecutive 1’s starting from the cell (i, j) and continuing upwards.

For example, for a given matrix
1 0 1
1 1 0
1 0 1

Its count matrix will be -
1 0 1
2 1 0
3 0 1

At index i = 3 & j = 1, its value is 3 because there are 3 1’s directly above it including itself.
  At index i = 2 & j = 3, its value is 0 as its value itself is 0, hence no consecutive 1’s chain can be formed starting from this index.

We can use simple prefix sum method to evaluate the count array.

Now, once we have got this array, let’s consider a row i. Each element of this row will have
some count[i][j] value where j is from 1 to m. Now as permutation is allowed, we can select any order 
for keeping the columns. Let’s fix that ordering for time being with lower the value of count[i][j],
the earlier it is getting placed. So we will have a sorted arrangement of columns according to their 
count[i][j] values. We can easily see that while traversing through the above sorted arrangement,
we can calculate the maximum area possible for that particular row. On repeating this algorithm for each 
row of the grid will give us the maximum area rectangle possible in the given grid.

The above method time complexity is O(n * m * LOG(m)) where n is the number of rows and m is the number of columns.

This can be further improved by using count sort in place of normal sorting algorithms like quick sort.
  We can use count sort as maximum number of consecutive 1’s in a column would be the size of the row i.e. n.
  On using count sort, We will get time complexity as O(n * m).

int Solution::solve(vector<vector<int> > &A) {
	int n, m, res = 0;
	n = A.size();
	m = A[0].size();
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(A[j-1][i-1] == 0) {
				dp[j][i] = 0;
			}
			else {
				dp[j][i] += dp[j-1][i] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int arr[n + 1], cnt = 0;
		memset(arr, 0, sizeof(arr));
		for (int j = 1; j <= m; ++j) {
			arr[dp[i][j]] ++;
		}
		for (int j = n; j >= 0; --j) {
			cnt += arr[j];
			res = max(res, cnt * j);
		}
	}
	return res;
}
