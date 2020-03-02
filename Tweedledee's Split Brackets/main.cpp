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

bool verif(string ch)
{
    int a1=0,a2=0,b1=0,b2=0;
    rep(i,ch.size())
    {
        if(ch[i]=='(')
            a1++;
        else if(ch[i]==')')
            a2++;
        else if(ch[i]=='[')
            b1++;
        else
            b2++;
    }
    return a1==a2&&b1==b2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string ch;
    cin>>ch;
    if((ch.size()%4)||(ch.size()%2))
    {
        cout<<"impossible";
        return 0;
    }
    if(!verif(ch))
    {
        cout<<"impossible";
        return 0;
    }
    if(ch.size()==4){
        rep(i,4){
            if (ch[i]=='(')cout<<1<<' ';
            else if (ch[i]==')')cout<<1<<' ';
            else if(ch[i]=='[')cout<<2<<' ';
            else cout<<2<<' ';
        }
        return 0;
    }
    int a1=0,a2=0,a3=0,a4=0,s1=0,s2=0;
    rep(i,ch.size())
    {
        if(ch[i]=='(')
        {
            if(s1==ch.size()/2)a1=1;
            if(s2==ch.size()/2)a1=0;
            if(a1==0)
            {
                cout<<1<<' ';s1++;
                a1=1;continue;
            }
            if(a1==1)
            {
                cout<<2<<' ';s2++;
                a1=0;continue;
            }
        }
        if(ch[i]==')')
        {
            if(s1==ch.size()/2)a2=1;
            if(s2==ch.size()/2)a2=0;
            if(a2==0)
            {
                cout<<1<<' ';s1++;
                a2=1;continue;
            }
            if(a2==1)
            {
                cout<<2<<' ';s2++;
                a2=0;continue;
            }
        }
        if(ch[i]=='[')
        {
            if(s1==ch.size()/2)a3=1;
            if(s2==ch.size()/2)a3=0;
            if(a3==0)
            {
                cout<<1<<' ';s1++;
                a3=1;continue;
            }
            if(a3==1)
            {
                cout<<2<<' ';s2++;
                a3=0;continue;
            }
        }
        if(ch[i]==']')
        {
            if(s1==ch.size()/2)a4=1;
            if(s2==ch.size()/2)a4=0;
            if(a4==0)
            {
                cout<<1<<' ';s1++;
                a4=1;continue;
            }
            if(a4==1)
            {
                cout<<2<<' ';s2++;
                a4=0;continue;
            }
        }
    }
    return 0;
}
