#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue<string> q;
        q.push("9");
        while(stoi(q.front()) % n != 0){
            q.push(q.front()+"0");
            q.push(q.front()+"9");
            q.pop();
        }
        cout << q.front() << endl;
    }
}
