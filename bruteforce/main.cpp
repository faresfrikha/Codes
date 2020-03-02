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

const int MOD = 1000000007;
const int N = 1000005;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;

ll n;
ll b;
ll x;
ll t;
int main(){
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> b >> x;
        ll k=b;
        ll cnt=1;
        while(x>k){
            x-=k;
            cnt++;
            k*=b;
        }
        k/=b;
        cnt--;

    }
    cout << -1;
}
