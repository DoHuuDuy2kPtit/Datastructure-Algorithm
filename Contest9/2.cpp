#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a[n];
    string s;
    getline(cin,s);
    for(int i = 0 ; i < n; i++){
        getline(cin,s);
        for(int j = 0; j < s.length(); j++){
            if(s[j]!= ' '){
                string temp;
                while(s[j] != ' ' && j < s.length()){
                    temp+=s[j++];
                }
                a[i].push_back(stoi(temp));
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j]>i+1)
                cout << i+1 << " " << a[i][j] << endl;
        }
    }
}
