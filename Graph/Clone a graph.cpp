class Solution {
public:
    unordered_map<Node*, Node*> hash;
    Node *cloneGraph(Node *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new Node(node -> val);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cloneGraph(x) );
           }
       }
       return hash[node];
    }
};
