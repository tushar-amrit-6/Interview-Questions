//Without duplicates iterative
class Solution {
public:
    int search(vector<int>& nums, int target) {

        //For fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        //Iterative binary search
        while(left<=right)
        {
            mid = (left+right)/2;
            //cout<<nums[mid]<<"\n";
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>=nums[left])
            {
                if(target<=nums[mid] && target>=nums[left])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(target>=nums[mid] && target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};

//Without Duplicates recursive
int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;
 
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
 
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid]) {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
        /*If key not lies in first half subarray,
           Divide other half  into two subarrays,
           such that we can quickly check if key lies
           in other half */
        return search(arr, mid + 1, h, key);
    }
 
    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);
 
    return search(arr, l, mid - 1, key);
}
 
//With Duplicates recursive
int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;
 
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
 
    // The tricky case, just update left and right
    if ((arr[l] == arr[mid])
        && (arr[h] == arr[mid]))
    {
        ++l;
        --h;
        return search(arr, l, h, key);
    }
 
    // If arr[l...mid] is sorted
    if (arr[l] <= arr[mid]) {
 
        // As this subarray is sorted, we can quickly
        // check if key lies in any of the halves
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
 
        // If key does not lie in the first half
        // subarray then divide the other half
        // into two subarrays such that we can
        // quickly check if key lies in the other half
        return search(arr, mid + 1, h, key);
    }
 
    // If arr[l..mid] first subarray is not sorted
    // then arr[mid... h] must be sorted subarray
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);
 
    return search(arr, l, mid - 1, key);
}
