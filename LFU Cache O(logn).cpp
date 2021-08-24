typedef pair<int,int> ii;

class LFUCache {
public:
    priority_queue<pair<int,ii>, vector<pair<int,ii>>, greater<pair<int,ii>>> pq;
    unordered_map<int,int> m;
    unordered_map<int,int> freq;
    int cap;
    int t=0;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        put(key,m[key]);
        return m[key];
        
    }
    
    void put(int key, int value) {
        if(cap==0){
            return;
        }
        if(m.find(key)==m.end()&&m.size()==cap){
			/// capacity full
            while(m.size()==cap){
			// try to actually remove an element from our maps
                auto x = pq.top();
                if(freq[x.second.second]==x.first){
				// this entry actually is a valid entry( freq[key] = freq_while_this_element_was_inserted)
                    m.erase(x.second.second);
                    freq.erase(x.second.second);
                }
                pq.pop();
            }            
        }
		// fill priority_queue and increase time
        m[key] = value;
        freq[key]++;
        pq.push({freq[key],{t++,key}});
        
    }
};
