// 利用分治算法求一组数据中最大的连个数和最小的两个数
#include <iostream>
using namespace std;
int a[100];

void max_min(int left, int right, float &min1, float &min2, float &max1, float &max2);

int main(int argc, char const *argv[]) {
    int n;
    float min1, min2, max1, max2;
    cout << "有多少数据：";
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    max_min(0, n - 1, min1, min2, max1, max2);
    cout << "最小的两数为：" << min1 << ", " << min2 << endl;
    cout << "最大的两数为：" << max1 << ", " << max2 << endl;
    return 0;
}

void max_min(int left, int right, float &min1, float &min2, float &max1, float &max2) {
    int mid;
    float l_min1, l_min2, l_max1, l_max2, r_min1, r_min2, r_max1, r_max2;
    if (left == right) {
        min1 = min2 = max1 = max2 = a[left];
    } else if (left == right - 1) {
        min1 = max2 = a[left] >= a[right] ? a[right] : a[left];
        min2 = max1 = a[left] <= a[right] ? a[right] : a[left];
    } else {
        mid = (left + right) / 2;
        max_min(left, mid, l_min1, l_min2, l_max1, l_max2);
        max_min(mid + 1, right, r_min1, r_min2, r_max1, r_max2);
        if (l_min1 <= r_min1) {
            min1 = l_min1;
            min2 = l_min2 <= r_min2 ? l_min2 : l_min1;
        } else if (l_min1 > r_min1) {
            min1 = r_min1;
            min2 = l_min2 >= r_min2 ? r_min2 : l_min1;
        }
        if (l_max1 >= r_max1) {
            max1 = l_max1;
            max2 = l_max2 >= r_max2 ? l_max2 : r_max2;
        } else if (l_max1 <= r_max1) {
            max1 = r_max1;
            max2 = l_max2 >= r_max2 ? l_max2 : r_max2;
        }
    }
}
