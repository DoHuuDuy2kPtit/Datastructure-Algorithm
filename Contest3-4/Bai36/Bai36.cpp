#include<bits/stdc++.h>

using namespace std;

string s1;
string s2;

long long binaryToDec(string s1){
    long long num = 0;
    long long power = 1;
    for(int i = s1.size()-1; i >= 0; i--){
        num += (s1[i]-'0')*power;
        power*=2;
    }
    return num;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> s1 >> s2;
        cout << binaryToDec(s1)*binaryToDec(s2) << endl;
    }
}
