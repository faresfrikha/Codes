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

ll n,m,ss;
vector<pair<ll,ll> > ra;
ll type[N];
ll dp[N];
ll tree[N];
vector<pair<ll,ll> > v[N];

void update(ll l , ll r, ll pos, ll ind , ll val){
    if(l==r && l==ind){
        tree[pos]=val;
        return;
    }
    if(l>ind || r<ind)return;
    ll mid=(l+r)/2;
    update(l,mid, 2*pos+1, ind, val);
    update(mid+1,r,2*pos+2,ind ,val);
    tree[pos]=min(tree[2*pos+1],tree[2*pos+2]);
}

ll get(ll l , ll r , ll pos, ll a, ll b){
    if(l>=a && r<=b){
        return tree[pos];
    }
    if(l>b || r<a){
        return 1e17;
    }
    ll mid=(l+r)/2;
    return min(get(l,mid,2*pos+1,a,b),get(mid+1,r,2*pos+2,a,b));
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m >> ss;
    for(int i=0;i<n;i++){
        ll l,r;
        cin >> l >> r;
        ra.pb({l,r});
    }
    for(int i=0;i<m;i++){
        ll l,r,c;
        cin >> l >> r>> c;
        v[r].pb({l,c});
    }
    sort(all(ra));
    ll pos=0;
    for(int i=0;i<n;i++){
        for(int j=max(pos,ra[i].f);j<=ra[i].s;j++){
            type[j]=1;
        }
        pos=max(pos,ra[i].s);
    }

    dp[0]=0;
    for(int i=1;i<=ss;i++){
        dp[i]=dp[i-1]+type[i]*(1ll+(ll)1e14);
        for(auto t:v[i]){
            dp[i]=min(dp[i],t.s+get(0,ss-1, 0, t.f-2,i-2));
        }
        update(0,ss-1,0,i-1,dp[i]);
    }
    if(dp[ss-1]<=1e14){
        cout << dp[ss-1];
    }else{
        cout <<-1;
    }
    return 0;
}
