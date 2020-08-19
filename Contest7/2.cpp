#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> result;
    while(n--){
        string action;
        int num;
        cin >> action;
        if(action == "PUSH") {cin >> num; result.push_back(num);}
        if(action == "POP" && !result.empty()){
            result.pop_back();
        }
        if(action == "PRINT"){
            if(result.empty()){
                cout << "NONE";
            }
            else {
                cout << result[result.size()-1];
            }
            cout << endl;
        }
    }
}
