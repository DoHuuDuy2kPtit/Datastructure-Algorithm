#include<bits/stdc++.h>

using namespace std;

// Mảng vectorCubeNum chứa các số lập phương được sắp xếp giảm dần
// Đối chiếu đầu vào với mảng vectorCubeNum để tìm ra kết quả


vector<string> vectorCubeNum(long long n) {
    vector<string> result;
    for(long long  i = 1; i*i*i <= n; i++) {
        string temp = to_string(i*i*i);
        result.push_back(temp);
    }
    reverse(result.begin(),result.end());
    return result;
}

void solve(vector<string> result, long long n) {
    string num = to_string(n);
    for(int i = 0; i < result.size(); i++){
        int index = 0;
        for(int j = 0; j < num.length(); j++) {
            if(num[j] == result[i][index]) {
                index++;
            }
        }
        if(index == result[i].length()) {
            cout << result[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        long long n;
        cin >> n;
        vector<string> result = vectorCubeNum(n);
        solve(result,n);
    }
    return 0;
}
