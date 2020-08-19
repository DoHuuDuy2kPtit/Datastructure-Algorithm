#include<bits/stdc++.h>

using namespace std;

vector< vector<int> > a(1005);
bool chuaxet[1005];
int n, m;

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

bool check(){
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
        a.clear();
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        bool strongConnect =  true;
        for(int i = 1; i <= n; i++) chuaxet[i] = true;
        for(int i = 1; i <= n; i++){
            BFS(i);
            if(check()==false) strongConnect = false;
            for(int i = 1; i <= n; i++) chuaxet[i] = true;
        }
        if(strongConnect){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

