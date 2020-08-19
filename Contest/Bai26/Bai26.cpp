#include<bits/stdc++.h>
#include<string>

using namespace std;

void swap(char &m, char &n) {
    char temp;
    temp = m;
    m = n;
    n = temp;
}

void biggestNum(string &s, int k) {
    int h = 0;
    while(k > 0) {
        int index = h;
        int Max = s[h];
        for(int i = s.length()-1; i >= h; i--) {
            if(Max < s[i]) {
                Max = s[i];
                index = i;
            }
        }
        swap(s[index],s[h]);
        h++;
        k--;
    }
}

int main()
{
    int test;
    cin >> test;
    while(test--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        biggestNum(s,k);
        cout << s << endl;;
    }

}
