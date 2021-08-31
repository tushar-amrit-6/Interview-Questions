class Solution {
public:
    int dp[71][71][71];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int rows=grid.size() , cols=grid[0].size();
        return Answer(grid,rows,cols,0,0,cols-1);
    }
    int Answer(vector<vector<int>> &mat,int row,int col,int r,int c1,int c2){
        if(r == row)    return 0;
 
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
 
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int fc1 = c1 +i,fc2 =c2+j;
                if( fc1>=0 && fc1<col && fc2>=0 && fc2<col)
                    ans = max(ans,Answer(mat,row,col,r+1,fc1,fc2));
            }
        }
 
        int cur = (c1 == c2? mat[r][c1]:mat[r][c1] + mat[r][c2]);
        dp[r][c1][c2] = ans +cur;
 
        return dp[r][c1][c2];
    }
};
