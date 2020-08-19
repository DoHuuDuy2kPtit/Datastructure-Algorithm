#include<bits/stdc++.h>

using namespace std;

void solve(int a[],int n,int b[], int m){
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i < n && j < m){
        if(a[i] < b[j]){
            unionArr.push_back(a[i]);
            i++;
        } else {
            unionArr.push_back(b[j]);
            j++;
        }
    }
    while(i < n){
        unionArr.push_back(a[i]);
        i++;
    }
    while(j < m){
        unionArr.push_back(b[j]);
        j++;
    }
    cout << unionArr[0] << " ";
    for(int i = 1; i < unionArr.size();i++){
        if(unionArr[i] != unionArr[i-1]) cout << unionArr[i] << " ";
    }
    cout << endl;
    for(int i = 1; i < unionArr.size();i++){
        if(unionArr[i] == unionArr[i-1])cout << unionArr[i] << " ";
    }
    cout << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for(int i = 0; i < n;i++) cin >> a[i];
        for(int i = 0; i < m;i++) cin >> b[i];
        solve(a,n,b,m);
    }
}
