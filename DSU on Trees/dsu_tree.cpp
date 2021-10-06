int dfs(int x,int par,int big)
{
    int mx=0,bigc=-1,maxi=-1;
    for (auto i:g[x])
    {
        if (i!=par&&maxi<sz[i])
        {
            maxi=sz[i];
            bigc=i;
        }
    }
    for (auto i:g[x])
    {
        if (i!=par&&i!=bigc)
        {
            dfs(i,x,0);
        }
    }
    if (bigc!=-1)
    {
        mx=max(mx,dfs(bigc,x,1));
        swap(v[x],v[bigc]);
    }
    v[x].pb(x);
    update(mx,x,1);
    for (auto i:g[x])
    {
        if (i!=par&&i!=bigc)
        {
            for (auto j:v[i])
            {
                update(mx,j,1);
                v[x].pb(j);
            }
        }
    }
    res[x]=ans[mx];
    if (big==0)
    {
        for (auto i:v[x])
        {
            update(mx,i,-1);
        }
    }
    return mx;
}
