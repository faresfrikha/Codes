#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    long long t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        long long n;
        cin>>n;
        vector<long long>v;
        set<long long > e;
        long long l=0;
        for(int j=0; j<n; j++)
        {
            long long a;
            cin>>a;
            e.insert(a);
            if(l!=e.size())
            {
                v.push_back(a);
                l++;
            }
        }
        if(l==1)
        {
            cout<<"Case "<<i+1<<":"<<0;
            continue;
        }
        long long ans=0;
        sort(v.begin(),v.end());
        for(int j=1; j<l; j++)
        {
            for(int h=0; h<j; h++)
            {
                if((v[h]*3)==v[j])
                {
                    ans++;
                    break;
                }
            }
        }
        cout<<"Case "<<i+1<<":"<<ans<<"\n";
    }

    return 0;
}
