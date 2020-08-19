#include<iostream>
#include<string>
#include<time.h>

using namespace std;

// Sinh nhị phân
// Duyệt từ cuối về tìm số 0 đầu tiên
// Nếu tìm thấy thì tăng lên 1 và cập nhập các vị trí phía sau nó về 0
// Nếu không tìm thấy thì reset về 0;

void nextBit(string &s) {
    int j = s.length() - 1;
    while(s[j] == '1' && j >= 0){
            j--;
    }
    if(j != -1) {
        s[j] = '1';
        for(int i = j + 1; i < s.length(); i++) {
            s[i] = '0';
        }
    }
    else {
        for(int i = 0 ; i < s.length(); i++)
            s[i] = '0';
    }
}

int main()

{
    int test;
    string s;
    cin >> test;
    while(test > 0) {
        cin >> s;
        nextBit(s);
        cout << s << endl;
        test--;
    }
    return 0;
}
