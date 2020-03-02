#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    long long n;
    cin>>n;
    string ch;
    cin>>ch;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(ch[i]=='+')ans++;
        else {ans--;ans=max(0,ans);}
    }
    cout<<ans;
    return 0;
}
