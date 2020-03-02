#include <bits/stdc++.h>
using namespace std;
const int nmax=3e3+3;
queue <pair <int,int> > q1,q2;
long long x,y,cx,cy,px,py,dx[]= {-1,0,1,0},dy[]= {0,1,0,-1},a,b;
long long usu,n,m,st,dr,v[nmax][nmax],vizz[nmax][nmax],sol=0;
char c;
bool inline inside(long long x,long long y)
{
    return x>=1&&y>=1&&x<=n&&y<=m;
}
void soll()
{
    while(!q1.empty())
    {
        x=q1.front().first;
        y=q1.front().second;
        q1.pop();
        a=q2.front().first;
        b=q2.front().second;
        q2.pop();
        for(int i=0; i<4; ++i)
        {
            cx=x+dx[i];
            cy=y+dy[i];
            if(!inside(cx,cy)||v[cx][cy])
                continue;
            if(!vizz[cx][cy])
            {
                if(i==1&&b>0)
                {
                    q1.push({cx,cy});
                    q2.push({a,b-1});
                    vizz[cx][cy]=1;
                }
                if(i==3&&a>0)
                {
                    q1.push({cx,cy});
                    q2.push({a-1,b});
                    vizz[cx][cy]=1;
                }
                if(i==0||i==2)
                {
                    q1.push({cx,cy});
                    q2.push({a,b});
                    vizz[cx][cy]=1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>px>>py>>st>>dr;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            cin>>c;
            if(c!='.')
                v[i][j]=1;
        }
    }
    q1.push({px,py});
    q2.push({st,dr});
    vizz[px][py]=1;
    soll();
    //sol=0;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(vizz[i][j])
                sol++;
    cout<<sol<<"\n";
    return 0;
}
