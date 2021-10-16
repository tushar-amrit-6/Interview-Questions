dp[mask] = {a, b} where
a - minimum number of session
b - minimum time of last session
The idea is to go through all tasks who belong to mask and optimally choose the last task 't' that was added to last session.

Similar problem: CSES Problem Set - Elevator Rides https://cses.fi/problemset/task/1653
This is exactly the same problem if you change the capacity of elevator to 'sessionTime' and weights of people to 'task'.

//N*2^N solution
  
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        const int N = tasks.size();
        const int INF = 1e9;
        vector<pair<int, int>> dp(1 << N, {INF, INF});
        dp[0] = {0, INF};
        for(int mask = 1; mask < (1 << N); ++mask) {
            pair<int, int> best = {INF, INF};
            for(int i = 0; i < N; ++i) {
                if(mask & (1 << i)) {
                    pair<int, int> cur = dp[mask ^ (1 << i)];
                    if(cur.second + tasks[i] > sessionTime) {
                        cur = {cur.first + 1, tasks[i]};
                    } else
                        cur.second += tasks[i];
                    best = min(best, cur);
                }
            }
            dp[mask] = best;
        }
        return dp[(1 << N) - 1].first;
    }
};
