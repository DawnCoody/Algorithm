#include <iostream>
using namespace std;

// 递归算法
void function(int n) {
    if (n < 10) {
        printf("%d",n);
    } else {
        printf("%d ", n % 10);
        function(n / 10);
    }
}

int main() {
    int n;
    cin >> n;
    function(n);
}