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


ll ans=0;
ll checkans(ll m,ll x,ll k,ll n)
{

    if (!x)
        ans++;

    ll r =(ll)floor(pow(m,1.0/n));

    for (int i=k+1; i<=r; i++)
    {
        ll a=x-(ll)pow(i,n);
        if (a>=0)
            checkans(m,x-(ll)pow(i,n),i,n);
    }
    return ans;
}

ll check(ll x,ll n)
{
    return checkans(x,x,0,n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll n,x;
    cin>>x>>n;
    cout<<check(x,n);
    return 0;
}
