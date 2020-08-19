#include<bits/stdc++.h>

using namespace std;

bool chuaxet[1005];
vector< vector<int> > a(1005);
int truoc[1005];
bool check = true;

void BFS(int s, int t){
    queue<int> q;
    q.push(s);
    chuaxet[s] = false;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < a[u].size(); i++){
            if(chuaxet[a[u][i]]){
                truoc[a[u][i]] = u;
                if(a[u][i] == t) check = false;
                q.push(a[u][i]);
                chuaxet[a[u][i]] = false;
            }
        }
    }
}

void findWayByBFS(int s, int t){
    BFS(s,t);
    if(check) cout << -1 << endl;
    else{
        vector<int> res;
        res.push_back(t);
        int u = t;
        while(s!=truoc[u]){
            u = truoc[u];
            res.push_back(u);
        }
        res.push_back(s);
        for(int i = res.size()-1; i >= 0; i--){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        a.clear();
        int n, m , s, t;
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        for(int i = 0; i <= n; i++){
            chuaxet[i] = true;
            truoc[i] = 0;
        }
        int q; cin >> q;
        while(q--){
            cin >> s >> t;
            for(int i = 0; i <= n; i++){
                chuaxet[i] = true;
                truoc[i] = 0;
            }
            findWayByBFS(s,t);
        }
    }
    return 0;
}
