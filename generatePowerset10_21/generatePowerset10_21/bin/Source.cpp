#include <iostream>
using namespace std;

const int max= 100;

// ���j��{����
void gP(int set[], int current[], int index, int setSize) {
    // �� index ���󶰦X�j�p�ɡA��ܤw�g�ͦ��F�@�Ӥl��
    if (index == setSize) {
        cout << "{ ";
        // ���L��e�l����������
        for (int i = 0; i < setSize; i++) {
            if (current[i] != -1) { 
                cout << current[i] << " ";
            }
        }
        cout << "}" << endl; 
        return;
    }

    // �]�t��e����
    current[index] = set[index]; // �N��e�����K�[��l����
    gP(set, current, index + 1, setSize); // ���j�եΡA�B�z�U�@�Ӥ���

    // ���]�t��e����
    current[index] = -1; // �ϥ� -1 ��ܤ��]�t��e����
    gP(set, current, index + 1, setSize); // ���j�եΡA�B�z�U�@�Ӥ���
}

int main() {
    int set[] = { 1, 2, 3 }; // �w�q���X�A�i�H�ھڻݭn��露��
    int current[max]; // �Ω�O�s��e�l��

    // ��l�� current �}�C�� -1�A��ܤ��]�t���󤸯�
    for (int i = 0; i <max; i++) {
        current[i] = -1;
    }

    cout << "�������G" << endl;
    gP(set, current, 0, 3); // 3 �O set ���j�p
    return 0;
}
