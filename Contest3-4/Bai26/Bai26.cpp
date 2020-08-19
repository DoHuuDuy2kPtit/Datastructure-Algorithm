#include<bits/stdc++.h>

using namespace std;

// Chuyển 2 số này từ hệ base sang hệ 10
// Tính tổng 2 số ở hệ 10 
// Chuyển kết quả đó từ hệ 10 sang hệ base

int NToDec(string number, int base) {
    int num = 0;
    int power = 1;
    for(int i = number.size()-1; i >= 0; i--){
        num+=(number[i]-'0')*power;
        power*=base;
    }
    return num;
}

string decToN(int n, int base){
    string result = "";
    while(n > 0){
        char temp = (n%base) + '0';
        result += temp;
        n = n/base;
    }
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int base;
        string num1, num2;
        cin >> base >> num1 >> num2;
        cout << decToN( NToDec(num1,base) + NToDec(num2,base),base ) << endl;
    }
}
