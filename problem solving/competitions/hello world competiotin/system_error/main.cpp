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

					ll n;


                    int main(){
                        ios::sync_with_stdio(0);
                        cin.tie(0);
                        cout.tie(0);
                        //start
                        cin >> n;
                        if(n%3){
                            cout << n/3+1 << " ";
                        }else{
                            cout << n/3 << " ";
                        }
                        if(n%3==2){
                            cout << n/3 +1 << " ";
                        }else{
                            cout << n/3 << " ";
                        }
                        cout << n/3 << endl;




                        return 0;
                    }
