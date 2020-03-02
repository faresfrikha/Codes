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
	for (int ii = 0; ii < 1 ; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
        n=100;
        cout << n << endl;
        for(int i=0;i<n;i++){
            ll xx,y,z,w,o;
            //xx=ra(100)+1;
            xx=1;
            //y=ra(2)+1;
            y=1;
            //z=ra(2)+1;
            z=1;
            //w=ra(2)+1;
            w=0;
            //o=ra(2)+1;
            o=1;
            cout << xx << " " << y << " " << z << " " <<w<<" "<< o << endl;
        }
	}
}
