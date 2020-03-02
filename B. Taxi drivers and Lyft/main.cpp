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

//set<char> vowel={'A', 'O', 'Y','E', 'U', 'I','a','o','e','u','i'};

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

/* ll _sieve_size;bitset<10000> bs;vl primes;
        void sieve(ll upperbound) {_sieve_size = upperbound + 1;bs.set();bs[0] = bs[1] = 0;
            for (ll i = 2; i<= _sieve_size; i++) if (bs[i]) {for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;primes.pb(i);} }
*/


ll n,m,x,y,k,z,w,t,l,r,res;
ll a[N];
ll ans[N];
ll pos[N];
bool taxi[N];
pair<ll,ll> ud[N];
pair<ll,ll> du[N];

int main()
{
    ios::sync_with_stdio(0);
    memset(ans,0,sizeof(ans));
    //cin.tie(NULL);
    cin >> n >> m;
    x=0;
    ll h=n+m;
    for(int i=0; i<h; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<h; i++)
    {
        cin >> taxi[i];
        if(taxi[i])
        {
            pos[i]=x;
            x++;
        }
    }
    for(int i=0; i<h; i++)
    {
        if(taxi[i])
        {
            du[i]=mp(a[i],pos[i]);
        }
        else
        {
            if(i>0)
            {
                du[i]=du[i-1];
            }
            else
            {
                du[i]=mp(-1,-1);
            }
        }
    }
    for(int i=h-1; i>=0; i--)
    {
        if(taxi[i]!=0)
        {
            ud[i]=mp(a[i],pos[i]);
        }
        else
        {
            if(i<h-1)
            {
                ud[i]=ud[i+1];
            }
            else
            {
                ud[i]=mp(-1,-1);

            }
        }
    }
    for(int i=0; i<h; i++)
    {
        res=1e18;
        ll j=0;
        if(taxi[i]!=0)
            continue;
        if(du[i].f>=0)
        {
            res=abs(du[i].f-a[i]);
            j=du[i].s;
        }
        // cout << du[i].f << endl;
        if(abs(ud[i].f-a[i])<res && ud[i].f>=0)
        {
            res=abs(ud[i].f-a[i]);
            j=ud[i].s;
        }
        if(0<=j)
        {
            ans[j]+=1;
        }
    }
    for(int i=0; i<m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
