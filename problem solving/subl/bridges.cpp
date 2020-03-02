#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
     
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
  
const int MOD = 998244353;
const int N = 1000005;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;
 
const int AlPHA = 26, B = 30;

vl adj[N];
ll disc[N];
ll low[N];
bool vis[N];
ll par[N];
ll n,m;
ll dp[N];
ll type[N];
set<pair<ll,ll> > ss;



void dfs(ll u, ll t){
    vis[u]=1;
    disc[u]=low[u]=t++;
    for(auto v:adj[u]){
        if(vis[v]==0){
            par[v]=u;
            dfs(v,t);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u]){
                ss.insert(mp(min(u,v),max(u,v)));
            }
        }else if (par[u]!=v){
            low[u]=min(low[u],disc[v]);
        }
    }
}

ll tem=0;

void dfs2(ll src){
    vis[src]=1;
    for(auto t: adj[src]){
        if(vis[t])continue;
        if(ss.count(mp(min(src, t),max(src,t)))){
            type[t]=++tem;
            dfs2(t);
        }else{
            type[t]=type[src];
            dfs2(t);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
    memset(par, -1,sizeof(par));
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0,0);
    type[0]=tem;
    dfs2(0);
    for(int i=0;i<n;i++){
        dp[type[i]]++;
    }

    
    return 0;
}