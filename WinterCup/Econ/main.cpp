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
ll a,b;
int main(){
    ios::sync_with_stdio(0);
    freopen("theorem.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> a >> b;
        if(a==0 && b==0){
            cout << "YES\n";
            continue;
        }
        if(b==0){
            cout << "NO\n";
            continue;
        }
        if(abs(a)%abs(b)==0 && a*b>0){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";

    }

    return 0;
}
