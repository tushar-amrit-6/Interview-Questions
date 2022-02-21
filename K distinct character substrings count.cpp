The idea is to use a sliding window to count the number of substrings with at most K different characters because finding substrings with exactly K characters
will again cost us N ^ 2 times. 
  Therefore we will count as the number of substrings with exactly K different characters will be the number of
  substrings with at most K different characters - number of substrings with at most (K-1) different characters.
int helper(string str, int k) 
{

    int i = 0, j = 0, currCount = 0;
    int result = 0;

    // Array to store count of characters.
    vector<int>count(26, 0);

    while (j < str.size()) 
    {
        // Index for current character.
        int index = str[j] - 'a';

        // Increment count for the current character.
        count[index] += 1;

        if (count[index] == 1) 
        {
            currCount++;
        }

        // Decrement count and increase ith pointer.
        while (currCount > k) 
        {
            count[str[i] - 'a']--;
            if (count[str[i] - 'a'] == 0) 
            {
                currCount--;
            }

            i++;
        }

        // Total substrings.
        result += (j - i + 1);
        j++;
    }
    return result;
}

int countSubStrings(string str, int k) {

    // Calculating for at most k and at most k-1 distinct chars.
    int ans = helper(str, k) - helper(str, k - 1);

    return ans;
}
