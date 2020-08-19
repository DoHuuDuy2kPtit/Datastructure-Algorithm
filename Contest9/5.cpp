#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        vector<vector<int>> a(1005);
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int head, tail;
            cin >> head >> tail;
            a[head].push_back(tail);
        }
        for(int i = 1; i <= n; i++){
            cout << i << ": ";
            for(int j = 0; j < a[i].size(); j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
