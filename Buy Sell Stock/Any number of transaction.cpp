class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size()==0|| prices.size()==1) return 0;
    int max_pro=0;
    for(int i=prices.size()-1;i>0;i--){
        if(prices[i]-prices[i-1]>0) max_pro+=prices[i]-prices[i-1];
    }
    return max_pro;
    }
};
