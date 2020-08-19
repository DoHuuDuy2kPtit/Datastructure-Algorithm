#include<bits/stdc++.h>

using namespace std;


int main(){
    vector<int> result;
    while(true){
        string action;
        int n;
        cin >> action;
        if(action == "push") {
            cin >> n;
            result.push_back(n);
        }
        if(action == "pop" && !result.empty()){
            result.pop_back();
        }

        if(action == "show"){
            if(result.empty()){
                cout << "empty";
                break;
            }
            else {
                for(int i = 0; i < result.size();i++){
                    cout << result[i] << " ";
                }
                cout << endl;
            }
        }
    }
}
