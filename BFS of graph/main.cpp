#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/* You have to complete this function*/
/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> g[], bool vis[])
{
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int t = q.front();
        cout<<t<<" ";
        q.pop();
        for(int i=0; i<g[t].size(); i++)
        {
            if(!vis[g[t][i]])
        {
            vis[g[t][i]]=true;
            q.push(g[t][i]);
        }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N];
        for(int i=0; i<E; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        bfs(0, adj, vis);
        cout<<endl;
    }
}
