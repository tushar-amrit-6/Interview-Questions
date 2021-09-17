From example graph, we can see that this is Shortest path problem/Minimum spanning tree problem. In this problem, 
in a graph, view cities as nodes, pipe connects two cities as edges with cost. here, wells costs, it is self connected edge,
we can add extra node as root node 0, and connect all 0 and i with costs wells[i]. So that we can have one graph/tree, 
and how to get minimun spanning trees / shortest path problem in a graph. Please see below detailed steps for analysis.
class Solution {
public:
    // runtime O(NlogN), space O(N)
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        parent.resize(n+1, 0);
       
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
        
        // represent the wells as additional pipes to a water-source node 0.
        for(int i = 0; i < wells.size(); i++){
            pipes.push_back({0, i+1, wells[i]});
        }  
        
        sort(pipes.begin(), pipes.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[2] < rhs[2];            
        });


                
        int cost = 0;
        for(int i = 0; i < pipes.size(); i++){

            int first = find(pipes[i][0]);
            int second = find(pipes[i][1]);
            if(first != second){
                cost += pipes[i][2];
                merge(pipes[i][0], pipes[i][1]);
            }
        }

        
        
        
        return cost;
    }
        
private:
    vector<int> parent;
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    
    void merge(int x, int y){
        int parentX = find(x);
        int parentY = find(y);
        if(parentX != parentY){
            parent[parentY] = parentX;
        }
    }
};
