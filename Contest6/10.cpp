#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        bool checkNum[10] = {false};
        string number[n];
        for(int i = 0; i < n; i++) cin >> number[i];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < number[i].size();j++){
                checkNum[int(number[i][j]-'0')] = true;
            }
        }
        for(int i = 0; i < 10; i++)
            if(checkNum[i]) cout << i << " ";
        cout << endl;
    }
}
