//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n, m;
//bool check = false;
//
//bool cycleByDFS(int u,vector<int> a[],bool chuaxet[])
//{
//    stack<int> stk;
//    stk.push(u);
//    chuaxet[u] = false;
//    while(!stk.empty()){
//        int s = stk.top();
//        stk.pop();
//        for(int i = 0; i < a[s].size();i++){
//            if(chuaxet[a[s][i]]){
//                stk.push(s);
//                stk.push(a[s][i]);
//                for(int j = 0; j < a[a[s][i]].size(); j++){
//                    if(!chuaxet[a[a[s][i]][j]] && a[a[s][i]][j] != s){
//                        return true;
//                    }
//                }
//                chuaxet[a[s][i]] = false;
//                break;
//            }
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    while(t--)
//    {
//        check = false;
//        cin >> n >> m;
//        vector<int> a[n+1];
//        bool chuaxet[n+1];
//        int truoc[n+1];
//        for(int i = 1; i <= m; i++)
//        {
//            int u, v;
//            cin >> u >> v;
//            a[u].push_back(v);
//            a[v].push_back(u);
//        }
//        for(int i = 1; i <= n; i++) chuaxet[i] = true;
//        if(cycleByDFS(1,a,chuaxet)) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//}


#include<bits/stdc++.h>

using namespace std;

struct edge{
    int head;
    int tail;
};

// Tim root cua dinh

int find(int parent[],int i){
    if(parent[i]==-1) return i;
    else
    {
        return find(parent,parent[i]);
    }
}

// Gan 2 root cua 2 dinh khac nhau vao nhau

void Union(int parent[],int x, int y)
{
    int xset = find(parent,x);
    int yset = find(parent,y);
    if(xset!= yset)
    {
        parent[xset] = yset;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int parent[n+1];
        for(int i = 0; i <= n; i++) parent[i] = -1;
        vector<edge> E;
        int testCase = 1;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            edge e;
            e.head = u;
            e.tail = v;
            E.push_back(e);
        }
        // Tim root của dinh dau va dinh cuoi
        // Neu no chung 1 root thi tao chu trinh
        // Neu ko thi ta gan 2 root lai voi nhau
        for(int i = 0; i < E.size(); i++){
            int x = find(parent, E[i].head);
            int y = find(parent, E[i].tail);
            if(x==y) testCase = 0;
            Union(parent,x,y);
        }
        if(testCase == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
