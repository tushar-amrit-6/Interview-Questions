You are given a N x 2 2-D array 'Jobs' of 'N' jobs where Jobs[i][0] denote the deadline of i-th job and Jobs[i][1] denotes the profit associated with i-th job.
You will make a certain profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.
  
  In the above approach, for each index in the jobs array, we may have to traverse a boolean array of slots of size maxDeadline. 
    However, we can optimize the above approach by using a set and applying a binary search on the elements of the set. 
    So, we store the elements from maxDeadline to 1 in the set. We traverse the jobs array, and for each job,
we find the nearest element present in the set that is less than or equal to the deadline of that job. 
  If such an element exists in the set, then we add the profit to the answer and remove this element from the set.
  
  
  bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    // Find the maximum deadline among all the jobs.
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    // Create a set "slots".
    set<int, greater<int>> slots;

    // Insert all the elements from maxDeadline to 1 into the set.
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }

    for (int i = 0; i < jobs.size(); i++)
    {

        // If the set is empty or the deadline is less than the last element of the set, then ignore this job.
        if (slots.size() == 0 || jobs[i][0] < *slots.rbegin())
        {
            continue;
        }

        int availableSlot = *slots.lower_bound(jobs[i][0]);
        maxProfit = maxProfit + jobs[i][1];
        slots.erase(availableSlot);
    }

    return maxProfit;
}
