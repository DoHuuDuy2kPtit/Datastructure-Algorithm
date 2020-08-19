#include<iostream>
#include<string>

using namespace std;

// Sử dụng sinh hoán vị (chú ý trong việc sử dụng string);

int state = 0;

void nextPermutation(string &s) {
    int i = s.length() - 1;
    while((s[i] -'0') <= (s[i-1] - '0') && i>0) {
        i--;
    }
    if(i != 0){
        state = 2;
        int k = s.length() - 1;
        while((s[k]-'0') <= (s[i-1]-'0')) {
            k--;
        }
        char temp;
        temp = s[k];
        s[k] = s[i-1];
        s[i-1] = temp;
        int l = i;
        int r = s.length() - 1;
        while(l <= r) {
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    } else {
        state = 1;
    }

}

int main()
{
    int test;
    cin >> test;
    while(test > 0) {
        int number;
        cin >> number;
        string s;
        cin >> s;
        nextPermutation(s);
        cout << number << " ";
        if(state == 2) {
            cout << s <<endl;
        } else
        cout<< "BIGGEST" <<endl;
        test--;
    }
    return 0;
}
