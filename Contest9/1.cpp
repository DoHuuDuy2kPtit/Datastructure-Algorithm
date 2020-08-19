#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,u,v,t;
    cin >> t;
    while(t--){
    vector< vector <int> > a(1005);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(a[i].begin(),a[i].end());
    }
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 0; j < a[i].size(); j++){
            cout<<a[i][j]<< " ";
        }
        cout << endl;
    }
    }
}
