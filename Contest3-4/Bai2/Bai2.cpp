#include<iostream>

using namespace std;

int sum = 0;

// int change5To6(int a) {
//     if(a <= 10) {
//         if(a%10==5) {
//             return (a%10+1);
//         }
//         else return a%10;
//     } else {
//         int temp = change5To6(a/10);
//         if(a%10 == 5){
//             sum = (a%10+1) + temp*10;
//         }
//         else sum = (a%10) + temp*10;
//         return sum;
//     }
// }

// int change6To5(int a) {
//     if(a <= 10) {
//         if(a%10 == 6)
//             return (a%10-1);
//         else return a%10;
//     } else {
//         int temp = change6To5(a/10);
//         if(a%10 == 6){
//             sum = (a%10-1) + temp*10;
//         }
//         else sum = (a%10) + temp*10;
//         return sum;
//     }
// }

// Duyệt đến khi gặp số 6 thì chuyển thành 5;

int change6To5(string a){
    for(int i = 0; i < a.length();i++){
        if(a[i] == '6') a[i] = '5';
    }
    return stoi(a);
}

// Đuyệt đến khi gặp số 5 chuyển thành 6;

int change5To6(string a){
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '5') a[i] = '6';
    }
    return stoi(a);
}

int main() {
        string a,b;
        cin >> a; 
        cin >> b;
        sum = 0;
        cout << change6To5(a) + change6To5(b)<< " ";
        cout << change5To6(a) + change5To6(b)<< endl;
    return 0;
}

