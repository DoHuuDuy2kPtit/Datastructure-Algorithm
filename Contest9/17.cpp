#include<bits/stdc++.h>

using namespace std;

int n, m;

void DFS(int u,vector<int> a[],bool chuaxet[])
{
    stack<int> stk;
    stk.push(u);
    chuaxet[u] = false;
    while(!stk.empty()){
        int s = stk.top();
        stk.pop();
        for(int i = 0; i < a[s].size(); i++){
            if(chuaxet[a[s][i]]){
                stk.push(s);
                stk.push(a[s][i]);
                chuaxet[a[s][i]] = false;
                break;
            }
        }
    }
}

bool check(bool chuaxet[]){
    for(int i = 1; i <= n; i++){
        if(chuaxet[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<int> a[n+1];
        bool chuaxet[n+1];
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        bool strongConnect =  true;
        for(int i = 1; i <= n; i++) chuaxet[i] = true;
        for(int i = 1; i <= n; i++){
            DFS(i,a,chuaxet);
            if(check(chuaxet)==false) strongConnect = false;
            for(int i = 1; i <= n; i++) chuaxet[i] = true;
        }
        if(strongConnect){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
