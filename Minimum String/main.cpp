#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<ll> vl ;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const int N = 1000005;
const double PI =4*atan(1);
const ll MAX=9223372036854775807;

//set<char> vowel={'A', 'O', 'Y','E', 'U', 'I','a','o','e','u','i','y'};

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
ll moduloMultiplication(ll a,ll b/*,ll mod*/)
{
    ll res = 0/*;a %= mod*/;
    while (b)
    {
        if (b & 1)
            res = (res + a)/* % mod*/;
        a = (2 * a) /*% mod*/;
        b >>= 1;
    }
    return res;
}
ll power(ll x, ll y,ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
/*       ll _sieve_size;bitset<1500100> bs;vl primes;
        void sieve(ll upperbound) {_sieve_size = upperbound + 1;bs.set();bs[0] = bs[1] = 0;
            for (ll i = 2; i<= _sieve_size; i++) if (bs[i]) {for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;primes.pb(i);} }

*/

ll q,y,k,w,t,l,r,x,n,m;
string ch;
ll z[1000005];

void insatzebi(string ch2)
{
    ll left=0;
    ll right=0;
    for(int k=1; k<n; k++)
    {
        if(k>right)
        {
            right=k;
            left=k;
            while(right<n+m+1 && ch2[right]==ch2[right-left])
                right++;
            z[k]=right-left;
            right--;
        }
        else
        {
            ll k1=k-left;
            if(z[k1]+k-1<right)
            {
                z[k]=z[k1];
            }
            else
            {
                left=k;
                while(right<n+m+1 && ch2[right]==ch2[right-left])
                    right++;
                z[k]=right-left;
                right--;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> t;t++;
    vl fares;
    for(int i=0;i<1005;i++){fares.pb(i);fares.pb(-i);}
    while(--t)
    {
        cin >> ch>> k;
        n=ch.size();
        ll res=0;
        for(int i=0; i<n+1; i++)
        {
            z[i]=0;
        }
        insatzebi(ch);

        for(int i=1; i<n; i++)
        {
            if(z[i]==n-i)
            {
                res=max(res,n-i);
            }
        }
        ll ans=res+(n-res)*k;
        cout<<ans<<"\n";
    }
    return 0;
}
