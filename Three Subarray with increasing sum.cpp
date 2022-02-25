Generate the prefix sum array and suffix sum array.
Initialize two pointers s and e to find the sum of the second subarray.
Iterate over the array, increment curr_subarray_sum with arr[e] while curr_subarray_sum less than prefix_sum[s – 1] and keep incrementing e.
Whenever curr_subarray_sum is ≥ prefix_sum[s – 1], then check if curr_subarray_sum is ≤ suffix_sum[e]. If found to be true, increment count.
Reduce curr_subarray_sum by arr[s] and increment s.
Repeat the above steps and finally, print count

int findCount(int arr[], int n)
{
 
    // Stores the prefix sums
    int prefix_sum[n];
 
    prefix_sum[0] = arr[0];
 
    for(int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
 
    // Stores the suffix sums
    int suffix_sum[n];
 
    suffix_sum[n - 1] = arr[n - 1];
 
    for(int i = n - 2; i >= 0; i--)
        suffix_sum[i] = suffix_sum[i + 1] + arr[i];
 
    int s = 1, e = 1;
    int curr_subarray_sum = 0, count = 0;
 
    // Traverse the given array
    while (s < n - 1 && e < n - 1)
    {
         
        // Updating curr_subarray_sum until
        // it is less than prefix_sum[s-1]
        while (e < n - 1 && curr_subarray_sum <
               prefix_sum[s - 1])
        {
            curr_subarray_sum += arr[e++];
        }
 
        if (curr_subarray_sum <= suffix_sum[e])
        {
             
            // Increase count
            count++;
        }
 
        // Decrease curr_subarray_sum by arr[s[]
        curr_subarray_sum -= arr[s++];
    }
 
    // Return count
    return count;
}
