/**
 * 找出 n 个自然数(1,2,3,...,n)中取 r 个数的组合。例如，当 n = 5，r=3时，所有组合为：
 *      1   2   3
 *      1   2   4
 *      1   2   5
 *      1   3   4
 *      1   3   5   
 *      1   4   5
 *      2   3   4
 *      2   3   5
 *      2   4   5
 *      3   4   5
*/

#include <iostream>
using namespace std;
int a[100];     

void combine(int m, int k) {
    int i, j;
    for (int i = m; i >=k; i--) {  
        a[k] = i;   // 
        if (k > 1) {    // 当 k = 1 的时候该论递归完成
            combine(i - 1, k - 1);
        } else {
            for (j = a[0]; j > 0; j--) {    // 找出一组数 遍历，在 main 函数中设置的a[0] 就起到作用了
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
}
int main () {
    int n, r;
    cin >> n >> r;
    if (r > n) cout << "Input n, r error!" << endl;
    else {
        a[0] = r;       // 将 a[0] 存储取几个数组合
        combine(n, r);  // 递归
    }
    return 0;
}