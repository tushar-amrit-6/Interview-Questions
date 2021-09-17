class DisjointSet
{
	public:
 
	vector<int> parent;
	vector<int> rank;
	
	DisjointSet(int n)
	{
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}
 
	int Find(int k)
	{
		if (parent[k] != k)
			parent[k] = Find(parent[k]);
 
		return parent[k];
	}
 
	void Union(int a, int b)
	{
		int x = Find(a);
		int y = Find(b);
 
		if (x == y)
			return;
 
		if (rank[x] > rank[y])
			parent[y] = x;
		else if (rank[x] < rank[y])
			parent[x] = y;
		else
		{
			parent[x] = y;
			rank[y]++;
		}
	}
};
