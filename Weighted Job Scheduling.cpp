bool static comp(vector<int>&x,vector<int>&y){
    
    return x[1]<y[1];
    
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
    int n=startTime.size();
    
    vector<vector<int>>vec(n);
    
    for(int i=0;i<n;i++){
        vec[i]={startTime[i],endTime[i],profit[i]};
    }
    
    sort(vec.begin(),vec.end(),comp);
    
    vector<int>dp(n);
    
    dp[0]=vec[0][2];
    
    for(int i=1;i<n;i++){
        
        int low=0,high=i-1;
        
        int inc=-1,ans=vec[i][2];
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(vec[i][0]>=vec[mid][1]){
                inc=mid;
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
            
        }
        
        ans=inc==-1?ans:ans+dp[inc];
        
        dp[i]=max(dp[i-1],ans);
        
    }
    
    return dp[n-1];
    
    
}
};
