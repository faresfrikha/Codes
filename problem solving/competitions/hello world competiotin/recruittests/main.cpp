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
    ll y=getr(9);
    return y%x;
}

ll n,m,q,k;
int main()
{   srand(time(0));
	int idx = 3;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 7 ; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
        n=100000;
        k=ra(n)+1;
        cout <<n  << " " << k << endl;
        for(int i=0;i<n;i++){
            ll y=ra(100000)+1;
            cout << y <<  " ";
        }

	}
}
