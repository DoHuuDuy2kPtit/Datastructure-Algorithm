#include<bits/stdc++.h>

using namespace std;

int n, m, u;

void Tree_BFS(int u, vector<int> a[], bool chuaxet[])
{
    queue<int> q;
    q.push(u);
    chuaxet[u] = false;
    vector<int> T;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int i = 0; i < a[s].size(); i++)
        {
            if(chuaxet[a[s][i]]){
                chuaxet[a[s][i]] = false;
                q.push(a[s][i]);
                T.push_back(s);
                T.push_back(a[s][i]);
            }
        }
    }
    if(T.size()/2 < n-1) cout << -1 << endl;
    else
    for(int i = 0; i < T.size(); i+=2)
    {
        cout << T[i] << " " << T[i+1] << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> u;
        vector<int> a[n+1];
        bool chuaxet[n+1];
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) chuaxet[i] = true;
        Tree_BFS(u,a,chuaxet);
    }
    return 0;
}
