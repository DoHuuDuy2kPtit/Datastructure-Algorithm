#include<bits/stdc++.h>

using namespace std;

int n, m;


struct edge{
    int head;
    int tail;
    int id;
};

int minKey(int key[],bool mstSet[])
{
    int minp = INT_MAX;
    int min_index;
    for(int i = 1; i <= n; i++)
    {
        if(!mstSet[i] && key[i] < minp)
            minp = key[i], min_index = i;
    }
    return min_index;
}

void prim(int a[][105])
{
    int parent[n+1];
    int key[n+1];
    bool mstSet[n+1];
    for(int i = 1; i <= n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[1] = 0;
    parent[1] = -1;
    for(int i = 1; i <= n; i++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;

        for(int v = 1; v <= n; v++)
        {
            if(a[u][v]!= 0 && mstSet[v] == false && a[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = a[u][v];
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        res += a[i][parent[i]];
    }
    cout << res << endl;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int a[105][105];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] = 0;
        for(int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            a[u][v] = w;
            a[v][u] = w;
        }
        prim(a);
    }
}
