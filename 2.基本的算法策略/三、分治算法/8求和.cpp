// 利用分治求一组数据的和

#include <iostream>
using namespace std;
int sum(int a[], int left, int right);

int main(int argc, char const *argv[]) {
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "和为：" <<  sum(a, 0, n - 1) << endl;

    return 0;
}

int sum(int a[], int left, int right) {
    int left_sum, right_sum;
    if (left == right)
        return a[left];
    else if (left == right - 1)
        return a[left] + a[right];
    else {
        int mid = (left + right) / 2;
        left_sum = sum(a, left, mid);
        right_sum = sum(a, mid + 1, right);
        return left_sum + right_sum;
    }
}
