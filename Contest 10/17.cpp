#include<bits/stdc++.h>

using namespace std;
int a[201][201], n, m;

// Su dung Floyd de tim duong di ngan nhat tu dinh u den dinh v
// Duong di ngan nhat tu dinh u den dinh v la gia tri a[u][v]

void Floyd()
{
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) a[i][j] = 0;
            else a[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }
    Floyd();
    int q;
    cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        cout << a[s][t] << endl;
    }
}




