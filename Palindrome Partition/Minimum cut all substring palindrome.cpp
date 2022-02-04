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

Highly Optimised Dynamic Programming Approach
In the previous approach, we calculated the minimum cut while finding all palindromic substring. 
    If we find all palindromic substrings first and then calculate the minimum cut, the solution would optimize.

 

 

We can do that in the following way:

Compute one 2 Dimensional arrays 'isPalindrome[][]' and an array 'cuts[]' 
    where 'isPalindrome[i][j]' stores if a substring with starting index ‘i’ and ending index ‘j’ is a palindrome or not.
Mark isPalindrome[i][i] true as every substring of length 1 is a palindrome.cuts[i] 
is the minimum number of cuts needed for a palindrome partitioning of substring str[0..i].
    Now, find all the palindromic substrings in the given string for each length ‘L’ and for every starting index ‘i’. In the following way:
If the value of ‘L’ is 2 we just compare the 2 characters.
Otherwise, we check the first and last character of the substring and also if isPalindrome[i+1][j-1] is true. If yes, we mark the current substring as a palindrome.
 

Now that we know all the substrings which are Palindromes, We can efficiently find the minimum cuts in the following way:

 

Let cuts[i]  is the minimum number of cuts needed for a palindrome partitioning of substring str[0..i]
If isPalindrome[0][i] is true we say cuts[i]=0.
Otherwise, we first initialize the value of cuts[i] to be infinite.
Then for each ‘i’ we take a variable’ j’ and initialize it to 0.
Then we loop through j such that 0 <= j < i and find update cuts[i], if 1+cuts[j] is less than the current value of cuts[i] 
i.e we find a better way of partitioning the substring str[0...i]  with lesser number of cuts.
We add an extra 1 because the substring is not palindrome we need to make a cut.
Otherwise cuts[i] = cuts[j] + 1 for all j < i and if str[j + 1...i] is a palindrome
Finally, our answer lies at cuts[n-1] which is the final answer
Time Complexity
O(n^2), ‘n’ is the length of the string.

 

As finding all palindromic substrings takes an order of n^2  and finding minimum cuts takes an order of n^2 the final complexity is an order of n^2.

Space Complexity
O(n^2), ‘n’ is the length of the string.

 

We are using a 2 Dimensional array of size ‘n*n’.
    
    int palindromePartitioning(string str) {
    // Get the length of the string
    int n = str.size();

    /* Create two arrays to build the solution
       in bottom up manner cuts[i][j] = Minimum number of cuts needed for palindrome partitioning of substring str[i..j]
       isPalindrome[i][j] = true if substring str[i..j] is  palindrome, else false
       cuts[i][j] is 0 if isPalindrome[i][j] is true */

    int cuts[n];
    bool isPalindrome[n][n];

    int i, j, k, L;  // different looping variables

    // Every substring of length 1 is a palindrome
    for (i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
    }

    /* L is substring length. Build the solution in bottom up manner by
       considering all substrings of length starting from 2 to n. */
    for (L = 2; L <= n; L++) {
        // For substring of length L, set different possible starting indexes
        for (i = 0; i < n - L + 1; i++) {
            j = i + L - 1;  // Set ending index

            /* If L is 2, then we just need to compare two characters. Else
               need to check two corner characters and value of isPalindrome[i+1][j-1] */
            if (L == 2) {
                isPalindrome[i][j] = (str[i] == str[j]);
            } else {
                isPalindrome[i][j] = (str[i] == str[j]) && isPalindrome[i + 1][j - 1];
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (isPalindrome[0][i] == true) {
            cuts[i] = 0;
        } else {
            cuts[i] = INT_MAX;
            for (j = 0; j < i; j++) {
                if (isPalindrome[j + 1][i] == true && 1 + cuts[j] < cuts[i]) cuts[i] = 1 + cuts[j];
            }
        }
    }

    // Return the min cut value for complete string. i.e., str[0..n-1]
    return cuts[n - 1];
}

