#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
int main()
{
	int idx = 3;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 15; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
		ll n,k;
		n=100000;
		k= rand() % (n-1)+2;
		cout <<n << " " << k << endl;
		for(int i=0;i<n;i++){
            ll x=rand()%(1000000) +1;
            cout << x << " ";
		}
		cout << endl;


	}
}
