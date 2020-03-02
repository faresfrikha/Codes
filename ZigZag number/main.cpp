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
    ll m1[11][11];
    memset(m1,0,sizeof(m1));
    rep(i,10)
    {
        for(int j=i; j<10; j++)
        {
            m1[i][j]=1;
        }
    }
    ll m2[11][11];
    memset(m2,0,sizeof(m2));
    rep(i,10)
    {
        for(int j=0; j<=i; j++)
        {
            m2[i][j]=1;
        }
    }
    ll m3[11][11];
    memset(m3,0,sizeof(m3));
    rep(i,10)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                m3[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll k,ans=0;
        cin >> k;
        ll m4[11][11];
        memset(m4,0,sizeof(m4));
        ll test[11][11];
        memset(test,0,sizeof(test));
        rep(i,10)
        {
            rep(j,10)
            {
                test[i][j]=m3[i][j];
            }
            m4[i][i]=1;
        }
        bitset<64> n=(k/2);
        rep(i,64)
        {
            if(n[i]!=0)
            {
                ll o[11][11];
                memset(o,0,sizeof(o));
                rep(i,10)
                {
                    rep(j,10)
                    {
                        rep(p,10)
                        {
                            o[i][j]+=test[i][p]*m4[p][j];
                            o[i][j]%=1000000007;
                        }
                    }
                }
                rep(i,10)
                {
                    rep(j,10)
                    {
                        m4[i][j]=o[i][j];
                    }
                }
            }
            ll y[11][11];
            memset(y,0,sizeof(y));
            rep(i,10)
            {
                rep(j,10)
                {
                    rep(p,10)
                    {
                        y[i][j]+=test[i][p]*test[p][j];
                        y[i][j]%=1000000007;
                    }
                }
            }
            rep(i,10)
            {
                rep(j,10)
                {
                    test[i][j]=y[i][j];
                }
            }
        }
        if(!(k%2==0))
        {
            ll o[11][11];
            memset(o,0,sizeof(o));
            rep(i,10)
            {
                rep(j,10)
                {
                    rep(p,10)
                    {
                        o[i][j]+=m4[p][j]*m1[i][p];
                        o[i][j]%=1000000007;
                    }
                }
            }
            rep(i,10)
            {
                rep(j,10)
                {
                    m4[i][j]=o[i][j];
                }
            }
        }
        rep(i,9)
        {
            ans+=m4[0][i] ;
            ans%=1000000007;
        }
        cout << ans%1000000007 << "\n";
    }
    return 0;
}
