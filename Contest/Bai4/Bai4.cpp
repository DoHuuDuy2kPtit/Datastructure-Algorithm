#include<iostream>
#include<string>

using namespace std;


// Tương tự bài nhị phân

void init(string &s, int &n) {
    for(int i = 0; i< n;i++) {
        s += 'A';
    }
}

void nextBit(string &s,int &n) {
    int i = n - 1;
    while(s[i] == 'B' && i >= 0) {
        i--;
    }
    s[i] = 'B';
    for(int j = i+1; j < s.length() ; j++) {
        s[j] = 'A';
    }
}

bool check(string &s, int &n) {
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') return false;
    }
    return true;
}

int main()
{
    int test;
    cin >> test;
    while(test > 0) {
        string s = "";
        int n;
        cin >> n;
        init(s,n);
        while (check(s,n) != true) {
            cout << s << " ";
            nextBit(s,n);
        }
        cout << s << endl;
        test--;
    }
}
