//Depth-first search (DFS) is an algorithm (or technique) for traversing a graph.
#include<bits/stdc++.h>
using namespace std;
/*This is a function problem.You only need to complete the function given below*/
/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/

void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s] = true;          // Mark the current source vertex as visited
    cout<<s<<" ";           // Print the vertex
    for(int i=0; i<g[s].size(); i++) // Traverse through all the connected components of vertex s
    {
        if(!vis[g[s][i]])           // If they are not visited, call dfs for the new connected vertex
            dfs(g[s][i],g,vis);
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

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0; i<E; i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);

        cout<<endl;
    }
}
