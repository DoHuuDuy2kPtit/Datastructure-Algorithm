#include<bits/stdc++.h>

using namespace std;

// Thực hiện đệ quy:
// Điều kiện dừng là khi mẫu số chia hết cho tử số
// Đệ quy với phân số có dạng ts/ms = ts/ma - 1/msc (msc = ms/tu + 1);

void unitFraction(long long tuso,long long mauso) {
    if(mauso%tuso == 0) {
        cout << 1 << "/" << mauso/tuso;
        return;
    }
    else {
        long long mausochung = mauso/tuso + 1;
        cout << 1 << "/" << mausochung << " + ";
        unitFraction(tuso*mausochung - mauso,mausochung*mauso);
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        long long p, q;
        cin >> p >> q;
        unitFraction(p,q);
        cout << endl;
    }
    return 0;
}
