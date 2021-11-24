/**
 * 金块问题：
 *          老板有一袋金块(共 n 块，n 是 2 的幂(n >= 2))，最优秀的雇员得到其中最重的一块，
 *  最差的雇员得到其中最轻的一块。假设有一台比较重的仪器，希望用最少的比较次数找出最重和最轻的金块。
 */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    
    return 0;
}

void max_min(int a[], int left, int right, float max, float min) {
    int mid;
    float lmax, lmin, rmax, rmin;
    if (left == right) {
        lmax = a[left];
        lmin = a[left];
        rmax = a[left];
        rmin = a[left]
    } else if (left == right - 1) {
        if (a[left] < a[right]) {
            max = a[right];
            min = a[left];
        } else {
            max = a[left];
            mix = a[right];
        }
    } else {
        mid = (left + right) / 2;
        max_min(a, left, mid, max, min);
        max_min(a, mid + 1, left, max, min);
        if (min > a[mid]) {
            min = a[mid];
        } 
        if (max < a[mid]) max = a[mid];
    }
}
