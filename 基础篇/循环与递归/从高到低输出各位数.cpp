#include<iostream>
using namespace std;

void function(int n) {
    if (n < 10) cout << n << " ";
    else {
        function(n / 10);
        cout << n % 10 << " ";
    }
}

int main() {
    int num;
    cin >> num;
    function(num);
}