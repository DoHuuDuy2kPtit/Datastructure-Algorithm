#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int in_degree[n+1];
        vector<int> a[n+1];
        for(int i = 1; i <= n; i++) in_degree[i] = 0;;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            in_degree[v]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(in_degree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(int i = 0; i < a[u].size(); i++){
                in_degree[a[u][i]]--;
                if(in_degree[a[u][i]] == 0) q.push(a[u][i]);
            }
        }
        if(count == n)
            cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
