// Code for finding articulation points/cut vertices in a graph.
// Time Complexity - O(n + m) where n is the number of vertices and m is the number of edges in the graph.

vi adj[LIM];
bool visited[LIM];
int tin[LIM], low[LIM], timer;
set<int> cutPoints;

void dfs(int u, int p)
{
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;

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

            if(low[x] >= tin[u] && p != -1)
                cutPoints.insert(u);

            children++;
        }
    }

    if(p == -1 && children > 1)
        cutPoints.insert(u);
}

void findCutPoints()
{
    for(int i=0; i<LIM; i++)
    {
        visited[i] = false;
        adj[i].clear();
        tin[i] = low[i] = -1;
    }

    timer = 0;
    cutPoints.clear();

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            dfs(i, -1);
    }
}
