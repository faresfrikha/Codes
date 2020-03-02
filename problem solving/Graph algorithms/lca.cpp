#include <bits/stdc++.h>
     
        using namespace std;
        typedef long long ll;
        typedef vector<ll> vl ;
     
        #define mp make_pair
        #define pb push_back
        #define f first
        #define s second
        #define all(v) (v).begin(),(v).end()
     
     
        const int MOD = 998244353;
        const int N = 500005;
        const double PI =4*atan(1);
        const double eps = 1e-7;
        
        vector<set<int> > tree;
        vector<int> dad, sub, deptth, e, l, h;
        ll sparset[N][20];
        int n,m;
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
    int x=h[i];
    int y=h[j];
    int z=getsparse(min(x,y),max(x,y));
    int dist = depth[i]+depth[j]-2*depth[z];
    return dist;
}


void buildlca(int  src, int par, int dep){
    e.pb(src);
    l.pb(dep);
    depth[src]=dep;
    if(h[src]==-1)h[src]=cnt;
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

        int main(){
            ios::sync_with_stdio(0);
            freopen("easy.txt","r",stdin);
            
            cin >> n >> m;
            tree.resize(n);
            for(int i=0;i<n-1;i++){
                int x, y;
                cin >> x >> y;
                x--;y--;
                tree[x].insert(y);
                tree[y].insert(x);
            }
            dad.resize(n);
            sub.resizer(n);
            depth.resize(n);
            h.assign(n,-1);
            buildlca(0,-1,1);

            //build(0,-1);
            return 0;
        }