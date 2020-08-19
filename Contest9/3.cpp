#include<bits/stdc++.h>

using namespace std;

int main()
{
//    int t;
//    cin >> t;
//    while(t--){
        int n;
        cin >> n;
        int a[n][n];
        vector< vector <int> > result(1005);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                if(a[i][j] == 1) result[i].push_back(j);
            }
        }
//        for(int i = 1; i <= n; i++){
//            sort(result[i].begin(),result[i].end());
//        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < result[i].size();j++){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
//    }
}
