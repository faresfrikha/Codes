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
  
ll n,x,y;
string ch;
ll a,b;
ll vis[N];
vl v;
ll dp[305][305];
ll a1,a2;

ll solve(string ch, string sh, ll i, ll j){
    if(i>=n){
        return a2-j;
    }
    if(j>=a2){
        return a1-i;
    }

    if(dp[i][j]>=0)return dp[i][j];
    ll to_return =1e15;
    to_return = 1+solve(ch,sh,i+1,j);
    if(ch[i]==sh[j])to_return =min(to_return , solve(ch,sh,i+1,j+1));
    else to_return =min(to_return , 1+ solve(ch,sh,i+1,j+1));
    to_return =min(to_return , 1+solve(ch, sh, i,j+1));
    return dp[i][j]=to_return ;

}

ll editdist(string ch,string sh){
    a1=ch.size();
    a2 =sh.size();
    memset(dp,-1,sizeof(dp));
    return solve(ch,sh,0,0);
}




int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
    ch="a";
    string fh;
    cin >> fh;
    cout << ch << endl;
    x=editdist(ch,fh);
    cout << x << endl;
    if(x==0){
        return 0;
    }
    ch="b";
    cout << ch << endl;
    y=editdist(ch,fh);
    cout << y << endl;
    if(y==0){
        return 0;
    }
    if(x!=y){
        if(x>y){
            ch="";
            for(int i=0;i<=y;i++){
                ch+="b";
            }
            cout << ch << endl;
            x=editdist(ch,fh);
            cout << x << endl;
            return  0;      
        }else{
            ch="";
            for(int i=0;i<=x;i++){
                ch+="a";
            }
            cout << ch << endl;
            x=editdist(ch,fh);
            cout << x << endl;
            return 0;
        }
    }
    if(x<y){
        n=x+1;
    }else{
        n=y+1;
    }

    string sh1="";
    ll y=0;
    for(int i=0;i<n-1;i++){
        ch=sh1+'b';
        for(int j=i+1;j<n;j++){
            ch+='a';
        }
        cout << ch << endl;
        x=editdist(ch,fh);
        cout << x << endl;
        if(x==0){
             return 0;
        }
        v.pb(x);
        sh1+='a';
    }
    ll ma=0;
    for(int i=0;i<n-1;i++){
        ma=max(ma,v[i]);
    }
    bool cond=false;
    for(int i=0;i<n-1;i++){
        if(v[i]<ma){
            cond=true;
        }
    }
    if(cond==true){
        b=ma-1;
    }else if(ma==2){
        ch="";
        for(int i=0;i<n-1;i++)ch+='a';
            ch+='b';
        cout << ch << endl;
        x=editdist(ch,fh);
        cout << x << endl;
        return 0;
    }else if(ma==1){
        ch="";
        for(int i=0;i<n-1;i++)ch+='a';
            ch+='a';
        cout << ch << endl;
        x=editdist(ch,fh);
        cout << x << endl;
        return 0;
    }else{
        b=ma+1;
    }
    ch="";
    y=b;
    for(int i=0;i<n-1;i++){
        if(v[i]<b){
            y--;
            ch+='b';
        }else{
            ch+='a';
        }
    }
    if(y)ch+='b';
    else ch+='a';
    cout << ch << endl;
    x=editdist(ch,fh);
    cout << x << endl;
    return 0;
}