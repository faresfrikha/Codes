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
const int N = 200005;
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

ll _sieve_size;bitset<10000010> bs;vl primes;

            void sieve(ll upperbound) {
              _sieve_size = upperbound + 1;bs.set();bs[0] = bs[1] = 0;
              for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
                for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;primes.push_back((int)i); }
             }
             vl primeFactors(ll N) {
              vl factors;ll PF_idx = 0, PF = primes[PF_idx];
              while (N != 1 && (PF * PF <= N)) {
              	if(N%PF==0)factors.push_back(PF);
                while (N % PF == 0) { N /= PF; }PF = primes[++PF_idx];   }
              if (N != 1) factors.push_back(N);
              return factors;
            }

vl adj[N];
ll n,x,y,ans;
ll a[N];

ll dfs(ll src, ll fac){
	while(a[src]%fac==0)a[src]/=fac;
	ll m1=0,m2=0;
	for(auto t: adj[src]){
		if(a[t]%fac)continue;
		ll y=dfs(t,fac);
		if(y>m1){
			m2=m1;
			m1=y;
		}else if(y>m2){
			m2=y;
		}
	}
	ans=max(ans,m1+m2+1);
	return 1+m1;
}
vl fares;
int main(){
    ios::sync_with_stdio(0);
    sieve(200000);
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n-1;i++){
    	cin >> x >> y;
    	fares.pb(x);
    	x--;y--;
    	fares.pb(y);
    	adj[x].pb(y);
    	adj[y].pb(x);
    }
    ans=0;
    for(int i=0;i<n;i++){
    	vl v=primeFactors(a[i]);
    	for(auto u:v){
    		ans=max(ans,dfs(i,u));
    	}
    }
    cout << ans <<"\n";
    return 0;
}
