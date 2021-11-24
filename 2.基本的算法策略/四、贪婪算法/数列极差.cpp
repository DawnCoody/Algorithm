/**
 * 在黑板上写了 n 个正整数排成的一个数列，进行如下操作：每次擦去其中两个数 a 和 b，
 * 然后在数列中加入一个数 axb+1，如此下去直至黑板上剩下一个数，
 * 在所有安这种操作方式最后得到的数，最大记作 max，则该数列的极差定义为 m = max - min。
 */

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, max, min, res;   // max 为最大结果，min 为最小结果， res 为两者差
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
    cout << "有几个数：";
    cin >> n;
    cout << "请输入这几个数：";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        min_heap.push(value);
        max_heap.push(value);
    }
    while (min_heap.size() > 1) {
        int a = min_heap.top(); min_heap.pop();
        int b = min_heap.top(); min_heap.pop();
        min_heap.push(a * b + 1);
    }
    while (max_heap.size() > 1) {
        int a = max_heap.top(); max_heap.pop();
        int b = max_heap.top(); max_heap.pop();
        max_heap.push(a * b + 1);
    }
    res = min_heap.top() - max_heap.top();
    cout << res << endl;
    return 0;
}
