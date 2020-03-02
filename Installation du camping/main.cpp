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

    int t [350][350];
    int n,m;

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

    int verif (int i,int j,int p)
    {
        int h;
        for( h=i; h<i+p; h++)
        {
            for(int k=j;k<j+p;k++)
                if(t[i+h][j+k])
                    return 0;
        }
        return 1;
    }

    int rp(int i,int j)
    {
        int p=0;
        while(1)
        {
            if(!verif(i,j,p))
                return p;
            p++;
            if(i+p==n || j+p==m)
                return p-1;
        }
    }

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cin>>n>>m;
        rep(i,n)
            rep(j,m)
                cin>>t[i][j];
        int ans=0;
        rep(i,n)
            rep(j,m)
                if(!t[i][j])
                    ans=max(ans,rp(i,j));
        cout<<ans;
        return 0;
    }
