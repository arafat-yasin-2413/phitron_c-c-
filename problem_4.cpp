#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int>adj[N];
bool visited[N];
int temp[N];


void dfs(int u)
{
    visited[u] = true;
    
    // cout<<u<<" ";

    for(int v : adj[u])
    {
        if(visited[v] == false)
        {
            temp[0]++;
            dfs(v);
        }
    }
    
}

int main()
{
    int n , m; 
    cin >> n >>m ;

    for(int i = 0; i<m; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);

    }

    // for(int i =0; i<n; i++)
    // {
    //     cout<<"List "<<i <<": ";
    //     for(int v : adj[i])
    //     {
    //         cout<<v<<" ";

    //     }
    //     cout<<endl;
    // }

    int x ; cin >> x; 
    dfs(x);
    cout<<temp[0]<<endl;
    

    return 0;
}





























/*
#include<bits/stdc++.h>
using namespace std;

const int N=20;
vector<int> adj[N];
bool visited[N];

int dfs(int u , int cnt)
{
    visited[u] = true;

    for(int v : adj[u])
    {
        if(visited[v] == false)
        {
            dfs(v,cnt);
            cnt++;
        }
    }
    return cnt;
}


int main()
{
    int n, m;
    cin >> n >> m; 
    

    for(int i =0; i<m; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
    }

    for(int i = 0; i<n; i++)
    {
        cout<<"List "<<i<<": ";
        for(int v : adj[i])
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }

    int src; cin >> src;
    int c = 0;

    for(int i = 0; i<n; i++)
    {
        if(visited[i] == false)
        {
            int count = dfs(src,c);
        }
    }
    
    

    return 0;
}
*/