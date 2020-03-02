#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef pair<ll,ll> pl;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

const int MOD = 1000000007;
const int N = 1000002;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;

ll t;
ll a,b,c;
vl v;
int main(){
    ios::sync_with_stdio(0);
    freopen("three.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> a >> b >> c;
        v.clear();
        v.pb(a);
        v.pb(b);
        v.pb(c);
        sort(all(v));
        if(v[0]==v[1]){
            cout << v[2] << endl;
        }else{
            cout << v[0] << endl;
        }
    }

    return 0;
}
