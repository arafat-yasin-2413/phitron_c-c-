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

/* 
Test case 4

57 73
348 916
6 594
872 515
960 976
169 662
317 529
702 789
255 74
574 330
338 584
238 31
172 929
967 19
654 780
478 336
66 342
13 415
842 908
283 652
921 571
848 7
560 287
890 730
1 703
262 453
338 223
935 872
478 718
979 886
768 336
703 672
167 606
498 66
647 769
665 827
852 144
533 2
306 494
328 97
414 693
562 625
697 755
576 462
319 778
995 752
583 977
397 178
409 450
143 836
633 576
355 400
153 792
98 492
153 542
838 740
619 125
840 129
115 766
803 442
257 208
66 888
347 339
494 838
844 925
381 798
451 317
278 500
197 135
329 454
709 547
203 882
464 726
338 346


2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 4 4 4 4
 */


#include <bits/stdc++.h>
using namespace std;

const int N = 1007;
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
    // for (int i = 1; i <= 1000; i++)
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    // cout<<adj[6].size()<<endl;

    // for(int i = 0; i<=n; i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(int  v : adj[i])
    //     {
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
    // }

    // for (int i = 0; i <= N; i++)
    // {
    //     if (!adj[i].empty())
    //     {
    //         cout << i << " ";
    //     }
    //     cout<<endl;

    // }

    // cout<<endl;


    // cout<<adj[4][0]<<endl;
    
    int cc = 0;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false and 
        !adj[i].empty())
        {
            cc++;
            dfs(i, cc);
        }
    }

    // cout<<cc<<endl;

    vector<int> finalVec;
    for(int i = 1; i<=N; i++)
    {
        // cout<<"Comp "<<i<<": ";
        // for(int v : comp[i])
        // {
        //     cout<<v <<" ";
        // }
        // cout<<endl;
        
        
        // if(comp[i].size() and comp[i].size() > 1)
        if(comp[i].size() > 1)
        {
            finalVec.push_back(comp[i].size());
        }

        // cout<<"Comp "<<i<<" size = "<<comp[i].size()<<endl;
        
    }

    sort(finalVec.begin(), finalVec.end());

    for(int v : finalVec)
    {
        cout<<v<<" ";
    }
    cout<<endl; 

    return 0;
}
