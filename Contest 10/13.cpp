#include<bits/stdc++.h>

using namespace std;

int n, m;

struct edge{
    int src, dest, weight;
};

bool bellman_ford(vector<edge> E)
{
    for(int k = 1; k <= n; k++){
        int d[n+1];
        for(int i = 1; i <= n; i++){
            d[i] = INT_MAX;
        }
        d[k] = 0;
        bool check = true;
        for(int i = 1; i <= n-1; i++){
            for(int j = 0; j < E.size(); j++){
                int u = E[j].src;
                int v = E[j].dest;
                int w = E[j].weight;
                if(d[u] != INT_MAX && d[v] >d[u] +w ){
                    d[v] = d[u] + w;
                }
            }
        }
        for(int j = 0; j < E.size(); j++){
            int u = E[j].src;
            int v = E[j].dest;
            int w = E[j].weight;
            if(d[u] != INT_MAX && d[v] > d[u]+w){
                return true;
                break;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<edge> E;
        for(int i = 1; i <= m; i++){
            int u, v ,w;
            cin >> u >> v >> w;
            edge e;
            e.src = u;
            e.dest = v;
            e.weight = w;
            E.push_back(e);
        }
        if(bellman_ford(E)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
