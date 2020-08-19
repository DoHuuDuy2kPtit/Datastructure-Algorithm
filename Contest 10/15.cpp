#include<bits/stdc++.h>

using namespace std;

int n, m, s;

struct edge{
    int src, dest, weight;
};

void bellman_ford(vector<edge> E)
{
    int d[n+1];
    for(int i = 1; i <= n; i++) d[i] =INT_MAX;
    d[s] = 0;
    bool check = true;
    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < E.size(); j++){
            int u = E[j].src;
            int v = E[j].dest;
            int w = E[j].weight;
            if(d[u] != INT_MAX && d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }
    }
    for(int i = 0; i < E.size(); i++)
    {
        int u = E[i].src;
        int v = E[i].dest;
        int w = E[i].weight;
        if(d[u] != INT_MAX && d[v] > d[u] + w){
            check = false;
            break;
        }
    }
    if(check){
        for(int i = 1; i <= n; i++){
            if(d[i] == INT_MAX) cout << "INFI" << " ";
            else cout << d[i] << " ";
        }
    } else cout << -1;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s;
        vector<edge> E;
        for(int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edge e;
            e.src = u;
            e.dest = v;
            e.weight = w;
            E.push_back(e);
        }
        bellman_ford(E);
    }
    return 0;
}
