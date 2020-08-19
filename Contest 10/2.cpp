#include<bits/stdc++.h>

using namespace std;

bool chuaxet[22];
int n, m;
int check;

void Try(int u, vector<int> a[], int j)
{
    if(j==n) {
        check = 1;
        return;
    }
    for(int i = 0; i < a[u].size(); i++){
        if(chuaxet[a[u][i]]){
            chuaxet[a[u][i]] = false;
            Try(a[u][i],a, j+1);
            chuaxet[a[u][i]] = true;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> a[20];
        for(int i = 1; i <= n; i++) chuaxet[i] = true;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);

        }
        check = 0;
        for(int i = 1; i <= n; i++) {
            chuaxet[i] = false;
            Try(i,a,1);
            chuaxet[i] = true;
        }
        cout << check << endl;
    }
    return 0;
}


