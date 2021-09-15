/**
 * 编写一个算法，其功能是给给一维数组 a 输入任意 6 个整数，假设为 5,7,4,8,9,1 然后建立一个具有如下图的方阵，并打印出来
 * 
 *  5   7   4   8   9   1
 *  1   5   7   4   8   9
 *  9   1   5   7   4   8 
 *  8   9   1   5   7   4
 *  4   8   9   1   5   7
 *  7   4   8   9   1   5
 */

#include <iostream>

using namespace std;

// 非递归算法
void plain_print(int a[])
{
    for (int i = 0; i < 6; i++)
    {

        for (int j = (6 - i) % 6, k = 0; k < 6; j = (j + 1) % 6, k++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

// 递归算法
void recurrence_print(int a[], int n)
{
    if (n >= 6)
        return;
    for (int j = (6 - n) % 6, k = 0; k < 6; j = (j + 1) % 6, k++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
    recurrence_print(a, ++n);

}

int main()
{
    int a[6] = {5, 7, 4, 8, 9, 1};
    // plain_print(a);
    recurrence_print(a, 0);
    return 0;
}