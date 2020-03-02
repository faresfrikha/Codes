#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef pair<ll,ll> pl;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

const int MOD = 1000000007;
const int N = 1000002;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;

vector<set<int> > tree;
vector<int> dad, sub, depth, e, l, h;
ll sparset[N][20];
int n;
int cnt=0;

void buildsparse(){
    int i,j;
    for(i = 0; i < cnt ;i++){
        sparset[i][0]=i;
    }
    for( j=1; 1<<j <cnt ; j++){
        for(i=0; i + (1<<j) -1 <cnt ; i++){
            if(l[sparset[i][j-1]] < l[sparset[i+( 1<<(j-1))][j-1]])sparset[i][j]=sparset[i][j-1];
            else sparset[i][j]=sparset[i + (1<<j-1)][j-1];
        }
    }
}

int getsparse(int i, int j){
    int k=log2(j-i+1);
    if(l[sparset[i][k]]<=l[sparset[j- (1<<k)+1][k]]){
        int x=sparset[i][k];
        return e[x];
    }else{
        int x=sparset[j- (1<<k)+1][k];
        return e[x];
    }
}

int getdist(int i, int j){
    int z=getsparse(min(i,j),max(i,j));
    return z;
}


void buildlca(int  src, int par, int dep){
    e.pb(src);
    l.pb(dep);
    depth[src]=dep;
    if(h[src]==-1){
            h[src]=cnt;
    }
    cnt++;
    for(auto t: tree[src]){
        if(t!=par){
            buildlca(t,src, dep+1);
            e.pb(src);
            l.pb(dep);
            cnt++;

        }
    }
}
ll t;
ll q;

int main(){
    ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    cin >> t;
    while(t--){
        cin >> n;
        cnt=0;
        tree.resize(n);
        dad.resize(n);
        sub.resize(n);
        e.clear();
        l.clear();
        depth.resize(n);
        h.assign(n,-1);
        for(int i=0;i<n;i++){
            tree[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int x, y;
            cin >> x >> y;
            x--;y--;
            tree[x].insert(y);
            tree[y].insert(x);
        }


        buildlca(0,-1,1);
        buildsparse();
        set<ll> ss,sl;
        cin >> q;
        while(q--){
            ll ty,u;
            cin >> ty >> u;
            u--;
            if(ty==1){
                ss.insert(h[u]);
                sl.insert(-h[u]);
            }else{
                ss.erase(h[u]);
                sl.erase(-h[u]);
            }
            if(ss.empty()){
                cout << -1 << endl;
            }else{
                ll x=(*ss.begin());
                ll y=-(*sl.begin());
                cout << getdist(x,y)+1 << endl;
            }
        }
    }

    return 0;
}
