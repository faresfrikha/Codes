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

ll n,m,q,k,x,y,z;
int main()
{   srand(time(0));
	int idx = 3;
	char xx[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 10 ; ii++){
		if (xx[idx] == '9')
			idx++;
		freopen(xx, "w", stdout);
		xx[idx]++;
        n=ra(100000)+1;
        q=100000;
        cout << n << " " << q << endl;
        for(int i=0;i<n;i++){
            x=ra(100000)+1;
            cout << x << " ";
        }
        cout << endl;
        for(int i=0;i<q-1;i++){
            x=ra(2)+1;
            if(x==1){
                y=ra(n)+1;
                z=ra(y)+1;
                cout << x << " " <<1 << " " << n << endl;
            }else{
                y=ra(n)+1;
                z=ra(10)+1;
                cout << x << " " << y << " " << z << endl;
            }
        }
        y=ra(n)+1;
        z=ra(y)+1;
        cout << 1 << " " << z << " " << y << endl;
	}
}
