/**
 * 某国王大赦囚犯，让一狱史 n 次通过一排锁着的 n 间牢房，每通过一次，
 * 按所规定规则转动 n 间牢房中的某些门锁，每转动一次，原来锁着的门被打开，
 * 原来打开的门被锁上，通过 n 次后，门锁开着的，牢房中的犯人放出，否则犯人不得获释。
 */

/**
 * 数学模型1：当该数的因子数为奇数个时，牢房最终就是开着的；该数的因子数为偶数个时，牢房最终就是关着的
 */
#include <iostream>
using namespace std;

void isOpen1(int n);
void isOpen2(int n);
int main() {
    int n;
    cin >> n;
    // isOpen1(n);
    isOpen2(n);
    return 0;
}

// 数学模型1：当该数的因子数为奇数个时，牢房最终就是开着的；该数的因子数为偶数个时，牢房最终就是关着的
void isOpen1(int n) {
    for (int i = 1; i <= n; i++)
    {
        int divisorCount = 1;   // 因子个数
        for (int j = 2; j <= i; j++) 
            if (i % j == 0) divisorCount++;
        if (divisorCount % 2 == 1) cout << i << "被释放" << endl;
    }
    
}

// 数学模型2：可以发现出规律当该数是完全平方数的时候，牢房最终就是开着的
void isOpen2(int n) {
    for (int i = 1; i <= n; i++) 
        if (i * i <= n) cout << i * i << "被释放" << endl;
        else break;
}