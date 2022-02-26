class Solution {
public:
    int helper(vector<int>& nums, int target, int n, vector<int> &dp) {
		// if target is 0, there is 1 way i.e. not choosing any item
        if(target == 0) return 1;
		
		// if there is no item or target is less than 0, there is no way
        if(n == 0 || target < 0) return 0;
        
		// check if this subproblem is already solved before
        if(dp[target] != -1)
            return dp[target];
        
		// item is less than or equal to target
        if(nums[n-1] <= target) {
			//  two choices : either we pick this item and reduce the target by item weight, OR we do not pick this item and move to the next item
            return dp[target] = helper(nums, target-nums[n-1], nums.size(), dp) + helper(nums, target, n-1, dp);
        } else { // item is greater than target
			// We can not pick this item and can just move to the next item
            return dp[target] = helper(nums, target, n-1, dp);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(nums, target, nums.size(), dp);
    }
};
