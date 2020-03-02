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
ll n,k;
ll dp[105][105];
unordered_map<ll,ll> maa , mal;
set<ll> ss;

ll tab[N][2];

ll getarea(ll i, ll j , ll o , ll p){
    i=maa[i];
    j=maa[j];
    o=maa[o];
    p=maa[p];
    return (p-o)*(j-i);
}

int main(){
    ios::sync_with_stdio(0);
    freopen("big.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> n >> k;
        ss.clear();
        maa.clear();
        mal.clear();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            ll x,y;
            cin >> x >> y;
            ss.insert(x);
            ss.insert(y);
            tab[i][0]=x;
            tab[i][1]=y;
        }
        ll cnt=1;
        for(auto t:ss){
            maa[cnt]=t;
            mal[t]=cnt;
            cnt++;
        }

        for(int i=0;i<n;i++){
            ll x,y;
            x=mal[tab[i][0]];
            y=mal[tab[i][1]];
            dp[x][y]=1;
        }
        for(int i=1;i<cnt;i++){
            for(int j=1;j<cnt;j++){
                dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        ll ans=5e18;
        for(int i=1;i<cnt;i++){
            for(int j=i;j<cnt;j++){
                ll o=1;
                for(int p=1;p<cnt;p++){
                    ll x= dp[j][p]+dp[i-1][o-1]-dp[i-1][p]-dp[j][o-1];
                    while(x>=k){
                        o++;
                        x= dp[j][p]+dp[i-1][o-1]-dp[i-1][p]-dp[j][o-1];
                        if(x<k){
                            o--;
                            break;
                        }
                    }
                    x= dp[j][p]+dp[i-1][o-1]-dp[i-1][p]-dp[j][o-1];
                    if(x>=k){
                        ans=min(ans,getarea(i,j,o,p));
                    }
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}


