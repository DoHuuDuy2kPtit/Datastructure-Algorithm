#include<iostream>
#include<stack>

using namespace std;

bool checkStr(string &s) {
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            count++;
        }
        if(s[i] == ')') {
            count++;
        }
        if(count < 0) return false;
    }
    return (count == 0);
}

int main()
{
    
}


