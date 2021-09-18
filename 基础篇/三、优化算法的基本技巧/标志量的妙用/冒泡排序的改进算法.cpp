#include <iostream>
using namespace std;
int main() {
    int array[100], n, flag;
    cout << "请输入有几个数：" << endl;
    cin >> n;
    cout << "请输入这几个数：" << endl;
    for (int i = 0; i < n; i++) cin >> array[i];
    // 循环前将 flag 置 1，以便进入循环
    flag = 1;
    for (int i = 0; i < n && 1 == flag; i++) {
        flag = 0;
        for (int j = 0; j < n - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                // 进行了一次交换，说明还没排好序
                flag = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "\t";
    }
    

    return 0;
}