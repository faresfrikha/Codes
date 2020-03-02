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
	for (int ii = 0; ii < 10; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
        n=ra(1000);
        cout <<n << "\n";
        for(int i=0;i<n;i++){
            ll y=ra(1000);
            cout << y << " ";
        }
        cout << endl;
        for(int i=0;i<n;i++){
            string sh="";
            for(int j=0;j<7;j++){
                ll y= ra(100);
                if(y>50){
                    sh+='1';
                }else{
                    sh+='0';
                }
            }
            cout << sh << endl;
        }
	}
}
