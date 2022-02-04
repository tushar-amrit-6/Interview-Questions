k ==> Number of floors 
n ==> Number of Eggs 
Time Complexity: O(n*k^2). 
Where ‘n’ is the number of eggs and ‘k’ is the number of floors, as we use a nested for loop ‘k^2’ times for each egg
Auxiliary Space: O(n*k). 
vector<vector<int>> memo(MAX, vector<int> (MAX, -1));
int solveEggDrop(int n, int k) {
  
    if(memo[n][k] != -1) { return memo[n][k];}
     
    if (k == 1 || k == 0)
      return k;
 
    if (n == 1)
      return k;
 
    int min = INT_MAX, x, res;
 
    for (x = 1; x <= k; x++) {
      res = max(
        solveEggDrop(n - 1, x - 1),
        solveEggDrop(n, k - x));
      if (res < min)
        min = res;
    }
     
    memo[n][k] = min+1;
    return min + 1;
  }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////

n--Floor , K===Egg
Time Complexity: O((n * k) * logn )
Space Complexity: O(n * k)
class Solution {
public:
    int find(int k,int n,vector<vector<int>> &memo)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        if(memo[k][n]!=-1) return memo[k][n];
        int ans=1000000,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=find(k-1,mid-1,memo);   //egg broken check for down floors of mid
            int right=find(k,n-mid,memo) ;   // not broken check for up floors of mid
            temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
        
     /*
        Here we have k eggs and n floor
        if we drop from i  (i=1 to n):
         i) egg break , now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will break
        ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
      */
        return memo[k][n]=ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor
        vector<vector<int>> memo(K+1,vector<int> (N+1,-1));
        return find(K,N,memo);
         
    }
};


///////////////////////////////////////////////////////////////////////
So I consider this problem in a different way:
dp[M][K]means that, given K eggs and M moves,
what is the maximum number of floor that we can check.

The dp equation is:
dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1,
which means we take 1 move to a floor,
if egg breaks, then we can check dp[m - 1][k - 1] floors.
if egg doesn't breaks, then we can check dp[m - 1][k] floors.

dp[m][k] is the number of combinations and it increase exponentially to N
C++/Java O(KlogN) Time, O(K) Space
  int superEggDrop(int K, int N) {
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++)
            for (int k = K; k > 0; --k)
                dp[k] += dp[k - 1] + 1;
        return m;
    }
