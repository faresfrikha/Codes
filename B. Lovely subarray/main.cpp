
#include <bits/stdc++.h>
using namespace std;

void minRange(long long arr[], long long n, long long k)
{

	int l = 0, r = n;

	int j = -1;
	map<int, int> hm;
	for (int i=0; i<n; i++)
	{
		while (j < n)
		{
			j++;
			if (hm.size() < k)
				hm[arr[j]]++;
			if (hm.size() == k && ((r - l) >= (j - i)))
			{
				l = i;
				r = j;
				break;
			}
		}
		if (hm.size() < k)
			break;
		while (hm.size() == k)
		{

			if (hm[arr[i]] == 1)
				hm.erase(arr[i]);
			else
				hm[arr[i]]--;
			i++;
			if (hm.size() == k && (r - l) >= (j - i))
			{
				l = i;
				r = j;
			}
		}
		if (hm[arr[i]] == 1)
			hm.erase(arr[i]);
		else
			hm[arr[i]]--;
	}

	cout <<r-l+1 << endl;
}

int main()
{
	long long arr[100005] ;
	long long t;
	set<long long> s;
	cin>>t;
	for(int i=0;i<t;i++)
    {
        cin>>arr[i];s.insert(arr[i]);
    }
	long long n = sizeof(arr) / sizeof(arr[0]);
	int k = s.size();
	minRange(arr, n, k);
	return 0;
}
