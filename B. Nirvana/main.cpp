// CPP Program to find the number in a
// range having maximum product of the
// digits

#include <bits/stdc++.h>
using namespace std;

// Returns the product of digits of number x
long long product(long long x)
{
	int prod = 1;
	while (x) {
		prod *= (x % 10);
		x /= 10;
	}
	return prod;
}

// This function returns the number having
// maximum product of the digits
long long findNumber(int l, long long r)
{
	// Converting both integers to strings
	string a = to_string(l);
	string b = to_string(r);

	// Let the current answer be r
	int ans = r;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '0')
			continue;

		// Stores the current number having
		// current digit one less than current
		// digit in b
		string curr = b;
		curr[i] = ((curr[i] - '0') - 1) + '0';

		// Replace all following digits with 9
		// to maximise the product
		for (int j = i + 1; j < curr.size(); j++)
			curr[j] = '9';

		// Convert string to number
		int num = 0;
		for (auto c : curr)
			num = num * 10 + (c - '0');

		// Check if it lies in range and its product
		// is greater than max product
		if (num >= l && product(ans) < product(num))
			ans = num;
	}

	return ans;
}
long long countDigit(long long n)
{
    int temp = n, sum = 0, product = 1;
    while (temp != 0) {

        // Fetching each digit of the number
        int d = temp % 10;
        temp /= 10;

        // Checking if digit is greater than 0
        // and can divides n.
        if (d > 0 && n % d == 0) {
            sum += d;
            product *= d;
        }
    }
    return product;
}

// Driver Code
int main()
{
	int l = 1, r = 390;
	long long n;cin>>n;
	long long pro=1,ans =findNumber(1,n);
	//cout << (findNumber(l, n)) << endl;
	for(int i=ans;i>0;i=i/10)
    {
        int r = i % 10;
        pro = pro*r;
    }
    cout<<pro;
	return 0;
}
