void Graph::topologicalSortUtil(int v, bool visited[],

                                stack<int>& Stack)
{

    // Mark the current node as visited.

    visited[v] = true;
 

    // Recur for all the vertices

    // adjacent to this vertex

    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)

        if (!visited[*i])

            topologicalSortUtil(*i, visited, Stack);
 

    // Push current vertex to stack

    // which stores result

    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()

void Graph::topologicalSort()
{

    stack<int> Stack;
 

    // Mark all the vertices as not visited

    bool* visited = new bool[V];

    for (int i = 0; i < V; i++)

        visited[i] = false;
 

    // Call the recursive helper function

    // to store Topological

    // Sort starting from all

    // vertices one by one

    for (int i = 0; i < V; i++)

        if (visited[i] == false)

            topologicalSortUtil(i, visited, Stack);
 

    // Print contents of stack

    while (Stack.empty() == false) {

        cout << Stack.top() << " ";

        Stack.pop();

    }
}




//Kahn


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
vector<int> tsort;
int din[ MAXN ];

void kahn(int n) {
	queue<int > q;
	for(int i = 1 ; i <= n; ++i) 
		if( din[i] == 0 ) 
			q.push(i);
	while(!q.empty()) {
		int cur = q.front();
		tsort.push_back(cur);
		q.pop();
		
		for(int node : adj[cur]) {
			din[node]--;
			if(din[node] == 0) 
				q.push(node);
		}
	}
} 

int32_t main() {
	int n , m;
	cin >> n >> m;
	
	for(int i = 0 ; i <= n; ++i) 
		adj[i].clear() , din[i] = 0;
	tsort.clear();
	
	for(int i = 0 ; i < m; ++i) {
		int u , v; 
		cin >> u >> v;
		adj[u].push_back(v);
		din[v]++;
	}
	
	kahn(n);
	
	
	if( (int)tsort.size() == n ) {
		cout << "Topsort : "; for(auto &i : tsort ) cout << i << " "; cout << "\n";
	} else {
		cout << "Topsort doesn't exist\n";
	}
}
