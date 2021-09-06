/*
    Time Complexity: O(N * ( 2 ^ N ))
    Space Complexity: O(N ^ 2)

    Where 'N' is the length of string.
*/

#include <vector>
#include <string>

void partitionHelper(string &s, int start, vector<vector<string>> &ans, vector<string> &currentList, vector<vector<bool>> &dp) 
{

    // If start reach the end of String.
    if (start >= s.length()) 
    {
        // Add the current generated Palindromic Partition to answer List.
        ans.push_back(currentList);
        return;
    }

    for (int k = start; k < s.length(); k++) 
    {

        // Check if substring S[start...k] is Palindrome or not.
        if (dp[start][k]) 
        {
            // Add the substring S[start...k].
            currentList.push_back(s.substr(start, k + 1 - start));

            // Recurence for rest of the string to get all the palindromic partitions.
            partitionHelper(s, k + 1, ans, currentList, dp);

            // Remove the substring S[start...k] from current partition.
            currentList.pop_back();

        }
    }
}

vector<vector<string>> partition(string &s) 
{
    
    // It store all the possible palindromic partitions.
    vector<vector<string>> ans;

    // Create a boolean dp for checking substing[i..j] is palindrome or not.
    vector<vector<bool>> dp (s.length(), vector <bool> (s.length(), false));
    for (int i = 0; i < s.length(); i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) 
            {
                dp[j][i] = true;
            }
        }
    }

    vector<string> currentList;
    // Recursive function to generate all the possible palindromic partitions.
    partitionHelper(s, 0, ans, currentList, dp);

    return ans;

}
