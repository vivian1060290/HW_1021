#include <iostream>
using namespace std;

// ���j��{���J�Ҩ��
int A(int m, int n) { 
    if (m == 0) {
        return n + 1;
    }
    else if (m == 1) {
        return n + 2;
    }
    else if (m == 2) {//���]m=2,n=3,2*3+3=9
        return 2 * n + 3;
    }
    else if (m == 3) {//
        return A(2, A(3, n - 1));
    }
    else {
        // ��� m > 3�A�N�ɭP�L�a���j�A�ڭ̳q�`���Ҽ{�t�ơC
        return A(m - 1, A(m, n - 1));
    }
}


int main() {
    int m, n;
    cout << "��J m �M n ���ȡ]�D�t��ơ^�G";
    cin >> m >> n;

    // �ˬd��J�����ĩ�
    if (m < 0 || n < 0) {
        cout << "�п�J�D�t��ơI" << endl;
        return 1; // ��^���~�N�X
    }

    // �p����J�Ҩ�ƪ����G
    cout << "A(" << m << ", " << n << ") = " << A(m, n) << endl;
    return 0;
}
