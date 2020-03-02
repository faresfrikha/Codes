#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()

const int MOD = 786433;
const int N = 1000005;
const double PI =4*atan(1);

ll power(ll x, ll y,ll p){ll res = 1;x = x % p;
while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

ll b,k,ans;
ll a[N];


int main(){
    ios::sync_with_stdio(0);
    cin >> b >> k;
    for(int i=0;i<k;i++){
    	cin >> a[i];
    }
    reverse(a,a+k);
    ans=0;
    for(int i=0;i<k;i++){
    	ans+=(a[i]*power(b,i,2))%2;
    }
    ans%=2;
    if(ans==0){
    	cout << "even";
    }else{
    	cout << "odd";
    }
    return 0;
}
