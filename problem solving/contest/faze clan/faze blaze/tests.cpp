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
    for (int ii = 0; ii < 2; ii++){
        if (x[idx] == '9')
            idx++;
        freopen(x, "w", stdout);
        x[idx]++;
        n=100000;
        //n=ra(100000);
        cout << n << endl;
        for(int i=0;i<n;i++){
            ll a,b,c;
            b=ra(1000000000);
            //b=1000000-i;
            //a=5000-i;
            if(b==1){a=1;b=2;}
            else a=ra(b-1);
            c=ra(1000000000);
            cout << a << " " << b << " " << c << endl;
        }
       
    }
}
