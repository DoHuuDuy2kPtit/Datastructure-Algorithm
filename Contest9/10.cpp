#include<bits/stdc++.h>

using namespace std;

bool check = true;

void DFS(int s,int t,vector<int> a[], bool chuaxet[], int truoc[]){
    stack<int> stk;
    stk.push(s);
    chuaxet[s] = false;
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        for(int i = 0; i < a[u].size(); i++){
            if(chuaxet[a[u][i]]){
                truoc[a[u][i]] = u;
                if(a[u][i]==t) check = false;
                stk.push(u);
                stk.push(a[u][i]);
                chuaxet[a[u][i]] = false;
                break;
            }
        }
    }
}

void findWayByDFS(int s, int t, vector<int> a[], bool chuaxet[], int truoc[]){
    DFS(s,t,a,chuaxet,truoc);
    if(check == true) cout << -1 << endl;
    else {
        vector<int> res;
        res.push_back(t);
        int u = t;
        while(s != truoc[u]){
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
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<int> a[n+1];
        bool chuaxet[n+1];
        int truoc[n+1];
        for(int i = 1; i <= m; i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            // a[v].push_back(u);
        }
        for(int i = 0; i <= n; i++){
            chuaxet[i] = true;
            truoc[i] = 0;
        }
        for(int i = 1; i <= n; i++) sort(a[i].begin(),a[i].end());
        check = true;
        findWayByDFS(s,t,a,chuaxet,truoc);
    }
}
