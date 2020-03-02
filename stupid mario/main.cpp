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
    // Don't uncomment this line! What's the time complexity of your solution? COMPLEXITY : O(nlog(n))

    //"Truth can only be found in one place: the code."
    //                              - Robert C. Martin
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    map<string ,string> m;
    string ch1,ch2;
    cin>>ch1>>ch2;
    rep(i,t)
    {
        string c1,c2;
        cin>>c1>>c2;
        if(m[c1]!=ch2)m[c1]=c2;
    }
    string ans=ch1;
    while(ans!=ch2);
    {
        cout<<m[ans]<<" ";
        ans=m[ans];
    }
    return 0;
}
