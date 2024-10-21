#include <iostream>
using namespace std;

const int max= 100;

// 遞迴實現冪集
void gP(int set[], int current[], int index, int setSize) {
    // 當 index 等於集合大小時，表示已經生成了一個子集
    if (index == setSize) {
        cout << "{ ";
        // 打印當前子集中的元素
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
    gP(set, current, index + 1, setSize); // 遞迴調用，處理下一個元素

    // 不包含當前元素
    current[index] = -1; // 使用 -1 表示不包含當前元素
    gP(set, current, index + 1, setSize); // 遞迴調用，處理下一個元素
}

int main() {
    int set[] = { 1, 2, 3 }; // 定義集合，可以根據需要更改元素
    int current[max]; // 用於保存當前子集

    // 初始化 current 陣列為 -1，表示不包含任何元素
    for (int i = 0; i <max; i++) {
        current[i] = -1;
    }

    cout << "冪集為：" << endl;
    gP(set, current, 0, 3); // 3 是 set 的大小
    return 0;
}
