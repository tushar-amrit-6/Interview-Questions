Efficient Approach [ O(n) solution ] :

If sum of all the elements of the array is not divisible by 3, return 0.
It is obvious that the sum of each part of each contiguous part will be equal to the sum of all elements divided by 3.
Let’s create an array cnt[ ], where cnt[ i ] equals 1, if the sum of elements from i-th to n-th equals Array_Sum/3 else 0. Now, calculate the cumulative sum of the cnt array from the last index.
Thus, we receive very simple solution: for each prefix of initial array 1…i with the sum that equals Array_Sum/3 we need to add to the answer sums[ i+2 ].
int countways(int a[], int n)
{
    int cnt[n] = {0}, s = 0;
     
    // Calculating the sum of the array
    // and storing it in variable s
    for (int i = 0 ; i < n ; i++)
    {
        s += a[i];
    }
 
    // Checking s is divisible by 3 or not
    if (s % 3 != 0)
        return 0;
     
    // Calculating the sum of each part
    s /= 3;
     
    int ss = 0;
     
    // If the sum of elements from i-th to n-th
    // equals to sum of part putting 1 in cnt
    // array otherwise 0.
    for (int i = n-1; i >= 0 ; i--)
    {
        ss += a[i];
        if (ss == s)
            cnt[i] = 1;
    }
     
    // Calculating the cumulative sum
    // of the array cnt from the last index.
    for (int i = n-2 ; i >= 0 ; i--)
        cnt[i] += cnt[i + 1];
     
    int ans = 0;
    ss = 0;
     
    // Calculating answer using original
    // and cnt array.
    for (int i = 0 ; i+2 < n ; i++)
    {
        ss += a[i];
        if (ss == s)
            ans += cnt[i + 2];
    }
    return ans;
}
