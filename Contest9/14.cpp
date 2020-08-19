#include<bits/stdc++.h>

using namespace std;

bool check = true;

void BFS(int s, int t, vector<int> a[], bool chuaxet[]){
    queue<int> q;
    q.push(s);
    chuaxet[s] = false;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < a[u].size(); i++){
            if(chuaxet[a[u][i]]){
                if(a[u][i] == t) check = false;
                q.push(a[u][i]);
                chuaxet[a[u][i]] = false;
            }
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        vector<int> a[n+1];
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int q;
        cin >> q;
        while(q--){
            int s,t;
            cin >> s >> t;
            check = true;
            bool chuaxet[n+1];
            for(int i = 0; i <= n; i++){
                chuaxet[i] = true;
            }
            BFS(s,t,a,chuaxet);
            if(check) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}

