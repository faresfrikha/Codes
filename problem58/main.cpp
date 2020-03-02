#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

const int MOD = 998244353;
const int N = 1000005;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;

ll t;
ll b,n;
ll k[11];
ll p[11][105];
ll ans;
void solve(ll u, ll rem){
    if(u>=n && rem>=0){
        ans=min(ans,rem);
    }
    if(u>=n || rem<0){
            return ;
    }else {
        for(int i=0;i<k[u];i++){
            solve(u+1,rem-p[u][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> b;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> k[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<k[i];j++){
                cin >> p[i][j];
            }
        }
        ans=b;
        solve(0,b);
        cout << b-ans << endl;
    }
    return 0;
}
