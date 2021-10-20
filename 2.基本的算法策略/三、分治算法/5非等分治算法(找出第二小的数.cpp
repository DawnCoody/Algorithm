/**
 * 求一组数的第二小的数组：
 */

#include <iostream>
using namespace std;

void min_two(int left, int right, float &min_one, float &min_two);
float a[100];

int main(int argc, char const *argv[]) {
    int n;
    float min1, min2;
    cout << "有几个数据：";
    cin >> n;
    cout << "请输入这几个数据：";
    for (int i = 0; i < n; i++) cin >> a[i];
    min_two(0, n - 1, min1, min2);
    cout << "第二小的数为：" << min2 << " 第一小的数为：" << min1 << endl;
    return 0;
}

void min_two(int left, int right, float &min_one, float &min_two) {
    // mid为数组中间值的下标
    int mid;
    // lmin1为 mid 左边第一小的数，lmin2为 mid 左边第二小的数，rmin1 为 mid
    // 左边第一小的数，rmin2 为 mid 左边第二小的数
    float lmin1, lmin2, rmin1, rmin2;
    if (left == right) {  // 如果只有一个数则第一小的数是 min1，第二小的数是 min2
        min_one = min_two = a[left];
    } else if (left == right - 1) {  //  如果有两个数据则比较两个数的大小
        if (a[left] > a[right]) {
            min_one = a[right];
            min_two = a[left];
        } else {
            min_one = a[left];
            min_two = a[right];
        }
    } else {  // 多个数据进行分治
        mid = (left + right) / 2;
        min_two(left, mid, lmin1, lmin2);       // 向左边查找
        min_two(mid + 1, right, rmin1, rmin2);  // 向右边查找

        // 在 lmin1, lmin2, rmin1, rmin2 中找第一小的数和第二小的数
        if (lmin1 <= rmin1) {  // 如果左边的最小的数小于右边最小的数
            if (lmin2 < rmin1) {
                min_one = lmin1;
                min_two = lmin2;
            } else if (lmin2 > rmin1) {
                min_one = lmin1;
                min_two = rmin1;
            }
        } else if (rmin1 <= lmin1) {  // 如果左边的最小的数小于右边最小的数
            if (rmin2 < lmin1) {
                min_one = rmin1;
                min_two = rmin2;
            } else if (rmin2 > lmin1) {
                min_one = rmin1;
                min_two = lmin2;
            }
        }
    }
}