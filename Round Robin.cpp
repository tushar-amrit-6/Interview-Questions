/* 
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the number of processes given to be scheduled.
*/

typedef long long ll;

// Function to find the waiting time for all processes.
void findwaitingTime(vector<int>& processes, int n, vector<int>& bt, vector<ll>& wt, int quantum){
    vector<ll> rem_bt(n, 0);

    // Copy the burst time into rt[].
    for(int i = 0; i < n; i++){
        rem_bt[i] = bt[i];
    }

    // Current Time.
    ll t = 0; 

    // Keep traversing processes in round robin manner until all of them are not done.
    while(1){
        bool done = true;

        // Traverse all processes one by one repeatedly.
        for(int i = 0; i < n; i++){
            if(rem_bt[i] > 0){
                // There is a pending process.
                done = false;

                if(rem_bt[i] > quantum){

                    // Increase the value of t i.e. shows how much time a process has been processed.
                    t += quantum;

                    // Decrease the burst_time of current process by quantum.
                    rem_bt[i] -= quantum;
                }
                // If burst time is smaller than or equal to quantum. Last cycle for this process.
                else{

                    // Increase the value of t i.e. shows how much time a process has been processed.
                    t += rem_bt[i];

                    // Waiting time is current time minus time used by this process.
                    wt[i] = t - bt[i];

                    // As the process gets fully executed make its remaining burst time = 0.
                    rem_bt[i] = 0;
                }
            }
        }
        // If all processes are done.
        if(done == true){
            break;
        }
    }
}

void findTurnAroundTime(vector<int>& processes, int n, vector<int>& bt, vector<ll>& wt, vector<ll>& tat){

    // Calculating turnaround time.
    for(int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
    }
}

vector<ll> findavgTime(vector<int>& processes, int n, vector<int>& bt, int quantum){
    vector<ll> wt(n, 0);
    vector<ll> tat(n, 0);

    findwaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);

    ll total_wt = 0;
    ll total_tat = 0;

    for(int i = 0; i < n; i++){
        total_wt += wt[i];
        total_tat += tat[i];
    }

    return {total_wt/n, total_tat/n};
}
