            #include <bits/stdc++.h>

                    using namespace std;

                    typedef long long ll;
                    typedef long double ld;

                    typedef vector<ll> vl;

                    #define mp make_pair
                    #define pb push_back
                    #define f first
                    #define s second

                    const int MOD = 1000000007;
                    const int N = 400005;
                    const double PI =4*atan(1);
                    const ll MAX=9223372036854775807;

                    ll mod(ll to_mod,ll MOD){to_mod%=MOD;while(to_mod<0)to_mod+=MOD;return to_mod%MOD;}
                    ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)
                        res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
                    ll power(ll x, ll y,ll p){ll res = 1;x = x % p;
                        while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

                        void modInverse(int a, int m)
                            {
                                int x, y;
                                int g = gcdExtended(a, m, &x, &y);
                                if (g != 1)
                                    cout << "Inverse doesn't exist";
                                else
                                {
                                    // m is added to handle negative x
                                    int res = (x%m + m) % m;
                                    cout << "Modular multiplicative inverse is " << res;
                                }
                            }

                        int gcdExtended(int a, int b, int *x, int *y)
                            {
                                // Base Case
                                if (a == 0)
                                {
                                    *x = 0, *y = 1;
                                    return b;
                                }

                                int x1, y1; // To store results of recursive call
                                int gcd = gcdExtended(b%a, a, &x1, &y1);

                                // Update x and y using results of recursive
                                // call
                                *x = y1 - (b/a) * x1;
                                *y = x1;

                                return gcd;
                            }



                    ll n,m,q,y,k,z,w,t,l,r,res,x,ans,inv,a,b;

                    ll geta(ll n,ll k){
                        ll u=power(k,n,MOD);
                        ll v=(power(5,n,MOD)+((n%2==0)?1:-1)*2)*inv;
                        v=moduloMultiplication(u,v,MOD);
                        return v;
                    }

                    ll getb(ll n,ll k){
                        ll u=power(k,n,MOD);
                        ll v=(power(5,n,MOD)+((n%2==0)?1:-1))*inv;
                        v=moduloMultiplication(u,v,MOD);
                        return v;
                    }


                    int main(){
                        //ios::sync_with_stdio(0);
                        //freopen("baklava.in","r",stdin);
                        cin.tie(0);
                        cout.tie(0);
                        //start
                        inv=modInverse(3,MOD);
                        cin >> t;
                        while(t--){
                            cin >> x >> y >> z;
                            cin >> k;
                            cin >> n;
                            a=geta(n,(k+1)/6);
                            b=getb(n,(k+1)/6);
                            x=a*x+b*(y+z);
                            x=mod(x,MOD);
                            y=a*y+b*(x+z);
                            y=mod(y,MOD);
                            z=a*z+b*(x+y);
                            z=mod(z,MOD);
                            cout << x <<" " << y << " " << z << endl;
                        }


                        return 0;
                    }
