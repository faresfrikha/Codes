#include <bits/stdc++.h>

using namespace std;

/* ---*-----*-----
---------o--------
-----------------*/

typedef long long ll;
typedef long double ld;

typedef vector<ll> vl ;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const int N = 32500;
const double PI =4*atan(1);
const ll MAX=9223372036854775807;

//set<char> vowel={'A', 'O', 'Y','E', 'U', 'I','a','o','e','u','i','y'};

int dx[]= {1,-1,0,0,1,-1,1,-1};
int dy[]= {0,0,1,-1,1,1,-1,-1};


ll q,y,k,z,w,t,l,r,x,n,m;
string ch;
stack<ll> ss;
ll pos[N];
ll val[N];
vector<pair<ll,ll> > v;


int main()
{
    ios::sync_with_stdio(0);
    cin >> ch;
    vl fares;
    for(int i=0; i<10005; i++)
    {
        fares.pb(i);
        fares.pb(-i);
    }
    x=0;
    while(ch.size()>2)
    {
        v.clear();
        x++;
        cout << x<<". ";
        n=ch.size();
        ll res=0;
        for(int i=0; i<n; i++)
        {
            if(ch[i]=='(')
            {
                ss.push(i);
                y++;
            }
            else if(ch[i]==')')
            {
                ll ras=ss.top();
                ss.pop();
                pos[ras]=i;
                v.pb(mp(y,ras));
                y--;
            }
            res=max(y,res);
        }
        ll ans=0;
        sort(v.rbegin(),v.rend());
        for(int i=0; i<v.size(); i++)
        {
            l=v[i].s;
            r=pos[v[i].s];
            y=0;
            ans=-1;
            for(int j=l+1; j<=r-1;)
            {
                if(ch[j]=='(')
                {
                    y++;
                    if(ans==-1)
                    {
                        ans=val[j];
                    }
                    else if((res-v[i].f)%2==0)
                    {
                        ans=ans&val[j];
                    }
                    else
                    {
                        ans=ans|val[j];
                    }
                    j=pos[j];
                }
                else if(ch[j]==')')
                {
                    y--;
                    j++;
                }
                else
                {
                    if(y>0)
                    {
                        j++;
                        continue;
                    }
                    if(ch[j]=='T')
                    {
                        if(ans==-1)
                            ans=1;
                        else if((res-v[i].f)%2==0)
                        {

                            ans=ans&1;
                        }
                        else
                        {
                            ans=ans|1;
                        }
                    }
                    else
                    {
                        if(ans==-1)
                            ans=0;
                        else if((res-v[i].f)%2==0)
                        {
                            ans=ans&0;
                        }
                        else
                        {
                            ans=ans|0;
                        }
                    }
                    j++;
                }
            }
            val[l]=ans;
        }
        if(val[0])
        {
            cout << "true\n";
        }
        else
        {
            cout << "false\n";
        }
        cin >> ch;
    }
    return 0;
}
