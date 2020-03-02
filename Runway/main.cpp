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

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll h[n],c[n];
        rep(i,n)
        {
            cin>>h[i]>>c[i];
        }
        ll ans=1e18;
        rep(i,n-k+1)
        {
            vector<pair<ll,ll> > a;
            ll ab=0,am=0,as=0,af=0,ag=0;
            for(int j=i; j<i+k; j++)
            {
                a.pb(mp(h[j],c[j]));
                am+=c[j];
                //as+=[j];
            }
            sort(all(a));
            rep(j,k)
            {
                as+=a[j].s*(a[j].f-a[0].f);
            }
            //am-=c[0];
            rep(j,k)
            {
                if(!j)
                    ans=min(ans,as);
                else
                    ans=min(ans,as+af*(a[j].f-a[j-1].f)+ag);
                if(j-k+1<0)
                    as-=(a[j+1].f-a[j].f)*(am-af-a[j].s);

                if(j>=1)
                    ag+=af*(a[j].f-a[j-1].f);
                af+=a[j].s;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
