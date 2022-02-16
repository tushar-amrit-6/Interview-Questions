class Solution {
public:
    int dp[100005][3][3];
    int solver(vector<int>& prices, int idx, int bought, int transactions) {

        if (idx >= prices.size() || transactions == 0) {
            return 0;
        }
        
        if (dp[idx][bought][transactions] != -1) {
            return dp[idx][bought][transactions]; 
        }

        int profitWithBuying, profitWithSelling, profitWithSkipping;
        profitWithSkipping = profitWithSelling = profitWithBuying = 0;

        profitWithSkipping = solver(prices, idx+1, bought, transactions);

        if (bought) {

            // already have purchased the stock
            profitWithSelling = prices[idx] + solver(prices, idx+1, 1-bought, transactions-1);  
        }
        else {

            // no stocks bought so buy it
            profitWithBuying = solver(prices, idx+1, 1-bought, transactions) - prices[idx];
        }

        return dp[idx][bought][transactions] = max(profitWithSkipping, max(profitWithBuying, profitWithSelling));
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solver(prices, 0, 0, 2);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};
