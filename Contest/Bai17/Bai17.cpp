#include<iostream>
#include<vector>
//#include<cmath>

// 

using namespace std;

void nextBit(string &s) {
    int i = s.size() - 1;
    while(s[i] == '9' && i >= 0) i--;
    if(i != -1) {
        s[i] = '9';
        for(int j = i+1; j < s.size(); j++) {
            s[j] = '0';
        }
    } else {
        s[0] = '9';
        for(int m = 1; m < s.size(); m++) {
            s[m] = '0';
        }
        s+="0";
    }
}

int main() {
    int test;
    cin >> test;
    while(test > 0) {
        string s="";
        int n;
        cin >> n;
        s+="9";
        while(stoi(s) % n != 0) {
            nextBit(s);
        }
        cout << stoi(s) << endl;
        s.clear();
        test--;
    }
}
