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
#define ub upper_bound

const int MOD = 1000000007;
const int N = 300005;
const double PI =4*atan(1);
const ll MAX=9223372036854775807;
int dx[]= {1,-1,0,0,1,-1,1,-1};
int dy[]= {0,0,1,-1,1,1,-1,-1};

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}
bool issquare(ll w )
{
    return trunc(sqrt(w))*trunc(sqrt(w))==w;
}
bool isprime(ll u)
{
    for(ll i=2; i<=(int)sqrt(u); i++)
    {
        if(u%i==0)
            return 0;
    }
    return 1;
}
ll mod(ll to_mod,ll MOD)
{
    to_mod%=MOD;
    while(to_mod<0)
        to_mod+=MOD;
    return to_mod%MOD;
}
ll moduloMultiplication(ll a,ll b,ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}
ll power(ll x, ll y/*,ll p*/)
{
    ll res = 1;
    x = x /*% p*/;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x)/* % p*/;
        y = y>>1;
        x = (x*x) /*% p*/;
    }
    return res;
}
ll n,m,x,y,res,t,k,z,w,l,r,ans,a,b,h;
vector<pair<ll,ll> > v;
int main()
{

    ios::sync_with_stdio(false);
    cin >> n >> h;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    if(n==1)
    {
        cout << h+v[0].s-v[0].f << "\n";
        return 0;
    }
    ll j=0;
    x=h;
    res=0;
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            x=max(x,h+v[i].s-v[i].f);
            ans=v[i].s-v[i].f;
            continue;
        }
        ans+=v[i].s-v[i].f;
        res+=v[i].f-v[i-1].s;
        while(res>=h)
        {
            res-=v[j+1].f-v[j].s;
            ans-=(v[j].s-v[j].f);
            j=j+1;
        }
        x=max(x,v[i].s-v[j].f+h-(v[i].s-v[j].f-ans));

    }
    cout << x ;


    cout<<"\n";
}
