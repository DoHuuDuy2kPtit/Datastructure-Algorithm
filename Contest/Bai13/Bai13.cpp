#include<iostream>
#include<string>

using namespace std;

// Sinh nhị phân như bình thường, sau đó kiểm tra:
// Lặp đến hết dãy bit vừa sinh nếu gặp A thì tăng biến count lên 1 còn nếu gặp B thì cho biến count = 0;
// Nếu count >= k thì ta tăng biến countStrA(biến đếm số dãy kí tự A liên tiếp) lên 1
// Nếu countStrA == 1 thì ta in ra màn hình 

void init(string &s, int n) {
    for(int i = 0; i < n; i++) {
        s+="A";
    }
}

void nextBit(string &s) {
    int j = s.length() - 1;
    while(s[j] == 'B' && j >= 0) {
        j--;
    }
    s[j] = 'B';
    for(int i = j+1 ; i < s.length();i++) {
        s[i] = 'A';
    }
}

bool testCharA(string s, int k) {
    int count = 0;
    int countStrA = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'A') count++;
        else count = 0;
        if(count >= k) countStrA ++;
    }
    if(countStrA == 1) return true;
    else return false;
}

bool check(string s) {
    for(int i = 0; i<s.length();i++) {
        if(s[i] == 'A') return false;
    }
    return true;
}

int main()
{
    string s="";
    string s1="";
    int n,k;
    cin>>n>>k;
    int countTotal = 0;
    init(s,n);
    while(check(s) == false) {
        if(testCharA(s,k)==true) {
            countTotal++;
            s1+=s;
        }
        nextBit(s);
    }
    cout << countTotal <<endl;
    int countPrint = 0;
    for(int i = 0; i < s1.length(); i++) {
        cout << s1[i];
        countPrint++;
        if(countPrint == n) {
            cout << endl;
            countPrint = 0;
        }
    }
    return 0;
}
