O(n^3) MCM way
class Solution {
public:
    bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

    int solve (string & s, int i, int j, vector<vector<int>> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            
            /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
            
        return solve (s, 0, n-1, dp);
    }
};



MANACHAR O(n^2)
  //Manancher-like solution
class Solution {
public:
    int minCut(string s) {
        const int N = s.size();
        if(N<=1) return 0;
        
        int i, j, minCUTS[N+1];
        for(i=0; i<=N; ++i) minCUTS[i] = i-1;
        
        for(i=1;i<N;i++)
        {
            for(j=0;(i-j)>=0 && (i+j)<N && s[i-j]== s[i+j]; ++j) // odd-length substrings 
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j]);

            for(j=0;(i-j-1)>=0 && (i+j)<N && s[i-j-1]== s[i+j]; ++j) // even-length substrings
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j-1]);
        }
        return minCUTS[N];
    }
};

https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
