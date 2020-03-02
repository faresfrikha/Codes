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
ll q;
ll u,v;
string b1,b2;

int main(){
    //ios::sync_with_stdio(0);
    freopen("data.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> q;
        while(q--){
            cin >> u >> v;
            b1="";
            b2="";
            while(u){
                if(u%2){
                    b1+='1';
                }else{
                    b1+='0';
                }
                u/=2;
            }
            while(v){
                if(v%2){
                    b2+='1';
                }else{
                    b2+='0';
                }
                v/=2;
            }
            ll i=b1.size()-1;
            ll j=b2.size()-1;
            //cout << i << " " << j << endl;
            //cout << b1[i] <<  " " << b2[j] << endl;
            //cout << b1 << " " << b2 << endl;
            while(i>=0 && j>=0 && (b1[i]==b2[j])){
                i--;j--;
            }
           // cout << i << " " << j << endl;
            //cout << b1 << " " << b2 << endl;
            cout << i+j+2 << endl;
        }
    }

    return 0;
}
