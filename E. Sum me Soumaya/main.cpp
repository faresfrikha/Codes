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

const int MOD = 7 + (ll)1e9;
const int N = 700105;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;

ll t;
ll n;
ll m;
int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        if(i*(n-i)==m){
            cout << i << " " << n-i ;
            return 0;
        }
    }
    return 0;
}
