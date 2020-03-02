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
 
const int MOD = 1000000007;
const int N = 1000000;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;
  
ll n,q;
ll tree[N];
ll a[N];
void update(ll u,ll val ){
	for(;u<=200005;u+=u&(-u)){
		tree[u]=max(tree[u],val);
	}
}

ll get(ll u){
	ll res=0;
	for(;u>0;u-=u&(-u)){
		res=max(res,tree[u]);	
	}
	return res;
}


int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	ll x=get(a[i]-1);
    	update(a[i],x+1);
    	ans=max(ans,x+1);
    }
    cout << ans;

    return 0;
}