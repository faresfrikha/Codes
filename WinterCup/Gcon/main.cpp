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
ll tree[4000005];
ll q;
string ch;

void build(ll l , ll r, ll pos){
    if(l==r){
        if(ch[i]=='0'){
            tree[pos][0]=1;
            tree[pos][1]=1;
            tree[pos][2]=0;
            tree[pos][3]=0;
            tree[pos][4]=1;
            tree[pos][5]=1;
            tree[pos][6]=1;
            tree[pos][7]=0;
        }else{
            tree[pos][0]=0;
            tree[pos][1]=0;
            tree[pos][2]=1;
            tree[pos][3]=1;
            tree[pos][4]=1;
            tree[pos][5]=1;
            tree[pos][6]=0;
            tree[pos][7]=1;
        }
        return ;
    }
    ll mid=(l+r)/2;
    build(l,mid,2*pos+1);
    build(mid+1,r,2*pos+2);
    tree[pos][0]=tree[2*pos+1][0];
    if(tree[2*pos+1][0]==mid-l+1){
        tree[pos][0]=tree[2*pos+1][0]+tree[2*pos+2][0];
    }
    if(tree[2*pos+1][0]==tree[2*pos+1][3]){
        tree[pos][0]=tree[2*pos+1][0]+tree[2*pos+2][2];
    }
    tree[pos][2]=tree[2*pos+1][2];
    if(tree[2*pos+1][2]==mid-l+1){
        tree[pos][2]=tree[2*pos+1][2]+tree[2*pos+2][2];
    }
}


int main(){
    ios::sync_with_stdio(0);
    freopen("bracket.in","r",stdin);
    cin >> t ;
    while(t--){
        cin >> n >> q;
        cin >> ch;
        for(int i=0;i<4*n;i++){
            vl v;
            v.assign(0,8);
            tree[i]=v;
        }
        build(0,n-1,0);
    }


    return 0;
}
