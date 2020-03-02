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
    ll n,m;
    ll a[70];
    ll x;

    int main(){
        ios::sync_with_stdio(0);
        freopen("easy.txt","r",stdin);
        cin >> t;
        while(t--){
            cin >> n >> m;
            ll res=0;
            memset(a,0,sizeof(a));
            for(int i=0;i<m;i++){
                cin >> x;
                res+=x;
                ll b = (ll)log2(x);
                a[b]++;
            }
            if(res<n){
                cout << -1 <<"\n";
                continue;
            }
            bool cond=true;
            res=0;
            for(int i=0;i<61;i++){
                if((1ll<<i) > n)break;
                if((1ll<<i)&n){
                    if(a[i]){
                        a[i]--;
                    }else{
                        ll k=-1;
                        for(int j=i+1;j<61;j++){
                            if(a[j]){
                                k=j;
                                break;
                            }
                        }
                        if(k==-1){
                            cond=false;
                            break;
                        }
                        a[k]--;
                        for(int j=k-1;j>=i;j--){
                            res++;
                            a[j]+=2;
                        }
                        a[i]--;
                    }
                }
                a[i+1]+=a[i]/2;
            }
            if(!cond){
                cout << -1 << "\n";
            }
            cout << res << endl;
        }
        return 0;
    }