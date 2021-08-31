Dp Solution <-- Give You TLE

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),INT_MIN);
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            int l = k;
            while(l){
                if(i-l>=0){
                    dp[i] = max(dp[i-l]+nums[i],dp[i]);     
                }
                l--;
            }
        }
        return dp[nums.size()-1];
    }
};


now  here is the trick we don't need to loop each K time insted of what we can do we can use set/priority_queue to find max DP valu from previous K element by O(log K) time 
now find It and add to the DP table . That's it!!!!!!
    
Here Is the O ( N Log K) slution

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size(),INT_MIN);
        multiset<int>Q;
        dp[0] = nums[0];
        Q.insert(dp[0]);
        for(int i = 1;i<nums.size();i++){
            if(Q.size()>k){
                auto it = Q.find(dp[i-k-1]);
                Q.erase(it);
            }
            dp[i] = max(*Q.rbegin()+nums[i],dp[i]);
            Q.insert(dp[i]);
        }
        return dp[nums.size()-1];
    }
};
