#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e3 + 6;
const int INF = 1e9 + 8;
int adjMat[N][N];

void printMatrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMat[i][j] == INF)
            {
                cout << "H"<< " ";
            }
            else
                cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

void dist_init()
{
    // সবার ডিস্ট্যান্স ইনফিনিটি করে দিবো
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // initially adjMat এর সব এলিমেন্ট ০ ই আছে। তাই [i]!=[j] ঘর গুলোতে ইনফিনিটি করে দিচ্ছি।
            if (i != j)
                adjMat[i][j] = INF;
        }
    }
}

int main()
{

    cin >> n >> m;

    dist_init();

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMat[u][v] = w;
        // adjMat[v][u] = w;

    }

    cout<<"Before Floyd Warshall : "<<endl; 
    printMatrix();


    // প্রত্যেক লেভেলে এসে K এর মাধ্যমে গিয়ে distance কমানো যায় কিনা চেক করবো। কমানো গেলে আপডেট করে দিবো। এখানে লেভেল হলো 'K'
    
    // Floyd Warshall Algo
    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
            }
        }
    }


    cout<<endl<<"After Floyd Warshall"<<endl;
    printMatrix();

    return 0;
}