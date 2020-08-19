#include<bits/stdc++.h>

using namespace std;

int color[20];
int n, m, d;

// Kiem tra mau cua cac dinh ke
// Neu mau dang xet trung mau cua cac dinh ke thi bo qua
// Neu mau dang xet khong trung mau cua cac dinh ke thi xet tiep

bool checkColor(int u, int c,vector<int> a[])
{
    for(int i = 0; i < a[u].size(); i++){
        if(c == color[a[u][i]]) return false;
    }
    return true;
}

// Ham quay lui de thu mau

bool Try(int u,vector<int> a[])
{
    if(u == n+1){
        return true;
    }
    for(int c = 1; c <= d; c++){
        if(checkColor(u,c,a)){
            color[u] = c;
            if(Try(u+1,a)) return true;
            color[u] = 0;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> d;
        vector<int> a[n+1];
        for(int i = 1; i <= n; i++){
            color[i] = 0;
        }
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if(Try(1,a)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
