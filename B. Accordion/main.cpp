#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()

const int MOD = 1000000007;
const int N = 1000007;
const double PI =4*atan(1);
string ch;
ll n,x,ans;
ll p1,p2,p3,p4;
vl fares;

int main(){
    ios::sync_with_stdio(0);
	cin >> ch;
	n=ch.size();
	p1=p2=p3=p4=-1;
	for(int i=0;i<n;i++){
            fares.pb(i);
		if(ch[i]=='['){p1=i;break;}
	}
	if(p1==-1){
		cout << -1<<"\n";
		return 0;
	}
	for(int i=n-1;i>p1;i--){
		if(ch[i]==']'){
			p2=i;fares.pb(i);
			break;
		}
	}
	if(p2==-1){
		cout << -1<<"\n";
		return 0;
	}
	for(int i=p1+1;i<p2;i++){
		if(ch[i]==':'){
			p3=i;
			break;
		}
	}if(p3==-1){
		cout << -1<<"\n";
		return 0;
	}
	for(int i=p2-1;i>p3;i--){
		if(ch[i]==':'){
			p4=i;
			break;
		}
	}
	if(p4==-1){
		cout << -1<<"\n";
		return 0;
	}
	ans=4;
	for(int i=p3;i<p4;i++){
		if(ch[i]=='|'){
			ans++;
		}
	}
	cout << ans<<"\n";

    return 0;
}
