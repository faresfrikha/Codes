#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;vector<long long >v;
        for(int i=0; i<n; i++)
        {
            long long a;
            cin>>a;
            if(a!=-1)
            {
                cout<<a<<" ";
                v.push_back(a);
            }
            else
            {
                v.push_back((v[i-1]+1)%m);
                cout<<v[i]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
