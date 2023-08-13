/*
Input: Read the number of vertices n and the number of edges m.
Data Structures: Initialize an array adj to store the adjacency list of the graph, a boolean array visited to keep track of visited vertices, a 2D vector v to store connected components, an integer cc to count connected components, and an empty vector vv to store the sizes of connected components.
Input Edges: For each edge, read the vertices u and v that are connected. Add v to the adjacency list of u and vice versa.
DFS Exploration:
Iterate through vertices from 0 to 1000.
If a vertex is not visited, perform a depth-first search (dfs) on that vertex.
Inside the dfs function:
Mark the current vertex as visited.
Add the current vertex to the current connected component v[cc+1].
For each neighbor val of the current vertex, if it's not visited, recursively call dfs(val).
Calculate Connected Components' Sizes:
Iterate through the connected components (from 1 to cc).
Push the size of each connected component (size of v[i]) into the vector vv.
Sort and Output Sizes:
Sort the vector vv containing the sizes of connected components in ascending order.
Iterate through the sorted vector:
If the size val is greater than 1, print val followed by a space.
Output: The output will be the sizes of connected components with more than one vertex.
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
vector<int> adj[N];
bool visited[N];
vector<int> comp[N];


void dfs(int u, int cnt)
{
    visited[u] = true;
    comp[cnt].push_back(u);

    for (int v : adj[u])
    {
        if (visited[v] == false)
        {
            dfs(v, cnt);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= 1000; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     if (!adj[i].empty())
    //     {
    //         cout << i << endl;
    //     }
    // }

    // cout<<endl;

    int cc = 0;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false and !adj[i].empty())
        {
            cc++;
            dfs(i, cc);
            // bfs(i);
        }
    }

    // cout<<cc<<endl;

    vector<int> finalVec;
    for(int i = 1; i<=n; i++)
    {
        // cout<<"Comp "<<i<<": ";
        // for(int v : comp[i])
        // {
        //     cout<<v <<" ";
        // }
        // cout<<endl;
        if(comp[i].size() and comp[i].size() > 1)
        // cout<<"Comp "<<i<<" size = "<<comp[i].size()<<endl;
        finalVec.push_back(comp[i].size());
    }

    sort(finalVec.begin(), finalVec.end());

    for(int v : finalVec)
    {
        cout<<v<<" ";
    }
    cout<<endl; 

    return 0;
}
