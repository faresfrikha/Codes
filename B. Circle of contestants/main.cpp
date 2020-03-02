#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios::sync_with_stdio(0);
    long long n,i,j;
    cin>>n;
    vector<string>v;
    for(int l=0; l<n; l++)
    {
        string ch;
        cin>>ch;
        v.push_back(ch);
    }
    cin>>i>>j;
    i--;
    i--;
    cout<<v[(i+j)%n]<<"\n";
    v[(i+j)%n]="*";
    int m=(i+j)%n;
    for(int l=0; l<n-1; l++)
    {
        int k=0;
        while(k<=j)
        {
            if(k==j)
            {
                while(1)
                {
                    if(v[(m+k)%n]!="*")
                    {
                        cout<<v[(m+k)%n]<<"\n";
                        v[(m+k)%n]="*";
                        break;
                    }
                    k++;

                }
            }
            k++;
        }
        m=(m+j)%n;
    }
    return 0;
}
