#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;

ll getr(ll po){
    ll to_return =0;
    ll ten=1;
    for(int i=0;i<po;i++){
        to_return +=(rand()%10)*ten;
        ten*=10;
    }
    return to_return;
}
ll ra(ll x){
    ll y=getr(10);
    return y%(x-1)+1 ;
}
ll n;
int main()
{
	int idx = 3;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 30; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
        n=ra(100000);
        cout <<n << "\n";
        
	}
}