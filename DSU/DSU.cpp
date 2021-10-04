vector<int> Arr(MAXN), sz(MAXN);
void initialize()
{
    for(int p = 0; p<MAXN; p++)
    {
        Arr[ p ] = p ;
        sz[ p ] = 1;
    }
}
int root (int p)
{
    while(Arr[ p ] != p)
    {
        Arr[ p ] = Arr[ Arr[ p ] ] ;
        p = Arr[ p ];
    }
    return p;
}
void unions(int A, int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(root_A==root_B)
        return ;
    if(sz[root_A] < sz[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        sz[root_B] += sz[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        sz[root_A] += sz[root_B];
    }
}
