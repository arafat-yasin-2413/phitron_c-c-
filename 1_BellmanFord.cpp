#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
const int INF = 1e9+6;
int n, m;
vector<pair<int,int>> adj[N];
vector< pair<pair<int,int>, int> > list_of_edges;

int dist[N];

void bellmanFord(int src)
{
    for(int i = 1 ; i<=n; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0; 
    for(int i = 1; i<n; i++)
    {
        /*
        // using adjacency list
        // all edges relaxation
        for(int u = 1; u<=n; u++)
        {
            for(pair<int,int> vpair : adj[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if(dist[u]!=INF and dist[v] > dist[u]+w)
                {
                    dist[v] = dist[u]+w; 
                }
            }
        }
        */

       // list of edges
       for(auto edge : list_of_edges)
       {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second; 

            if(dist[u] != INF and 
            dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w; 
            }
       }
    }
}

/*
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
*/

int main()
{
     
    cin >> n >> m ; 

    for(int i = 1; i<=m; i++)
    {
        int u, v , w ; 
        cin >> u >> v >> w ; 
        // adj[u].push_back({v,w});
        list_of_edges.push_back({{u,v},w});
    }


    bellmanFord(1);

    for(int i = 1; i<= n; i++)
    {
        cout<<"Distance of "<<i<<": "
        << dist[i] <<endl;
    }

    return 0;
}