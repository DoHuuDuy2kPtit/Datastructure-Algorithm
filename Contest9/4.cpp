#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< int > a[n];
    string s;
    getline(cin,s);
    for(int i = 0; i < n; i++){
        getline(cin,s);
        for(int j = 0; j < s.length(); j++){
            if(s[j]!= ' '){
                string temp;
                while(s[j] != ' ' && j < s.length()){
                    temp += s[j++];
                }
                a[i].push_back(stoi(temp));
            }
        }
    }
    int res[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].size(); j++){
            res[i+1][a[i][j]] = 1;
            res[a[i][j]][i+1] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
