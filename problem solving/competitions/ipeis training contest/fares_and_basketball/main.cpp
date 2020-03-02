            #include <bits/stdc++.h>

                    using namespace std;

                    typedef long long ll;

                    #define mp make_pair
                    #define pb push_back

                    #define f first
                    #define s second

                    ll n,ans,nb,d,x,y;
                    vector< pair<ll,ll> > v;

                    ll dist(pair<ll,ll> u, pair<ll,ll> uu){
                        return abs(u.f-uu.f) + abs(u.s-uu.s);
                    }



                    int main(){
                        cin.tie(0);
                        cout.tie(0);
                        //start
                        cin >> n;
                        for(int i=0;i<n;i++){
                            scanf("%Ld %Ld",&x,&y);
                            v.pb(mp(x,y));
                        }
                        for(int i=0;i<n;i++){
                            ans=1e18;
                            nb=0;
                            for(int j=0;j<n;j++){
                                if(i==j)continue;
                                d=dist(v[i],v[j]);
                                if(d<ans){
                                    ans=min(ans,d);
                                    nb=1;
                                }else if(d==ans){
                                    nb++;
                                }
                            }
                            cout << ans << " " << nb << endl;
                        }





                        return 0;
                    }
