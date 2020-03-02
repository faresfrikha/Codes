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
    int n,k;
    cin >> n >> k;
    int t[n];
    for(int i=0; i<n; i++)
        cin >> t[i];
    set<int> s;
    map<int,int> m;
    int idx = 0;
    while(s.size() != k && idx < n)
    {
        s.insert(t[idx]);
        m[t[idx]]++;
        idx++;
    }
    if(s.size() < k)
    {
        cout << -1 << " " << -1 << "\n";
        return 0;
    }
    idx--;
    if(k == 1)
    {
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    int ansr=idx,ansl=0;
    int l = 0, r = idx;
    while(l < r && r < n)
    {
        while(m[t[l]] >= 2)
        {
            m[t[l]]--;
            l++;
            if(r-l < ansr - ansl)
            {
                ansl = l;
                ansr = r;
            }
        }
        int oldr = r;
        while(m[t[r]] != 0 && r < n)
        {
            r++;
        }
        if(r != n)
            for(int i = oldr + 1; i<=r; i++)
                m[t[i]]++;

        while(m[t[l]] >= 1 && l<r)
        {
            m[t[l]]--;
            l++;
            if(m[t[l-1]] == 0)
            {
                break;
            }
        }
        if(r-l < ansr - ansl)
        {
            ansl = l;
            ansr = r;
        }
    }
    cout << ansl+1 << " " << ansr+1 << "\n";
    return 0;
}
