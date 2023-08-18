#include <bits/stdc++.h>
using namespace std;

/*
কামালের বাসার নোড দেওয়া আছে.. সে নোড এর কত গুলা চিলড্রেন আছে সেটা কাউন্ট করলেই হবে ভাইয়া..
Adjacency list ইউজ করেন আর adj[k].size() প্রিন্ট করে দিলেই হবে ভাইয়া
*/

const int N = 100;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int src)
{
    visited[src] = true;
    queue<int> q;
    q.push(src);
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
                level[v] = level[u]+1;
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
    // cout<<endl;
    
    int x; cin >> x; 
    bfs(x);
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        // cout<<"Level of "<<i<<": "<<level[i]<<endl;
        if(level[i] == level[x]+1)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}