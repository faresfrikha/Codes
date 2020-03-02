#include<bits/stdc++.h>
using namespace std;
int id[1005];
int cost=0;
void initialize()
{
    for(int i=0; i<=1005-1; i++)
        id[i]=i;
}

int root(int x)
{
    while(x!=id[x])
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(int x,int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}

int kruskal(pair<int,int> p[],int e)
{

    for(int i=0; i<=e-1; i++)
    {
        int x=p[i].first;
        int y=p[i].second;
        if(root(x)!=root(y))
        {
            cost++;
            union1(x,y);
        }

    }
    return cost;
}

int main()
{
    int t,i,n,e,j,x,y,m;
    pair<int,int>p[1000000];
    scanf("%d",&t);

    for(i=0; i<=t-1; i++)
    {
        initialize();
        cost=0;
        scanf("%d %d",&n,&e);
        for(j=0; j<=e-1; j++)
        {
            scanf("%d %d",&x,&y);
            p[j]=make_pair(x,y);
        }
        m=kruskal(p,e);
        printf("%d\n",m);
    }
    return 0;
}
