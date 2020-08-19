#include<bits/stdc++.h>

using namespace std;

void BFS(int u, vector<int> a[],bool chuaxet[])
{
    queue<int> q;
    q.push(u);
    cout << u << " ";
    chuaxet[u] = false;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 0; i < a[t].size(); i++){
            if(chuaxet[a[t][i]]){
                cout << a[t][i] << " ";
                q.push(a[t][i]);
                chuaxet[a[t][i]] = false;
            }
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, s;
        cin >> n >> m >> s;
        vector<int> a[n+1];
        bool chuaxet[n+1];
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i = 1; i <= n; i++){
            chuaxet[i] = true;
        }
        BFS(s,a,chuaxet);
    }
    return 0;
}
