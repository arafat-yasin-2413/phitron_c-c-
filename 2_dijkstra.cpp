#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
const int INF = 1e9+8;
vector< pair<int,int> > adj[N];
vector<int> dist(N,INF);
vector<bool>visited(N);

void dijkstra(int src)
{
    priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> >pq;
    // একটা প্রায়োরিটি কিউ তে src এর distance এবং src কে রাখি। 
    dist[src] = 0;
    pq.push({dist[src],src});

    while (!pq.empty())
    {
        // প্রা. কিউ খালি না হওয়া পর্যন্ত প্রা. কিউ এর সেকেন্ড ইলিমেন্ট যে কিনা আমাদের নোড তাকে একটা ভ্যারিয়েবল u এর মধ্যে রাখি। 
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        //প্রা. কিউ তে এখন পপ করি এবং ওই নোড u কে visited = true করে দিয়ে আসি। 

        // Range based for loop  এর মাধ্যমে ওই u এর adjacency list থেকে একেক্টা কানেক্টেড নোড v এবং সেগুলোর weight বের করি।
        for(pair<int,int> pr : adj[u])
        {
            // একেক্টা পেয়ার বের হচ্ছে 
            int v = pr.first;
            int w = pr.second; 

            // যদি visited[v] ট্রু না হয় তাহলে তাদের relax করবো
            if(visited[v]) continue;
            // relaxation korbo ekhon
            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                // distance আপডেট করলাম। এখন v কে প্রা. কিউতে distance সহ পুশ করে দিবো।  
                pq.push({dist[v],v});

            }
        }


    }
    
    
}

/*
7
8
1 2 3 
1 3 5 
3 4 1 
4 6 1 
2 5 6 
5 6 1 
5 7 2
3 7 12
*/

int main()
{
    int n , m ; 
    cin >> n >> m; 
    for(int i = 1;i<=m; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w; 
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }



    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(pair<int,int> pr : adj[i])
    //     {
    //         cout<< "("<< pr.first<<","<<pr.second<<")"<<" ";
    //     }
    //     cout<<endl;
    // }

    dijkstra(1);
    cout<<endl; 
    for(int i =1 ; i<=n; i++)
    {
        cout<<"Distance of "<<i<<": "<<dist[i]<<endl; 
    }

    return 0;
}
























/*
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e18+10;

const int N = 1e3+7;
vector<bool> visited(N);
vector<pair<int,int>> adj[N];
vector<int> dist(N,INF);

void dijkstra(int src)
{
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;

    dist[src] = 0;
    pq.push({dist[src],src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        // pop korar sathe sathei visited k true kore dibo

        visited[u]= true;

        for(auto vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if(visited[v] ) continue;
            // relaxation
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

}


int main()
{
    int n, m; 
    cin >> n >> m ; 
    for(int i = 1; i<=m; i++)
    {
        int u , v , w ; 
        cin >> u >> v >> w; 
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }

    // for(int i = 1; i<=n; i++)
    // {
    //     for(auto v : adj[i])
    //     {
    //         cout<<"("<<v.first<<","<<v.second<<")"<<" "; 
    //     }
    //     cout<<endl;
    // }

    int s; cin >> s ;
    dijkstra(s);
    for(int i = 1; i<=n; i++)
    {
        cout<<"distance of "<<i<<": "<<dist[i]<<endl;
    }



    return 0;
}
*/