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

int main()
{
    ios::sync_with_stdio(0);
    ll n,q;
    cin>>n>>q;
    ll ans =0,r=0,c=0;
    map<pair<int,int>,int>m;
    while(q--)
    {
        ll a,b,x;
        cin>>a>>b>>x;
        ll k=m[mp(a,b)];
        if(m[mp(a,b)])ans-=(n-1)*m[mp(a,b)];
        m[mp(a,b)]=x;
        if(a==1)
        {
            ans+=n*x-c;
            r+=x;c-=k;
        }
        else
        {
            ans+=n*x-r;
            c+=x;
            r-=k;
        }
        //if(m[mp(a,b)])ans-=(n-1)*x;
        cout<<ans<<"\n";
    }
    return 0;
}
