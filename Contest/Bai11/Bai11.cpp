#include<iostream>
#include<string>

using namespace std;

void toBinary(string &s1) {
    for(int i = 1 ;i < s1.length(); i++) {
        if(s1[i] == '1' && s1[i-1] == '1') {
            s1[i] = '0';
        }
        else s1[i] = ((s1[i] - '0')+(s1[i-1] - '0')) + '0';
    }
}

int main() {
    int test;
    cin >> test;
    while(test > 0) {
        string s1;
        cin>>s1;
        toBinary(s1);
        cout<<s1<<endl;
        test--;
    }
}
