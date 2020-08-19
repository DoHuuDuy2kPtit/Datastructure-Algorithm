#include<iostream>
#include<string>

using namespace std;

// Áp dụng sinh nhị phân

void nextPermutation(string &s) {
    int i = s.length() - 1;
    while(s[i] <= s[i-1] && i > 0) i--;
    int k = s.length() - 1;
    while(s[k] <= s[i-1] && k > 0) k--;
    char temp = s[k];
    s[k] = s[i-1];
    s[i-1] = temp;
    int l = i;
    int r = s.length() - 1;
    while(l < r) {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

bool check(string &s) {
    for(int i =s.length()-1; i > 0; i--) {
        if(s[i] > s[i-1]) return false;
    }
    return true;
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        string s;
        cin >> s;
        while(check(s) == false) {
            cout << s <<" ";
            nextPermutation(s);
        }
        cout << s << endl;
    }
}
