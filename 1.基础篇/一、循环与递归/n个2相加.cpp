#include <iostream>
#include <math.h>
using namespace std;
// 递归算法
int add(int n)
{
    if (n == 1)
    {
        return 2;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += 2 * pow(10, i);
    }
    return sum + add(n - 1);
}

// 非递归算法
int add2(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += 2 * pow(10, j);
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << add2(n) << endl;
}

