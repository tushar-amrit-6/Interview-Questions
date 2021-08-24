class LFUCache {
private:
    int num;
    int time;
    int capacity;
    struct Node{
        int key;
        int cnt;
        int time;
        Node(int key, int cnt, int time){
            this->key = key;
            this->cnt = cnt;
            this->time = time;
        }
        bool operator < (const Node& a) const {
            if (this->cnt == a.cnt) {
                return this->time > a.time;
            }
            return this->cnt > a.cnt;
        }
    };
    priority_queue<Node, vector<Node>> frequency;
    unordered_map<int, int> cache;
    unordered_map<int, int> count;
    unordered_map<int, int> tag;
public:
    LFUCache(int capacity) {
        this->time = 0;
        this->num = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        count[key]++;
        tag[key] = time;
        time++;
        return cache[key];
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            count[key]++;
            tag[key] = time;
        } else if (num < capacity) {
            frequency.push(Node(key, 1, time));
            cache[key] = value;
            count[key] = 1;
            tag[key] = time;
            num++;
        } else {
            bool flag = false;
            while(!frequency.empty()){
                Node top = frequency.top();
                frequency.pop();
                if (top.cnt==count[top.key] && tag[top.key]==top.time) {
                    ejectKey(top.key);
                    flag = true;
                    break;
                }
                frequency.push(Node(top.key, count[top.key], tag[top.key]));
            }
            if (flag) {
                cache[key] = value;
                count[key] = 1;
                tag[key] = time;
                frequency.push(Node(key, 1, time));
            }
        }
        time++;
        return ;
    }
private:
    void ejectKey(int key){
        count.erase(key);
        cache.erase(key);
        tag.erase(key);
    }
};
