struct CentroidDecomposition{
	vector<set<int> > tree;
	vector<int> dad;
	vector<int> sub;

	CentroidDecomposition(vector<set<int>> &tree ) : tree(tree){
		int n =  tree.size();
		dad.resize(n);
		sub.resize(n);
		build(0,-1);
	}


	void build(int u, int p){
		int n = dfs(u, p);
		int centroid = dfs(u,p,n);
		if(p==-1) p=centroid;
		dad[centroid] = p;

		for(auto v: tree[centroid]){
			tree[centroid].erase(v);
			tree[v].erase(centroid):
			build(v,centroid);
		}
	}

	int dfs(int u , int p){
		sub[u]=1;
		for(auto v: tree[u]){
			if(v!=p)sub[u]+=dfs(u,v);
		}
		return sub[u];
	}

	int dfs(int u , int p, int n){
		for(auto v:tree[u]){
			if(v!=p && sub[v]>n/2)return dfs(v,u,n);
		}
		return u;
	}

	int operator[](int i){
		return dad[i];
	}
};

//
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
ll ans=0;

ll tree[N];
ll dad[N];
ll sub[N];
vl child[N];
ll dist[N][20];
bool del[N];
ll depth[N],h[N];
vl e,l;


ll sparset[N][20];

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
    int res=log2(j-i+1);
    if(l[sparset[i][k]]<=l[sparset[j- (1<<k)+1][k]]){
        int x=sparset[i][k];
        return e[x];
    }else{
        int x=sparset[j- (1<<k)+1][k];
        return e[x];
    }
}

int getdist(int i, int j, int bit){
    int x=h[i];
    int y=h[j];
    int z=getsparse(min(x,y),max(x,y));
    int dist = depth[i][bit]%2+depth[j][bit]%2+(a[z]&(1<<bit)?1:0);
    return dist%2;
}


void buildlca(int  src, int par, int dep){
    e.pb(src);
    l.pb(dep);
    depth[src]=dep;
    if(h[src]==-1){
        h[src]=dep;
        for(int i=0;i<20;i++){
            if(a[src]&(1<<i))depth[src][i]++;
        }
        for(auto t: tree[src]){
            depth[t][i]=depth[src][i];
        }
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

int dfs(int u , int p){
    sub[u]=1;
    for(auto v: tree[u]){
        if(del[v])continue;
        if(v!=p)sub[u]+=dfs(v,u);
    }
    return sub[u];
}

int dfs(int u , int p, int n){
    for(auto v:tree[u]){
        if(del[v])continue;
        if(v!=p && sub[v]>n/2)return dfs(v,u,n);
    }
    return u;
}

void build(int u, int p){
    int n = dfs(u, p);
    int centroid = dfs(u,p,n);
    if(p==-1) p=centroid;
    dad[centroid] = p;
    del[centroid] = 1;
    for(auto v: tree[centroid]){
        build(v,centroid);
    }
}
    

int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
    cin >> n;
    
    return 0;
}
