#include<bits/stdc++.h>

using namespace std;

bool isCyCle(vector<int> a[],int s, int n,bool chuaxet[])
{
    int truoc[n+1];
    for(int i = 0; i <= n; i++) truoc[i] = -1;
    queue<int> q;
    q.push(s);
    chuaxet[s] = false;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < a[u].size(); i++)
        {
            if(chuaxet[a[u][i]]) {
                q.push(a[u][i]);
                chuaxet[a[u][i]] = false;
                truoc[a[u][i]] = u;
            }
            else if(truoc[u] != a[u][i])
                return true;
        }
    }
    return false;
}

bool isCyCleDiscon(vector<int> a[], int n,bool chuaxet[])
{
    for(int i = 1; i <= n; i++){
        if(chuaxet[i] && isCyCle(a,i,n,chuaxet)) return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a[n+1];
        bool chuaxet[n+1];
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        for(int i = 1; i <= n; i++) chuaxet[i] = true;
        if(isCyCleDiscon(a,n,chuaxet)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
