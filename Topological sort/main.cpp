
#include<bits/stdc++.h>
using namespace std;
/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
    void topo(vector<int> adj[],int u,bool visited[],stack<int> &s)
{
    visited[u]=true;        // Mark the current node as visited

    for(auto v : adj[u])    // Run for adjacent vertices
    {
        if(!visited[v])     // If adjacent vertex is not visited
            topo(adj,v,visited,s);  // Call the topo function for adjacent vertex
    }
    s.push(u);      // Push the current node to the stack
}


int* topoSort(int N, vector<int> adj[])
{
    bool visited[N+1];                  // Make a visited array of N nodes
    memset(visited,0,sizeof visited);   // Mark the visited array intially 0
    stack<int> s;

    for(int i=0;i<N;i++)                // Traverse for all the nodes from 0 to N.
    {
        if(!visited[i])                 // If the current node is not visited
            topo(adj,i,visited,s);      // Call the topo function
    }

    int *A = new int [s.size()];
    int i=-1;
    while(!s.empty())                   // Till stack is not empty
    {
        A[++i]=s.top();                 // Put the stack top value to the array
        s.pop();
    }
    return A;
}
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;

        vector<int> adj[N];

        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout<<check(N, res, adj)<<endl;

    }
}
