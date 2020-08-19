#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    queue<int> q;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        if(s == "PUSH") {
            int num;
            cin >> num;
            q.push(num);
        }
        if(s== "PRINTFRONT"){
            q.empty() ? cout << "NONE" : cout << q.front();
            cout << endl;
        }
        if(s == "POP"){
            if(!q.empty()) q.pop();
        }
    }
}
