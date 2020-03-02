#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long ll;

vector<ll> primes;

const ll N = 1<<20;
ll n = 0;

void sieve()
{
    bitset<N+1> b;
    b.set();
    b[0] = b[1] = 0;
    for (ll p=2; p<=N; p++)
    {
        if (b[p])
        {
            primes.push_back(p);
            for (ll i=p*p; i<=N; i += p)
                b[i] = 0;
        }
    }
    n = primes.size();
}


vector<ll> f(ll x)
{
    vector<ll> v(n,0);
    for (int i=0; i < n; i++)
    {
        ll p = primes[i];
        ll exp = 0;
        while (p <= x)
        {
            exp = exp + (x/p);
            p = p*primes[i];
        }
        v[i] = exp;
    }
    return v;
}

int main()
{
    sieve();
    int T;
    cin >> T;
    while(T--)
    {
        int u,v,w,p,k;
        cin >> u >> v >> w >> p >> k;
        vector<ll> vw = f(w);
        vector<ll> vv = f(v);
        for(int i=0; i<n; i++)
        {
            vw[i] *= p;
            vv[i] *= p;
        }
        vector<int> vu(n,0);
        int idx = 0;
        while(primes[idx]*primes[idx] <= u)
        {
            while(u % primes[idx] == 0)
            {
                u /= primes[idx];
                vu[idx] += k;
            }
            idx++;
        }

        bool poss = true;
        for(int i=0; i<n; i++)
        {
            if(primes[i] == u)
                vu[i] += k;
            if(vw[i] + vv[i] < vu[i])
            {
                poss = false;
                break;
            }
        }
        if(poss)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
