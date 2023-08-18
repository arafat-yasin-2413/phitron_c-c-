#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> adj[N];
bool visited[N];
int level[N]={-1};


void bfs(int src)
{
    for (int i = 0; i <= N; i++)
    {
        visited[i] = 0;
        // level[i] = 0;
    }

    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
   

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, d;
        cin >> s >> d;
        // if(s == 0 and d == 0) cout<<0<<endl;
        for(int i =0; i<=N; i++)
        {
            level[i]=-1;
        }
        bfs(s);
        if (visited[d] == 0 )
            cout << -1 << endl;
        else
        {
            cout << level[d] << endl;
        }
    }

    return 0;
}
