Use min heap to store the meeting rooms end time. If new meeting start time is greater or equal than least element, update it.
If not, open a new meeting room. 
Time Complexity : O(NlogN).
 int Solution::solve(vector<vector<int> > &v) {
   priority_queue <int, vector<int>, greater<int> > pq; 
    sort(v.begin(),v.end());
    pq.push(v[0][1]);
    int count=1;
    for(int i=1;i<v.size();i++)
    {
        
        if(v[i][0]<pq.top()) count++;
        else pq.pop();
        pq.push(v[i][1]);
        
    }
    return count;
}
