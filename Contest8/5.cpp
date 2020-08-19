#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        queue<string> q;
        q.push("1");
        while(n--){
            cout << q.front() << " ";
            q.push(q.front()+"0");
            q.push(q.front()+"1");
            q.pop();
        }
        cout << endl;
    }
    return 0;
}
