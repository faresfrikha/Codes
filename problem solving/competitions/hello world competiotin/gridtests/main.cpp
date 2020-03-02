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

ll n,m,k;
int main()
{   srand(time(0));
	int idx = 3;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 3 ; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
        n=2;
        m=ra(999)+2;
        k=2;
        cout <<n << " "<<m  << " " << k << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll x=ra(k)+1;
                cout << x << " ";
            }
            cout << endl;
        }

	}
}
