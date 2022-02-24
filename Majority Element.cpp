/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' is the number of elements in the given array/list
*/

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();

    // Array for storing final answer.
    vector<int> majorityElement;

    // Variables for storing the elements which may occur more than n/3 times.
    int firstCandidate = 0, secondCandidate = 0;

    // Variables for storing the frequency of the candidate elements.
    int firstCount = 0, secondCount = 0;

    // Iterate through the array.
    for (int i = 0; i < n; i++)
    {
        // Increment firstCount if the current element is equal to firstCandidate.
        if (arr[i] == firstCandidate)
        {
            firstCount = firstCount + 1;
        }

        // Increment secondCount if the current element is equal to secondCandidate.
        else if (arr[i] == secondCandidate)
        {
            secondCount = secondCount + 1;
        }
        // Change value of the firstCandidate to the current element if firstCount is equal to 0.
        else if (firstCount == 0)
        {
            firstCandidate = arr[i];
            firstCount = 1;
        }

        // Change value of the secondCandidate to the current element if secondCount is equal to 0.
        else if (secondCount == 0)
        {
            secondCandidate = arr[i];
            secondCount = 1;
        }

        // Otherwise decrement firstCount and secondCount by 1.
        else
        {
            firstCount = firstCount - 1;
            secondCount = secondCount - 1;
        }
    }

    firstCount = 0;
    secondCount = 0;

    // Iterate through the array to find frequency of firstCandidate and secondCandidate.
    for (int i = 0; i < n; i++)
    {
        // Increment firstCount if the current element is equal to firstCandidate.
        if (arr[i] == firstCandidate)
        {
            firstCount = firstCount + 1;
        }

        // Increment secondCount if the current element is equal to secondCandidate.
        else if (arr[i] == secondCandidate)
        {
            secondCount = secondCount + 1;
        }
    }

    // Include firstCandidate in the answer if its frequency is more than n/3.
    if (firstCount > n / 3)
    {
        majorityElement.push_back(firstCandidate);
    }

    // Include secondCandidate in the answer if its frequency is more than n/3.
    if (secondCount > n / 3)
    {
        majorityElement.push_back(secondCandidate);
    }

    // Return all stored majority elements.
    return majorityElement;
}
