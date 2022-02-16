class Solution {
public:
    int dp[50005][2];
    int solve(vector<int>& prices, int fee, int idx, int buy){
        if(idx >= prices.size()) return 0;
        
        // if i know the result of this state i will simply use that
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        // i will have two options either to do nothing or to do something(buy/sell)
        
        int op1 = INT_MIN, op2 = INT_MIN;
        
        //option 1 -> to do nothing
        
        op1 = solve(prices, fee, idx + 1, buy);
        
        //option 2 -> to buy or sell
        
        // if i already bought some stock than i have to sell this
        // because we cannot engage in multiple transactions
        if(buy){
            op2 = prices[idx] - fee + solve(prices, fee, idx + 1, 0);
        }
        
        // else we haven't bought anything so we can buy a stock 
        else{
              op2 = -prices[idx] + solve(prices, fee, idx + 1, 1);
        }
        
        return dp[idx][buy] = max(op1, op2);
    
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, fee, 0, 0);   
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
     int n = p.size();
        if (n < 2) return 0;
        vector<int> hold(n, 0), sold(n, 0);
        hold[0] = -p[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], sold[i - 1] - p[i]);
            sold[i] = max(sold[i - 1], hold[i - 1] - fee + p[i]);
        }

        return sold[n - 1];    
    }
};
