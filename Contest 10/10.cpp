#include<bits/stdc++.h>

using namespace std;

int n, m;

struct edge{
    int src, dest, weight;
};

bool myCompare(edge a, edge b)
{
    if(a.weight == b.weight) return a.src < b.src;
    else return a.weight < b.weight;
}

// Tim root cua 1 dinh

int find(int parent[], int i)
{
    if(parent[i] == -1) return i;
    else return find(parent,parent[i]);
}

void Union(int parent[], int x, int y)
{
    int xset = find(parent,x);
    int yset = find(parent,y);
    if(xset != yset){
        parent[xset] = yset;
    }
}

void kruscal(vector<edge> E)
{
    int dh = 0;
    int parent[n+1];
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }
    vector<edge> T;
    while(T.size() < n-1 && E.size() > 0)
    {
        edge e = E[0];
        E.erase(E.begin());
        if(find(parent,e.src) != find(parent,e.dest)){
            T.push_back(e);
            dh += e.weight;
        }
        Union(parent,e.src,e.dest);
    }
    cout << dh << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<edge> E;
        for(int i = 1; i <= m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edge e;
            e.src = u;
            e.dest = v;
            e.weight = w;
            E.push_back(e);
        }
        sort(E.begin(),E.end(),myCompare);
        kruscal(E);
    }
    return 0;
}

