#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
int main()
{
	int idx = 3;
	ll troll=1000000;
	ll easy=99999;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 80; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;


		ll n, k;
		n=rand() % easy + 2;
		k= rand()% (n-1) + 2;
		cout << n << " " << k << endl;
		for(int i=0;i<n;i++){
            ll x=rand()%troll +1;
            cout << x << " ";
		}
		cout << endl;




	}
}
