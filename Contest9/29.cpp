#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a[n+1];
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >>  u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int demChan = 0;
        int demLe = 0;
        for(int i = 1; i <= n; i++){
           if(a[i].size()%2 == 0) demChan++;
           else demLe++;
        }
        if(demChan == n) cout << 2 << endl;
        else if(demLe == 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
