/************************************MEMORIZATION***************************************************/
class Solution {
    vector<int> mem;
    
    int findMax(vector<int>& prices,int curr,int n)
    {
        if(curr>=n)
            return 0;
        if(mem[curr]!=-1)
            return mem[curr];
        
        //Now find all the positions where we can sell the stock
        int maxVal = 0;
        for(int i=curr+1;i<n;++i)
            if(prices[curr]<prices[i])  //We can try to sell on ith day
                //We have 2 choices
                //1.We can sell the stock at ith day and findMax from (i+2)th day
                //2.We don't sell the stock on ith day
                maxVal = max(maxVal, prices[i]-prices[curr]+findMax(prices,i+2,n));
        
        maxVal = max(maxVal, findMax(prices,curr+1,n)); //Exclude current element
        mem[curr] = maxVal;
        return maxVal;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        mem.resize(n+1,-1);
        return findMax(prices,0,n);
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
