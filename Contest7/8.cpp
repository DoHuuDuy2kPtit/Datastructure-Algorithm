#include<bits/stdc++.h>

using namespace std;

void removeBracket(string s){
    string result;
    vector<int> switchOper;
    switchOper.push_back(0);
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='+') {
            if(switchOper.back()==0) result+='+';
            if(switchOper.back()==1) result+='-';
        }
        else if(s[i]=='-'){
            if(switchOper.back()==0) result+='-';
            if(switchOper.back()==1) result+='+';
        }
        else if(s[i]=='('){
            if(s[i-1] == '-'){
                if(switchOper.back() == 0) switchOper.push_back(1);
                else switchOper.push_back(0);
            }
            if(s[i-1] == '+'){
                if(switchOper.back()==0) switchOper.push_back(switchOper.back());
            }
        }
        else if (s[i]==')') switchOper.pop_back();
        else result +=s[i];
    }
    cout << result << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        removeBracket(s);
    }
    return 0;
}
