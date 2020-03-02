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
const int N = 1000000;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;
  

ll profit[N];
ll n;
ll fight[N];

int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> profit[i];
    }
    for(int i=0;i<n;i++){
        string ch;
        cin >> ch;
        ll res=0;
        for(int j=0;j<7;j++){
            res+=(ch[j]-'0')*(1<<(j));
        }
        fight[i]=res;
    }
    ll ans=0;
    for(int i=1;i<(1<<7);i++){
        ll res=0;
        for(int j=0;j<n;j++){
            if(i&fight[j])continue;
            res+=profit[j];
        }
        //cout << res << endl;
        ans=max(ans,res);
    }
    cout << ans;

    return 0;
}