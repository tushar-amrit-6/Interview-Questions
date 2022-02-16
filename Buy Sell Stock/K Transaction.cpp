class Solution {
public:
    int dp[1005][3][105];
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
    

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solver(prices, 0, 0, k);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {

public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int hold[k+1];
        int rele[k+1];
        for (int i=0;i<=k;++i){
            hold[i] = INT_MIN;
            rele[i] = 0;
        }
        int cur;
        for (int i=0; i<len; ++i){
            cur = prices[i];
            for(int j=k; j>0; --j){
                rele[j] = max(rele[j],hold[j] + cur);
                hold[j] = max(hold[j],rele[j-1] - cur);
            }
        }
        return rele[k];
    }
};
