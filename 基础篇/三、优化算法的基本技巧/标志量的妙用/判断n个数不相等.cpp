/**
 * 编程判定从键盘输入 n 个数据互不相等
 */

#include <iostream>
using namespace std;
int main() {
    int array[100], n, flag = 1;
    cout << "要输入几个是数：";
    cin >> n;
    for (int i = 0; i < n; i++) cin >> array[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1) {
        cout << "Non repeat" << endl;
    } else {
        cout << "repeat" << endl;
    }

    return 0;
}