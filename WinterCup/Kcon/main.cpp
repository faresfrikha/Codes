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
ll n;
ll a[N];

int main(){
    ios::sync_with_stdio(0);
    freopen("bracket.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        stack<ll> ss;
        ll cnt=0;
        ll ans=0;
        ll pos=0;
        ll len=0;
        ll arglen=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                cnt++;
                if(cnt>ans){
                    ans=cnt;
                    pos=i+1;
                }
                ss.push(i);
            }else{
                cnt--;
                ll x=ss.top();
                ss.pop();
                if(i-x+1>len){
                    len=i-x+1;
                    arglen=x+1;
                }
            }

        }
        cout << ans << " "<< pos << " " << len << " " << arglen << endl;
    }

    return 0;
}

2
10
2 5
6 5
2 1
7 9
7 2
2 4
8 7
10 8
10 3
7
1 3
1 8
1 1
2 1
1 10
2 10
1 2
10
2 5
6 5
2 1
7 9
7 2
2 4
8 7
10 8
10 3
7
1 3
1 8
1 1
2 1
1 10
2 10
1 2


