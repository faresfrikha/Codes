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
string ch;
ll dist[105];

bool ispal(string fh){
    for(int i=0;i<fh.size()/2;i++){
        if(fh[i]!=fh[fh.size()-i-1])return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
    cin >> n;
    cin >> ch;
    for(int i=0;i<=n;i++){
        dist[i]=1e18;
    }
    dist[0]=0;
    for(int i=0;i<n;i++){
        string sh="";
        for(int j=i;j<n;j++){
            sh+=ch[j];
            if(ispal(sh)){
                dist[j+1]=min(dist[j+1],dist[i]+1);
            }
        }
    }
    cout << dist[n] ;

    return 0;
}