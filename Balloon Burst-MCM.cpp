class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &arr, int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MIN;
        for(int k = i; k < j; k++)
        {
            int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            ans = max(ans, temp_ans);
        }
        
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1); // adding one at the end
        nums.insert(nums.begin(), 1); // adding one in the beginning
        memset(dp, -1, sizeof(dp));
        return solve(nums, 1, nums.size()-1);
    }
};
