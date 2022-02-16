/************************************MEMORIZATION***************************************************/
class Solution {
public:

    int dp[5005][3];
    int solver(vector<int>& prices, int idx, int bought) {

        if (idx >= prices.size()) {
            return 0;
        }
        
        if (dp[idx][bought] != -1) {
            return dp[idx][bought]; 
        }

        int profitWithBuying, profitWithSelling, profitWithSkipping;
        profitWithSkipping = profitWithSelling = profitWithBuying = 0;

        profitWithSkipping = solver(prices, idx+1, bought);

        if (bought) {

            // already have purchased the stock
            profitWithSelling = prices[idx] + solver(prices, idx+2, 1-bought);  
        }
        else {

            // no stocks bought so buy it
            profitWithBuying = solver(prices, idx+1, 1-bought) - prices[idx];
        }

        return dp[idx][bought] = max(profitWithSkipping, max(profitWithBuying, profitWithSelling));
    }
    

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solver(prices, 0, 0);
    }
};
/************************************STATE MACHINE***************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
        vector<int> noStock(n,0),inHand(n,0),Sold(n,0);
        
        noStock[0] = 0;
        inHand[0] = -prices[0];    //bcoz we have bought a stock and never sold it
        Sold[0] = 0;
        
        for(int i=1;i<n;++i)
        {
            noStock[i] = max(noStock[i-1],Sold[i-1]);
            inHand[i] = max(inHand[i-1],noStock[i-1]-prices[i]);
            Sold[i] = inHand[i-1]+prices[i];
        }
        int result = max(noStock[n-1],Sold[n-1]);
        return result;
    }
};
