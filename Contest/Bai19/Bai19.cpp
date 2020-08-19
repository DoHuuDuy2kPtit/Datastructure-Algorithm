#include<iostream>
#include<vector>

using namespace std;


void display(vector<int> result){
    if(result.size() > 0) {
        cout << "[";
        for(int i = 0; i < result.size()-1;i++) {
            cout << result[i] << " ";
        }
    cout << result[result.size()-1] << "]" << endl;
    }
    else return;
}

void recursion(vector<int> result,vector<int> a, int n){
    if(n==0) return;
    else {
        for(int i = 0; i < n-1; i++) {
            result.push_back(a[i]+a[i+1]);          // Lưu kết quả của phép tính a[i] + a[i+1] vào result;
        }
        for(int i = 0; i < result.size(); i++) {
            a[i] = result[i];                       // Gán lại kết quả cho mảng a[i] 
        }
        display(result);                            // In ra result
        result.clear();                             // Nhớ xóa result đi để thực hiện cho lần đệ quy sau
        recursion(result,a,n-1);                    // Hàm đệ quy với số lượng phần tử bớt đi 1;
    }
}

int main()
{
    int test;
    cin >> test;
    while(test > 0) {
        vector<int> result;
        vector<int> arr;
        int n,x;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x;
            arr.push_back(x);
        }
        display(arr);
        recursion(result,arr,n);
        test--;
    }
    return 0;
}
