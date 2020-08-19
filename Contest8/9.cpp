#include<bits/stdc++.h>

using namespace std;

// Nếu s >= t thì kết quả là s - t;
// Lặp cho đến khi s = t;
// Nếu t>s và t%2!=0 thì t = t+1
// Nếu t>s và t%2==0 thì t = t/2
// Còn nếu t < s thì  t = t + 1;

int main()
{
    int test;
    cin >> test;
    while(test--){
        int s, t;
        cin >> s >> t;
        if(s>=t) cout << s-t << endl;
        else{
            int count = 0;
            while(s!=t) {
                count++;
                if(t>s&&t%2!=0){
                    t++;
                }
                else if(t>s && t%2==0){
                    t /= 2;
                }
                else t++;
            }
            cout << count << endl;
        }
    }
}
