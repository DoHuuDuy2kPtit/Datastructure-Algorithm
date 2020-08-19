#include<bits/stdc++.h>

using namespace std;

int n, m;

// Do thi la cay khi va chi khi
// 1. Khong chua chu trinh
// 2. Lien thong

struct edge{
    int head, tail;
};

// Cac ham de kiem tra chu trinh

// Tim root cua 1 dinh

int findRoot(int i, int parent[])
{
    if(parent[i] == -1) return i;
    else return findRoot(parent[i],parent);
}

// Gan 2 root vao nhau

void Union(int parent[],int x, int y)
{
    int xset = findRoot(x,parent);
    int yset = findRoot(y,parent);
    if(xset != yset){
        parent[xset] = yset;
    }
}
//

// Ham kiem tra lien thong

bool CheckConnect(vector<int> a[],int u,bool chuaxet[]){
    queue<int> q;
    q.push(u);
    chuaxet[u] = false;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int i = 0; i < a[s].size(); i++)
        {
            if(chuaxet[a[s][i]]){
                q.push(a[s][i]);
                chuaxet[a[s][i]] = false;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(chuaxet[i]) return false;
    }
    return true;
}

//

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a[n+1];
        vector<edge> E;
        int parent[n+1];
        bool chuaxet[n+1];
        for(int i = 1; i <= n; i++) parent[i] = -1, chuaxet[i] = true;
        for(int i = 1; i <= n-1; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
            edge e;
            e.head = u;
            e.tail = v;
            E.push_back(e);
        }
        int testCase = 1;
        for(int i = 0; i < E.size(); i++){
            int x = findRoot(E[i].head,parent);
            int y = findRoot(E[i].tail,parent);
            if(x == y) testCase = 0;
            Union(parent,x,y);
        }
        if(testCase == 1 && CheckConnect(a,1,chuaxet)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
