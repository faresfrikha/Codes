#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    return y%(x)+1 ;
}
ll n;
int main()
{
    int idx = 3;
    char x[] = "out00000000000000000000000000000000.txt";
    for (int ii = 0; ii < 5; ii++){
        if (x[idx] == '9')
            idx++;
        freopen(x, "w", stdout);
        x[idx]++;
        //n=50000;
        n=ra(10);
        cout << n << endl;
        for(int i=0;i<n;i++){
            ll y = ra(100000);
            ll bit = ra(100);
            if(bit>50){
                cout << y << " ";
            }else{
                cout << -y << " ";
            }
        }
        cout << endl;
        //ll q = ra(100000);
        ll q= 5;
        cout << q << endl;
        for(int i=0;i<q;i++){
            ll z,y;
            y= ra(n);
            z= ra(y);
            cout << z << " " << y << endl;
        }
       
    }
}
