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

int solve(string ch)
{
    stack<char> s;
    char c;
    rep(i,ch.size())
    {
        if (ch[i]=='('||ch[i]=='['||ch[i]=='{')
        {
            s.push(ch[i]);
            continue;
        }
        if (s.empty())
           return 0;

        switch (ch[i])
        {
        case ')':
            c=s.top();
            s.pop();
            if(c=='{'||c=='[')
                return 0;
            break;
        case '}':
            c=s.top();
            s.pop();
            if (c=='('||c=='[')
                return 0;
            break;

        case ']':
            c=s.top();
            s.pop();
            if(c=='('||c=='{')
                return 0;
            break;
        }
    }
    return (s.empty());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    // Don't uncomment this line! What's the time complexity of your solution? COMPLEXITY : O(n)

    //"Truth can only be found in one place: the code."
    //                              - Robert C. Martin

    ll t; cin>>t;
    while(t--){
	string ch;
    cin>>ch;
	if (solve(ch))
		cout<<"YES\n";
	else
		cout<<"NO\n";}
    return 0;
}
