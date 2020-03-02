#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
int main()
{
	int idx = 3;
	ll n,k,q,xx,l,r,y;
	set<ll> ss;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 5; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
		ss.clear();
		n= rand() % 100000 + 1 ;
		k= 0;
		//y=min(100000ll,(n)*(n+1)/2);
		q= rand() % 100000 + 1;
		cout << n <<" " << k << " " << q << endl;
		for(int i=0;i<n;i++){
            xx=rand() %(1000000) +1;
            cout << xx << " ";
		}
		cout << endl;
		for(int i=0;i<k;i++){
            xx=rand()% n +1;
            while(ss.count(xx)){
                xx=rand()% n +1;
            }
            ss.insert(xx);
            cout << xx << " ";
		}
		if(k)cout << endl;
        for(int i=0;i<q;i++){
            l=rand() % n +1;
            r= rand() % (n-l+1) + l ;
            cout <<l << " " << r << endl;
        }


	}
}
