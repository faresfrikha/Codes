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

ll t,n,a[N];

int main(){
    ios::sync_with_stdio(0);
    freopen("bricks.in","r",stdin);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        ll st=1;
        for(int i=0;i<n;i++){
            if(a[i]==st){
                st++;
            }
        }
        if(st>1)
        cout << n-(st-1) << endl;
        else  cout << -1 << endl;
    }

    return 0;
}
