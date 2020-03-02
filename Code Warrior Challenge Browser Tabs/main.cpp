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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(k==1 || k==n)cout<<1<<"\n";
        else cout<<2<<"\n";
    }
    return 0;
}
