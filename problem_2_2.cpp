
// ACCEPTED
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int src)
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

    int x;
    cin >> x;
    bool shopExist = false;
    if (x == 0)
        cout << 0 << endl;

    else 
    {
        bfs(0);

        for(int i = 0; i<N; i++)
        {
            if(level[i] == x)
            {
                shopExist = true; 
                cout<<i<<" ";
            }

        }
        // cout<<endl;
        
        if(shopExist == 0) cout<<-1<<endl;
        // উল্টাপাল্টা লেভেল দিলে -1 আউটপুট দিতে হবে সরাসরি। মানে এমন লেভেল যেটা গ্রাফে নাই।  
/*         যেমন ঃ 
        3 2
        0 1 
        0 2 
        5

        এই ইনপুটে লেভেল -০, লেভেল-১ অ্যাভেইলেবল আছে । এখন আমি যদি লেভেল - ৫ বা লেভেল -২ এর জন্য শপ প্রিন্ট করতে বলি... এইটা তো এক্সিস্ট ই করে না । তখন এই কন্ডিশন টা কাজ করবে।  */

    }

    // cout<<shopExist<<endl;

    
    
    return 0;
}