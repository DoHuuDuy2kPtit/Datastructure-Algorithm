// Bai 8

#include<bits/stdc++.h>

using namespace std;
int n, m, u;

void Tree_DFS(int u, vector<int> a[], bool chuaxet[])
{
    vector<int> T;
    stack<int> stk;
    stk.push(u);
    chuaxet[u] = false;
    while(!stk.empty())
    {
        int s = stk.top();
        stk.pop();
        for(int i = 0; i < a[s].size(); i++){
            if(chuaxet[a[s][i]])
            {
                chuaxet[a[s][i]] = false;
                stk.push(s);
                stk.push(a[s][i]);
                T.push_back(s);
                T.push_back(a[s][i]);
                break;
            }
        }
    }
    if(T.size()/2 < n-1) cout << -1 << endl;
    else {
        for(int i = 0; i < T.size(); i+=2)
        {
            cout << T[i] << " " << T[i+1] << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> u;
        vector<int> a[n+1];
        bool chuaxet[n+1];
        for(int i = 1; i <= m; i++){
            int s, t;
            cin >> s >> t;
            a[s].push_back(t);
            a[t].push_back(s);
        }
        for(int i = 1; i <= n; i++) chuaxet[i] = true;
        Tree_DFS(u,a,chuaxet);
    }
    return 0;
}
