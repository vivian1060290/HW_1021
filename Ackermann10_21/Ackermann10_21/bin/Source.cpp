#include <iostream>
using namespace std;

// 遞迴實現阿克曼函數
int A(int m, int n) { 
    if (m == 0) {
        return n + 1;
    }
    else if (m == 1) {
        return n + 2;
    }
    else if (m == 2) {//假設m=2,n=3,2*3+3=9
        return 2 * n + 3;
    }
    else if (m == 3) {//
        return A(2, A(3, n - 1));
    }
    else {
        // 對於 m > 3，將導致無窮遞迴，我們通常不考慮負數。
        return A(m - 1, A(m, n - 1));
    }
}


int main() {
    int m, n;
    cout << "輸入 m 和 n 的值（非負整數）：";
    cin >> m >> n;

    // 檢查輸入的有效性
    if (m < 0 || n < 0) {
        cout << "請輸入非負整數！" << endl;
        return 1; // 返回錯誤代碼
    }

    // 計算阿克曼函數的結果
    cout << "A(" << m << ", " << n << ") = " << A(m, n) << endl;
    return 0;
}
