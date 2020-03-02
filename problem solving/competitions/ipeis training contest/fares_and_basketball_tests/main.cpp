#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
int main()
{
	int idx = 3;
	ll n,xx,y;
	char x[] = "out00000000000000000000000000000000.txt";
	for (int ii = 0; ii < 5; ii++){
		if (x[idx] == '9')
			idx++;
		freopen(x, "w", stdout);
		x[idx]++;
		n=1000;
		cout << n << endl;
		for(int i=0;i<n;i++){
            xx=rand()%1000000000 +1 ;
            y=rand()%1000000000 +1 ;
            cout << xx << " " << y << endl;
		}


	}
}
