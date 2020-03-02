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
ll n,u,v;
ll a[N];

int main(){
    ios::sync_with_stdio(0);
    freopen("friendship.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> n >> u >> v;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        ll sum=0;
        for(int i=1;i<n;i++){
            sum+=min(v,u*(a[i]-a[i-1]));
        }
        cout << sum << endl;
    }

    return 0;
}
