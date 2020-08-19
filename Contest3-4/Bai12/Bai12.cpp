#include<iostream>
#include<string>
#include<map>

using namespace std;

// Tìm phần tử xuất hiện nhiều nhất trong string s;
// Nếu tổng số phần tử còn lại lớn hơn hoặc bằng phần tử xuất hiện
// nhiều nhất trừ 1 thì thỏa mãn yêu cầu đề bài. 

void solve(string s) {
    // map< char,int > count;
    // int MAX = 0;
    // char temp;
    // for(int i = 0; i < s.length(); i++){
    //     count[s[i]]++;
    //     if(MAX < count[s[i]]) {
    //         MAX = count[s[i]];
    //         temp = s[i];
    //     }
    // }
    // int total = 0;
    // for(auto i : count) {
    //     // cout << i.first << " " << i.second << endl;
    //     if(i.first == temp);
    //     else {
    //         total += i.second;
    //     }
    // }
    // if(total >= MAX - 1) cout << 1 << endl;
    // else cout << -1 << endl;
    int alpha[30];
    for(int i = 0; i < 26; i++){
        alpha[i] = 0;
    }
    for(int i = 0; i < s.length();i++){
        alpha[s[i]-'a']++;
    }
    int max = 0;
    int max_index = 0;
    for(int i = 0; i < 26; i++){
        if(alpha[i] > max){
            max = alpha[i];
            max_index = i;
        }
    }
    int total = 0;
    for(int i = 0; i < 26; i++){
        if(i == max_index);
        else{
            total += alpha[i];
        }
    }
    if(total >= max-1) cout << 1 << endl;
    else cout << -1 << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
