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
 
const int AlPHA = 26, B = 30;
 
ll n,x,y;
ll dp[10000005];
 
int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n >> x >> y;
    dp[1]=x;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=min(dp[i-1]+x, dp[i/2]+y);
        }else{  
            dp[i]=min(dp[i-1]+x,min(dp[i/2]+y+x, dp[(i+1)/2]+y+x));
        }
    }
    cout << dp[n];
    return 0;
}