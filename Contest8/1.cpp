#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        queue<int> q;
        cin >> n;
        while(n--){
            int chooseNum;
            cin >> chooseNum;
            switch(chooseNum){
            case 1:
                cout << q.size() << endl;
                break;
            case 2:
                q.empty() ? cout << "YES" : cout << "NO";
                cout << endl;
                break;
            case 3:
                int num;
                cin >> num;
                q.push(num);
                break;
            case 4:
                if(!q.empty()) q.pop();
                else ;
                break;
            case 5:
                q.empty() ? cout << -1 : cout << q.front();
                cout << endl;
                break;
            case 6:
                q.empty() ? cout << -1 : cout << q.back();
                cout << endl;
                break;
            }
        }
    }
}
