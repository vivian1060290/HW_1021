#include <iostream>
using namespace std;

const int maxsize = 100;

// 遞迴實現冪集
void gp(int set[], int current[], int index, int setSize) {
    if (index == setSize) {
        cout << "{ ";
        for (int i = 0; i < setSize; i++) {
            if (current[i] != -1) {
                cout << current[i] << " ";
            }
        }
        cout << "}" << endl;
        return;
    }

    // 包含當前元素
    current[index] = set[index]; // 將當前元素添加到子集中
    gp(set, current, index + 1, setSize); // 遞迴調用，處理下一個元素

    // 不包含當前元素
    current[index] = -1; // 使用 -1 表示不包含當前元素
    gp(set, current, index + 1, setSize); // 遞迴調用，處理下一個元素
}

int main() {
    int set[maxsize];
    int setSize;

    cout << "請輸入集合的大小: ";
    cin >> setSize;

    cout << "請輸入集合的元素: ";
    for (int i = 0; i < setSize; i++) {
        cin >> set[i];
    }

    int current[maxsize];

    // 初始化 current 陣列為 -1，表示不包含任何元素
    for (int i = 0; i < maxsize; i++) {
        current[i] = -1;
    }

    cout << "冪集為：" << endl;
    gp(set, current, 0, setSize); // 使用用戶輸入的集合大小
    return 0;
}
//總共會有2^n個子集，輸出的子集會按照陣列依序排序至空集合
//因此，for example
//n=3,s={1,2,3}
//輸出2^3=8個子集合，{1,2,3}{1,2}{1,3}{1}{2,3}{2}{3}{}
