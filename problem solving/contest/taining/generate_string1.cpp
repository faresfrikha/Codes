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
  
ll n;
string ch="";
ll c[26];
int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
    cin >> n;
    for(int i=0;i<26;i++){
        c[i]=i+1;
        n-=c[i];
    }
    if(n<0){
        cout << -1;
        return 0;
    }
    ll j=25;
    for(int i=0;i<n;i++){
        if(j==-1){
            j=25;
        }
        c[j]++;
        j--;
    }
    ll sum=0;
    for(int i=0;i<26;i++){
        //cout << c[i] << " ";
        sum+=c[i];
        for(int j=0;j<c[i];j++){
            ch+=(char('a'+i));
        }
    }
    cout << ch;

    return 0;
}