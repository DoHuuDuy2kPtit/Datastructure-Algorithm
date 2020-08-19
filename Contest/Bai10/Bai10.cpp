#include<iostream>
#include<string>

using namespace std;


void init(string &s1, string &s2) {
    for(int i = 0; i < s1.length(); i++) {
        s2+=s1[i];
    }
}

void toGray(string &s1, string &s2) {
    for(int i = 0; i < s1.length(); i++) {
        s1[i] = ((s1[i] - '0')^(s2[i] - '0')) +'0';
    }
}

int main() {
    int test;
    cin >> test;
    while(test >0){
        string s1;
        string s2 = "0";
        cin>>s1;
        init(s1,s2);
        toGray(s1,s2);
        cout<< s1 <<endl;
        test--;
    }
    return 0;
}
