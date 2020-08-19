#include<bits/stdc++.h>

using namespace std;

int precedence(char x){
    if(x == '^') return 3;
    else if(x == '*' || x == '/') return 2;
    else if(x == '+' || x == '-') return 1;
    return -1;
}

// Duyệt string s;
// 1. Gặp toán hạng thì in ra 
// 2. Gặp mở ngoặc thì đẩy vào ngăn xếp
// 3. Gặp đóng ngoặc thì 
//    + Nếu ngăn xếp chưa rỗng và đỉnh ngăn xếp không phải dấu mở ngoặc 
//      thì in ra các phần tử trong đỉnh ngăn xếp cho đến khi gặp dấu mở ngoặc
//    + Sau đó xóa bỏ dấu mở ngoặc trên đỉnh ngăn xếp.
// 4. Gặp toán tử thì:
//    + Nếu Độ ưu tiên > Độ ưu tiên của TOP thì đẩy vào ngăng xếp
//    + Nếu Độ ưu tiên < Độ ưu tiên của TOP thì in ra sau lặp cho đến khi ngăn xếp rỗng hoặc quay lại trường hợp trên
//      thì ta đẩy vào ngăn xếp. 
// 5. Nếu trong ngăn xếp vẫn còn thi In hết ra  


void solve(string s){
    stack<char> stk;
    string ns;
    for(int i = 0; i < s.length(); i++){
        if((s[i]>='a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            ns+= s[i];
        }
        else if(s[i] == '(') stk.push(s[i]);

        else if(s[i] == ')'){
            while(!stk.empty() && stk.top() != '('){
                char c = stk.top();
                stk.pop();
                ns += c;
            }
            stk.pop();
        }
        else{
            while(!stk.empty()&&precedence(s[i]) <= precedence(stk.top())){
                char c = stk.top();
                stk.pop();
                ns += c;
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty()){
        char c = stk.top();
        if(c != '(') ns+=c;
        stk.pop();
    }
    cout << ns << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
