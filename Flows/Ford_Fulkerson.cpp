//100gods

#include <bits/stdc++.h>
#define int long long
#define vec2 vector<vector<int>>
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("elegant.in","r",stdin);freopen("elegant.out","w",stdout)
#define pii pair <int,int>
#define vii vector <int>
#define vpii vector <pii>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define minii LLONG_MAX
#define all(x) x.begin(), x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define double long double
#define eb emplace_back
const double pi = 3.1415926535898;
const int mod=1e9+7;
//const int mod=998244353;

using namespace std;

const int N=1005;

vii g[N];
int a[N][N];
int vis[N];
int source,sink;

int dfs(int x,int amt)
{
    if (x==sink)
    {
        return amt;
    }
    vis[x]=1;
    for (auto i:g[x])
    {
        if (a[x][i]&&!vis[i])
        {
            int val=dfs(i,min(amt,a[x][i]));
            if (val>0)
            {
                a[x][i]-=val;
                a[i][x]+=val;
                return val;
            }
        }
    }
    return 0;
}


int32_t main()
{
    fio;
    int n;
    cin>>n;
    
    //graph input;
    

    int ans=0;
    int val=-1;
    while (val!=0)
    {
        mem(vis,0);
        val=dfs(source,1e9);
        ans+=val;
    }
    cout<<ans;
    return 0;
}
