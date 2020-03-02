#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
typedef long long ll;
const int N=1000005;
ll n,a,b,h,tree[N],ind,ans;
map<ll,ll> maa;
vector<pair<pair<ll,ll>,ll> > v;
set<ll> ss;
 
void update(ll x,ll val){
	for(; x<=ind-1;x+=x&(-x)){
		tree[x]=max(tree[x],val);
	}
}
ll get(ll x){
	ll to_return=0;
	for(; x>0;x-=x&(-x)){
		to_return=max(to_return,tree[x]);
	}
	return to_return;
}
 
int main() {
	scanf("%I64d",&n);
	for(int i=0;i<n;i++){
		scanf("%I64d %I64d %I64d",&a,&b,&h);
		v.pb(mp(mp(b,a),h));
		ss.insert(a);
		ss.insert(a-1);
		ss.insert(a+1);
		ss.insert(b+1);
		ss.insert(b);
		ss.insert(b-1);
	}
	ind=1;
	for(auto t: ss){
		maa[t]=ind;
		ind++;
	}
	ans=0;
	sort(v.rbegin(),v.rend());
	for(auto t:v){
		a=get(maa[t.f.f-1]);
		ans=max(ans,a+t.s);
		update(maa[t.f.s],a+t.s);
	}
	cout << ans;
	
	
	return 0;
}