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
ll sum=0;
int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n;
    sum=(n)*(n+1)/2;
    ll three=1;
    while(three<=n){
        sum-=2*three;
        three*=3;
    }
    cout << sum ;
    return 0;
}
