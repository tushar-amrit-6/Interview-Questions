We are getting the timestamps in non-decreasing order only which means we can use binary search here. We add the timestamps at the back of the vector which remains in sorted order and when we need to return total number of timestamps in the range of 60 from the given timestamp we use lower bound which will give the first occurrence of such number in the array and we just subtract it from the size or end of the array to get total of all such occurrences.

Implementation
As described above we push back elements in vector which will always be in sorted order. We return the first element that isn't less than the required element(timestamp-60) using lower_bound.

Time Complexity
\mathcal{O}(\log n )O(logn) as insertion is \mathcal{O}(1 )O(1) and finding the element is logarithmic using binary search.

Space Complexity
\mathcal{O}(n)O(n) we need vector to store element, not sure if this should be included in space complexity as additional space isn't required.

class HitCounter {
    public:
    vector<int> v;
    HitCounter() {
    }

    void add(int timestamp) {
        v.push_back(timestamp);
    }

    int count(int timestamp) {
        return v.end() - lower_bound(v.begin(), v.end(), timestamp - 60);
    }
};



If we are tracking hits in the past 5 mins in seconds granularity which is 300 seconds, create 2 arrays of size 300.
int[] hits = new int[300];

TimeStamp[] times = new TimeStamp[300]; // timestamp of the last counted hit
Given an incoming, mod its timestamp by 300 to see where it locates in the hits array.

int idx = timestamp % 300; => hits[idx] keeps the hit count took place in this second

But before we increase the hit count at idx by 1, the timestamp really belongs to the second that hits[idx] is tracking.
timestamp[i] stores the timestamp of the last counted hit.
If timestamp[i] > timestamp, this hit should be discarded since it did not happened in the past 5 minute.
If timestamp[i] == timestamp, then hits[i] increase by 1.
If timestamp[i] currentTime – 300.


vector<int> times, hits;
  
times.resize(300);
hits.resize(300);
  
/** Record a hit.
   @param timestamp - The current timestamp
   (in seconds granularity). */
void hit(int timestamp)
{
    int idx = timestamp % 300;
    if (times[idx] != timestamp) {
        times[idx] = timestamp;
        hits[idx] = 1;
    }
    else {
        ++hits[idx];
    }
}
  
// Time Complexity : O(1)
  
/** Return the number of hits in the past 5 minutes.
    @param timestamp - The current timestamp (in 
    seconds granularity). */
int getHits(int timestamp)
{
    int res = 0;
    for (int i = 0; i < 300; ++i) {
        if (timestamp - times[i] < 300) {
            res += hits[i];
        }
    }
    return res;
}
// Time Complexity : O(300) == O(1)
