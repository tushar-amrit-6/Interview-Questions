class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs, int idx, vector<int> &dp) {
        if(idx == jobs.size())  // Base case
            return 0;
        if(dp[idx] != -1)  // return memoized result
            return dp[idx];
        
        // profit if skipped current job
        int skipCurrent = maxProfit(jobs, idx + 1, dp);
        
        // binary search for the next non-overlapping job, if we decide to do current job
        int currEnd = jobs[idx][1], lo = idx + 1, hi = jobs.size(), mid;
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            if(jobs[mid][0] < currEnd)
                lo = mid + 1;
            else
                hi = mid;
        }

        // profit from doing current job
        int takeCurrent = jobs[idx][2] + maxProfit(jobs, lo, dp);
        return dp[idx] = max(skipCurrent, takeCurrent);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = profit.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < N; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());  // sort the jobs by start time
        
        vector<int> dp(N, -1);  // dp array to store the maxProfit. dp[i] = max profit from (i, N)
        return maxProfit(jobs, 0, dp);
    }
};
