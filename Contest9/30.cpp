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
        int deg[n+1];
        for(int i = 1; i <= n; i++) deg[i] = 0;
        for(int i = 1; i <=m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            deg[v]++;
        }
        int countDeg = 0;
        int countD =0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i].size() == deg[i])  countDeg++;
            else if(abs(a[i].size()-deg[i]) == 1){
                countD++;
            }
        }
        if(countDeg == n || countD == 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
