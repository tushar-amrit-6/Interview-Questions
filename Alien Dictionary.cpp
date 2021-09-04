/*
    Time Complexity - O(N + K)
    Space Complexity - O(K)
    where N is the number of given words and K is the number of letters in the alphabet of the alien language
*/

#include <unordered_set>
#include <stack>

class Graph
{
public:
    vector<vector<int>> neighbours;
    int numVertices;

    Graph(int vertexCount)
    {
        numVertices = vertexCount;
        neighbours.resize(vertexCount);
    }


    void addEdge(int src, int dest)
    {
        neighbours[src].push_back(dest);
    }


    vector<char> topologicalSort()
    {
        vector<bool> visited(numVertices, false);
        stack<int> completedVertices;

        // Getting the topological sort
        for (int i = 0; i < numVertices; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, completedVertices);
            }
        }

        // Storing the topological sort in a character array
        vector<char> arr(completedVertices.size());
        int curr = 0;

        while (!completedVertices.empty())
        {
            arr[curr++] = ((char)('a' + completedVertices.top()));
            completedVertices.pop();
        }

        return arr;
    }

    void dfs(int curr, vector<bool> &visited, stack<int> &completedVertices)
    {
        
        // Mark the current node as visited.
        visited[curr] = true;

        // Make a recursive call to all the neighbours.
        for (int neighnour : neighbours[curr])
        {
            if (!visited[neighnour])
            {
                dfs(neighnour, visited, completedVertices);
            }
        }

        // All neighbours completed.
        completedVertices.push(curr);
    }
};

vector<char> getAlienLanguage(string *dictionary, int n)
{
    
    // Find the number of unique characters in the strings.
    unordered_set<char> uniqChars;
    for (int i = 0; i < n; ++i)
    {
        for (char c : dictionary[i])
        {
            uniqChars.insert(c);
        }
    }

    Graph *graph = new Graph(uniqChars.size());

    for (int i = 0; i < n - 1; i++)
    {
        string currWord = dictionary[i];
        string nextWord = dictionary[i + 1];

        int compareTill = min(currWord.length(), nextWord.length());

        for (int j = 0; j < compareTill; j++)
        {
            if (nextWord[j] != currWord[j])
            {
                graph->addEdge(currWord[j] - 'a', nextWord[j] - 'a');
                break;
            }
        }
    }

    return graph->topologicalSort();
}
