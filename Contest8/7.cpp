#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue<int> q;
        int count = 0;
        q.push(1);
        while(true){
            int res = q.front();
            if(res <= n){
                count++;
                q.push(res*10);
                q.push(res*10+1);
                q.pop();
            }
            else {
                break;
            }
        }
        cout << count << endl;
    }
}
