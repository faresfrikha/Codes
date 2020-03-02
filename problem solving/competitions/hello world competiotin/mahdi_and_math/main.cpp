            #include <bits/stdc++.h>

                    using namespace std;

                    typedef long long ll;
                    typedef long double ld;

                    typedef vector<ll> vl;

                    #define mp make_pair
                    #define pb push_back
                    #define f first
                    #define s second
                    #define lb lower_bound
                    #define ub upper_bound

                    const int MOD = 1000000007;
                    const int N = 1000005;
                    const double PI =4*atan(1);
                    const ll MAX=9223372036854775807;
                    ll n,k,ans,x;
                    unordered_set<ll> ss;
                    vl v;


                    int main(){
                        //ios::sync_with_stdio(0);
                        //freopen("baklava.in","r",stdin);
                        cin.tie(0);
                        cout.tie(0);
                        //start
                        cin >> n >> k;
                        for(int i=0;i<n;i++){
                            cin >> x;
                            if(ss.count(x)==0){
                                v.pb(x);
                                ss.insert(x);
                            }
                        }
                        sort(v.begin(),v.end());
                        if(v.size()<k){
                            cout <<"NO";
                            return 0;
                        }
                        cout <<"YES ";
                        ans=0;
                    	n=v.size();
                        for(int i=0;i<n;i++){
                            x=n-(k-(i+1));
                            if(x>=n)break;
                            if(x<=i)continue;
                            ans=max(ans,v[x]-v[i]);
                        }
                        cout << ans;


                        return 0;
                    }
