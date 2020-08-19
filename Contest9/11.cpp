#include<bits/stdc++.h>

using namespace std;

bool chuaxet[1005];
int truoc[1005];
vector< vector<int> > a(1005);
bool check = true;

void DFS(int s,int t){
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

void findWayByDFS(int s, int t){
    DFS(s,t);
//    for(int i = 1; i <= n; i++){
//        cout << truoc[i] << " ";
//    }
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
        a.clear();
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        for(int i = 1; i <= m; i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        for(int i = 0; i <= n; i++){
            chuaxet[i] = true;
            truoc[i] = 0;
        }
//        DFS(s);
//        for(int i = 0; i <= n; i++){
//            cout << truoc[i] << " ";
//        }
        findWayByDFS(s,t);
    }
}

