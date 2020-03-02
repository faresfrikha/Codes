#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound //upper_bound(all(a),h{position})-a.begin()
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<n;i++)

const int MOD = 1000000007;
const int N = 300005;
const double PI =4*atan(1);
const ll MAX=9223372036854775807;

ll n,m,x,y,res,t,k,z,w,l,r,a,d;
vector<pair<ll,ll> > adj[N];
ll dist[N];
bool vis[N];
ll parent[N];
stack<ll> ans;

void dijkstra(ll src)
{
    for(int i=0; i<n; i++)
    {
        vis[i]=0;
        dist[i]=1e18;
        parent[i]=-1;
    }
    dist[src]=0;
    priority_queue<pair<ll,ll> > pq;
    pq.push(mp(0,src));
    while(!pq.empty())
    {
        pair<ll,ll> ras=pq.top();
        pq.pop();
        //cout << ras.s << endl;
        if(vis[ras.s])
            continue;
        vis[ras.s]=1;
        for(int t=0; t<adj[ras.s].size(); t++)
        {
            if(dist[adj[ras.s][t].f]>-ras.f+adj[ras.s][t].s)
            {
                dist[adj[ras.s][t].f]=-ras.f+adj[ras.s][t].s;
                parent[adj[ras.s][t].f]=ras.s;
                pq.push(mp(-dist[adj[ras.s][t].f],adj[ras.s][t].f));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n>>m;
    for(int i=0; i<m; i++)
    {
        cin >>x >> y >> z;
        x--;
        y--;
        adj[x].pb(mp(y,z));
        adj[y].pb(mp(x,z));
    }
    dijkstra(0);
    if(dist[n-1]<1e18)
    {
        ans.push(n-1);
        ll ras=n-1;
        while(parent[ras]!=-1)
        {
            ans.push(parent[ras]);
            ras=parent[ras];
        }
        while(!ans.empty())
        {
            cout << ans.top()+1 << " ";
            ans.pop();
        }
    }
    else
    {
        cout <<-1;
    }


    return 0;
}
