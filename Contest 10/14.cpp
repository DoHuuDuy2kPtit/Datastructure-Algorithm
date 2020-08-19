#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, m, s;

// d[i] : luu duong di nho nhat tu dinh s den dinh i

int minDistance(int d[],bool chuaxet[])
{
    int minp = INT_MAX;
    int min_index;
    for(int i = 1; i <= n; i++)
    {
        if(chuaxet[i] && d[i] < minp)
            minp = d[i], min_index = i;
    }
    return min_index;
}

void Dijkstra(vector< pair<int,int> > a[], int s)
{
    int d[n+1];
    bool chuaxet[n+1];
    for(int i = 1; i <= n; i++){
        d[i] = INT_MAX;
        chuaxet[i] =  true;
    }
    d[s] = 0;
    for(int i = 1; i <= n; i++){
        int u = minDistance(d,chuaxet);
        chuaxet[u] = false;
        for(int  i =0; i< a[u].size(); i++){
            if(chuaxet[a[u][i].first] && d[u] != INT_MAX && d[a[u][i].first] > a[u][i].second + d[u]){
                d[a[u][i].first] = d[u] + a[u][i].second;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s;
        vector< pair<int,int> > a[n+1];
        for(int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            a[u].push_back({v,w});
            a[v].push_back({u,w});
        }
        Dijkstra(a,s);
    }
    return 0;
}
