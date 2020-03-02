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
 
 
ll n;
ll a[N];
ll dp[N][4];
void build(ll l , ll r, ll pos){
    if(l==r){
        dp[pos][0]=dp[pos][1]=dp[pos][2]=dp[pos][3]=a[l];
        return ;
    }
    ll mid=(l+r)/2;
    build(l,mid,2*pos+1);
    build(mid+1,r,2*pos+2);
    dp[pos][3]=dp[2*pos+1][3]+dp[2*pos+2][3];
    dp[pos][2]=max(dp[2*pos+1][0]+dp[2*pos+2][1],max(dp[2*pos+1][2],dp[2*pos+2][2]));
    dp[pos][0]=max(dp[2*pos+2][0],dp[2*pos+2][3]+dp[2*pos+1][0]);
    dp[pos][1]=max(dp[2*pos+1][1],dp[2*pos+1][3]+dp[2*pos+2][1]);
}
 
pair<pair<ll,ll>, pair<ll,ll> > get(ll l , ll r, ll pos , ll a, ll b){
    if(l>b || a>r){
        return mp(mp(-1e15,-1e15),mp(-1e15,-1e15));
    }
    if(l>=a && r<=b){
        return mp(mp(dp[pos][0],dp[pos][1]),mp(dp[pos][2],dp[pos][3]));
    }
    ll mid=(l+r)/2;
    pair<pair<ll,ll>,pair<ll,ll> > pa=get(l,mid,2*pos+1,a,b),pa1=get(mid+1,r,2*pos+2,a,b);
    ll x,y,z,w;
    w = pa.s.s + pa1.s.s;
    z = max(pa.f.f+pa1.f.s,max(pa.s.f,pa1.s.f));
    x=max(pa1.f.f,pa1.s.s+pa.f.f);
    y=max(pa.f.s,pa.s.s+pa1.f.s);
    return mp(mp(x,y),mp(z,w));
}
 
ll q;
int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build(0,n-1,0);
    cin >> q;
    for(int i=0;i<q;i++){
        ll l ,r;
        cin >> l >> r;
        l--;r--;
        //cout <<l << " " << r << endl;
        ll ans= get(0,n-1,0,l,r).s.f;
        cout << ans << endl;
    }
    return 0;
} 