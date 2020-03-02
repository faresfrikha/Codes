#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
int main()
{
	int idx = 3;
	ll n;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 100; ii++){
		if (x[idx] == '9')
                                                    idx++;
		freopen(x, "w", stdout);
		x[idx]++;
		ll i=ii;
		n=(i+1)*(i+1)*(i+1)*(i+1)*(i+1)*(i+1)*(i+1)*(i+1)*(i+1);
		cout << n << endl;


	}
}
