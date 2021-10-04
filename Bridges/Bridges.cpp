// Code for finding bridges in a graph.
// Time Complexity - O(n + m) where n is the number of vertices and m is the number of edges in the graph.

vector<int> adj[LIM];
bool visited[LIM];
int tin[LIM], low[LIM], timer;
set<pair<int, int>> bridges;

void dfs(int u, int p)
{
    visited[u] = true;
    tin[u] = low[u] = timer++;

    for(auto x : adj[u])
    {
        if(x == p)
            continue;

        if(visited[x])
            low[u] = min(low[u], tin[x]);
        else
        {
            dfs(x, u);

            low[u] = min(low[u], low[x]);

            if(low[x] > tin[u])
                bridges.insert({u, x});
        }
    }
}

void findBridges()
{
    for(int i=0; i<LIM; i++)
    {
        visited[i] = false;
        adj[i].clear();
        tin[i] = low[i] = -1;
    }

    timer = 0;
    bridges.clear();

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            dfs(i, -1);
    }
}
