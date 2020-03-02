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
const int N = 100002;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;
const int B=32;

struct suffix{
	int index;
	int fi,sec;
};
bool cmp(struct suffix a,struct suffix b){
	return (a.fi==b.fi) ? (a.sec<b.sec) : (a.fi<b.fi);
}
int p[100005][B];
int SA[N];
string ch;
int n;
int step;

void buildSA(){
	struct suffix suffixes[N];
	for(int i=0;i<n;i++){
		p[0][i] = (ch[i]-'a');
	}
	step=1;
	for(int i=1;(1<<(i-1))<n;i++,step++){
		for(int j=0;j<n;j++){
			suffixes[j].index = j;
			suffixes[j].fi = p[i-1][j];
			suffixes[j].sec = (j+(1<<(i-1)) <n ? p[i-1][j+(1<<(i-1))] : -1);
		}
		sort(suffixes,suffixes+n,cmp);
		for(int j=0;j<n;j++){
			p[i][suffixes[j].index]= (j>0 && suffixes[j].fi ==suffixes[j-1].fi && suffixes[j].sec==suffixes[j-1].sec ?
			p[i][suffixes[j-1].index] :j );
		}

	}
	step=step-1;
	for(int i=0;i<n;i++){
		SA[p[step][i]] = i;
	}
}
int LCP(ll i, ll j){
	if(i==j){
		return n-i;
	}
	ll to=0;
	for(int x=step;x>=0;x--){
		if(p[x][i]==p[x][j]){
			to+=(1<<x);
			i+=(1<<x);
			j+=(1<<x);
		}
	}
	return to;
}



int main(){
    ios::sync_with_stdio(0);
    freopen("easy.txt","r",stdin);
    cin >> ch;
    n=ch.size();
    buildSA();
    for(int i=0;i<n;i++){
    	cout << SA[i] << endl;
    }
    return 0;
}