#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];
int level[N];
vector<int> shop;

void bfs(int src, int lv)
{
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
                if (level[v] == lv)
                {
                    // shop[0].push_back(v);
                    shop.push_back(v);
                }
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

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "List " << i << ": ";
    //     for (int v : adj[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    int x;
    cin >> x;
    bfs(0, x);

    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Level of " << i << ": " << level[i] << endl;
    // }

    // cout << endl;

    // cout<<shop.size()<<endl;
    if (shop.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int el : shop)
        {
            cout << el << " ";
        }
    }

    return 0;
}