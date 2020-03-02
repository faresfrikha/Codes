#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ll> vl;

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

ll _sieve_size;
bitset<10000010> bs;
vi primes;

const int MOD = 1000000007;
const int N = 100005;
const double PI =4*atan(1);
const ll MAX=9223372036854775807;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

bool isPrime(ll N)
{
    if (N <= _sieve_size)
        return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0)
            return false;
    return true;
}

ll EulerPhi(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;
    while (N != 1 && (PF * PF <= N))
    {
        if (N % PF == 0)
            ans -= ans / PF;
        while (N % PF == 0)
            N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans -= ans / N;
    return ans;
}

ll n,m,q,y,k,z,w,t,l,r,res,ans,x,n1,m1,a,b;


int main()
{
    ios::sync_with_stdio(0);
    sieve(1000000);
    cin >> a >> b >> k;
    a/=k;
    b/=k;
    ans=0;
    for(int i=1; i<=min(a,b); i++)
    {
        ans+=EulerPhi(i);
    }
    for(int i=min(a,b)+1; i<=max(a,b); i++)
    {
        for(int j=1; j<=min(a,b); j++)
        {
            if(gcd(i,j)==1)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
