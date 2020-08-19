#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> dq;
    while(n--){
        string s;
        cin >> s;
        if(s == "PUSHFRONT") {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        if(s == "PRINTFRONT") {
            dq.empty() ? cout<< "NONE" : cout << dq.front();
            cout << endl;
        }
        if(s == "POPFRONT") {
            if(!dq.empty()) dq.pop_front();
        }
        if(s == "PUSHBACK") {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        if(s == "PRINTBACK") {
            dq.empty() ? cout<< "NONE" : cout << dq.back();
            cout << endl;
        }
        if(s == "POPBACK") {
            if(!dq.empty()) dq.pop_back();
        }
    }
}
