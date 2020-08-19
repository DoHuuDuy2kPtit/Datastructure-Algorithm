#include<bits/stdc++.h>

using namespace std;

int a[1001][1001];
int n, m;

void Floyd()
{
    for(int k = 1; k <= n; k++){
        for(int i =1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    int sum = 0;
    int count = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] != 0 && a[i][j] != 1e9) sum += a[i][j], count++;
        }
    }
    printf("%0.2f\n",sum*1.0/(count));
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) a[i][j] = 0;
                else a[i][j] = 1e9;
            }
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u][v] = 1;
        }
        Floyd();
    }
}
