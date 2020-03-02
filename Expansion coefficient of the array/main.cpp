#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n,minn=1e9;
    long long v[n];
    for(int i=0; i<n; i++)
    {
        cin>>v[i];

        if (v[i]<=minn)
            minn=v[i];
    }
    if (minn==0)
        cout<<0<<endl;
    else
        cout<<((minn+1)/2)-1<<endl;
    return 0;
}
