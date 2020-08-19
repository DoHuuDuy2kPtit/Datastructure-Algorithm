#include<bits/stdc++.h>

using namespace std;

//bool chuaxet[1005];
//vector< vector <int> > a(1005);

void DFS(int u,vector<int> a[], bool chuaxet[]){
    stack<int> stk;
    cout << u << " ";
    stk.push(u);
    chuaxet[u] = false;
    while(!stk.empty()){
        int s = stk.top();
        stk.pop();
        for(int i = 0; i < a[s].size(); i++){
            if(chuaxet[a[s][i]]){
                stk.push(s);
                stk.push(a[s][i]);
                cout << a[s][i] << " ";
                chuaxet[a[s][i]] = false;
                break;
            }
        }
    }
    cout << endl;
}

int main(){
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
        }
        for(int i = 1; i <= n; i++) sort(a[i].begin(),a[i].end());
        for(int i = 1; i <= n; i++){
            chuaxet[i] = true;
        }
        DFS(s,a,chuaxet);
    }
    return 0;
}
