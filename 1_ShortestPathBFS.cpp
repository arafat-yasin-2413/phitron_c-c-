#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
vector<int> adj[N];
int level[N];
vector<bool> visited(N);
int parent[N];

void bfs(int src)
{
    queue<int> q; 
    q.push(src);
    visited[src] = true;
    level[src] = 0; 
    parent[src]=-1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u]+1;
            parent[v] = u;  
        }
    }
}



int main()
{
    int n, m ; cin >> n >> m; 
    for(int i = 1;i<=m;i++)
    {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    // for(int i= 1; i<=n; i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(int el: adj[i])
    //     {
    //         cout<<el<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // visited[0] = 1;
    // cout<<visited[0]<<endl;
    
    int s, d; 
    cin >> s >> d; 
    bfs(s);
    cout<<level[d]<<endl;
    
    cout<<endl;
    for(int i = 1; i<= n; i++)
    {
        cout<<"Parent of "<<i<<": "<<parent[i]<<endl;
    }

    int curr = d; 
    vector<int> v;
    
    while(curr!=-1)
    {
        v.push_back(curr);
        curr = parent[curr];
    }
    // v.push_back(curr);

    reverse(v.begin(),v.end());
    cout<<"Path : ";
    for(int el : v )
    {
        cout<<el<<" ";
    }
    




    return 0;
}