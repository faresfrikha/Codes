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
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<n;i++)
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
const int MOD = 7 + (ll)1e9;
const int m = 1000105;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;
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

/*int solve(ll n , ll k)
{
    if(n>= (k*k) && ((n-(k*k))%2==0))return 1;
    else return 0;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if (solve(n,k))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}*/
vl v[1000105];
ll vist[1000105],donn[1000105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n;
        rep(i,n+1)
        {
            vist[i]=0;
            donn[i]=0;
        }
        rep(i,n)
        {
            v[i].clear();
            cin>>k;
            rep(j,k)
            {
                ll x;
                cin>>x;
                v[i].pb(x);
            }
        }
        rep(i,n)
        {
            int cond=0;
            for(auto t:v[i])
            {
                if(vist[t])continue;
                vist[t]=1;
                cond=1;
                break;
            }
            if(cond)donn[i]=1;
        }
        ll x=-1,y=-1;
        rep(i,n)
        {
            if(!donn[i])y=i;
        }
        repp(i,n+1)
        {
            if(!vist[i])x=i;
        }
        if(x!=-1 && y!=-1)
        {
            cout<<"IMPROVE\n"<<y+1<<" "<<x<<"\n";
        }
        else cout<<"OPTIMAL\n";
    }
    return 0;
}
