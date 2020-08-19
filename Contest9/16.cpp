#include<bits/stdc++.h>

using namespace std;

vector< vector<int> > a(1005);
bool chuaxet[1005];

void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaxet[u] = false;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i = 0; i < a[s].size(); i++){
            if(chuaxet[a[s][i]]){
                q.push(a[s][i]);
                chuaxet[a[s][i]] = false;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        a.clear();
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) chuaxet[i] = true;
        int sotplt = 0;
        for(int i = 1; i <= n; i++){
            if(chuaxet[i]){
                sotplt++;
                BFS(i);
            }
        }
        cout << sotplt << endl;
    }
}
