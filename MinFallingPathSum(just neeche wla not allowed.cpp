int minFallingPathSum(vector<vector<int>>& arr) {
        
        int n = arr.size() ;
        vector<int> dp ;
        dp = arr[n-1] ;
        
        for(int i=n-2;i>=0;i--){
            int firstmin=INT_MAX,secondmin=INT_MAX,firstminindex ;
            for (int j=0;j<n;j++){
                if (firstmin>dp[j]){                    //calculating first min
                    firstmin = dp[j] ;
                    firstminindex = j ;
                }
            }for (int j=0;j<n;j++){
                if (j==firstminindex)continue ;                          //second min
                secondmin = min(secondmin,dp[j]) ;
            }
            for (int j=0;j<n;j++){
                if (j==firstminindex) dp[j]=arr[i][j]+secondmin ;  
                else dp[j] = arr[i][j]+firstmin ;
            }
        }
        return *min_element(dp.begin(),dp.end());
    }
