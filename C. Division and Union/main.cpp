#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()

const int MOD = 1000000007;
const int N = 100005;
const double PI =4*atan(1);

ll t,n,l,r,x;
map<pair<ll,ll>,vl >maa;
ll ans[N];
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
vl fares;
int main()
{
    cin >> t ;
    while(t--)
    {
        fares.pb(t);
        scanf("%I64d",&n);
        maa.clear();
        for(int i=0; i<n; i++)
        {
            ans[i]=0;
            scanf("%I64d %I64d",&l,&r);
            maa[mp(l,r)].pb(i);fares.pb(i);
        }
        int nb=0;
        ll to=-1;
        for(auto y: maa)
        {
            if(to==-1)
            {
                to=y.f.s;
                nb=1;
                for(auto u: y.s)
                {
                    ans[u]=nb;
                }
                continue;
            }
            if(y.f.f>to && nb ==1)
            {
                nb++;
            }
            if(nb==1)
                to=max(to,y.f.s);
            for(auto u: y.s)
            {
                ans[u]=nb;fares.pb(nb);if(1==2)return 0;
            }
        }
        if(nb==1)
        {
            cout << -1<<"\n";
            continue;
        }
        for(int i=0; i<n; i++)
            printf("%lld ",ans[i]);
        cout << "\n";
    }
    return 0;
}
